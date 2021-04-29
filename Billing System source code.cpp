// Billing System Project in C++

#include<iostream>
#include<iomanip>
#include<conio.h>
#include<stdio.h>
#include<fstream>
using namespace std;
fstream file,file1;
class product
{
 int pno;
 string name;
 float price,qty,tax,dis;
 public:
	void create();
	void show();
	void write();
	void display();
	void admin();
	void search(int n);
	void modify(int n);
	void del(int n);
	void order();
	void menu();
};
	void product::create()
	{
	 cout<<"\n\n Please Enter The Product No. of The Product ";
	 cin>>pno;
	 cout<<"\n\n Please Enter The Name of The Product ";
	 cin>>name;
	 cout<<"\n\n Please Enter The Price of The Product ";
	 cin>>price;
	 cout<<"\n\n Please Enter The Discount (%) ";
	 cin>>dis;
	 }
	void product::show()
	{
	 cout<<"\nThe Product No. of The Product : "<<pno;
	 cout<<"\nThe Name of The Product : "<<name;
	 cout<<"\nThe Price of The Product : "<<price;
	 cout<<"\nDiscount : "<<dis<<"%";
	 }
	void product::write()
   {
    file.open("shop.txt",ios::out|ios::app);
    create();
    file<<" "<<pno<<" "<<name<<" "<<price<<" "<<dis<<"\n";
    file.close();
    cout<<"\n\nThe Product Has Been Created ";
    getch();
   }
	void product::display()
	{
    system("cls");
    cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
    file.open("shop.txt",ios::in);
    if(!file)
    admin();
    file>>pno>>name>>price>>dis;
    while(!file.eof())
	{
	 show();
	 cout<<"\n\n====================================\n";
	 file>>pno>>name>>price>>dis;
	 }
    file.close();
    getch();
	}
	void product::search(int n)
	{
	int found=0;
    file.open("shop.txt",ios::in);
    if(!file)
    admin();
    file>>pno>>name>>price>>dis;
    while(!file.eof())
	{
	 if(pno == n)
		{
		 system("cls");
		 show();
		 found=1;
		}
		file>>pno>>name>>price>>dis;
	}
    file.close();
	if(found == 0)
 	cout<<"\n\nrecord not exist";
    getch();
	}
	void product::modify(int n)
	{
    int found=0;
    system("cls");
    cout<<"\n\n\tTo Modify ";
    file.open("shop.txt",ios::in);
    if(!file)
    admin();
    file1.open("shop1.txt",ios::out|ios::app);
    file>>pno>>name>>price>>dis;
    while(!file.eof())
	{
	    if(pno == n)
		{
		    show();
		    cout<<"\n\n Please Enter The New Details of Product"<<endl;
		    create();
		    file1<<" "<<pno<<" "<<name<<" "<<price<<" "<<dis<<"\n";
		    cout<<"\n\n\t Record Updated";
		    found=1;
		}
		else
		file1<<" "<<pno<<" "<<name<<" "<<price<<" "<<dis<<"\n";
		file>>pno>>name>>price>>dis;
	}
    file.close();
    file1.close();
    remove("shop.txt");
    rename("shop1.txt","shop.txt");
    if(found==0)
    cout<<"\n\n Record Not Found ";
    getch();
	}
	void product::del(int n)
   {
    int found=0;
    file.open("shop.txt",ios::in);
    if(!file)
    admin();
    file1.open("shop1.txt",ios::out);
    file>>pno>>name>>price>>dis;
    while(!file.eof())
	{
	    if(pno == n)
		{

		    cout<<"\n\n\t Record Deleted";
		    found=1;
		}
		else
		file1<<" "<<pno<<" "<<name<<" "<<price<<" "<<dis<<"\n";
		file>>pno>>name>>price>>dis;
	}
    file.close();
    file1.close();
    remove("shop.txt");
    rename("shop1.txt","shop.txt");
    if(found==0)
    cout<<"\n\n Record Not Found ";
    getch();
    }
    void product::menu()
    {
    system("cls");
    file.open("shop.txt",ios::in);
    cout<<"\n\n\t\tProduct MENU\n\n";
	cout<<"====================================================\n";
	cout<<"P.NO.\t\tNAME\t\tPRICE\n";
	cout<<"====================================================\n";
	file>>pno>>name>>price;
	while(!file.eof())
	{
	   cout<<pno<<"\t\t"<<name<<"\t\t"<<price<<"\n";
	   file>>pno>>name>>price>>dis;
	}
    file.close();
	}
   	void product::order()
   	{
    int  order_arr[50],quan[50],c=0;
    float amt=0,damt=0,total=0;
    char ch;
    file.open("shop.txt",ios::in);
    if(file)
    {
    file.close();
    menu();
    cout<<"\n============================";
    cout<<"\n    PLACE YOUR ORDER";
    cout<<"\n============================\n";
    do{
	 cout<<"\n\nEnter The Product No. Of The Product : ";
	 cin>>order_arr[c];
	 cout<<"\nQuantity in number : ";
	 cin>>quan[c];
	 c++;
	 cout<<"\nDo You Want To Order Another Product ? (y/n)";
	 cin>>ch;
    }while(ch=='y' ||ch=='Y');
    cout<<"\n\nThank You For Placing The Order";getch();system("cls");
      cout<<"\n\n********************************INVOICE************************\n";
      cout<<"\nPr No.\tPr Name\tQuantity \tPrice \tAmount \tAmount after discount\n";
      for(int x=0;x<=c;x++)
	{
		 file.open("shop.txt",ios::in);
		 file>>pno>>name>>price>>dis;
		  while(!file.eof())
			{
			if(pno == order_arr[x])
				{
				 amt=price*quan[x];
				 damt=amt-(amt/100*dis);
				 cout<<"\n"<<order_arr[x]<<"\t"<<name<<"\t"<<quan[x]<<"\t\t"<<price<<"\t"<<amt<<"\t\t"<<damt;
				 total+=damt;
				}
			file>>pno>>name>>price>>dis;
			}

		 file.close();
	 }
       cout<<"\n\n\t\t\t\t\tTOTAL = "<<total;
    getch();
	}
    }
	void product::admin()
	{
  	system("cls");
  	int choice;
  	cout<<"\n\n\n\tADMIN MENU";
  	cout<<"\n\n\t1.CREATE PRODUCT";
  	cout<<"\n\n\t2.DISPLAY ALL PRODUCTS";
  	cout<<"\n\n\t3.Search PRODUCT ";
  	cout<<"\n\n\t4.MODIFY PRODUCT";
  	cout<<"\n\n\t5.DELETE PRODUCT";
  	cout<<"\n\n\t6.VIEW PRODUCT MENU";
  	cout<<"\n\n\t7.BACK TO MAIN MENU";
  	cout<<"\n\n\tPlease Enter Your Choice (1-7) ";
  	cin>>choice;
  	switch(choice)
  	{
    case 1: system("cls");
	      write();
	      break;
    case 2: display();break;
    case 3:
	       int num;
	       system("cls");
	       cout<<"\n\n\tPlease Enter The Product No. ";
	       cin>>num;
	       search(num);
	       break;
      case 4:
	       system("cls");
	       cout<<"\n\n\tPlease Enter The Product No. ";
	       cin>>num;
		   modify(num);
	  break;
      case 5:
	       system("cls");
	       cout<<"\n\n\t\t\t\tDelete Record";
	       cout<<"\n\n Please Enter The Product No. ";
	       cin>>num;
	  		del(num);
	  break;
      case 6: menu();
		getch();
      case 7: break;
      default:cout<<"\a";admin();
   	}
	}
main()
{
  product p;
  h:
  int choice;
	  system("cls");
	  cout<<"\n\n\n\tMAIN MENU";
	  cout<<"\n\n\t01. CUSTOMER";
	  cout<<"\n\n\t02. ADMIN";
	  cout<<"\n\n\t03. EXIT";
	  cout<<"\n\n\tPlease Select Your Option (1-3) ";
	  cin>>choice;
	  switch(choice)
	  {
		 case 1: system("cls");
			     p.order();
			   getch();
			   break;
		  case 2: p.admin();
			    break;
		  case 3:exit(0);
		  default :cout<<"\a";
	  }
	  goto h;
}
