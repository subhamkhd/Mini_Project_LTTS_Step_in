#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "function.h"



int main()
{
  int ch, n, op, c, d, type,flag = 0,consumer=0 ,i;
  char adn[20], mbn[20];
  char str1[10] = {"LTTS"}, str2[10]; //password
  printf("\n\t\tFOR SAFE LOGIN...\n");
  printf("\n\tENTER YOUR PASSWORD:");
b:
  gets(str2);
  if (strcmp(str1, str2) == 0)
  {
    printf("\n\t\t*********************************** WELCOME TO ELECTRICITY BILL PAYMENT  (One  Touch Solution) ******************************************\n");
    k:
	printf("\n\t\tARE YOU A ?!:\n\n\n\t\t1. Domestic Consumer\n\n\t\t2. Commercial Consumer\n\n\t\t3. HELP DESK\n\n\t\t");
	printf("\n\t\tChoose:\t");
    scanf("%d", &type);
    switch(type){
    	case 1: consumer =1 ;
    			break;
    	case 2: consumer =2;
				break;		
		case 3: 
			exits();		
		default : 
			printf("\n\n\t\t Incorrect ! Try Again!...");
			goto k;
			break;			
	}
    
    printf("\t\t\tWELCOME TO THE PORTAL KINDLY ENTER YOUR CREDENTIALS FOR FURTHER PROCEED:\n\n\t\t\t1.Consumer number\n\t\t\t2.Registerd phone number \n\t\t\t3.exit\n\n\n ");
  c:
    printf("SELECT: ");
    {
      scanf("%d", &op);
      switch (op)
      {

      case 1:
        printf("\nEnter 12 DIGIT consumer number: ");
      d:
        scanf("%s", &adn);
        c = strlen(adn);
        if (c == 12)

        {
          for (i = 0; i < c; i++)
          {
            if ((adn[i] >= '0') && (adn[i] <= '9'))
            {
              flag = 1;
            }
            else
            {
              flag = -1;
              break;
            }
          }
        }

        if (flag == -1)
        {
          printf("\nIncorrect CONSUMER no.\n");
          printf("\nEnter once again your CONSUMER no.\n");
          goto d;
        }
        else if (flag == 1)
        {
          printf("\n\nyou are successfully logged in...\n\n\n");
          goto a;
        }
        else
        {
          printf("\nIncorrect CONSUMER no.\n");
          printf("\nEnter once again your CONSUMER no.\n");
          goto d;
        }

        break;
      case 2:
      {
        printf("\nEnter consumer registered phone number: ");
        scanf("%s", &mbn);
        d = strlen(mbn);
        if (d == 10)

        {
          for (i = 0; i < d; i++)
          {
            if ((mbn[i] >= '0') && (mbn[i] <= '9'))
            {
              flag = 1;
            }
            else
            {
              flag = -1;
              break;
            }
          }
        }

        if (flag == -1)
        {
          printf("\nIncorrect registered phone no.\n");
          printf("\nEnter once again registered phone no.\n");
          goto d;
        }
        else if (flag == 1)
        {
          printf("\n\nyou are successfully logged in...\n\n\n");
          goto a;
        }
        else
        {
          printf("\nIncorrect registered phone no.\n");
          printf("\nEnter once again registered phone no.\n");
          goto d;
        }
        break;
      case 3:
        exits();
      default:
        printf("please choose appropriate option\n");
        goto c;
        break;
      }
      a:
        printf("\n\n\n\t\t1.Add Consumer details\n\t\t2.Modify consumer deatails\n\t\t3.calculate consumer bill\n\t\t4.Show electricity bill rate chart\n\t\t5.Exit\n\t\t");
        generate();
        printf("\n\n\t\tChoose your option\n\t\t");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
          printf("\n\t\t***** Adding New Consumer *****\n");
          generate();
          printf("\n\nEnter no. of consumers to add\n");
          scanf("%d", &n);
          new_consumer(n);
          goto a;
          break;
        case 2:
          printf("\n\t\t ** modifying Consumer Details... ** \n");
          generate();
          modify_consumer(n);
          goto a;
          break;
        case 3:
          printf("\n\t\t* calculate consumer bill*\n");
          generate();
          electricity_bill(n,consumer);
          goto a;
          break;
        case 4:
        	bill_chart(consumer);
          generate();
          goto a;
          break;
        case 5:
        	exits();
        default:
          printf("Please choose a valid option\n");
          goto a;
        }
      }
    }
  }
  else
  {
    printf("incorrect password\nENTER ONCE AGAIN:");
    goto b;
  }
}

void bill_chart(consumer);
void new_consumer(n);
void exits();
void generate();
void modify_consumer(n);
int calculate_bill( units, consumer);
void electricity_bill(n, consumer);



