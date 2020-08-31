#include<stdio.h>
#include<conio.h>


void main()
{ int i;
int j; int n;
int p;
float array[15];
float temp;
float mean; float median; int mode;
   printf("enter the number of values to enter");
                scanf("%d",&n);
                printf("enter the values in integer form:");
                for(i=0;i<n;i++)
                {
                    scanf("%f",&array[i]);
                }

                for(i=0;i<n-1;i++)
   {
       for(p=0;p<(n-i-1);p++)
       {
           if(array[p]>array[p+1])
           {temp=array[p];
           array[p]=array[p+1];
           array[p+1]=temp;
       }}
   }
    printf("sorted\n");
    for(i=0;i<n;i++)

                    printf("%f  ",array[i]);

       if(n%2==0)
       median=(array[(n/2-1)]+array[n/2])/2;
       else{
       median=array[(n+1)/2-1];}
       printf("the median is %f\n",median);
       int count[n];
       for(i=0;i<n;i++)
                {
                    int x=array[i];
                    count[i]=1;
                    for(j=0;j<i;j++)
                    {
                        if(array[j]==x)
                        count[i]++;
                    }
                    for(j=(i+1);j<n;j++)
                    {
                        if(array[j]==x)
                        count[i]++;
                    }
                }
                float sum=0;int maxpos=0;
       for(i=0;i<n;i++)
       {
           sum+=array[i];

           if(count[i]>count[maxpos])
           maxpos=i;
       }


       if(count[maxpos]!=1)
       {mode=array[maxpos];
         printf("MODE: %f\n",array[maxpos]);
       }
       else
       printf("no mode because each value occurs once\n");

       mean=sum/n;
       printf("mean is %f\n",mean);
           float t;
                  float sd;
                   for(i=0;i<n;i++)
    {
        t+=pow(mean-array[i],2);

    }
    t/=n;
    printf("%f\n",t);
    sd=pow(t,0.5);
    printf("\nstandard deviation of the data is =%f",sd);
   }



