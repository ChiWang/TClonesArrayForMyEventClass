
              Project:     TestDmpEvent
      ======================================================
          By: Chi WANG (chiwang@mail.ustc.edu.cn)  13/11/2013

Description
--------------

    define all event classes in ./include
    write a ./include/XXXLinkDef.h file (must include "LinkDef")

    use rootcint in createDictionary


Usage
--------------
    create dictionary
        ./createDictionary    // will generate *_Dict* files in ./include and ./src

Note
-----
    if you want to re-compile this package, please make sure that these are no any "*_Dict.*" files in any directories.


