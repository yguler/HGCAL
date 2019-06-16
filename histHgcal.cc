#include "histHgcal.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <string>
#include <cassert>
#include <vector>
#include <time.h>

#include "TFile.h"
#include "TTree.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TH3D.h"
#include "TProfile.h"
#include "TDirectory.h"
#include "TCanvas.h"
#include "TApplication.h"
#include "TStyle.h"
#include "inputHgcal.h"
#include "test.h"
// g++ `root-config --cflags` -o HGCALAnalyzer test.cc histHgcal.cc inputHgcal.cc anaHgcal.cc  `root-config --glibs`
// ./HGCALAnalyzer pdgID211_beamMomentum100_listFTFP_BERT_EMM 1 0 
double P=28.28;
histoSet1::histoSet1(TFile * fout,string anaType,string cutname){

  dirname=anaType+"_set1_"+cutname;
  //fout->mkdir(dirname.c_str());
  //fout->cd(dirname.c_str());
  const int max_Layer = 41;

  char name[100], Title[100], name2[100], Title2[100];
  for(int i = 0; i<max_Layer+1; i++){
        string s_ee="hE1_Layer";
        string s_layer=to_string(i+1);
        string hname=s_ee+s_layer;
	string title = "distribution of E1 at layer";
	string htitle = title+s_layer;
        histo1D[hname]=new TH1D(hname.c_str(),htitle.c_str(),300,0.0,1500);
        histo1D[hname]->SetXTitle("GeV");
        histo1D[hname]->SetYTitle("# Entry");
        histo1D[hname]->GetYaxis()->SetTitleOffset(1.);
	histo1D[hname]->Sumw2();

        s_ee="hE6_Layer";
        s_layer=to_string(i+1);
        hname=s_ee+s_layer;
        title = "distribution of E6 at layer";
        htitle = title+s_layer;	
        histo1D[hname]=new TH1D(hname.c_str(),htitle.c_str(),300,0.0,1500);
        histo1D[hname]->SetXTitle("GeV");
        histo1D[hname]->SetYTitle("# Entry");
        histo1D[hname]->GetYaxis()->SetTitleOffset(1.);
	histo1D[hname]->Sumw2();

        s_ee="hE7_Layer";
        s_layer=to_string(i+1);
        hname=s_ee+s_layer;
        title = "distribution of E7 at layer";
        htitle = title+s_layer;
        histo1D[hname]=new TH1D(hname.c_str(),htitle.c_str(),300,0.0,1500);
        histo1D[hname]->SetXTitle("GeV");
        histo1D[hname]->SetYTitle("# Entry");
        histo1D[hname]->GetYaxis()->SetTitleOffset(1.);
	histo1D[hname]->Sumw2();

        s_ee="hE18_Layer";
        s_layer=to_string(i+1);
        hname=s_ee+s_layer;
        title = "distribution of E18 at layer";
        htitle = title+s_layer;
        histo1D[hname]=new TH1D(hname.c_str(),htitle.c_str(),300,0.0,1500);
        histo1D[hname]->SetXTitle("GeV");
        histo1D[hname]->SetYTitle("# Entry");
        histo1D[hname]->GetYaxis()->SetTitleOffset(1.);
	histo1D[hname]->Sumw2();

        s_ee="hE19_Layer";
        s_layer=to_string(i+1);
        hname=s_ee+s_layer;
        title = "distribution of E19 at layer";
        htitle = title+s_layer;
        histo1D[hname]=new TH1D(hname.c_str(),htitle.c_str(),300,0.0,1500);
        histo1D[hname]->SetXTitle("GeV");
        histo1D[hname]->SetYTitle("# Entry");
        histo1D[hname]->GetYaxis()->SetTitleOffset(1.);
	histo1D[hname]->Sumw2();

        s_ee="hE1byE7_Layer";
        s_layer=to_string(i+1);
        hname=s_ee+s_layer;
        title = "distribution of E1/E7 at layer";
        htitle = title+s_layer;
        histo1D[hname]=new TH1D(hname.c_str(),htitle.c_str(),100,0.0,1.2);
        //histo1D[hname]->SetXTitle("GeV");
        histo1D[hname]->SetYTitle("# Entry");
        histo1D[hname]->GetYaxis()->SetTitleOffset(1.);
	histo1D[hname]->Sumw2();

        s_ee="hE1byE19_Layer";
        s_layer=to_string(i+1);
        hname=s_ee+s_layer;
        title = "distribution of E1/E19 at layer";
        htitle = title+s_layer;
        histo1D[hname]=new TH1D(hname.c_str(),htitle.c_str(),100,0.0,1.2);
        //histo1D[hname]->SetXTitle("GeV");
        histo1D[hname]->SetYTitle("# Entry");
        histo1D[hname]->GetYaxis()->SetTitleOffset(1.);
	histo1D[hname]->Sumw2();

        s_ee="hE7byE19_Layer";
        s_layer=to_string(i+1);
        hname=s_ee+s_layer;
        title = "distribution of E7/E19 at layer";
        htitle = title+s_layer;
        histo1D[hname]=new TH1D(hname.c_str(),htitle.c_str(),100,0.0,1.2);
        //histo1D[hname]->SetXTitle("GeV");
        histo1D[hname]->SetYTitle("# Entry");
        histo1D[hname]->GetYaxis()->SetTitleOffset(1.);
	histo1D[hname]->Sumw2();

        s_ee="hSumE_Layer";
        s_layer=to_string(i+1);
        hname=s_ee+s_layer;
        title = "distribution of Energy Sum at layer";
        htitle = title+s_layer;
        histo1D[hname]=new TH1D(hname.c_str(),htitle.c_str(),300,0.0,1500);
        histo1D[hname]->SetXTitle("GeV");
        histo1D[hname]->SetYTitle("# Entry");
        histo1D[hname]->GetYaxis()->SetTitleOffset(1.);
	histo1D[hname]->Sumw2();

        s_ee="hE1iuiv_Layer";
        s_layer=to_string(i+1);
        hname=s_ee+s_layer;
        title = "Positions of maximum Energy hit at layer";
        htitle = title+s_layer;
        histo2D[hname]=new TH2D(hname.c_str(),htitle.c_str(),40,-10,10, 40, -10, 10);
        histo2D[hname]->SetXTitle("iu");
        histo2D[hname]->SetYTitle("iv");
        histo2D[hname]->GetYaxis()->SetTitleOffset(1.);
	histo2D[hname]->Sumw2();

        s_ee="hE1xy_Layer";
        s_layer=to_string(i+1);
        hname=s_ee+s_layer;
        title = "Positions of maximum Energy hit at layer";
        htitle = title+s_layer;
        histo2D[hname]=new TH2D(hname.c_str(),htitle.c_str(),80,-10,10, 80, -10, 10);
        histo2D[hname]->SetXTitle("x");
        histo2D[hname]->SetYTitle("y");
        histo2D[hname]->GetYaxis()->SetTitleOffset(1.);
	histo2D[hname]->Sumw2();
    }
	sprintf(name,"hShower_depth_forEE");
        sprintf(Title,"Depth =Sum(layer[Radiation Length] x E_layer) / Sum(E_layer)");
        histo1D[name]=new TH1D(name,Title, 100,0,30 );
        histo1D[name]->SetXTitle("Shower depth EE");
        histo1D[name]->SetYTitle("# Entry");
	histo1D[name]->Sumw2();

        sprintf(name,"hShower_depth_forFH");
        sprintf(Title,"Depth =Sum(layer[Interaction Length] x E_layer) / Sum(E_layer)");
        histo1D[name]=new TH1D(name,Title, 100,0,10 );
        histo1D[name]->SetXTitle("Shower depth FH");
        histo1D[name]->SetYTitle("# Entry");
	histo1D[name]->Sumw2();
}

