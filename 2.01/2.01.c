#include <stdio.h>
#include <limits.h>

int calculate_char();
int calculate_schar_min();
int calculate_schar_max();
int calculate_uchar_max();
int calculate_sint_min();
int calculate_sint_max();
int calculate_long_min();
int calculate_long_max();
int calculate_short_min();
int calculate_short_max();
int calculate_uint_max();
int calculate_ulong_max();
int calculate_llong_max();
int calculate_llong_min();
int calculate_ullong();

void main()
{
    int char_d,schar_min_d,schar_max_d,uchar_max_d,sint_min_d,sint_max_d,short_min_d,shirt_max_d,uint_max_d,i;
    long long_min_d,long_max_d,ulong_max_d;
    long long llong_min_d,llong_max_d,ullong_max_d;

    printf("\n\nThis defined in file limits.h variables are just taken from file.\n");

    printf("CHAR_BIT=%d\n",CHAR_BIT);
    printf("SCHAR_MIN=%d\n",SCHAR_MIN);
    printf("SCHAR_MAX=%d\n",SCHAR_MAX);
    printf("UCHAR_MAX=%d\n",UCHAR_MAX);
    printf("INT_MAX=%d\n",INT_MAX);
    printf("INT_MIN=%d\n",INT_MIN);
    printf("LONG_MIN=%d\n",LONG_MIN);
    printf("LONG_MAX=%d\n",LONG_MAX);
    printf("SHRT_MIN=%d\n",SHRT_MIN);
    printf("SHRT_MAX=%d\n",SHRT_MAX);
    printf("UCHAR_MAX=%d\n",UCHAR_MAX);
    printf("UINT_MAX=%d\n",UINT_MAX);
    printf("USHRT_MAX=%d\n",USHRT_MAX);
    printf("ULONG_MAX=%d\n\n",ULONG_MAX);

    printf("CHAR_BIT=%d\n",CHAR_BIT);
    printf("SCHAR_MIN=%d\n",SCHAR_MIN);
    printf("SCHAR_MAX=%d\n",SCHAR_MAX);
    printf("UCHAR_MAX=%d\n",UCHAR_MAX);
    printf("CHAR_MIN=%d\n",CHAR_MIN);
    printf("CHAR_MAX=%d\n",CHAR_MAX);
    printf("SHRT_MIN=%d\n",SHRT_MIN);
    printf("SHRT_MAX=%d\n",SHRT_MAX);
    printf("USHRT_MAX=%d\n",USHRT_MAX);
    printf("INT_MIN=%d\n",INT_MIN);
    printf("INT_MAX=%d\n",INT_MAX);
    printf("UINT_MAX=%g\n",UINT_MAX);
    printf("LONG_MAX=%d\n",LONG_MAX);
    printf("LONG_MIN=%d\n",LONG_MIN);
    printf("ULONG_MAX=%d\n",ULONG_MAX);
    printf("LLONG_MAX=%d\n",LLONG_MAX);
    printf("LLONG_MIN=%d\n",LLONG_MIN);
    printf("ULLONG_MAX=%d\n",ULLONG_MAX);

    printf("\nAnd now it will be calculated.\n");

    printf("For the first we calculate size of char.\n");
    i=calculate_char();
    printf("Size of char=%d;\n",i);

    printf("\nNext we will know size of signed char.\n");    
    i=calculate_schar_min();
    printf("Minimal value of signed char equal %d\n",i);

    printf("\nNext we will know size of signed char.\n");    
    i=calculate_schar_max();
    printf("Maximal value of signed char equal %d\n",i);


}


int calculate_char()
{
    char i=0;

    while(i>=0){
	++i;
    }
    --i;
    return i;

}

int calculate_schar_min()
{
    signed char i=0;

    while(i<=0){
	--i;
    }
    ++i;
//    ++i;
    return i;

}


int calculate_schar_max()
{
    signed char i=0;

    while(i>=0){
	++i;
    }
    --i;
//    ++i;
    return i;

}


