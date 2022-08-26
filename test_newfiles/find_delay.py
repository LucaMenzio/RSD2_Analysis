import sys
import ROOT
import os
import shutil
from ROOT import TH2F, TFile, TTree, TCanvas, TH1F, TString
from array import array
from progress.bar import ChargingBar

ROOT.EnableThreadSafety()
ROOT.EnableImplicitMT(8)

#Channels = [6,7,8,5]
Channels = [1,2,3,4]
#Channels_positions = [[55,65],[435,65],[435,265],[55,265]]
nEntries_hist = [] 
entries_per_bin = []

step    = 20
maxdimx = 1500
maxdimy = 1500
nbinsx = int(maxdimx/step)
nbinsy = int(maxdimy/step)

fHists = []
fEntries_Hists = []
delays  = [0.,0.,0.,0.]
count   = [0.,0.,0.,0.]

fCanvas   = []

if len(sys.argv) == 1:
	filename = input("please specify the file name and path")
if len(sys.argv) > 1:
	filename = sys.argv[1]

myFile = TFile.Open(filename, "OPEN")
tree = myFile.Get("Analysis")

nEntries = tree.GetEntries()
for j in range(len(Channels)):
	fHists.append(TH2F(str(j),"c"+str(j),nbinsx,0,maxdimx,nbinsy,0,maxdimy))
	fEntries_Hists.append(TH2F(str(j),"c"+str(j),nbinsx,0,maxdimx,nbinsy,0,maxdimy))

bar = ChargingBar('Processing', max=nEntries, suffix = '%(percent)d%% [%(elapsed_td)s]')

for i in range(nEntries):
	tree.GetEntry(i)
	for j in range(len(Channels)):
		fHists[j].Fill(tree.XPos, tree.YPos, tree.t_max[Channels[j]])
		fEntries_Hists[j].Fill(tree.XPos, tree.YPos, 1)

	#if tree.XPos > 100 and tree.XPos < 120 and tree.YPos > 100 and tree.YPos < 120: # channel 6, w3 boxes
	if tree.XPos > 1340 and tree.XPos < 1370 and tree.YPos > 1320 and tree.YPos < 1350: # channel 1, w3 crosses
		delays[0] += tree.t_max[Channels[0]]
		count [0] += 1
	#if tree.XPos > 380 and tree.XPos < 400 and tree.YPos > 90 and tree.YPos < 110: # channe 7, w3 boxes
	if tree.XPos > 1330 and tree.XPos < 1360 and tree.YPos > 90 and tree.YPos < 120: # channe 2, w3 crosses
		delays[1] += tree.t_max[Channels[1]]
		count [1] += 1
	#if tree.XPos > 385 and tree.XPos < 405 and tree.YPos > 235 and tree.YPos < 255: # channe 7, w3 boxes
	if tree.XPos > 110 and tree.XPos < 140 and tree.YPos > 110 and tree.YPos < 140: # channe 3, w3 crosses
		delays[2] += tree.t_max[Channels[2]]
		count [2] += 1
	#if tree.XPos > 95 and tree.XPos < 115 and tree.YPos > 225 and tree.YPos < 245: # channe 7, w3 boxes
	if tree.XPos > 120 and tree.XPos < 150 and tree.YPos > 1280 and tree.YPos < 1310: # channe 4, w3 crosses
		delays[3] += tree.t_max[Channels[3]]
		count [3] += 1
	bar.next()
bar.finish()
for k in range(len(delays)):	
	if count[k] != 0:
		delays[k]/= count[k]
	else:
		print("problems with position " + str(k) + " in the array")
		print("delay = " + str(delays[k]) + "\ncount = " + str(count[k]))

print("delays are:\n" + str(delays[0]) + " ps [ch " + str(Channels[0]) + "]\n" + str(delays[1]) + " ps [ch " + str(Channels[1]) + "]\n" + str(delays[2]) + " ps [ch " + str(Channels[2]) + "]\n" + str(delays[3]) + " ps [ch " + str(Channels[3]) + "]")


for j in range(len(Channels)):
	fHists[j].Divide(fEntries_Hists[j])

for j in range(len(Channels)):
	fCanvas.append(TCanvas(str("c%d"%j),str(j),600,600))
	fHists[j].SetTitle(str(Channels[j]))
	fHists[j].Draw("colz")
	fCanvas[j].Modified()
	fCanvas[j].Update()
	fCanvas[j].SaveAs(str("c%d.pdf"%j))


input("")