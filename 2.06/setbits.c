#include <stdio.h>
#include <math.h>

int setbits ( int x, int p, int n, int y );
unsigned getbits ( unsigned x, int p, int n );
int dec_bin ( int n );


void main ()
{

    unsigned short int n = 0;
    unsigned short int p = 0;
    unsigned short int setb = 0;
    unsigned short int x = 0;
    unsigned short int y = 0;

    n = 3;
    p = 7;
    x = 466;
    y = 0245;

    printf ( "n = %d;\np = %d;\nx = %d;\ny = %d;\n", n, p, x, y );
    printf ( "n in binary = %36d;\np in binary = %36d;\nx in binary = %36d;\ny in binary = %36d;\n\n", dec_bin ( n ), dec_bin ( p ), dec_bin ( x ), dec_bin ( y ) );
/*    printf ( "n & p = %12d; and in binary = %12d;\n", n & j, dec_bin ( n & p ) );
    printf ( "n | p = %12d; and in binary = %12d;\n", n | j, dec_bin ( n | p ) );
    printf ( "n ^ p = %12d; and in binary = %12d;\n", n ^ j, dec_bin ( n ^ p ) );
    printf ( "n << p = %11d; and in binary = %12d;\n", n ^ j, dec_bin ( n << p ) );
    printf ( "n >> p = %11d; and in binary = %12d;\n", n ^ j, dec_bin ( n >> p ) );
    printf ( "~n = %15d; and in binary = %12d;\n~j = %15d; and in binary = %12d;\n", ~ i, dec_bin ( ~ n ), ~ j, dec_bin ( ~ p ) );
//    printf ( "  077 = %11d; and in binary = %12d;\n", 077, dec_bin ( 077 ) );
    printf ( "  077 = %12d; and in binary = %12d;\n", s, dec_bin ( s ) );
    printf ( "~ 077 = %12d; and in binary = %12d;\n", ~ 077, dec_bin ( ~ 077 ) );
    printf ( "n = %16d;n & 0177 =%19d;\n", i, n & 0177 );
    printf ( "070 in digital= %4d;070 in binary = %13d;\n", 070, dec_bin ( 070 ) );
    printf ( "0177 in digital= %3d;0177 in binary = %12d;\n", 0177, dec_bin ( 0177 ) );
    printf ( "0100 in digital= %3d;0100 in binary = %12d;\n", 0100, dec_bin ( 0100 ) );
    printf ( "0177700 in digital= %3d;0177700 in binary = %12d;\n", 0177700, dec_bin ( 0177700 ) );
    printf ( "~ 0 = %d; and in binary = %d;  ~ 0 << %d = %d; and in binary = %d;\n", ~ 0, dec_bin ( ~ 0 ), i, ~ 0 << i, dec_bin ( ~ 0 << n ) );
    printf ( "~ ( ~ 0 << %d ) = %d; and in binary = %d\n", i, ~ ( ~ 0 << n ), dec_bin ( ~ ( ~ 0 << n ) ) );
    printf ( "1 << %d = %d; s = %d; \t\t\t\t    and in binary = %10d\n", i, 1 << i, s, dec_bin ( s ) );
    printf ( "( n = %d ) >> ( ( p = %d ) + 1 - ( n = %d)  ) = %d; and in binary = %10d\n ", s, j, i, s >> ( p + 1 - n ), dec_bin ( s >> ( p + 1 - n ) ) );
    printf ( "getbits ( %d, %d, %d ) = %d; and in binary = %d\n", s, j, i, getbits ( s, j, n ), dec_bin ( getbits ( s, j, n ) ) );
    printf ( "~ ( ~ 0 << ( n = %d ) ) = %d; and in binary = ( %d ); \n", i, ~ ( ~ 0 << n ), dec_bin ( ~ ( ~ 0 << n ) ) );
    printf ( "  ( ~ 0 << ( n = %d ) ) = %d; and in binary = ( %d ); and c & ( rez ) = %d; and in binary = %d; \n", i, ( ~ 0 << n ), dec_bin ( ~ 0 << n ), \
    c & dec_bin ( ~ 0 << i), dec_bin ( c & dec_bin ( ~ 0 << n ) ) );
    printf ( "~ ( 1 << ( n + 1 ) ) = %d;and in binary = %d; \n", ~ ( 1 << ( n + n ) ), dec_bin ( ~ ( 1 << ( n + 1 ) ) ) );
//    printf ( "~ ( ~ 0 << n = %d ) = %d; and in binary " );
*/
//    printf ( "~ ( ~ 0 << 3 )  << 4 = %d;\n", dec_bin ( ~ ( ~ 0 << 3 ) << 4 ) );
    setb = setbits ( x, p, n, y );
    printf ( "rezult = %4d; and in binary = %19d;\n", setb, dec_bin ( setb ) );

}


int setbits ( int x, int p, int n, int y )
{
    
    int first = 0;
    int second = 0;
    unsigned short int third = 0;
    unsigned short int fourth = 0;

//    first = ( 1 << p + 1 ) | ( ~ ( ~ 0 << p + 1 - n ) ) ;
    //get n ones bits on position, that starts in p
    first = (  ( ~ ( ~ 0 << n ) << ( p - n + 1 ) ) );
    printf ( "first = %42d;\n", dec_bin ( first ) );

    //get n bits of y, moved to position p
    second = ( ( y & ( ~ ( ~ 0 << n) ) ) << ( p - n + 1 ) );
    printf ( "second = %41d;\n", dec_bin ( second ) );
    
    //get nulls in n bits of x in position, that starts in p
    third = x & ( ~ first ) ;
    printf ( "third = %42d;\n", dec_bin ( third ) );

    //get 
    fourth = third | second;
    printf ( "fourth = %41d;\n\n", dec_bin ( fourth ) );
//    return ( y &  ~ ( ~ 0 << n) );
//    return ( n | ( ~ ( ~ 0 << n ) << ( p - n ) ) );
//    return ( n | ~ ( ~ 0 << n ) & ( y & ~ ( ~ 0 << n ) ) );

//    return second;
    return fourth;
}

unsigned getbits ( unsigned x, int p, int n )
{

    return ( x >> ( p+1-n ) & ~ ( ~ 0 << n) );

}

int dec_bin ( int n )  /* Function to convert decimal to binary.*/
{    
    int rem;
    int i = 1;
    int  binary = 0;

    while ( n != 0 ){
        rem = n % 2;
        n /= 2;
        binary += rem * i;
        i *= 10;
    }
    return binary;
}

int binary_decimal ( int n ) /* Function to convert binary to decimal.*/
{
    int decimal = 0;
    int i = 0;
    int rem;

    while ( n != 0 ){
        rem = n%10;
        n /= 10;
//        decimal += rem * pow( 2, i);
        ++i;
    }

    return decimal;
}