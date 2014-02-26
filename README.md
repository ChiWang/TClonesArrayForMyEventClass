#TClonesArrayForMyEventClass
===========================

#Write MyEventClass and use TClonesArray to book branch in root
>-------------------------------------------------------------------

Once you develope the event class this way,

    TTree could set your defined class as a branch just by using the class name, and
    the leaves are the data members in that class.
>-------------------------------------------------------------------

AMS-2, BES-III and Daya bay are using the same technical, that is:

    Define a event class which inherit from TObject, then
    create the event class as a shared library by using rootcint, then
    other package could use the class, and book branch just by the class name, instead of by a serial data members.
>-------------------------------------------------------------------


Structure
----------
    Event
            define event classes, generate a dictionary by rootcint, create shared library

    Simulation
            use the created library and the header file of event classes to create a root file

    Analysis
            use the created library and the header file of event classes to read the root file which is created before

    Database
            root file is stored in here.

How to test
-----------
    step 1, compile all whole(now mean Event and Simulation)
        1.  create dictionary, do:
            ./pre-install
        2.  compilation, do:
            scons

    step 2, run Simulation
        1.  cd  into Simulation
        2.  execute the created command

    step 3, run Analysis(now finished yet)
        1.  cd into Analysis
        2.  execute the created command


What is the key point in code?
------------------------------
    those lines are commented by "key"


