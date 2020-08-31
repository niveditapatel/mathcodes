void main()
{
float x[10];
float y[10];
float xy[10];
float x2[10];
float y2[10];
float sumx;
float sumy;
float sumxy;
float sumx2;
float sumy2;
 int n,i;
printf("enter the number of values to enter:\n");
                  scanf("%d",&n);

                  printf("enter the values of x and y:\n");
                  for(i=0;i<n;i++)
                  {
                      scanf("%f %f",&x[i],&y[i]);
                  }
 for(i=0;i<n;i++)
    {xy[i]=x[i]*y[i];
    sumx+=x[i];
    sumy+=y[i];
    sumxy+=xy[i];
    x2[i]=x[i]*x[i];
    sumx2+=x2[i];
    y2[i]=y[i]*y[i];
    sumy2+=y2[i];
    }
    printf(" the table is \n x\t               y\t            xy\t           x2\t           y2\n");

  for(i=0;i<n;i++)
  {
      printf("%f\t%f\t%f\t%f\t%f\n",x[i],y[i],xy[i],x2[i],y2[i]);
  }
  printf("\n sums:%f\t%f\t%f\t%f\t%f\n",sumx,sumy,sumxy,sumx2,sumy2);
  float r,t,s;
  t=n*sumx2-sumx*sumx;
  s=n*sumy2-sumy*sumy;

  r=(n*sumxy-sumx*sumy)/(pow(t,0.5)*pow(s,0.5));
  printf("valur of r pearsons coefficient =%f",r);}
