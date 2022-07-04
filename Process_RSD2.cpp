#include <TFile.h>
#include <TTree.h>

void Process_RSD2(TString filename = "RunXX.root"){
	auto *file = new TFile(filename,"open");
	TTree *Analysis = (TTree*)file->Get("Analysis");
	Analysis->Process("RSD2_Digitizer_Cross13.C");
}