#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

int calculate_uchar_max();
int calculate_schar_min();
int calculate_schar_max();

int calculate_usint_max();
int calculate_sint_min();
int calculate_sint_max();

unsigned int unsigned_int_max();
int int_min();
int int_max();

unsigned long ulong_max();
long min_size_long();
long max_size_long();

int calculate_llong_min();
int calculate_llong_max();
int calculate_ullong();

float float_min_size();
float float_max_size();

int main()
{
    int char_d,schar_min_d,schar_max_d,uchar_max_d,int_min_d,int_max_d,short_min_d,shirt_max_d,uint_max_d,i;
    unsigned int unsigned_int;
    long long_min,long_max;
    unsigned long u_long_max;
    long long llong_min_d,llong_max_d,ullong_max_d;
    float float_min,float_max;
    double double_min,double_max;

    printf("\n\nThis defined in file limits.h variables are just taken from file.\n");

/*    printf("CHAR_BIT=%d\n",CHAR_BIT);
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
*/
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
    printf("UINT_MAX=%u\n",UINT_MAX);
    printf("LONG_MAX= %ld\n",LONG_MAX);
    printf("LONG_MIN= %ld\n",LONG_MIN);
    printf("ULONG_MAX=%lu\n",ULONG_MAX);
    printf("LLONG_MAX=%lld\n",LLONG_MAX);
    printf("LLONG_MIN=%lld\n",LLONG_MIN);
    printf("ULLONG_MAX=%lld\n",ULLONG_MAX);
    printf ( "FLT_MAX=%f;\n",FLT_MAX );

    printf("\nAnd now it will be calculated.\n");

//---------------------------------------------char
/*    printf("For the first we calculate size of char.\n");
    i=calculate_char();
    printf("Size of char=%d;\n",i);
*/

//    printf("\nNext we will know size of unsigned char.\n");    
    i=calculate_uchar_max();
    printf("Maximal value of unsigned char equal %d\n",i);

//    printf("\nNext we will know size of signed char.\n");    
    i=calculate_schar_min();
    printf("Minimal value of signed char equal %d\n",i);

//    printf("\nNext we will know size of signed char.\n");    
    i=calculate_schar_max();
    printf("Maximal value of signed char equal %d\n",i);


//---------------------------------------------short-integer

/*    i=calculate_usint_max();
    printf("Maximal value of unsigned short int equal %d\n",i);

    i=calculate_sint_min();
    printf("Minimal value of signed short int equal %d\n",i);

    i=calculate_sint_max();
    printf("Maximal value of signed short int equal %d\n",i);
*/

//---------------------------------------------integer 

    unsigned_int=unsigned_int_max();
    printf("Maximal value of unsigned int equal %u\n",unsigned_int);

    i=int_max();
    printf ( "Maximal value of signed int equal %d\n",i );
    
    i = int_min();
    printf ( "Minimal value of signed int equal %d;\n",i );

//---------------------------------------------long-integer

    long_max = max_size_long();
    printf("Maximal value of signed long int equal %ld\n",long_max);

    long_min = min_size_long();
    printf("Minimal value of signed long int equal %ld\n",long_min);

    u_long_max = ulong_max();
    printf("Maximal value of signed long int equal %lu\n",u_long_max);

//=============================================float

    float_max = float_max_size();
    printf ( "Maximal value of float equal %f;\n",float_max );

    float_min = float_min_size();
    printf ( "Minimal value of float equal %f;\n",float_min );


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

int calculate_uchar_max()
{
    unsigned char i=1;

    while(i>0){
	++i;
//	printf("i=%d;\n",i);
    }
    --i;
//    ++i;
    return i;

}

//---------
unsigned int unsigned_int_max()
{
    unsigned int d,d_p,step,max;
    int j,i,prov;
    i = j = step = d = d_p = prov = 0;
    d = 1;
    while ( d>d_p ){
        ++i;
        d_p = d;
        d = d*10;
    }
//after getting negative value of digit d replacing him with backup
    d = d_p;
//and now we get max size of int    
    step = d;
    while ( step>1 ){
        step = step/10;
        i = 0;
        max = 0;
        prov = 0;
	d_p = 0;
        while ( prov == 0 ){
            d_p = d+step;
            if ( d_p<d )
                prov = 1;
            else {
                d = d+step;
                
            }
            ++i;
        }
    }
    return d;
}


int int_max()
{
    int i,j,step,d,d_p;
    i = j = step = d = d_p = 0;
    d = 1;
    while ( d>0 ){
        ++i;
        d_p = d;
        d = d*10;
    }
//after getting negative value of digit d replacing him with backup
    d = d_p;
//and now we get max size of int    
    step = d;
    while ( step>1 ){
        step = step/10;
        i = 0;
        while ( d>0 ){
            d_p = d;
            d = d+step;
            ++i;
        }
        d = d_p;
    }
    return d;
}

//---------

int int_min()
{
    int d,d_p,min,step;
    short int i,j;

    d = 0;
    d_p = 0;
    i = 0;
    j = 0;

    d = -1;
    while ( d<0 ) {
        d_p = d;
        d = d*10;
    }
    
    d = d_p;
//    printf ( "d=%10d;d_p=%10d;\n",d,d_p );

    d_p = 0;
    step = d;
    while ( step<(-1) ){
        step = step/10;
        while ( d<0 ){ 
            d_p = d;
            d = d + step;
        }
        d = d_p;

    }
    return d;
}


long calculate_ulint_max()
{
    unsigned long int i=0;

/*    while(i>=0){
	++i;
    }
*/
    --i;
    
    return i;

}

int calculate_lint_min()
{
    signed long int i=0;

    while(i<=0){
	--i;
//	printf("i=%d;\n",i);
    }
    ++i;
    
    return i;

}


long max_size_long()
{
    int i,j;
    long  step,d,d_p;

    i = j = 0;
    step = d = d_p = 0; 

    d = 1;
    while(d>0){
	++i;
	d_p = d;
	d = d*10;
//	printf("at step %2i d = %20ld;d_p = %20ld;cycle 1\n",i,d,d_p);
    }
//after getting negative value of digit d replacing him with backup
    d = d_p;
//    printf("backup) d = %20ld;\n",d);
//and now we get max size of long
    step = d;
    while ( step>1 ){
	step = step/10;
	i = 0;
	while ( d>0 ){
	    d_p = d;
	    d = d+step;
	    ++i;
	    if( i ==100 )
		getchar ();
//	    printf("at step %20ld d = %20ld;\n",i,d);
	}
    	d = d_p;
//	printf("backup2)) step = %20ld;d = %20ld;\n",step,d);


    }
//    printf("in result d = %20ld;\n",d);
    return d;
}

long min_size_long()
{

    long d,d_p,step;
    step = d = d_p = 0;

    d = (-1);
    while ( d<0 ){
        d_p = d;
        d = d*10;
    }
    d = d_p;

    step = d;
    while ( step<(-1) ){
        step = step/10;
        while ( d<0 ){
            d_p = d;
            d = d+step;
        }
        d = d_p;
    }

//    printf ( "d=%ld;\n",d );
    return d;

}

unsigned long ulong_max(){

    int prov;
    unsigned long d,d_p,step;

    d = d_p = step = 0;
    d = 1;
    while ( d>d_p ){
        d_p = d;
        d = d*10;
    };
    d = d_p;

    step = d;
    while ( step>1 ){
        step = step/10;
        prov = 0;
        d_p = 0;
        while ( prov==0 ) {
            if ( (d+step)<d )
                prov = 1;
            else
                d = d+step;
        };
//        d = d_p;
    };
    return d;

}

float float_max_size(){

    float d,d_p,step;
    short int i;

    d = d_p = step = 0;
    i = 0;

    d = 1;
    while ( d!=INFINITY ){
        d_p = d;
        d = d*10;
        i++;
//        printf ( "d=%46f;i=%d\n",d,i );
//        if ( i==100 )
//            getchar();
    };
    d = d_p;
//    printf ( "after 1 cycle d=%f;\n",d );

    step = d;
    while ( step>1 ){
        step = step/10;
        i = 0;
        while ( (d<INFINITY) && (d+step!=d) ){
            d_p = d;
            d = d+step;
            i++;
/*            printf ( "inside INF cycle \nd_p=   %f;\nd=     %f;\nstep=         %f;\nd+step=%f;\ni=%d;\n",d_p,d,step,d+step,i );
            printf ( "--------------------------------------------------------\n" );
            if (i==30)
                getchar();
            if (i==60)
                getchar();
            if (i==130)
                getchar();
            if (i==230)
                getchar();
*/
        };
        d = d_p;
/*        printf ( "in step cycle \nd=   %46f;\nstep=%46f;\n",d,step );
        printf ( "===========================================\n" );
*/
    };

    return d;

}

float float_min_size(){

    float d,d_p,step;
    short int i;

    d = d_p = step = 0;
    i = 0;

    d = -1;
    while ( d!=-INFINITY ){
        d_p = d;
        d = d*10;
    };
    d = d_p;

    step = d;
    while ( step<-1 ){
        step = step/10;
        i = 0;
        while ( (d>-INFINITY) && (d+step!=d) ){
            d_p = d;
            d = d+step;
            i++;
        };
        d = d_p;
    };

    return d;


}
