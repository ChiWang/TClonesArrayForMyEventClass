/*
 *  $Id: DmpEvtBgoHit.cc, 2014-02-22 14:12:45 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 22/02/2014
*/

#include <iostream>
#include "DmpEvtBgoHit.h"

ClassImp(DmpEvtBgoHit)     // key

DmpEvtBgoHit::DmpEvtBgoHit()
 :fUID(0),
  fEnergy(0),
  fTime(0)
{
  for (int i=0;i<3;++i) fPosition[i] = 0 ;
}

DmpEvtBgoHit::~DmpEvtBgoHit(){
}

void DmpEvtBgoHit::UpdateThisStep(double e, double x, double y, double z, double t){
  double totE = e + fEnergy;
  double nX = (e*x + fEnergy * fPosition[0])/totE;
  double nY = (e*y + fEnergy * fPosition[1])/totE;
  double nZ = (e*z + fEnergy * fPosition[2])/totE;
  fPosition[0] = nX;
  fPosition[1] = nY;
  fPosition[2] = nZ;
  fEnergy = totE;
  fTime = t;
}

void DmpEvtBgoHit::PrintHit() const{
  std::cout<<fUID<<"\t"<<fEnergy<<"\t("<<fPosition[0]<<","<<fPosition[1]<<","<<fPosition[2]<<")"<<std::endl;
}


