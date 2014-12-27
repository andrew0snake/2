#include <stdio.h>

void squezze ( char s[], int c, int len );
int getline_my ( char line[] );
void strcat_my ( char s[], char t[] );
void squezze_del ( char s1[], char s2[] );

void main ()
{

    char string[100];
    int c=0;
    int i = 0;
    int j = 0;
    int sum = 0;
    int len = 0; 
    char first[100];
    char second[200];

/*    c = 'c';
    printf ( "c=%d in digit and =%c in char;\n",c,c );
    printf ( "Please insert string for squeeze:" );
    len = getline_my ( string );
    squezze ( string, c, len );
    printf ( "After squezze stering seems so:%s;\n",string );

    for ( i = 0; i<len; ++i) {
        printf ( "string[i=%d]=%c;\n", i, string[i] );
    
    }
*/    
//    printf ( "And now we try to concatenate strings.\nPlease, input first string:" );
    printf ( "Please, input first string:" );
    len = getline_my ( first );
    printf ( "Please, input second string:" );
    len = getline_my ( second );
    squezze_del ( first, second );
    printf ( "after check string seems so:%s;\n", second );
//    printf ( "Before concatenation strings seems so:\nFirst string:%s;\nSecond string:%s;\n", first, second );
//    strcat_my ( first, second );
//    printf ( "Copying first string to second.\nResult:%s;\n", first );
    
/*    i = 5;
    j = 3;
    sum = ++i;
    printf ( "sum = ++i = %d;\n",sum );
    sum = i++;
    printf ( "sum = i++ = %d;\n",sum );
    */
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
//        printf ( "outside s[i = %d] = %c;s[j = %d] = %c;\n",i,s[i],j,s[j] );
    };
//    --i;
    s[j] = '\0';
    printf ( "i = %d; j = %d;\n", i, j );
    
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
    printf ( "getted string:%s;\n", line );

    return i;

}

void strcat_my ( char s[], char t[] )
{
    int i = 0;
    int j = 0;
    
    printf ( "Searching end of first string;\n" );
    while ( s[i]!='\0') {
        printf ( "s[%d]=%c;\n",i,s[i] );
        ++i;
    };
    --i;
    printf ( "Copying second string to first.\n" );
    while ( (s[i++] = t[j++] ) != '\0' ){
        printf ( "s[%d]=%c;t[%d]=%c;\n", i, s[i], j, t[j] );
    };

}


void squezze_del ( char s1[], char s2[] )
{

    int i = 0;
    int j = 0;
    int k = 0;

    for (i = 0; s1[i] != '\0'; ++i) {
        for ( j = 0; s2[j] != '\0'; ++j) {
            if ( s2[j] == s1[i]) {
                k = j;
                while ( s2[k] != '\0' ) {
                    s2[k] = s2[k+1];
                    ++k;
                };
            };            
        };
    };
};