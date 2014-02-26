/*
 *  $Id: DmpEvtHeader.h, 2014-02-23 16:15:56 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 22/02/2014
*/

#ifndef DmpEvtHeader_H
#define DmpEvtHeader_H

#include "TObject.h"

class DmpEvtHeader : public TObject{
  public:
    DmpEvtHeader();         // must have default constructor
    static DmpEvtHeader* GetInstance();
    ~DmpEvtHeader();
    long GetEventID() const     {return fEventID;}
    void SetEventID(long id)    {fEventID = id;}
    void Reset();

  private:
    static  DmpEvtHeader    *fInstance;  //! not save it
    long    fEventID;

  ClassDef(DmpEvtHeader,1)
};

#endif
