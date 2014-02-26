/*
 *  $Id: DmpEvtBgoHit.h, 2014-02-23 16:10:36 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 13/11/2013
*/

#ifndef DmpEvtBgoHit_H
#define DmpEvtBgoHit_H

#include "TObject.h"        // key

class DmpEvtBgoHit : public TObject{  // key
  public:
    DmpEvtBgoHit();       // key. must define default constructor
    ~DmpEvtBgoHit();
    int GetUID() const {return fUID;}
    void SetUID(int id) {fUID = id;}
    double GetEnergy()  const       {return fEnergy;}
    double GetTime()    const       {return fTime;}
    double GetPosition(short i) const  {return fPosition[i];}
    void UpdateThisStep(double e, double x, double y, double z, double t=0);     // only for simulation
    void PrintHit() const;

  private:
    int         fUID;           // unique ID of minimum unit of Sensitive Detector
    double      fPosition[3];   // unit cm
    double      fEnergy;        // unit Mev
    double      fTime;          //! this is tem.

  ClassDef(DmpEvtBgoHit,1);   // key
};

#endif

