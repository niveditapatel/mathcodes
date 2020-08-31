#include<stdio.h>
#include<conio.h>
typedef struct node
{

    int power;
    int coeff;
    struct node *link;
}node1;
node1 *HEAD3=NULL;
node1 *HEAD1=NULL;
node1 *HEAD2=NULL;
node1* temp=NULL;



  node1* insert(node1 *HEAD)
{

int d,c;
    printf("enter the power\n");

                    if (HEAD==NULL)
                    {
 HEAD=(node1*)malloc(sizeof(node1));

                     scanf("%d",&d);
                     printf("enter the coeff\n");
                     scanf("%d",&c);
                     HEAD->power=d;
                     HEAD->coeff=c;
                    HEAD->link=NULL;


                    }
                    else{

                             temp=(node1*)malloc(sizeof(node1));

                    scanf("%d",&d);
                    printf("enter the coeff\n");
                     scanf("%d",&c);
                    temp->power=d;

                    temp->coeff=c;
                    temp->link=HEAD;
                    HEAD=temp;


      }
      return HEAD;
      }

      void display(node1 *HEAD)
      {
          temp=HEAD;
          while(temp->link!=NULL)
      {
          printf("coeff=%d\t",temp->coeff);
        printf("power=%d\n",temp->power);
        temp=temp->link;
 }
           printf("coeff=%d\t",temp->coeff);
        printf("power=%d\n",temp->power);

      }


          node1* polyadd(node1 *HEAD1, node1 *HEAD2, node1 *HEAD3)
{      node1 *temp1=(node1*)malloc(sizeof(node1));
node1 *temp2=(node1*)malloc(sizeof(node1));
node1 *temp3=(node1*)malloc(sizeof(node1));

    temp1=HEAD1;
    temp2=HEAD2;
    temp3=HEAD3;
while(temp1->link!=NULL && temp2->link!=NULL)
    {
printf("%d",temp1->power);
              printf("%d",temp1->coeff);
              printf("%d",temp2->power);
              printf("%d",temp2->coeff);
        if(temp1->power > temp2->power)
        {    printf("%d",temp1->power);
              printf("%d",temp1->coeff);
            temp3->power = temp1->power;
            temp3->coeff = temp1->coeff;
            temp1 = temp1->link;
            printf("%d",temp3->power);
              printf("%d",temp3->power);
        }


        else if(temp1->power < temp2->power)
        {
            temp3->power = temp2->power;
            temp3->coeff = temp2->coeff;
            temp2 = temp2->link;
        }


        else
        {
            temp3->power = temp1->power;
            temp3->coeff = temp1->coeff+temp2->coeff;
            temp1 = temp1->link;
            temp2 = temp2->link;
        }


       temp3->link = (node1 *)malloc(sizeof(node1));
       temp3 = temp3->link;
       temp3->link = NULL;
    }
return HEAD3;
}





      void main()
{   int a;
int p,c;
      do{
printf(" Actions: 1.enter node into polynomial 1 \n 2.enter node into polynomial 2 \n3.add the polynomial \n 4.display the polynomial 1 \n 5.display polynomial 2\n 6.exit\n 7.display the added polynomial\n");
       scanf("%d",&a);
    switch(a)
    {
        case 1: HEAD1=insert(HEAD1); break;
case 2: HEAD2=insert(HEAD2);
break;

            break;
            case 3: HEAD3=polyadd(HEAD1,HEAD2,HEAD3); break;
                case 4:
                display(HEAD1);
                break;
                case 5: display(HEAD2); break;
                case 7: display(HEAD3); break;
}
      }while(a!=6);
}
