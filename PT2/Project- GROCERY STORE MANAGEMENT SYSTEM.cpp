//                      SECJ1023-09                           //
//               PROGRAMMING TECHNIQUE II                    //
//     PROJECT TITLE: GROCERY STORE MANAGEMENT SYSTEM       //
//      GROUP MEMBERS:
//                    RAHIM REHNUMA TAHSIN (A20EC5001)    //
//                        AFIFA JUMANA (A20EC4009)       //
//            HENRY MESHACK OKINYI ODONGO (A20EC0268)   //
//                   TASMIAH SARIF NAYNA (A20EC9109)   //

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;


class Error
{	public:
	bool classen(string);
	bool classeic(string);
	bool classeadd(string);
	bool classep(string);
	bool classedate(string);
	bool classetime(string);
};



bool Error::classen(string n)
{
	size_t found;
	found=n.find_first_of("0123456789~`!@#$%^&*(){}[]\\|+-=,""./;'<>?:");
	if (found!=string::npos)
       throw "Numeric numbers or symbols are not allowed! Please enter again. \n";
    else
     return true;
}

bool Error::classeic(string ic)
{
	int len = ic.length();
	int mm,dd,yy;
	char cmm[2],cdd[2],cyy[2];
	size_t found;
	found=ic.find_first_of ("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz~`!@#$%^&*()_+={}|:""''<>?,./;\[]\0 ");
	ic.copy(cyy,2,0);
	ic.copy(cmm,2,2);
	ic.copy(cdd,2,4);
	yy= atoi(cyy);
	mm=atoi(cmm);
	dd= atoi(cdd);

	if(len!=14)
	{
		throw " Error! Please enter again!\n";
	}
	if(yy>=10 && yy <=30)
	{
		throw "Error! Your birth year is invalid! Please enter again:";
	}
	if (mm<1||mm>12)
	{
		throw "Error! Your birth month is invalid! Please enter again:";
	}
	if (dd<1||dd>31)
	{
		throw "Error! Your birth date is invalid! Please enter again:";
	}

	if (found!=string::npos)
	{
		throw "No alphabet or special character except '-' are allowed! Please enter again:\n";
	}
	return true;

}
bool Error ::classeadd(string add)
{
	if(add.length()<30)
	{
		throw "Please enter your full addresss\n";
	}
	else
	 return true;

}
bool Error::classep(string p)
{
	int len = p.length();
	size_t found;
	found=p.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz~`!@#$%^&*()_+={}|:""''<>?,./;\[]\0 ");
	if (len<11 || len>12)
	{
		throw "Error! Please enter again!\n";
	}
	if(p.find("-",0)==string::npos||p.find("-",0)!=3)
	{
		throw "Wrong Format! Please enter based on the correct format. (60x-xxxxxxxx)\n";
	}
	if (found!=string::npos)
	{
		throw "No alphabet or special character except '-' are allowed! Please enter again.\n";
	}
	return true;
}
bool Error ::classedate(string d)
{
	int len =d.length();
	string month,year;
	char cday[2],cmonth[2],cyear[4];
	int iday, imonth, iyear;
	size_t found;
	found=d.find_first_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ~`|:""''<>?,./;\[]\!@#$%^&*()_+={}0");
	if(len<8||len>10)
	{
	   throw " Error! Please enter again!\n";
	}
	if(d.find("-",0)!=2&&d.find("-",0)!=5)
	{
	}
	else if (d.find("-",0)!=1&&d.find("-",0)!=3)
	{
	}
	else if (d.find("-",0)!=1&&d.find("-",0)!=4)
	{
	}
	else if (d.find("-",0)!=2&&d.find("-",0)!=4)
	{
		throw "Wrong Format! Please enter based on the correct format (dd-mm-yyyy)\n";
	}



 if (found!=string ::npos)
   {
	 throw "No alphabet or special character except '-' are allowed! Please enter again.\n";
   }

d.copy(cday,2,0);
iday=atoi(cday);

found=d.find_first_of("-");
month=d.substr(found+1,'-');
month.copy(cmonth,2,0);
imonth=atoi(cmonth);

found=month.find_first_of("-");
year=month.substr(found=1,'-');
year.copy(cyear,4,0);
iyear=atoi(cyear);

if (iday<1||iday>31)
 {
	 throw "Error! Please enter again following the correct range DAY(1-31) \n";
 }
if(imonth<1||imonth>12)
{
	 throw "Error! Please enter again following the correct range MONTH(1-12) \n";
}
if (imonth==1&&iday>28)
{
	 throw "February for year 2021 only have 28 days. Please enter again\n";
}
if (iyear!=2021)
{
	 throw "Wrong input! It should be 2021. Please enter again\n";

}
    return true;
}

bool Error::classetime(string t)
{
	int len = t.length();
	string min;
	char chour[2],cmin[2];
	int ihour, imin, found;
	if (len<5||len>7)
	{
		throw "Error! Please enter again!\n";
	}
	if(t.find(":",0)!=1&&t.find(":",0)!=2)
	{
		throw "Wrong Format! Please enter following the correct format (XX:XX AM/PM)\n";
	}


	t.copy(chour,2,0);
	ihour=atoi(chour);

	found=t.find_first_of(":");
	min=t.substr(found+1, ':');
	min.copy(cmin,2,0);
	imin=atoi(cmin);


	if(t.find("AM")==string::npos)
	{
		if(t.find("am")==string::npos)
		{
			if(t.find("PM")==string::npos)
			{
				if(t.find("pm")==string::npos)
				{
					throw "AM/PM was not stated!. Please enter again\n";
				}
			}
		}
	}


 if(ihour<1||ihour>12)
 {
 	throw "Error! Please enter again following the range HOUR(1-12)\n";
 }

 if(imin<0||imin>59)
 {
 	throw "Error! Please enter again following the range MINUTE(0-60)\n";
 }

 return true;
}






