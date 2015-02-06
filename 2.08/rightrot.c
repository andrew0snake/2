#include <stdio.h>
#include <math.h>

int setbits ( int x, int p, int n, int y );
int setbits2 ( int x, int p, int n, int y );
unsigned getbits ( unsigned x, int p, int n );
unsigned short int invert ( unsigned short int x, unsigned short int p, unsigned short int n );
unsigned short int rightrot ( unsigned short int x, unsigned short int n );
unsigned long int dec_bin ( unsigned long int n );


void main ()
{

    unsigned short int n = 0;
    unsigned short int p = 0;
    unsigned short int setb = 0;
    unsigned short int inv = 0;
    unsigned short int rev = 0;
    unsigned short int x = 0;
    unsigned short int y = 0;
    unsigned long int len = 0;

    n = 5;

    p = 7;
    x = 466;
    y = 0245;
    


    printf ( "n = %d;\np = %d;\nx = %d;\ny = %d;\n", n, p, x, y );
    printf ( "n in binary = %46d;\np in binary = %46d;\nx in binary = %46d;\ny in binary = %46d;\n\n", dec_bin ( n ), dec_bin ( p ), dec_bin ( x ), dec_bin ( y ) );

//    setb = setbits ( x, p, n, y );
//    printf ( "rezult = %4d; and in binary = %19d;\n\n", setb, dec_bin ( setb ) );

//    inv = invert ( x, p, n );
//    printf ( "rezult of inv = %d; and in binary = %12d;\n", inv, dec_bin ( inv ) );

    rev = rightrot ( x, n );
    printf ( "rezult of rotation to right = %d; and in bin = %13d;\n\n", rev, dec_bin ( rev ) );
    
    len = 262143;
    printf ( "len = %lu; and in bin = %39lu;\n", len, dec_bin ( len ) );
    printf ( "and size of unsigned long int = %d;\n", sizeof ( unsigned long int ) );

}


int setbits ( int x, int p, int n, int y )
{
    
/*
    In this function we get rezult in mode: 01100101
    where bits numbered from 0 and their number grows from left to right.
    We have to get n bits from second number from position 0.
    After we place getted bits to x and we put bits from p position to the right.
                        

*/

    int first = 0;
    int second = 0;
    unsigned short int third = 0;
    unsigned short int fourth = 0;

    //get n ones bits on position, that starts in p
    first = (  ( ~ ( ~ 0 << n ) << ( p - n + 1 ) ) );
    printf ( "first = %42d;\n", dec_bin ( first ) );

    //get n bits of y, moved to position p
    second = ( ( y & ( ~ ( ~ 0 << n) ) ) << ( p - n + 1 ) );
    printf ( "second = %41d;\n", dec_bin ( second ) );
    
    //get nulls in n bits of x in position, that starts in p
    third = x & ( ~ first ) ;
    printf ( "third = %42d;\n", dec_bin ( third ) );

    //get rezult)
    fourth = third | second;
    printf ( "fourth = %41d;\n\n", dec_bin ( fourth ) );

    return fourth;
}


int setbits2 ( int x, int p, int n, int y )
{
    
/*
    In this function we get rezult in mode: 01100101
    where bits numbered from 0 and their number grows from left to right.
    We have to get n bits from second number from position 0.
    After we place getted bits to x and we put bits from p position to the left.
                        

*/

    int first = 0;
    int second = 0;
    unsigned short int third = 0;
    unsigned short int fourth = 0;

    //get n ones bits on position, that starts in p
    first = (  ( ~ ( ~ 0 << n ) << ( p + n + 1 ) ) );
    printf ( "first = %42d;\n", dec_bin ( first ) );

    //get n bits of y, moved to position p
    second = ( ( y & ( ~ ( ~ 0 << n) ) ) << ( p + n + 1 ) );
    printf ( "second = %41d;\n", dec_bin ( second ) );
    
    //get nulls in n bits of x in position, that starts in p
    third = x & ( ~ first ) ;
    printf ( "third = %42d;\n", dec_bin ( third ) );

    //get rezult)
    fourth = third | second;
    printf ( "fourth = %41d;\n\n", dec_bin ( fourth ) );

    return fourth;
}




unsigned getbits ( unsigned x, int p, int n )
{

    return ( x >> ( p+1-n ) & ~ ( ~ 0 << n) );

}




unsigned long int dec_bin ( unsigned long int n )  /* Function to convert decimal to binary.*/
{    
    unsigned long int rem = 0;
    unsigned long int i = 1;
    unsigned long int binary = 0;

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
    int rem = 0;

    while ( n != 0 ){
        rem = n%10;
        n /= 10;
        decimal += rem * pow( 2, i);
        ++i;
    }

    return decimal;
}


unsigned short int invert ( unsigned short int x, unsigned short int p, unsigned short int n )
{
    unsigned short int first = 0;
    unsigned short int second = 0;
    unsigned short int third = 0;
    unsigned short int fourth = 0;
    unsigned short int fifth = 0;

    //get n ones bits on position, that starts in p
    first = (  ( ~ ( ~ 0 << n ) << ( p - n + 1 ) ) );
    printf ( "first = %42d;\n", dec_bin ( first ) );

    //get n bits of x, that are on position p
    second = ( x & ( ( ~ ( ~ 0 << n) ) << ( p - n + 1 ) ) );
    printf ( "second = %41d;\n", dec_bin ( second ) );
    
    //get nulls in n bits of x in position, that starts in p
    third = x & ( ~ first ) ;
    printf ( "third = %42d;\n", dec_bin ( third ) );

    //get inverse of n bits of x from position p
    fourth = first & ( ~ second );
    printf ( "fourth = %41d;\n\n", dec_bin ( fourth ) );
    
    //put inverse bits in nulled on position p x
    fifth = third | fourth;
    printf ( "fifth = %42d;\n ", dec_bin ( fifth ) ); 

    return second;

}


unsigned short int rightrot ( unsigned short int x, unsigned short int n )
{

    unsigned short int first = 0;
    unsigned short int second = 0;
    unsigned short int third = 0;
    unsigned short int fourth = 0;

    //get first n bits of x
    first = x & ( ~ ( ~ 0 << n ) );
    printf ( "first = %52d;\n", dec_bin ( first ) );
    
    //move bits that are higher than n to right on n position 
    second = x >> n;
    printf ( "second = %51d;\n", dec_bin ( second ) );

    //move first n bites of x to the end of full number
    third = first << ( 16 - n - 1 );
    printf ( "third = %52d; and in dec = %d; and in oct = %o; \n", dec_bin ( third ), third, third );

    return first;

}

