#include <stdio.h>

void main ()
{
    int c = 0;

//    c = 125;
    printf ( "insert please c:" );
    scanf ( "%d", &c );

    c -= 5;
    printf ( "c -=5 = %d;\n", c );

    c += 10;
    printf ( "c += 10 = %d;\n", c );

    c *=2;
    printf ( "c *=2 = %d;\n", c );

    c /= 2;
    printf ( "c /= 2 = %d;\n", c );
 
    c <<=3;
    printf ( "c <<= 3 = %d;\n", c );


    c >>=2;
    printf ( "c >>= 2 = %d;\n", c );


    c %= 2;
    printf ( "c %= 2 = %d;\n",\
     c );


}