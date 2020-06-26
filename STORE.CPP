/*
=============================================================================
This program is done as the Project Work of Class XII Practical Examinations.
It deals with the management of an Online Shopping Store.Other details are :


  Name of Project               : iStore
  Name of Object File           : Store.cpp
  Done by                       : Jerin Mathew Vithayathil
  Started on                    : 11th June 2015
  Completion Due Date           : November 2015
  Lines Coded till Last Update  : 1651
  Last Updated On               : 17th November 2015
  Last Backed Up On             : 1st November 2015


All Functions and Class Definitions are named with a comment whose definitions
are given in the file "Logs" in the Root Folder.

=============================================================================
*/


#include<fstream.h>
#include<iostream.h>
#include<conio.h>
#include<ctype.h>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dos.h>
#include<iomanip.h>
#include<graphics.h>                     //Header Files.




void graphicscreen(char*,int,int);
char* showfile2(char[]);
void dealerpage();
void customerpage();
					 //To Blink Text.
void blink(char *str)
 { textattr(7 + ((7+1) << 4));
   cprintf(str);
   textattr(0+((0+14) << 0));
 }

void start(int);

class error                                    //Class to handle Errors.
 {public:
   void oops();
 };

void error::oops()
 { clrscr();
      cout<<showfile2("oops");
      int choice1;
      cin>>choice1;
      switch(choice1)
       { case 1: start(100); break;
	 case 2: exit(0);
	 default : return;
       }
      getch();
  }




class dealeraccount                           //Class for Dealer Account.
 {
   public :  char name[80];
	     char company[80];
	     char username[80];
	     char password[80];
	     char emailid[80];
	     char number[40];
	     int pin;
	     int balance;
	     int transstatus;
 };


class customeraccount                        //Class for Customer Account.
 {
   public :  char name[80];
	     char emailid[80];
	     char address[80];
	     char username[80];
	     char password[80];
	     char number[40];
	     int pin;
	     int balance;
 };


class status                                 //Class for Current User.
 { public : int dealercount;
	    int customercount;
	    int transact;
	    int itemcount;
	    status()
	     { transact=0;
	       itemcount=0;
	       dealercount=0;
	       customercount=0;
	     }
 };

class userstatus                             //Class for Counters.
 { public :
    int stat;
    customeraccount c1;
    dealeraccount d1;

 };


error e;
status s;
userstatus u;
void showwelcome(int);
void signup();
void signin();
void contact();
void showstatus();
void rank();
void statusupdate();

void start(int time)                       //Program Starts Here.
 { showwelcome(time);
   int choice;
   cin>>choice;
   switch(choice)
    { case 1: signup();break	;
      case 2: signin();break;
      case 3: contact();break;
      case 4: showstatus();break;
      case 6: //rank();
	      break;
      case 5: exit(0);
      default: e.oops();
    }
   return;
 }


char* showfile2(char d[25])                //Shows File Content.
 {
  ifstream f2(d,ios::in);
  char e[1000];
  f2.seekg(0);
  f2.get(e,1000);

  for(int i=0;i<1000;i++)
    { if(e[i]==']')
       e[i]='\n';
      else
       { if(e[i]=='[')
	  { e[i]='\t';
	  }
       }
    }
   f2.close();
   e[i]='\0';
   return e;
 }


void getpass(char *s)                      //Display '*' for Input.
 { for(int i=0;;i++)
    { s[i]=getch();
      if(s[i]==13)
       {s[i]='\0';
	break;
       }
      cout<<"*";
    }
 }

int global=0;

void showwelcome(int time)                 //Intro Graphics.
 { clrscr();
   char v[]="iStore.";
   if(global==0)
   graphicscreen(v,7,time);
   if(global>=10)
    { clrscr();
      cout<<"\n WARNING ! ";
      cout<<"\n===========";
      cout<<"\n\n The maximum supported concurrant sessions are now over. \n";
      cout<<" You are advised to start a new session by restarting the program or else\n";
      cout<<" it will result in an memory overflow and data may be lost.\n\n";
      cout<<" Press 1 to exit to Windows and restart iStore and 2 to ignore and Continue : ";
      int choice;
      cin>>choice;
      switch(choice)
      {case 1:exit(0);
       case 2:showwelcome(1000);return;
       default:showwelcome(1000);return;
      }
    }
   textcolor(YELLOW);
   char st[]=" WELCOME TO   iStore.  ";
   cout<<"\n\n";
   blink(st);
   cout<<showfile2("WELCOME2");
   global++;

 }


void dealerssignup()                       //Dealer Sign Up.
 { clrscr();
   dealeraccount d,d1;
   cout<<showfile2("DEALERSSIGNUP");
   cout<<"\n Your name          :    ";
   gets(d.name);
   cout<<"\n Your Company Name  :    ";
   gets(d.company);
   cout<<"\n Your Email id      :    ";
   gets(d.emailid);
   cout<<"\n Credit Card number :    ";
   gets(d.number);
   cout<<"\n Card PIN           :    ";
   cin>>d.pin;
   cout<<"\n Your New Username  :    ";
   gets(d.username);
   cout<<"\n Enter a Password   :    ";
   getpass(d.password);
   d.balance=0;
   d.transstatus=0;
   cout<<"\n Re-enter Password  :    ";
   char passchk[30];
   getpass(passchk);
   if(strcmp(passchk,d.password)!=0)
    {cout<<"\n\n Passwords do not match !! Press ENTER to try again.. ";
     getch();
     dealerssignup();
     return;
    }
   ifstream f3("D.DAT",ios::binary|ios::in);
   while(f3.read((char*)&d1,sizeof(d1)))
    {
      if(strcmp(d1.username,d.username)==0 )
       { if(strcmp(d1.password,d.password)==0)
	  { cout<<"\n\n\n USERNAME and PASSWORD already exists. Access Denied !\n Press ENTER to return to Homepage ";
	    getch();
	    start(100);
	    return;
	  }
       }
    }
   cout<<"\n\n Proceed with account creation ? (Y||N) :  ";
   char cont2;
   cin>>cont2;
   if(tolower(cont2)=='n')
    { start(100);
      return;
    }
   else
    { s.dealercount++;
    }

   ofstream f1("D.DAT",ios::binary|ios::app|ios::out);
   f1.write((char*)&d,sizeof(d));
   f1.close();
   cout<<"\n\n\n Account Creation SUCCESSFULL. You can now sign in from the Home Page. ";
   cout<<"\n\n Press ENTER to go to HomePage. ";
   getch();
   start(500);
 }



