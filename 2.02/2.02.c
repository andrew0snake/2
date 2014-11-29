#include <stdio.h>
#define lim 100

enum prov2 {NO,YES};
unsigned long int next = 1;

int rand (void);
void srand (unsigned int seed);
int atoi_my (char s[]);
int lower (int c);

void main ()
{

    enum prov2 check;
    int i,j,c,prov;
    char s[100];
    check = YES;

    for (i=0;i<100;i++)
        s[i] = 0;

    for (i = 0; i < lim-1 && ( c = getchar() ) != EOF && c != '\n'; ++i)
        s[i] = c;

    printf ( "string s=%s;\n",s );

    for (i=0; i<100; i++)
        s[i] = 0;

    prov = 0;
    i = 0;
    while (prov == 0){
        if (i<lim-1)
            if ( (c = getchar() ) != EOF)
                if (c != '\n' ){
                    s[i] = c;
                    i++;
                }
            else 
                prov = 1;
        else 
            prov = 1;
    }

    printf ( "string s=%s;\n",s );
    printf ( "enumeration NO=%d;YES=%d;check=%d;\n",NO,YES,check );

    i = 10;
    j = 4;
    c = i%j;
    printf ( "i = %d;j = %d;c = i%j = %d;\n",i,j,c );
    
    i = 10;
    j = 4;
    c = i/j;
    printf ( "i = %d;j = %d;c = i/j = %d;\n",i,j,c );

    i = atoi_my(s);
    printf ( "returned atoi_my is %d;\n",i );
    
    i = 'a';
    j = 'A';
    printf ( "a=%d;A=%d;\n",i,j );

//    for (i=0;i<=129;++i)
//        printf ( "digit=%d;char=%c;\n",i,i );

    prov = 0;
    while (!prov){
        c = getchar ();
        if (c!='\n')
            i = lower (c);
        if (c == 59)
            prov = 1;
        else
            if (c!='\n') 
                printf ( "getted symbol=%c;lowered symbol=%c;in digit symbol=%d\n",c,i,c );
    }

    while ( (c = getchar() ) != 59){
        printf ( "in char c=%c;in digit c=%d;\n",c,isdigit(c) );
    }


    srand (next);
    printf ( "at first step next=%d;\n",next );
    next = rand ();
    printf ( "next=%d;\n",next );
}


int atoi_my(char s[])
{
    int i,n;
    n = 0;
    
    for (i = 0; s[i] >='0' && s[i]<='9';++i)
        n = 10*n+(s[i]-'0');

    return n;

}

int lower (int c)
{

    if (c>='A' && c<='Z')
        return c + 'a' - 'A';
    else 
        return c;


}

int rand (void)
{
    next = next*1103515245 + 12345;

    return (unsigned int) (next/65535) % 32768;
}


void srand (unsigned int seed)
{

    next = seed;

}