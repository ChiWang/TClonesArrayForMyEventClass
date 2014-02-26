#! /bin/bash
:<<EOF
 *  $Id: pre-install.sh, 2014-02-22 16:06:20 chi $
 *  Author(s):
 *    Chi WANG (chiwang@mail.ustc.edu.cn) 22/02/2014
EOF

#+ functions
#----------------------------------------------------
Usage(){
echo "
  Usage: (before install DMPSW, execute me)
    bash $0
"
  exit 1
}
if [[ $# -ne 0 ]];then
  Usage
fi

CheckEnv(){
  for var in $@;do
    if [[ `env | grep $var | wc -l` -lt 1 ]];then
      echo "    ERROR:  no shell variable \$$var"
      exit 1
    fi
  done
}

echo "---->   Checking Environment..."
CheckEnv ROOTSYS G4INSTALL G4LIB_USE_GDML

#+  Event
#----------------------------------------------------
package="Event"
echo "---->   Creating Dictionary..."
pushd $package 1>/dev/null
\rm ./*/Dictionary* 2>/dev/null
./createDictionary
popd  1>/dev/null


