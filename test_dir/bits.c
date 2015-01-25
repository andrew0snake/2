#include <stdio.h>
#include <math.h>

int setbits ( int x, int p, int n, int y );
long dec_bin ( long c );

void main ()
{

    signed char i = 0;
    int j = 0;
    int x = 0;
    int p = 0;
    int n = 0;
    signed char y = 0;
    signed char o = 0;

    x = 466;
    p = 7;
    n = 3;
    y = 164;

    i = ~ 1;
    printf ( "i = %d; and in binary = %d;\n", i, dec_bin ( i ) );
    printf ( "x = %d & ~ i = %d = %d;\n", x, i, x & ( ~ i ) );
    printf ( "x = %d | ~ i = %d = %d;\n\n", dec_bin ( x ) , dec_bin ( i ) , dec_bin ( x | ( ~ i ) ) );

    y = 127;
    printf ( "y in dec = %8d; and in binary = %8d; and in oct = %8o;\n", y, dec_bin ( y ), y );
    printf ( "~ y in dec = %6d; and in binary = %8d; and in oct = %8o;\n\n", ~ y, ~ dec_bin ( y ), ~ y );


    o = 077;
    printf ( "o in dec = %8d; and in binary = %8d; and in oct = %8o\n", o, dec_bin ( o ), o );
    printf ( "~ o in dec = %6d; and in binary = %8d; and in oct = %8o\n\n", ~ o, ~ dec_bin ( o ), ~ o );

    i =  ~ ( ~ 0 << n )  << n  ;
    printf ( "i in dec = %8d; and in binary = %8d; and in oct = %8o;\n", i, dec_bin ( i ), i );
    printf ( "~ i in dec = %6d; and in binary = %8d; and in oct = %8o;\n\n", ~ i, ~ dec_bin ( i ), ~ i );
   
    printf ( "y ^ i in dec = %4d; and in binary = %8d; and in oct = %8o;\n", ( y ^ i ), dec_bin ( y ^ i ), ( y ^ i ) );
    printf ( "~ y ^ i in dec =%d; and in binary = %8d; and in oct = %8o;\n", ~ ( y ^ i ), ~ ( dec_bin ( y ^ i ) ), ~ ( y ^ i ) );
    printf ( "-72 in binary = %29d; and in oct = %o;\n", dec_bin ( -72 ), -72 );
    printf ( "-13 in binary = %29d;\n", dec_bin ( -13 ) );
    printf ( "-52 in binary = %29d;\n", dec_bin ( -52 ) );
    printf ( "-2002 in bin = %30d;\n", dec_bin (-2002) );
    printf ( "0x76 in binary = %28d;\n", dec_bin ( 0x76 ) );


}


int setbits (int x, int p, int n, int y )
{

    


}

long dec_bin ( long n )  /* Function to convert decimal to binary.*/
{
    
    long rem;
    long i = 1;
    long  binary = 0;

    while ( n != 0 ){
        rem = n % 2;
        n /= 2;
        binary += rem * i;
        i *= 10;
    }

    return binary;
}