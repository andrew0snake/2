#include <stdio.h>
#include <math.h>

int setbits ( int x, int p, int n, int y );
int dec_bin ( int c );

void main ()
{

    int i = 0;
    int j = 0;
    int x = 0;
    int p = 0;
    int n = 0;
    int y = 0;

    x = 466;
    p = 7;
    n = 3;
    y = 164;

    i = ~ 1;
    printf ( "i = %d; and in binary = %d;\n", i, dec_bin ( i ) );
    printf ( "x = %d & ~ i = %d = %d;\n", x, i, x & ( ~ i ) );
    printf ( "x = %d | ~ i = %d = %d;\n", dec_bin ( x ) , dec_bin ( i ) , dec_bin ( x | ( ~ i ) ) );
   
}


int setbits (int x, int p, int n, int y )
{

    


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