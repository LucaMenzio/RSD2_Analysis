#define RSD2_Digitizer_boxes15_cxx
// The class definition in RSD2_Digitizer_boxes15.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.


// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// root> T->Process("RSD2_Digitizer_boxes15.C")
// root> T->Process("RSD2_Digitizer_boxes15.C","some options")
// root> T->Process("RSD2_Digitizer_boxes15.C+")
//


#include "RSD2_Digitizer_boxes15.h"
#include <TH2.h>
#include <TStyle.h>

void RSD2_Digitizer_boxes15::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).


  // 0 = All; 1 = bottom box; 2 = Top box; 3 Top & Bottom Box, 4 Small box // ==5 New data taking (run >= 33)
  // = 6 timing 
  // == 7 W3 data
   NBox = 7; 


   /* = 1 use correction LTSPICE 
      = 2 show correction LTSPICE without using it;
  
      = 10 write the correction file
      = 11 use correction from data; 
      = 12 show correction Data without using it;
   */

   Correction = 11;

   RunNumber = 0; // == 0 for run 30,31,32,33,34,35,37,38. Put bias for run 36 (225, 250, 275,300,330)

                        
   ExpCor = 2; // 

   kxfactor = 1; // best = 0.93
   kyfactor = 1;  // best = 0.58
   Distance_Axis_data = Xarmwidth+20;
   Distance_Axis_train = Xarmwidth+10; 
   
   XOffset = -20;
   YOffset = 100; //80 = 250,300V; 100 = 330V
   Radius = 40; //30;
   Rangle = 0.0* PI / 180.0;  // angle of rotation of training data
   UseArea = 0;
   UseWeightedMean = 0;
   
   MaxDim  = 800;
   TPx1 = 100;
   TPx2 = 600;
   TPy1 = 810;
   TPy2 = 910;

   if (Correction == 10)     Distance_Axis_data  = Distance_Axis_train;
   
   AScale =  1.;// 30./44.;// 10./44. ;// gain X/66; 35, 53,66
   NScale = 1.2;


  DCTimeLow = 20;
  DCTimeHigh = 30;

   if (NBox == 0)
     {
       Xp1 = 1;
       Xp2 = 12;
       Xp3 = 9;
       Xm1 = 6;
       Xm2 = 7;
       Xm3 = 8;
       Yp1 = 13;
       Yp2 = 9;
       Ym1 = 6;
       Ym2 = 4;
       
     }
   else if (NBox == 1)
     {
       
       Xp1 = 1;
       Xp2 = 12;
       Xm1 = 3;
       Xm2 = 5;
       Yp1 = 5;
       Yp2 = 12;
       Ym1 = 3;
       Ym2 = 1;
       Xm0 = 15;
       Ym0 = 15;
       Xm0 = 0;
       Ym0 = 0;
     }
   else if (NBox == 2)
     {
       
       Xp1 = 12;
       Xp2 = 9;
       Xm1 = 5;
       Xm2 = 13;
       Yp1 = 13;
       Yp2 = 9;
       Ym1 = 5;
       Ym2 = 12;
       Xm0 = 14;
       Ym0 = 14;
       Xm0 = 0;
       Ym0 = 0;
     }
   else if (NBox == 3)
     {
       Xp1 = 1;
       Xp2 = 12;
       Xp3 = 9;
       Xm1 = 3;
       Xm2 = 5;
       Xm3 = 13;
       Yp1 = 13;
       Yp2 = 9;
       Ym1 = 3;
       Ym2 = 1;
       Xm0 = 16;
       Ym0 = 16;
     }

   else if (NBox == 4)
     {
       Xp1 = 1;
       Xm1 = 4;
       Yp1 = 1;
       Ym1 = 4;
     }

   else if (NBox == 5)
     {

       MaxDim  = 500;
       for(a=0;a<16;a++)
	 {
	   XPa[a] = 0.;
	   YPa[a] = 0;
	   
	 }
          // new data
   //dcchannel - 0
   //  54
   //  36

       Xp3 = 11;
       Xp2 = 4;
       Xp1 = 6;

       Xm3 = 9;
       Xm2 = 5;
       Xm1 = 3;


       Ypp1 = 9;
       Ypp2 = 11;
       Yp1 = 5;
       Yp2 = 4;


       
       Ym1 = 3;
       Ym2 = 6;

       
       Xm0 = 16;
       Ym0 = 16;

       

       DCTimeLow = 22;
       DCTimeHigh = 32;

       XPa[Xm1] = 0.1;
       XPa[Xm2] = 0.1;
       XPa[Xm3] = 0.1;
       XPa[Xp1] = 330;
       XPa[Xp2] = 330;
       XPa[Xp3] = 330;
       YPa[Ym1] = 0.1;
       YPa[Ym2] = 0.1;
       YPa[Yp1] = 200;
       YPa[Yp2] = 200;
       YPa[Ypp1] = 400;
       YPa[Ypp2] = 400;

       XOffset = 70;
       YOffset = 140;
       
       
     }
  
   else if (NBox == 6){

    MaxDim  = 500;
    for(a=1;a<16;a++){
      XPa[a] = 0.;
      YPa[a] = 0;
    }
          // new data
   //dcchannel - 0


   //  76    
   //  58

       
       TDelay[5] = 0.488;
       TDelay[6] = 0.807;
       TDelay[7] = 0.95;
       TDelay[8] = 0.340;
       

       Ym1 = 6;
       Xm1 = 6;

       Xp1 = 7;
       Ym2 = 7;

       Xm2 = 5;
       Yp1 = 5;

       Xp2 = 8;
       Yp2 = 8;

       DCTimeLow = 22;
       DCTimeHigh = 60;

       XPa[Xm1] = 0.1;
       YPa[Ym1] = 0.1;

       XPa[Xp1] = 435-55;
       YPa[Ym2] = 0.1;

       XPa[Xm2] = 0.1;
       YPa[Yp1] = 200;

       XPa[Xp2] = 330;
       YPa[Yp2] = 210;

       XOffset = 55;
       YOffset = 65;
       
       
     }

 else if (NBox == 7){ //data from W3

  MaxDim  = 500;
  for(a=1;a<16;a++){
    XPa[a] = 0.;
    YPa[a] = 0;
   }
          // new data
   //dcchannel - 0


   //  76    
   //  58

       
   TDelay[5] = 5.368045802007208;
   TDelay[6] = 6.1343113172713055;
   TDelay[7] = 6.5569328201007;
   TDelay[8] = 6.227506611961163;
   
   Xm1 = 6;
   Ym1 = 6;
 
   Xm2 = 5;
   Yp1 = 5;

   Xp1 = 7;
   Ym2 = 7;

   Xp2 = 8;
   Yp2 = 8;

       
       

   DCTimeLow = 8;
   DCTimeHigh = 30;

   XPa[Xm1] = 0.1;
   YPa[Ym1] = 0.1;

   XPa[Xm2] = 0.1;
   YPa[Yp1] = 200;

   XPa[Xp1] = 435 - 55;
   YPa[Ym2] = 0.1;

   XPa[Xp2] = 435 - 55;
   YPa[Yp2] = 200;

   XOffset = 55;
   YOffset = 65;


   const int indexes_pads[4] = {5,6,7,8};
       
  } // ends W3 data 


  for(a=0;a<16;a++)
    {
      if (XPa[a]!=0)  XPa[a] +=XOffset;
      if (YPa[a]!=0)  YPa[a] +=YOffset;
      if (YPa[a]!=0)
	cout << "Pad " << a << " is in " << XPa[a]<<","<<YPa[a] << endl;
    }
   

   
   XCent = (XPa[Xp1]+XPa[Xm1])/2;
   YCent = (YPa[Yp1]+YPa[Ym1])/2;
   cout << "Bin center = " << XCent << " , " << YCent << endl;
   
   nbin = MaxDim/5.;
   
   
   
   sprintf(Filedatacorr,"Migration_xCor%3.2f_yCor%3.2f_NBox%d_UseArea%d_Mean%d_boxes.txt", kxfactor,kyfactor,NBox, UseArea, UseWeightedMean); //Data
   sprintf(FileSpicecorr,"LSPICE_correction/1node/ampcut0mV/table_crosses_0.75k_18.86fF.txt"); //best with 18.86
   //   sprintf(FileSpicecorr,"LSPICE_correction/3node/ampcut0mV/table_crosses_1.0k_2.26fF.txt"); //best with 2.26
   //  sprintf(FileSpicecorr,"LSPICE_correction/1node/ampcut0mV/table_crosses_2.0k_1.29fF.txt"); //best with 1.29
   sprintf(NormFiledatacorr,"Digitizer/Analysis_root/Croci_200x300micron/Norm_Migration_xCor%3.2f_yCor%3.2f_NBox%d_boxes.txt",kxfactor,kyfactor,NBox ); //Data
   sprintf(FileSpicecorr,"Digitizer/Analysis_root/Croci_200x300micron/Norm_Migration_xCor%3.2f_yCor%3.2f_NBox%d_boxes.txt",kxfactor,kyfactor,NBox ); //Data
   sprintf(FileSpicecorr,"Digitizer/Analysis_root/Croci_200x300micron/Norm_Migration_xCor%3.2f_yCor%3.2f_NBox%d_boxes.txt",kxfactor,kyfactor,1 ); //Data
   

  
   TString option = GetOption();

   HTime = new TH1F ("HTime","HTime; Time [ns]; Entries",100, -0.5,0.5);
   sprintf(histname,"W15, Signal time;X [um];Y [um]; Delay + 1 [ns]");       
   XYSignalTime = new TH2F ("XYSignalTime",histname,nbin,0,MaxDim,nbin, 0,MaxDim);   

   sprintf(histname,"W15, Time;X [um];Y [um]; Trigger - Event Time + 1 [ns]");       
   XYTimeArea = new TH2F ("XYTimeArea",histname,nbin,0,MaxDim,nbin, 0,MaxDim);

   sprintf(histname,"W15, Delay;X [um];Y [um]; Delay + 1 [ns]");       
   XYDelay = new TH2F ("XYDelay",histname,nbin,0,MaxDim,nbin, 0,MaxDim);

  sprintf(histname,"");       
  XYPads = new TH2F ("XYPads",";X [um];Y [um]",nbin,0.,MaxDim,nbin, 0.,MaxDim);
  
   sprintf(histname,"W15, Laser shot Positions;X [um];Y [um]");       
   XYPos = new TH2F ("XYPos",histname,nbin,0.,MaxDim,nbin, 0.,MaxDim);

   sprintf(histname,"W15, Signal amplitude;X [um];Y [um]");       
   XYSignal = new TH2F ("XYSignal",histname,nbin,0.,MaxDim,nbin, 0.,MaxDim);

   sprintf(histname,"W15, Struc Rec Pposition");       
   XYRec = new TH2F ("XYRec",histname,nbin,0.,MaxDim,nbin, 0.,MaxDim);

   sprintf(histname,"AC Area ;X [um];Y [um]");       
   XYACArea = new TH2F ("XYACArea",histname,nbin,0,MaxDim,nbin, 0,MaxDim);

   sprintf(histname,"W15, DC Area ;X [um];Y [um]");       
   XYDCArea = new TH2F ("XYDCArea",histname,nbin,0,MaxDim,nbin, 0,MaxDim);

   sprintf(histname,"DC shape;Time [ns]; Amplitude [mV] ");       
   PShapeDCCh = new TProfile("PShaperDCCh",histname, 750, 0, 100.);
   
   for (int b=0;b<9000;b++)
     {
       sprintf(histname,"XPos%d ",b);       
       HXPosRec[b] = new TH1F (histname,histname,MaxDim/2, 0,MaxDim);
       sprintf(histname,"YPos%d ",b);       
       HYPosRec[b] = new TH1F (histname,histname,MaxDim/2, 0,MaxDim);
       sprintf(histname,"Time%d; Time [ns]; Entries",b);       
       HTimeRec[b] = new TH1F (histname,histname,400, -2.,2.);
     }

   sprintf(histname,"Offset (xmin-XLaser); X [um];Entries ");       
   HXOffset = new TH1F ("HXOffset",histname,100, -100,100);
   sprintf(histname,"Offset (Ymin-YLaser); Y [um];Entries");       
   HYOffset = new TH1F ("HYOffsetc",histname,100, -100,100);

    sprintf(histname,"Sigma (xmin-XLaser); X [um];Entries ");       
   HXSigma = new TH1F ("HXSigma",histname,100, -100,100);
   sprintf(histname,"Sigma (ymin - Ylaser); Y [um];Entries");       
   HYSigma = new TH1F ("HYSigma",histname,100, -100,100);


  sprintf(histname,"; Signal Total [mV] ;Entries");       
   HSignalTotal = new TH1F ("HSignalTotal",histname,100, 0, 350. );
   sprintf(histname,"; DC Signal  [pWb] ;Entries");       
   HDCSignal = new TH1F ("HDCSignal",histname,100, 0, 450. );

    
   sprintf(histname,"; # point in migration ;Entries");       
   HNumPoint = new TH1F ("HNumPoint",histname,50, 0, 50. );

   
   sprintf(histname,"; X [um];Entries ");       
   HXAllPosRec = new TH1F ("HXAllPosRec",histname,100, -200,200);
   sprintf(histname,"; Y [um];Entries");       
   HYAllPosRec = new TH1F ("HYAllPosRec",histname,100, -200,200);

 
   
   sprintf(histname,"; X [um];Entries ");       
   HXAllAbsPos = new TH1F ("HXAllAbsPos",histname,100, XPa[Xm1]-50, XPa[Xp1]+50);
   sprintf(histname,"; Y [um];Entries");       
   HYAllAbsPos = new TH1F ("HYAllAbsPos",histname,100, YPa[Ym1]-50, YPa[Yp1]+50 );

   for (a = 0;a<9000;a++)
     {
       DataCorPointInside[a] = 0;
       LaserPointInside[a] = 0;
     }

   if( Correction == 1 || Correction == 2 ){
       
      ifstream inputFile2 (FileSpicecorr);
      if(!inputFile2){
	       cout << "Error: could not find the LTSPICE file " <<  FileSpicecorr << endl;
	     }
   else{
	   res = 0;
	   cout << "LTSPICE file = " << FileSpicecorr << endl;
	   //   inputFile2 >> pippo >> pippo >> pippo  >> pippo;
	   
	   while(1){ //upper limit for safety
	     //	      while(1)
	     		  
	       if(inputFile2.eof()) break;		 	   
	       inputFile2 >> x_true[res] >>y_true[res] >>	x_rec[res]  >> y_rec[res];

	
	       if (y_true[res]>YPa[Ym1]+Distance_Axis_train && y_true[res]<YPa[Yp1]-Distance_Axis_train &&
		         x_true[res] > XPa[Xm1]+Distance_Axis_train && x_true[res] <XPa[Xp1]-Distance_Axis_train)
                DataCorPointInside[res] = 1;

	       res++;
	    }
	   
	   sim_point = res--;
	   
	   Dx = 1;
	   Dy = 1;
	   Xo = 1;
	   Yo = 1;

	   if (NBox == 0){
	       Dx = 510;
	       Dy = 500;
	       Yo = YPa[6];
	       Xo = XPa[6];	       
	    }
	   else if (NBox == 1 || NBox ==5){
	       Dx = 340;
	       Dy = 200;
	       Yo = YPa[Ym1];
	       Xo = XPa[Xm1];	       
	    }
	   else if (NBox == 2){
	       Dx = 340;
	       Dy = 200;
	       Yo = YPa[5];
	       Xo = XPa[5];
     
	    }
	   else if (NBox == 3){
	       Dx = 340;
	       Dy = 400;
	       Yo = YPa[3];
	       Xo = XPa[3];	       
	    }

	  
	   if (NBox ==0 || NBox == 1 || NBox ==2 || NBox == 3 || NBox ==5 || NBox == 7)
	     for (cc = 0; cc<sim_point;cc++) // LTSpice corr.  
	       {
		        x_true[cc]=(x_true[cc]+1)/2*Dx+Xo;
		        y_true[cc]=(y_true[cc]+1)/2*Dy+Yo;
		        x_rec[cc]=(x_rec[cc]+1)/2*Dx+Xo;
		        y_rec[cc]=(y_rec[cc]+1)/2*Dy+Yo;			
		        if (x_true[cc]  == 0.0) cout <<  y_true[cc] << " " << y_rec[cc] << endl;		       
	       }
	  } 

   } // ends if ( Correction != 1,2)

   else if (Correction== 11 || Correction == 12 ){
     
    ifstream inputFile2 (Filedatacorr);
    if(!inputFile2)  cout << "Error: could not find the Data file = "  << Filedatacorr  << endl;
    else{
	     res = 0;
	     cout << "Data file = " << Filedatacorr << endl;
	     //   inputFile2 >> pippo >> pippo >> pippo  >> pippo;
	   
	     while(1) {//upper limit for safety
	     //	      while(1)
	   		  
	       if(inputFile2.eof() || res>9000)
		        break;		 	   
	       inputFile2 >> x_true[res] >>y_true[res] >> x_rec[res]  >> y_rec[res] >> t_rec[res]; ;
	       //  if (x_rec[res] <1) cout << " Empty rec point = " << res << " at " <<  x_true[res] << " , " << y_true[res] << endl;

	       //    xtr = (x_true[res]-xcent)*cos (Rangle)-(y_true[res]-ycent)*sin ( Rangle);
	       // ytr = (x_true[res]-xcent)*sin( Rangle)+(y_true[res]-ycent)*cos( Rangle);
	       // xrr = (x_rec[res]-xcent)*cos (Rangle)-(y_rec[res]-ycent)*sin ( Rangle);
	       // yrr = (x_rec[res]-xcent)*sin( Rangle)+(y_rec[res]-ycent)*cos( Rangle);
	       
	       // x_true[res] = xtr+xcent;
	       // y_true[res] = ytr+ycent;
	       // x_rec[res]  = xrr+xcent;
	       // y_rec[res] = yrr+ycent;

	       
	     if (y_true[res]>YPa[Ym1]+Distance_Axis_train && y_true[res]<YPa[Yp1]-Distance_Axis_train &&
		       x_true[res] > XPa[Xm1]+Distance_Axis_train && x_true[res] <XPa[Xp1]-Distance_Axis_train) {
		
		        DataCorPointInside[res] = 1;
		        //   cout << "Point inside = " << res << " x,y = " << x_true[res] << " " << y_true[res] << endl;
		        pinside++;
		    }

	     if (DataCorPointInside[res]){
		      XYSignalTime->SetBinContent(XYSignalTime->GetXaxis()->FindBin(x_true[res]),
			    XYSignalTime->GetYaxis()->FindBin(y_true[res]),t_rec[res]+1);
		      XYDelay->SetBinContent(XYDelay->GetXaxis()->FindBin(x_true[res]),XYDelay->GetYaxis()->FindBin(y_true[res]),t_rec[res]+1);
		    }

	     res++;

	       
	       
	    } //while
	 	   
	   res--;
	   sim_point = res;
		  
	   
	 } //else

  } //  if correction == 11, 12
  cout << " Correction files with " << sim_point << " points, inside = " << pinside << endl;	   


}


   
void RSD2_Digitizer_boxes15::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();


}

