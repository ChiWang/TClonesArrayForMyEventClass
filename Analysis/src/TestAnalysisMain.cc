/*
 *  $Id: TestAnalysisMain.cc, 2014-02-22 22:47:16 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 22/02/2014
*/

#include "TFile.h"
#include "TTree.h"

#include "DmpEvent.h"

int main(){
  DmpEvent *EvtHolder = new DmpEvent();

  TFile *aFile = new TFile("../Database/DmpSimTest.root");

  TTree *aTree = (TTree*)aFile->Get("DAMPESimEvent");
  aTree->SetBranchAddress("RawEvent",&EvtHolder);        // key

  Int_t N = aTree->GetEntries();
/*
  for (Int_t i = 0;i<N;++i) {
    aTree->GetEntry(i);
    if (EvtHolder->GetEventID()%100 == 0) {
      EvtHolder->PrintEvent();
    }
  }
*/
  return 0;
}
