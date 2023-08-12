#include<iostream>
#include<conio.h>
#include<fstream> //using for file function//
using namespace std;
class Billing //class name//
{
private: //class billing declare as private member//
int pcode;
float price,discount;
string pname; //data member//
public: //class billing declare as public member//
void menu() //member function//
{
system("cls"); //for open new clear screen//
int cho; //data member//
cout<<"\n \t\t\tSuper Market \n";
cout<<"\n 1.Admin";
cout<<"\n 2.Customer";
cout<<"\n 3.Exit \n";
cout<<"\n Enter your choice : ";
cin>>cho; //to get the data of the choice//
switch(cho) //switch case//
{
case 1:
admin(); //it show the admin member funcution
detail//
case 2:
customer(); //it show the admin member
funcution detail//
case 3:
exit(0); //exit from our project
default:
cout<<"\n ----Invalid value----";
}
getch();
}
void admin();
void customer();
void add();
void search();
void modify();
void deletee();
void display();
void list();
void Stockbill(); //all these are member function used
in our project//
};
void Billing::admin() //In this line admin member function
used as outside class//
{
k:
system("cls");
int ch;
cout<<"\n \t\t ADMIN \n";
cout<<"\n 1.Add Products";
cout<<"\n 2.Delete Products";
cout<<"\n 3.Modify Products";
cout<<"\n 4.Search Products";
cout<<"\n 5.Show Products";
cout<<"\n 6.Return \n";
cout<<"\n Enter your choice : ";
cin>>ch;
switch(ch)
{
case 1:
add();
break;
case 2:
deletee();
break;
case 3:
modify();
break;
case 4:
search();
break;
case 5:
display();
break;
case 6:
menu();
default:
cout<<"\n ----Invalid----";
}
getch();
goto k; //To bring back to admin member function after
using member function inside switch case//
}
void Billing::customer() //In this line customer member
function used as outside class//
{
k:
system("cls");
int ch;
cout<<"\n \t\t CUSTOMER \n";
cout<<"\n 1.Billing";
cout<<"\n 2.Return";
cout<<"\nEnter your choice : ";
cin>>ch;
switch(ch)
{
case 1:
Stockbill();
break;
case 2:
menu();
default:
cout<<"\n ----Invalid Value----";
}
getch();
goto k;
}
void Billing::add()
{
k:
system("cls");
fstream file;
int pc,found=0;
float p,d;
string pn;
cout<<"\n \t\t Add New Product \n";
cout<<"\n Product Code :";
cin>>pcode;
cout<<"\n Product Name :";
cin>>pname;
cout<<"\n price :";
cin>>price;
cout<<"\n Discount in % :";
cin>>discount;file.open("product.txt",ios::in);
if(!file)
{
file.open("product.txt",ios::app|ios::out);
file<<" "<<pcode<<" "<<pname<<" "<<price<<""<<discount<<"\n";
file.close();
}
else
{
file>>pc>>pn>>p>>d;
while(!file.eof())
{
if(pc == pcode)
{
found++;
}
file>>pc>>pn>>p>>d;
}
file.close();
if(found==1)
goto k;
else
{
file.open("product.txt",ios::app|ios::out);
file<<" "<<pcode<<" "<<pname<<" "<<price<<""<<discount<<"\n";
file.close();
}
}
cout<<"\n \t\t Product Added ";
}
void Billing::search()
{
system("cls");
fstream file;
int p_pc,found=0;
cout<<"\n \t\t Search Product \n";
cout<<"\n Product code : ";
cin>>p_pc;
file.open("product.txt",ios::in);
if(!file)
{
cout<<"\n File opening error";
}
else
{
file>>pcode>>pname>>price>>discount;
while(!file.eof())
{
if(p_pc == pcode)
{
system("cls");
cout<<"\n \t\t Searched Product \n";
cout<<"\n Product code : "<<pcode;
cout<<"\n Name : "<<pname;
cout<<"\n Price : "<<price;
cout<<"\n Discount : "<<discount<<"%";
found++;
}
file>>pcode>>pname>>price>>discount;
}
file.close();
if(found == 0)
cout<<"\n Product not found";
}
}
void Billing::modify()
{
system("cls");
fstream file,file1;
int p_pc,found=0,pc;
float p,d;
string pn;
cout<<"\n \t\t Modify Product \n";
cout<<"\n Product code : ";
cin>>p_pc;
file.open("product.txt",ios::in);
if(!file)
{
cout<<"\n File opening error";
}
else
{
file1.open("product1.txt",ios::app|ios::out);
file>>pcode>>pname>>price>>discount;
while(!file.eof())
{
if(p_pc==pcode)
{
cout<<"\n New Product code : ";
cin>>pc;
cout<<"\n Name : ";
cin>>pn;
cout<<"\n Price : ";
cin>>p;
cout<<"\n Discount : ";
cin>>d;
file1<<" "<<pc<<" "<<pn<<" "<<p<<" "<<d<<"\n";
cout<<"\n \t\t Product Modified \n";
found++;
}
else
{
file1<<" "<<pcode<<" "<<pname<<" "<<price<<""<<discount<<"\n";
}
file>>pcode>>pname>>price>>discount;
}
file.close();
file1.close();
remove("product.txt");
rename("product1.txt","product.txt");
if(found == 0)
cout<<"\n Product not found";
}
}
void Billing::deletee()
{
system("cls");
fstream file,file1;
int p_pc,found=0;
cout<<"\n \t\t Delete Product \n";
cout<<"\n Product Code: ";
cin>>p_pc;
file.open("product.txt",ios::in);
if(!file)
{
cout<<"\n File opening error";
}
else
{
file1.open("product1.txt",ios::app|ios::out);
file>>pcode>>pname>>price>>discount;
while(!file.eof())
{
if(pcode == p_pc)
{
cout<<"\n Product Deleted ";
found++;
}
else
{
file1<<" "<<pcode<<" "<<pname<<" "<<price<<""<<discount<<"\n";
}
file>>pcode>>pname>>price>>discount;
}
file.close();
file1.close();
remove("product.txt");
rename("product1.txt"
,
"product.txt");
if(found==0)
cout<<"\n Product not found";
}
}
void Billing::display()
{
system("cls");
fstream file;
cout<<"\n \t\t Show Products \n";
file.open("product.txt",ios::in);
if(!file)
{
cout<<"\n File opening error";
}
else
{
cout<<"\n Code\t\tName\t\tPrice\t\tDiscount %";
file>>pcode>>pname>>price>>discount;
while(!file.eof())
{
cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\t\t"<<discount;
file>>pcode>>pname>>price>>discount;
}
file.close();
}
}
void Billing::list()
{
fstream file;
file.open("product.txt"
,ios::in);
cout<<"----------------------------------------------------------------------------";
cout<<"\nP.no \t\t Name \t\t Price \n";
cout<<"----------------------------------------------------------------------------\n";
file>>pcode>>pname>>price>>discount;
while(!file.eof())
{
cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
file>>pcode>>pname>>price>>discount;
}
file.close();
}
void Billing::Stockbill()
{
system("cls");
fstream file;
char ch;
string cname;
int o_c[100],o_q[100],c=0;
float amt=0,dis=0,tot=0;
cout<<"\n \t\t Invoice \n";
file.open("product.txt"
,ios::in);
if(!file)
{
cout<<"\n Database is Empty \n";
}
else
{
file.close();
list();
cout<<"\n----------------------------------------------------------------------------\n";
cout<<"\nEnter the Name of Customer:";
cin>>cname;
cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
cout<<"\nPlace your order";
cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
do
{
k:
cout<<"\n Product Code : ";
cin>>o_c[c];
cout<<"\n Product Quantity : ";
cin>>o_q[c];
for(int i=0;i<c;i++)
{
if(o_c[c]==o_c[i])
{
cout<<"\n Duplicate Product code";
goto k;
}
}
c++;
cout<<"\n do you want to ADD another product(y/n):";
cin>>ch;
}while(ch =='y' || ch =='Y');
system("cls");
cout<<"\n============================SuperMarketBilling=====================================\n";
cout<<" Name of Customer: "<<cname;
cout<<"\n Customer Care: 9874563210";
cout<<"\n===================================================================================\n";
cout<<"\n Pr.no \tPr Name \tQuantity\tPrice \tAmount\tAfter Discount \n";
for(int i=0;i<c;i++)
{
file.open("product.txt",ios::in);
file>>pcode>>pname>>price>>discount;
while(!file.eof())
{
if(pcode == o_c[i])
{
amt= price*o_q[i];
dis= amt-(amt/100*discount);
tot+=dis;
cout<<"\n"<<o_c[i]<<"\t"<<pname<<"\t\t"<<o_q[i]<<"\t\t"<<price<<"\t"<<amt<<"\t"<<dis;
}
file>>pcode>>pname>>price>>discount;
}
file.close();
}
cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
cout<<" Total
Amount :Rs."<<tot;
cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}
}
int main()
{
Billing b;//class billing indicate as b//
char ch;//data member
string eid,pass;
cout<<"\n \t\tLogin System";
cout<<"\n Email id : ";
cin>>eid;
cout<<" Password : ";
for(int i=1;i<=6;i++)
{
ch= getch();
pass +=ch;
cout<<"*";
}
if(eid ==
"supermarket@gmail.com" && pass =="123456")
{
b.menu();
}
else
{
cout<<"\n ----Invalid Email id & Password----";
}
return 0;
}