class info
{protected:
	string name;
	string ic;
	string phone;
	string add;
	string date;
	string time;
	char mask;
	double temperature;
	Error error;
public:
	void DateTime(ofstream &);
	string getIC(){return ic;}
	bool search(info &,string);
	friend ostream &operator<<(ostream &output,info &input);
};



void info::DateTime(ofstream &outfile)
{
	bool ff = false;
	ff=false;
	do
	{
		cout << "Time (XX:XX AM/PM):";
		try{
			getline(cin,time);
			ff=error.classetime(time);
		}
		catch(const char* msg)
		{cout << msg << endl;
		}
	} while(ff==false);
	outfile << setw(11) << left;
	outfile << date << " | ";
	outfile << setw(9) << left;
	outfile << time << " | ";

}

bool info::search(info &input, string ii)
{
	return ii==input.ic;
}




class Total{
	public:
		void displaytotal(double);
};




class Menu{
	protected:
		double price;
		Total total;
	public:
		int choice(int);
		void meats();
		void veg();
		void bread();
		void grains();
		void frozen();
		void canned();
		void dairy();
		void drinkbev();
		void dessert();
		void petf();
		void hygiene();
		void beauty();
		void pharmacy();
		void stationary();
		void pay()
		{
			total.displaytotal(price) ;
			setprice(0);

		}
		void setprice(double p){price=p;}
		int me(int &);
};

int Menu::choice(int m)
    {
		switch(m)
	{
		case 1: meats();
				break;
		case 2: veg();
				break;
		case 3:	bread();
				break;
		case 4: grains();
				break;
		case 5:	frozen();
				break;
		case 6:	canned();
				break;
		case 7: dairy();
				break;
		case 8:	drinkbev();
				break;
		case 9: dessert();
				break;
		case 10: petf();
				 break;
		case 11: hygiene();
				 break;
		case 12: beauty();
				 break;
		case 13: pharmacy();
				 break;
		case 14: stationary();
				 break;
		case 0: pay();
				break;
	}
}

int Menu::me(int &m)
{
	string str;
	ifstream mfile;
	mfile.open("Menu.txt");
	if(!mfile)
		cout << "ERROR";
	do
	{
			getline(mfile,str);
	}while(str!="MENU");
	do
	{
		getline(mfile,str);
		if(str!="MEATS")
			cout << str << endl;
	}while(str!="MEATS");
//	cin.ignore();
	do
	{
	cout << "Please enter your choice...\n---->";
	cin >> m;
	try
	{
	if(m==1)
	{

			do
			{
				getline(mfile,str);
				if(str!="VEG")
					cout << str << endl;
			}while(str!="VEG");
	}
	else if(m==2)
	{
			do
			{
				getline(mfile,str);
			}while(str!="VEG");
			do
				{
					getline(mfile,str);
					if(str!="BREAD")
						cout << str << endl;
				}while(str!="BREAD");
	}
	else if(m==3)
	{
			do
			{
				getline(mfile,str);
			}while(str!="BREAD");
			do
				{
					getline(mfile,str);
					if(str!="GRAINS")
						cout << str << endl;
				}while(str!="GRAINS");
	}
	else if(m==4)
	{
			do
			{
				getline(mfile,str);
			}while(str!="GRAINS");
			do
				{
					getline(mfile,str);
					if(str!="FROZENF")
						cout << str << endl;
				}while(str!="FROZENF");
	}
	else if(m==5)
	{
			do
			{
				getline(mfile,str);
			}while(str!="FROZENF");
			do
				{
					getline(mfile,str);
					if(str!="CANNEDF")
						cout << str << endl;
				}while(str!="CANNEDF");
	}
	else if(m==6)
	{
			do
			{
				getline(mfile,str);
			}while(str!="CANNEDF");
			do
				{
					getline(mfile,str);
					if(str!="DAIRY")
						cout << str << endl;
				}while(str!="DAIRY");
	}
	else if(m==7)
	{
			do
			{
				getline(mfile,str);
			}while(str!="DAIRY");
			do
				{
					getline(mfile,str);
					if(str!="DRINKBEV")
						cout << str << endl;
				}while(str!="DRINKBEV");
	}
	else if(m==8)
	{
			do
			{
				getline(mfile,str);
			}while(str!="DRINKBEV");
			do
				{
					getline(mfile,str);
					if(str!="DESSERT")
						cout << str << endl;
				}while(str!="DESSERT");
	}
	else if(m==9)
	{
			do
			{
				getline(mfile,str);
			}while(str!="DESSERT");
			do
				{
					getline(mfile,str);
					if(str!="PETF")
						cout << str << endl;
				}while(str!="PETF");
	}
	else if(m==10)
	{
			do
			{
				getline(mfile,str);
			}while(str!="PETF");
			do
				{
					getline(mfile,str);
					if(str!="HYGIENE")
						cout << str << endl;
				}while(str!="HYGIENE");
	}
	else if(m==11)
	{
			do
			{
				getline(mfile,str);
			}while(str!="HYGIENE");
			do
				{
					getline(mfile,str);
					if(str!="BEAUTY")
						cout << str << endl;
				}while(str!="BEAUTY");
	}
	else if(m==12)
	{
			do
			{
				getline(mfile,str);
			}while(str!="BEAUTY");
			do
				{
					getline(mfile,str);
					if(str!="PHARMACY")
						cout << str << endl;
				}while(str!="PHARMACY");
	}
	else if(m==13)
	{
			do
			{
				getline(mfile,str);
			}while(str!="PHARMACY");
			do
				{
					getline(mfile,str);
					if(str!="STATIONERY")
						cout << str << endl;
				}while(str!="STATIONERY");
	}
	else if(m==14)
	{
			do
			{
				getline(mfile,str);
			}while(str!="STATIONERY");
			do
				{
					getline(mfile,str);
					if(str!="")
						cout << str << endl;
				}while(str!="");
	}
	else if (m != 0)
		throw "The product you have entered does not exist. Please enter again (0-15)";
	}
	catch(const char* msg){
		cout << msg << endl;
	}
	}while(m<0||m>14);
	cin.ignore();
	mfile.close();
	return m;
}

