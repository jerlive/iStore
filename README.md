# iStore
A virtual store management system with dealers and customers as end users.

CONTENTS.


Introduction



This program takes customers and dealers of various firms as end users and provides them with separate accounts to deal with the variety of commodities they wish to purchase or sell in the Store. Each account is capable of managing financial details and the end users can update their status by using provided options. This program is equipped to handle multiple customer and dealer accounts in a single run and also provides for creating the same for the end-user.
Each user is requested sign in to their accounts in the beginning using a username and password they have created and if a customer, he/she can search for items using four provided filters in the database. The user can then buy the item he/she chooses and a bill of sale would be produced whose amount would be settled from the account he/she uses. This money would be deposited in the dealer account from which the item has been issued by. The dealer on the other hand can monitor customer visits and can also update the list of available items he wishes to sell or can add new items too which would be available for all registered customers for purchase. The dealer is also notified when more and more customers buy from his/her account through a message service.
This makes the program independent on itself and can be used my multiple users all working on the same database. The program also maintains a counter which accounts for the total transactions done and the number of registered customers and dealers. 
To achieve all this different binary files have been used and the database so created gets modified every time a user works on the program.  All errors which might creep up during runtime including false inputs by users and program instability have been taken care of through error messages and automatic save methodology.

This program has been coded in pure C++ programming language and a Turbo C compiler is used to run the same. It relies on various dependencies like binary & text files and graphic libraries to give an aesthetic appeal for the output. To find out more about dependencies, coding and output read on till the end of this document.
On a concluding note, this program provides innumerous possibilities to develop itself into a practical program that can be used in a shopaholic dominant world.



Synopsis of Program Code 

Files USED:

“C.DAT “        -Binary File to store records of Customer details.
“D.DAT”         -Binary File to store records of dealer details.
“ITEM.DAT”       -Binary File to store record of available items for sale.
“STATUS.DAT”    - Binary File to maintain the Counters
“WELCOME.TXT”   -Text File to show the contents of Home Page.
“STATUS.TXT”        -Text File to show the contents of Status Screen.
“SIGNUP.TXT”        -Text File to show the contents of Sign up Page.
“SIGNIN.TXT”        -Text File to show the contents of Sign in Page.
“PAGECUST.TXT”  -Text File to show the contents of Customer Page.
“INCUST.TXT”        -Text File to show the contents of customer Sign In Page.
“DEALERSS.TXT”      -Text File to show the contents of dealer Sign Up Page.
“DEALERSPA.TXT”  -Text File to show the contents of Dealer Page.
“DEALERIN.TXT”   -Text File to show the contents of Dealer Sign in Page.
“CUSTOMER.TXT”   -Text File to show the contents of customer Sign Up Page.
“CONTACT.TXT”         -Text File to show the contents of Contact Page.


classes USED:

ITEM
CUSTOMERACCOUNT
DEALERACCOUNT
STATUS
ERROR
USERSTATUS



FUNCTIONS USED:

void graphicscreen(char*,int,int);
void dealerpage();
void customerpage();
void blink(char *str);
void start(int);
void error::oops();
void showwelcome(int);
void signup();
void signin();
void contact();
void showstatus();
void rank();
void statusupdate();
char* showfile2(char d[25]);
void getpass(char *s) ;
void dealerssignup();
void customersignup();
void dealersignin();
void customerpage();
void customersignin();
void item::inputdata();
void item::displaydata();
void statusupdate();
void itementry();
void accdetail();
void inputmoney();
void signout();
void updateuserstatus();
void purchase2();
void accdetail2();
void inputmoney2();
void signout2();
void search();
void browse();
void browsecompany();
void browseprice();
void browsecategory();
void purchase(item);
void graphicscreen(char *msg1,int size,int time);
void rank();

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

