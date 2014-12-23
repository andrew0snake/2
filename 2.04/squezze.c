#include <stdio.h>

void squezze ( char s[], int c );
void getline_mu ( char line[] );

void main ()
{

    char string[100];
    int c=0;
    int i = 0;
    int j = 0;
    int sum = 0;

    c = 'c';
    getline_my ( string );
    squezze ( string, c );
    printf ( "after squezze stering seems so:%s;\n",string );

    i = 5;
    j = 3;
    sum = ++i;
    printf ( "sum = ++i = %d;\n",sum );
    sum = i++;
    printf ( "sum = i++ = %d;\n",sum );
}


void squezze ( char s[], int c )
{
    int i = 0;
    int j = 0;

    printf ( "function squezze begin.\n" );
    for ( i = j = 0; s[i] != '\0'; i++ ){
        if ( s[i] != c)
            s[j++] = s[i];
        printf ( "s[i = %d] = %c;s[j = %d] = %c;\n",i,s[i],j,s[j] );
    };
//    --i;
    s[i] = '\0';

}

void getline_my ( char line[] )
{
    int i = 0;
    int c = 0;

    for ( i = 0; ( (c = getchar () ) != EOF ) && c != '\n';++i ){
        line[i] = c;
        printf ( "line[%d] = %c; i = %d;\n",i,line[i],i );
    }


}