void customersignup()                      //Customer Sign Up.
 { clrscr();
   customeraccount c,c1;

   cout<<showfile2("CUSTOMERSIGNUP");
   cout<<"\n Your name               :    ";
   gets(c.name);
   cout<<"\n Your Email id           :    ";
   gets(c.emailid);
   cout<<"\n Your Shipping Address   :    ";
   gets(c.address);
   cout<<"\n Credit Card number      :    ";
   gets(c.number);
   cout<<"\n Card PIN                :    ";
   cin>>c.pin;
   c.balance=0;
   cout<<"\n Your New Username       :    ";
   gets(c.username);
   cout<<"\n Enter a Password        :    ";
   getpass((c.password));
   cout<<"\n Re-enter Password       :    ";
   char passchk[30];
   getpass(passchk);
   if(strcmp(passchk,c.password)!=0)
    {cout<<"\n\n Passwords do not match !! Press Enter to try again. ";
     getch();
     customersignup();
     return;
    }
   ifstream f4("C.DAT",ios::binary|ios::in);
   while(f4)
    { f4.read((char*)&c1,sizeof(c1));
      if(strcmp(c1.username,c.username)==0 )
       { if(strcmp(c1.password,c.password)==0)
	  { cout<<"\n\n Username and Password already exists. \n\n ACCESS DENIED !\n Press ENTER to return to Homepage ";
	    getch();
	    e.oops();
	    return;
	  }
       }
    }
   cout<<"\n\n Proceed with account creation ? (Y||N) :  ";
   char cont2;
   cin>>cont2;
   if(tolower(cont2)=='n')
    { cout<<"\n\n ABORT Request Accepted . Press ENTER key to go to HomePage. ";
      start(100);
      return;
    }
   else
    { s.customercount++;
    }

   ofstream f1("C.DAT",ios::binary|ios::out);
   f1.write((char*)&c,sizeof(c));
   f1.close();
   cout<<"\n\n Account Creation Successful. You can now sign in from the Home Page. ";
   cout<<"\n\n Press ENTER to go to HomePage. ";
   getch();
   start(500);
   return;
 }


 void signup()                             //Sign Up.
 { clrscr();
   cout<<showfile2("SIGNUP");
   int choice;
   cin>>choice;
   switch(choice)
    { case 2: dealerssignup(); break;
      case 1: customersignup();break;
      default : e.oops();
    }


 }

void dealersignin()                          //Dealer Sig  In.
 { clrscr();
   dealeraccount check;
   cout<<showfile2("DEALERIN");
   char userid[80],pass[80];
   cout<<" Enter Username     :   ";
   gets(userid);
   cout<<"\n Enter Password     :   ";
   getpass(pass);int a=0;
   int flag=0 ;
   ifstream f1("D.DAT",ios::binary|ios::in);
   while(f1.read((char*)&check,sizeof(check)))
    {
      if(strcmp(userid,check.username)==0 )
       { if(strcmp(pass,check.password)==0)
	  { u.stat=1;
	    u.d1=check;
	    dealerpage();
	    return;
	  }
	 else
	  { cout<<"\n\n Your Password doesn't match . Access denied ! ";
	    cout<<"Press ENTER to try again. "; 																																													    cout<<"\n Press ENTER to return to home page.. ";
	    getch();
	    dealersignin();
	    return;
	  }
       }
      else
       { flag++;
       }
       ++a;
    }
    if(flag==a)
     { cout<<"\n\n\n You are not a registered dealer. Please sign up for an account in the\n Homepage. ";
	 cout<<"\n If you are a user already, please check your Username and try again. ";
	 cout<<"\n Press ENTER to return to HomePage. ";
	 getch();
	 start(100);
	 return;
     }
  return;


 }

void customerpage();

void customersignin()                        //Customer Sign In.
 { clrscr();
   customeraccount check;
   cout<<showfile2("incust");
   char userid[80],pass[80];
   cout<<" Enter Username     :   ";
   gets(userid);
   cout<<"\n Enter Password     :   ";
   getpass(pass);
   int a=0,flag=0;
   ifstream f1("C.DAT",ios::binary|ios::in);
   while(f1)
    { f1.read((char*)&check,sizeof(check));
      if(strcmp(userid,check.username)==0 )
       { if(strcmp(pass,check.password)==0)
	  { u.stat=1;
	    u.c1=check;
	    customerpage();
	    return;
	  }
	 else
	  { cout<<"\n\n\n Your Password doesn't match . Access denied ! ";
	    cout<<"\n\n Press ENTER to return to HomePage.. ";
	    getch();
	    start(100);
	    return;
	  }
       }
      else
       { flag++;
       }
      a++;
    }
    if(flag==a)
     { cout<<"\n\n\n You are not a registered Customer. Please sign up for an account in the\n Homepage. ";
	 cout<<"\n If you are a user already, please check your Username and try again. ";
	 cout<<"\n\n Press ENTER to return to HomePage. ";
	 getch();
	 start(100);
	 return;
     }
  return;


 }





