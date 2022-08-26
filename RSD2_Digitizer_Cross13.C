#define RSD2_Digitizer_Cross13_cxx
// The class definition in RSD2_Digitizer_Cross13.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.


// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in thgetmeais function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// root> T->Process("RSD2_Digitizer_Cross13.C")
// root> T->Process("RSD2_Digitizer_Cross13.C","some options")
// root> T->Process("RSD2_Digitizer_Cross13.C+")
//


#include "RSD2_Digitizer_Cross13.h"
#include <TH2.h>
#include <TStyle.h>
#include <random>

void RSD2_Digitizer_Cross13::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();


   
   /* declaring normal distribution object 'distN' and initializing its mean and standard deviation fields. */
   /* Mean and standard deviation are distribution parameters of Normal distribution. Here, we have used mean=5, and standard deviation=2. You can take mean and standard deviation as per your choice */



   /* = 1 use correction LTSPICE 
      = 2 show correction LTSPICE without using it;
  
      = 10 write the correction file 
      = 11 use correction from data; 
      = 12 show correction Data without using it;
   */

   Correction = 11;

   datataking = 4;
   /*
    = 0 old run  5, 6,7,8;
    ==1 for  10=< run =<13;  ==2 for  14=< run =<16;   new data taking
    == 2
   == 3 for timing
   == 4 for run 28
   */
   
   kfactor = 1;
   
   Distance_Axis_cor = 30;
   Distance_Axis_data = 30;
   UseArea = 0;
   UseWeightedMean = 0;
   UseRotation = 0;
   SquareCut = 0; // 0 no cut, ==10 rotated cut, 1 +-250; 2 =250- 500; 3 = 500-750;
   Rangle = 0* PI / 180.0;  // angle of rotation of training data
   RMSNoise = 4.439 ; // In ADC count
   Radius = 30; //30;
   n_integral_DC = 1000;

   AScale = 1;// 10./63. ;// gain X/66; 35, 53,66
   NScale = 1.2;
   TPx1 = 100;
   TPx2 = 1000;
   TPy1 = 1750;
   TPy2 = 1950;

   alow = 0;
   ahigh = 5;
   
   if (datataking == 0){
    dcchannel = 2;
    DCTimeLow = 25;
    DCTimeHigh = 40;// 18;
    
    Xm1 = 3;
    Xm2 = 1;
    Xp1 = 4;
    Xp2 = 0;
    Ym1 = 3;
    Ym2 = 4;
    Yp1 = 1;
    Yp2 = 0;
    XOffset = 210;
    YOffset = 205;
    XPa[0] = 1300;
    XPa[1] = 0;
    XPa[2] = 0;
    XPa[3] = 0;
    XPa[4] = 1300;
    YPa[0] = 1300;
    YPa[1] = 1300;
    YPa[2] = 0;
    YPa[3] = 0;
    YPa[4] = 0; 
    }
    else if (datataking == 1 || datataking == 2){
      if (datataking ==1){
	     XOffset = 140;
	     YOffset = 90;
	     XPa[1] = 1320;
	     XPa[2] = 20;
	     XPa[3] = 1300;
	     XPa[4] = 0;
	 
	     YPa[0] = 0;
	     YPa[1] = 1280;
	     YPa[2] = 1300;
	     YPa[3] = -20;
	     YPa[4] = 0;
	     DCTimeLow  = 30;
	     DCTimeHigh = 40;
       }
      else{
	     DCTimeLow  = 30;
	     DCTimeHigh = 60;
	     XOffset = 90;
	     YOffset = 120;	   
	     XPa[1] = 1300;
	     XPa[2] = 0;
	     XPa[3] = 1300;
	     XPa[4] = 0;

	     YPa[0] = 0;
	     YPa[1] = 1300;
	     YPa[2] = 1300;
	     YPa[3] = 0;
	     YPa[4] = 0;
	     }
      dcchannel = 0;
      XPa[0] = 0;
      Xm1 = 4;
      Xm2 = 2;
      Xp1 = 3;
      Xp2 = 1;
      Ym1 = 4;
      Ym2 = 3;
      Yp1 = 2;
      Yp2 = 1;	 
    }

    else if ( datataking == 3){

      XOffset = 140;
      YOffset = 90;
      XPa[3] = 1320;
      XPa[4] = 20;
      XPa[5] = 1300;
      XPa[6] = 0;

      YPa[3] = 1280;
      YPa[4] = 1300;
      YPa[5] = -20;
      YPa[6] = 0;
      DCTimeLow  = 30;
      DCTimeHigh = 40;
      dcchannel = 2;
      XPa[0] = 0;

      Xm1 = 6;
      Xm2 = 4;
      Xp1 = 5;
      Xp2 = 3;
      Ym1 = 6;
      Ym2 = 5;
      Yp1 = 4;
      Yp2 = 3;
      alow = 2;
      ahigh = 8;

      TDelay[3] = 0.632;
      TDelay[4] = 0.068;
      TDelay[5] = 0.6421;
      TDelay[6] = 0.488;
     }
   
    else if (datataking == 4){
      //XOffset = 125;
      //YOffset = 120;

      //(Xm1,Ym1) - (Xp2, Yp2) - (Xm2, Yp1) - (Xp1, Ym2)
      XOffset = 70;
      YOffset = 80;

      Xm1 = 3;
      Xm2 = 4;
      Xp1 = 2;
      Xp2 = 1;
      Ym1 = 3;
      Ym2 = 2;
      Yp1 = 4;
      Yp2 = 1;
       
      dcchannel = 0;
      XPa[0] = 0;
      YPa[0] = 0;

      XPa[Xm1] = 0;
      XPa[Xm2] = 0;
      XPa[Xp1] = 1300;
      XPa[Xp2] = 1300;
       
      YPa[Ym1] = 0;
      YPa[Ym2] = 0;
      YPa[Yp1] = 1310;
      YPa[Yp2] = 1310;

      DCTimeLow  = 10;
      DCTimeHigh = 60;

      TDelay[1] = 5.557302422353908;
      TDelay[2] = 5.412929484946022;
      TDelay[3] = 5.888555319756881;
      TDelay[4] = 5.461670658289696;

 
   }
     
   sprintf(Filedatacorr,"Migration_Cor%3.2f_UseArea%d_Mean%d_Rotation%d_datataking%d_Cross13.txt", kfactor, UseArea, UseWeightedMean, UseRotation,datataking); //Data
   sprintf(NormFiledatacorr,"Norm_Migration_Cor%3.2f_Cross13.txt", kfactor); //Data
   sprintf(FileSpicecorr,"LSPICE_correction/1node/ampcut0mV/table_crosses_0.75k_18.86fF.txt"); //best with 18.86
   sprintf(FileSpicecorr,"LSPICE_correction/3node/ampcut0mV/table_crosses_3.0k_2.26fF.txt"); //best with 2.26
   // sprintf(FileSpicecorr,"LSPICE_correction/1node/ampcut0mV/table_crosses_3.0k_1.29fF.txt"); //best with 1.29

  //new


   // scaling the reconstruction method 


  for(a=alow;a<ahigh;a++){
    if (a!= dcchannel){
	    XPa[a] = XPa[a]+XOffset;
	    YPa[a] = YPa[a]+YOffset;
	  }
      
    cout << "Pad " << a << " is in " << XPa[a]<<","<<YPa[a] << endl;
  }

  MaxDim  = 1500;
  sprintf(histname,"");       
  XYPads = new TH2F ("XYPads",";X [um];Y [um]",nbin,0.,MaxDim,nbin, 0.,MaxDim);
  
  sprintf(histname,"W15, Laser shot Positions;X [um];Y [um]");       
  XYPos = new TH2F ("XYPos",histname,nbin,0.,MaxDim,nbin, 0.,MaxDim);

  sprintf(histname,"W15, Signal amplitude;X [um];Y [um]");       
  XYSignal = new TH2F ("XYSig",histname,nbin,0.,MaxDim,nbin, 0.,MaxDim);

  sprintf(histname,"W15, DC Area ;X [um];Y [um]");       
  XYDCArea = new TH2F ("XYDCArea",histname,50,0,MaxDim,50, 0,MaxDim);

  sprintf(histname,"W15, AC Area ;X [um];Y [um]");       
  XYACArea = new TH2F ("XYACArea",histname,50,0,MaxDim,50, 0,MaxDim);
   
  sprintf(histname,"W15,xmin-XLaser;X [um];Y [um]");       
  XYXOffset = new TH2F ("XYXOffset",histname,nbin,0.,MaxDim,nbin, 0.,MaxDim);

  sprintf(histname,"W15, Signal time;X [um];Y [um]; Delay + 1 [ns]");       
  //   XYSignalTime = new TH2F ("XYSignalTime",histname,nbin,0,MaxDim,nbin, 0,MaxDim);
  XYSignalTime = new TH2F ("XYSignalTime",histname,nbin,0,MaxDim,nbin, 0,MaxDim);
   
  sprintf(histname,"W15, Time;X [um];Y [um]; Trigger - Event Time + 1 [ns]");       
  XYTimeArea = new TH2F ("XYTimeArea",histname,MaxDim/10,0,MaxDim,MaxDim/10, 0,MaxDim);
  sprintf(histname,"W15, Delay;X [um];Y [um]; Delay + 1 [ns]");       
  XYDelay = new TH2F ("XYDelay",histname,MaxDim/50,0,MaxDim,MaxDim/50, 0,MaxDim);

   
  sprintf(histname,"W15, Struc Rec Pposition");       
  XYRec = new TH2F ("XYRec",histname,nbin,0.,MaxDim,nbin, 0.,MaxDim);

  sprintf(histname,"DC shape;Time [ns]; Amplitude [mV] ");       
  PShapeDCCh = new TProfile("PShaperDCCh",histname, 300, 0, 60.);


  sprintf(histname,"Xm1 shape;Time [ns]; Amplitude [mV] ");       
  PShapeXm1 = new TProfile("PShaperXm1",histname, 100, 20, 50.);
  sprintf(histname,"Xm2 shape;Time [ns]; Amplitude [mV] ");       
  PShapeXm2 = new TProfile("PShaperXm2",histname, 100, 20, 50.);
  sprintf(histname,"Xp1 shape;Time [ns]; Amplitude [mV] ");       
  PShapeXp1 = new TProfile("PShaperXp1",histname, 100, 20, 50.);
  sprintf(histname,"Xp2 shape;Time [ns]; Amplitude [mV] ");       
  PShapeXp2 = new TProfile("PShaperXp2",histname, 100, 20, 50.);
   

  for (int b=0;b<8000;b++){
    sprintf(histname,"XPos%d ",b);       
    HXPosRec[b] = new TH1F (histname,histname,MaxDim/2, 0,MaxDim);
    sprintf(histname,"YPos%d ",b);       
    HYPosRec[b] = new TH1F (histname,histname,MaxDim/2, 0,MaxDim);
    sprintf(histname,"Time%d; Time [ns]; Entries",b);       
    HTimeRec[b] = new TH1F (histname,histname,400, -2.,2.);
  }

  HTime = new TH1F ("HTime","HTime; Time [ns]; Entries",100, -0.5,0.5);
   
  sprintf(histname,"; X [um];Entries ");       
  HXAllPosRec = new TH1F ("HXAllPosRec",histname,100, -200,200);
  sprintf(histname,"; Y [um];Entries");       
  HYAllPosRec = new TH1F ("HYAllPosRec",histname,100, -200,200);

  sprintf(histname,"; X [um];Entries ");       
  HXAllAbsPos = new TH1F ("HXallAbs",histname,100, 0,1600);
  sprintf(histname,"; Y [um];Entries");       
  HYAllAbsPos = new TH1F ("HYallAbs",histname,100, 0,1600);

  sprintf(histname,"Offset (xmin-XLaser); X [um];Entries ");       
  HXOffset = new TH1F ("HXOffset",histname,100, -250,250);
  sprintf(histname,"Offset (ymin-YLaser); Y [um];Entries");       
  HYOffset = new TH1F ("HYOffsetc",histname,100, -250,250);

  sprintf(histname,"Sigma (xmin-XLaser); X [um];Entries ");       
  HXSigma = new TH1F ("HXSigma",histname,100, -250,250);
  sprintf(histname,"Sigma (ymin - Ylaser); Y [um];Entries");       
  HYSigma = new TH1F ("HYSigma",histname,100, -250,250);

  sprintf(histname,"; Signal Total [mV] ;Entries");       
  HSignalTotal = new TH1F ("HSignalTotal",histname,100, 0, 350. );
  sprintf(histname,"; DC Signal  [fC] ;Entries");       
  HDCSignal = new TH1F ("HDCSignal",histname,200, -100, 100. );

  sprintf(histname,"; Shift  [um] ;Entries");       
  HMigration = new TH1F ("HMigration",histname,100, 0, 350. );

  sprintf(histname,"; Point ;Entries");       
  HNumPoint = new TH1F ("HNumPoint",histname,50, 0, 50. );

   
  if(Correction == 1 || Correction == 2 ){
       
    ifstream inputFile2 (FileSpicecorr);
    if(!inputFile2)
	   cout << "Error: could not find the LTSPICE file" << endl;
    else{
	   res = 0;
	   cout << "LTSpice file = " << FileSpicecorr << endl;
	   //   inputFile2 >> pippo >> pippo >> pippo  >> pippo;
	   while(1){ //upper limit for safety		  
	     if(inputFile2.eof() || res>8000) break;		 	   
	     inputFile2 >> x_true[res] >> y_true[res] >>	x_rec[res]  >> y_rec[res] >> t_rec[res];
	     DataCorPointInside[res] = 1;
	     res++;
	   }
	   res--;
	   sim_point = res;
	   cout << " LTSPICE file with " << res << " points" << endl;
	   
	   
	   Dx = 1300;
	   Dy = 1300;
	   Yo = YPa[Ym1];
	   Xo = XPa[Xm1];	       
	   
	   
	   for (cc = 0; cc<sim_point;cc++){ // LTSpice corr.  
	     x_true[cc]=(x_true[cc]+1)/2*Dx+Xo;
	     y_true[cc]=(y_true[cc]+1)/2*Dy+Yo;
	     x_rec[cc]=(x_rec[cc]+1)/2*Dx+Xo;
	     y_rec[cc]=(y_rec[cc]+1)/2*Dy+Yo;			
	   }
	  }

  } // corr 1,2

  else if (Correction== 11 || Correction== 12 ){
    ifstream inputFile2 (Filedatacorr);
    if(!inputFile2)
	   cout << "Error: could not find the Data file = "  << Filedatacorr  << endl;
    else{
	   res = 0;
	   cout << "Correction file = " << Filedatacorr << endl;
	   //   inputFile2 >> pippo >> pippo >> pippo  >> pippo;
	   while(1){		  
	     if(inputFile2.eof() || res>8000)
		    break;		 	   
	     inputFile2 >> x_true[res] >>y_true[res] >> x_rec[res]  >> y_rec[res] >> t_rec[res];
	       // rcorrection matrix rotation
	     if (Rangle !=0){
		    xtr = (x_true[res]-(XPa[Xm1]+XPa[Xp2])/2.)*cos (Rangle)-(y_true[res]-(YPa[Ym1]+YPa[Yp2])/2)*sin ( Rangle);
		    ytr = (x_true[res]-(XPa[Xm1]+XPa[Xp2])/2.)*sin( Rangle)+(y_true[res]-(YPa[Ym1]+YPa[Yp2])/2)*cos( Rangle);
		  
		    xrr = (x_rec[res]-(XPa[Xm1]+XPa[Xp2])/2.)*cos (Rangle)-(y_rec[res]-(YPa[Ym1]+YPa[Yp2])/2)*sin ( Rangle);
		    yrr = (x_rec[res]-(XPa[Xm1]+XPa[Xp2])/2.)*sin( Rangle)+(y_rec[res]-(YPa[Ym1]+YPa[Yp2])/2)*cos( Rangle);

		    x_true[res] = xtr+(XPa[Xm1]+XPa[Xp2])/2.;
		    y_true[res] = ytr+(YPa[Ym1]+YPa[Yp2])/2;
		    x_rec[res]  = xrr+(XPa[Xm1]+XPa[Xp2])/2.;
		    y_rec[res] = yrr+(YPa[Ym1]+YPa[Yp2])/2;
		   }  
	       
	     DataCorPointInside[res] = 0;

	       
	     if (y_true[res]>YPa[Ym2]+Distance_Axis_cor &&  y_true[res]>YPa[Ym1]+Distance_Axis_cor && y_true[res]<YPa[Yp2]-Distance_Axis_cor
		      && y_true[res]<YPa[Yp1]-Distance_Axis_cor
		      &&  x_true[res] > XPa[Xm1]+Distance_Axis_cor  && x_true[res] > XPa[Xm2]+Distance_Axis_cor
		      && x_true[res] <XPa[Xp1]-Distance_Axis_cor && x_true[res] <XPa[Xp2]-Distance_Axis_cor)
		        DataCorPointInside[res] = 1;

	     if (DataCorPointInside[res]){
		    XYSignalTime->SetBinContent(XYSignalTime->GetXaxis()->FindBin(x_true[res]),
			  XYSignalTime->GetYaxis()->FindBin(y_true[res]),t_rec[res]+1);
		    XYDelay->SetBinContent(XYDelay->GetXaxis()->FindBin(x_true[res]),XYDelay->GetYaxis()->FindBin(y_true[res]),t_rec[res]+1);
		   }
	     res++;
	   } //while 
	   
	   res--;
	   sim_point = res;
	   cout << " Correction files with " << sim_point << " points inside the pixel" << endl;	   	   
	 }

  }
  
}

