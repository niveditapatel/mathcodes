#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int d,n;
float **p;
float acc;
int flag;
float var[100][100];
float answerarray[100][100];
float error[100][100];
int accuracy(int in)
{
    int i;

        for(i=0;i<d;i++)
        {

            if(fabs(error[i][in])<acc)
          {      continue;
                printf("continuing");
        }
            else
           {
                return 0;
           }

    }
    return 1;
}
void solve()
{
    int i,j;
int in=1;
do{ printf("%d",in);
    for(i=0;i<d;i++)

    { var[i][in]=0;
    if(i!=0)
    { for(j=0;j<i;j++)
        {

           var[i][in]-=p[i][j]*var[j][(in)];

        }
    }

       for(j=(i+1);j<d;j++)
        {
           var[i][in]-=p[i][j]*var[j][(in-1)];

        }
        j=d;
        var[i][in]-=p[i][j];

           var[i][in]/=p[i][i];
            printf(" %f \t",var[i][in]);
   answerarray[i][in]=var[i][in];

error[i][in]=answerarray[i][in]-answerarray[i][in-1];
}
flag=accuracy(in);
in++;
printf("\n");
}while(flag==0);
}
void main()
{ int i,j;

     printf("Enter the number of equations");
 scanf("%d",&n);
 printf("Enter the number of variables");
 scanf("%d",&d);
 printf("enter the degree of accuracy of the answer");
    scanf("%f",&acc);

printf("\n");
 p=(float**)malloc(n*sizeof(float));
 for(i=0;i<n;i++)
 {

     *(p+i)=(float*)malloc((d+1)*sizeof(float));
 }



 for(i=0;i<n;i++)
 {

   for(j=0;j<(d+1);j++)
{

 printf("Enter the coefficient at position %d %d in the equation form",i,j);


 scanf("%f",&p[i][j]);

}
}
printf("The matrix is \n");
for(i=0;i<n;i++)
 {

   for(j=0;j<d;j++)
{
    printf("%f \t",p[i][j]);
}
j=d;
 printf("%f \t",-p[i][j]);
 printf("\n");
}
float sum;

for(i=0;i<n;i++)
 {
     sum=0;

   for(j=0;j<d;j++)
{
    if(j!=i)
        sum=sum+p[i][j];

}
 if(p[i][i]>sum)
    continue;
 else {printf("matrix is not diagonally dominant hence this method cannot be used.");
 return;
 printf("\n");
}
 }
 for(i=0;i<d;i++)
 {

     printf("x%d th var\t",i);

 }
  printf("\n");
  printf("0  ");
 for(i=0;i<d;i++)
 {
     var[i][0]=0;
     answerarray[i][0]=0;
     error[i][0]=0;
     printf("%f\t",var[i][0]);

 }
 printf("\n");
solve();
}