void signin()                                //Sign In.
 { clrscr();
   cout<<showfile2("SIGNIN");
   int choice;
   cin>>choice;
   switch(choice)
    { case 1 : dealersignin();break;
      case 2 : customersignin();break;
      default : e.oops();
    }


 }


void contact()                                  //Contact Us.
 { clrscr();
   cout<<showfile2("CONTACT");
   cout<<" \n\n Press ENTER key to go to Homepage.  ";
   getch();
   start(100);
   return;
 }



 class item                                        //Class for each Item.
 { public:
    char itemname[80];
    char category[80];
    int price;
    char itemcode[50];
    char company[80];
    char about[160];
    int quantity;
    dealeraccount d2;
    void displaydata();

    void inputdata();
 };

void item::inputdata()
  { clrscr();
       cout<<"\n ADD A NEW ITEM.  ";
       for(int o=0;o<80;o++)
	cout<<"=";
       cout<<"\n\n\n Input all the details of the product that you wish to sell..";
       cout<<"\n\n  Item Name      : ";
       gets(itemname);
       cout<<"\n  Category       : ";
       gets(category);
       cout<<"\n  Price          : $ ";
       cin>>price;
       cout<<"\n  Item Code      : ";
       cin>>itemcode;
       cout<<"\n  Quantity       : ";
       cin>>quantity;
       cout<<"\n  Remarks        : ";
       gets(about);

       if(u.stat==1)
	{ strcpy(company,u.d1.company);
	  d2=u.d1;
	   cout<<"\n\n\n Thank You . Your item '"<<itemname<<"' has been entered into the database successfully. ";

       getch();
	}
       else {cout<<" \n\n SIGN IN UNDETECTED !! : ACCESS DENIED ! ";
       getch();
       e.oops();
       return;
     }

  }
 void item::displaydata()
 { clrscr();
       cout<<"\n\n PRODUCT DETAILS . ";
       cout<<"\n===================\n";
       cout<<"  \n\n  Name       : "<<itemname;
       cout<<"  \n\n  Category   : "<<category;
       cout<<"  \n\n  Item Code  : "<<itemcode;
       cout<<"  \n\n  Company    : "<<company;
       cout<<"  \n\n  Remarks    : "<<about;
       cout<<"\n\n\n  PRICE      : $ "<<price;
       getch();
  }


void statusupdate()                          //F7
 { fstream f3("STATUS.DAT",ios::binary);
   status s2;
   int m=0;
   item i4;
   ifstream f5("ITEM.DAT",ios::binary|ios::in);
    while(f5.read((char*)&i4,sizeof(i4)))
       {
	 m++;
       }
   while(f3.read((char*)&s2,sizeof(s2)))
    {

	s.dealercount+=s2.dealercount;
	s.customercount+=s2.customercount;
	s.transact+=s2.transact;
	s.itemcount=m;   //Add these lines of code only after completion.
    }
   f3.close();
   ofstream f4("STATUS.DAT",ios::binary|ios::out);
   f4.write((char*)&s,sizeof(s));
   f4.close();
 }

void itementry();
void accdetail();
void inputmoney();
void signout();
int flag2=0;

void dealerpage()                              // Dealer Page.
 {
   if(u.stat==0)
    {clrscr(); cout<<" ACCESS DENIED !!  SIGN IN UNDETECTED.. ";getch();e.oops();
    }
   else{clrscr();
   cout<<"\n DEALER'S  PAGE.                         Now Signed In as : "<<u.d1.name;
   cout<<".\n";
   int k=0;
   while(k<80)
    {cout<<"=";k++;}
   cout<<"\n\n\n";
   cout<<" Hello And Welcome back to the iStore  Mr./Mrs. "<<u.d1.name<<" .\n\n";
   if((u.d1.transstatus!=0) && (flag2==0))
    { cout<<"\n\n\n ";
      char str[]="1 Message Recieved. Press ENTER to View Message.";
      blink(str);
      getch();
      for(int q=0;q<50;q++)
       cout<<"\b";
      cout<<"\n";
      for(q=0;q<80;q++)
       cout<<"";
      cout<<"\n\n We are pleased to inform you that "<<u.d1.transstatus<<" of our customers have bought your products  so far.";
      cout<<"\n Keep up the good work and gain commisions !   - Manager, iStore. ";
      cout<<"\n\n\n\n";
      for(q=0;q<80;q++)
       cout<<"";
      cout<<"\n\n\n";
      getch();
      flag2++;
      clrscr();
      cout<<"\n DEALER'S  PAGE.                         Now Signed In as : "<<u.d1.name;
   cout<<".\n";
   int k=0;
   while(k<80)
    {cout<<"=";k++;}
   cout<<"\n\n\n";
   cout<<" Hello And Welcome back to the iStore  Mr./Mrs. "<<u.d1.name<<" .\n\n";

    }
   cout<<endl<<endl;
   cout<<showfile2("DEALERPAGE");
   int choice;
   cin>>choice;
   switch(choice)
    { case 1:itementry();break;
      case 2:accdetail();break;
      case 3:inputmoney();break;
      case 4:signout();break;
      default : e.oops();return;
    }
   }

 }


