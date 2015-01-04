#include <stdio.h>
#include <math.h>

void setbits ( int x, int p, int n, int y );
unsigned getbits ( unsigned x, int p, int n );
int decimal_binary ( int n );


void main ()
{

    int i = 0;
    int j = 0;

    i = 10;
    j = 3;

    printf ( "i = %d, j = %d\n", i, j );
    printf ( "i in binary = %36d;\nj in binary = %36d;\n\n", decimal_binary ( i ), decimal_binary ( j ) );
    printf ( "i & j = %12d; and in binary = %12d;\n", i & j, decimal_binary ( i & j ) );
    printf ( "i | j = %12d; and in binary = %12d;\n", i | j, decimal_binary ( i | j ) );
    printf ( "i ^ j = %12d; and in binary = %12d;\n", i ^ j, decimal_binary ( i ^ j ) );
    printf ( "i << j = %11d; and in binary = %12d;\n", i ^ j, decimal_binary ( i << j ) );
    printf ( "i >> j = %11d; and in binary = %12d;\n", i ^ j, decimal_binary ( i >> j ) );
    printf ( "~i = %15d; and in binary = %12d;\n~j = %15d; and in binary = %12d;\n", ~ i, decimal_binary ( ~ i ), ~ j, decimal_binary ( ~ j ) );
    printf ( "   077 = %11d; and in binary = %12d;\n", 077, decimal_binary ( 077 ) );
    printf ( " ~ 077 = %11d; and in binary = %12d;\n", ~ 077, decimal_binary ( ~ 077 ) );
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
//        decimal += rem * pow( 2, i);
        ++i;
    }

    return decimal;
}