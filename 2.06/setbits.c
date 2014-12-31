#include <stdio.h>
#include <math.h>

void setbits ( int x, int p, int n, int y );
unsigned getbits ( unsigned x, int p, int n );
int decimal_binary ( int n );


void main ()
{

    int i = 0;
    int j = 0;

    i = 5;
    j = 8;

    printf ( "i = %d, j = %d, i & j = %d;\n", i, j, i & j );
    printf ( "i in binary = %8d;\nj in binary = %8d;\n ", decimal_binary ( i ), decimal_binary ( j ) );

}


void setbits ( int x, int p, int n, int y )
{

    


}

unsigned getbits ( unsigned x, int p, int n )
{

    return ( x>> ( p+1-n ) & ~ ( ~ 0 << n) );

}

int decimal_binary ( int n )  /* Function to convert decimal to binary.*/
{    
    int rem;
    int i = 1;
    int  binary = 0;

    while ( n != 0 ){
        rem = n%2;
        n /= 2;
        binary += rem*i;
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
        decimal += rem * pow( 2, i);
        ++i;
    }

    return decimal;
}