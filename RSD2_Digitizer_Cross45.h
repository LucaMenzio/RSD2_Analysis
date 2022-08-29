//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sun May  8 22:35:05 2022 by ROOT version 6.24/06
// from TTree Analysis/Analysis
// found on file: /Users/nicolo/work/GruppoV_UFSD/TBAnalysis/RSD/Digitizer/Analysis_root/Croci_450micron/Analysis_W15_Run2_croci045_300V.root
//////////////////////////////////////////////////////////

#ifndef RSD2_Digitizer_Cross45_h
#define RSD2_Digitizer_Cross45_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>

// Headers needed by this particular selector


class RSD2_Digitizer_Cross45 : public TSelector {
public :


   TCanvas *c1;
   TCanvas *c2;
   TCanvas *c3;
   TCanvas *c4;
   TCanvas *c5;
   TCanvas *c6;
   TCanvas *c7;
   
   TH2F *XYPads;
   TH2F *XYPos;
   TH2F *XYRec;
   TH2F *XYSignal;
   TH2F *XYSignalTime;
   TH2F *XYTimeArea;
   TH2F *XYDelay;
   TH2F *XYDCArea;

   TH1F *HXPosRec[8000];
   TH1F *HYPosRec[8000];
   TH1F *HTimeRec[8000];

   TH1F *HXAllPosRec;
   TH1F *HYAllPosRec;
   TH1F *HSignalTotal;
   TH1F *HNumPoint;
   
   TH1F *HDCSignal;
   TH1F *HTime;
   TH1F *HMigration;


   TH1F *HXAllAbsPos;
   TH1F *HYAllAbsPos;

      
   TH1F *HXOffset;
   TH1F *HYOffset;
      
   TH1F *HXSigma;
   TH1F *HYSigma;

   TF1 *exp2;

   TProfile *PShapeDCCh;

   
#define PI 3.14159265
   Double_t param, result, Rangle;
   Double_t xtr, ytr,xrr,yrr,DT, EventTime;
   Double_t XPa_m1, XPa_m2, XPa_p1, XPa_p2, YPa_m1, YPa_m2, YPa_p1, YPa_p2;
   Double_t DCTimeLow, DCTimeHigh;

   Double_t XRecArray[8000];
   Double_t YRecArray[8000];
   Double_t TRecArray[8000];

   Double_t XTrueArray[8000];
   Double_t YTrueArray[8000];
   Double_t TDelay[18];
   Double_t TChannel[18];
   
   Double_t Radius = 0;
   Double_t Radius_r = 0;
   Double_t ASum = 0;
   Int_t NChMax;
   Double_t AMax;
   

   int XOffset = 0;
   int YOffset = 0;
   int n_integral_DC;

   int TPx1,TPx2,TPy1,TPy2;

   Int_t Xm1,Xm2,Xm3, Xp1,Xp2, Xp3, Ym1,Ym2,Yp1,Yp2;

   Double_t  XCent, YCent;
   
   Double_t MaxDim = 0;
   Double_t MinDim = 0;
   Double_t AScale = 1;
   Double_t NScale = 1;
   Double_t Noise = 1;
   Double_t kxfactor = 1;
   Double_t kyfactor = 1;
   Double_t SignalTotal = 1;
   Double_t Signal[20];

   Double_t Tcor2, Tcor10,Tcor12,Tcor14, TTrigger; 
   Double_t XLaser = 0;
   Double_t YLaser= 0;
   Double_t ExpCor= 0;
   Double_t   Distance_Axis;

   Double_t   Distance_Axis_cor;
   Double_t   Distance_Axis_data;
   Double_t   RMSNoise = 4.439;
   Double_t   ADCmV = 0.247;
   int datataking = 0;
   int dcchannel = 0;



   int XPa[18] = {1655,1655,1205,0,755,755,305,305,305,0,755,0,0,1205,0,1655,0,0};
   int YPa[18] = {470,920,470,0,920,470,920,470,20,0,20,0,0,20,0,20,0,0};
   int XPa_old[18] = {1655,1655,1205,0,755,755,305,305,305,0,755,0,0,1205,0,1655,0,0};
   int YPa_old[18] = {470,920,470,0,920,470,920,470,20,0,20,0,0,20,0,20,0,0};

