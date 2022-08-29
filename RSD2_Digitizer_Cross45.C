#define RSD2_Digitizer_Cross45_cxx
// The class definition in RSD2_Digitizer_Cross45.h has been generated automatically
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
// root> T->Process("RSD2_Digitizer_Cross45.C")
// root> T->Process("RSD2_Digitizer_Cross45.C","some options")
// root> T->Process("RSD2_Digitizer_Cross45.C+")
//


#include "RSD2_Digitizer_Cross45.h"
#include <TH2.h>
#include <TStyle.h>

void RSD2_Digitizer_Cross45::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

   
    /* = 1 use correction LTSPICE 
      = 2 show correction LTSPICE without using it;
  
      = 10 write the correction file
      = 11 use correction from data; 
      = 12 show correction Data without using it;
   */

   Correction = 11;

   rebin_HDC = 2;
 
   ExpCor = 2; // 

   kxfactor = 1; //0.84; // 0.8
   kyfactor = 1; //0.84; 
   Distance_Axis = Xarmwidth+10;
   Radius = 20;
   UseWeightedMean = 0;
   UseArea = 0;
   UseRotation = 0;
   Rangle = 0* PI / 180.0;  // angle of rotation of training data

   datataking = 2; // 1 = new data taking //2 = W3 datataking 

   AScale = 1; //0./42. ;// gain X/66; 35, 53,66
   NScale = 1.2;
   
   XOffset = 0;
   YOffset = 0; //Nbox = 1 80
   n_integral_DC = 1000;


   if (datataking ==0){
       Xm1 = 7;
       Xm2 = 6;
       Xp1 = 5;
       Xp2 = 4;
       
       Ym1 = 7;
       Ym2 = 5;
       Yp1 = 6;
       Yp2 = 4;

       MaxDim  = 1000;
       MinDim  = 200;
     }
   else if (datataking ==1){
       
       dcchannel = 0;
       Xm1 = 1;
       Xm2 = 12;
       Xp1 = 3;
       Xp2 = 14;
       
       Ym1 = 1;
       Ym2 = 3;
       Yp1 = 12;
       Yp2 = 14;

      
       XOffset = 140;
       YOffset = 115; //Nbox = 1 80

       XPa[Xm1] = 0;
       XPa[Xm2] = 0;
       XPa[Xp1] = 450;
       XPa[Xp2] = 450;
       YPa[Ym1] = 0;
       YPa[Ym2] = 0;
       YPa[Yp1] = 450;
       YPa[Yp2] = 450;

       TDelay[12] = 0.409;
       TDelay[14] = 0.388;
       
       MaxDim  = 800;
       MinDim  = 0;
       

       DCTimeLow = 20;
       DCTimeHigh = 100;
     }

   else if (datataking ==2){

       //please always use the crosses positions stricly with these pairs:
       // (Xm1,Ym1) -- (Xm2,Yp1) -- (Xp1,Ym2) -- (Xp2,Yp2)
       dcchannel = 0;
       Xm1 = 10;
       Xm2 = 5;
       Xp1 = 13;
       Xp2 = 2;
       
       Ym1 = 10;
       Ym2 = 13;
       Yp1 = 5;
       Yp2 = 2;

      
       XOffset = 0;
       YOffset = 0; //Nbox = 1 80

       //original coordinates, before rotation
       XPa[Xm1] = 465;
       XPa[Xm2] = 480;
       XPa[Xp1] = 915;
       XPa[Xp2] = 925;
       YPa[Ym1] = 95;
       YPa[Ym2] = 75;
       YPa[Yp1] = 545;
       YPa[Yp2] = 525;

       //cout << "mean along the diagonal before rotation: (" << (XPa[Xp2] + XPa[Xm1])/2<< "," << (YPa[Yp2] + YPa[Ym1])/2<<")" << endl;

       cout << "Reconstruction matrix rotation angle: " << Rangle*180/PI << " degrees" << endl;
       RangleLasPos = 3*PI/180.; //rotation angle for the laser (and crosses) points
       cout << "Laser points rotation angle: " << RangleLasPos*180/PI << " degrees" << endl;

       if(RangleLasPos!=0){
        //rotating the crosses positions
        XPa_old[Xm1] = XPa[Xm1];
        XPa_old[Xm2] = XPa[Xm2];
        XPa_old[Xp1] = XPa[Xp1];
        XPa_old[Xp2] = XPa[Xp2];
        YPa_old[Ym1] = YPa[Ym1];
        YPa_old[Ym2] = YPa[Ym2];
        YPa_old[Yp1] = YPa[Yp1];
        YPa_old[Yp2] = YPa[Yp2];

        float xcentre = (XPa_old[Xm1]+XPa_old[Xp2])/2., ycentre = (YPa_old[Ym1]+YPa_old[Yp2])/2.;

        XPa[Xm1] = (XPa_old[Xm1] - xcentre)*cos(RangleLasPos) - (YPa_old[Ym1] - ycentre)*sin(RangleLasPos) + xcentre; 
        XPa[Xm2] = (XPa_old[Xm2] - xcentre)*cos(RangleLasPos) - (YPa_old[Yp1] - ycentre)*sin(RangleLasPos) + xcentre; 
        XPa[Xp1] = (XPa_old[Xp1] - xcentre)*cos(RangleLasPos) - (YPa_old[Ym2] - ycentre)*sin(RangleLasPos) + xcentre; 
        XPa[Xp2] = (XPa_old[Xp2] - xcentre)*cos(RangleLasPos) - (YPa_old[Yp2] - ycentre)*sin(RangleLasPos) + xcentre; 

        YPa[Ym1] = (XPa_old[Xm1] - xcentre)*sin(RangleLasPos) + (YPa_old[Ym1] - ycentre)*cos(RangleLasPos) + ycentre; 
        YPa[Ym2] = (XPa_old[Xp1] - xcentre)*sin(RangleLasPos) + (YPa_old[Ym2] - ycentre)*cos(RangleLasPos) + ycentre; 
        YPa[Yp1] = (XPa_old[Xm2] - xcentre)*sin(RangleLasPos) + (YPa_old[Yp1] - ycentre)*cos(RangleLasPos) + ycentre; 
        YPa[Yp2] = (XPa_old[Xp2] - xcentre)*sin(RangleLasPos) + (YPa_old[Yp2] - ycentre)*cos(RangleLasPos) + ycentre;
        //cout << "mean along the diagonal after rotation: (" << xcentre << "," << ycentre <<")" << endl;
       }


       TDelay[2] = 5.657768286139561;
       TDelay[5] = 5.8349734994484646;
       TDelay[10] = 5.916778348798859;
       TDelay[13] = 6.273456340292286;
       
       MaxDim  = 1100;
       MinDim  = 0;
       

       DCTimeLow = 20;
       DCTimeHigh = 100;
     }
       
    nbin = (MaxDim-MinDim)/5;
    TPx1 = MinDim;
    TPx2 = MinDim+300;
    TPy1 = MaxDim;
    TPy2 = MaxDim+100;
   

  for(a=0;a<15;a++){
      if (a ==Xm1 || a == Xm2 || a ==Xp1 || a ==Xp2){
       XPa[a] +=XOffset;
       YPa[a] +=YOffset;
       cout << "Pad " << a << " is in (" << XPa[a]<<", "<<YPa[a] << ")" << endl;
     }
    }
     
  //sprintf(Filedatacorr,"Digitizer/Analysis_root/Croci_450micron/Migration_Cor%3.2f_UseArea%d_UseMean%d_datataking%d_Cross45.txt", kxfactor, UseArea, UseWeightedMean,datataking); //Data
  sprintf(Filedatacorr,"Migration_Cor%3.2f_UseArea%d_UseMean%d_datataking%d_Cross45.txt", kxfactor, UseArea, UseWeightedMean,datataking); //Data
  sprintf(Filetimecorr,"Delay_Cor%3.2f_UseArea%d_UseMean%d_datataking%d_Cross45.txt", kxfactor, UseArea, UseWeightedMean,datataking); //Data
  sprintf(FileSpicecorr,"LSPICE_correction/1node/ampcut0mV/table_crosses_0.75k_18.86fF.txt"); //best with 18.86

 
  //new

  sprintf(histname,"");       
  XYPads = new TH2F ("XYPads",";X [um];Y [um]",nbin,MinDim,MaxDim,nbin, MinDim,MaxDim);
  sprintf(histname,"W15, Laser shot Positions;X [um];Y [um]");       
  XYPos = new TH2F ("XYPos",histname,nbin,MinDim,MaxDim,nbin, MinDim,MaxDim);

  sprintf(histname,"W15, Signal amplitude;X [um];Y [um]");       
  XYSignal = new TH2F ("XYSignal",histname,nbin,MinDim,MaxDim,nbin, MinDim,MaxDim);

  sprintf(histname,"W15, Signal time;X [um];Y [um]");       
  XYSignalTime = new TH2F ("XYSignalTime",histname,nbin,MinDim,MaxDim,nbin, MinDim,MaxDim);

  sprintf(histname,"W15, Time;X [um];Y [um]");       
  XYTimeArea = new TH2F ("XYTimeArea",histname,nbin,MinDim,MaxDim,nbin, MinDim,MaxDim);
  sprintf(histname,"W15, Delay;X [um];Y [um]");       
  XYDelay = new TH2F ("XYDelay",histname,MaxDim/20,MinDim,MaxDim,MaxDim/20, MinDim,MaxDim);

   sprintf(histname,"W15, DC Area ;X [um];Y [um]");       
   XYDCArea = new TH2F ("XYDCArea",histname,nbin,MinDim,MaxDim,nbin, MinDim,MaxDim);

   sprintf(histname,"W15, Struc Rec Pposition");       
   XYRec = new TH2F ("XYRec",histname,nbin,MinDim,MaxDim,nbin, MinDim,MaxDim);

   sprintf(histname,"DC shape;Time [ns]; Amplitude [mV] ");       
   PShapeDCCh = new TProfile("PShaperDCCh",histname, 750, 0, 150.);

   for (int b=0;b<8000;b++)
     {
       sprintf(histname,"XPos%d ",b);       
       HXPosRec[b] = new TH1F (histname,histname,200, MinDim,MaxDim);
       sprintf(histname,"YPos%d ",b);       
       HYPosRec[b] = new TH1F (histname,histname,200, MinDim,MaxDim);
       sprintf(histname,"Time%d ",b);       
       HTimeRec[b] = new TH1F (histname,histname,100, -0.5,.5);
     }

   sprintf(histname,"; X [um];Entries ");       
   HXAllPosRec = new TH1F ("Xall",histname,100, -200,200);
   sprintf(histname,"; Y [um];Entries");       
   HYAllPosRec = new TH1F ("Yall",histname,100, -200,200);

   HTime = new TH1F ("HTime","HTime",100, -0.5,.5);
   
   sprintf(histname,"; X [um];Entries ");       
   HXAllAbsPos = new TH1F ("HXAllAbsPos",histname,100, XPa[Xm1]-50, XPa[Xp1]+50);
   sprintf(histname,"; Y [um];Entries");       
   HYAllAbsPos = new TH1F ("HYAllAbsPos",histname,100, YPa[Ym1]-50, YPa[Yp1]+50 );

   sprintf(histname,"; AC Signal Total [mV] ;Entries");       
   HSignalTotal = new TH1F ("HSignalTotal",histname,100, 0, 500. );

   sprintf(histname,"; DC Signal  [fC] ;Entries");       
   HDCSignal = new TH1F ("HDCSignal",histname,200, -100, +100. );
   
   sprintf(histname,"; Shift  [um] ;Entries");       
   HMigration = new TH1F ("HMigration",histname,100, 0, 350. );
   
   sprintf(histname,"; Point ;Entries");       
   HNumPoint = new TH1F ("HNumPoint",histname,50, 0, 50. );

   sprintf(histname,"Sigma (xmin-XLaser); X [um];Entries ");       
   HXSigma = new TH1F ("HXSigma",histname,100, -100,100);
   sprintf(histname,"Sigma (ymin - Ylaser); Y [um];Entries");       
   HYSigma = new TH1F ("HYSigma",histname,100, -100,100);

   
   sprintf(histname,"Offset (xmin-XLaser); X [um];Entries ");       
   HXOffset = new TH1F ("HXOffset",histname,100, -100,100);
   sprintf(histname,"Offset (ymin-YLaser); Y [um];Entries");       
   HYOffset = new TH1F ("HYOffsetc",histname,100, -100,100);

   if(Correction == 1 || Correction == 2 ){
       
       ifstream inputFile2 (FileSpicecorr);
       if(!inputFile2)
        cout << "Error: could not find the LTSPICE file" << endl;
       else{
        res = 0;
        cout << "LTSPICE file = " << FileSpicecorr << endl;
        //   inputFile2 >> pippo >> pippo >> pippo  >> pippo;
        
        while(1){      
            if(inputFile2.eof() || res>8000)
              break;        
            inputFile2 >> x_true[res] >>y_true[res] >> x_rec[res]  >> y_rec[res];
            res++;
          }
        
        res--;
        sim_point = res;
        cout << " LTSPICE file with " << res << " points" << endl;
        
        
        Dx = 1300;
        Dy = 1300;
        Yo = YPa[3];
        Xo = XPa[3];        
     
     
        for (cc = 0; cc<sim_point;cc++){
            x_true[cc]=(x_true[cc]+1)/2*Dx+Xo;
            y_true[cc]=(y_true[cc]+1)/2*Dy+Yo;
            x_rec[cc]=(x_rec[cc]+1)/2*Dx+Xo;
            y_rec[cc]=(y_rec[cc]+1)/2*Dy+Yo;     
            if (x_true[cc]  == 0.0) cout <<  y_true[cc] << " " << y_rec[cc] << endl;          
          }
     
     
      }

   }
   else if (Correction== 11 || Correction== 12 ){
       ifstream inputFile2 (Filedatacorr);
       if(!inputFile2)
          cout << "Error: could not find the Data file = "  << Filedatacorr  << endl;
       else{
          res = 0;
          cout << "Data file = " << Filedatacorr << endl;
          //   inputFile2 >> pippo >> pippo >> pippo  >> pippo;
          
          while(1){      
              if(inputFile2.eof() || res>8000)
                break;        
              inputFile2 >> x_true[res] >>y_true[res] >> x_rec[res]  >> y_rec[res] >> t_rec[res] ;
              
              if(RangleLasPos!=0){
                xtr = (x_true[res]-(XPa[Xm1]+XPa[Xp2])/2.)*cos(RangleLasPos) - (y_true[res]-(YPa[Ym1]+YPa[Yp2])/2)*sin(RangleLasPos) + (XPa[Xm1]+XPa[Xp2])/2.;
                ytr = (x_true[res]-(XPa[Xm1]+XPa[Xp2])/2.)*sin(RangleLasPos) + (y_true[res]-(YPa[Ym1]+YPa[Yp2])/2)*cos(RangleLasPos) + (YPa[Ym1]+YPa[Yp2])/2.;
                x_true[res] = xtr;
                y_true[res] = ytr;
              }
              if (Rangle !=0){
                xtr = (x_true[res]-(XPa[Xm1]+XPa[Xp2])/2.)*cos(Rangle) - (y_true[res]-(YPa[Ym1]+YPa[Yp2])/2)*sin(Rangle);
                ytr = (x_true[res]-(XPa[Xm1]+XPa[Xp2])/2.)*sin(Rangle) + (y_true[res]-(YPa[Ym1]+YPa[Yp2])/2)*cos(Rangle);
                
                xrr = (x_rec[res]-(XPa[Xm1]+XPa[Xp2])/2.)*cos (Rangle) - (y_rec[res]-(YPa[Ym1]+YPa[Yp2])/2)*sin(Rangle);
                yrr = (x_rec[res]-(XPa[Xm1]+XPa[Xp2])/2.)*sin( Rangle) + (y_rec[res]-(YPa[Ym1]+YPa[Yp2])/2)*cos(Rangle);
                
                x_true[res] = xtr+(XPa[Xm1]+XPa[Xp2])/2.;
                y_true[res] = ytr+(YPa[Ym1]+YPa[Yp2])/2;
                x_rec[res]  = xrr+(XPa[Xm1]+XPa[Xp2])/2.;
                y_rec[res] = yrr+(YPa[Ym1]+YPa[Yp2])/2;
              }
         
          DataCorPointInside[res] = 0;
          
          if (y_true[res]>YPa[Ym1]+Distance_Axis && y_true[res]<=YPa[Yp1]-Distance_Axis && x_true[res] > XPa[Xm1]+Distance_Axis && x_true[res] <XPa[Xp1]-Distance_Axis)  
             DataCorPointInside[res] = 1;
          if (DataCorPointInside[res]){
             XYSignalTime->SetBinContent(XYSignalTime->GetXaxis()->FindBin(x_true[res]), XYSignalTime->GetYaxis()->FindBin(y_true[res]),t_rec[res]+1);
             XYDelay->SetBinContent(XYDelay->GetXaxis()->FindBin(x_true[res]),XYDelay->GetYaxis()->FindBin(y_true[res]),t_rec[res]+1);
           }
          
          res++;
          }

      res--;
      sim_point = res;
      cout << " Correction files with " << sim_point << " points inside the pixel" << endl;

   }

  } // end of correction if else
   
}

