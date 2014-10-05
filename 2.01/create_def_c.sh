#!/bin/tcsh
cat limits.h |grep define|grep "#"|grep -v if>defines;
foreach i (`cat defines`)
    echo 'printf("'$i'=%d\\n",'$i');'
end