void itementry()                                     // Enter Item.
 { clrscr();
   cout<<"\n ITEM ENTRY OPTIONS.  \n";
   for(int o=0;o<80;o++)
    cout<<"=";
   cout<<"\n\n 1. Update Stock of Existing Item ";
   cout<<"\n\n 2. Add New Item ";
   cout<<"\n\n\n Enter Choice : ";
   int choice;
   cin>>choice;
   switch(choice)
    { case 1: item i6;
	      cout<<"\n\n Product List of "<<u.d1.company<<" : ";
	      cout<<endl<<endl;
	      for(int ky=0;ky<80;ky++)
	       cout<<"+";
	      cout<<" ";
	      item idis;int cnt=1;
	      fstream fin8("ITEM.dat",ios::binary|ios::out|ios::in);
	      while(fin8.read((char*)&idis,sizeof(idis)))
	       { if(strcmp(idis.d2.username,u.d1.username)==0)
		  { cout<<cnt++<<"."<<idis.itemname<<"          ";
		    switch(cnt)
		     { case 4:
		       case 7:
		       case 10:
		       case 13:
		       case 16:
		       case 19:
		       case 22:
		       case 25:
		       case 28:
		       case 31:
		       case 34: cout<<endl<<endl<<" ";break;
		     }
		 if(cnt==34)
		  {getch();
		   clrscr();
		  }
		 }
		}
	     fin8.close();
	     cout<<"\n";
	     for(int ky1=0;ky1<80;ky1++)
	       cout<<"+";
	      cout<<"\n\n Enter Item Name of Existing Item : ";
	      char s[80];  int flag=0;int a9;
	      gets(s);
	      fstream fin("ITEM.dat",ios::binary|ios::out|ios::in);
	      while(fin.read((char*)&i6,sizeof(i6)))
	       {
		 if(strcmpi(i6.itemname,s)==0)
		  { cout<<"\n Existing Quantity of "<<i6.itemname<<" is : "<<i6.quantity;
		    cout<<" \n\n Enter Items Added : ";
		    int quant;
		    cin>>quant;
		    i6.quantity+=quant;
		    a9=fin.tellg();
		    fin.seekp(a9-sizeof(i6));
		    fin.write((char*)&i6,sizeof(i6));
		    flag=1;break;
		  }
	       }
	      if(flag==0)
	       { cout<<"\n\n Item Not Found ! :( ";
		 getch();
		 itementry();
		 return;
	       }
	      else
	       { cout<<"\n\n Item(s) added Successfully ! ";
		 getch();
		 fin.close();
		 dealerpage();
		 return;
	       }


      case 2: item i2;
	      i2.inputdata();
	      ofstream fino("ITEM.dat",ios::binary|ios::out|ios::app);
	      fino.write((char*)&i2,sizeof(i2));
	      fino.close();
	      dealerpage();
	      break;

      default : e.oops();return;
    }
   return;

 }

void accdetail()                                     // Account Details.
 { clrscr();
   cout<<" Welcome Mr. "<<u.d1.name<<" .  The following are your financial details : \n\n";
   cout<<"  \n Credit Card Number   :   ";
   cout<<u.d1.number;
   cout<<"\n\n Account PIN          :   ";
   cout<<u.d1.pin;
   cout<<"\n\n\n Account Balance    :   $ ";
   cout<<u.d1.balance;
   cout<<"\n\n\n Press ENTER to go back to account page ..";
   getch();
   dealerpage();
 }

void inputmoney()                                 // Deposit Money.
 { clrscr();
   cout<<" Welcome Mr. "<<u.d1.name<<" .  The following are your financial details :\n\n";
   cout<<"  \n Credit Card Number   :   ";
   cout<<u.d1.number;
   cout<<"\n\n Account PIN          :   ";
   cout<<u.d1.pin;
   cout<<"\n\n\n Account Balance    :   $ ";
   cout<<u.d1.balance;
   cout<<"\n\n\n Enter the amount you wish to add to your account  :  $ ";
   int temp;
   cin>>temp;
   u.d1.balance+=temp;
   cout<<"\n\n\n Amount Deposited Successfully. Make sure you sign out now for the changes to    take place .";
   getch();
   dealerpage();
   return;
 }

void updateuserstatus();

void signout()                                 // Sign Out.
 { clrscr();char cont;
   cout<<"\n Are you sure you want to sign out from your Account ? (Y||N) : ";
   cin>>cont;
   if(tolower(cont)=='y')
    { updateuserstatus();
      u.stat=0;
      strcpy(u.d1.name,"UNNAMED");
      start(500);return;
    }
   else
    dealerpage();
 }


void updateuserstatus()
 { fstream fout("D.DAT",ios::binary|ios::in|ios::out);
   dealeraccount d4;int a,flag=0;
   while (fout.read((char*)&d4,sizeof(d4)))
    {

     if(strcmp((d4.username),(u.d1.username))==0)
       { a=fout.tellg();
	 fout.seekp(a-sizeof(d4));
	 fout.write((char*)&(u.d1),sizeof(u.d1));
	 flag=1;break;
       }
    }
    if(flag==0)
     { cout<<" \n\n Something Went Wrong :( ";
       getch();
       e.oops();
       return;
     }
   fout.close();
   cout<<"\n Signed Out Successfully . Press ENTER to Continue ... ";
   getch();
 }



//============================= CUSTOMER  AREA  =============================


void purchase2();
void accdetail2();
void inputmoney2();
void signout2();


void customerpage()                       // Customer Page.
 { if(u.stat==0)
    {clrscr();
     cout<<" ACCESS DENIED !!  SIGN IN UNDETECTED.. ";
     getch();
     start(500);
     return;
    }
   else
    { clrscr();
      cout<<"\n CUSTOMER  PAGE.  \n";
      int k=0;
      while(k<80)
       {cout<<"=";
	k++;
       }
      cout<<"\n\n\n";
      cout<<" Hello And Welcome to the iStore  Mr./Mrs. "<<u.c1.name<<".\n\n";
      getch();
      cout<<showfile2("PACUST");
      int choice;
      cin>>choice;
      switch(choice)
       { case 1:purchase2();
		break;
	 case 2:accdetail2();
		break;
	 case 3:inputmoney2();
		break;
	 case 4:signout2();
		break;
	 default : e.oops();
		   return;
       }
   }
 }


void accdetail2()                        // Account Details.
 { clrscr();
   cout<<" Welcome Mr. "<<u.c1.name<<" .  The following are your financial details : \n\n";
   cout<<"  \n Credit Card Number   :   ";
   cout<<u.c1.number;
   cout<<"\n\n Account PIN          :   ";
   cout<<u.c1.pin;
   cout<<"\n\n\n Account Balance    :   $ ";
   cout<<u.c1.balance;
   cout<<"\n\n\n\n Press ENTER to go back to account page ..";
   getch();
   customerpage();
   return;
 }