Bool_t RSD2_Digitizer_boxes15::Process(Long64_t entry)
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

   
   if ( RunNumber == *nrun  || RunNumber == 0  )
     {



   unsigned seed = chrono::steady_clock::now().time_since_epoch().count(); 
   default_random_engine generator(seed);
   Noise =  NScale*5.7*pow(1 - AScale*AScale,0.5);
   
   normal_distribution<double> distN(0,Noise);

    if (nentry == 0)
	{

	  //	  cout << "Active channels  " << *nchro << endl;
	  // Design the pads
	  for (int a = 1; a<*nchro;a++) // bins = 20 um
	    {
	      if(XPa[a] >10 && YPa[a]>10)
		{
		  cout << "Drawing pad " << a << endl;

		  for (int b = -Xarmlenght; b<Xarmlenght;b++) // bins = 20 um
		    XYPads->SetBinContent(XYPads->GetXaxis()->FindBin(XPa[a]+b),XYPads->GetYaxis()->FindBin(YPa[a]),200);
		  for (int b = -Yarmlenght; b<Yarmlenght;b++) // bins = 20 um
		    XYPads->SetBinContent(XYPads->GetXaxis()->FindBin(XPa[a]),XYPads->GetYaxis()->FindBin(YPa[a]+b),200);
		}
	    }

	}

    nentry++;



    XLaser = *XPos;
    YLaser = *YPos;
    // Design the True points

   if (XLaser>XCent-40 && XLaser<XCent+40 && YLaser>YCent-40 && YLaser<YCent+40){
    for (b=0;b<samples[0]-10;b++){
	   if (NBox == 6)
	     PShapeDCCh->Fill(time[b],m_amp2[b]); // 1000 point = 50 ns
	   else
	     PShapeDCCh->Fill(time[b],m_amp0[b]); // 1000 point = 50 ns
	   
	  }
   }
   
    
    if (*npos !=nposold)
      {
	//	cout << *npos << " " << nposold << endl;
	LaserPointInside[*npos] = 0;
	nposold = *npos;
	XYPos->SetBinContent(XYPos->GetXaxis()->FindBin(*XPos),XYPads->GetYaxis()->FindBin(*YPos),*npos);
	XTrueArray[*npos] = *XPos;
	YTrueArray[*npos] = *YPos;
	LaserPointInside[*npos] = 0;
	if (*YPos>YPa[Ym1]+Distance_Axis_data && *YPos <= YPa[Yp2]-Distance_Axis_data
	    && *XPos>XPa[Xm1]+Distance_Axis_data && *XPos<XPa[Xp1]-Distance_Axis_data)
	  {
	    if( (*XPos< XCent-Distance_Axis_data ||  *XPos > XCent + Distance_Axis_data)
		&& (*YPos< YCent-Distance_Axis_data || *YPos >YCent+Distance_Axis_data )) // avoid the cross

	      //	    if(Correction == 0 ||( (*YPos<YPa[Ym0]-Distance_Axis_data || *YPos >= YPa[Ym0]+Distance_Axis_data)
	    //			   && (*XPos<XPa[Xm0]-Distance_Axis_data || *XPos>=XPa[Xm0]+Distance_Axis_data)))
	      {
		LaserPointInside[*npos] = 1;
	      }
	  }
	//	if (Correction == 10) LaserPointInside[*npos] = 1;
	    
	//	LaserPointInside[*npos] = 1;
	
	
      }

    

    
    ASum = 0;
    //   if (XLaser<50 && YLaser>200 && YLaser<300)
    {
      for (int a = DCTimeLow*5; a< DCTimeHigh*5;a++)
	{
	  //	   if (time[a]>DCTimeLow && time[a]<DCTimeHigh)
	  if (NBox == 6)
	    ASum +=m_amp2[a];
	  else
	    ASum +=m_amp0[a];
	  //ASum += m_amp0[a]+m_amp1[a]+m_amp12[a]+m_amp3[a]+m_amp14[a];
	}
      ASum *= (time[10]-time[9])*ADCmV*AScale;
      //    HDCSignal->Fill(area[dcchannel]*ADCmV*AScale);
     }

    
    if (LaserPointInside[*npos])
      HDCSignal->Fill((ASum/5.));
    
    // Pos. Reconstruction
    XNum = 0;
    YNum = 0;
    XYDen = 0;
    SignalTotal = 0;
    AllSignalTotal = 0;

    NChMax = 0;
    AMax = 0;
    for (int a = 2; a<*nchro;a++) // bins = 20 um // maybe 10 for W3, ie run 26 and Nbox = 7
      {
	//	if ((a ==1 || a == 3 || a ==5 || a ==12 ) && Inside1[*npos])
	ChanRec = 0;
	if (NBox ==0   && (a ==1 || a == 4 || (a>5 && a <10 ) || a ==12 || a == 13))  ChanRec=1;
	if ((NBox == 1 || NBox == 3 ) && (a ==1 || a == 3 || a ==5 || a ==12 )) ChanRec=1;
	if ((NBox == 2 || NBox == 3 ) && (a ==5 || a == 12 || a == 13 || a ==9 )) ChanRec=1;
	if (NBox == 4 && (a ==3 || a == 7)) ChanRec=1;
	if (NBox == 5 && ( (a > 2 &&  a< 7) )) ChanRec=1;
	if (NBox == 6 && ( a > 4 && a<9  )) ChanRec=1;
  if (NBox == 7 && ( a >= 5 && a <=8  )) ChanRec=1;
	Signal[a] = 0;



	
	if(ChanRec) AllSignalTotal +=  (ampl[a]*AScale + distN(generator))*ADCmV;

	// Position reconstruction from amplitude weighted position
	if(ChanRec && LaserPointInside[*npos])
	  //	  if (ampl[a]*AScale>10)
	    {
	      
	      if (ampl[a]>AMax)
		{
		  AMax = ampl[a];
		  NChMax = a;
		}
	      
	      if (UseArea)
		{
		  Signal[a] = area[a]*AScale;
		  SignalTotal +=  Signal[a];
		}
	      else
		{

		  Signal[a] = ampl[a]*AScale +distN(generator);		
		  SignalTotal += Signal[a];
		}

	      XNum += XPa[a]*Signal[a];	    
	      YNum += YPa[a]*Signal[a];	    
	      XYDen  += Signal[a];
	      

	      
	    }

	//	cout << " NCh = " << NChMax << endl;
		  
     }



    if (LaserPointInside[*npos])
      {
	//	cout << " NCh 2 = " << NChMax << endl;

	HSignalTotal->Fill(SignalTotal*0.247);
	
	//	xmin = XNum/XYDen;
	//	ymin = YNum/XYDen;

	if (UseWeightedMean && XYDen !=0  )
	  {
	    xmin = XNum/XYDen;
	    ymin = YNum/XYDen;
	  }
	else
	  {
	    xmin = (XPa[Xm1]+XPa[Xp1])/2+1./kxfactor*(XPa[Xp1]-XPa[Xm1])/2*( (Signal[Xp1]+Signal[Xp2])- (Signal[Xm1]+Signal[Xm2]))/SignalTotal;
	
	  if (NBox == 0 || NBox ==3)
	  xmin = (XPa[Xm1]+XPa[Xp1])/2+1./kxfactor*(XPa[Xp1]-XPa[Xm1])/2*
	    ( (Signal[Xp1]+Signal[Xp2]+Signal[Xp3])- (Signal[Xm1]+Signal[Xm2]+Signal[Xm3]))/SignalTotal;
	
	  ymin = (YPa[Ym1]+YPa[Yp1])/2+1./kyfactor*(YPa[Yp1]-YPa[Ym1])/2*( (Signal[Yp1]+Signal[Yp2])- (Signal[Ym1]+Signal[Ym2]))/SignalTotal;

	//	xmin = XNum/XYDen;
	//	ymin = YNum/XYDen;
	  }




	if (Correction == 1 || Correction == 11)
	  {
	    a = 0;
	    cor_x = 0;
	    cor_d = 0;
	    cor_nx = 0;
	    cor_ny = 0;
	    weight = 0;
	    //	    for (int ccc = 0;ccc<sim_point;ccc++)
	    //   {
		//	cout << b+a*grid << endl;
	    //	if (DataCorPointInside[ccc] == 1)
	    //	  {
	    //	    dif = pow(pow((xmin-x_rec[ccc]),2)+pow((ymin-y_rec[ccc]),2),0.5); // distance to the rec. point
		    
	    //	    if ( dif < fabs(dif_min) )
	    //	      {
	    //		dif_min = dif ;
	    //		dif_minx = x_true[ccc] - xmin;			
	    //		dif_miny = y_true[ccc] - ymin;
	    //		res_min = ccc;
	    //	      }		 
	    //	  }		
	    //}


	   	    
	    x_rec0[*npos] = 0;
	    y_rec0[*npos] = 0;
	    /*   for (int ccc = 0;ccc<sim_point;ccc++)
	      {
		dif = pow(pow((xmin-x_rec[ccc]),2)+pow((ymin-y_rec[ccc]),2),0.5); // distance to the rec. point
		if (DataCorPointInside[ccc] == 1 && dif<dif_min+Radius)
		  {

		    weight= 1./pow(dif,1);
		    cor_nx += (x_true[ccc] - xmin)*weight;
		    cor_ny += (y_true[ccc] - ymin)*weight;		    
		    cor_d +=  weight;
		    a++;
		  };
	      }
	    */

	    a = 0;
	    
	    Radius_r = Radius;
	    while(1)
	      {
		for (int ccc = 0;ccc<sim_point;ccc++)
		  {
		    //		    if (DataCorPointInside[ccc])  cout << DataCorPointInside[ccc] << " punto = " << ccc << endl;
		    dif = pow(pow((xmin-x_rec[ccc]),2)+pow((ymin-y_rec[ccc]),2),0.5); // distance to the rec. point
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
		if (a>3 || 	Radius_r>100) break;
		a=0;
		cor_d = 0;
		cor_nx = 0;
		cor_ny = 0;
		weight = 0;				
	
	      }

	    if (a <=3 )
	      {
		x_rec0[*npos] = xmin;
		y_rec0[*npos] = ymin;		
		cout << "Too few points for correction: " << a << " X, Y - " << xmin << " " << ymin << " Radius = " << Radius_r <<  endl;
	      }


	    
	    if (cor_d > 0)
	      {
		cor_x = cor_nx/cor_d;
		cor_y = cor_ny/cor_d;

	      }

	    
	    xmin +=  cor_x;	  
	    ymin +=  cor_y;
	  }
      

	//	cout << "x,y = " << xmin << " ," << ymin << endl;
	if (NBox == 6)
	  {

	    
	    Tcor5 = 0;
	    Tcor6 = 0;
	    Tcor7 = 0;
	    Tcor8 = 0;

	    if (Correction ==11 || Correction ==12)
	      {
		Tcor7 =  XYDelay->GetBinContent(XYDelay->GetXaxis()->FindBin(x_true[*npos]), XYDelay->GetYaxis()->FindBin(y_true[*npos]))-1;
		//		Tcor7 =  XYDelay->GetBinContent(XYDelay->GetXaxis()->FindBin(xmin), XYDelay->GetYaxis()->FindBin(ymin))-1;
	
		Tcor6 =   XYDelay->GetBinContent( XYDelay->GetXaxis()->FindBin(XPa[Xp2]-(xmin-XPa[Xm1])),
						  XYDelay->GetYaxis()->FindBin(ymin))-1;	    
		Tcor5 =   XYDelay->GetBinContent( XYDelay->GetXaxis()->FindBin(xmin),
						  XYDelay->GetYaxis()->FindBin(YPa[Yp1]-(ymin-YPa[Ym1])))-1;
		Tcor8 =  XYDelay->GetBinContent( XYDelay->GetXaxis()->FindBin(XPa[Xp2]-(xmin-XPa[Xm1])),
						 XYDelay->GetYaxis()->FindBin(YPa[Yp1]-(ymin-YPa[Ym1])))-1;
		if (Tcor5 == -1) Tcor5 = 0;
		if (Tcor6 == -1) Tcor6 = 0;
		if (Tcor7 == -1) Tcor7 = 0;
		if (Tcor8 == -1) Tcor8 = 0;
	      }
	    
	    TChannel[5] =  t_max[5]+TDelay[5]+Tcor5;
	    TChannel[6] =  t_max[6]+TDelay[6]+Tcor6;       
	    TChannel[7] =  t_max[7]+TDelay[7]+Tcor7;       
	    TChannel[8] =  t_max[8]+TDelay[8]+Tcor8;       
	    TTrigger     = t_max[0];
	    

	    
	    //	    if (Correction !=10)
	    //  if(Correction ==10 || (xmin< XPa[Xm2]+100 &&  xmin> XPa[Xm2] && ymin<YPa[Yp1] && ymin>YPa[Yp1]-100) ) // ch 7
	    //	    if(Correction == 10 || (xmin< XPa[Xm2]+100 &&  xmin> XPa[Xm2] && ymin>YPa[Ym1] && ymin<YPa[Ym1]+100) ) // ch 5
		      //   if(Correction == 10 || (xmin< XPa[Xp1] &&  xmin> XPa[Xp1]-100 && ymin>YPa[Ym2] && ymin<YPa[Ym2]+100) ) // ch 8
	    //  if(Correction == 10 || (xmin< XPa[Xp1] &&  xmin> XPa[Xp1]-100 && ymin<YPa[Yp2] && ymin>YPa[Yp2]-100) ) // ch 6
	    //   if (ymin>YCent)
	    if (LaserPointInside[*npos])
	      {
		
		TNum =0;
		TDen = 0;
		for (int a = 5; a<9;a++) // bins = 20 um
		  {
		    if (fabs(TChannel[a]-TChannel[NChMax])<0.3)
		      {
			TNum += TChannel[a]*pow(Signal[a],1);
			TDen +=pow(Signal[a],1);
			//	cout << "a = " << a << " "  << TChannel[a] << " " << pow(Signal[a],1) << " " << NChMax <<  endl;
			
		      }
		  }
		// Position reconstruction from amplitude weighted position
		
		EventTime = TTrigger-TNum/TDen;
		//  cout << EventTime << " " << endl;

		
		//	EventTime =TTrigger-TChannel[7];
		// EventTime =TTrigger-(TChannel[4]+TChannel[3])/2;
		if (Correction == 10)
		  EventTime =TTrigger-TChannel[7];
		
		
		HTime->Fill(EventTime);
		//	    if( EventTime>-1 && EventTime <1 )
		
		XYTimeArea->SetBinContent(XYTimeArea->GetXaxis()->FindBin(xmin),XYTimeArea->GetYaxis()->FindBin(ymin),EventTime+1);
	      }
	  }


	
	
	HXPosRec[*npos]->Fill(xmin);
	HYPosRec[*npos]->Fill(ymin);
	HTimeRec[*npos]->Fill(EventTime);
	HNumPoint->Fill(a);

	//	XYSignal->SetBinContent(XYPads->GetXaxis()->FindBin(xmin),XYPads->GetYaxis()->FindBin(ymin),SignalTotal);
	XYSignal->SetBinContent(XYPads->GetXaxis()->FindBin(XLaser),XYPads->GetYaxis()->FindBin(YLaser),SignalTotal);
	
	HXAllPosRec->Fill(xmin-*XPos);
	HYAllPosRec->Fill(ymin-*YPos);

	HXAllAbsPos->Fill(xmin);
	HYAllAbsPos->Fill(ymin);
      }
    
    if (fabs(ASum) >0)
      {
	XYDCArea->SetBinContent(XYDCArea->GetXaxis()->FindBin(XLaser),XYDCArea->GetYaxis()->FindBin(YLaser),fabs(ASum));
	XYACArea->SetBinContent(XYDCArea->GetXaxis()->FindBin(XLaser),XYDCArea->GetYaxis()->FindBin(YLaser),fabs(AllSignalTotal));
      }
    //    if (*event<300 && XNum/XYDen>10) cout << "x = " << XNum/XYDen << " X true = " <<  *XPos << "y = " << YNum/XYDen << " Y true = " <<  *YPos << endl;

     }
    
   return kTRUE;
}

