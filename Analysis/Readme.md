> *
> *  TODO: Not write how to read a root file which create by using the newest event classes
> *

              Project:     uselibDmpEvtTest_Read
      ======================================================
          By: Chi WANG (chiwang@mail.ustc.edu.cn)  13/11/2013

Description
--------------

    in ./include    DmpEvtTest.h, use this header file
    in ./src/uselibDmpEvtTest_Read.cc, load the root file created by uselibDmpEvtTest_Write. Load the root file just through the class DmpEvtTest.


Usage
--------------

    scons       // will create executable file uselibDmpEvtBgoTest at ./, and temporary files in ./Scons
    scons -c    // clean up

    execute the created file "libDmpEvtTest_Read"


Note
-----

    1.  if you get this error while compiling:
            /usr/bin/ld: cannot find -lDmpEvtTest

        cd ../creatLib, compile at there

    2.  if get this error while running:
           ./libDmpEvtTest_Write: error while loading shared libraries: libDmpEvtTest.so: cannot open shared object file: No such file or directory 

        do:
            export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:`pwd`/../createLib

    3.  make sure you have created XXX.root in Database



