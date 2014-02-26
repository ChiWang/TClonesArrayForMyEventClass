/*
 *  $Id: DmpEvtHeader.cc, 2014-02-22 15:36:51 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 22/02/2014
*/

#include "DmpEvtHeader.h"
#include <iostream>

ClassImp(DmpEvtHeader)

DmpEvtHeader* DmpEvtHeader::fInstance = 0;

DmpEvtHeader::DmpEvtHeader()
 :fEventID(0)
{}

DmpEvtHeader::~DmpEvtHeader(){
}

DmpEvtHeader* DmpEvtHeader::GetInstance(){
  if (!fInstance) {
    //boost::shared_ptr<DmpEvtHeader>  fInstance(new DmpEvtHeader());
    fInstance = new DmpEvtHeader();
  }
  return fInstance;
}

void DmpEvtHeader::Reset(){
  fEventID = -1;
}