void Menu::meats()
{
	int b,m;char again;
	double q;


	do{
		do{
			cout << "Choice --->";
			try{
			cin >> b;
			if(b<0||b>16)
				throw "Sorry! Your choice does not exist! Please enter again following the range (0-16)\n";
			}
			catch(const char* msg){
				cout << msg << endl;
			}
		}while(b<0||b>16);
		if(b!=0)
		{
		cout << "Quantity? (max 2) : ";
		do{
			cin.ignore();
			cin >> q;
			if(q>=3)
				cout <<"Maximum quantity is 2!\n Please enter again: ";
		}while(q>=3);

		switch(b)
		{
			case 1:  price+=(22.70*q);
					   break;
			case 2:  price+=(13.95*q);
					   break;
			case 3:  price+=(21.74*q);
					   break;
			case 4:  price+=(32.60*q);
					   break;
			case 5:  price+=(27.00*q);
					   break;
			case 6:  price+=(25.50*q);
					   break;
			case 7:  price+=(17.99*q);
					   break;
			case 8:  price+=(30.00*q);
					   break;
			case 9:  price+=(21.99*q);
					   break;
			case 10: price+=(13.45*q);
					   break;
			case 11: price+=(14.00*q);
					   break;
			case 12: price+=(25.32*q);
					   break;
			case 13: price+=(13.50*q);
					   break;
			case 14: price+=(12.70*q);
					   break;
			case 15: price+=(15.45*q);
					   break;
			case 16: price+=(14.50*q);
					   break;
			case 0:  me(m);
					 choice(m);
					   break;
		}
			cout << "Total = Rm " << price << endl;
			do
			{
				cout << "Purchase again?(Y/N)\n------>";
				try{
					cin >> again;
					if(again!='n'&&again!='N'&&again!='y'&&again!='Y')
						throw "Invalid character!!";
				}
				catch(const char* msg){
					cout << msg << endl;
				}
			}while(again!='n'&&again!='N'&&again!='y'&&again!='Y');
		}
		else if(b==0)
		{
			again=='n';
		}

	}while(again=='y'||again=='Y');

	me(m);
	choice(m);
}

void Menu::veg()
{
	int b,m;char again;
	double q;

	do{
		do{
			cout << "Choice --->";
			try{
			cin >> b;
			if(b<0||b>30)
				throw "Sorry! Your choice does not exist! Please enter again following the range (0-30).\n";
			}
			catch(const char* msg){
				cout << msg << endl;
			}
		}while(b<0||b>30);
		if(b!=0)
		{
		cout << "Quantity? (max 2) : ";
		do{
			cin.ignore();
			cin >> q;
			if(q>=3)
				cout <<"Maximum quantity is 2! \nEnter again: ";
		}while(q>=3);

		switch(b)
		{
			case 1:  price+=(3.69*q);
					   break;
			case 2:  price+=(2*q);
					   break;
			case 3:  price+=(2.69*q);
					   break;
			case 4:  price+=(1.99*q);
					   break;
			case 5:  price+=(2.89*q);
					   break;
			case 6:  price+=(2.69*q);
					   break;
			case 7:  price+=(7.99*q);
					   break;
			case 8:  price+=(6.99*q);
					   break;
			case 9:  price+=(4.89*q);
					   break;
			case 10: price+=(8.91*q);
					   break;
			case 11: price+=(4.49*q);
					   break;
			case 12: price+=(3.59*q);
					   break;
			case 13: price+=(5.59*q);
					   break;
			case 14: price+=(6.59*q);
					   break;
			case 15: price+=(1.99*q);
					   break;
			case 16: price+=(3.99*q);
					   break;
			case 17: price+=(5.89*q);
					   break;
			case 18: price+=(3.69*q);
					   break;
			case 19: price+=(2*q);
					   break;
			case 20: price+=(2*q);
					   break;
			case 21: price+=(8.99*q);
					   break;
			case 22: price+=(4.99*q);
					   break;
			case 23: price+=(2.59*q);
					   break;
			case 24: price+=(5.99*q);
					   break;
			case 25: price+=(2.49*q);
					   break;
			case 26: price+=(1.99*q);
					   break;
			case 27: price+=(3.99*q);
					   break;
			case 28: price+=(4.99*q);
					   break;
			case 29: price+=(4.99*q);
					   break;
			case 30: price+=(2.99*q);
					   break;
			case 0:  me(m);
					 choice(m);
					   break;
		}
		cout << "Total = Rm " << price << endl;
		do
		{
			cout << "Purchase again?(Y/N)\n------>";
			try{
				cin >> again;
				if(again!='n'&&again!='N'&&again!='y'&&again!='Y')
					throw "Invalid character!!";
			}
			catch(const char* msg){
				cout << msg << endl;
			}
		}while(again!='n'&&again!='N'&&again!='y'&&again!='Y');

	}
	else if(b==0)
	{
		again=='n';
	}
	}while(again=='y'||again=='Y');
	me(m);
	choice(m);
}

