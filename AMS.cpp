#include<fstream.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>


class flight
{
long flno;
char destination[100];
long psngb;
long psnge;
char deptime[20];
public:
void getdata();
void showdata();
int check1(char ds[]);
int check2(long fn);
int check3(long pnb);
int check4(long pne);
int check5(char dpt[]);
void edit();
};




void flight::getdata()
{
cout<<endl<<"ENTER THE FLIGHT NO.                          :";
cin>>flno;
cout<<endl<<"ENTER THE DESTINATION                         :";
gets(destination);
cout<<endl<<"ENTER THE NO. OF PASSENGERS IN BUSINESS CLASS :";
cin>>psngb;
cout<<endl<<"Enter THE NO. OF PASSENGERS IN ECONOMY CLASS  :";
cin>>psnge;
cout<<endl<<"ENTER THE DEPARTURE TIME                      :";
gets(deptime);
cout<<endl<<"\n\n\t!!YOUR RECORD IS UPDATED!!\n";

}



void flight::showdata()
{
cout<<"\n\nFLIGHT NUMBER                :"<<flno;
cout<<"\nDESTINATION                  :"<<destination;
cout<<"\nPASSENGERS IN BUSINESS CLASS :"<<psngb;
cout<<"\nPASSENGERS IN ECONOMY CLASS  :"<<psnge;
cout<<"\nDEPARTURE TIME               :"<<deptime;
}

int flight::check1(char ds[])
{
if(strcmp(ds,destination)==0)
 return 1;
 else
 return 0;
 }

 int flight::check2(long fn)
 {
 if(fn==flno)
 return 1;
 else
 return 0;
 }

 int flight::check3(long pnb)
 {
  if(pnb==psngb)
  return 1;
  else
  return 0;
  }

 int flight::check4(long pne)
 {
 if(pne==psnge)
 return 1;
 else
 return 0;
}

int flight::check5(char dpt[])
{
if(strcmp(dpt,deptime)==0)
return 1;
else
return 0;
}

