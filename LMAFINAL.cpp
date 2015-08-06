//Library Management Application

//header files
#include<fstream>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<windows.h>

using namespace std;

//classes

class book
{
 char bname[50];        // Name of the book
 char aname[30];        // Name of the author of the book
 char isbn[10];			// isbn of the book
 int year;				// publication year
 int copies;			// no. of copies available in the library

 public:

 book();				// constructor for book class
 void displaybook();	// display the book information
 char* getbname();		// accessor function that returns book name
 char* getisbn();		// accessor function that returns isbn
 int getcopies();		// accessor function that returns no. of copies of the book
 void bookinfoinput();  // function to input all book details from user
 void removecopy();		// decreases the no. of copies of the book by 1. called when a book is issued
 void addcopy();		// increases the no. of copies of the book by 1. called when an issued book is returned
 void resetcopies();    // set the no. of copies of the book to 1
};

book::book()
{
    year=1996;
    copies=1;
}

void book::resetcopies()
{
    copies=1;
}

char* book::getbname()
 {
     return bname;
 }

 char* book::getisbn()
 {
     return isbn;
 }

 int book::getcopies()
 {
     return copies;
 }


 void book::removecopy()
 {
     copies--;
 }

 void book::addcopy()
 {
     copies++;
 }

void book::displaybook()
{
 cout<<"    Book name\t\t     "<<bname;
 cout<<"\n    Author name\t\t     "<<aname;
 cout<<"\n    ISBN\t\t     "<<isbn;
 cout<<"\n    Publication year\t     "<<year;
 cout<<"\n    No. of copies available  "<<copies;
 cout<<"\n\n\n";

}


void book::bookinfoinput()
{
 fflush(stdin);

 cout<<"\n    Book name ";
 cin.getline(bname,50);
 cout<<"\n    Author ";
 cin.getline(aname,30);
 cout<<"\n    ISBN (9 digits) ";
 cin.getline(isbn,10);
 cout<<"\n    Publication year ";
 cin>>year;
 cout<<"\n    No. of copies ";
 cin>>copies;

 //end of function
}





class LDATE
{
 int day;
 int month;
 int year;

 public:

	 LDATE();			// constructor
     int getday();		// accessor function that returns day
     int getmonth();	// accessor function that returns month
     int getyear();		// accessor function that returns year
     void inputdate();	// accessor function that returns function to input date

};

     LDATE::LDATE()
	 {
		day=1;
		month=1;
		year=2000;
	 }

     int LDATE::getday()
     {
         return day;
     }

     int LDATE::getmonth()
     {
         return month;
     }

     int LDATE::getyear()
     {
         return year;
     }

void LDATE::inputdate()
{
   cout<<"\n    Enter date (Day Month Year)\n    ";
   cin>>day;
   cout<<"    ";
   cin>>month;
   cout<<"    ";
   cin>>year;
}






class issuedbook             // class to maintain record of issued books
{
 book binfo;            // book information
 char sname[30];        // name of the student issuing the book
 char studroll[11];		// roll no. of the student
 LDATE date;			// date of issuing

 public:

 void dispissued();      // display the details of an issued book
 char* getstudroll();    // accessor function for student rollno
 book getbinfo();		 // accessor functin for binfo
 void setbinfo(book bo); // setter function for binfo
 void input();			 // function to input details of issued book

};





 char* issuedbook::getstudroll()
 {
     return studroll;
 }

 book issuedbook::getbinfo()
 {
     return binfo;
 }

 void issuedbook::setbinfo(book bo)
 {
     binfo=bo;
 }


void issuedbook::input()
{
   cout<<"\n\n    Enter the name of student to whom the book is to be issued\n    ";
   cin.getline(sname,30);
   cout<<"\n    Enter the enrollment no. of the student (10 digits)\n    ";
   cin.getline(studroll,11);

   date.inputdate();
}

void issuedbook::dispissued()
{
	cout<<"    Book name\t             "<<binfo.getbname();
	cout<<"\n    Book ISBN no.\t     "<<binfo.getisbn();
	cout<<"\n    student name\t     "<<sname;
	cout<<"\n    student enrollment no.   "<<studroll;
	cout<<"\n    Date\t\t     "<<date.getday()<<"/"<<date.getmonth()<<"/"<<date.getyear()<<"\n\n\n";
}




class libraryrec         // class to be used as a linked list to store record of all books in the library
{
    public:
	book info;
	libraryrec *next;
};


class issuerec			 // class to be used as a linked list to store record of all issued books
{
    public:
    issuedbook info;
    issuerec *next;
};