void inputmoney2()                         // Input Money.
 { clrscr();
   cout<<" Welcome Mr.\Mrs. "<<u.c1.name<<" .  The following are your financial details :\n\n";
   cout<<"  \n Credit card number     :   ";
   cout<<u.c1.number;
   cout<<"  \n\n Account PIN          :   ";
   cout<<u.c1.pin;
   cout<<"\n\n\n Account Balance      :   $ ";
   cout<<u.c1.balance;
   cout<<"\n\n\n\n Enter the amount you wish to add to your account  :  $ ";
   int temp;
   cin>>temp;
   u.c1.balance+=temp;
   cout<<"\n Amount Deposited Successfully. Press ENTER to go Back. ";
   getch();
   customerpage();
   return;
 }



void updateuserstatus2();

void signout2()                            // Sign Out.
 { clrscr();
   char cont;
   cout<<"\n CONFIRMATION. \n";
   for(int w=0;w<80;w++)
    cout<<"=";
   cout<<"\n\n Are You Sure You Want to Sign Out from your Account ? (Y||N) : ";
   cin>>cont;
   if(tolower(cont)=='y')
    { updateuserstatus2();
      u.stat=0;
      strcpy(u.c1.name,"UNNAMED");
      start(500);
      return;
    }
   else
    { customerpage();
      return;
    }
 }


void updateuserstatus2()
 { fstream fout("C.DAT",ios::binary|ios::in|ios::out);
   customeraccount c4;
   int a,flag=0;
   while (fout.read((char*)&c4,sizeof(c4)))
    {

     if(strcmp((c4.username),(u.c1.username))==0)
       { a=fout.tellg();
	 fout.seekp(a-sizeof(c4));
	 fout.write((char*)&(u.c1),sizeof(u.c1));
	 flag=1;break;
       }
    }
    if(flag==0)
     { cout<<" \n\n Something Went Wrong :( ";
       getch();
       e.oops();
       return;
     }


   fout.close();
   cout<<"\n Signed Out Successfully !  Press ENTER to Continue ... ";
   getch();
   start(500);
   return;
 }

void search();
void browse();
void browsecompany();
void browseprice();
void browsecategory();

void purchase2()                           // Purchase Items.
 { clrscr();
   cout<<showfile2("PURCH");
   int a;
   cin>>a;
   switch(a)
   {
      case 1 :  browse(); break;
      case 2 :  browsecompany();break;
      case 3 :  browseprice();break;
      case 4 :  browsecategory();break;
      default : e.oops();return;
    }
 }

void purchase(item);

void browseprice()                         // Filter By Price.
 { clrscr();
   item i;
   char p[80];
   int cnt=1;
   cout<<"\n\n";
   cout<<"\n\n Enter Price Range to filter products : ";
   cout<<"\n\n Higest : $ ";
   int highest;
   int lowest;
   cin>>highest;
   cout<<"\n Lowest : $ ";
   cin>>lowest;
   if(highest<lowest)
    { cout<<" Eh?.. The highest price seems to be smaller than the lowest price. Try Again ";
      getch();
    }
   clrscr();
   cout<<"\n\n List of items that fall under specified Price Range : \n\n\n";
   for(int ky1=0;ky1<80;ky1++)
    cout<<"+";
   cout<<"\n\n";
   int flag=0;
   ifstream f1("ITEM.dat",ios::binary|ios::in);
   cout<<" ";
   while(f1.read((char*)&i,sizeof(i)))
    { if((i.price<=highest) && (i.price>=lowest ))
     {
      cout<<cnt++<<"."<<i.itemname<<"         ";
      switch(cnt)
       { case 4:
	 case 7:
	 case 10:
	 case 13:
	 case 16:
	 case 19:
	 case 22:
	 case 25:
	 case 28:
	 case 31:
	 case 34: cout<<endl<<endl<<" ";break;
       }
      if(cnt==34)
       {getch();
	clrscr();
       }
      flag=1;
     }
    }
     if(flag==0)
      { cout<<"\n\n NIL. Sorry . No items could be filtered with the specified Price Range. ";
	cout<<"\n Press ENTER to try again. ";
	getch();
	purchase2();
	return;
      }

   f1.close();
   cout<<"\n\n\n\n";
   for(ky1=0;ky1<80;ky1++)
    cout<<"+";
   cout<<"\n\n\n Enter ITEMNAME of product you wish to purchase : ";
   gets(p);
   item i1;
   flag=0;
   cnt=1;
   ifstream f3("ITEM.dat",ios::binary|ios::in);
   while(f3.read((char*)&i1,sizeof(i)))
    {
      { if(strcmpi(p,i1.itemname)==0)
	 { purchase(i1);flag=1;
	   return;
	 }
      }
    }
   if(flag==0)
    { cout<<"\n\n That Item was not found in the above List . Press ENTER to continue.";
      getch();
      purchase2();
      return;
    }
   f3.close();
 }