void flight::edit()
{
char ch;
do{
cout<<"DETAILS OF RECORD:";
showdata();
cout<<"\n\nPRESS A IF YOU WANT TO CHANGE FLIGHT NO\n";
cout<<"PRESS B IF YOU WANT TO CHANGE DESTINATION";
cout<<"\nPRESS C IF YOU WANT TO CHANGE NO. OF PASSENGERS IN BUSINESS CLASS";
cout<<"\nPRESS D IF YOU WANT TO CHANGE NO. OF PASSENGERS IN ECONOMY CLASS";
cout<<"\nPRESS E IF YOU WANT TO CHANGE THE DEPARTURE TIME";
cout<<"\nPRESS F IF YOU WANT NO MORE CHANGE";
cout<<"\nENTER YOUR CHOICE";
ch=getche();
switch (ch)
{
 case'A':
 case'a':cout<<"\nENTER NEW FLIGHT NO.                         :";
			cin>>flno;
			break;
 case'B':
 case'b':cout<<"\nENTER NEW DESTRINATION                       :";
			cin>>destination;
			break;
 case'C':
 case'c':cout<<"\nENTER NEW PASSENGERS IN BUSINESS CLASS       :";
			cin>>psngb;
			break;
 case'D':
 case'd':cout<<"\nENTER NEW NO. OF PASSENGERS IN ECONOMY CLASS :";
			cin>>psnge;
			break;
 case'E':
 case'e':cout<<"\nENTER NEW SDEPARTURE TIME                    :";
			cin>>deptime;
			break;
case'F':
case'f':  break;
 default: cout<<"\tWRONG OPTION !!TRY AGIAN!!";
 }
 }while(ch!='F' && ch!='f');
 }




 void append()
 {
 flight f;
 cout<<"\n \tENTER THE DELATILS OF THE NEW RECORD:\n";
 f.getdata();
 fstream f1;
 f1.open("AIRWAYS.DAT",ios::binary|ios::app);
 f1.write((char*) &f, sizeof(f));
 f1.close();
 }




 void DisplayAll()
 {
 flight f;
 fstream f1;
 f1.open("AIRWAYS.DAT",ios::binary|ios::in);
 while(f1.read((char*) &f, sizeof(f)))
 {
 f.showdata();
 }
 f1.close();
 }




 void search1()
 {
 char ds[50];
 flight f;
 int found=0;
 cout<<"\n\nENTER THE DESTINATION:";
 gets(ds);
 fstream f1;
 f1.open("AIRWAYS.DAT",ios::binary|ios::in);
 while(f1.read((char*) &f, sizeof(f)));
 {
 if(f.check1(ds)==1)
 {
 found++;
 f.showdata();
 }
 }
 f1.close();
 if(found==0)
 cout<<"\n\nNO MATCH FOUND\n\n";
 else
 cout<<"\n\nTOTAL"<<found<<"RECORD(s) FOUND";
 }





 void search2()
 {
 long fn;
 flight f;
 int found=0;
 cout<<"\n\nENTER THE FIGHT NO. :";
 cin>>fn;
 fstream f1;
 f1.open("AIRWAYS.DAT",ios::binary|ios::in);
 while(f1.read((char*) &f, sizeof(f)));
 {
 if(f.check2(fn)==1)
 {
 found++;
 f.showdata();
 }
 }
 f1.close();
 if(found==0)
 cout<<"\n\nNO MATCH FOUND\n\n";
 else
 cout<<"\n\nTOTAL"<<found<<"RECORD(s) FOUND";
 }




 void search3()
 {
 long pnb;
 flight f;
 int found=0;
 cout<<"\n\nENTER THE NO. OF PASSENGERS IN BUSINESS CLASS:";
 cin>>pnb;
 fstream f1;
 f1.open("AIRWAYS.DAT",ios::binary|ios::in);
 while(f1.read((char*) &f, sizeof(f)));
 {
 if(f.check3(pnb)==1)
 {
 found++;
 f.showdata();
 }
 }
 f1.close();
 if(found==0)
 cout<<"\n\nNO MATCH FOUND\n\n";
 else
 cout<<"\n\nTOTAL"<<found<<"RECORD(s) FOUND";
 }




 void search4()
 {
 long pne;
 flight f;
 int found=0;
 cout<<"\n\nENTER THE NO. OF PASSENGERS IN ECONOMY CLASS:";
 cin>>pne;
 fstream f1;
 f1.open("AIRWAYS.DAT",ios::binary|ios::in);
 while(f1.read((char*) &f, sizeof(f)));
 {
 if(f.check4(pne)==1)
 {
 found++;
 f.showdata();
 }
 }
 f1.close();
 if(found==0)
 cout<<"\n\nNO MATCH FOUND\n\n";
 else
 cout<<"\n\nTOTAL"<<found<<"RECORD(s) FOUND";
 }





 void search5()
 {
 char dpt[50];
 flight f;
 int found=0;
 cout<<"\n\nENTER THE DEPARTURE TIME:";
 gets(dpt);
 fstream f1;
 f1.open("AIRWAYS.DAT",ios::binary|ios::in);
 while(f1.read((char*) &f, sizeof(f)));
 {
 if(f.check5(dpt)==1)
 {
 found++;
 f.showdata();
 }
 }
 f1.close();
 if(found==0)
 cout<<"\n\nNO MATCH FOUND\n\n";
 else
 cout<<"\n\nTOTAL"<<found<<"RECORD(s) FOUND";
 }




 void modify()
 {
 char ds[50];
 flight f;
 int modified=0;
 cout<<"\n\nENTER THE DESTINATION:";
 gets(ds);
 fstream f1,f2;
 f1.open("AIRWAYS.DAT",ios::binary|ios::in);
 f2.open("TEMP.DAT",ios::binary|ios::out);
 while(f1.read((char*) &f, sizeof(f)));
 {
 if(f.check1(ds)==1)
 {
 modified++;
 f.edit();
 }
 f2.write((char*) &f, sizeof(f));
 }
 f1.close();
 f2.close();
 if(modified==0)
 {
 cout<<"\n\nNO MATCH FOUND!!\n\n";
 }
 else
 {
 remove("AIRWAYS.DAT");
 rename("TEMP.DAT","AIRWAYS.DAT");
 }
 }




 void del()
 {
	char ds[50];
	flight f;
	int deleted=0;

	cout<<"\n\nENTER THE DESTINATION: ";
	gets(ds);

	fstream f1,f2;
	f1.open("AIRWAYS.DAT",ios::binary|ios::in);
	f2.open("TEMP.DAT",ios::binary|ios::out);

	while(f1.read((char*) &f, sizeof(f)))
	{
		if(f.check1(ds)==1)
			{
			deleted++;
			}
		else
		{
			f2.write((char*) &f, sizeof(f));
		}
	}
	f1.close();
	f2.close();

		if(deleted==0)
		  {
			cout<<"\n\n NO MATCH FOUND!! \n\n";
			}
 else
 {
 remove("AIRWAYS.DAT");
 rename("TEMP.DAT","AIRWAYS.DAT");
 }
 }





 void main(){
 char choice;
 do{
 clrscr();
		cout<<"===========================AIRWAYS MANAGEMENT SYSTEM===========================\n";
		cout<<"\n\t\t\t\t MAIN MENU";
		cout<<"\n\n\t01. NEW RECORD";
		cout<<"\n\n\t02. DISPLAY ALL RECORDS";
		cout<<"\n\n\t03. SEARCH BY DESTINATION";
		cout<<"\n\n\t04. SEARCH BY FLIGHT NO.";
		cout<<"\n\n\t05. PASSENGERS(BUSINESS)";
		cout<<"\n\n\t06. PASSENGERS(ECONOMY)";
		cout<<"\n\n\t07. DEPARTURE TIME";
		cout<<"\n\n\t08. MODIFY A RECORD";
		cout<<"\n\n\t09. DELETE A RECORD";
		cout<<"\n\n\t\t\tPRESS Z IF YOU WANT TO REFRESH";
		cout<<"\n\n\tSelect Your Option (1-8) ";
		choice=getch();
		switch(choice)
		{
		 case '1': append();
					  break;
		 case '2':DisplayAll();
					  break;
		 case '3':search1();
					 break;
		 case '4':search2();
					 break;
		 case '5':search3();
					 break;
		 case '6':search4();
					 break;
		 case '7':search5();
					 break;
		 case '8':modify();
					 break;
		 case '9':del();
					 break;
		 case 'Z':
		 case 'z':break;

		 default:cout<<"\n\n\tWRONG CHOICE ENTERED";
		 }
		 getch();
		 }
		 while(choice!='10');
		 }