void RSD2_Digitizer_boxes15::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.


   for (int b=0;b<nposold;b++)
     {
       if ( HXPosRec[b]->GetEntries()>50) // At least 20 entries to perform a fit
	 {
	   if (HXPosRec[b]->GetMean()>10) HXPosRec[b]->Fit("gaus","Q0 tw");    
	   if (HYPosRec[b]->GetMean()>10) HYPosRec[b]->Fit("gaus","Q0 tw");
	   if (HXPosRec[b]->GetFunction("gaus") != NULL) XRecArray[b] =  HXPosRec[b]->GetFunction("gaus")->GetParameter(1);
	   if (HYPosRec[b]->GetFunction("gaus") != NULL) YRecArray[b] =  HYPosRec[b]->GetFunction("gaus")->GetParameter(1);
	   if (HTimeRec[b]->GetFunction("gaus") != NULL) TRecArray[b] =  HTimeRec[b]->GetFunction("gaus")->GetParameter(1);
	 }
       else if (HXPosRec[b]->GetEntries()>10 && HXPosRec[b]->GetEntries()<=50) 
	 {
	   XRecArray[b] =  HXPosRec[b]->GetMean();
	   YRecArray[b] =  HYPosRec[b]->GetMean();
	   TRecArray[b] =  HTimeRec[b]->GetMean();
	   //   cout << "b = " << b << " " << TRecArray[b] << endl;
	   
	   if (HXPosRec[b]->GetStdDev() !=0) HXSigma->Fill(HXPosRec[b]->GetStdDev());
	   if (HYPosRec[b]->GetStdDev() !=0) HYSigma->Fill(HYPosRec[b]->GetStdDev());
	   if (HXPosRec[b]->GetMean() !=0) HXOffset->Fill(HXPosRec[b]->GetMean()-XTrueArray[b] );
	   if (HYPosRec[b]->GetMean() !=0) HYOffset->Fill(HYPosRec[b]->GetMean()-YTrueArray[b] );
	 }
     }


   if (Correction == 10)
     {
       
       //       sprintf(histname,Filedatacorr);    
       std::ofstream outfile1 (Filedatacorr);
       for (b=1;b<nposold;b++) //loop over positions
	 {
	   //	   if (LaserPointInside[b])
	     {
	       outfile1  <<  XTrueArray[b] << " \t " << YTrueArray[b] << " \t " << XRecArray[b] << " \t " << YRecArray[b] <<  " \t " << TRecArray[b] <<  std::endl;
	      
	     }
	 }
       cout << "Writing correction file " << Filedatacorr << endl; 
       cout << "Number of Laser positions " << *npos-1 << endl; 
       outfile1.close();
     }
   
   gr1 = new TGraph(nposold,XRecArray,YRecArray);
  

}

