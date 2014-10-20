#include<stdio.h>
#include<limits.h>

void max_size();
void max_size_int();
void max_size_uint();

void main()
{
//    max_size();
//    max_size_int();
    max_size_uint();
}
void max_size()
{
    int i,j,k,k_b,perem;
    unsigned int step;
    short sh,end;
    k=0;
    i=0;
    j=0;
    sh=0;
    i=0;
    k=10;
    k_b=0;
    while (k>0){
	k_b=k;
	k=k*10;
	++i;
	printf("at step %d k=%d;\n",i,k);
    }
    printf("after first searching cycle k_b=%d;\n",k_b);
    k=k_b;
    k_b=0;
    end=0;
    i=0;
    step=0;
    while(step>=0){
	step=k/10;
	printf("step=%d;\n",step);
	++i;
	if(i==10)
	    getchar();
	j=0;
	while(k>0){
	    k_b=k;
	    printf("k+step=%d;k=%d\n",k+step,k);
	    perem=k+step;
	    while(perem<0){
		step=step/10;
		perem=k+step;
		printf("inside check step=%d;\n",step);
	    }
	    ++j;
	    if(j==20)
		getchar();
	    printf("step after check=%d;\n",step);
	    k=k+step;
	    printf("in the end of cycle k=%d;k_b=%d\n",k,k_b);
	    }
	k=k_b;
	k_b=0;
	printf("after removing k=%d;k_b=%d\n",k,k_b);
    }
    printf("in the end k=%d;\n",k);

}




void max_size_int()
{

    int i,j,step,d,d_p;

    i=j=step=d=d_p=0; 

    d=1;
    while(d>0){
	++i;
	d_p=d;
	d=d*10;
	printf("at step %i d=%d;\n",i,d);
    }
//after getting negative value of digit d replacing him with backup
    d=d_p;
    printf("backup) d=%d;\n",d);
//and now we get max size of int
    step=d;
    while(step>1){
	step=step/10;
	i=0;
	while(d>0){
	    d_p=d;
	    d=d+step;
	    ++i;
	    printf("at step %d d=%d;\n",i,d);
	}
    	d=d_p;
	printf("backup2)) step=%d;d=%d;\n",step,d);


    }





}

void max_size_uint()
{

    int i,j;
    unsigned int step,d,d_p;

    i=j=0;
    step=d=d_p=0; 

    d=1;
    while(d>0){
	++i;
	d_p=d;
	d=d*10;
	printf("at step %2i d=%11d;d_p=%11d;cycle 1\n",i,d,d_p);
    }
//after getting negative value of digit d replacing him with backup
    d=d_p;
    printf("backup) d=%11d;\n",d);
//and now we get max size of int
    step=d;
    while(step>1){
	step=step/10;
	i=0;
	while(d>0){
	    d_p=d;
	    d=d+step;
	    ++i;
	    if(i==100)
		getchar();
	    printf("at step %2d d=%11d;\n",i,d);
	}
    	d=d_p;
	printf("backup2)) step=%2d;d=%11d;\n",step,d);


    }

/*    j=10;
    for(i=0;i<20;++i){
	j=j*10;
	printf("step=%d;d=%d;\n",i,j);
    }
*/

}

