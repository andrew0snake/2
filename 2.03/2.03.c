#include <stdio.h>

void get_string (char str []);
int htol (char string);

void main ()
{
    int len,i;
    char str[100];

    for (i=0;i<100;++i)
        str[i] = 0;
   
    get_string (str);
    printf ( "string=%s;\n",str );
 
    len = htol (str);

}

void  get_string (char str[])
{
    int i = 0;
    char prov = 0;     

    while ( !prov ){
        if ( (str[i]=getchar() )!='\n' && str[i]!=EOF && i<=100 )
            if (str[i]>='a' &&  str[i]<='f' ) { 
//                printf ( "first check! str[%d] = %c\n",i,str[i] );
                  i = i;
            }
            else
                if (str[i]>='A' && str[i]<='F'){ 
//                    printf ( "second check!\n" );
                      i = i;
                }
                else
                    if (str[i]>='0' && str[i]<='9') { 
//                        printf ( "third check! str[%d] = %c\n",i,str[i] );
                          i = i;
                    }
                    else 
                        if ( i==1 && str[i] == 'x' ){
//                            printf ( "fourth check!\n" );
                              i = i;
                        }
                       
                        else {
                            printf ( "wrong input!str[%d]=%c;\n",i,str[i] );
                            prov = 1;
                        }
        else
            prov = 1;
//        str[i] = getchar();
        printf ( "step %d done!;str[%i]=%c;\n",i,i,str[i] );
        ++i;
    }


}

int htol (char string)
{

}