void RSD2_Digitizer_boxes15::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.



  sprintf(histname,"C1 Laser Position");
  c1 = new TCanvas("c1",histname,900,700);
  c1->Divide(2,2);

  c1->cd(1);
  XYPos->SetTitle("");
  XYPos->Draw("colz");
  XYPads->Draw("same");
  // XYPads->Draw();

  TPaveText *pt11 = new TPaveText(TPx1, TPy1,TPx2,TPy2);
  pt11->AddText("Position Number");
  pt11->SetTextColor(kRed);
  pt11->Draw();

  c1->cd(2);
  
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
    

  sprintf(histname,"C4 Signal");
  c4 = new TCanvas("c4",histname,800,800);
  c4->Divide(2,2);
  c4->cd(1);

  HSignalTotal->Fit("gaus", "tw");

  c4->cd(2);

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


  



  if (Correction == 1 || Correction==2 || Correction==11 || Correction==12 )
    {
      sprintf(histname,"C5 LTSpice");
      c5 = new TCanvas("c5",histname,900,700);
      c5->Divide(2,2);
      c5->cd(1);
     
     gr_rec = new TGraph(sim_point,x_rec,y_rec); //where x , y are 2 arrays of n points and draw this graph with option “p”
     gr_true = new TGraph(sim_point,x_true,y_true); //where x , y are 2 arrays of n points and draw this graph with option “p”
     gr_rec0 = new TGraph(sim_point,x_rec0,y_rec0); //where x , y are 2 arrays of n points and draw this graph with option “p”
     
     //      XYPads->SetTitle("From True to Rec");

     XYPads->Draw();    
     gr_true->SetMarkerSize(0.2);
     gr_true->SetMarkerStyle(20);
     gr_true->SetMarkerColor(1);
     gr_true->SetTitle("Pippo");
     gr_true->Draw("p same");

     TPaveText *pt51 = new TPaveText(TPx1, TPy1,TPx2,TPy2);
     pt51->AddText("Laser Position of training data");
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

     TPaveText *pt52 = new TPaveText(TPx1, TPy1,TPx2,TPy2);
     pt52->AddText("Reconstructed Position of training data");
     pt52->SetTextColor(kRed);
     pt52->Draw();

     c5->cd(3);

     
     //     XYPads->SetTitle("Rec positions");
     XYPads->Draw();
     
     gr_rec0->SetMarkerSize(0.2);
     gr_rec0->SetMarkerStyle(107);
     gr_rec0->SetMarkerColor(1);
     gr_rec0->Draw("p same");

     TPaveText *pt53 = new TPaveText(TPx1, TPy1,TPx2,TPy2);
     pt53->AddText("Position with too few cor. points");
     pt53->SetTextColor(kRed);
     pt53->Draw();
     //
     //
   
     c5->cd(4);

     //     XYPads->SetTitle("Migration");

     XYPads->Draw();


        for (cc= 0; cc< sim_point; cc++)
       {
	 if (DataCorPointInside[cc])
	   {
	     if (x_rec[cc] >1)
	       {
		 ar_spice[cc] = new TArrow(x_true[cc],y_true[cc],x_rec[cc],y_rec[cc],0.01,"|>");
		 ar_spice[cc]->SetAngle(40);
		 ar_spice[cc]->SetLineColor(4);	 
		 ar_spice[cc]->SetFillColor(4);	 
		 ar_spice[cc]->Draw();
	       }
	   }
       }

       TPaveText *pt54= new TPaveText(TPx1, TPy1,TPx2,TPy2);
       pt54->AddText("Migration of training data");
       pt54->SetTextColor(kRed);
       pt54->Draw();

    }

  sprintf(histname,"C6 Resolution");
  c6 = new TCanvas("c6",histname,900,700);
  c6->Divide(2,2);
  c6->cd(1);

  HXAllPosRec->Fit("gaus","tw");

  TPaveText *pt61 = new TPaveText(-190,  HXAllPosRec->GetMaximum()+20,0,HXAllPosRec->GetMaximum()+50);
  pt61->AddText("X position reconstruction");
  pt61->SetTextColor(kRed);
  pt61->Draw();
  //

  
  c6->cd(2);
  
  HYAllPosRec->Fit("gaus", "tw");
  

  TPaveText *pt62 = new TPaveText(-190,   HYAllPosRec->GetMaximum()+20,0,HYAllPosRec->GetMaximum()+50);
  pt62->AddText("Y position reconstruction");
  pt62->SetTextColor(kRed);
  pt62->Draw();


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
      PShapeDCCh->Fit("exp2","Q","",DCTimeLow+6,DCTimeHigh+20);
      cout<< left << setw(20) << "RC = " <<setprecision(3) << 1./PShapeDCCh->GetFunction("exp2")->GetParameter(1) << " [ns]" << endl;
    }


 c7->cd(2);
 HTime->SetTitle("Trigger - Event Time");
 HTime->Fit("gaus","tw");

   c7->cd(3);
  XYPads->SetStats(0);
  XYDelay->SetStats(0);
  XYDelay->SetTitle("Signal delay with respect of top left pad");
  XYDelay->GetZaxis()->SetRangeUser(0.5, 1.0);
  XYDelay->Draw("colz");
  XYPads->Draw("same");

  c7->cd(4);
  XYPads->SetStats(0);  
  XYTimeArea->SetStats(0);
  XYTimeArea->SetTitle("Trigger - Event Time");
  XYTimeArea->GetZaxis()->SetRangeUser(0.5, 1.5);
  XYTimeArea->Draw("colz");
  XYPads->Draw("same");
  

  cout << "Central position of box (x,y) = " << (XPa[Xp1]+XPa[Xm1])/2<<","<<(YPa[Yp1]+YPa[Ym1])/2 << endl;
  cout << "Mean position of data (x,y) = " << HXAllAbsPos->GetMean()<<","<<HYAllAbsPos->GetMean() << endl;
  
  cout << "Area = " <<  HDCSignal->GetFunction("gaus")->GetParameter(1) << " [pWb], gain =  " << HDCSignal->GetFunction("gaus")->GetParameter(1)*2. << endl;  
  cout << "Sum of 4 amplitudes = " <<  HSignalTotal->GetFunction("gaus")->GetParameter(1) << endl;    

  
  //

  /*
  
  sprintf(histname,"C2 XPos");
  c2 = new TCanvas("c2",histname,900,700);
  c2->Divide(5,5);
  b = 0;
  for (a = 0;a<*npos;a++)
    {
      if (HXPosRec[a]->GetMean()>10)
      {
	if (b<26)
	  {
	    b++;
	    c2->cd(b);
	    HXPosRec[a]->Draw();
	  }
      }

    }

  */
}