void RSD2_Digitizer_Cross13::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

   XCent = (XPa[Xp2]+XPa[Xm1])/2;
   YCent = (YPa[Yp2]+YPa[Ym1])/2;

   cout << "Center of the pixel: "<< XCent << ", "<< YCent << endl;


}

Bool_t RSD2_Digitizer_Cross13::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // When processing keyed objects with PROOF, the object is already loaded
   // and is available via the fObject pointer.
   //
   // This function should contain the \"body\" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.

   fReader.SetLocalEntry(entry);
   unsigned seed = chrono::steady_clock::now().time_since_epoch().count(); 
   default_random_engine generator(seed);
   Noise =  NScale*RMSNoise*pow(1 - AScale*AScale,0.5);
  
   normal_distribution<double> distN(0,Noise);
   
   //  cout << distN(generator) << endl; 
   
   //   default_random_engine generator(seed);


   //   cout << distN(generator) << endl; 

  if (entry == 0){

	  cout << "Additional noise term = " << Noise << " mV" << endl;
	  // Design the pads
	  for (int a = alow; a<ahigh;a++) // bins = 20 um
	    {
	      if(a!=dcchannel)
		{
		  for (int b = -Xarmlenght; b<Xarmlenght;b++) // bins = 20 um
		    XYPads->SetBinContent(XYPads->GetXaxis()->FindBin(XPa[a]+b),XYPads->GetYaxis()->FindBin(YPa[a]),200);
		  for (int b = -Yarmlenght; b<Yarmlenght;b++) // bins = 20 um
		    XYPads->SetBinContent(XYPads->GetXaxis()->FindBin(XPa[a]),XYPads->GetYaxis()->FindBin(YPa[a]+b),200);
		}
	    }
	      
	}
 
 
 XLaser = *XPos;
 YLaser = *YPos;


   if (SquareCut ==10)
     {
       if (XLaser>YLaser+650 || XLaser<YLaser-650 || XLaser<-YLaser+1000 || XLaser>-YLaser+2300) return 0;
     }
   else if (SquareCut ==1)
     {
        if (XLaser>XCent+250 || YLaser>YCent+250 || XLaser<XCent-250 || YLaser<YCent-250) return 0;
     }
      else if (SquareCut ==2)
     {
       if ( ( (XLaser<XCent+250 && XLaser>XCent-250) && ( YLaser>YCent-250  && YLaser<YCent+250) ) 
	    ||   XLaser>XCent+500 || YLaser>YCent+500 || XLaser<XCent-500 || YLaser<YCent-500
	    ) return 0;
     }
      else if (SquareCut ==3)
     {
       if ( ( (XLaser<XCent+500 && XLaser>XCent-500) && ( YLaser>YCent-500  && YLaser<YCent+500) ) 
	    //  ||   XLaser>XCent+500 || YLaser>YCent+500 || XLaser<XCent-500 || YLaser<YCent-500
	    ) return 0;
     }


   if (XLaser>XCent-40 && XLaser<XCent+40 && YLaser>YCent-40 && YLaser<YCent+40){
    for (b=0;b<samples[0]-10;b++){
	   if (dcchannel ==0)        PShapeDCCh->Fill(time[b],m_amp0[b]); // 1000 point = 50 ns
	   else if  (dcchannel ==2)  PShapeDCCh->Fill(time[b],m_amp2[b]); // 1000 point = 50 ns	   
	   
	   }
   }

   if (XLaser>XCent-225 && XLaser<XCent-175 && YLaser>YCent-325 && YLaser<YCent-275)
     {
       for (b=0;b<samples[0]-10;b++)
	 {
	   PShapeXm1->Fill(time[b]-t_max[0]+30,m_amp4[b]); 
	   PShapeXm2->Fill(time[b]-t_max[0]+30,m_amp2[b]); 
	   PShapeXp1->Fill(time[b]-t_max[0]+30,m_amp3[b]); 
	   PShapeXp2->Fill(time[b]-t_max[0]+30,m_amp1[b]);
	 }
     }
	   
   
 // Design the True points
 if (*npos !=nposold){
	 nposold = *npos;
	 XYPos->SetBinContent(XYPos->GetXaxis()->FindBin(XLaser),XYPads->GetYaxis()->FindBin(YLaser),*npos);
	 XTrueArray[*npos] = XLaser;
	 YTrueArray[*npos] = YLaser;
	 LaserPointInside[*npos] = 0;

	 if (YLaser>YPa[Ym1]+Distance_Axis_data && YLaser<YPa[Yp2]-Distance_Axis_data && YLaser>YPa[Ym2]+Distance_Axis_data
	     && YLaser<YPa[Yp1]-Distance_Axis_data
	     && XLaser>XPa[Xm1]+Distance_Axis_data && XLaser<XPa[Xp2]-Distance_Axis_data
	     && XLaser>XPa[Xm2]+Distance_Axis_data && XLaser<XPa[Xp1]-Distance_Axis_data
	     )
	     LaserPointInside[*npos] = 1;
	     if (Correction == 10) LaserPointInside[*npos] = 1;
  }

    ASum = 0;
 
 
       for (int a = 0; a<n_integral_DC;a++){
	   //if (time[a]>DCTimeLow && time[a]<DCTimeHigh)
	     {
	       if (dcchannel ==0) 
		      ASum += m_amp0[a];
	       //ASum +=(m_amp0[a]+m_amp1[a]+m_amp2[a]+m_amp3[a]+m_amp4[a]);
	       else if (dcchannel ==2) 
		      ASum += m_amp2[a];
	       // ASum +=(m_amp0[a]+m_amp1[a]+m_amp2[a]+m_amp3[a]+m_amp4[a]);
	     }

	 }

       ASum *= (time[10]-time[9])*ADCmV*AScale/5.; // in fC
       //    HDCSignal->Fill(area[dcchannel]*ADCmV*AScale);
       if (LaserPointInside[*npos])
	 {
	   if (XLaser>XCent-100 && XLaser<XCent+100 && YLaser>YCent-100 && YLaser < YCent +100)
       //HDCSignal->Fill(fabs(ASum));       
	     HDCSignal->Fill(ASum);       
	 }
   
 // cout << "here 1 " << *XPos << " " << *YPos <<  " " << *npos << endl;
    // Pos. Reconstruction
    XNum = 0;
    YNum = 0;
    XYDen = 0;
    NChMax = 0;
    AMax = 0;

    SignalTotal = 0;
    AllSignalTotal = 0;
    
    //    cout << distN(e) << endl;
   
    for (int a = alow; a<ahigh;a++) // bins = 20 um
      {
	//	if ((a ==1 || a == 3 || a ==5 || a ==12 ) && LaserPointInside[*npos])
	ChanRec = 0;
	Signal[a] = 0;

	if (ampl[a]>AMax)
	  {
	    AMax = ampl[a];
	    NChMax = a;
	  }
	
	 AllSignalTotal +=  (ampl[a]*AScale +distN(generator))*ADCmV;
	
	if (a != dcchannel)  ChanRec=1;

	// Position reconstruction from amplitude weighted position
	if(ChanRec && LaserPointInside[*npos])
	  // if (ampl[a]*AScale>10)
	    {

	      if (UseArea)
		{
		  Signal[a] = area[a]*AScale*ADCmV;
		  SignalTotal +=  Signal[a];
		}
	      else
		{
		  
		  Signal[a] = (ampl[a]*AScale +distN(generator))*ADCmV; // From TDC to mV		
		   if (Signal[a]<-20)
		    {
		      //       Signal[a] = 0;
		    }
		  SignalTotal += Signal[a];		  
		}

	
	      XNum += XPa[a]*Signal[a];	    
	      YNum += YPa[a]*Signal[a];
	      XYDen  += Signal[a];
		  
	    
	    }

      }
  
  
    if (XYDen !=0)
      {
	if (UseWeightedMean)
	  {
	    xmin = XNum/XYDen;
	    ymin = YNum/XYDen;
	  }
	else
	  {
	    xmin = (XPa[Xp2]+XPa[Xm1])/2+(XPa[Xp2]-XPa[Xm1])/2.*(1./kfactor*( (Signal[Xp2]+Signal[Xp1])- (Signal[Xm2]+Signal[Xm1])))/SignalTotal;
	    ymin = (YPa[Yp2]+YPa[Xm1])/2+(YPa[Yp2]-YPa[Xm1])/2.*(1./kfactor*( (Signal[Yp2]+Signal[Yp1])- (Signal[Ym1]+Signal[Ym2])))/SignalTotal;
	     if (xmin<XPa[Xm1]) cout << LaserPointInside[*npos] << " 0  " <<xmin << " " << XLaser << " " << YLaser << " " << Signal[3] << " " << Signal[5] <<  " " << ampl[3] << " " << ampl[5] << endl; 
	    if (UseRotation)
	      {
		xminr = (XPa[Xp2]-XPa[Xm1])/2*(Signal[4]-Signal[1])/(Signal[1]+Signal[4]);// x axis at -45
		yminr = (XPa[Yp2]-XPa[Ym1])/2*(Signal[Xp2]-Signal[Xm1])/(Signal[Xp2]+Signal[Xm1]);//  y axis at +45
		xmin = (XPa[Xp2]+XPa[Xm1])/2+(xminr+yminr)/(1.44);
		ymin = (XPa[Yp2]+XPa[Ym1])/2+(-xminr + yminr)/(1.44);
	      }
	  }

	dif_minx = 1000;
	dif_miny = 1000;
	dif_min = 1000;
	dif = 1000; 

	if (LaserPointInside[*npos])
	  {
	    HSignalTotal->Fill(SignalTotal);	    	    
	    // HDCSignal->Fill(area[dcchannel]*ADCmV*AScale);
	  }
	if (Correction == 1 || Correction == 11)
	  {
	    cor_x = 0;
	    cor_d = 0;
	    cor_nx = 0;
	    cor_ny = 0;
	    weight = 0;
	    for (int ccc = 0;ccc<sim_point;ccc++)
	      {
		//	cout << b+a*grid << endl;
		if (DataCorPointInside[ccc] == 1)
		  {
		    dif = pow(pow((xmin-x_rec[ccc]),2)+pow((ymin-y_rec[ccc]),2),0.5); // distance to the rec. point
		    
		    if ( dif < fabs(dif_min) )
		      {
			dif_min = dif ;
			dif_minx = x_true[ccc] -x_rec[ccc] ;			
			dif_miny = y_true[ccc] -y_rec[ccc];
			res_min = ccc;
		      }		 
		  }		
	      }


	    //    cout << xmin-XLaser  << "  - A2 " << xmin << " " << XLaser  << endl;
	    a = 0;
	    Radius_r = Radius;

	    while(1)
	      {
		for (int ccc = 0;ccc<sim_point;ccc++)
		  {
		    
		    dif = pow(pow((xmin-x_rec[ccc]),2)+pow((ymin-y_rec[ccc]),2),0.5); // distance to the rec. point
		    //		    if (DataCorPointInside[ccc] == 1 && dif<dif_min+Radius_r)
		    if (DataCorPointInside[ccc] == 1 && dif<Radius_r)
		      {
			a++;
			weight= 1./pow(dif,1);

			cor_nx += (x_true[ccc] - x_rec[ccc])*weight;
			cor_ny += (y_true[ccc] - y_rec[ccc])*weight;		    
			cor_d +=  weight;

	       
		    
		      }		
		  }
	

		Radius_r +=10;
		if (a>3) break;
		a=0;
		cor_d = 0;
		cor_nx = 0;
		cor_ny = 0;
		weight = 0;				
	
	      }
	    //	    cout << a << " " << Radius_r << endl;
	    HNumPoint->Fill(a);

	    
	    //	     cout << " a= " << a << endl;	    
	    cor_x = cor_nx/cor_d;
	    cor_y = cor_ny/cor_d;

	    xmin +=  cor_x;	  
	    ymin +=  cor_y;

	    
	  }

	Tcor3 = 0;
	Tcor4 = 0;
	Tcor6 = 0;
	Tcor5 = 0;

	if (Correction ==11 || Correction ==12)
	  {

	    Tcor4 =  XYDelay->GetBinContent(XYDelay->GetXaxis()->FindBin(xmin), XYDelay->GetYaxis()->FindBin(ymin))-1;
	    
	    Tcor3 =   XYDelay->GetBinContent( XYDelay->GetXaxis()->FindBin(XPa[Xp2]-(xmin-XPa[Xm1])),
	    					  XYDelay->GetYaxis()->FindBin(ymin))-1;	    
	    Tcor6 =   XYDelay->GetBinContent( XYDelay->GetXaxis()->FindBin(xmin),
	    					  XYDelay->GetYaxis()->FindBin(YPa[Yp1]-(ymin-YPa[Ym1])))-1;
	    Tcor5 =  XYDelay->GetBinContent( XYDelay->GetXaxis()->FindBin(XPa[Xp2]-(xmin-XPa[Xm1])),
						  XYDelay->GetYaxis()->FindBin(YPa[Yp1]-(ymin-YPa[Ym1])))-1;
	    
	    // Tcor4 =  XYSignalTime->GetBinContent(XYSignalTime->GetXaxis()->FindBin(x_true[*npos]), XYSignalTime->GetYaxis()->FindBin(y_true[*npos]))-1;
	    //Tcor3 =  XYSignalTime->GetBinContent(XYSignalTime->GetXaxis()->FindBin(XPa[Xp2]-(x_true[*npos]-XPa[Xm1])),
	    //					 XYSignalTime->GetYaxis()->FindBin(y_true[*npos]))-1;
	    //	    Tcor6 =  XYSignalTime->GetBinContent(XYSignalTime->GetXaxis()->FindBin(x_true[*npos]),
	    //					 XYSignalTime->GetYaxis()->FindBin(YPa[Yp1]-(y_true[*npos]-YPa[Ym1])))-1;
	    //	    Tcor5 =  XYSignalTime->GetBinContent(XYSignalTime->GetXaxis()->FindBin(XPa[Xp2]-(x_true[*npos]-XPa[Xm1])),
	    //					 XYSignalTime->GetYaxis()->FindBin(YPa[Yp1]-(y_true[*npos]-YPa[Ym1])))-1;
	  }
	//	cout << Tcor3 << endl;
	
	TChannel[3] =  t_max[3]+TDelay[3]+Tcor3;
	TChannel[4] =  t_max[4]+TDelay[4]+Tcor4;       
	TChannel[5] =  t_max[5]+TDelay[5]+Tcor5;      
	TChannel[6] =  t_max[6]+TDelay[6]+Tcor6;       
	TTrigger     = t_max[0];

       //       43
       //	65

	// 	if(xmin> XPa[Xm2] &&  xmin< XPa[Xm2]+250 && ymin<YPa[Xp2] && ymin>YPa[Xp2]-250 )
	// 	  if(xmin> XCent-50 &&  xmin< XCent+50 && ymin>YCent-50 && ymin<YCent+50 )
	if (LaserPointInside[*npos])
	{

	  TNum = 0;
	  TDen = 0;
	  for (int a = alow; a<ahigh;a++) // bins = 20 um
	    {
	      if (a != dcchannel && fabs(TChannel[a]-TChannel[NChMax])<0.5)
		{
		  TNum += TChannel[a]*pow(Signal[a],1);
		  TDen += pow(Signal[a],1);
		  //  cout << "a = " << a << " "  << TChannel[a] << " " << pow(Signal[a],1) << " " << TNum << " " << TDen <<  endl;

		}
	    }
			 // Position reconstruction from amplitude weighted position
			 
	  EventTime = TTrigger-TNum/TDen;
	  //  cout << EventTime << " " << endl;
	  // EventTime =TTrigger-TChannel[4];
	  // EventTime =TTrigger-(TChannel[4]+TChannel[3])/2;
	  if (Correction == 10)
	    EventTime = TTrigger-TChannel[1];

	  
	  HTime->Fill(EventTime);
	  //	    if( EventTime>-1 && EventTime <1 )
	  
	  XYTimeArea->SetBinContent(XYTimeArea->GetXaxis()->FindBin(xmin),XYTimeArea->GetYaxis()->FindBin(ymin),EventTime+1);
	  if (xmin<XPa[Xm1]) cout << LaserPointInside[*npos] << " " <<xmin << " " << XLaser << " " << YLaser << " " << Signal[3] << " " << Signal[5] <<  " " << ampl[3] << " " << ampl[5] << endl; 
	}

	HXPosRec[*npos]->Fill(xmin);
	HYPosRec[*npos]->Fill(ymin);
	HTimeRec[*npos]->Fill(EventTime);
	
	XYSignal->SetBinContent(XYPads->GetXaxis()->FindBin(XLaser),XYPads->GetYaxis()->FindBin(YLaser),SignalTotal);
       	// XYSignal->SetBinContent(XYPads->GetXaxis()->FindBin(xmin),XYPads->GetYaxis()->FindBin(ymin),SignalTotal);

	//	if (xmin>800)
	
	HXAllPosRec->Fill(xmin-XLaser);
	//	if (ymin>800)
	HYAllPosRec->Fill(ymin-YLaser);


	
	HXAllAbsPos->Fill(xmin);
	HYAllAbsPos->Fill(ymin);
      }


    
    if (fabs(ASum)>0){
      XYDCArea->SetBinContent(XYDCArea->GetXaxis()->FindBin(XLaser),XYDCArea->GetYaxis()->FindBin(YLaser),fabs(ASum));
      XYACArea->SetBinContent(XYDCArea->GetXaxis()->FindBin(XLaser),XYDCArea->GetYaxis()->FindBin(YLaser),fabs(AllSignalTotal));
    }
    
   return kTRUE;
}

