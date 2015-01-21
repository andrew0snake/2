#include <stdio.h>
#include <math.h>

int setbits ( int x, int p, int n, int y );
unsigned getbits ( unsigned x, int p, int n );
int dec_bin ( int n );


void main ()
{

    int i = 0;
    int j = 0;
    int setb = 0;
    unsigned int c = 0;
    unsigned short int s = 0;

    i = 3;
    j = 7;
    c = 466;
    s = 0244;

    printf ( "i = %d;\nj = %d;\ns = %d;\nc = %d;\n", i, j, s, c );
    printf ( "i in binary = %36d;\nj in binary = %36d;\ns in binary = %36d;\nc in binary = %36d;\n", dec_bin ( i ), dec_bin ( j ), dec_bin ( s ), dec_bin ( c ) );
    printf ( "i & j = %12d; and in binary = %12d;\n", i & j, dec_bin ( i & j ) );
    printf ( "i | j = %12d; and in binary = %12d;\n", i | j, dec_bin ( i | j ) );
    printf ( "i ^ j = %12d; and in binary = %12d;\n", i ^ j, dec_bin ( i ^ j ) );
    printf ( "i << j = %11d; and in binary = %12d;\n", i ^ j, dec_bin ( i << j ) );
    printf ( "i >> j = %11d; and in binary = %12d;\n", i ^ j, dec_bin ( i >> j ) );
    printf ( "~i = %15d; and in binary = %12d;\n~j = %15d; and in binary = %12d;\n", ~ i, dec_bin ( ~ i ), ~ j, dec_bin ( ~ j ) );
//    printf ( "  077 = %11d; and in binary = %12d;\n", 077, dec_bin ( 077 ) );
    printf ( "  077 = %12d; and in binary = %12d;\n", s, dec_bin ( s ) );
    printf ( "~ 077 = %12d; and in binary = %12d;\n", ~ 077, dec_bin ( ~ 077 ) );
    printf ( "i = %16d;i & 0177 =%19d;\n", i, i & 0177 );
    printf ( "070 in digital= %4d;070 in binary = %13d;\n", 070, dec_bin ( 070 ) );
    printf ( "0177 in digital= %3d;0177 in binary = %12d;\n", 0177, dec_bin ( 0177 ) );
    printf ( "0100 in digital= %3d;0100 in binary = %12d;\n", 0100, dec_bin ( 0100 ) );
    printf ( "0177700 in digital= %3d;0177700 in binary = %12d;\n", 0177700, dec_bin ( 0177700 ) );
    printf ( "~ 0 = %d; and in binary = %d;  ~ 0 << %d = %d; and in binary = %d;\n", ~ 0, dec_bin ( ~ 0 ), i, ~ 0 << i, dec_bin ( ~ 0 << i ) );
    printf ( "~ ( ~ 0 << %d ) = %d; and in binary = %d\n", i, ~ ( ~ 0 << i ), dec_bin ( ~ ( ~ 0 << i ) ) );
    printf ( "1 << %d = %d; s = %d; \t\t\t\t    and in binary = %10d\n", i, 1 << i, s, dec_bin ( s ) );
    printf ( "( x = %d ) >> ( ( p = %d ) + 1 - ( n = %d)  ) = %d; and in binary = %10d\n ", s, j, i, s >> ( j + 1 - i ), dec_bin ( s >> ( j + 1 - i ) ) );
    printf ( "getbits ( %d, %d, %d ) = %d; and in binary = %d\n", s, j, i, getbits ( s, j, i ), dec_bin ( getbits ( s, j, i ) ) );
    printf ( "~ ( ~ 0 << ( i = %d ) ) = %d; and in binary = ( %d ); \n", i, ~ ( ~ 0 << i ), dec_bin ( ~ ( ~ 0 << i ) ) );
    printf ( "  ( ~ 0 << ( i = %d ) ) = %d; and in binary = ( %d ); and c & ( rez ) = %d; and in binary = %d; \n", i, ( ~ 0 << i ), dec_bin ( ~ 0 << i ), \
    c & dec_bin ( ~ 0 << i), dec_bin ( c & dec_bin ( ~ 0 << i ) ) );
    printf ( "~ ( 1 << ( i + 1 ) ) = %d;and in binary = %d; \n", ~ ( 1 << ( i + i ) ), dec_bin ( ~ ( 1 << ( i + 1 ) ) ) );
//    printf ( "~ ( ~ 0 << i = %d ) = %d; and in binary " );

    setb = setbits ( c, j, i, s );
    printf ( "setb = %d; and in binary = %d;\n", setb, dec_bin ( setb ) );

}


int setbits ( int x, int p, int n, int y )
{
    
    int first = 0;
    int second = 0;

//    first = ( 1 << p + 1 ) | ( ~ ( ~ 0 << p + 1 - n ) ) ;
    first = (  ( ~ ( ~ 0 << n ) << ( p - n + 1 ) ) );
//    second = ( y &  ~ ( ~ 0 << n) ) << ( p - n + 1) ;
//    return ( y &  ~ ( ~ 0 << n) );
//    return ( x | ( ~ ( ~ 0 << n ) << ( p - n ) ) );
//    return ( x | ~ ( ~ 0 << n ) & ( y & ~ ( ~ 0 << n ) ) );

//    return second;
    return first;
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