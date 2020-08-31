#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float functionvalue(int *p,float c, int d)
{   int i=0;
    float sum=0;
    for(i=d;i>=0;i--)
{
    sum+=p[i]*pow(c,i);
    }
    return sum;
}

float difffunctionvalue(int *pp,float c, int d)
{   int i=0;
    float sum=0;
    for(i=d;i>=0;i--)
{
    sum+=pp[i]*pow(c,(i-1));
    }
    return sum;
}
void main()
{   float x,fx,dfx;

    float acc,error,c;
    float answerarray[100];
    float sum=0;
    int i,d;
    int itno=1;


    printf("enter the degree of the polynomial");
    scanf("%d",&d);
    int *pp;
pp=(int *)malloc(sizeof(int)*(d+1));

    int *p;
    p=(int *)malloc((d+1)*sizeof(int));
    printf("enter the degree of accuracy of the answer");
    scanf("%f",&acc);
    for(i=0;i<(d+1);i++)
    {
        printf("enter the coefficients of the polynomial x power %d",(i));
        scanf("%d",&p[i]);


    }
    for(i=0;i<(d+1);i++)
    {

        pp[i]=i*p[i];
    }
printf("enter the initial value of x: x0");
scanf("%f",&x);
answerarray[0]=x;
fx=functionvalue(p,x,d);
dfx=difffunctionvalue(pp,x,d);
printf("x                  fx             dfx      \n");

printf("%f         %f            %f         \n",x,fx,dfx);
do{


c=x-(fx/dfx);
x=c;
fx=functionvalue(p,x,d);

dfx=difffunctionvalue(pp,x,d);

answerarray[itno]=x;
error=answerarray[itno]-answerarray[itno-1];
itno++;


printf("%f         %f            %f         \n",x,fx,dfx);

}
while(fabs(error)>acc);
}