void browsecategory()                        // Filter By Category.
 { clrscr();
   item i;
   char p[80];
   int cnt=1;
   cout<<"\n";
   item i2;
   int j;
   int kq;
   ifstream f2("ITEM.dat",ios::binary|ios::in);
   cout<<" ";
   cout<<"\n\n The List of all available categories in iStore : ";
   cout<<"\n ( No: of items in each are indicated in brackets )\n\n\n";
   char fake[80][80]={""};
   char num[80];
   int q=0;
   for(kq=0;kq<80;kq++)
    cout<<"+";
   cout<<"\n\n";
   int flag,freq=0;
   while(f2.read((char*)&i2,sizeof(i2)))
    { strcpy(fake[q],i2.category);
      q++;
    }
    int count=q;
    for(q=0;q<count;q++)
     { strcpy(num,fake[q]);
       flag=0;freq=0;
       for(j=0;j<q;j++)
	{ if(strcmp(num,fake[j])==0)
	   flag=1;
	}
       if(flag==0)
	{ for(j=0;j<count;j++)
	   { if(strcmp(num,fake[j])==0)
	      freq++;
	   }

	   // Output Starts.
	  cout<<cnt++<<"."<<fake[q]<<" ("<<freq<<")         ";
	  switch(cnt)
	   { case 4:
	     case 7:
	     case 10:
	     case 13:
	     case 16:
	     case 19:
	     case 22:
	     case 25:
	     case 28:
	     case 31:
	     case 34: cout<<endl<<endl<<" ";break;
	   }
	  if(cnt==34)
	   {getch();
	    clrscr();
	   }
	   //Output Ends.
	}
     }
   f2.close();
   cout<<"\n\n\n\n";
   int ky1;
   for( ky1=0;ky1<80;ky1++)
    cout<<"+";

   cout<<"\n\n Enter a Category from above list : ";
   char w[80];
   gets(w);
   clrscr();
   cout<<"\n\n List of Items available in the section "<<w<<" are :\n\n";
   for(ky1=0;ky1<80;ky1++)
    cout<<"+";
   cnt=1;
   flag=0;
   cout<<"\n\n";
   ifstream f1("ITEM.dat",ios::binary|ios::in);
   cout<<" ";
   while(f1.read((char*)&i,sizeof(i)))
    { if(strcmpi(i.category,w)==0)
     {
      cout<<cnt++<<"."<<i.itemname<<"         ";
      switch(cnt)
       { case 4:
	 case 7:
	 case 10:
	 case 13:
	 case 16:
	 case 19:
	 case 22:
	 case 25:
	 case 28:
	 case 31:
	 case 34: cout<<endl<<endl<<" ";break;
       }
      if(cnt==34)
       {getch();
	clrscr();
       }   flag=1;
      }
     }
   if(flag==0)
    { cout<<" NIL. Sorry .. Category Not Found. Check for string mismatches. :(";
	getch();
	customerpage();
	return;
    }
   f1.close();
   cout<<"\n\n\n\n";
   for(ky1=0;ky1<80;ky1++)
    cout<<"+";
   cout<<"\n\n\n Enter ITEMNAME of product you wish to purchase : ";
   gets(p);
   item oui;
   flag=0;
   ifstream f3("ITEM.dat",ios::binary|ios::in);
   while(f3.read((char*)&oui,sizeof(oui)))
    {
       if(strcmpi(p,oui.itemname)==0)
	 { flag=1;
	   purchase(oui);
	   return;
	 }

    }
   if(flag==0)
    { cout<<"\n\n That Item was not found in the above List . Press ENTER to continue.";
      getch();
      purchase2();
      return;
    }
   f3.close();
 }

void browse()                                // No Filter.
 { clrscr();
   item i;
   char p[80];
   int cnt=1;
   cout<<"\n\n List of all items available in iStore :\n\n\n";
   for(int ky1=0;ky1<80;ky1++)
    cout<<"+";
   cout<<"\n\n";
   ifstream f1("ITEM.dat",ios::binary|ios::in);
   cout<<" ";
   while(f1.read((char*)&i,sizeof(i)))
    {
      cout<<cnt++<<"."<<i.itemname<<"         ";
      switch(cnt)
       { case 4:
	 case 7:
	 case 10:
	 case 13:
	 case 16:
	 case 19:
	 case 22:
	 case 25:
	 case 28:
	 case 31:
	 case 34: cout<<endl<<endl<<" ";break;
       }
      if(cnt==34)
       {getch();
	clrscr();
       }
     }
   f1.close();
   cout<<"\n\n\n";
   for(ky1=0;ky1<80;ky1++)
    cout<<"+";
   cout<<"\n\n\n Enter ITEMNAME of product you wish to purchase : ";
   gets(p); item i1;  int flag=0;
   ifstream f2("ITEM.dat",ios::binary|ios::in);
   while(f2.read((char*)&i1,sizeof(i)))
    {
      { if(strcmpi(p,i1.itemname)==0)
	 { flag=1;
	   purchase(i1);
	   return;
	 }
      }
    }
   if(flag==0)
    { cout<<"\n\n That Item was not found in the above List . Press ENTER to continue.";
      getch();
      purchase2();
      return;
    }
   f2.close();
 }

					     // Show Counters.
void showstatus()
 { clrscr();
   cout<<showfile2("status");
   cout<<"\n";
   int e1=0,e2=0,e4=0;
   ifstream f1("D.DAT",ios::binary|ios::in);
   dealeraccount dd1;
   while(f1.read((char*)&dd1,sizeof(dd1)))
    e1++;
   f1.close();
   ifstream f2("C.DAT",ios::binary|ios::in);
   customeraccount cc1;
   while(f1.read((char*)&cc1,sizeof(cc1)))
    e2++;
   f2.close();
   ifstream f3("ITEM.DAT",ios::binary|ios::in);
   item ii1;
   while(f3.read((char*)&ii1,sizeof(ii1)))
    e4++;
   f3.close();
   cout.setf(ios::left);
   cout<<setw(30)<<" 1. Dealers Registered           :  "<<e1;
   cout<<"\n\n"<<setw(30)<<" 2. Customers Registered         :  "<<e2;
   cout<<"\n\n"<<setw(30)<<" 3. No. of Items Available       :  "<<e4;
   cout<<"\n\n\n\n\n\n\n\n Press ENTER to return to Homepage.	 ";
   getch();
   e.oops();
   return;
 }