void Menu::bread()
{
	int b,m;char again;
	double q;

	do{
		do{
			cout << "Choice --->";
			try{
			cin >> b;
			if(b<0||b>8)
				throw "Sorry! Your choice does not exist! Please enter again following the range (0-8).\n";
			}
			catch(const char* msg){
				cout << msg << endl;
			}
		}while(b<0||b>8);
		if(b!=0)
		{
		cout << "Quantity? (max 2) : ";
		do{
			cin.ignore();
			cin >> q;
			if(q>=3)
				cout <<"Maximum quantity is 2! \nEnter again: ";
		}while(q>=3);

		switch(b)
		{
			case 1:  price+=(12.85*q);
					   break;
			case 2:  price+=(2.65*q);
					   break;
			case 3:  price+=(4.56*q);
					   break;
			case 4:  price+=(3.53*q);
					   break;
			case 5:  price+=(4.50*q);
					   break;
			case 6:  price+=(5.56*q);
					   break;
			case 7:  price+=(3.60*q);
					   break;
			case 8:  price+=(4.15*q);
					   break;
			case 0:  me(m);
					 choice(m);
					   break;
		}
		cout << "Total = Rm " << price << endl;
		do
		{
			cout << "Purchase again?(Y/N)\n------>";
			try{
				cin >> again;
				if(again!='n'&&again!='N'&&again!='y'&&again!='Y')
					throw "Invalid character!!";
			}
			catch(const char* msg){
				cout << msg << endl;
			}
		}while(again!='n'&&again!='N'&&again!='y'&&again!='Y');
	}
	else if(b==0)
	{
		again=='n';
	}
	}while(again=='y'||again=='Y');
	me(m);
	choice(m);
}

void Menu::grains()
{
	int b,m;char again;
	double q;

	do{
		do{
			cout << "Choice --->";
			try{
			cin >> b;
			if(b<0||b>9)
				throw "Sorry! Your choice does not exist! Please enter again following the range (0-9).\n";
			}
			catch(const char* msg){
				cout << msg << endl;
			}
		}while(b<0||b>9);
		if(b!=0)
		{
		cout << "Quantity? (max 2) : ";
		do{
			cin.ignore();
			cin >> q;
			if(q>=3)
				cout <<"Maximum quantity is 2! \nEnter again: ";
		}while(q>=3);

		switch(b)
		{
			case 1:  price+=(13.40*q);
					   break;
			case 2:  price+=(6.30*q);
					   break;
			case 3:  price+=(5.55*q);
					   break;
			case 4:  price+=(13.88*q);
					   break;
			case 5:  price+=(27.99*q);
					   break;
			case 6:  price+=(18.50*q);
					   break;
			case 7:  price+=(4.99*q);
					   break;
			case 8:  price+=(4.99*q);
					   break;
			case 9:  price+=(6.00*q);
					   break;
			case 0:  me(m);
					 choice(m);
					   break;
		}
		cout << "Total = Rm " << price << endl;
		do
		{
			cout << "Purchase again?(Y/N)\n------>";
			try{
				cin >> again;
				if(again!='n'&&again!='N'&&again!='y'&&again!='Y')
					throw "Invalid character!!";
			}
			catch(const char* msg){
				cout << msg << endl;
			}
		}while(again!='n'&&again!='N'&&again!='y'&&again!='Y');
		}
		else if(b==0)
		{
			again=='n';
		}
	}while(again=='y'||again=='Y');
	me(m);
	choice(m);
}

void Menu::frozen()
{
	int b,m;char again;
	double q;

	do{
		do{
			cout << "Choice --->";
			try{
			cin >> b;
			if(b<0||b>10)
				throw "Sorry! Your choice does not exist! Please enter again following the range (0-10).\n";
			}
			catch(const char* msg){
				cout << msg << endl;
			}
		}while(b<0||b>10);
		if(b!=0)
		{
		cout << "Quantity? (max 2) : ";
		do{
			cin.ignore();
			cin >> q;
			if(q>=3)
				cout <<"Maximum quantity is 2! \nEnter again: ";
		}while(q>=3);

		switch(b)
		{
			case 1:  price+=(6.50*q);
					   break;
			case 2:  price+=(10.50*q);
					   break;
			case 3:  price+=(6.50*q);
					   break;
			case 4:  price+=(14.00*q);
					   break;
			case 5:  price+=(4.60*q);
					   break;
			case 6:  price+=(10.50*q);
					   break;
			case 7:  price+=(13.70*q);
					   break;
			case 8:  price+=(13.15*q);
					   break;
			case 9:  price+=(8.99*q);
					   break;
			case 10:  price+=(12.50*q);
					   break;
			case 0:  me(m);
					 choice(m);
					   break;
		}
		cout << "Total = Rm " << price << endl;
		do
		{
			cout << "Purchase again?(Y/N)\n------>";
			try{
				cin >> again;
				if(again!='n'&&again!='N'&&again!='y'&&again!='Y')
					throw "Invalid character!!";
			}
			catch(const char* msg){
				cout << msg << endl;
			}
		}while(again!='n'&&again!='N'&&again!='y'&&again!='Y');
		}
		else if(b==0)
		{
			again=='n';
		}
	}while(again=='y'||again=='Y');
	me(m);
	choice(m);
}

void Menu::canned()
{
	int b,m;char again;
	double q;

	do{
		do{
			cout << "Choice --->";
			try{
			cin >> b;
			if(b<0||b>7)
				throw "Sorry! Your choice does not exist! Please enter again following the range (0-7).\n";
			}
			catch(const char* msg){
				cout << msg << endl;
			}
		}while(b<0||b>7);
		if(b!=0)
		{
		cout << "Quantity? (max 2) : ";
		do{
			cin.ignore();
			cin >> q;
			if(q>=3)
				cout <<"Maximum quantity is 2! \nEnter again: ";
		}while(q>=3);

		switch(b)
		{
			case 1:  price+=(3.99*q);
					   break;
			case 2:  price+=(4.15*q);
					   break;
			case 3:  price+=(16.99*q);
					   break;
			case 4:  price+=(3.40*q);
					   break;
			case 5:  price+=(30.10*q);
					   break;
			case 6:  price+=(5.00*q);
					   break;
			case 7:  price+=(10.60*q);
					   break;
			case 0:  me(m);
					 choice(m);
					   break;
		}
		cout << "Total = Rm " << price << endl;
		do
		{
			cout << "Purchase again?(Y/N)\n------>";
			try{
				cin >> again;
				if(again!='n'&&again!='N'&&again!='y'&&again!='Y')
					throw "Invalid character!!";
			}
			catch(const char* msg){
				cout << msg << endl;
			}
		}while(again!='n'&&again!='N'&&again!='y'&&again!='Y');
	}
		else if(b==0)
		{
			again=='n';
		}
	}while(again=='y'||again=='Y');
	me(m);
	choice(m);
}

