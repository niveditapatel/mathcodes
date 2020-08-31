#include<stdio.h>
#include<math.h>
void main()
{
float x[10];
float y[10];
float tempx[10];
float tempy[10]; float d[10];
float temp; int i,p;
int n;
printf("enter the number of values to enter:\n");
                  scanf("%d",&n);

                  printf("enter the values of x and y:\n");
                  for(i=0;i<n;i++)
                  {
                      scanf("%f %f",&x[i],&y[i]);
                      tempx[i]=x[i];
                      tempy[i]=y[i];
                  }
                   for(i=0;i<n-1;i++)
   {
       for(p=0;p<(n-i-1);p++)
       {
           if(tempx[p]<tempx[p+1])
           {temp=tempx[p];
           tempx[p]=tempx[p+1];
           tempx[p+1]=temp;
       }}}

 for(i=0;i<n-1;i++)
   {
       for(p=0;p<(n-i-1);p++)
       {
           if(tempy[p]<tempy[p+1])
           {temp=tempy[p];
           tempy[p]=tempy[p+1];
           tempy[p+1]=temp;
       }}
   }
       int rx[10];
       int ry[10];
       for(i=0;i<n;i++)
                  {
                      for(p=0;p<n;p++)
       {
 if(x[i]==tempx[p])
    rx[i]=p+1;
       }}
       for(i=0;i<n;i++)
                  {
                      for(p=0;p<n;p++)
       {
 if(y[i]==tempy[p])
    ry[i]=p+1;
       }}
       printf("\n the table is\n");
        printf("no \t   rankx \t   x   \t ranky   \t   y   \t difference d2\n");
      for(i=0;i<n;i++){
        d[i]=pow((rx[i]-ry[i]),2);
        printf(" %d\t %d\t %f\t %d\t %f\t %f\n",(i+1),rx[i],x[i],ry[i],y[i],d[i]);

     }
     float sumd;
      for(i=0;i<n;i++){
        sumd+=d[i];
      }
      printf("sum of differences=%f\n",sumd);
     float r=1-(6*sumd/(n*(pow(n,2)-1)));


    printf("spearmans coeff r=%f",r);
}
