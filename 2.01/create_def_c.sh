#!/bin/tcsh
cat limits.h |grep define|grep "#"|grep -v if|awk '{print $3}'>defines;
foreach i (`cat defines`)
    echo 'printf("'$i'=%d\\n",'$i');'
end

cat float.h |grep define|grep "#"|grep -v if|awk '{print $2}'>defines_float;
#cat defines_float;

echo "\n\nAnd now float defines!\n\n";
foreach i (`cat defines_float`)
    echo 'printf("'$i'=%d\\n",'$i');'
end
