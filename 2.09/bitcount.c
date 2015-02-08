#include <stdio.h>

int bitcount1 ( unsigned int x );
int bitcount2 ( unsigned int x );
unsigned long int dec_bin ( unsigned long int n );

void main ()
{

    int x = 0;
    int rez = 0;

    printf ( "insert please number:" );
    scanf ( "%d", &x );
    printf ( "\ngettend x = %30d;\nand in bin = %29lu;\n\n", x, dec_bin ( x ) );

    rez = bitcount1 ( x );
    printf ( "rezult of counting bits = %16d;\n", rez );

    rez = bitcount2 ( x );
    printf ( "re<unt of counting bits = %16d;\n", rez );


}

int bitcount1 ( unsigned int x )
{

    int b = 0;

    for ( b = 0; x != 0; x >>= 1 ){
        if ( x & 01 )
            b++;
    };

    return b;

}


int bitcount2 ( unsigned int x )
{

    int b = 0;
  
/*    while ( x != 0 ) {
        if ( x ^ ( x &= ( x - 1 ) ) )
            ++b;
        x >>= 1;
        printf ( "x in bin = %lu;\n", dec_bin ( x ) );
        printf ( "x ^ ( x &= ( x - 1 ) ) = %d;\n", x ^ ( x &= ( x - 1 ) ) );
    };
*/
    while ( x != 0 ) {
        printf ( "x = %10d; and in bin = %13lu;\n", x , dec_bin ( x ) );

        b = ( x & ( x - 1 ) );
        printf ( "b = %10d; and in bin = %13lu;\n", b, dec_bin ( b ) );

        printf ( "x ^ b = %6d; and in bin = %13lu;\n", ( x ^ b ), dec_bin ( x ^ b ) );

        x >>=1;
        printf ( "x >>= 1 = %32lu;\n\n", dec_bin ( x ) );
    }

    return b;
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