void Menu::dairy()
{
	int b,m;char again;
	double q;
	do{
		do{
			cout << "Choice --->";
			try{
			cin >> b;
			if(b<0||b>12)
				throw "Sorry! Your choice does not exist! Please enter again following the range (0-12).\n";
			}
			catch(const char* msg){
				cout << msg << endl;
			}
		}while(b<0||b>12);
		if(b!=0)
		{
		cout << "Quantity? (max 2) : ";
		do{
			cin.ignore();
			cin >> q;
			if(q>=3)
				cout <<"Maximum quantity is 2! \nEnter again: ";
		}while(q>=3);

		switch(b)
		{
			case 1:  price+=(12.90*q);
					   break;
			case 2:  price+=(16.90*q);
					   break;
			case 3:  price+=(14.79*q);
					   break;
			case 4:  price+=(11.90*q);
					   break;
			case 5:  price+=(13.90*q);
					   break;
			case 6:  price+=(11.20*q);
					   break;
			case 7:  price+=(4.25*q);
					   break;
			case 8:  price+=(9.71*q);
					   break;
			case 9:  price+=(5.30*q);
					   break;
			case 10: price+=(3.50*q);
					   break;
			case 11:  price+=(1.03*q);
					   break;
			case 12:  price+=(2.89*q);
					   break;
			case 0:  me(m);
					 choice(m);
					   break;
		}
		cout << "Total = Rm " << price << endl;
		do
		{
			cout << "Purchase again?(Y/N)\n------>";
			try{
				cin >> again;
				if(again!='n'&&again!='N'&&again!='y'&&again!='Y')
					throw "Invalid character!!";
			}
			catch(const char* msg){
				cout << msg << endl;
			}
		}while(again!='n'&&again!='N'&&again!='y'&&again!='Y');
	}
	else if(b==0)
	{
		again=='n';
	}
	}while(again=='y'||again=='Y');
	me(m);
	choice(m);
}


void Menu::drinkbev()
{
	int b,m;char again;
	double q;
	do{
		do{
			cout << "Choice --->";
			try{
			cin >> b;
			if(b<0||b>20)
				throw "Sorry! Your choice does not exist! Please enter again following the range (0-20).\n";
			}
			catch(const char* msg){
				cout << msg << endl;
			}
		}while(b<0||b>20);

		if(b!=0)
		{
			cout << "Quantity? (max 2) : ";
			do{
				cin >> q;
				if(q>=3)
					cout <<"Maximum quantity is 2! \nEnter again: ";
			}while(q>=3);

		switch(b)
		{
			case 1:  price+=(10.99*q);
					   break;
			case 2:  price+=(5.49*q);
					   break;
			case 3:  price+=(1.05*q);
					   break;
			case 4:  price+=(4.89*q);
					   break;
			case 5:  price+=(3.45*q);
					   break;
			case 6:  price+=(6.60*q);
					   break;
			case 7:  price+=(12.79*q);
					   break;
			case 8:  price+=(7.99*q);
					   break;
			case 9:  price+=(5.90*q);
					   break;
			case 10:  price+=(3.99*q);
					   break;
			case 11:  price+=(7.90*q);
					   break;
			case 12:  price+=(3.99*q);
					   break;
			case 13:  price+=(7.90*q);
					   break;
			case 14:  price+=(4.70*q);
					   break;
			case 15:  price+=(7.05*q);
					   break;
			case 16:  price+=(2.50*q);
					   break;
			case 17:  price+=(2.99*q);
					   break;
			case 18:  price+=(3.92*q);
					   break;
			case 19:  price+=(1.95*q);
					   break;
			case 20:  price+=(2.44*q);
					   break;
			case 0:  me(m);
					 choice(m);
					   break;
		}
			cout << "Total = Rm " << price << endl;
		do
		{
			cout << "Purchase again?(Y/N)\n------>";
			try{
				cin >> again;
				if(again!='n'&&again!='N'&&again!='y'&&again!='Y')
					throw "Invalid character!!";
			}
			catch(const char* msg){
				cout << msg << endl;
			}
		}while(again!='n'&&again!='N'&&again!='y'&&again!='Y');
		}
		else if(b==0)
		{
			again=='n';
		}
	}while(again=='y'||again=='Y');

	me(m);
	choice(m);
}

void Menu::dessert()
{
	int b,m;char again;
	double q;

	do{
		do{
			cout << "Choice --->";
			try{
			cin >> b;
			if(b<0||b>19)
				throw "Sorry! Your choice does not exist! Please enter again following the range (0-19).\n";
			}
			catch(const char* msg){
				cout << msg << endl;
			}
		}while(b<0||b>19);
		if(b!=0)
		{
		cout << "Quantity? (max 2) : ";
		do{
			cin.ignore();
			cin >> q;
			if(q>=3)
				cout <<"Maximum quantity is 2! \nEnter again: ";
		}while(q>=3);

		switch(b)
		{
			case 1:  price+=(6.99*q);
					   break;
			case 2:  price+=(4.00*q);
					   break;
			case 3:  price+=(6.75*q);
					   break;
			case 4:  price+=(4.50*q);
					   break;
			case 5:  price+=(10.28*q);
					   break;
			case 6:  price+=(3.15*q);
					   break;
			case 7:  price+=(2.50*q);
					   break;
			case 8:  price+=(4.90*q);
					   break;
			case 9:  price+=(10.90*q);
					   break;
			case 10:  price+=(4.88*q);
					   break;
			case 11:  price+=(19.17*q);
					   break;
			case 12:  price+=(14.50*q);
					   break;
			case 13:  price+=(5.50*q);
					   break;
			case 14:  price+=(20.35*q);
					   break;
			case 15:  price+=(23.90*q);
					   break;
			case 16:  price+=(6.70*q);
					   break;
			case 17:  price+=(5.00*q);
					   break;
			case 18:  price+=(3.50*q);
					   break;
			case 19:  price+=(4.60*q);
					   break;
			case 0: me(m);
					 choice(m);
					   break;
		}
		cout << "Total = Rm " << price << endl;
		do
		{
			cout << "Purchase again?(Y/N)\n------>";
			try{
				cin >> again;
				if(again!='n'&&again!='N'&&again!='y'&&again!='Y')
					throw "Invalid character!!";
			}
			catch(const char* msg){
				cout << msg << endl;
			}
		}while(again!='n'&&again!='N'&&again!='y'&&again!='Y');
	}
	else if(b==0)
	{
		again=='n';
	}
	}while(again=='y'||again=='Y');
	me(m);
	choice(m);
}

