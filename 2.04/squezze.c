#include <stdio.h>

void squezze ( char s[], int c, int len );
int getline_my ( char line[] );

void main ()
{

    char string[100];
    int c=0;
    int i = 0;
    int j = 0;
    int sum = 0;
    int len = 0; 

    c = 'c';
    printf ( "c=%d in digit and =%c in char;\n",c,c );
    printf ( "insert please string:" );
    len = getline_my ( string );
    squezze ( string, c, len );
    printf ( "after squezze stering seems so:%s;\n",string );

    i = 5;
    j = 3;
    sum = ++i;
    printf ( "sum = ++i = %d;\n",sum );
    sum = i++;
    printf ( "sum = i++ = %d;\n",sum );
}


void squezze ( char s[], int c, int len )
{
    int i = 0;
    int j = 0;

    printf ( "function squezze begin.\n" );
    for ( i = j = 0; s[i] != '\0'; i++ ){
        if ( s[i] != c){
//            s[j++] = s[i];
              s[j] = s[i];
        printf ( "inside  s[i = %d] = %c;s[j = %d] = %c;\n",i,s[i],j,s[j] );
              j++;
        }
        printf ( "outside s[i = %d] = %c;s[j = %d] = %c;\n",i,s[i],j,s[j] );
    };
//    --i;
    s[i] = '\0';
    printf ( "i=%d;\n",i );
    
    for ( j = i+1; j <= len; ++j ){
        s[j] = ' ';
    }

}

int getline_my ( char line [] )
{
    int i = 0;
    int c = 0;

    for ( i = 0; ( (c = getchar () ) != EOF ) && c != '\n';++i ){
        line[i] = c;
        printf ( "line[%d] = %c; i = %d;\n",i,line[i],i );
    }

    line[++i] = '\0';

    return i;

}