void RSD2_Digitizer_Cross45::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

   XCent = (XPa[Xp2]+XPa[Xm1])/2;
   YCent = (YPa[Yp2]+YPa[Ym1])/2;
}

Bool_t RSD2_Digitizer_Cross45::Process(Long64_t entry)
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
   Noise =  NScale*5.7*pow(1 - AScale*AScale,0.5);
   normal_distribution<double> distN(0,Noise);
   if (entry == 0){
    DT = time[1]-time[0];
    cout << "Additional noise term = " << Noise << " mV" << endl;  
    // Design the pads
    for (int a = 0; a<*nchro-2;a++){
     if (a ==Xm1 || a == Xm2 || a ==Xp1 || a ==Xp2 ){
       for (int b = -Xarmlenght; b<Xarmlenght;b++) // bins = 20 um
         XYPads->SetBinContent(XYPads->GetXaxis()->FindBin(XPa[a]+b),XYPads->GetYaxis()->FindBin(YPa[a]),500);
       for (int b = -Yarmlenght; b<Yarmlenght;b++) // bins = 20 um
         XYPads->SetBinContent(XYPads->GetXaxis()->FindBin(XPa[a]),XYPads->GetYaxis()->FindBin(YPa[a]+b),500);
       }
     }
   }
   
   XLaser = *XPos;
   YLaser = *YPos;
   //  if (XLaser>600) return 0;

   if (XLaser>XCent-40 && XLaser<XCent+40 && YLaser>YCent-40 && YLaser<YCent+40){
      for (b=0;b<samples[0]-10;b++){
       if (dcchannel ==0)  PShapeDCCh->Fill(time[b],m_amp0[b]); // 1000 point = 50 ns
       else if  (dcchannel ==2)  PShapeDCCh->Fill(time[b],-m_amp2[b]); // 1000 point = 50 ns
    }
   }
   
   if (*npos !=nposold){
      LaserPointInside[*npos] = 0;
      XTrueArray[*npos] = 0;
      YTrueArray[*npos] = 0;

      nposold = *npos;
      XYPos->SetBinContent(XYPos->GetXaxis()->FindBin(*XPos),XYPads->GetYaxis()->FindBin(*YPos),*npos);
       
      if (YLaser>YPa[Ym1]+Distance_Axis && YLaser<YPa[Yp2]-Distance_Axis && XLaser>XPa[Xm1]+Distance_Axis && XLaser<XPa[Xp2]-Distance_Axis)
      //   if (YLaser>500 && YLaser<900 && XLaser>300 && XLaser<750)
        LaserPointInside[*npos] = 1;
       //   if (Correction == 10) LaserPointInside[*npos] = 1;
      if (LaserPointInside[*npos]){
        XTrueArray[*npos] = *XPos;
        YTrueArray[*npos] = *YPos;
      }
   }


   ASum = 0;
   if (LaserPointInside[*npos])
     {

        //   if (XLaser<50 && YLaser>200 && YLaser<300){
        //cout << "New event\t" << ampl[0] << "\t" << t_max[0] << endl;
        for (int a = 0; a<n_integral_DC;a++){
            //cout << m_amp0[a]  << " " << a  << " " << time[a] <<endl;
         //if (time[a]>0 && time[a]<60)
           ASum +=m_amp0[a];
           /*
           if(time[a] > t_max[2] -1 && time[a] >    t_max[2] +2)
            ASum += m_amp2[a];
            if(time[a] > t_max[5] -1 && time[a] >   t_max[5] +2)
             ASum += m_amp5[a];
            if(time[a] > t_max[10] -1 && time[a] >  t_max[10] +2)
             ASum += m_amp10[a];
            if(time[a] > t_max[13] -1 && time[a] >  t_max[13] +2)
             ASum += m_amp13[a];
        */
         }
        ASum *= (time[10]-time[9])*ADCmV*AScale;

   }
   //    HDCSignal->Fill(area[dcchannel]*ADCmV*AScale);
   //}
   // Pos. Reconstruction
   XNum = 0;
   YNum = 0;
   XYDen = 0;
   NChMax = 0;
   AMax = 0;
   
   SignalTotal = 0;   

   if (LaserPointInside[*npos])
     {
       HDCSignal->Fill(ASum/5.);
       //HDCSignal->Fill(fabs(ASum/5.));

       //   cout << *XPos << " , " << *YPos << " npos " << *npos << endl;


       if (UseArea)
   {
     Signal[1]  = 0;
     Signal[3] = 0; 
     Signal[12] = 0;
     Signal[14] =0;
     for (b=0;b<samples[0]-10;b++)
       {
         if (time[b]>20 && time[b]<35)
     {
       // 1,3,12,14
       Signal[1] +=m_amp1[b]*AScale*ADCmV*DT;
       Signal[3] +=m_amp3[b]*AScale*ADCmV*DT;
       Signal[12] +=m_amp12[b]*AScale*ADCmV*DT;
       Signal[14] +=m_amp14[b]*AScale*ADCmV*DT;
     }
       }
     //          Signal[a] = area[a]*AScale*ADCmV;
     SignalTotal =  Signal[1]+Signal[3]+Signal[12]+Signal[14];
     //   cout << Signal[1] << " [pWb]"<< endl;
   }
       else
   {
     for (int a = 0; a<*nchro-2;a++) // bins = 20 um
       {
         if (ampl[a]>AMax && (a ==12 || a ==14))
     {
       AMax = ampl[a];
       NChMax = a;
     }
         Signal[a] = 0;
         if (a == Xm1 || a == Xm2 || a == Xp1 || a ==Xp2 ){
       //  if ( ampl[Xm1]*AScale>10)             
           Signal[a] = (ampl[a]*AScale +distN(generator))*ADCmV; // From TDC to mV    
           if (Signal[a]<-3){
                Signal[a] = 0;
            }
           SignalTotal += Signal[a];      
     }
       }
   }
     
       // Position reconstruction from amplitude weighted position
       //     if ( ampl[Xm1]*AScale>10) Signal[Xm1] = ampl[Xm1]*AScale +distN(generator)*ADCmV;;
       // if ( ampl[Xm2]*AScale>10) Signal[Xm2] = ampl[Xm2]*AScale +distN(generator)*ADCmV;
       // if ( ampl[Xp1]*AScale>10) Signal[Xp1] = ampl[Xp1]*AScale +distN(generator)*ADCmV;
       // if ( ampl[Xp2]*AScale>10) Signal[Xp2] = ampl[Xp2]*AScale +distN(generator)*ADCmV;

       
       xmin = (XPa[Xm1]+XPa[Xp1])/2+1./kxfactor*(XPa[Xp1]-XPa[Xm1])/2*( (Signal[Xp1]+Signal[Xp2])-
                  (Signal[Xm1]+Signal[Xm2]))/SignalTotal;
       ymin = (YPa[Ym1]+YPa[Yp1])/2+1./kxfactor*(YPa[Yp1]-YPa[Ym1])/2*( (Signal[Yp1]+Signal[Yp2])-
                  (Signal[Ym1]+Signal[Ym2]))/SignalTotal;
       
       // if(ChanRec && LaserPointInside[*npos])
       //  cout << " xmin = " << xmin << " Ampl = " << SignalTotal << endl;


       HSignalTotal->Fill(SignalTotal);



       XNum = XPa[Xm1]*Signal[Xm1]+XPa[Xm2]*Signal[Xm2]+XPa[Xp1]*Signal[Xp1]+XPa[Xp2]*Signal[Xp2];      
       YNum = YPa[Xm1]*Signal[Xm1]+YPa[Xm2 ]*Signal[Xm2]+YPa[Xp1]*Signal[Xp1]+YPa[Xp2]*Signal[Xp2];     
       XYDen = Signal[Xm1]+Signal[Xm2]+Signal[Xp1]+Signal[Xp2];

       if (UseWeightedMean)
   {
     xmin = XNum/XYDen;
     ymin = YNum/XYDen;
   }
  
  if (Correction == 1 || Correction == 11)
    {
      cor_x = 0;
      cor_d = 0;
      cor_nx = 0;
      cor_ny = 0;
      weight = 0;



      a = 0;

      Radius_r = Radius;
      while(1)
        {
    for (int ccc = 0;ccc<sim_point;ccc++)
      {
        
        dif = pow(pow((xmin-x_rec[ccc]),2)+pow((ymin-y_rec[ccc]),2),0.5); // distance to the rec. point
        if (DataCorPointInside[ccc] == 1 && dif<Radius_r)
          {
      a++;
      weight= 1./pow(dif,1);
      
      cor_nx += (x_true[ccc] -  x_rec[ccc])*weight;
      cor_ny += (y_true[ccc] -  y_rec[ccc])*weight;       
      cor_d +=  weight;
        
          }   
      }
    
    Radius_r +=10;
    if (a>3 || Radius_r>100) break;
    a=0;
    cor_d = 0;
    cor_nx = 0;
    cor_ny = 0;
    weight = 0;       
  
        }
      //  cout << a << endl;
      if (a <=3 )
        {
  
    cout << "Too few points for correction: # of point " << a << " (X,Y) = ( " << xmin << ", " << ymin << ")  Radius = " << Radius <<  endl;
        }


      
      if (cor_d > 0)
        {
    cor_x = cor_nx/cor_d;
    cor_y = cor_ny/cor_d;

        }


      
      xmin +=  cor_x;   
      ymin +=  cor_y;
    }

  Tcor2 = 0;
  Tcor10 = 0;
  TChannel[2]=0;
  TChannel[10]=0;
  
        if (Correction ==11 || Correction ==12)
    {
      Tcor2 =  XYSignalTime->GetBinContent(XYSignalTime->GetXaxis()->FindBin(x_true[*npos]), XYSignalTime->GetYaxis()->FindBin(y_true[*npos]))-1.;
      Tcor10 =  XYSignalTime->GetBinContent(XYSignalTime->GetXaxis()->FindBin(XPa[Xp2]-(x_true[*npos]-XPa[Xm1])), XYSignalTime->GetYaxis()->FindBin(y_true[*npos]))-1.;
    }

   TChannel[10] =  t_max[10]+TDelay[10]+Tcor10;
   TChannel[2] =  t_max[2]+TDelay[2]+Tcor12;

   if ( fabs(TChannel[2]-TChannel[NChMax])>0.5) TChannel[2] = 0;// t_max[12]+TDelay[12]+Tcor12;
   if ( fabs(TChannel[10]-TChannel[NChMax])>0.5) TChannel[10] = 0;  t_max[10]+TDelay[10]+Tcor14;

  TTrigger     = t_max[17];
       // XYSignal->SetBinContent(XYPads->GetXaxis()->FindBin(XLaser),XYPads->GetYaxis()->FindBin(YLaser),SignalTotal);
       // (xmin> XCent-50 &&  xmin< XCent+50 && ymin>YCent-50&& ymin<YCent+50 ) )
       if (xmin != 0 && ymin !=0)
   {
     XYSignal->SetBinContent(XYSignal->GetXaxis()->FindBin(xmin),XYSignal->GetYaxis()->FindBin(ymin),SignalTotal);
     //if (t_max[17]-t_max[12]+1>0 && (t_max[17]-t_max[12])<3 && Signal[12]>10 &&
     //   if(ymin>YCent)
     //  if(xmin> XCent-50 &&  xmin< XCent+50 && ymin>YCent-50 && ymin<YCent+50 )
     // if(xmin> XPa[Xm2] &&  xmin< XPa[Xm2]+50 && ymin<YPa[Xm2] && ymin>YPa[Xm2]-50 )
     //      if(xmin< XPa[Xp2] &&  xmin> XPa[Xp2]-100 && ymin<YPa[Xp2] && ymin>YPa[Xp2]-100 )
     // if(  xmin> XCent && ymin>YCent)
     //    if(xmin> XCent-50 &&  xmin< XCent+50 && ymin>YCent)
       {
         EventTime = TTrigger-(TChannel[10]*ampl[10]+TChannel[2]*ampl[2])/(ampl[10]+ampl[2]);
         EventTime =TTrigger-TChannel[2];
         //  EventTime =TChannel[12]-TChannel[14];
         HTime->Fill(EventTime);
         if( EventTime>-1 && EventTime <1 )
     XYTimeArea->SetBinContent(XYSignal->GetXaxis()->FindBin(xmin),XYSignal->GetYaxis()->FindBin(ymin),EventTime+1);
       }
   }
       HXPosRec[*npos]->Fill(xmin);
       HYPosRec[*npos]->Fill(ymin);
       HTimeRec[*npos]->Fill(EventTime);
       
       // 12 offeset = 0;
       // 14 offeset = -0.025;
       
       // if (xmin>800)
       // cout << xmin-XLaser << endl;
       
       HXAllPosRec->Fill(xmin-XLaser);
       // if (ymin>800)
       HYAllPosRec->Fill(ymin-YLaser);


        HXAllAbsPos->Fill(xmin);
  HYAllAbsPos->Fill(ymin);

  HNumPoint->Fill(a);


       
     }


   if (fabs(ASum) >0)
     
     //XYDCArea->SetBinContent(XYDCArea->GetXaxis()->FindBin(XLaser),XYDCArea->GetYaxis()->FindBin(YLaser),fabs(ASum/5.));
     XYDCArea->SetBinContent(XYDCArea->GetXaxis()->FindBin(XLaser),XYDCArea->GetYaxis()->FindBin(YLaser),(ASum/5.));

   return kTRUE;
}