void browsecompany()                         // Browse By Company.
 { clrscr();
    item i;
   char p[80];
   int cnt=1;
   cout<<"\n";
   item i2;
   int j;
   ifstream f2("ITEM.dat",ios::binary|ios::in);
   cout<<" ";
   cout<<"\n\n The List of all Dealers signed up in iStore : ";
   cout<<"\n ( No: of items marketed by each are shown in brackets ) \n\n\n";
   char fake[80][80]={""};
   char num[80];
   int q=0;
   for(int kq=0;kq<80;kq++)
    cout<<"+";
   cout<<"\n\n";
   int flag,freq=0;
   while(f2.read((char*)&i2,sizeof(i2)))
    { strcpy(fake[q],i2.d2.company);
      q++;
    }
    int count=q;
    for(q=0;q<count;q++)
     { strcpy(num,fake[q]);
       flag=0;freq=0;
       for(j=0;j<q;j++)
	{ if(strcmp(num,fake[j])==0)
	   flag=1;
	}
       if(flag==0)
	{ for(j=0;j<count;j++)
	   { if(strcmp(num,fake[j])==0)
	      freq++;
	   }

	   // Output Starts.
	  cout<<cnt++<<"."<<fake[q]<<" ("<<freq<<")         ";
	  switch(cnt)
	   { case 4:
	     case 7:
	     case 10:
	     case 13:
	     case 16:
	     case 19:
	     case 22:
	     case 25:
	     case 28:
	     case 31:
	     case 34: cout<<endl<<endl<<" ";break;
	   }
	  if(cnt==34)
	   {getch();
	    clrscr();
	   }
	   //Output Ends.
	}
     }
   f2.close();
   cout<<"\n\n\n\n";
   int ky1;
   for( ky1=0;ky1<80;ky1++)
    cout<<"+";

   cout<<"\n\n Enter the Company whose products you want to filter : ";
   char w[80];
   gets(w);
   clrscr();
   cout<<"\n\n List of Items marketed by "<<w<<" are : \n\n\n";
   for(ky1=0;ky1<80;ky1++)
    cout<<"+";
   cnt=1;
   flag=0;
   cout<<"\n\n";
   ifstream f1("ITEM.dat",ios::binary|ios::in);
   cout<<" ";
   while(f1.read((char*)&i,sizeof(i)))
    { if(strcmpi(i.d2.company,w)==0)
     {
      cout<<cnt++<<"."<<i.itemname<<"         ";
      switch(cnt)
       { case 4:
	 case 7:
	 case 10:
	 case 13:
	 case 16:
	 case 19:
	 case 22:
	 case 25:
	 case 28:
	 case 31:
	 case 34: cout<<endl<<endl<<" ";break;
       }
      if(cnt==34)
       {getch();
	clrscr();
       }   flag=1;
      }
     }
   if(flag==0)
    { cout<<"\n\n NIL. Sorry .. Unregistered Company. Check for string mismatches. :(";
	getch();
	customerpage();
	return;
    }
   f1.close();
   cout<<"\n\n";
   for(ky1=0;ky1<80;ky1++)
    cout<<"+";
   cout<<"\n\n\n Enter ITEMNAME of product you wish to purchase : ";
   gets(p);
   item oui;
   flag=0;
   ifstream f3("ITEM.dat",ios::binary|ios::in);
   while(f3.read((char*)&oui,sizeof(oui)))
    {
       if(strcmpi(p,oui.itemname)==0)
	 { flag=1;
	   break;
	 }
    }
   if(flag==1)
    {purchase(oui);
     f3.close();
     return;
    }
   else
    { cout<<"\n\n That Item was not found in the above List . Press ENTER to continue.";
      getch();
      purchase2();
      f3.close();
      return;
    }
 }


