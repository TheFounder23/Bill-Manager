Better spam filters … Now Drive automatically moves suspicious files shared with you to spam. You can still report spam on your own.Learn more
#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#include<conio.h>

#include<math.h>

int extra ;
int units, customer_number;// declaring variables required for electricity bill
float amt = 0;
char comp[500];
int CA_number ;


struct info1// a structure for storing the users information
{
    char name[20];
    int telephone_number;
    char address[100];
   
} person1;


void elec(int units, float amt)// function for electricity bill
{
    printf("-------------------------------ELECTRICITY BILL------------------------------------\n");
    printf("NAME: %s \n", person1.name);
    printf("TELEPHONE NUMBER: %d\n", person1.telephone_number);
    printf("ADDRESS : %s\n", person1.address);
    printf("CA NUMBER : %d\n", CA_number);
//conditions for calculating the electricity bill
    if (units <= 200)              
    {
        amt = amt +  0.6 * units;
    }
    else if (units <= 400)
    {
        amt =   amt + 120 + 0.65 * (units - 200);
    }
    else if (units <= 600)
    {
        amt =    amt + 210 + 0.8 * (units - 400);
    }
    else{
        amt =   amt + 400 + 0.2 * (units - 600);
        
    }
     
        getchar();
        penalty();
        amt = amt + 50*extra;
    printf("YOUR FINAL BILL IS : %6.2f and you have consumed: %d units\n", amt, units); 
    

}


int calls = 0; // declaring variables required for phone bill
char choice;
float bill = 0;  
char c;
int s;


struct info // a structure for storing the users information
{
    char name[20];
    int phone_number;
} person;



void phone(int calls, float bill) //function for phone
{
    printf("---------------------------------------PHONE BILL-----------------------------\n"); // user has chosen phone bill
    printf("YOUR SERVICE PROVIDER IS AT TEL\n");
    printf("NAME: %s\n", person.name); // printing user information
    printf("YOUR PHONE NUMBER: %d\n", person.phone_number);
    // conditions for calculating phone bill 
    if (calls >= 0 && calls < 100) 
    {
        bill = bill + 150;
    }

    else if (calls < 0)
    {
        printf("YOU HAVE ENTERED AN INVALID NUMBER ");
        
    }
    else if (calls > 100 && calls <= 150)
    {
        calls = calls - 100;
        bill = bill + 150 + 0.7 * calls;
    }
    else if (calls > 150 && calls < 200)
    {
        calls = calls - 150;
        bill = bill + 150 + 0.6 * calls;
    }

    else
    {
        calls = calls - 200;
        bill = bill + 200 + 0.7 * 50 + 0.6 * 50 + 0.5 * calls;

    }
    getchar();
        penalty();
        bill =  bill + 10*extra;
   
    printf("YOU HAVE TO PAY  : %6.2f \n", bill); // final bill
    
}   
   
   
    void help1()//query desk for PHONE bill users
    
    {
        printf("PRESS 'Y' IF YOU NEED HELP, PRESS 'N' IF YOU DON'T \n");
        getchar();
        c = getchar();
        switch (c)
        {
        case 'Y':
        case 'y':
            printf("PLEASE CHOOSE ANY ONE OUT OF THE FOLLOWING\n ");
            printf("---------------------------------QUERY----------------------------------\n");
            printf("1) What is my current account balance/validity? \n 2) What are the available packs?\n 3) Recharge done, but not refelcting \n 4) Some other issue\n");
            scanf("%d", &s);
            switch (s)
            
            {
            case 1:
                printf("As per our records your data balance is 2gb and your main balance is 500\n ");
                break;
            case 2:
                printf("1) 1.5gb/day for 84 days @ 598 , 2) 1.5gb/day for 56 days @ 399, 3) 1.5gb/day for 28days @ 249\n");
                break;
            case 3:
                printf("Wait for sometime, if still not refelcting contact us at toll free 4243xyz\n");
                break;
            case 4:
                printf("Please reach us at our customer care number 4243xyz\n");
                break;
            default:
                printf("THANK YOU FOR YOUR TIME\n");
                break;
            }
            
        case 'N':
        case 'n':
            printf("THANK YOU FOR YOUR TIME\n");
            break;
            
           default:
           printf("WRONG CHOICE ENTERED");
           
        }
    }
  
  
  
  void help()// query desk for ELECTRICITY bill users
  {
     printf("PRESS 'Y' IF YOU NEED HELP, PRESS 'N' IF YOU DON'T \n");
        char l;
       
        l = getchar();
        switch(l)
        {
            case 'Y':
            case 'y':
            printf("PLEASE CHOOSE ANY ONE OUT OF THE FOLLOWING\n ");
            printf("---------------------------OPTIONS---------------------------------\n");
            printf("1)What is the frequency of billing of a customer  monthly / bi - monthly?\n  2)What should I do if I have a billing complaint?\n  3)How to apply for New Connection?\n  4)Any other complaint please mention: %s \n  ", comp);
            int choice1;
            scanf("%d", &choice1);
            switch(choice1)
            {
                case 1:
                printf("Its is monthly\n");
                break;
                case 2: 
                printf("You can reach our website : www.billme.com \n Our mobile app : Bill me mobile app \n");
                break;
                case 3: 
                printf("For new Connection of 1 KW to 44 KW: Call at our helpline number 093842 or apply online at www.billme.com \n");
                break;
                case 4:
                getchar();
                gets(comp);
                printf("ANY OTHER PROBLEM : %s\n", comp);
                printf("WE HAVE REGISTERED YOUR COMPLAINT OUR TEAM WILL RESOLVE IT WITHIIN 48 HOURS\n ");
                break;
                
                default :
                
                printf("WRONG CODE ENTERED \n");
                
            }
            break;
            
            case 'n':
            case 'N':
            printf("Thank you for your time\n");
            break;
            
            default:
            printf("WRONG CHOICE ENTERED\n");
        }
         
    }
    
 
 
 void tme()// a function displaying current date and time in UTC
 {
   time_t nowtime;
   struct tm *now;
   time( &nowtime );
   now = localtime(&nowtime);
   printf("-------------------------------------------Current local time(UTC) and date: %s\t", asctime(now));
   
} 