void RSD2_Digitizer_Cross13::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

  //      dif = 0;

  //cout << " here 2" << endl;
   for (int b=0;b<*npos;b++)
     {
       if ( HXPosRec[b]->GetEntries()>200) // At least 20 entries to perform a fit
	 {
	   if (HXPosRec[b]->GetMean()>10) HXPosRec[b]->Fit("gaus","Q0 tw");    
	   if (HYPosRec[b]->GetMean()>10) HYPosRec[b]->Fit("gaus","Q0 tw");
	   if (HXPosRec[b]->GetFunction("gaus") != NULL) XRecArray[b] =  HXPosRec[b]->GetFunction("gaus")->GetParameter(1);
	   if (HYPosRec[b]->GetFunction("gaus") != NULL) YRecArray[b] =  HYPosRec[b]->GetFunction("gaus")->GetParameter(1);
	   if (HTimeRec[b]->GetFunction("gaus") != NULL) TRecArray[b] =  HTimeRec[b]->GetFunction("gaus")->GetParameter(1);
	 }
       else
	 {
	   XRecArray[b] =  HXPosRec[b]->GetMean();
	   YRecArray[b] =  HYPosRec[b]->GetMean();
	   TRecArray[b] =  HTimeRec[b]->GetMean();
	   
	   XYXOffset->SetBinContent(XYPads->GetXaxis()->FindBin(xmin),XYPads->GetYaxis()->FindBin(ymin),HXPosRec[b]->GetStdDev());
	   //  cout << " offset " << HXPosRec[b]->GetStdDev() << endl;
	   if (HXPosRec[b]->GetStdDev() !=0) HXSigma->Fill(HXPosRec[b]->GetStdDev());
	   if (HYPosRec[b]->GetStdDev() !=0) HYSigma->Fill(HYPosRec[b]->GetStdDev());


	   if (HXPosRec[b]->GetMean() !=0) HXOffset->Fill(HXPosRec[b]->GetMean()-XTrueArray[b] );
	   if (HYPosRec[b]->GetMean() !=0) HYOffset->Fill(HYPosRec[b]->GetMean()-YTrueArray[b] );
	     
	   
	       if (DataCorPointInside[b]==1)
	     {
	       dif = pow(pow(x_true[b]-x_rec[b],2) + pow(y_true[b]-y_rec[b],2), 0.5);
	       HMigration->Fill(dif);
	     }
	 }
     }


   if (Correction == 10)
     {
       
       //       sprintf(histname,Filedatacorr);    
       std::ofstream outfile1 (Filedatacorr);
       std::ofstream outfile2 (NormFiledatacorr); // files written as the LTSPice correction, from -1 to 1
       
       for (b=1;b<*npos;b++) //loop over positions
	 {
	   //	   if (LaserPointInside[b])
	     {
	       outfile1  <<  XTrueArray[b] << " \t " << YTrueArray[b] << " \t " << XRecArray[b] << " \t " << YRecArray[b] << " \t " << TRecArray[b] << std::endl;
	       dif = pow(pow(x_true[b]-x_rec[b],2) + pow(y_true[b]-y_rec[b],2), 0.5);
	       HMigration->Fill(dif);
	     }
	   if (LaserPointInside[b])
	     outfile2  <<  (XTrueArray[b]-XPa[Xm1])/650.-1. << " \t " << (YTrueArray[b]-YPa[Ym1])/650.-1. << " \t " << (XRecArray[b]-XPa[Xm1])/650.-1. << " \t " << (YRecArray[b]-YPa[Ym1])/650.-1. << std::endl;
	   
	 }
       cout << "Writing correction file " << Filedatacorr << endl; 
       cout << "Number of Laser positions " << *npos-1 << endl; 
       outfile1.close();
     }
   
   gr1 = new TGraph(*npos,XRecArray,YRecArray);
   //  gr1 = new TGraph(*npos,XTrueArray,YTrueArray);
   
   cout << " here 3" << endl;
}

