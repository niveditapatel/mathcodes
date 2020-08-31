#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

float valueoffunction(int *p, float x, int d)
{  int i=0;
    double sum=0;
  for(i=0;i<=d;i++)
      sum=sum+p[i]*pow(x,i);


    return sum;

}



void main()
{   float answerarray[100];
     int d,itno=1
     ;
     float error;
    printf("enter the degree of the polynomial");
    scanf("%d",&d);
     int *p;
    p = (int *)malloc((d+1)*sizeof(int));
     printf("enter the degree of accuracy: ");
    float e;
    scanf("%f",&e);
    int i;
    answerarray[0]=0;
    for(i=0;i<=d;i++){
        printf("Give co-efficient of the polynomial for x power%d: ",i);
        scanf("%d",&p[i]);
    }
        float a=0,b=0,c=0,fa=0,fb=0,fc=0;
        printf("Give value of 'a' such that f(a) < 0: " );
        scanf("%f",&a);
         printf("Give value of 'b' such that f(b) > 0: " );
            scanf("%f",&b);
              printf("\n a               b             c            fa             fb            fc\n");
        do{
        fa=valueoffunction(p,a,d);
        fb=valueoffunction(p,b,d);
        c=((a*fb)-(fa*b))/(fb-fa);
        answerarray[itno]=c;
        fc=valueoffunction(p,c,d);
               printf("%f     %f    %f      %f      %f     %f\n",a,b,c,fa,fb,fc);
        if(fc<0)
            a=c;
        else
            b=c;


        error=answerarray[itno]-answerarray[itno-1];

itno++;
        }while(fabs(error)>e);
    }