int penalty()// penalty calculator for late payment and number of day calculator
{
int day1,mth1,yr1,day2,mth2,yr2,ref_date,d1,d2,i,due;
printf("Enter todays date, month, year\n");
scanf("%d%d%d",&day1,&mth1,&yr1);
printf("Enter due date \n");
scanf("%d%d%d",&day2,&mth2,&yr2);
ref_date = yr1;

if(yr2<yr1)

ref_date = yr2;
d1=0;
d1=  func1( mth1);
for(i=ref_date;i<yr1;i++)
{
	if(i%4==0)
	d1+=1;
}
d1=d1+day1+(yr1-ref_date)*365;
d2 = 0;

for(i=ref_date;i<yr2;i++)
{
	if(i%4==0)
	d2+=1;
}
d2 = func1(mth2)+d2+day2+((yr2-ref_date)*365);
if ((d2 - d1) >= 0)
{
    printf("YOU DONT HAVE TO PAY ANY FINE  \n");
    return (0);
}
else{
extra = abs(d2-d1);
getch();
printf("YOU ARE LATE FOR BILL PAYMENT BY : %d days , YOU ARE LIABLE TO PAY FINE\n", extra);
return(extra);
}

}


int func1(int l)// for number of days calculation       
{  int m=0;
switch(l)
{
case 1:

m=0;

break;

case 2:

m=31; 

break;

case 3:

m=59;

break;

case 4: 

m=90;

break;

case 5:

m=120;

break;

case 6:

m=151;

break;

case 7:

m=181; 

break;

case 8:

m=212;

break;

case 9:

m=243;

break;

case 10:

m=273;

break;

case 11:

m=304;

break;

case 12:

m=334;

break;

default: printf("Error ");
exit(0);

}

return(m);
}




int main()
{

    printf("------------------------------------ WELCOME TO BILL CALCULATING SYSTEM-------------------------------------\n");
    
    
    printf("------------------------------------CHOOSE THE BILL YOU WANT TO CALCULATE--------------------------------------\t\t\n");
    
    printf(" A: PHONE BILL    B: ELECTRICITY BILL\n"); // asking user to select his choice
     
    
    scanf("%c", &choice);
    
    
    getchar();
    if(choice != 'a' && choice != 'A'  && choice != 'b' && choice != 'B')
    { 
        printf("WRONG CODE ENTERED PLEASE TRY AGAIN \n");
        scanf("%c", &choice);
        switch (choice)
    {
        
      case 'A':
      case 'a':
        
        printf("Enter your first  name : \n"); // asking user information
        scanf("%s",person.name);
        printf("Enter your phone number: \n");
        scanf("%d", &person.phone_number);

        printf("PLEASE ENTER THE NUMBER OF CALLS YOU HAVE MADE THIS MONTH\n\n");
        scanf("%d", &calls);
        
        tme();
        
        phone(calls, bill);
        
        help1();
         
        break;    

        
      case 'B':
      case 'b':
        printf("PLEASE ENTER YOUR NAME:\n");
        scanf("%s", person1.name);
        printf("PLEASE ENTER YOUR PHONE TELEPHONE NUMBER\n");
        scanf("%d", &person1.telephone_number);
        printf("PLEASE ENTER YOUR ADDRESS\n");
        getchar();
        gets(person1.address);
        printf("PLEASE ENTER YOUR 9 DIGIT CA NUMBER: %d\n", CA_number);
        scanf("%d", &CA_number);
        printf("PLEASE ENTER THE UNIT CONSUMED\n");
        scanf("%d", &units);
       
        
        tme();
       
        elec(units, amt);
        printf("POWER FACTOR IS : 1\n");
        getchar();
        help();
        
        break;
        
        
       
    }
    
        
    }
        
     switch (choice)
    {
        
      case 'A':
      case 'a':
        
        printf("Enter your name : \n"); // asking user information
        scanf("%s", person.name);
        printf("Enter your phone number: \n");
        scanf("%d", &person.phone_number);

        printf("PLEASE ENTER THE NUMBER OF CALLS YOU HAVE MADE THIS MONTH:\n");
        scanf("%d", &calls);
        
        tme();
        
        phone(calls, bill);
        
        help1();
         
        break;    

        
      case 'B':
      case 'b':
        printf("PLEASE ENTER YOUR NAME:\n");
        scanf("%s", person1.name);
        printf("PLEASE ENTER YOUR PHONE TELEPHONE NUMBER\n");
        scanf("%d", &person1.telephone_number);
        printf("PLEASE ENTER YOUR ADDRESS\n");
        getchar();
        gets(person1.address);
        printf("PLEASE ENTER YOUR CA NUMBER:", CA_number);
        scanf("%d", &CA_number);
        printf("PLEASE ENTER THE UNIT CONSUMED\n");
        scanf("%d", &units);
       
        
        tme();
       
        elec(units, amt);
        printf("POWER FACTOR IS : 1\n");
        getchar();
        help();
        
        break;
        
        
       
    }
    
}