void RSD2_Digitizer_Cross45::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

  // cout << " npos " << *npos << endl;




  
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



     //  cout << " offset " << HXPosRec[b]->GetStdDev() << endl;
     if (HXPosRec[b]->GetStdDev() !=0) HXSigma->Fill(HXPosRec[b]->GetStdDev());
     if (HYPosRec[b]->GetStdDev() !=0) HYSigma->Fill(HYPosRec[b]->GetStdDev());
     if (HXPosRec[b]->GetMean() !=0) HXOffset->Fill(HXPosRec[b]->GetMean()-XTrueArray[b] );
     if (HYPosRec[b]->GetMean() !=0) HYOffset->Fill(HYPosRec[b]->GetMean()-YTrueArray[b] );
     
     
   }


       if (DataCorPointInside[b])
   {
     dif = pow(pow(x_true[b]-x_rec[b],2) + pow(y_true[b]-y_rec[b],2), 0.5);
     HMigration->Fill(dif);

   }
       
     }


   if (Correction == 10)
     {
       
       //       sprintf(histname,Filedatacorr);    
       std::ofstream outfile1 (Filedatacorr);
       
       for (b=1;b<*npos;b++) //loop over positions
   {
     outfile1  <<  XTrueArray[b] << " \t " << YTrueArray[b] << " \t " << XRecArray[b] << " \t " << YRecArray[b] << " \t " << TRecArray[b] << std::endl;
     
   }

       //      std::ofstream outfile2 (Filetimecorr);       
       //       for (b=1;b<*npos;b++) //loop over positions
      // {
       //    outfile2  <<  XTrueArray[b] << " \t " << YTrueArray[b] << " \t " <<  TRecArray[b] << std::endl;     
       //  }
       
       cout << "Writing correction file " << Filedatacorr << endl; 
       cout << "Number of Laser positions " << *npos-1 << endl; 
       outfile1.close();
     }   
   gr1 = new TGraph(*npos,XRecArray,YRecArray);
   // gr1 = new TGraph(*npos,XTrueArray,YTrueArray);
   
   

}