   Double_t x_true[8000], y_true[8000], x_rec[8000], y_rec[8000],t_rec[8000];
   Double_t dif, dif_min, cor_x,cor_y, cor_nx,cor_d,cor_ny;
   Int_t grid = 15;
   Int_t res = 0;
   Int_t res_min = 0;
   Int_t sim_point = 0;
   
   
   TGraph *gr1;
   TGraph *gr2;

   TGraph *gr_rec;
   TGraph *gr_true;
   
   TArrow *ar[8000];
   TArrow *ar_spice[8000];
   


   Double_t XNum, YNum, XYDen;
   Double_t Yarmlenght = 160;
   Double_t Xarmwidth = 10;

   Double_t Xarmlenght = 160;
   Double_t Yarmwidth = 10;

   Int_t Correction;
   Int_t LaserPointInside[8000];
   Int_t DataCorPointInside[8000];
   Int_t a,b,cc;
   Int_t nposold=0;
   Int_t NBox=0;
   Int_t ChanRec=0;
   int UseArea = 1;
   int UseRotation = 0;
   bool RotateLasPositions = false;
   float RangleLasPos = 0.;
   Int_t UseWeightedMean = 0;
   unsigned int rebin_HDC = 1;
   unsigned int rebin_positions = 1;

   Double_t weight;
   

   Double_t xmin, ymin, xmind, ymind;
   Double_t Dx,     Dy,     Xo,     Yo;
   //  Int_t Xm1,Xm2,Xp1,Xp2, Ym1,Ym2, Yp1, Yp2;
   Int_t nbin = 200;

   char *histname = new char[100];
   char *Filedatacorr = new char[100];
   char *Filetimecorr = new char[100];
   char *FileSpicecorr = new char[100];
  


  TTreeReader     fReader;  //!the tree reader
   TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain



   // Readers to access the data (delete the ones you do not need).
   TTreeReaderValue<Int_t> ntrig = {fReader, "ntrig"};
   TTreeReaderValue<Int_t> event = {fReader, "event"};
   TTreeReaderValue<Int_t> nrun = {fReader, "nrun"};
   TTreeReaderValue<Int_t> nchro = {fReader, "nchro"};
   TTreeReaderValue<Int_t> npos = {fReader, "npos"};
   TTreeReaderValue<Double_t> XPos = {fReader, "XPos"};
   TTreeReaderValue<Double_t> YPos = {fReader, "YPos"};
   TTreeReaderArray<Double_t> XPad = {fReader, "XPad"};
   TTreeReaderArray<Double_t> YPad = {fReader, "YPad"};
   TTreeReaderArray<Double_t> Dist = {fReader, "Dist"};
   TTreeReaderArray<Double_t> t_bck = {fReader, "t_bck"};
   TTreeReaderArray<Double_t> t_pul = {fReader, "t_pul"};
   TTreeReaderArray<Double_t> maxD = {fReader, "maxD"};
   TTreeReaderArray<Double_t> area = {fReader, "area"};
   TTreeReaderArray<Double_t> ampl = {fReader, "ampl"};
   TTreeReaderArray<Double_t> Toffset = {fReader, "Toffset"};
   TTreeReaderArray<Double_t> ampl_chi2 = {fReader, "ampl_chi2"};
   TTreeReaderArray<Double_t> dVdt3070 = {fReader, "dVdt3070"};
   TTreeReaderArray<Double_t> dVdt1030 = {fReader, "dVdt1030"};
   TTreeReaderArray<Double_t> dVdt2080 = {fReader, "dVdt2080"};
   TTreeReaderArray<Double_t> bck = {fReader, "bck"};
   TTreeReaderArray<Double_t> max_bck_before = {fReader, "max_bck_before"};
   TTreeReaderArray<Double_t> rms_bck_before = {fReader, "rms_bck_before"};
   TTreeReaderArray<Double_t> max_bck_after = {fReader, "max_bck_after"};
   TTreeReaderArray<Double_t> rms_bck_after = {fReader, "rms_bck_after"};
   TTreeReaderArray<Double_t> t_cent = {fReader, "t_cent"};
   TTreeReaderArray<Double_t> t_level10 = {fReader, "t_level10"};
   TTreeReaderArray<Double_t> t_level15 = {fReader, "t_level15"};
   TTreeReaderArray<Double_t> t_level20 = {fReader, "t_level20"};
   TTreeReaderArray<Double_t> t_level30 = {fReader, "t_level30"};
   TTreeReaderArray<Double_t> t_level40 = {fReader, "t_level40"};
   TTreeReaderArray<Double_t> t_level50 = {fReader, "t_level50"};
   TTreeReaderArray<Double_t> t_level60 = {fReader, "t_level60"};
   TTreeReaderArray<Double_t> t_level80 = {fReader, "t_level80"};
   TTreeReaderArray<Double_t> t_level100 = {fReader, "t_level100"};
   TTreeReaderArray<Double_t> t_level200 = {fReader, "t_level200"};
   TTreeReaderArray<Double_t> t_level300 = {fReader, "t_level300"};
   TTreeReaderArray<Double_t> trail_t_level10 = {fReader, "trail_t_level10"};
   TTreeReaderArray<Double_t> trail_t_level20 = {fReader, "trail_t_level20"};
   TTreeReaderArray<Double_t> trail_t_level30 = {fReader, "trail_t_level30"};
   TTreeReaderArray<Double_t> trail_t_level40 = {fReader, "trail_t_level40"};
   TTreeReaderArray<Double_t> trail_t_level50 = {fReader, "trail_t_level50"};
   TTreeReaderArray<Double_t> trail_t_level60 = {fReader, "trail_t_level60"};
   TTreeReaderArray<Double_t> trail_t_level80 = {fReader, "trail_t_level80"};
   TTreeReaderArray<Double_t> trail_t_level100 = {fReader, "trail_t_level100"};
   TTreeReaderArray<Double_t> trail_t_level120 = {fReader, "trail_t_level120"};
   TTreeReaderArray<Double_t> trail_t_level140 = {fReader, "trail_t_level140"};
   TTreeReaderArray<Double_t> trail_t_level160 = {fReader, "trail_t_level160"};
   TTreeReaderArray<Double_t> trail_t_level180 = {fReader, "trail_t_level180"};
   TTreeReaderArray<Double_t> cfd05 = {fReader, "cfd05"};
   TTreeReaderArray<Double_t> cfd10 = {fReader, "cfd10"};
   TTreeReaderArray<Double_t> cfd15 = {fReader, "cfd15"};
   TTreeReaderArray<Double_t> cfd20 = {fReader, "cfd20"};
   TTreeReaderArray<Double_t> cfd25 = {fReader, "cfd25"};
   TTreeReaderArray<Double_t> cfd30 = {fReader, "cfd30"};
   TTreeReaderArray<Double_t> cfd40 = {fReader, "cfd40"};
   TTreeReaderArray<Double_t> cfd50 = {fReader, "cfd50"};
   TTreeReaderArray<Double_t> cfd60 = {fReader, "cfd60"};
   TTreeReaderArray<Double_t> cfd70 = {fReader, "cfd70"};
   TTreeReaderArray<Double_t> cfd80 = {fReader, "cfd80"};
   TTreeReaderArray<Double_t> cfd90 = {fReader, "cfd90"};
   TTreeReaderArray<Int_t> Ncfd05 = {fReader, "Ncfd05"};
   TTreeReaderArray<Int_t> Ncfd10 = {fReader, "Ncfd10"};
   TTreeReaderArray<Int_t> Ncfd15 = {fReader, "Ncfd15"};
   TTreeReaderArray<Int_t> Ncfd20 = {fReader, "Ncfd20"};
   TTreeReaderArray<Int_t> Ncfd25 = {fReader, "Ncfd25"};
   TTreeReaderArray<Int_t> Ncfd30 = {fReader, "Ncfd30"};
   TTreeReaderArray<Int_t> Ncfd40 = {fReader, "Ncfd40"};
   TTreeReaderArray<Int_t> Ncfd50 = {fReader, "Ncfd50"};
   TTreeReaderArray<Int_t> Ncfd60 = {fReader, "Ncfd60"};
   TTreeReaderArray<Int_t> Ncfd70 = {fReader, "Ncfd70"};
   TTreeReaderArray<Int_t> Ncfd80 = {fReader, "Ncfd80"};
   TTreeReaderArray<Int_t> Ncfd90 = {fReader, "Ncfd90"};
   TTreeReaderArray<Int_t> trail_Ncfd10 = {fReader, "trail_Ncfd10"};
   TTreeReaderArray<Int_t> trail_Ncfd30 = {fReader, "trail_Ncfd30"};
   TTreeReaderArray<Int_t> trail_Ncfd50 = {fReader, "trail_Ncfd50"};
   TTreeReaderArray<Int_t> trail_Ncfd70 = {fReader, "trail_Ncfd70"};
   TTreeReaderArray<Int_t> trail_Ncfd90 = {fReader, "trail_Ncfd90"};
   TTreeReaderArray<Double_t> t_rms3 = {fReader, "t_rms3"};
   TTreeReaderArray<Double_t> t_rms5 = {fReader, "t_rms5"};
   TTreeReaderArray<Double_t> trail_cfd10 = {fReader, "trail_cfd10"};
   TTreeReaderArray<Double_t> trail_cfd30 = {fReader, "trail_cfd30"};
   TTreeReaderArray<Double_t> trail_cfd50 = {fReader, "trail_cfd50"};
   TTreeReaderArray<Double_t> trail_cfd70 = {fReader, "trail_cfd70"};
   TTreeReaderArray<Double_t> trail_cfd90 = {fReader, "trail_cfd90"};
   TTreeReaderArray<Int_t> samples = {fReader, "samples"};
   TTreeReaderArray<Double_t> t_max = {fReader, "t_max"};
   TTreeReaderValue<Int_t> samples_0 = {fReader, "samples_0"};
   TTreeReaderValue<Int_t> samplesrec_0 = {fReader, "samplesrec_0"};
   TTreeReaderArray<Double_t> amp0 = {fReader, "amp0"};
   TTreeReaderArray<Double_t> m_amp0 = {fReader, "m_amp0"};
   TTreeReaderArray<Double_t> der_amp0 = {fReader, "der_amp0"};
   TTreeReaderArray<Double_t> FFT_abs0 = {fReader, "FFT_abs0"};
   TTreeReaderArray<Double_t> FFT_real0 = {fReader, "FFT_real0"};
   TTreeReaderArray<Double_t> FFT_comp0 = {fReader, "FFT_comp0"};
   TTreeReaderValue<Int_t> samples_1 = {fReader, "samples_1"};
   TTreeReaderValue<Int_t> samplesrec_1 = {fReader, "samplesrec_1"};
   TTreeReaderArray<Double_t> amp1 = {fReader, "amp1"};
   TTreeReaderArray<Double_t> m_amp1 = {fReader, "m_amp1"};
   TTreeReaderArray<Double_t> der_amp1 = {fReader, "der_amp1"};
   TTreeReaderArray<Double_t> FFT_abs1 = {fReader, "FFT_abs1"};
   TTreeReaderArray<Double_t> FFT_real1 = {fReader, "FFT_real1"};
   TTreeReaderArray<Double_t> FFT_comp1 = {fReader, "FFT_comp1"};
   TTreeReaderValue<Int_t> samples_2 = {fReader, "samples_2"};
   TTreeReaderValue<Int_t> samplesrec_2 = {fReader, "samplesrec_2"};
   TTreeReaderArray<Double_t> amp2 = {fReader, "amp2"};
   TTreeReaderArray<Double_t> m_amp2 = {fReader, "m_amp2"};
   TTreeReaderArray<Double_t> der_amp2 = {fReader, "der_amp2"};
   TTreeReaderArray<Double_t> FFT_abs2 = {fReader, "FFT_abs2"};
   TTreeReaderArray<Double_t> FFT_real2 = {fReader, "FFT_real2"};
   TTreeReaderArray<Double_t> FFT_comp2 = {fReader, "FFT_comp2"};
   TTreeReaderValue<Int_t> samples_3 = {fReader, "samples_3"};
   TTreeReaderValue<Int_t> samplesrec_3 = {fReader, "samplesrec_3"};
   TTreeReaderArray<Double_t> amp3 = {fReader, "amp3"};
   TTreeReaderArray<Double_t> m_amp3 = {fReader, "m_amp3"};
   TTreeReaderArray<Double_t> der_amp3 = {fReader, "der_amp3"};
   TTreeReaderArray<Double_t> FFT_abs3 = {fReader, "FFT_abs3"};
   TTreeReaderArray<Double_t> FFT_real3 = {fReader, "FFT_real3"};
   TTreeReaderArray<Double_t> FFT_comp3 = {fReader, "FFT_comp3"};
   TTreeReaderValue<Int_t> samples_4 = {fReader, "samples_4"};
   TTreeReaderValue<Int_t> samplesrec_4 = {fReader, "samplesrec_4"};
   TTreeReaderArray<Double_t> amp4 = {fReader, "amp4"};
   TTreeReaderArray<Double_t> m_amp4 = {fReader, "m_amp4"};
   TTreeReaderArray<Double_t> der_amp4 = {fReader, "der_amp4"};
   TTreeReaderArray<Double_t> FFT_abs4 = {fReader, "FFT_abs4"};
   TTreeReaderArray<Double_t> FFT_real4 = {fReader, "FFT_real4"};
   TTreeReaderArray<Double_t> FFT_comp4 = {fReader, "FFT_comp4"};
   TTreeReaderValue<Int_t> samples_5 = {fReader, "samples_5"};
   TTreeReaderValue<Int_t> samplesrec_5 = {fReader, "samplesrec_5"};
   TTreeReaderArray<Double_t> amp5 = {fReader, "amp5"};
   TTreeReaderArray<Double_t> m_amp5 = {fReader, "m_amp5"};
   TTreeReaderArray<Double_t> der_amp5 = {fReader, "der_amp5"};
   TTreeReaderArray<Double_t> FFT_abs5 = {fReader, "FFT_abs5"};
   TTreeReaderArray<Double_t> FFT_real5 = {fReader, "FFT_real5"};
   TTreeReaderArray<Double_t> FFT_comp5 = {fReader, "FFT_comp5"};
   TTreeReaderValue<Int_t> samples_6 = {fReader, "samples_6"};
   TTreeReaderValue<Int_t> samplesrec_6 = {fReader, "samplesrec_6"};
   TTreeReaderArray<Double_t> amp6 = {fReader, "amp6"};
   TTreeReaderArray<Double_t> m_amp6 = {fReader, "m_amp6"};
   TTreeReaderArray<Double_t> der_amp6 = {fReader, "der_amp6"};
   TTreeReaderArray<Double_t> FFT_abs6 = {fReader, "FFT_abs6"};
   TTreeReaderArray<Double_t> FFT_real6 = {fReader, "FFT_real6"};
   TTreeReaderArray<Double_t> FFT_comp6 = {fReader, "FFT_comp6"};
   TTreeReaderValue<Int_t> samples_7 = {fReader, "samples_7"};
   TTreeReaderValue<Int_t> samplesrec_7 = {fReader, "samplesrec_7"};
   TTreeReaderArray<Double_t> amp7 = {fReader, "amp7"};
   TTreeReaderArray<Double_t> m_amp7 = {fReader, "m_amp7"};
   TTreeReaderArray<Double_t> der_amp7 = {fReader, "der_amp7"};
   TTreeReaderArray<Double_t> FFT_abs7 = {fReader, "FFT_abs7"};
   TTreeReaderArray<Double_t> FFT_real7 = {fReader, "FFT_real7"};
   TTreeReaderArray<Double_t> FFT_comp7 = {fReader, "FFT_comp7"};
   TTreeReaderValue<Int_t> samples_8 = {fReader, "samples_8"};
   TTreeReaderValue<Int_t> samplesrec_8 = {fReader, "samplesrec_8"};
   TTreeReaderArray<Double_t> amp8 = {fReader, "amp8"};
   TTreeReaderArray<Double_t> m_amp8 = {fReader, "m_amp8"};
   TTreeReaderArray<Double_t> der_amp8 = {fReader, "der_amp8"};
   TTreeReaderArray<Double_t> FFT_abs8 = {fReader, "FFT_abs8"};
   TTreeReaderArray<Double_t> FFT_real8 = {fReader, "FFT_real8"};
   TTreeReaderArray<Double_t> FFT_comp8 = {fReader, "FFT_comp8"};
   TTreeReaderValue<Int_t> samples_9 = {fReader, "samples_9"};
   TTreeReaderValue<Int_t> samplesrec_9 = {fReader, "samplesrec_9"};
   TTreeReaderArray<Double_t> amp9 = {fReader, "amp9"};
   TTreeReaderArray<Double_t> m_amp9 = {fReader, "m_amp9"};
   TTreeReaderArray<Double_t> der_amp9 = {fReader, "der_amp9"};
   TTreeReaderArray<Double_t> FFT_abs9 = {fReader, "FFT_abs9"};
   TTreeReaderArray<Double_t> FFT_real9 = {fReader, "FFT_real9"};
   TTreeReaderArray<Double_t> FFT_comp9 = {fReader, "FFT_comp9"};
   TTreeReaderValue<Int_t> samples_10 = {fReader, "samples_10"};
   TTreeReaderValue<Int_t> samplesrec_10 = {fReader, "samplesrec_10"};
   TTreeReaderArray<Double_t> amp10 = {fReader, "amp10"};
   TTreeReaderArray<Double_t> m_amp10 = {fReader, "m_amp10"};
   TTreeReaderArray<Double_t> der_amp10 = {fReader, "der_amp10"};
   TTreeReaderArray<Double_t> FFT_abs10 = {fReader, "FFT_abs10"};
   TTreeReaderArray<Double_t> FFT_real10 = {fReader, "FFT_real10"};
   TTreeReaderArray<Double_t> FFT_comp10 = {fReader, "FFT_comp10"};
   TTreeReaderValue<Int_t> samples_11 = {fReader, "samples_11"};
   TTreeReaderValue<Int_t> samplesrec_11 = {fReader, "samplesrec_11"};
   TTreeReaderArray<Double_t> amp11 = {fReader, "amp11"};
   TTreeReaderArray<Double_t> m_amp11 = {fReader, "m_amp11"};
   TTreeReaderArray<Double_t> der_amp11 = {fReader, "der_amp11"};
   TTreeReaderArray<Double_t> FFT_abs11 = {fReader, "FFT_abs11"};
   TTreeReaderArray<Double_t> FFT_real11 = {fReader, "FFT_real11"};
   TTreeReaderArray<Double_t> FFT_comp11 = {fReader, "FFT_comp11"};
   TTreeReaderValue<Int_t> samples_12 = {fReader, "samples_12"};
   TTreeReaderValue<Int_t> samplesrec_12 = {fReader, "samplesrec_12"};
   TTreeReaderArray<Double_t> amp12 = {fReader, "amp12"};
   TTreeReaderArray<Double_t> m_amp12 = {fReader, "m_amp12"};
   TTreeReaderArray<Double_t> der_amp12 = {fReader, "der_amp12"};
   TTreeReaderArray<Double_t> FFT_abs12 = {fReader, "FFT_abs12"};
   TTreeReaderArray<Double_t> FFT_real12 = {fReader, "FFT_real12"};
   TTreeReaderArray<Double_t> FFT_comp12 = {fReader, "FFT_comp12"};
   TTreeReaderValue<Int_t> samples_13 = {fReader, "samples_13"};
   TTreeReaderValue<Int_t> samplesrec_13 = {fReader, "samplesrec_13"};
   TTreeReaderArray<Double_t> amp13 = {fReader, "amp13"};
   TTreeReaderArray<Double_t> m_amp13 = {fReader, "m_amp13"};
   TTreeReaderArray<Double_t> der_amp13 = {fReader, "der_amp13"};
   TTreeReaderArray<Double_t> FFT_abs13 = {fReader, "FFT_abs13"};
   TTreeReaderArray<Double_t> FFT_real13 = {fReader, "FFT_real13"};
   TTreeReaderArray<Double_t> FFT_comp13 = {fReader, "FFT_comp13"};
   TTreeReaderValue<Int_t> samples_14 = {fReader, "samples_14"};
   TTreeReaderValue<Int_t> samplesrec_14 = {fReader, "samplesrec_14"};
   TTreeReaderArray<Double_t> amp14 = {fReader, "amp14"};
   TTreeReaderArray<Double_t> m_amp14 = {fReader, "m_amp14"};
   TTreeReaderArray<Double_t> der_amp14 = {fReader, "der_amp14"};
   TTreeReaderArray<Double_t> FFT_abs14 = {fReader, "FFT_abs14"};
   TTreeReaderArray<Double_t> FFT_real14 = {fReader, "FFT_real14"};
   TTreeReaderArray<Double_t> FFT_comp14 = {fReader, "FFT_comp14"};
   TTreeReaderValue<Int_t> samples_15 = {fReader, "samples_15"};
   TTreeReaderValue<Int_t> samplesrec_15 = {fReader, "samplesrec_15"};
   TTreeReaderArray<Double_t> amp15 = {fReader, "amp15"};
   TTreeReaderArray<Double_t> m_amp15 = {fReader, "m_amp15"};
   TTreeReaderArray<Double_t> der_amp15 = {fReader, "der_amp15"};
   TTreeReaderArray<Double_t> FFT_abs15 = {fReader, "FFT_abs15"};
   TTreeReaderArray<Double_t> FFT_real15 = {fReader, "FFT_real15"};
   TTreeReaderArray<Double_t> FFT_comp15 = {fReader, "FFT_comp15"};
   TTreeReaderValue<Int_t> samples_16 = {fReader, "samples_16"};
   TTreeReaderValue<Int_t> samplesrec_16 = {fReader, "samplesrec_16"};
   TTreeReaderArray<Double_t> amp16 = {fReader, "amp16"};
   TTreeReaderArray<Double_t> m_amp16 = {fReader, "m_amp16"};
   TTreeReaderArray<Double_t> der_amp16 = {fReader, "der_amp16"};
   TTreeReaderArray<Double_t> FFT_abs16 = {fReader, "FFT_abs16"};
   TTreeReaderArray<Double_t> FFT_real16 = {fReader, "FFT_real16"};
   TTreeReaderArray<Double_t> FFT_comp16 = {fReader, "FFT_comp16"};
   TTreeReaderValue<Int_t> samples_17 = {fReader, "samples_17"};
   TTreeReaderValue<Int_t> samplesrec_17 = {fReader, "samplesrec_17"};
   TTreeReaderArray<Double_t> amp17 = {fReader, "amp17"};
   TTreeReaderArray<Double_t> m_amp17 = {fReader, "m_amp17"};
   TTreeReaderArray<Double_t> der_amp17 = {fReader, "der_amp17"};
   TTreeReaderArray<Double_t> FFT_abs17 = {fReader, "FFT_abs17"};
   TTreeReaderArray<Double_t> FFT_real17 = {fReader, "FFT_real17"};
   TTreeReaderArray<Double_t> FFT_comp17 = {fReader, "FFT_comp17"};
   TTreeReaderArray<Double_t> time = {fReader, "time"};


   RSD2_Digitizer_Cross45(TTree * /*tree*/ =0) { }
   virtual ~RSD2_Digitizer_Cross45() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();
   virtual void    Terminate2();

   ClassDef(RSD2_Digitizer_Cross45,0);

};

#endif

#ifdef RSD2_Digitizer_Cross45_cxx
void RSD2_Digitizer_Cross45::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the reader is initialized.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   fReader.SetTree(tree);
}

Bool_t RSD2_Digitizer_Cross45::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}


#endif // #ifdef RSD2_Digitizer_Cross45_cxx