void Menu::petf()
{
	int b,m;char again;
	double q;

	do{
		do{
			cout << "Choice --->";
			try{
			cin >> b;
			if(b<0||b>7)
				throw "Sorry! Your choice does not exist! Please enter again following the range (0-7).\n";
			}
			catch(const char* msg){
				cout << msg << endl;
			}
		}while(b<0||b>7);
		if(b!=0)
		{
		cout << "Quantity? (max 2) : ";
		do{
			cin.ignore();
			cin >> q;
			if(q>=3)
				cout <<"Maximum quantity is 2! \nEnter again: ";
		}while(q>=3);

		switch(b)
		{
			case 1:  price+=(55.60*q);
					   break;
			case 2:  price+=(45.88*q);
					   break;
			case 3:  price+=(36.25*q);
					   break;
			case 4:  price+=(32.29*q);
					   break;
			case 5:  price+=(26.90*q);
					   break;
			case 6:  price+=(10.00*q);
					   break;
			case 7:  price+=(20.00*q);
					   break;
			case 0:  me(m);
					 choice(m);
					   break;
		}
		cout << "Total = Rm " << price << endl;
		do
		{
			cout << "Purchase again?(Y/N)\n------>";
			try{
				cin >> again;
				if(again!='n'&&again!='N'&&again!='y'&&again!='Y')
					throw "Invalid character!!";
			}
			catch(const char* msg){
				cout << msg << endl;
			}
		}while(again!='n'&&again!='N'&&again!='y'&&again!='Y');
		}
		else if(b==0)
		{
			again=='n';
		}
	}while(again=='y'||again=='Y');
	me(m);
	choice(m);
}

void Menu::hygiene()
{
	int b,m;char again;
	double q;

	do{
		do{
			cout << "Choice --->";
			try{
			cin >> b;
			if(b<0||b>19)
				throw "Sorry! Your choice does not exist! Please enter again following the range (0-19).\n";
			}
			catch(const char* msg){
				cout << msg << endl;
			}
		}while(b<0||b>19);
		if(b!=0)
		{
		cout << "Quantity? (max 2) : ";
		do{
			cin.ignore();
			cin >> q;
			if(q>=3)
				cout <<"Maximum quantity is 2! \nEnter again: ";
		}while(q>=3);

		switch(b)
		{
			case 1:  price+=(80.99*q);
					   break;
			case 2:  price+=(12.20*q);
					   break;
			case 3:  price+=(10.50*q);
					   break;
			case 4:  price+=(7.00*q);
					   break;
			case 5:  price+=(8.60*q);
					   break;
			case 6:  price+=(19.50*q);
					   break;
			case 7:  price+=(10.20*q);
					   break;
			case 8:  price+=(5.50*q);
					   break;
			case 9:  price+=(5.50*q);
					   break;
			case 10:  price+=(12.50*q);
					   break;
			case 11:  price+=(12.90*q);
					   break;
			case 12:  price+=(15.90*q);
					   break;
			case 13:  price+=(7.90*q);
					   break;
			case 14:  price+=(24.99*q);
					   break;
			case 15:  price+=(29.99*q);
					   break;
			case 16:  price+=(14.29*q);
					   break;
			case 17:  price+=(7.90*q);
					   break;
			case 18:  price+=(16.99*q);
					   break;
			case 19:  price+=(11.99*q);
					   break;
			case 0:  me(m);
					 choice(m);
					   break;
		}
		cout << "Total = Rm " << price << endl;
		do
		{
			cout << "Purchase again?(Y/N)\n------>";
			try{
				cin >> again;
				if(again!='n'&&again!='N'&&again!='y'&&again!='Y')
					throw "Invalid character!!";
			}
			catch(const char* msg){
				cout << msg << endl;
			}
		}while(again!='n'&&again!='N'&&again!='y'&&again!='Y');
		}
		else if(b==0)
		{
			again=='n';
		}
	}while(again=='y'||again=='Y');
	me(m);
	choice(m);
}