void RSD2_Digitizer_Cross45::Terminate()
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

  c4->cd(4);

  HDCSignal->Rebin(rebin_HDC);
  HDCSignal->Fit("gaus", "tw");
 

  c4->cd(2);
  HNumPoint->Draw();


  c4->cd(3); 
   XYPads->SetStats(0);
   XYDCArea->SetStats(0);
   XYDCArea->SetTitle("");
   XYDCArea->Draw("colz");
   //   XYPads->Draw("same");


  
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

  c7->cd(2);

  XYPads->Draw();
  gr1->SetMarkerSize(0.2);
  gr1->SetMarkerStyle(107);
  gr1->SetMarkerColor(1);
  gr1->Draw("p same");
  
 
  
  sprintf(histname,"C2 Time");
  c2 = new TCanvas("c2",histname,900,700);
  c2->Divide(2,2);
   c2->cd(1);
  XYPads->SetStats(0);
  
  XYSignalTime->SetStats(0);
  XYSignalTime->SetTitle("");
  XYSignalTime->Draw("colz");
  XYPads->Draw("same");

  c2->cd(2);
  HTime->Fit("gaus","tw");


  c2->cd(3);
  XYPads->SetStats(0);
  XYDelay->SetStats(0);
  XYDelay->SetTitle("Signal delay with respect of top left pad");
  XYDelay->GetZaxis()->SetRangeUser(0.5, 1.0);
  XYDelay->Draw("colz");
  XYPads->Draw("same");

 c2->cd(4);
   XYPads->SetStats(0);
   XYTimeArea->GetZaxis()->SetRangeUser(0.9, 1.1);
  XYTimeArea->SetStats(0);
  XYTimeArea->SetTitle("");
  XYTimeArea->Draw("colz");
  XYPads->Draw("same");

  
  cout << "Central position of box (x,y) = " << (XPa[Xp2]+XPa[Xm1])/2<<","<<(YPa[Xp2]+YPa[Xm1])/2 << endl;
  cout << "Mean position of data (x,y) = " << HXAllAbsPos->GetMean()<<","<<HYAllAbsPos->GetMean() << endl;
  cout << "Mean Migration = " << HMigration->GetMean()<<" [um]" << endl;
  cout << "Area = " <<  HDCSignal->GetFunction("gaus")->GetParameter(1) << " [fC], gain =  " << HDCSignal->GetFunction("gaus")->GetParameter(1)*2. << endl;  

  cout << "DC integral using the Tprofile: " << PShapeDCCh->Integral(0,500)*(time[10]-time[9])*ADCmV*AScale /5. << " fc"<< endl;

  if ( PShapeDCCh->GetEntries()>1000)
  {
    PShapeDCCh->Fit("exp2","Q","",DCTimeLow+5,DCTimeHigh+10);
    cout<< left << setw(20) << "RC = " <<setprecision(3) << 1./PShapeDCCh->GetFunction("exp2")->GetParameter(1) << " [ns]" << endl;
  }
}



