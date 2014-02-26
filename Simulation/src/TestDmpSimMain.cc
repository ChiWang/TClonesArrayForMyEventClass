/*
 *  $Id: TestDmpSimMain.cc, 2014-02-22 16:34:11 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 22/02/2014
*/

#include <sys/time.h>

#include "TFile.h"
#include "TTree.h"
#include "TRandom.h"

#include "DmpEvtHeader.h"
#include "DmpEvtBgoHit.h"
#include "DmpEvent.h"

#include <iostream>

int main(){

  gRandom->SetSeed(time(0));

  DmpEvent *EvtHolder = new DmpEvent();
  DmpEvtHeader *EvtHeader = DmpEvtHeader::GetInstance();

  TTree *aTree = new TTree("DAMPESimEvent","DAMPE");
  aTree->Branch("RawEvent","DmpEvent",&EvtHolder,32000,2);     // key

  for (int i = 0;i<2000;++i) {
    EvtHolder->Reset();
    EvtHeader->SetEventID(i);
    int TotHit = (int) gRandom->Gaus(50,10);  // BarNo = 80
    for (int nHit=0; nHit<TotHit; ++nHit){
      int Uid = (int) gRandom->Uniform(60);
      double e = gRandom->Gaus(4,0.5);
      double x = gRandom->Gaus(20,10);
      double y = gRandom->Gaus(5,2.2);
      double z = gRandom->Gaus(5,2.2);
      EvtHolder->UpdateHit("Bgo",Uid,e,x,y,z);
    }
    aTree->Fill();
  }

  TFile *aFile = new TFile("../Database/DmpSimTest.root","recreate");
  aTree->Write();
  aFile->Close();
  delete aFile;
  return 0;
}