void RSD2_Digitizer_Cross13::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.



  sprintf(histname,"C1 Laser Position");
  c1 = new TCanvas("c1",histname,800,800);
  c1->Divide(2,2);

  c1->cd(1);
    XYPos->SetStats(0);
  XYPos->SetTitle("");
   XYPos->Draw("*");
  XYPads->Draw("same");

  TPaveText *pt11 = new TPaveText(TPx1, TPy1,TPx2,TPy2);
  pt11->AddText("True positions");
  pt11->SetTextColor(kRed);
  pt11->Draw();

  c1->cd(2);
  XYPads->SetStats(0);
  XYSignal->SetStats(0);
  XYSignal->SetTitle("");
  XYSignal->Draw("colz");
  XYPads->Draw("same");
  TPaveText *pt12 = new TPaveText(TPx1, TPy1,TPx2,TPy2);
  pt12->AddText("Signal Amplitude");
  pt12->SetTextColor(kRed);
  pt12->Draw();

 c1->cd(3);
  XYPads->Draw();
  gr1->SetMarkerSize(0.2);
  gr1->SetMarkerStyle(107);
  gr1->SetMarkerColor(1);
  gr1->Draw("p same");

  TPaveText *pt13 = new TPaveText(TPx1, TPy1,TPx2,TPy2);
  pt13->AddText("Reconstructed Positions");
  pt13->SetTextColor(kRed);
  pt13->Draw();


  sprintf(histname,"C4 Signal");
  c4 = new TCanvas("c4",histname,800,800);
  c4->Divide(2,2);
  c4->cd(1);

  HSignalTotal->Fit("gaus", "tw");

  c4->cd(2);

  HDCSignal->Rebin(rebin_DC);
  HDCSignal->Fit("gaus", "tw");
  


  
  c4->cd(3);
    XYPads->SetStats(0);
   XYACArea->SetStats(0);
   XYACArea->SetTitle("");
   XYACArea->Draw("colz");
  XYPads->Draw("same");

  c4->cd(4);

    XYPads->SetStats(0);
   XYDCArea->SetStats(0);
   XYDCArea->SetTitle("");
   XYDCArea->Draw("colz");
  XYPads->Draw("same");
    
  sprintf(histname,"C3 Offset & Sigma");
  c3 = new TCanvas("c3",histname,700,700);
  c3->Divide(2,2);

  c3->cd(1);
  HXSigma->Fit("gaus","tw");
  c3->cd(2);
  HYSigma->Fit("gaus","tw");
    c3->cd(3);
  HXOffset->Fit("gaus","tw");
  c3->cd(4);
  HYOffset->Fit("gaus","tw");
    

  
  
  c1->cd(4); 
  XYPads->Draw();
  for (Int_t cc=0; cc< nposold; cc++)
    {
      if (LaserPointInside[cc]==1)
	{
	  //  cout << XTrueArray[cc] << endl;
	  ar[cc] = new TArrow(XTrueArray[cc],YTrueArray[cc],XRecArray[cc],YRecArray[cc],0.01,"|>");      
	  ar[cc]->SetAngle(40);
	  ar[cc]->SetLineColor(2);	 
	  ar[cc]->SetFillColor(2);	 
	  ar[cc]->Draw();
	}
    }
  // TPaveLabel *title = new TPaveLabel(TPx1, 1TPx2,TPx2,1TPx2,"Data Migration","TL");

  TPaveText *pt14 = new TPaveText(TPx1, TPy1,TPx2,TPy2);
  //  TPaveText *pt = new TPaveText(0.2, 0.8,0.4,0.8);
  pt14->AddText("Data Migration");
  pt14->SetTextColor(kRed);
  pt14->Draw();
 
  
  

  if (Correction == 1 || Correction==2 || Correction==11 || Correction==12 )
    {
      sprintf(histname,"C5 Training");
      c5 = new TCanvas("c5",histname,700,700);
      c5->Divide(2,2);
      c5->cd(1);
     
     gr_rec = new TGraph(sim_point,x_rec,y_rec); //where x , y are 2 arrays of n points and draw this graph with option “p”
     gr_true = new TGraph(sim_point,x_true,y_true); //where x , y are 2 arrays of n points and draw this graph with option “p”

     
     //      XYPads->SetTitle("From True to Rec");

     XYPads->SetStats(0);
     XYPads->Draw();    
     gr_true->SetMarkerSize(0.2);
     gr_true->SetMarkerStyle(20);
     gr_true->SetMarkerColor(1);
     gr_true->SetTitle("Pippo");
     gr_true->Draw("p same");

     TPaveText *pt51 = new TPaveText(TPx1, TPy1,TPx2,TPy2);
     pt51->AddText("Laser Position");
     pt51->SetTextColor(kRed);
     pt51->Draw();
     //
 
     
     c5->cd(2);

     
     //     XYPads->SetTitle("Rec positions");
     XYPads->Draw();
     
     gr_rec->SetMarkerSize(0.2);
     gr_rec->SetMarkerStyle(107);
     gr_rec->SetMarkerColor(1);
     gr_rec->Draw("p same");

     TPaveText *pt52 = new TPaveText(TPx1, TPy1,TPx2+100,TPy2);
     pt52->AddText("Reconstructed Position");
     pt52->SetTextColor(kRed);
     pt52->Draw();
     //
   
     c5->cd(3);

     //     XYPads->SetTitle("Migration");

     XYPads->Draw();


       for (cc=0; cc< sim_point; cc++)
       {
	 if (x_rec[cc]>10 && y_rec[cc]>10 &&  DataCorPointInside[cc] == 1)
	   {	     
	     ar_spice[cc] = new TArrow(x_true[cc],y_true[cc],x_rec[cc],y_rec[cc],0.01,"|>");
	     ar_spice[cc]->SetAngle(40);
	     ar_spice[cc]->SetLineColor(4);	 
	     ar_spice[cc]->SetFillColor(4);	 
	     ar_spice[cc]->Draw();
	   }
       }

       TPaveText *pt53= new TPaveText(TPx1, TPy1,TPx2,TPy2);
       pt53->AddText("Migration");
       pt53->SetTextColor(kRed);
       pt53->Draw();

    
  
   c5->cd(4);

     //     XYPads->SetTitle("Migration");

     HMigration->Draw();
     //    cout << "Mean Migration = " << HMigration->GetMean()<<" [um]" << endl;
    }
  sprintf(histname,"C6 Resolution");
  c6 = new TCanvas("c6",histname,900,700);
  c6->Divide(2,2);
  c6->cd(1);

  HXAllPosRec->Rebin(rebin_positions);
  HXAllPosRec->Fit("gaus","tw");

  TPaveText *pt61 = new TPaveText(-190,  HXAllPosRec->GetMaximum()+10,0,HXAllPosRec->GetMaximum()+35);
  pt61->AddText("X position reconstruction");
  pt61->SetTextColor(kRed);
  pt61->Draw();
  //

  
  c6->cd(2);
  
  HYAllPosRec->Rebin(rebin_positions);
  HYAllPosRec->Fit("gaus", "tw");
  

  TPaveText *pt62 = new TPaveText(-190,   HYAllPosRec->GetMaximum()+10,0,HYAllPosRec->GetMaximum()+35);
  pt62->AddText("Y position reconstruction");
  pt62->SetTextColor(kRed);
  pt62->Draw();
  //
  c6->cd(3);
  
  HXAllAbsPos->Draw();

    c6->cd(4);

    //  HYAllAbsPos->SetStats(1);
  HYAllAbsPos->Draw();


  sprintf(histname,"C7 DC");
  c7 = new TCanvas("c7",histname,700,700);
  c7->Divide(2,2);
  c7->cd(1);
  exp2 = new TF1("exp2","exp([0]+x*[1])",0,1000);
  PShapeDCCh->Draw();
  if ( PShapeDCCh->GetEntries()>1000)
    {
      PShapeDCCh->Fit("exp2","Q","",DCTimeLow,DCTimeHigh);
      cout<< left << setw(20) << "RC = " <<setprecision(3) << 1./PShapeDCCh->GetFunction("exp2")->GetParameter(1) << " [ns]" << endl;
    }

  c7->cd(2);
  XYPads->Draw();
  
  sprintf(histname,"C8 AC Signal");
  c8 = new TCanvas("c8",histname,700,700);
  c8->Divide(2,2);
  c8->cd(1);
  
  PShapeXp1->SetMaximum(130);
  PShapeXp2->SetMaximum(130);
  PShapeXm1->SetMaximum(130);
  PShapeXm2->SetMaximum(130);
  PShapeXp1->SetStats(0);
  PShapeXp2->SetStats(0);
  PShapeXm1->SetStats(0);
  PShapeXm2->SetStats(0);
  PShapeXp1->SetTitle("");
  PShapeXp2->SetTitle("");
  PShapeXm1->SetTitle("");
  PShapeXm2->SetTitle("");
  PShapeXm1->SetLineColor(6);
  PShapeXm2->SetLineColor(2);
  PShapeXp1->SetLineColor(3);
  PShapeXp2->SetLineColor(4);

  PShapeXm1->SetMarkerColor(6); 
  PShapeXm2->SetMarkerColor(2); 
  PShapeXp1->SetMarkerColor(3); 
  PShapeXp2->SetMarkerColor(4); 
  
  PShapeXp1->Draw();
  c8->cd(2);

  PShapeXp2->Draw();
  c8->cd(3);
  PShapeXm1->Draw();
  c8->cd(4);
  PShapeXm2->Draw();
  
  cout << "Central position of box (x,y) = " << (XPa[Xp2]+XPa[Xm1])/2<<","<<(YPa[Xp2]+YPa[Xm1])/2 << endl;
  cout << "Mean position of data (x,y) = " << HXAllAbsPos->GetMean()<<","<<HYAllAbsPos->GetMean() << endl;
  cout << "Mean Migration = " << HMigration->GetMean()<<" [um]" << endl;
  cout << "Area = " <<  HDCSignal->GetFunction("gaus")->GetParameter(1) << " [fC], gain =  " << HDCSignal->GetFunction("gaus")->GetParameter(1)*2. << endl;  




  
  sprintf(histname,"C2 Time");
  c2 = new TCanvas("c2",histname,900,700);
  c2->Divide(2,2);


  
  c2->cd(1);
  XYPads->SetStats(0);
  XYSignalTime->SetStats(0);
  XYSignalTime->SetTitle("Signal delay with respect of top left pad");
  XYSignalTime->GetZaxis()->SetRangeUser(0.5, 1.0);
  XYSignalTime->Draw("colz");
  XYPads->Draw("same");

  c2->cd(3);
  XYPads->SetStats(0);
  XYDelay->SetStats(0);
  XYDelay->SetTitle("Signal delay with respect of top left pad");
  XYDelay->GetZaxis()->SetRangeUser(0.5, 1.0);
  XYDelay->Draw("colz");
  XYPads->Draw("same");

  

  c2->cd(2);
  HTime->SetTitle("Trigger - Event Time");
  HTime->Fit("gaus","tw");

 c2->cd(4);
   XYPads->SetStats(0);  
  XYTimeArea->SetStats(0);
  XYTimeArea->SetTitle("Trigger - Event Time");
  XYTimeArea->GetZaxis()->SetRangeUser(0.9, 1.1);
  XYTimeArea->Draw("colz");
  XYPads->Draw("same");

  c1->cd(1);
  /* 
  c2->Divide(3,3);
  b = 0;
  for (a = 240;a<250;a++)
    {
      if (HXPosRec[a]->GetMean()>10)
      {
	if (b<10)
	  {
	    b++;
	    c2->cd(b);
	    HXPosRec[a]->Draw();
	    //HXPosRec[a]->Draw();
	  }
      }

    }
  
  */
}
