#include<stdio.h>
#include<conio.h>
void main()
{
    int n,i,j;
    float arrx[10];
    float arry[10][10];
    printf("Enter the number of observations");
    scanf("%d",&n);

  for(i=0;i<n;i++)
  {
      printf("Enter the observation value at %d",(i+1));
     scanf("%f",&arrx[i]);
  }
    for(j=0;j<n;j++)
	{
	    printf("Enter the observation value of y at %d",(j+1));
	    scanf("%f",&arry[0][j]);
	}

	  

	for(i=1;i<n;i++)
    {
        for(j=0;j<(n-i);j++)
		{
			arry[i][j]=arry[i-1][j+1]-arry[i-1][j];
		
		}
	}
	printf("then the difference table is\n");
	
    for(j=0;j<n;j++)
    {
        	printf("%f",arrx[j]); printf("\t");
	for(i=0;i<(n-j);i++){
    printf("%f\t",arry[i][j]);
	}
	printf("\n");
	}
	float x;
    printf("enter the x for which you want to find f(x)");
    scanf("%f",&x);
    float fx;
    float h=arrx[1]-arrx[0];
    float p=(x-arrx[0])/h;
    printf("p=%f",p);
    fx=arry[0][0]+p*arry[1][0]+(p*(p-1)/2*arry[2][0])+(p*(p-1)*(p-2)/6*arry[3][0]);
    if(n>4)
    fx+=(p*(p-1)*(p-2)*(p-3)/24*arry[4][0]);
    if(n>5)
    fx+=(p*(p-1)*(p-2)*(p-3)*(p-4)/120*arry[5][0]);
printf("\nso fx=%f",fx);
	
}