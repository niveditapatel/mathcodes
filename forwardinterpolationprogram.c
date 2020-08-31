
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
	 printf("the table is");
	  for(i=0;i<n;i++)
  {

     printf("%f",&arrx[i]);
  }
    for(j=0;j<n;j++)
	{

	    printf("%f",&arry[0][j]);
	}

	for(i=1;i<n;i++)
    {
        for(j=0;j<(n-i);j++)
		{
			arry[i][j]=arry[i-1][j+1]-arry[i-1][j];
			printf("%d\n",&arry[i][j]);
		}
	}
	printf("then the difference table is");
	for(j=0;j<(n-i);j++)
    {
	for(i=0;i<n;i++)
    {

			printf("%d\n",&arry[i][j]);
		}
		printf("\t");
	}
}