void Menu::beauty()
{
	int b,m;char again;
	double q;

	do{
		do{
			cout << "Choice --->";
			try{
			cin >> b;
			if(b<0||b>30)
				throw "Sorry! Your choice does not exist! Please enter again following the range (0-30).\n";
			}
			catch(const char* msg){
				cout << msg << endl;
			}
		}while(b<0||b>30);
		if(b!=0)
		{
		cout << "Quantity? (max 2) : ";
		do{
			cin.ignore();
			cin >> q;
			if(q>=3)
				cout <<"Maximum quantity is 2! \nEnter again: ";
		}while(q>=3);

		switch(b)
		{
			case 1:  price+=(21.65*q);
					   break;
			case 2:  price+=(20.50*q);
					   break;
			case 3:  price+=(22.95*q);
					   break;
			case 4:  price+=(18.45*q);
					   break;
			case 5:  price+=(6.29*q);
					   break;
			case 6:  price+=(120.00*q);
					   break;
			case 7:  price+=(20.35*q);
					   break;
			case 8:  price+=(50.99*q);
					   break;
			case 9:  price+=(25.00*q);
					   break;
			case 10:  price+=(30.50*q);
					   break;
			case 11:  price+=(20.00*q);
					   break;
			case 12:  price+=(54.95*q);
					   break;
			case 13:  price+=(40.55*q);
					   break;
			case 14:  price+=(45.00*q);
					   break;
			case 15:  price+=(55.25*q);
					   break;
			case 16:  price+=(28.50*q);
					   break;
			case 17:  price+=(15.50*q);
					   break;
			case 18:  price+=(150.99*q);
					   break;
			case 19:  price+=(25.80*q);
					   break;
			case 20:  price+=(30.40*q);
					   break;
			case 21:  price+=(14.99*q);
					   break;
			case 22:  price+=(18.99*q);
					   break;
			case 23:  price+=(35.99*q);
					   break;
			case 24:  price+=(45.60*q);
					   break;
			case 25:  price+=(8.49*q);
					   break;
			case 26:  price+=(14.65*q);
					   break;
			case 27:  price+=(19.50*q);
					   break;
			case 28:  price+=(114.00*q);
					   break;
			case 29:  price+=(6.00*q);
					   break;
			case 30:  price+=(35.90*q);
					   break;
			case 0:  me(m);
					 choice(m);
					   break;
		}
		cout << "Total = Rm " << price << endl;
		do
		{
			cout << "Purchase again?(Y/N)\n------>";
			try{
				cin >> again;
				if(again!='n'&&again!='N'&&again!='y'&&again!='Y')
					throw "Invalid character!!";
			}
			catch(const char* msg){
				cout << msg << endl;
			}
		}while(again!='n'&&again!='N'&&again!='y'&&again!='Y');
		}
		else if(b==0)
		{
			again=='n';
		}
	}while(again=='y'||again=='Y');
	me(m);
	choice(m);
}

void Menu::pharmacy()
{
	int b,m; char again;
	double q;

	do{
		do{
			cout << "Choice --->";
			try{
			cin >> b;
			if(b<0||b>13)
				throw "Sorry! Your choice does not exist! Please enter again following the range (0-13).\n";
			}
			catch(const char* msg){
				cout << msg << endl;
			}
		}while(b<0||b>13);
		if(b!=0)
		{
		cout << "Quantity? (max 2) : ";
		do{
			cin.ignore();
			cin >> q;
			if(q>=3)
				cout <<"Maximum quantity is 2! \nEnter again: ";
		}while(q>=3);

		switch(b)
		{
			case 1:  price+=(10.00*q);
					   break;
			case 2:  price+=(25.99*q);
					   break;
			case 3:  price+=(10.25*q);
					   break;
			case 4:  price+=(48.50*q);
					   break;
			case 5:  price+=(20.99*q);
					   break;
			case 6:  price+=(40.00*q);
					   break;
			case 7:  price+=(15.50*q);
					   break;
			case 8:  price+=(25.80*q);
					   break;
			case 9:  price+=(20.90*q);
					   break;
			case 10: price+=(10.50*q);
					   break;
			case 11:  price+=(20.60*q);
					   break;
			case 12:  price+=(12.55*q);
					   break;
			case 13: price+=(5.00*q);
					   break;
			case 0:  me(m);
					 choice(m);
					   break;
		}
		cout << "Total = Rm " << price << endl;
		do
		{
			cout << "Purchase again?(Y/N)\n------>";
			try{
				cin >> again;
				if(again!='n'&&again!='N'&&again!='y'&&again!='Y')
					throw "Invalid character!!";
			}
			catch(const char* msg){
				cout << msg << endl;
			}
		}while(again!='n'&&again!='N'&&again!='y'&&again!='Y');
		}
		else if(b==0)
		{
			again=='n';
		}
	}while(again=='y'||again=='Y');
	me(m);
	choice(m);
}

void Menu::stationary()
{
	int b,m;char again;
	double q;

	do{
		do{
			cout << "Choice --->";
			try{
			cin >> b;
			if(b<0||b>20)
				throw "Sorry! Your choice does not exist! Please enter again following the range (0-20).\n";
			}
			catch(const char* msg){
				cout << msg << endl;
			}
		}while(b<0||b>20);
		if(b!=0)
		{
		cout << "Quantity? (max 2) : ";
		do{
			cin.ignore();
			cin >> q;
			if(q>=3)
				cout <<"Maximum quantity is 2! \nEnter again: ";
		}while(q>=3);

		switch(b)
		{
			case 1:  price+=(12.50*q);
					   break;
			case 2:  price+=(1.00*q);
					   break;
			case 3:  price+=(13.50*q);
					   break;
			case 4:  price+=(15.50*q);
					   break;
			case 5:  price+=(2.20*q);
					   break;
			case 6:  price+=(11.50*q);
					   break;
			case 7:  price+=(2.90*q);
					   break;
			case 8:  price+=(4.50*q);
					   break;
			case 9:  price+=(6.20*q);
					   break;
			case 10:  price+=(5.40*q);
					   break;
			case 11:  price+=(5.90*q);
					   break;
			case 12:  price+=(1.70*q);
					   break;
			case 13:  price+=(1.00*q);
					   break;
			case 14:  price+=(10.55*q);
					   break;
			case 15:  price+=(15.60*q);
					   break;
			case 16:  price+=(11.50*q);
					   break;
			case 17:  price+=(12.99*q);
					   break;
			case 18:  price+=(5.25*q);
					   break;
			case 19:  price+=(4.55*q);
					   break;
			case 20:  price+=(8.25*q);
					   break;
			case 0:  me(m);
					 choice(m);
					   break;

		}
		cout << "Total = Rm " << price << endl;
		do
		{
			cout << "Purchase again?(Y/N)\n------>";
			try{
				cin >> again;
				if(again!='n'&&again!='N'&&again!='y'&&again!='Y')
					throw "Invalid character!!";
			}
			catch(const char* msg){
				cout << msg << endl;
			}
		}while(again!='n'&&again!='N'&&again!='y'&&again!='Y');
		}
		else if(b==0)
		{
			again=='n';
		}
  }
  while(again=='Y'||again=='y');
  me(m);
  choice(m);
}