typedef libraryrec node;
typedef issuerec nodei;


//global objects

node *start=NULL,*ptr;
nodei *starti=NULL,*ptri;
book b;
issuedbook i;



//global function definitions

void displaylibraryrec()
{
 int i=0;
 system("cls");
 ptr=start;

 if(start==NULL)
 {
	cout<<"Currently there is no book in the library\n";
 }

 else
 {
  cout<<"\n    The details of all books in the library are\n\n\n";

  while(ptr!=NULL)
  {
   ptr->info.displaybook();
   ptr=ptr->next;
   i++;

   if(i%3==0)
   {
    getchar();
    getchar();
    system("cls");
   }

  }
 }

 getchar();
 //end of function
}




void displayissuerec()
{
 int i=0;
 system("cls");
 ptri=starti;

 if(starti==NULL)
 {
	cout<<"\n    Currently no book is issued from the library\n";
 }

 else
 {
  cout<<"\n    The details of all issued books from the library are\n\n\n";

  while(ptri!=NULL)
  {
   ptri->info.dispissued();
   ptri=ptri->next;
   i++;

   if(i%3==0)
   {
    getchar();
    getchar();
    system("cls");
   }

  }
 }
 getchar();

 //end of function
}



void addnew(book bookinfo)
{
 fflush(stdin);
 ptr=start;

 if(start==NULL)
 {
  ptr=new node;
  start=ptr;
 }

 else
 {
  while(ptr->next!=NULL)
  {
   ptr=ptr->next;
  }

  ptr->next=new node;
  ptr=ptr->next;
 }

 ptr->next=NULL;
 ptr->info=bookinfo;

 //end of function
}




void issuebook()
{
 char bookname[30];
 int y=1;       //y will be 1 if book is not found

 if(start==NULL)                //if linked list is empty
 {
  cout<<"\n    There is no book in the library to be issued\n";
  getchar();
 }


 else
 {

  fflush(stdin);
  cout<<"\n    Enter the name of the book you want to issue from library\n    ";
  cin.getline(bookname,30);
  ptr=start;

  if(strcmpi(ptr->info.getbname(),bookname)==0)         //if book is found at first position
  {
   y=0;

   if(ptr->info.getcopies()==1)          //in this case the record is deleted from library record
   {
    b=ptr->info;

    if(ptr->next!=NULL)
     start=ptr->next;

    else
     start=NULL;
   }

   else
   {
    ptr->info.removecopy();
    b=ptr->info;
   }


  }


  else                 //searching book at other positions
  {

   while(ptr->next!=NULL&&y!=0)
   {
    y=strcmpi(ptr->next->info.getbname(),bookname);

    if(y!=0)                         //book not found. shifting to next node
     ptr=ptr->next;

    else                             //condition when book is found
    {

     if(ptr->next->info.getcopies()==1)
     {
      b=ptr->next->info;

      if(ptr->next->next==NULL)
      {
       ptr->next=NULL;
      }

      else
      {
       ptr->next=ptr->next->next;
       ptr=ptr->next;
      }

     }

     else
     {
      ptr->next->info.removecopy();
      b=ptr->next->info;
     }

    }

    //end of while
   }

   //end of nested else
  }

  if(y!=0)
  {
   cout<<"\n    Required book not available in the library\n";
   getchar();
  }

  else
  {
   //deleted that copy of book from linked list
   ptri=starti;

   if(starti==NULL)
   {
    ptri=new nodei;
    starti=ptri;
   }

   else
   {
    while(ptri->next!=NULL)            //shifting ptri to last node to add new node at the end
    {
     ptri=ptri->next;
    }

    ptri->next=new nodei;
    ptri=ptri->next;
   }

   ptri->next=NULL;

   fflush(stdin);
   b.resetcopies();
   ptri->info.setbinfo(b);
   cout<<"\n    Book found";
   ptri->info.input();
   cout<<"\n    Book succesfully issued\n";

  }

  //end of main else part
 }




 //end of function
}




