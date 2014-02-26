/*
 *  $Id: DmpEvent.h, 2014-02-22 15:42:10 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 13/11/2013
*/

#ifndef DmpEvent_H
#define DmpEvent_H

#include "TObject.h"        // key
#include "TString.h"

class TClonesArray;
class DmpEvtHeader;
class DmpEvtBgoHit;

class DmpEvent : public TObject{  // key
  public:
    DmpEvent();       // key. must define default constructor
    ~DmpEvent();
    TClonesArray*  GetBgoHitCollection() const {return fBgoHits;}
    void UpdateHit(TString Det, int UID, double e, double x, double y, double z, double t=-1);
    void PrintEvent()const;
    void Reset();

  private:
    DmpEvtHeader    *fEvtHeader;
    TClonesArray    *fBgoHits;  //->

  ClassDef(DmpEvent,1);   // key
};

#endif

