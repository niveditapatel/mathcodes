#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int d, n;
float **p;
float max[100];
int position[100];
void
multiplyadd (int r)
{
  int i, j, m, s;
  float factor;

  for (i = (r + 1); i < n; i++)
    {
      factor = -(p[i][r] / p[r][r]);
      for (j = 0; j < (d + 1); j++)
	{
	  p[i][j] = factor * p[r][j] + p[i][j];


	}

      printf("the new matrix after multiplying row %d by %f and adding to row %d \n",
	 r, factor, i);
      for (m = 0; m < n; m++)
	{

	  for (s = 0; s < (d + 1); s++)
	    {
	      printf ("%f\t", p[m][s]);
	    }
	  printf ("\n");
	}
    

}
}

void
pivot (int j)
{
  int i;
  max[j] = 0;
  for (i = 0; i < n; i++)

    {

      if (p[i][j] > max[j])
	{
	  max[j] = p[i][j];
	  position[j] = i;
	}

    }
  printf ("the max element in column %d is %f at row %d \n", j, max[j],
	  position[j]);
}

void
swap (int r1, int r2)
{
  int j, i;
  float temp;
  for (j = 0; j < (d + 1); j++)

    {

      temp = p[r1][j];
      p[r1][j] = p[r2][j];
      p[r2][j] = temp;
    }

  printf ("The matrix is now after swapping rows %d %d \n", r1, r2);
  for (i = 0; i < n; i++)
    {

      for (j = 0; j < (d + 1); j++)
	{
	  printf ("%f\t", p[i][j]);
	}
      printf ("\n");
    }
}

void
main ()
{
  int i, j;
  printf ("Enter the number of equations");
  scanf ("%d", &n);
  printf ("Enter the no of variable in the equation");
  scanf ("%d", &d);

  p = (float **) malloc (n * sizeof (float));
  for (i = 0; i < d; i++)
    {

      *(p + i) = (float *) malloc ((d + 1) * sizeof (float));
    }



  for (i = 0; i < n; i++)
    {

      for (j = 0; j < (d + 1); j++)
	{
	  float g;
	  printf ("Enter the coefficient at position %d %d in the equation",
		  i, j);
	  scanf ("%f", &g);
	  if (j != d)
	    p[i][j] = g;
	  else
	    p[i][j] = (-g);

	}
    }
  printf ("The matrix is \n");
  for (i = 0; i < n; i++)
    {

      for (j = 0; j < (d + 1); j++)
	{
	  printf ("%f\t", p[i][j]);
	}
      printf ("\n");
    }
  pivot (0);
  swap (0, position[0]);
  for (i = 0; i < d; i++)
    multiplyadd (i);
    float var[100];
    for(i=(n-1);i>=0;i--){
        if(i==(n-1))
        var[i]=p[i][d]/p[i][i];
        else{
        var[i]=p[i][d];
           
    for(j=(d-1);j>i;j--){
        int m;
    
    
      
           
           
          
       var[i]-=var[j]*p[i][j];
          
       
       
    }
  var[i]/=p[i][i];
        }
  
}
    
  for (i = 0; i < n; i++)
    printf ("answer of variable %d is %f \n", i, var[i]);
}
