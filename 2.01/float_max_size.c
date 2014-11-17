#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

float float_max_size();
double double_max();
int main()
{
    float float_max;
    double db_max;
    float_max = float_max_size();
    db_max = double_max();
    printf ( "maximal size of float eq:%46f;\n",float_max );

    db_max = double_max();
    db_max = double_max();
    printf ( "maximal size of double eq:%46ld;\n",db_max );

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
//            printf ( "inside INF cycle \nd_p=   %f;\nd=     %f;\nstep=         %f;\nd+step=%f;\ni=%d;\n",d_p,d,step,d+step,i );
//            printf ( "--------------------------------------------------------\n" );
            if (i==30)
                getchar();

        };
        d = d_p;
//        printf ( "in step cycle \nd=   %46f;\nstep=%46f;\n",d,step );
//        printf ( "===========================================\n" );
    };

    return d;

}

double double_max(){

    double d,d_p,step;
    int i;
    
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

    step = d;
    while ( step>1 ){
        step = step/10;
        i = 0;
        while ( (d<INFINITY) && (d+step!=d) ){
            d_p = d;
            d = d+step;
            i++;
//            printf ( "inside INF cycle \nd_p=   %f;\nd=     %f;\nstep=         %f;\nd+step=%f;\ni=%d;\n",d_p,d,step,d+step,i );
//            printf ( "--------------------------------------------------------\n" );
            if (i==30)
                getchar();

        };
        d = d_p;
//        printf ( "in step cycle \nd=   %46f;\nstep=%46f;\n",d,step );
//        printf ( "===========================================\n" );
    };

    return d;
    
}


