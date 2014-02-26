/*
 *  $Id: DmpEvent.cc, 2014-02-23 16:05:44 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 13/11/2013
*/

#include <iostream>

#include "TClonesArray.h"

#include "DmpEvtHeader.h"
#include "DmpEvtBgoHit.h"
#include "DmpEvent.h"

ClassImp(DmpEvent)   // key

DmpEvent::DmpEvent()
 :fEvtHeader(0),
  fBgoHits(0)
{
  fEvtHeader = DmpEvtHeader::GetInstance();
  fBgoHits = new TClonesArray("DmpEvtBgoHit",300);
}

DmpEvent::~DmpEvent(){
  Reset();
  delete fBgoHits;
}

void DmpEvent::PrintEvent()const{
  std::cout<<"Event ID "<<fEvtHeader->GetEventID()<<std::endl;
  std::cout<<"UID\t"<<"Energy\t"<<"Position(x,y,z)"<<std::endl;
  for(int i=0;i<fBgoHits->GetEntriesFast();++i){
    ((DmpEvtBgoHit*)fBgoHits->At(i))->PrintHit();
  }
}

void DmpEvent::Reset(){
  fEvtHeader->Reset();
  if(fBgoHits->GetEntriesFast()>0) fBgoHits->Delete();
  fBgoHits->Clear();
}

void DmpEvent::UpdateHit(TString Det, int UID, double e, double x, double y, double z, double t){
  int setID = -1;
  DmpEvtBgoHit *aBgoHit = 0;
  if(Det == "Bgo"){
    for (int i=0;i<fBgoHits->GetEntriesFast();++i){
      if (((DmpEvtBgoHit*)fBgoHits->At(i))->GetUID() == UID){
        setID = i;
      }
    }
    if (setID<0){
      setID = fBgoHits->GetEntriesFast();
      //std::cout<<"DEBUG: "<<__FILE__<<"("<<__LINE__<<"), in "<<__PRETTY_FUNCTION__<<std::endl;
      aBgoHit = (DmpEvtBgoHit*)fBgoHits->ConstructedAt(setID);
      //std::cout<<"DEBUG: "<<__FILE__<<"("<<__LINE__<<"), in "<<__PRETTY_FUNCTION__<<std::endl;
    }else{
      aBgoHit = (DmpEvtBgoHit*)fBgoHits->At(setID);
    }
    aBgoHit->UpdateThisStep(e,x,y,z);
  }
}


{
 fBgoHits->
}