void RSD2_Digitizer_Cross45::Terminate2()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

  
  //HXAllPosRec->Fit("gaus","tw");
  

   sprintf(histname,"C1 Laser Position");
  c1 = new TCanvas("c1",histname,900,700);
  c1->Divide(2,2);

  c1->cd(1);
  XYPos->SetTitle("");
  XYPos->Draw("colz");
  XYPads->Draw("same");

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
    //    cout << " npos = " << cc << " " << XTrueArray[cc] << endl;
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
  

  
  if (Correction == 1 || Correction==2 || Correction==11 || Correction==12 )
    {
      sprintf(histname,"C5 LTSpice");
      c5 = new TCanvas("c5",histname,900,700);
      c5->Divide(2,2);
      c5->cd(1);
     
     gr_rec = new TGraph(sim_point,x_rec,y_rec); //where x , y are 2 arrays of n points and draw this graph with option “p”
     gr_true = new TGraph(sim_point,x_true,y_true); //where x , y are 2 arrays of n points and draw this graph with option “p”

     
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
     //
   
     c5->cd(3);

     //     XYPads->SetTitle("Migration");

     XYPads->Draw();


       for (cc=0; cc< sim_point; cc++)
       {
   if (x_rec[cc]>10 && y_rec[cc]>10)
     {       
       ar_spice[cc] = new TArrow(x_true[cc],y_true[cc],x_rec[cc],y_rec[cc],0.01,"|>");
       ar_spice[cc]->SetAngle(40);
       ar_spice[cc]->SetLineColor(4);  
       ar_spice[cc]->SetFillColor(4);  
       ar_spice[cc]->Draw();
     }
       }

       TPaveText *pt53= new TPaveText(TPx1, TPy1,TPx2,TPy2);
       pt53->AddText("Migration of training data");
       pt53->SetTextColor(kRed);
       pt53->Draw();

    }

  sprintf(histname,"C6 Resolution");
  c6 = new TCanvas("c6",histname,900,700);
  c6->Divide(2,2);
  c6->cd(1);

  HXAllPosRec->Fit("gaus","tw");

  TPaveText *pt61 = new TPaveText(-190,  HXAllPosRec->GetMaximum(),-100,HXAllPosRec->GetMaximum()+20);
  pt61->AddText("X position reconstruction");
  pt61->SetTextColor(kRed);
  pt61->Draw();
  //

  
  c6->cd(2);
  
  HYAllPosRec->Fit("gaus", "tw");
  

  TPaveText *pt62 = new TPaveText(-190,   HYAllPosRec->GetMaximum(),-100,HYAllPosRec->GetMaximum()+20);
  pt62->AddText("Y position reconstruction");
  pt62->SetTextColor(kRed);
  pt62->Draw();

    c6->cd(3);
  
    HSignalTotal->Fit("gaus", "tw");
  
  //


  
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
  

  cout << "Central position of box (x,y) = " << (XPa[Xp1]+XPa[Xm1])/2<<","<<(YPa[Yp1]+YPa[Ym1])/2 << endl;
  cout << "Mean position of data (x,y) = " << HXAllAbsPos->GetMean()<<","<<HYAllAbsPos->GetMean() << endl;
  
  


}