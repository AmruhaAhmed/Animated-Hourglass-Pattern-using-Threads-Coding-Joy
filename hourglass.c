#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
void *runner();
void main()
{
    pthread_t tid;//thread id
    int ret;//to store a return value
    ret=pthread_create(&tid,NULL,runner,0);//creating a thread
    
    if(ret==-1)
    {
        printf("\n Thread has not been created");
        exit(1);
    }
    pthread_join(tid,0);
 
}

void *runner()
{
        int m=11;//number of asterisks to be printed
        int s=0;// number of spaces
        int i,j;//i-outer loop counter, j-inner loop counter
        //upper half of the pattern
        for(i=1;i<=6;i++)
        {
            for(j=1;j<=s;j++)
            printf("  ");
            for(j=1;j<=m;j++)
            printf("* ");
            sleep(1);
            s++;
            m-=2;
            printf("\n");
        }
        m=3;
        s=4;
        //lower half of the pattern
        for(i=1;i<=5;i++)
        {
            for(j=1;j<=s;j++)
            printf("  ");
            for(j=1;j<=m;j++)
            printf("* ");
            sleep(1);
            s--;
            m+=2;
            printf("\n");
        }
        pthread_exit(0);
}