void purchase(item i3)                       // Purchase Item 2.
 { i3.displaydata();
   cout<<"\n\n Do you wish to buy this Item? (Y||N) : ";
   char ans;
   cin>>ans;
   if(toupper(ans)!='Y')
    { customerpage();
      return;
    }
   else
    { clrscr();
      if(u.stat==0)
       { cout<<" Something Happened . Please Sign in Again. ";
	 getch();
	 e.oops();
	 return;
       }
      else
      { cout<<"\n\n Transaction Page for Mr./Mrs.  ";
	cout<<u.c1.name<<" .";
	cout<<endl<<endl;
	int quantinput;
	int netpriceinput;
	if(i3.quantity==0)
	 { cout<<" Sorry ! But we ran out of stock for this item. ";
	   getch();
	   customerpage();
	   return;
	 }
	else
	 {
	  cout<<"\n\n Enter Quantity Needed : ";
	  cin>>quantinput;
	  if(i3.quantity<quantinput)
	   { cout<<"\n\n Sorry but we have limited stocks for this item. Try for smaller quantaties. ";
	     cout<<"\n\n Available Quantity : "<<i3.quantity<<" nos. ";
	     getch();
	     purchase(i3);
	     return;
	   }
	  else
	   { if(u.c1.balance<(quantinput * i3.price))
	      { cout<<"\n\n Sorry but you do not have the necessary funds in your account for this \n Transaction . ";
		cout<<"\n\n Account Balance   : $ ";
		cout<<u.c1.balance;
		cout<<"\n\n Bill Amount       : $ ";
		cout<<quantinput * i3.price;
		cout<<"\n\n\n Press ENTER to cancel current transaction and exit to User Page. ";
		getch();
		customerpage();
		return;
	      }
	  else
	   { cout<<"\n\n\n Generate BILL and PROCEED ? (Y||N)  : ";
	     char s;
	     cin>>s;
	     if(toupper(s)=='Y')
	      { clrscr();
		cout.setf(ios::left);
		int net=(quantinput * i3.price);
		cout<<"=================================  SALES  BILL  ================================";
		cout<<"\n\n\n Sl.No:     Item Name :    Quantity :      Unit  Price:          Net Amount:";
		cout<<"\n================================================================================";
		cout<<"\n\n "<<"  1.        "<<setw(14)<<i3.itemname<<"    "<<setw(3)<<quantinput<<"             $ "<<setw(3)<<i3.price<<"                 $ "<<setw(3)<<net;


		fstream fout("ITEM.DAT",ios::binary|ios::in|ios::out);          //altering quantity in file
		item c0;int a,flaga=0;
		 while (fout.read((char*)&c0,sizeof(c0)))
		  {

		  if(strcmp(c0.itemname,i3.itemname)==0)
		   { a=fout.tellg();
		     fout.seekp(a-sizeof(c0));
		     c0.quantity-=quantinput;
		     fout.write((char*)&(c0),sizeof(c0));
		     flaga=1;
		     break;
		   }
		  }
		  if(flaga==0)
		   { cout<<" \n\n Something Went Wrong :( ";
		     getch();
		     e.oops();
		     return;
		   }
		  fout.close();

		  fstream fout2("C.DAT",ios::binary|ios::in|ios::out);
		  customeraccount c7;int a2=0;int flagb=0;
		  while (fout2.read((char*)&c7,sizeof(c7)))
		   {

		    if(strcmpi((c7.username),(u.c1.username))==0)
		     { a2=fout2.tellg();
		       fout2.seekp(a2-sizeof(c7));
		       c7.balance-=net;
		       u.c1.balance-=net;
		       fout2.write((char*)&(c7),sizeof(c7));
		       flagb=1;
		       break;
		     }
		   }
	       ifstream fout90("C.DAT",ios::binary|ios::in);
	       customeraccount c90;
	      while (fout2.read((char*)&c90,sizeof(c90)))
	       {
		 if(strcmpi((c90.username),(u.c1.username))==0)
		 {  cout<<c90.username<<c90.balance;getch();
		    break;
		  }
		 }
		if(flagb==0)
		   { cout<<" \n\n Something Went Wrong :( ";
		     getch();
		     e.oops();
		     return;
		   }
		  fout2.close();

		  fstream fout3("D.DAT",ios::binary|ios::in|ios::out);
		  dealeraccount d4;int a3;int flagc=0;
		  while (fout3.read((char*)&d4,sizeof(d4)))
		   {

		    if(strcmp((d4.username),(i3.d2.username))==0)
		     { a3=fout3.tellg();
		       fout3.seekp(a3-sizeof(d4));
		       d4.balance+=net;
		       d4.transstatus++;
		       fout3.write((char*)&(d4),sizeof(d4));
		       flagc=1;break;
		     }
		   }
		  if(flagc==0)
		   { cout<<" \n\n Something Went Wrong :( ";
		     getch();
		     e.oops();
		     return;
		   }
		  fout3.close();

		  cout<<"\n\n\n\n\n\n Transaction Completed Successfully. ";
		  cout<<" \nPress ENTER to Continue ... ";
		  getch();
		  customerpage();
		  return;
	     }
	  }
	 }
       }
      }
    }
 }


void graphicscreen(char *msg1,int size,int time)   // Graphics Output.
 {
  int gdriver = DETECT, gmode, errorcode;
  initgraph(&gdriver, &gmode,"");
  int maxcolor = getmaxcolor();
  settextjustify(CENTER_TEXT, CENTER_TEXT);
  int x = getmaxx() / 2;
  int y = getmaxy() / 2;

  for (int color=1; color<=maxcolor; color++)
  { cleardevice();
    setcolor(color);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, size);
    if(strcmp(msg1,"iStore.")==0)
     { sprintf("iStore.", "Color: %d", color);
       outtextxy(x, y-50,"iStore.");
     }
    else
     { sprintf("LOADING.", "Color: %d", color);
      outtextxy(x, y-50,"LOADING.");
     }
   delay(time);
  }
  closegraph();
 }


/*void rank()
 { clrscr();
   int w;
   for(w=0;w<33;w++)
    cout<<"=";
   cout<<" HALL OF FAME. ";
   for(w=0;w<32;w++)
    cout<<"=";
   cout<<"\n\n\n";
   cout<<" This section gives the list of all registered dealers ranked according to\n";
   cout<<" their perfomance in sales so far. Use this to choose dealers to buy your \n";
   cout<<" products from.\n\n";
   cout<<" And Dealers, Make your way to the top of the list to gain more customers.\n\n";
   cout<<"\n Note : This list is prepared by calculating the total no. of customer visits.\n";
   cout<<" \n Do check in here frequently for updates. ";
   cout<<" \n\n\n Press ENTER to view the complete list. ";
   getch();
   clrscr();
   ifstream f1("D.DAT",ios::binary|ios::in);
   dealeraccount2 check;
   dealeraccount2 check1[7];
   int i=0;
   while(f1.read((char*)&check,sizeof(check)))                            // THE BUG IS HERE..
    { check1[i]=check;
      i++;
    }
   int count=i;
   f1.close();
   dealeraccount2 temp;
   int j;
   for(i=1;i<count;i++)
    { temp=check1[i];
      j=i-1;
      while(temp.transstatus>check1[j].transstatus && j>=0)
       { check1[j+1]=check1[j];
	 j--;
       }
      check1[j+1]=temp;
    }
   cout<<"\n\n\n";
   cout<<"===============================================================================";
   cout<<"\n";
   cout.setf(ios::left);
   for(i=0;i<count;i++)
    { cout<<" "<<i+1<<". "<<setw(20)<<check1[i].company<<".     Managed by : ";
      cout<<check1[i].name<<"\n\n";
    }
   cout<<"========================================================================== End.";
   cout<<"\n\n\n Press ENTER to go to HomePage. ";
   getch();
   start(500);
   return;
 } */



void main()                                  // Main Starts Here.
 {
   textcolor(YELLOW);
   start(500);

 }



// END.