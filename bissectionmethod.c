#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void main()
{

    float acc,error,a,b,c,fc;
    float answerarray[100];
    answerarray[0]=0;
    float sum=0;
    int i,d;
    int itno=1;


    printf("enter the degree of the polynomial");
    scanf("%d",&d);
    int *p;
    p=(int *)malloc((d+1)*sizeof(int));
    printf("enter the degree of accuracy of the answer");
    scanf("%f",&acc);
    for(i=0;i<(d+1);i++)
    {
        printf("enter the coefficients of the polynomial x power %d",(d-i));
        scanf("%d",&p[i]);


    }
printf("enter any a so that fa<0");
scanf("%f",&a);
printf("enter any b so that fb>0");
scanf("%f",&b);
printf("a                   b              c             fc\n");
do{
c=(a+b)/2;
for(i=d;i>=0;i--)
{
    sum=sum+p[i]*pow(c,(d-i));
    }
fc=sum;
sum=0;
printf("%f         %f            %f          %f\n",a,b,c,fc);
if(fc>0)
{

    b=c;
}
else
{
    a=c;
}
answerarray[itno]=c;
error=answerarray[itno]-answerarray[itno-1];
itno++;


}
while(fabs(error)>acc);
}
