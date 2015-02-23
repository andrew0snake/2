#include <stdio.h>

int gett ( char text[1000] );
void form_out ( char text [1000], int len );
void lang_out ( char text [1000], int len );
void lower ( char text [1000], int len );

void main () {

    char text [1000];
    int i = 0;
    int len = 0;

    for ( i = 0; i <=1000; ++i ){
        text [i] = 0;
    }

    len = gett ( text );

//    form_out ( text, len );

//    lang_out ( text, len );
    
    lower ( text, len );
    
    for ( i = 0; i <= len; ++i ){
        printf ( "%c", text [ i ] );
    };
}





int gett ( char text[1000] )
{

    int c = 0;
    int i = 0;
    
    for ( i = 0; i < 1000; ++i ) {
	text [ i ] = 0;
    };

    for ( i=0; ( c = getchar() ) != EOF; ++i ){
	text [ i ] = c;
    };

    return i;
}


void form_out ( char text [1000], int len ) 
{
    int i = 0;

    for ( i = 0; i <= len; ++i ) {
        printf ( "%6c%c", text [i], ( i % 10 == 9 || i == len-1 ) ? '\n' : ' ' );
    };

}


void lang_out ( char text [1000], int len ) 
{
    int i = 0;
    int c = 0;
    
    for ( i = 0; i <= len; ++i ) {
        printf ( "Вы имеете %d элемент%s.\n ", text [ i ], ( text [ i ] % 10 == 1 && text [ i ] % 100 != 11 ) ? \
            " " : ( ( text [ i ] % 100 < 10 || text [ i ] % 100 > 20 ) && text [ i ] % 10 >= 2 && text [ i ] % 10 <= 4 ) ?\
            "а" : "ов" );
    };

}


void lower ( char text [], int len )
{
    int i = 0;
    
    for ( i = 0; i <= len; ++i ) {
        text [ i ] = ( text [ i ] >= 'A' && text [ i ] <= 'Z' ) ? ( text [ i ] + 'a' - 'A' ) : ( text [ i ] );
    }

//    return (  )

}