void returnbook()
{
 char bookname[30],enrollment[11];
 int p,y=1;       //y will be 1 if book is not found

 if(starti==NULL)
 {
  cout<<"\n    Currently no book is issued from the library\n";
 }



 else
 {
  fflush(stdin);
  cout<<"\n\n    Enter the name of the book you want to return\n    ";
  cin.getline(bookname,30);
  cout<<"\n    Enter the enrollment no. of the student to whom the book was issued\n    ";
  cin.getline(enrollment,11);

  ptri=starti;


  //searching the book to return at the first node
  if(strcmpi(ptri->info.getbinfo().getbname(),bookname)==0 && strcmp(ptri->info.getstudroll(),enrollment)==0)         //if book is found at first position
  {
   y=0;

   b=ptri->info.getbinfo();       //storing the book details in variable b

   if(ptri->next!=NULL)
    starti=ptri->next;

   else
    starti=NULL;
  }


  //searching book at other positions
  else
  {

   while(ptri->next!=NULL&&y!=0)
   {

    if(strcmpi(ptri->next->info.getbinfo().getbname(),bookname)==0 && strcmp(ptri->next->info.getstudroll(),enrollment)==0)         //if book is found at first position
     y=0;

    if(y!=0)                         //book not found. shifting to next node
     ptri=ptri->next;

    else                             //condition when book is found
    {

     b=ptri->next->info.getbinfo();


     if(ptri->next->next==NULL)
     {
      ptri->next=NULL;
     }

     else
     {
      ptri->next=ptri->next->next;
     }

     // else
    }

    //end of while
   }

   //else
  }

  //finished searching

   if(y!=0)
   {
    cout<<"\n    Required book not issued from the library \n";
    getchar();
   }



  else
  {
   //deleted that copy of book from issued linked list
   //now adding this record into library

    ptr=start;
    p=1;             // p=0 indicates book is found

    while(ptr!=NULL && p!=0)
    {
     p=strcmpi(ptr->info.getbname(),b.getbname());

     if(p==0)
     {
      ptr->info.addcopy();       // simply increasing the variable holding no. of copies by unity
     }

     else
     {
      ptr=ptr->next;
     }

     //end of while
    }


    if(p!=0)
    {
        addnew(b);
    }

   cout<<"\n    Book successfully returned\n";
   getchar();
  }




  //end of main else
 }

 //end of function
}





void removerec()
{
 int y=1;       //y will be 1 if book is not found
 char bookname[30];

 fflush(stdin);
 cout<<"\n    Enter the name of the book you want to remove from library\n    ";
 cin.getline(bookname,30);
 ptr=start;

 if(start==NULL)                //if linked list is empty
 {
  y=1;
 }

 else
 {
  if(strcmpi(ptr->info.getbname(),bookname)==0)         //if book is found at first position
  {
   y=0;

   b=ptr->info;

   if(ptr->next!=NULL)
    start=ptr->next;

   else
    start=NULL;
  }
						  //searching book at other positions
  else
  {
   while(ptr->next!=NULL&&y!=0)
   {
    y=strcmpi(ptr->next->info.getbname(),bookname);

    if(y!=0)                         //book not found. shifting to next node
     ptr=ptr->next;

    else                             //condition when book is found
    {
     b=ptr->next->info;

     if(ptr->next->next==NULL)
     {
      ptr->next=NULL;
     }

     else
     {
      ptr->next=ptr->next->next;
      ptr=ptr->next;
     }
    }
   }

  }
 }

 if(y!=0)
 {
  cout<<"\n    Required book not available in the library\n";
 }

 else
 {
  //deleted that copy of book from linked list
  cout<<"\n    Book record removed from library\n";
 }

}




void updaterec()
{
 char bookname[30];
 int y=1;       //y will be 1 if book is not found

 cout<<"\n    Enter the name of the book whose details you want to update\n    ";
 fflush(stdin);
 cin.getline(bookname,30);
 ptr=start;

 while(ptr!=NULL&&y!=0)
 {
  y=strcmpi(ptr->info.getbname(),bookname);

  if(y==0)
  {
   cout<<"\n    The details of the book are\n";
   ptr->info.displaybook();
   cout<<"\n    Enter new details of the book\n";
   ptr->info.bookinfoinput();
   cout<<"\n\n\n    Record updated\n";
   getchar();
  }
  ptr=ptr->next;
 }

 if(y!=0)
 {
  cout<<"\n    Book not found\n";
  getchar();
 }

}




void lpasschange()
{
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode = 0;

    fstream fp;
    char lpass[25],lpass2[25];

    system("cls");
    fflush(stdin);

    GetConsoleMode(hStdin, &mode);
    SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));

    cout<<"\n\n\tEnter new password for librarian\n\t";
    cin.getline(lpass,25);

    cout<<"\n\n\tEnter again\n\t";
    cin.getline(lpass2,25);

    if(strcmp(lpass,lpass2)==0)
    {
        fp.open("lpass.dat",ios::out|ios::trunc);
        fp.write((char *)(&lpass), 25);
        fp.close();

        cout<<"\n\tpassword changed successfully";
    }

    else
    {
        cout<<"\n\tPasswords do not match\n\tPassword change failure";
    }

    getchar();
}




