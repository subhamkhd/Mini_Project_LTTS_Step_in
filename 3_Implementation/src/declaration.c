/**
 * @file declaration.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */



struct electricity_bill
{
  char fname[30], lname[30], city[30], state[30];
  int cno;
};

struct electricity_bill b[100];


void bill_chart(int consumer){
	if(consumer== 1){
    		printf("\n\n\t\tYOU ARE WELLCOME IN ELECTRTICITY BOARD DEPPARTMENT\n.\n");

          printf("\t\tELECTRICITY BOARD RATE CHART FOR DOMESTIC USER (Rates/Unit)\n\n");

          printf("\tAn electricity board charges the following rates to domestic users to discourage large consumption of energy:\n\n");

          printf("\t0 Unit to 50 Units ..................................=Rs.4/Unit\n\n");

          printf("\t51 Unit to 100 Units .............................. =Rs.4.5/Unit\n\n");

          printf("\t101 Unit to 200 Units .............................. =Rs.5/Unit\n\n");

          printf("\t201 Unit to 300 Units .............................. =Rs.5.5/Unit\n\n");

          printf("\t301 Unit to 400 Units .............................. =Rs.6/Unit\n\n");

          printf("\t401 Unit to 500 Units .............................. =Rs.6.5/Unit\n\n");

          printf("\tand more than 500 Units .............................. =Rs.7/Unit\n\n");

	}else{
		
		printf("\t\t\t\n\nYOU ARE WELLCOME IN ELECTRTICITY BOARD DEPPARTMENT\n.\n");
	
		  printf("\t\tELECTRICITY BOARD RATE CHART FOR COMMERCIAL USER (Rates/Unit)\n\n");
		
		  printf("\tAn electricity board charges the following rates to Commercial users to discourage large consumption of energy:\n\n");
		
		  printf("\t0 Unit to 50 Units ..................................=Rs.15/Unit\n\n");
		
		  printf("\t51 Unit to 100 Units .............................. =Rs.20.5/Unit\n\n");
		
		  printf("\t101 Unit to 200 Units .............................. =Rs.26/Unit\n\n");
		
		  printf("\t201 Unit to 300 Units .............................. =Rs.36.5/Unit\n\n");
		
		  printf("\t301 Unit to 400 Units .............................. =Rs.47/Unit\n\n");
		
		  printf("\t401 Unit to 500 Units .............................. =Rs.57.5/Unit\n\n");
		
		  printf("\tand more than 500 Units .............................. =Rs.68/Unit\n\n");
      
	}
}
void new_consumer(int n)
{
  int i;
  for (i = 0; i < n; i++)
  {
    printf("\n\n----------------Consumer #%d#---------------------\n", i + 1);
    printf("Enter consumer id : ");
    scanf("%d", &b[i].cno);
    printf("Enter Consumer first name : ");
    scanf("%s", b[i].fname);
    printf("Enter Consumer last name : ");
    scanf("%s", b[i].lname);
    printf("Enter consumer city : ");
    scanf("%s", b[i].city);
    printf("Enter consumer state : ");
    scanf("%s", b[i].state);
  }
  printf("\n\nSucessfully added..");
//  printf("\nPress any key to continue...");
//  getchar();
}
void exits(){
	printf("\n\n\t\t\tPlease Register your queries/Feedback-consumerhelp@ebp.com/Reach us-1234567890 \n\t\tThank you for Visiting here... Hope You Had Good Experience.... Have a Good Day!!");
    exit(0);
}
void generate()
{
  int i;
  for (i = 0; i <= 50; i++)
    printf("_");
}
void modify_consumer(int n)
{
  int i, num, o;
  printf("\n\nEnter consumer id : ");
  scanf("%d", &num);
  for (i = 0; i < n; i++)
  {
    if (b[i].cno == num)
    {
    a:
      printf("\n\n\n\t\t1.modify address\n\t\t2.modify name\n\t\t");
      generate();
      printf("\n\n\t\tChoose your option\n\t\t");
      scanf("%d", &o);
      switch (o)
      {

      case 2:
        printf("\nCurrent Consumer name : %s %s\n", b[i].fname, b[i].lname);
        printf("Consumer first Name : ");
        scanf("%s ", b[i].fname);
        printf("Consumer last Name : ");
        scanf("%s", b[i].lname);
        printf("\nConsumer name sucessfully changed...");
        break;
      case 1:
        printf("\nCurrent Consumer address : %s , %s\n", b[i].city, b[i].state);
        printf("Enter consumer city : ");
        scanf("%s", b[i].city);
        printf("Enter consumer state : ");
        scanf("%s", b[i].state);
        printf("\nConsumer address sucessfully changed...");

        break;
      default:
        printf("Please choose a valid option\n");
        goto a;
        break;
      }
    }
    else
      printf("consumer Not Found !!\nPress any key to continue...");
    getchar();
  }
}

int calculate_bill(float units,int consumer){
	float total_bill;
	if(consumer==1){
	  	if (units <= 50) total_bill = units * 4;
		else if (units <= 100) total_bill = units * 4.5;
		else if (units <= 200) total_bill = units * 5;
		else if (units <= 300) total_bill = units * 5.5;
		else if (units <= 400) total_bill = units * 6;
		else if (units <= 500) total_bill = units * 6.5;
		else total_bill = units * 7;
	  }	else{
	  	if (units <= 50) total_bill = units * 5;
		else if (units <= 100) total_bill = units * 5.5;
		else if (units <= 200) total_bill = units * 6;
		else if (units <= 300) total_bill = units * 6.5;
		else if (units <= 400) total_bill = units * 7;
		else if (units <= 500) total_bill = units * 7.5;
		else total_bill = units * 8;
	  }
	  return total_bill;
}



void electricity_bill(int n,int consumer)
{
  int i, cro;
  char date[15];
  float units, pre_ut, total_bill,present_unit;
  static int k = 1;
  printf("\nEnter consumer id : ");
  scanf("%d", &cro);
  for (i = 0; i < n; i++)
  {
    if (cro == b[i].cno)
    {
      k = 0;
      printf("..........................LETS CALCULATE YOUR ELECTRICITY BILL...................................\n\n");
      printf("Enter Previous Unit: ");
      scanf("%f", &pre_ut);
      printf("Enter Present Unit: ");
      scanf("%f", &present_unit);
      units = present_unit - pre_ut;
      
      total_bill = calculate_bill(units,consumer);
      
      printf("\t\t*************************************************\n");
      printf("\n\t\t\t**NAME           \t\t%s %s\n\n", b[i].fname, b[i].lname);
      printf("\t\t\t**ADDRESS           \t\t%s %s\n\n", b[i].city, b[i].state);
      printf("\t\t\t**previous unit  \t\t%f\n\n", pre_ut);
      printf("\t\t\t**present unit  \t\t%f\n\n", present_unit);
      printf("\t\t\t**consumed unit \t\t%f\n\n", units);
      printf("\t\t\t**Total bill    \t\t%f(including GST)**\n\n", total_bill);
      printf("\t\t*************************************************\n");
      break;
    }
  }
  if (k == 1)
    printf("\nconsumer not found !!!......... \nPress any key to continue");
  getchar();
}