class User:public info{
	public:
		virtual void customer()
{
}
};

class NewUser:public User {
	public:
		void customer()
		{
			bool ff = false;

			cout << "[Enter your information]" << endl;
			do
			{
				cout << "Name: ";
				try{
					cin.ignore();
					getline(cin,name);
					ff=error.classen(name);
				}
				catch(const char* msg){
					cout << msg <<endl;
				}
			}while(ff==false);
			ff=false;
			do
			{
				cout << "IC Number (XXXXXX-XX-XXXX): ";
				try{
					getline(cin,ic);
					ff=error.classeic(ic);
				}
				catch(const char* msg){
					cout << msg <<endl;
				}
			}while(ff==false);
			ff=false;
			do
			{
				cout << "Phone Number (60X-XXXXXXXX):   ";
				try{
					getline(cin, phone);
					ff=error.classep(phone);
				}
				catch(const char* msg){
					cout << msg <<endl;
				}
			}while(ff==false);
			ff=false;
			do
			{
				cout << "Address:";
				try{
					getline(cin,add);
					ff=error.classeadd(add);
				}
				catch(const char* msg){
					cout << msg <<endl;
				}
			}while(ff==false);
			
		}
};


class OldUser:public User{
	public:
		void customer()
		{
			cout << "Please enter your IC Number (XXXXXX-XX-XXXX): ";
			cin.ignore();
			getline(cin,ic);

		}
};

class PreEntryCheck:public info

	{
	private:
		Menu mm;
	public:
		bool Temp();
		friend ostream &operator<<(ostream &output,PreEntryCheck &a)
		{
	output << a.temperature << endl;
    output << "-----------------------------------------------------------------------------------------------------";
	output << "-----------------------------------------------------------------------------------------------------" << endl;
		}

};



bool PreEntryCheck::Temp() 	//entered by workers
{
	int m;
	cout<< "Our workers will now detect your body temperature..................." << endl;
	do
	{
		cout << "Temperature: ";
		cin >> temperature;
	if(temperature<=33||temperature>=40)
			cout << "Abnormal Temperature. Please try again." << endl << endl;
	}while(temperature<=33||temperature>=40);

	do
	{
		cout << "Mask?(Y/N): " << endl;
		cin >> mask;
		if(mask!='Y' && mask!='y' && mask!='n' && mask!='N')
			cout << "Invalid character! Please enter again." << endl << endl;
	}while(mask!='Y' && mask!='y' && mask!='n' && mask!='N');

	if(temperature<37.5 && mask=='y'|| temperature <37.5 && mask=='Y')
	{
		cout << "\n Please move to the cashier counter to proceed..." << endl;
		mm.setprice(0);
		mm.me(m);
		mm.choice(m);
	}
	else if(temperature>=37.5)
	{
		cout << "\n Sorry! You are not allow to continue shopping.\n Please visit the nearest hospital as soon as possible!" << endl;
		cin.ignore();
		return false;
	}
	else if(mask=='n'||mask=='N')
	{
		cout << "\n Sorry! You are not allow to continue shopping without mask.\n Please wear the mask to consider other people and your health. Thank you." << endl;
		cin.ignore();
		return false;
	}

}



void Total::displaytotal(double p)
{
	cout << "RM" << p << endl << endl;
}

ostream & operator << (ostream &output,info &input)
{
	cout << endl << input.name <<endl;
	cout << input.ic << endl;
	cout << input.add << endl;
	cout << input.phone << endl;
	cout << "Your information has been recorded into our system...\n\n";
	output << setw(50) << left;
	output << input.name << "|";
	output << setw(19) << left;
	output << input.ic << "|";
	output << setw(95) << left;
	output << input.add << "|";
	output << setw(19) << left;
	output << input.phone << "|";
}


int main()
{
	int size=9999,i=0;
	string IC;
	info *Info = new info[size];
	Error e;
	NewUser newu;
	OldUser oldu;
	PreEntryCheck au;
	ofstream outfile;
	outfile.open("CustomerList.txt",ios::app);
	outfile << "\n\n[DATE]      | [TIME]    |                     [NAME]                         |      [IC.NO]        | ";
	outfile << "                                   [ADRRESS]                                                    |       [PHONE]       |  [TEMPERATURE]" << endl;
	outfile << "-----------------------------------------------------------------------------------------------------";
	outfile << "--------------------------------------------------------------------------------------------------------------------------------------" << endl;
	do{
	char ch;
	cout << "-------------------Welcome to HART Grocery Store!--------------------" << endl;
	Info[i].DateTime(outfile);
	do
	{
		cout << "Are you a first time customer? (Y/N)" << endl;
		cin >> ch;
		if(ch!='Y' && ch!='y' && ch!='n' && ch!='N')
			cout << "Invalid character! Please enter again." << endl << endl;
	}while(ch!='Y' && ch!='y' && ch!='n' && ch!='N');


	if(ch=='y'||ch=='Y')
	{
		newu.customer();
		Info[i]=newu;
		outfile << Info[i];
		au.Temp();
		outfile << au;

	}

	else if(ch=='n'||ch=='N')
	{
		int num=-1;
		bool dd;

		do
		{
			oldu.customer();
			Info[i]=oldu;
			IC=Info[i].getIC();
			dd=e.classeic(IC);
		}while(dd==false);

		for (int x=0; x<i;x++)
		{
			if(Info[i].search(Info[x],IC)==true)
				{
				num=x;}
		}

		if(num==-1)
			cout << "Sorry! This IC number does not exist!\n";
		else
		{
		outfile << Info[num];
		au.Temp();
		outfile << au;
		}
		i--;
	}

	i++;
	}while(i<=size);
	outfile.close();

	delete[]Info;

	return 0;
}
