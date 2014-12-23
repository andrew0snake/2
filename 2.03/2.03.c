#include <stdio.h>

void get_string ( char str [] );
int htol ( char str []);
int hex_symb ( char symb );
int hex_degree ( int step);

void main ()
{
    int len = 0;
    int i = 0;
    char str[100];

    for (i=0;i<100;++i)
        str[i] = 0;
   
    printf ( "Input hexadecimal string in format 0x .\n" ) ;
    get_string (str);
//    printf ( "in main string=%s;\n",str );
 
    len = htol (str);

    printf ( "In digital string equal %d;\n",len );
}

void  get_string (char str[])
{
    int i = 0;
    int j = 0;
    char check1 = 0;     
    char check2 = 0;     
    char exit = 0;

    while ( !exit ){
        check1 = 0;
        check2 = 0;
        while ( !check2 ){
            str[i] = getchar ();
            if ( str[i]!='\n' && str[i]!=EOF && i<=100 ) {
                if ( ( str[i]>='a' &&  str[i]<='f' ) || ( str[i]>='A' && str[i]<='F' ) || ( str[i]>='0' && str[i]<='9' ) || ( i == 1 && str[i] == 'x' ) )
                    ++i;
                else {
                    check1 = 1;
                    ++i;
                };
            }
            else{
                check2 = 1;
            };
        };
        if ( check1 == 1 ) {
            for ( j = 0; j<=i; ++j ) {
                str[j] = 0;
            };
            i = 0;
            exit = 0;
            printf ( "Wrong input, try again.\n" );
        } 
        else {
            exit = 1;
        };
    }
 
//    printf ( "getted in get_string string is:%s;\n",str );

}

int htol (char string[])
{

    int i = 0;
    int j = 0;
    int rev = 0;
    int sum = 0;
    int step = 0;
    char symb = 0;

//    printf ( "getted in htol string eq:%s;and its string eq %d\n", string, strlen ( string ) );
//    printf ( "%c\n", string[0] );

    for ( i = strlen ( string ) - 1 -1 ; i>=2; --i ) {
        j = hex_symb ( string [i] );
        step = hex_degree ( rev );
        sum = sum + step * j;
        ++rev;
//        printf ( "i=%d;j=%d;step=%d;sum=%d;rev=%d;string[%d]=%c\n", i, j, step, sum, rev, i, string[i] );
    }

    return sum;
}

int hex_symb ( char symb ) 
{

    int i = 0;
    int digit = 0;

//    printf ( "getted symbol:%c;\n",symb );

    if ( symb == '0' )
        digit = 0;

    if ( symb == '1' )
        digit = 1;

    if ( symb == '2' )
        digit = 2;

    if ( symb == '3' )
        digit = 3;

    if ( symb == '4' )
        digit = 4;

    if ( symb == '5' )
        digit = 5;

    if ( symb == '6' )
        digit = 6;

    if ( symb == '7' )
        digit = 7;

    if ( symb == '8' )
        digit = 8;

    if ( symb == '9' )
        digit = 9;

    if ( symb == 'a' )
        digit = 10;

    if ( symb == 'A' )
        digit = 10;

    if ( symb == 'b' )
        digit = 11;

    if ( symb == 'B' )
        digit = 11;

    if ( symb == 'c' )
        digit = 12;

    if ( symb == 'C' )
        digit = 12;

    if ( symb == 'd' )
        digit = 13;

    if ( symb == 'D' )
        digit = 13;

    if ( symb == 'e' )
        digit = 14;

    if ( symb == 'E' )
        digit = 14;

    if ( symb == 'f' )
        digit = 15;

    if ( symb == 'F' )
        digit = 15;

//    printf ( "converted symbol:%d;\n",digit );
    return digit;

}

int hex_degree ( int step )
{

    int i = 0;
    int j = 0;
    int res = 1;

    for ( i=0; i<step; ++i){
        res = res * 16;
//        printf ( "res=%d;\n",res );
    }

    return res;
}


