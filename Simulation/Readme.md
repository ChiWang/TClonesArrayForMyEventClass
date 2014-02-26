
              Project:     TestDmpSim
      ======================================================
          By: Chi WANG (chiwang@mail.ustc.edu.cn)  13/11/2013

Description
--------------

    in ./src/TestDmpSimMain.cc, create a root file, the branch is the class DmpEvent. Then save the root file in ../Database


Usage
--------------

    execute the created file "TestDmpSim"


Note
-----

    1.  if get this error while running:
           ./TestDmpSim: error while loading shared libraries: libTestDmpEvent.so: cannot open shared object file: No such file or directory 

        do:
            export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:`pwd`/../Event

    2.  check root file in ../Database, the structure is the same as the data members in class DmpEvtTest