void spasschange()
{
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode = 0;

    fstream fp;
    char spass[25],spass2[25];

    system("cls");
    fflush(stdin);

    GetConsoleMode(hStdin, &mode);
    SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));

    cout<<"\n\n\tEnter new password for student account\n\t";
    cin.getline(spass,25);

    cout<<"\n\n\tEnter again\n\t";
    cin.getline(spass2,25);

    if(strcmp(spass,spass2)==0)
    {
        fp.open("spass.dat",ios::out|ios::trunc);
        fp.write((char *)(&spass), 25);
        fp.close();

        cout<<"\n\tpassword changed successfully";
    }

    else
    {
        cout<<"\n\tPasswords do not match\n\tPassword change failure";
    }

    getchar();
}




void librarianlog()
{
 int x;

 do
 {
  system("cls");
  cout<<"\n    LIBRARY MENU\t\t\t\t\tLOGGED IN LIBRARIAN\n";
  cout<<"\n    1). Enter  1 to display the details of all books in the library";
  cout<<"\n    2). Enter  2 to display the details of all issued books";
  cout<<"\n    3). Enter  3 to add new book to the library";
  cout<<"\n    4). Enter  4 to issue a book";
  cout<<"\n    5). Enter  5 to return an issued book";
  cout<<"\n    6). Enter  6 to remove the record of any book from the library ";
  cout<<"\n    7). Enter  7 to update the details of any book in the library";
  cout<<"\n    8). Enter  8 to change administrator password";
  cout<<"\n    9). Enter  9 to change student password";
  cout<<"\n   10). Enter 10 to Log off";

  cout<<"\n\n    Enter your choice\n    ";
  cin>>x;

  system("cls");

  switch(x)
  {
   case 1:displaylibraryrec();
	  break;

   case 2:displayissuerec();
	  break;

   case 3:cout<<"\n    Enter details of the new book\n";
		  b.bookinfoinput();
          addnew(b);

	      cout<<"\n    Book succesfully added to the library\n";
	      break;

   case 4:issuebook();
	  break;

   case 5:returnbook();
	  break;

   case 6:if(start!=NULL)
	         removerec();

	      else
	         cout<<"\n    Currently, there is no book in the library\n";

             getchar();
	      break;

   case 7:if(start!=NULL)
	          updaterec();

	      else
	          cout<<"\n    Currently, there is no book in the library\n";

	          getchar();

	      break;

   case 8:lpasschange();
      break;

   case 9:spasschange();
      break;

   case 10:cout<<"\n\n\n\t\t\tLogging off...\n";
	  break;

   default:cout<<"\n    Invalid input\n    Please enter again";

  }

  getchar();

 }while(x!=10);

}




void studentlog()
{
 int x;
 do
 {
  system("cls");
  cout<<"\n    LIBRARY MENU\t\t\t\t\tLOGGED IN STUDENT\n";
  cout<<"\n    1). Enter 1 to display the details of all books in the library";
  cout<<"\n    2). Enter 2 to display the details of all issued books";
  cout<<"\n    3). Enter 3 to Log off";

  cout<<"\n\n    Enter your choice\n    ";
  cin>>x;

  system("cls");

  switch(x)
  {
   case 1:displaylibraryrec();
	  break;

   case 2:displayissuerec();
	  break;

   case 3:cout<<"\n\n\n\t\t\tLogging off...\n";
	  break;

   default:cout<<"\n    Invalid input\n    Please enter again";

  }

  getchar();
 }while(x!=3);

}



