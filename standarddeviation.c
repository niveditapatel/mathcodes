void main(){int n;
float xi[15];
float cf[15];
float f[15]; int i,j;
float lower[15];
float upper[15];
printf("enter the number of values to enter:\n");
                  scanf("%d",&n);

                  printf("enter the lower bound and upper bound and its frequency:\n");
                  for(i=0;i<n;i++)
                  {
                      scanf("%f %f %f",&lower[i],&upper[i],&f[i]);
                  }
                  cf[0]=f[0];
                  for(i=1;i<n;i++)
                  {
                      cf[i]=cf[i-1]+ f[i];
                  }

                  for(i=0;i<n;i++)
                  {
                      xi[i]=(lower[i]+upper[i])/2;
                  }
                  float interval=upper[0]-lower[0];

                  printf("the table formed:");
                  printf("RANGE           FREQUENCY      CF      XI\n");
                  for(i=0;i<n;i++)
                  {
                      printf("%f - %f         %f  %f  %f\n",lower[i],upper[i],f[i],cf[i],xi[i]);
                  }

                 float sum=0,ntotal=0;
                  for(i=0;i<n;i++)
                  {
                      ntotal=cf[n-1];
                      sum+=(xi[i] * f[i]);

                  } float mean;
                  printf("%f\n", sum);
                        printf("%f\n", ntotal);
                  mean=sum/ntotal;

                  printf("the mean = %f\n",mean);
                  float freq= ntotal/2; int medclasspos;
                  for(i=0;i<n;i++)
                  {
                      if(cf[i]>freq&& cf[i-1]<freq)
                      {  medclasspos=i;
                  break;}} float median;



                  median=lower[medclasspos]+(freq-cf[medclasspos-1])*interval/f[medclasspos];
                  printf("median=%f\n",median);

                 int maxf=f[0];
              int modeclasspos=0;
                      for(i=0;i<n;i++){
                  if(maxf<f[i]){
                      maxf=f[i];
                  modeclasspos=i;

                  }
                      }
                  float mode;
                  mode=lower[modeclasspos]+(f[modeclasspos]-f[modeclasspos-1])/(2*f[modeclasspos]-f[modeclasspos-1]-f[modeclasspos+1])*interval;
                  printf("mode=%f",mode);

                  float t;
                  float sd;
                   for(i=0;i<n;i++)
    {
        t+=(pow(mean-xi[i],2))*f[i];

    }
    t/=ntotal;
    printf("%f\n",t);
    sd=pow(t,0.5);
    printf("\nstandard deviation of the data is =%f",sd);


    }