histoSet1::~histoSet1(){
}

void histoSet1::summary(string anaType, string mydataset){
    // std::cout<<" yg  "<<std::endl;
}

void histoSet1::process(test & ev, double weight){

   // double wt=1.0;
   double wt=weight;
   uint32_t event;
   uint32_t run;
   double beamEnergy;
   double trueBeamEnergy;
   run = ev.run;
   event = ev.event;
   beamEnergy =ev.beamEnergy;
   trueBeamEnergy = ev.trueBeamEnergy;
   float  Etotal=0;
   int max_Layer=41;
   double RadLen[29] ={0.932753,1.90872, 2.81787, 3.79384, 4.70298, 5.67895,6.5881,7.56407,8.47322,9.44918,10.3583,11.3343,12.2434,13.2194,14.1286,15.1045,16.0137,16.9896,17.8988,18.8748,19.7839,20.927,21.8362,22.9793,23.8884,25.1341,26.0433,27.3262,29.6264}; 
   double IntLen[13] ={1.6535, 1.95281, 2.25213,2.55144, 2.85076,3.14224,3.25073,3.55005,3.84936,4.15185,4.44651,4.73799,4.83866};
   double SumE_layer[max_Layer] ={0.};

   double E1_layer[max_Layer] = {0.};
   double  detID_E1_layer[max_Layer] = {0.};

   double iu_E1_layer[max_Layer] ={0.};
   double iv_E1_layer[max_Layer] = {0.};

   double x_E1_layer[max_Layer] ={0.};
   double y_E1_layer[max_Layer] = {0.};

   for(int i =0; i<ev.NRechits; i++){
     //cout <<" rechit_layer number = "<<ev.rechit_layer->at(i)<<endl;
     if(ev.rechit_layer->at(i) > max_Layer) continue;
     int curr_layerNo = ev.rechit_layer->at(i);
     double curr_rechitEn=ev.rechit_energy->at(i);
     bool curr_noiseflag=ev.rechit_noise_flag->at(i);
     if(curr_rechitEn < 1.0) continue;

     if(curr_noiseflag) continue;

     //SumE_layer[curr_layerNo-1] += curr_rechitEn;
     SumE_layer[curr_layerNo-1] +=ev.rechit_energy->at(i);

     double curr_xpos = ev.rechit_x->at(i);
     double curr_ypos = ev.rechit_y->at(i);

     double dis = sqrt(curr_xpos*curr_xpos + curr_ypos*curr_ypos);

     if (dis>5.) continue;

     if (curr_rechitEn > E1_layer[curr_layerNo -1]){
       E1_layer[curr_layerNo -1] = curr_rechitEn;

       detID_E1_layer[curr_layerNo] = ev.rechit_detid->at(i);
       iu_E1_layer[curr_layerNo -1] = ev.rechit_iu->at(i);
       iv_E1_layer[curr_layerNo -1] = ev.rechit_iv->at(i);

       x_E1_layer[curr_layerNo -1] = ev.rechit_x->at(i);
       y_E1_layer[curr_layerNo -1] = ev.rechit_y->at(i);
     }
   }
   double E7_layer[max_Layer]={0.};
   double E19_layer[max_Layer]={0.};

   for(int i =0; i<ev.NRechits; i++){
     if(ev.rechit_layer->at(i) > max_Layer) continue;
     if(ev.rechit_energy->at(i) < 1.0) continue;
     if(ev.rechit_noise_flag->at(i)) continue;

     int curr_layerNo = ev.rechit_layer->at(i);

     int curr_iu = ev.rechit_iu->at(i);
     int curr_iv = ev.rechit_iv->at(i);

     double curr_x = ev.rechit_x->at(i);
     double curr_y = ev.rechit_y->at(i);

     pair<int, int> curr_iuiv;
     curr_iuiv=make_pair(curr_iu, curr_iv);

     int iu_E1_currlayer = iu_E1_layer[curr_layerNo -1];
     int iv_E1_currlayer = iv_E1_layer[curr_layerNo -1];

     double x_E1_currlayer = x_E1_layer[curr_layerNo -1];
     double y_E1_currlayer = y_E1_layer[curr_layerNo -1];

     pair<int, int> det2_iuiv, det3_iuiv, det4_iuiv, det5_iuiv, det6_iuiv, det7_iuiv;

     det2_iuiv=make_pair(iu_E1_currlayer +1 , iv_E1_currlayer);
     det3_iuiv=make_pair(iu_E1_currlayer -1 , iv_E1_currlayer);
     det4_iuiv=make_pair(iu_E1_currlayer, iv_E1_currlayer+1);
     det5_iuiv=make_pair(iu_E1_currlayer, iv_E1_currlayer-1);
     det6_iuiv=make_pair(iu_E1_currlayer+1, iv_E1_currlayer+1);
     det7_iuiv=make_pair(iu_E1_currlayer-1, iv_E1_currlayer-1);

     double Xdist = curr_x - x_E1_currlayer;
     double Ydist = curr_y - y_E1_currlayer;

     double R = sqrt(Xdist*Xdist + Ydist*Ydist);
   if(R<1.13){
     E7_layer[curr_layerNo -1] += ev.rechit_energy->at(i);
   }

   if(R<2.26){
     E19_layer[curr_layerNo -1] += ev.rechit_energy->at(i);
   }
  }// rechit loop
        double sumEEL1 = 0;
        double sumEEL2 = 0;
        double sumFHL1 = 0;
        double sumFHL2 = 0;
   for(int k = 0; k<max_Layer; k++){
     double E1_currLayer = E1_layer[k];
     string hname="hE1_Layer"+to_string(k+1);
     histo1D[hname]->Fill(E1_currLayer);

     double E6_currLayer = E7_layer[k] - E1_layer[k];
     hname="hE6_Layer"+to_string(k+1);
     histo1D[hname]->Fill(E6_currLayer);

     double E18_currLayer = E19_layer[k] - E1_layer[k];
     hname="hE18_Layer"+to_string(k+1);
     histo1D[hname]->Fill(E18_currLayer);

     double E7_currLayer = E7_layer[k];
     hname="hE7_Layer"+to_string(k+1);
     histo1D[hname]->Fill(E7_currLayer);

     double E19_currLayer = E19_layer[k];
     hname="hE19_Layer"+to_string(k+1);
     histo1D[hname]->Fill(E19_currLayer);
     if(!(E1_currLayer==0.) && !(E7_currLayer==0.)){
       double E1byE7_currLayer = E1_currLayer/E7_currLayer;
       hname="hE1byE7_Layer"+to_string(k+1);
       histo1D[hname]->Fill(E1byE7_currLayer);
     }

     if(!(E1_currLayer==0.) && !(E19_currLayer==0.)){
       double E1byE19_currLayer = E1_currLayer/E19_currLayer;
       hname="hE1byE19_Layer"+to_string(k+1);
       histo1D[hname]->Fill(E1byE19_currLayer);
     }

     if(!(E7_currLayer==0.) && !(E19_currLayer==0.)){
       double E7byE19_currLayer = E7_currLayer/E19_currLayer;
       hname="hE7byE19_Layer"+to_string(k+1);
       histo1D[hname]->Fill(E7byE19_currLayer);
     }

    double SumE_currLayer = SumE_layer[k];
       hname="hSumE_Layer"+to_string(k+1);
       histo1D[hname]->Fill(SumE_currLayer);
       if (k<=27){sumEEL1 += SumE_currLayer*RadLen[k]; sumEEL2 += SumE_layer[k];}
       if (k>=28){sumFHL1 += SumE_currLayer*IntLen[k-28]; sumFHL2 += SumE_layer[k];}

    double E1iu_currLayer = iu_E1_layer[k];
    double E1iv_currLayer = iv_E1_layer[k];
    hname="hE1iuiv_Layer"+to_string(k+1);
    histo2D[hname]->Fill(E1iu_currLayer,E1iv_currLayer);

    double E1x_currLayer = x_E1_layer[k];
    double E1y_currLayer = y_E1_layer[k];
    hname="hE1xy_Layer"+to_string(k+1);
    histo2D[hname]->Fill(E1x_currLayer,E1y_currLayer);
    } // Layer loop
       histo1D["hShower_depth_forEE"]->Fill(sumEEL1/sumEEL2);
       histo1D["hShower_depth_forFH"]->Fill(sumFHL1/sumFHL2);
	//std::cout<<" yg  end"<<std::endl;
   return;
}