void LMA()
{
 int x,y,j,k;
 fstream fp;
 char password[25],lpass[25],spass[25];

 HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
 DWORD mode = 0;

 do
 {
  system("cls");

  do
  {
   cout<<"\n    LIBRARY MANAGEMENT APPLICATION\n";
   cout<<"\n    1). Enter 1 to login as Librarian";
   cout<<"\n    2). Enter 2 to login as student";
   cout<<"\n    3). Enter 3 to Exit";

   cout<<"\n\n    Enter your choice\n    ";
   cin>>x;
   system("cls");

   if(x!=1&&x!=2&&x!=3)
   {
    cout<<"\n    Invalid input\n    Please Enter again";
    getchar();
    system("cls");
   }

  }while(x!=1&&x!=2&&x!=3);


  if(x==1)
  {
   y=0;

    fp.open("lpass.dat",ios::in);
    fp.read((char *)(&lpass), 25);
    fp.close();

   do
   {
    system("cls");
    cout<<"\n    LIBRARY MANAGEMENT APPLICATION\t\t\tLIBRARIAN LOG IN";
    fflush(stdin);


        GetConsoleMode(hStdin, &mode);
        SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));

        cout<<"\n    Enter the password \n";
        y++;
        cin.getline(password,25);

        if(strcmp(password,lpass)==0)
        {
             y=0;
             librarianlog();
        }

        else if(y!=3)
        {
            cout<<"\n    invalid password\n    Please enter again";
            getchar();
        }

        else
        {

            cout<<"\n    password incorrectly entered maximum no. of times\n";
            getchar();
            x=3;
        }

   }while(y!=0&&x!=3);

   //end of if
  }


  else if(x==2)
  {

   y=0;

    fp.open("spass.dat",ios::in);
    fp.read((char *)(&spass), 25);
    fp.close();

   do
   {
    system("cls");
    cout<<"\n    LIBRARY MANAGEMENT APPLICATION\t\t\tSTUDENT LOG IN";
    fflush(stdin);


        GetConsoleMode(hStdin, &mode);
        SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));

        cout<<"\n    Enter the password \n";
        y++;
        cin.getline(password,25);

        if(strcmp(password,spass)==0)
        {
             y=0;
             studentlog();
        }

        else if(y!=3)
        {
            cout<<"\n    invalid password\n    Please enter again";
            getchar();
        }

        else
        {

            cout<<"\n    password incorrectly entered maximum no. of times\n";
            getchar();
            x=3;
        }

   }while(y!=0&&x!=3);

   //end of else if
  }

  //end of main do while loop
 }while(x!=3);

 //end of LMA function
}





int main()
{
 int y=0;
 fstream fp,fpi;
 system("cls");

 //Introduction
 cout<<"\n\n\n\n\n\n\n\t\t\tWelcome to the\n\t\tLIBRARY MANAGEMENT APPLICATION\n\n\n\n\t\t\tdeveloped by\n\t\t   HO DEVELOPERS PVT. LTD.\n";
 getchar();
 system("cls");

 //reading text file library.dat
 fp.open("library.dat",ios::in);      //opening file in input mode

 while(fp.read((char*)&b,sizeof(book)))
 {
  if(y==0)
  {
   y=1;
   //in this case start has not been pointed to any location
   ptr=new node;
   start=ptr;
   ptr->info=b;
   ptr->next=NULL;
  }

  else
  {
   ptr->next=new node;
   ptr=ptr->next;
   ptr->next=NULL;
   ptr->info=b;
  }

 }


 fp.close();


 //reading text file issuerec.dat

 fpi.open("issuerec.dat",ios::in);

 y=0;
 while(fpi.read((char*)&i,sizeof(issuedbook)))
 {
  if(y==0)
  {
   y=1;
   //in this case starti has not been pointed to any location
   ptri=new nodei;
   starti=ptri;
   ptri->info=i;
   ptri->next=NULL;
  }

  else
  {
   ptri->next=new nodei;
   ptri=ptri->next;
   ptri->next=NULL;
   ptri->info=i;
  }

 }

 fpi.close();


 LMA();

 cout<<"\n\n\n\t\t\tExiting...\n";
 getchar();


 ofstream ofp,ofpi;

 //writing text file library.dat
 ofp.open("library.dat",ios::in|ios::trunc);

 if(start!=NULL)
 {
  ptr=start;

  while(ptr!=NULL)
  {
   ofp.write((char*)&(ptr->info),sizeof(book));
   ptr=ptr->next;
  }

 }

 ofp.close();

 //writing text file issuerec.dat
 ofpi.open("issuerec.dat",ios::in|ios::trunc);

 if(starti!=NULL)
 {
  ptri=starti;

  while(ptri!=NULL)
  {
   ofpi.write((char*)&(ptri->info),sizeof(issuedbook));
   ptri=ptri->next;
  }

 }


 ofpi.close();

 //closing message
 system("cls");
 cout<<"\n\n\n\n\t\t\t   A project by\n\n\n";
 cout<<"\t\t\tHO DEVELOPERS PVT. LTD.\n\n";
 cout<<"\t\t\tVishal Sharma\n\t\t\tAkash Gupta\n\t\t\tArjun Singhal\n\t\t\tAkshit Mittal";
 getchar();
 system("cls");
 cout<<"\n\n\n\n\n\n\n\t\t\tHope you like it";
 getchar();


 return 0;

 //end of main function
}
