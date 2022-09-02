import sys
import ROOT
import os
import shutil
from ROOT import TH2F, TFile, TTree, TCanvas, TH1F, TString
from array import array
from progress.bar import ChargingBar

ROOT.EnableThreadSafety()
ROOT.EnableImplicitMT(8)
renamefile = False

nHists  = 16
step    = 10
maxdimx = 1500
maxdimy = 1500
fHist     = []
fCanvas   = []

if len(sys.argv) == 1 or len(sys.argv) > 3:
	filename = "/home/daq/hdd8TB_bis/RSD2/stats_N_script/RunXX.root" # "/home/daq/hdd8TB/RSD2/stats_N_script/Run22_240.root" # " 
if len(sys.argv) == 2:
	filename = sys.argv[1]
if len(sys.argv) == 3:
        filename = sys.argv[1]
        renamefile = sys.argv[2]
myFile = TFile.Open(filename, "OPEN")
tree   = myFile.Get("Analysis")

nEntries = tree.GetEntries()
for j in range(nHists):
	fHist.append(TH2F(str(j),"c"+str(j),int(maxdimx/step),0,maxdimx,int(maxdimy/step),0,maxdimy))
print("created all histograms")

bar = ChargingBar('Processing', max=nEntries, suffix = '%(percent)d%% [%(elapsed_td)s]')
for i in range(nEntries):
	tree.GetEntry(i)
	for j in range(nHists): fHist[j].Fill(tree.XPos, tree.YPos, tree.ampl[j])
	bar.next()
bar.finish()

for j in range(nHists):
	fCanvas.append(TCanvas(str("c%d"%j),str(j),600,600))
	fHist[j].Draw("colz")
	fCanvas[j].Modified()
	fCanvas[j].Update()
	fCanvas[j].SaveAs(str("c%d.pdf"%j))

if renamefile:
	with open("/home/daq/Desktop/Luca/Analisi_RSD/RSD2_Analysis/Input_Folder_Digitizer_wfm.txt", 'r') as fr:
	    lines = fr.readlines()
	    path = lines[7]
	tpath     = path.replace("ana /home/daq/hdd8TB/RSD2/raw/","")
	run       = tpath[tpath.find("Run"):tpath.find("Run")+5]
	bias      = tpath[tpath.find("V")-3:tpath.find("V")]
	stats_dir = "/home/daq/hdd8TB_bis/RSD2/stats_N_script/"
	savepath = stats_dir+run+"_"+bias+"V.root"
	while(os.path.isfile(savepath)):
		savepath = savepath.replace(".root","") + "_RenameThis.root"
	print(f"saving file as: ", savepath)
	shutil.move(filename,savepath)

#input("")
