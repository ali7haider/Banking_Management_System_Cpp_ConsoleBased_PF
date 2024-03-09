//Admin UserName= admin , Password=1234
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h>
using namespace std;
//Function PrototypeStart--------------------------------------------------------------------------
void header();                       //Application Header
void home();                         //For Home Screen
void adminlog();                     //For Admin Login                      
void clearscreen();                  //For Clearing Screen and Getch
void adminMenu();                    //FOr Admin Menu
void addaccount();                   //For Add accounts
void addcustomertoarray(string name,string username1,string password1,string type,string address,string phone,double account,double deposit);
void viewallcustomer();              //To View All Customer
void usermenu();                     //Function For user Menu
void userlog();                      //Function for User Login
void totalmoney();                   //Function For Total Money in Bank
int depositmoney();                  //Function For Deposit Money
void depositdetails();               //Function For Deposit Details
void accountdetails();               //Function for Account Details
int withdrawmoney();                 //Function For Withdraw Money
void withdrawdetails();              //Function For Withdraw Details
void balancedetails();               //Function For Balance Details
int transactmoney();                 //Function For Transact Money
void transactdetails();              //Function For Transact Details
void receivedetails();               //Function for Receive Details
void sortingview();                  //Function For Sorting
void storedata();                    //Function to Store All Data
void loaddata();                     //Function to load all Data
string parse(string row, int column);//function For Comma Separating
void userdata();                    //For Storing User DAta
void total_money();                 //For Storing Total Money In BAnk
void storewithdrawmoney();          //For Storing Withdraw Money
void storedepositmoney();           //For Storing Deposit Money
void storetransact();               //For Storing Transact Money
void loaduserdata();   				//For Reading User Data
void loadtotal_money();   			//For Reading Total Money in the Bank
void loaddepositmoney();  			//For Reading Deposit Money
void loadwithdrawmoney(); 			//For Reading Withdraw Money
void loadtransact(); 				//For Reading Transact Money
void storetotal();    				//For  Writing Total Money 
void loadtotalmoney(); 				//For Reading Total Money
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE); //For Changing Color
void updateaccount();
void edit(string n);

//Function Prototype End----------------------------------------------------------------------------


//Data Structure Start--------------------------------------------------------------------
string editoption;
string option;                                         //For Taking Option
string password;
int check=0;
string username ;
const int limit=20;                                //Limit of Array
int count_user=0;
string nameA[limit];                                //Array for Storing Name
string usernameA[limit];                            //Array for Storing UserNAme
string passwordA[limit];                            //Array for Storing Password
string typeA[limit];                                //Array for Storing Account Type
string phoneA[limit];                               //Array for Phone Number
double accountnumberA[limit];                       //Array for Account Number
double  moneyA[limit];                              //Array For Balance
string cityA[limit];
double totalmoneyinbank=0;                         //Variable for Total Money in the BAnk
int usercheck=0;
int dateA[limit];                                  //Array of Date for Storing Deposit Money
int balanceA[limit];                               //Array of Balance for Storing Deposit Money
string purposeA[limit];                            //Array of Purpose for Storing Deposit Money
int intial[limit];                                 //Varaible for Intial Balance
int mon;
int idx;
int idx3;
int mon2;
int mon3;
int check5=0;
int dateA2[limit];                                   //Array of Date for Storing Withdraw Money
int balanceA2[limit];                                //Array of Balance for Storing Withdraw Money
string purposeA2[limit];                              //Array of Purpose for Storing Withdraw Money
int total1[limit]={0};                               //Array of Deposited Money
int total2[limit]={0};                                //Array of Withdrawed Money
int total3[limit]={0};                                //Array of Transact Money
int total4[limit]={0};                                //Array for Receievd Money
int dateA3[limit];                                    //Array of Date for Storing Transact Money
int balanceA3[limit];                                 //Array of Balance for Storing Transact Money
int receive[limit]={0};                               //Array For Received Money
double account3;                                      //For Checking Account for Transact Money
int yes=0;
double account[limit];                          
double account2[limit];                               //Array of AccountNumber for Transact Money
int count1=0;
int balance2[limit];                                  //Array for Transact Money
int date2[limit];                                     //Array of Date For Transact Money
int idxr;
int breakk = 0;                                        //For Breaking Loop
string nameAs[limit];                                 //Array of NAme for For Sorting
string usernameAs[limit];                             //Array of UserNAme for For Sorting
string passwordAs[limit];                             //Array of Password for For Sorting
string typeAs[limit];                                 //Array for accountNumber for Sorting
string phoneAs[limit];                                //Array of Phone for For Sorting
double accountnumberAs[limit];                         //Array of AccountNumber for For Sorting
double moneyAs[limit];                                //Array of Money for For Sorting
string cityAs[limit];                                 //Array of City for For Sorting
string chk,chk2,chk3,chk4;
int ind[limit]={-1};
int ind2[limit]={-1};
int editidx;



//Data Structure End----------------------------------------------------------------------
main () 
//Main Start-----------------------------------------------------------------------------
{
	
	loaddata();  //Reading Data
	while(true)
	{
	 home();     
	 if (option=="3") //Exit Option
	 {
	 	
	 	break;
	 }
	 if (option=="1")  //Admin Option
	 {
	 	while(check!=2) 
	 {
		 if(breakk == 1)
		 {
			 breakk = 3;
			 break;
		 }
        adminlog();	
	if ((username == "admin" || username=="ADMIN") && password == "1234") 
	 {
		    breakk = 2;
	 	    system("cls");
	 	    char adminOption=' ';
	while (true)
	 {

	 	    adminMenu(); //Menu of Admin
	 	    
	 	    
	if (option=="1") {
			//Add New Account
			while(true) {
			
	if (count_user>100) //Limit of User are 100
	{

			header();
			cout<<"No more Customer can added"<<endl;
			clearscreen();
			break;
		
    }
			addaccount(); //Add Account Function
			break;
	}
	}
	else if (option=="2") 
	{
			//View All Customer
			viewallcustomer();
	}
	else if (option=="3")
	{
			//View Customer in Sorting Order
			sortingview();
				
	}
	else if (option=="4") 
	{
			//Loan Request
			header();
			cout<<"Home > Admin > Loan Request"<<endl;
			cout<<"                "<<endl;
			cout<<"No New Request"<<endl;
			clearscreen();
	}
	else if (option=="5") 
	{
			//Total Money
			totalmoney();
	}
	else if (option=="6")
	{
		updateaccount();
	}
	else if (option=="7") 
	{
			//logout
			breakk = 1;
			break;
	}
	else  {
		//Wrong Input
		        header();
				SetConsoleTextAttribute(h,4);
				cout<<"           "<<endl;
            	cout<<"Wrong Input"<<endl;
				SetConsoleTextAttribute(h,4);
				clearscreen();
				
	}
        //End of while loop for admin menu 
		}
         
         
	 }
     
	else 
	{
		//Wrong UserName and Password
		SetConsoleTextAttribute(h,4);
	 	cout<<"Wrong UserName And Password"<<endl;
		 SetConsoleTextAttribute(h,11);
	 	cout<<"Enter 1 to Re-enter and 2 to Return to home screen........";
	 	cin>>check;
	 	system("cls");
	if (check==2) 
	{
	 		check++;
	 		break;
	 		
	}
	}	
	}
	//Admin Menu End
	}

	//User Menu Start----------------------------------------------------------------------------------------------------
	if (option=="2")
	{
		 	
	if (count_user==0)
	{
            //Incase of No Account
			header();
			cout<<"Home > Customer Log in >"<<endl;
			cout<<"------------------------    "<<endl;
			cout << "No Account till now....Please Register Yourself from Admin" << endl;
			clearscreen();
	}	
	else
	{
	while(usercheck!=2)
	{
	if(breakk == 1)
	{
			breakk = 3;
			break;
    }
			userlog();	
	for (int i=0 ; i<count_user ; i++) 
	{ 
	if (usernameA[i]==username && passwordA[i]==password)
	{
		    //Login
			system("cls");
	while(true)
					{
					
			idx=i;
			ind[idx]=idx;
			int count_deposit=idx;
	        usermenu();	
	if (option=="1")
	{
		    //Deposit Money
			mon=depositmoney();
			clearscreen();
	}
	else if (option=="2")
	{
			//withdraw Money
			mon2=withdrawmoney();
			clearscreen();
	}
	else if (option=="3")
	{
			//Transact Money
	if(count_user==1)
	{
			header();
			cout<<"You cannot transact money as there is one account of yours till now"<<endl;
			clearscreen();
	}
	else
	{
			mon3=transactmoney();
	if (account3==accountnumberA[idx3])
	{
			date2[idx3]=dateA3[idx];
			balance2[idx3]=balanceA3[idx];
			account2[idx3]=accountnumberA[idx];
			total4[idx3]=total4[idx3]+balanceA3[idx];
			moneyA[idx3]=moneyA[idx3]+balanceA3[idx];
			storetransact();
			count1++;
	}
	}
	}
	else if (option=="4")
	{
			//Check Deposit Details
			depositdetails();
	}
	else if (option=="5")
	{
			//check withdraw details
			withdrawdetails();
	}
	else if (option=="6")
	{
			//Check Transact Money Details
			transactdetails();
	}
	else if (option=="7")
	{
			//Check Received Money Details
			receivedetails();
	}
	
	
	else if (option=="8")
	{
			//Check balance Details
			balancedetails();
	}
			
	else if (option=="9")
	{
			//My Account Details
			accountdetails();
	}
	else if (option=="10")
	{
			//logout
			storetotal();
			breakk = 1;
			break;
	}
	else{
			header();
			
			cout<<"           "<<endl;
			SetConsoleTextAttribute(h,4);
			cout<<"Wrong Input"<<endl;
			clearscreen();
			SetConsoleTextAttribute(h,11);

	}
	}
	}
				
	} 
    if (breakk!=1)
	{
    if(username!=usernameA[idx] && password!=passwordA[idx])
	{
			system("cls");
			header();
			cout<<"Home > Customer Log in > "<<endl;
			SetConsoleTextAttribute(h,4);
			cout<<"Wrong UserName And Password"<<endl;
			SetConsoleTextAttribute(h,11);
			cout<<"Enter 1 to Re-enter and 2 to Return to home screen ";
			cin>>usercheck;
			system("cls");
	if (usercheck==2) 
	{
			usercheck++;
			break;	
	}				
	}
	}
	}
	}
		 	
	} //User Menu End-----------------------------------------------------------------------------

	} //Main While End 

    }   //Main End--------------------------------------------------------------------------------

//Funtion Defination Start----------------------------------------------------------------
void header() 
{
	//Header of Project
	SetConsoleTextAttribute(h,11);
	cout << "*************************************************************************" << endl;
	cout << "**************        BANKING MANAGEMENT SYSTEM            **************" << endl;
	cout << "*************************************************************************" << endl;
	cout << "                                                                         " << endl;
	
}

void home() 
{
    //Home Menu
	header();
    cout << "Home >" << endl;
    cout << "       " << endl;
    cout << "Select any of the Following"<<endl;
    cout << "---------------------------       " << endl;
    cout << "[1]- Admin" << endl;
    cout << "[2]- Custoumer" << endl;
    cout << "[3]- Exit    " <<endl;
    cout << "Your Option[Enter Respective Number]......";
    cin >> option;
	if (option!="1" && option!="2" && option!="3")
	{
		SetConsoleTextAttribute(h,4);
		cout<<"Wrong Input"<<endl;
		clearscreen();
		SetConsoleTextAttribute(h,11);
	}
	system("cls");
}

void adminlog() 
{
	header();
    cout << "Home > Admin > Log in " << endl;
    cout << "---------------------- " << endl;
    cout << "User Name : ";
    cin >> username;
    cout << "Password : ";
    cin >> password;

}

void clearscreen()
{
	cout<<"_______________________________"<<endl;
	cout << "Press any Key to Continue...."<<endl;
	getch();
	system("cls");	
}

void adminMenu() 
{
	//For Admin Menu
	 header();
     cout << "Home > Admin " << endl;
     cout << "------------------------------             " << endl;
     cout << "[1]- Add New Account" << endl;
     cout << "[2]- View All Customer Record" << endl;
     cout << "[3]- View All Customer In Sorting Order" <<endl;
     cout << "[4]- Check New Loan Request" << endl;
     cout << "[5]- Total Deposit Money in Bank" << endl;
	 cout << "[6]- Update the account "<<endl;
     cout << "[7]- Logout" << endl;
     cout << "Your Option[Enter Respective Number]......";
     cin >> option;
     system("cls");
}

void addaccount() 
{
	//For Adding Account
        header();
	    cout << "Home  > Admin > Add New Account" << endl;
		cout << "-------------------------------     " <<endl;
	    string password1;
	    double deposit,account;
	    string phone;
	    string name,username1,type,address;
		cout << "                             " << endl;
		cout << "Enter Customer Name : ";
		cin >> name;
		cout << "Enter Customer UserName : ";
		cin >> username1;
		cout << "Enter Customer Password[4 Character]: ";
		cin >> password1;
		cout << "Enter Account Type : ";
		cin >> type;
		cout << "Enter Residential City : ";
		cin >> address;
		cout << "Enter Phone Number : ";
		cin >> phone;
		while(account) 
		{
		cout << "Enter Account Number[6 Character] : ";
		cin >> account;
		if (account<999999 && account>99999)
		{
			break;
		}
		else {
			SetConsoleTextAttribute(h,4);
			cout<<"Please enter 6 number Figure!!!!"<<endl;
			SetConsoleTextAttribute(h,11);
		}
		}
		while(deposit<3000)
		{
		cout << "Enter Deposit Money : ";
		cin >> deposit;
		if (deposit < 3000)
		{
			SetConsoleTextAttribute(h,4);
             cout<<"Enter atleast 3000 Rupees"<<endl;
			 SetConsoleTextAttribute(h,11);

		}
		}
		cout << "Account is Successfully Registered" << endl;
		addcustomertoarray(name,username1,password1,type,address,phone,account,deposit);
		clearscreen();
}

void addcustomertoarray(string name,string username1,string password1,string type,string address,string phone,double account,double deposit)
{
	//Adding Customer to array
		nameA[count_user]=name;
		usernameA[count_user]=username1;
		passwordA[count_user]=password1;
		typeA[count_user]=type;
		cityA[count_user]=address;
		phoneA[count_user]=phone;
		accountnumberA[count_user]=account;
		moneyA[count_user]=deposit;
		intial[count_user]=deposit;
		nameAs[count_user]=name;
		usernameAs[count_user]=username1;
		passwordAs[count_user]=password1;
		typeAs[count_user]=type;
		phoneAs[count_user]=phone;
		accountnumberAs[count_user]=account;
		moneyAs[count_user]=deposit;
		cityAs[count_user]=address;
		totalmoneyinbank=totalmoneyinbank+deposit;
		count_user++;
		userdata();
		total_money();		
}

void viewallcustomer()
{
	//View all Customer
	system("cls");
	header();
	cout << "Home  > Admin > View All Customer" << endl;
	cout<<"-----------------------------------  "<<endl;
	if (count_user==0) {
	cout<<"No Records Found"<<endl;
		}
	else {
	cout<<"Name"<<"\t\t"<<"UserName"<<"\t\t"<<"Password"<<"\t\t"<<"AccountType"<<"\t\t"<<"PhoneNumber"<<"\t\t"<<"AccountNumber"<<"\t"<<"Balance"<<endl;
		for (int i =0 ;i<count_user;i++)
		{
	cout<<nameA[i]<<"\t\t"<<usernameA[i]<<"\t\t\t"<<passwordA[i]<<"\t\t\t"<<typeA[i]<<"\t\t\t"<<phoneA[i]<<"\t\t\t"<<accountnumberA[i]<<"\t\t"<<moneyA[i]<<endl; 
}
}
clearscreen();
}

void usermenu() 
{
	//For User Menu
	 header();
     cout << "Home  > Customer" << endl;
	 cout<<"---------------------------" <<endl;
     cout << "[1]- Deposit Money" << endl;
     cout << "[2]- Withdraw Money" << endl;
     cout << "[3]- Transact Money" << endl;
     cout << "[4]- Check Deposit History" << endl;
     cout << "[5]- Check Withdraw History" << endl;
     cout << "[6]- Check Transact History" << endl;
     cout << "[7]- Check Received Money History" << endl;
     cout << "[8]- Check Balance Details" << endl;
     cout << "[9]- My Account Details" << endl;
     cout << "[10]- Logout" << endl;
     cout << "Your Option[Enter Respective Number]......";
     cin >> option;
     system("cls");
}

void totalmoney()
{
	//For Total Money In the Bank
	 header();
	 cout << "Home  > Admin > Total Money in Bank" << endl;
	 cout<<"-------------------------------------- "<<endl;

	if (count_user==0) 
	{
		cout<<"No Money in the Bank "<<endl;
		clearscreen();
    }
    else
    {
    	cout<<"Total money In bank of "<< count_user <<" User is : "<< totalmoneyinbank <<endl;
	if (totalmoneyinbank<5000) 
	{
		cout<<"     "<<endl;
		SetConsoleTextAttribute(h,4);
		//Reccommendation
		cout<<"CRITICAL BALANCE LEVEL!!!!"<<endl;
		cout<<"PLEASE ADVERTISE MORE TO HAVE NEW INVESTMENT"<<endl;
		SetConsoleTextAttribute(h,11);
	}
		clearscreen();
    }
}

void userlog() 
{
	//For Customer Login
		header();
		cout << "Home > Customer > Log in " << endl;
		cout << "-------------------------" << endl;
		cout << "User Name : ";
		cin >> username;
		cout << "Password : ";
		cin >> password;
}

int depositmoney()
{
	//For Deposit Money
        header();
		cout << "Home  > Customer > Deposit Money" << endl;
		cout<< "---------------------------------" <<endl;
		cout << "Enter Date(DD/MM/YYYY) : ";
		cin >> dateA[idx];
		cout << "Enter Purpose : ";
		cin >> purposeA[idx];
		int temp=1;
		while(temp<1000) 
		{
		cout << "Enter Amount : ";
		cin >> balanceA[idx];
		if (balanceA[idx]>1000) 
		{
			temp=balanceA[idx];
			break;
		}
		else 
		{
			SetConsoleTextAttribute(h,4);
			cout<<"Deposit Money Should be more than 1000..."<<endl;
			SetConsoleTextAttribute(h,11);
		}
		
		}
		total1[idx]=total1[idx]+balanceA[idx];
		moneyA[idx] = moneyA[idx] + balanceA[idx];
		totalmoneyinbank=totalmoneyinbank+balanceA[idx];
		storedepositmoney();
		return moneyA[idx];
}

void depositdetails()
{
	//for Deposit Details
	header();
	cout << "Home  > Customer > Deposit Money Details" << endl;
	cout << "----------------------------------------" <<endl;
	cout<<"Date"<<"\t\t"<<"Purpose"<<"\t\t"<<"Amount"<<endl;
    cout<<dateA[idx]<<"\t\t"<<purposeA[idx]<<"\t\t"<<balanceA[idx]<<endl;
    clearscreen();
}

void accountdetails()
{
	//For Account Details
	header();
	cout << "Home  > Customer > My Account Details" << endl;
	cout << "-------------------------------------" <<endl;
	cout<<"Name"<<"\t\t\t"<<"UserName"<<"\t\t\t"<<"Password"<<"\t\t\t"<<"AccountNumber"<<"\t\t"<<"PhoneNumber"<<"\t\t"<<"Balance"<<endl;
	cout<<nameA[idx]<<"\t\t\t"<<usernameA[idx]<<"\t\t\t\t"<<passwordA[idx]<<"\t\t\t\t"<<accountnumberA[idx]<<"\t\t\t"<<phoneA[idx]<<"\t\t\t"<< moneyA[idx]<<endl;
	clearscreen();
}

int withdrawmoney()
{
	int temp=0;
	//For Withdraw Money
		header();
		cout << "Home  > Customer > WithDraw Money" << endl;
		cout<<"-----------------------------------"<<endl;
		cout << "Enter Date(DD/MM/YYYY) : ";
		cin >> dateA2[idx];
		cout << "Enter Purpose : ";
		cin >> purposeA2[idx];
		while(temp<1000) {
		cout << "Enter Amount : ";
		cin >> balanceA2[idx];
		if (balanceA2[idx]>1000) 
		{
			temp=balanceA2[idx];
			break;
		}
		else 
		{
			SetConsoleTextAttribute(h,4);
			cout<<"Withdraw Money Should be more than 1000..."<<endl;
			SetConsoleTextAttribute(h,11);
		}
		
		}
		moneyA[idx] = moneyA[idx] - balanceA2[idx];
		total2[idx]=total2[idx]+balanceA2[idx];
		totalmoneyinbank=totalmoneyinbank-balanceA2[idx];
		storewithdrawmoney();
		return moneyA[idx];
}

void withdrawdetails()
{
	//Withdraw Details
	header();
	cout << "Home  > Customer > WithDraw Money History" << endl;
	cout << "-----------------------------------------" <<endl;
	cout<<"Date"<<"\t\t"<<"Purpose"<<"\t\t"<<"Amount"<<endl;
	cout<<dateA2[idx]<<"\t\t"<<purposeA2[idx]<<"\t\t"<<balanceA2[idx]<<endl;  
	clearscreen();
}

void balancedetails()
{
	//balance Details
	header();
	cout << "Home  > Customer > Balance Details" << endl;
	cout << "----------------------------------" <<endl;
	cout<<"Intial Deposit  : "<<intial[idx]<<endl;
	cout<<"Deposit Money   : "<<total1[idx]<<endl;
	cout<<"Withdraw Money  : "<<total2[idx]<<endl;
	cout<<"Transact Money  : "<<total3[idx]<<endl;
	cout<<"Received Money  : "<<total4[idx]<<endl;
	cout<<"Available Money : "<<moneyA[idx]<<endl;
	if (moneyA[idx]<2000)
	{ 
		//Recommendation
		SetConsoleTextAttribute(h,4);
		cout<<"Your Available Money is Less than 2000, make sure to have balance above 2000... "<<endl;
		SetConsoleTextAttribute(h,11);
	}
	clearscreen();
}

int transactmoney()
{
	int temp=0;
	//For Transact Money
	while(true) {
	if (breakk==3 || breakk==2)
	{
		breakk=0;
		break;
	}
		breakk=0;
		header();
	    cout << "Home  > Customer > Transact Money" << endl;
		cout << "---------------------------------" <<endl;
		cout<<"Enter Account Number to Send Money : ";
		cin>>account3;
	for (int x=0 ; x<count_user ; x++)
	{
	if (accountnumberA[x]==account3)
	{
		idx3=x;
		ind2[idx3]=idx3;
		yes=1;
		breakk=3;
		break;
	}
	}
	if (breakk==0)
	{
		SetConsoleTextAttribute(h,4);
		cout<<"Wrong Account Number"<<endl;
		SetConsoleTextAttribute(h,11);
		cout<<"Enter 1 to Re-enter and 2 to return....";
		cin>>breakk;
	if (breakk==2)
	{
		system("cls");
		break;
	}
		system("cls");
	}
    }
    if (yes==1)
    {
       cout<< "Enter Date(DD/MM/YYYY) : ";
	   cin >> dateA3[idx];
	while(temp<1000) {
		cout << "Enter Amount : ";
		cin >> balanceA3[idx];
	if (balanceA3[idx]>1000) 
	{
		temp=balanceA3[idx];
		break;
	}
	else 
	{
		SetConsoleTextAttribute(h,4);
		cout<<"Transact Money Should be more than 1000..."<<endl;
		SetConsoleTextAttribute(h,11);
	}
		
	}
	moneyA[idx]=moneyA[idx]-balanceA3[idx];
	total3[idx]=total3[idx]+balanceA3[idx];
	yes=0;
	clearscreen();
    }
   return moneyA[idx];
}

void transactdetails()
{
	//For Transact Details
	header();
	 cout << "Home  > Customer > Transact History" << endl;
	 cout << "-----------------------------------" <<endl;
	if (count1==0)
	{
		cout<<"No Records Found"<<endl;
		clearscreen();
	}
	else
	{
	
		cout<<"FromAN"<<"\t\t"<<"ToAN"<<"\t\t"<<"Date"<<"\t\t"<<"Amount"<<endl;
		cout<<accountnumberA[idx]<<"\t\t"<<accountnumberA[idx3]<<"\t\t"<<dateA3[idx]<<"\t"<<balanceA3[idx]<<endl;
		clearscreen();
}
}

void receivedetails()
{
	//For Money Receiving
	header();
	cout << "Home  > Customer > Received History" << endl;
	cout << "-----------------------------------" <<endl;
	if (count1==0)
	{
		cout<<"No Records Found"<<endl;
		clearscreen();
	}
	if (balance2[idx]>0)
	{
	    cout<<"FromAN"<<"\t\t"<<"Date"<<"\t\t"<<"Amount"<<endl;
        cout<<account2[idx3]<<"\t\t"<<date2[idx3]<<"\t\t"<<balance2[idx3]<<endl;
	    clearscreen();
   }
    else if (balance2[idx]==0)
	{
    	cout<<"No Records Found"<<endl;
    	clearscreen();
	}
}

void sortingview()
{ 
	//For view all customer in Sorting Order
	system("cls");
	header();
	cout << "Home  > Admin > View All Customer In Sorting Order" << endl;
	cout<<"----------------------------------------------------"<<endl;
	if (count_user==0) {
		cout<<"No Records Found"<<endl;
	}
	else 
	{
		cout<<"Name"<<"\t\t"<<"UserName"<<"\t\t"<<"Password"<<"\t\t"<<"AccountType"<<"\t\t"<<"PhoneNumber"<<"\t\t"<<"AccountNumber"<<"\t"<<"Balance"<<endl;
		string temp1,temp2,temp3,temp4;
		double temp6,temp7;
		string temp5;
		int largest=-1;
	for (int i=0 ; i<count_user ; i++)
	{
	for (int j=i+1 ; j<count_user ; j++)
	{
	if (moneyAs[j]>moneyAs[i])
	{
		//Balance sort
		temp7=moneyAs[j];
		moneyAs[j]=moneyAs[i];
		moneyAs[i]=temp7;
		//Name Sort
		temp1=nameAs[j];
		nameAs[j]=nameAs[i];
		nameAs[i]=temp1;
		//User Sort
		temp2=usernameAs[j];
		usernameAs[j]=usernameAs[i];
		usernameAs[i]=temp2;
		//pass sort
		temp3=passwordAs[j];
		passwordAs[j]=passwordAs[i];
		passwordAs[i]=temp3;
		//Type sort
		temp4=typeAs[j];
		typeAs[j]=typeAs[i];
		typeAs[i]=temp4;
		//phone sort
		temp5=phoneAs[j];
		phoneAs[j]=phoneAs[i];
		phoneAs[i]=temp5;
		//account number sort
		temp6=accountnumberAs[j];
		accountnumberAs[j]=accountnumberAs[i];
		accountnumberAs[i]=temp6;
				
	}
	}
	    cout<<nameAs[i]<<"\t\t"<<usernameAs[i]<<"\t\t\t"<<passwordAs[i]<<"\t\t\t"<<typeAs[i]<<"\t\t\t"<<phoneAs[i]<<"\t\t\t"<<accountnumberAs[i]<<"\t\t"<<moneyAs[i]<<endl;	}
}

  clearscreen();
}

void userdata()
{

//For Storing Customer Information
    fstream file;
	file.open("user_data.txt",ios::out);
	for (int i=0 ; i<count_user ; i++)
	{
	if (nameA[i] == "\0" )
    {
        continue;
    }
    else
    {
        
		file<<nameA[i]<<","<<usernameA[i]<<","<<passwordA[i]<<","<<typeA[i]<<","<<phoneA[i]<<","<<accountnumberA[i]<<","<<moneyA[i]<<endl;
	}
    }
	file.close();
}

void storedepositmoney()
{
    //For Storing Deposit money
    fstream file;
	file.open("deposit_money.txt",ios::out);
	for (int i=0 ; i<count_user ; i++) {
	if (ind[i]!=-1) 
	{  
		file<<ind[i]<<","<<dateA[i]<<","<<purposeA[i]<<","<<balanceA[i]<<endl;
		ind[i]=ind[i];
    }
    else
    {
	    continue;
    }
    }
	file.close();
}

void storewithdrawmoney()
{
    fstream file;
	//For Withdarw Money
	file.open("withdraw_money.txt",ios::out);
	for (int i=0 ; i<count_user ; i++) {
	if (ind[i]!=-1) 
    {
    
		file<<ind[i]<<","<<dateA2[i]<<","<<purposeA2[i]<<","<<balanceA2[i]<<endl;
		ind[i]=ind[i];
    }
    else
    {
	continue;
	}
    }
	file.close();
}
void storetransact()
{

	//for Storing Transact Money
	    fstream file;
	file.open("transact_money.txt",ios::out);
	for (int i=0 ; i<count_user ; i++) 
	{
	if (ind[i]!=-1)  
	{
		int x=ind[i];
		int y=ind2[idx3];
		file<<ind[x]<<","<<y<<","<<dateA3[x]<<","<<balanceA3[x]<<endl;
		ind2[i]=ind2[i];
    }
    else
    {
	   continue;
	}
    }
	file.close();
}

void storetotal()
{
	//Storing Balance Details
	fstream file;
	file.open("total_money.txt",ios::out);
	for (int i=0;i<count_user ; i++)
	{
	if (intial[i]>0)
	{
	    file<<intial[i]<<","<<total1[i]<<","<<total2[i]<<","<<total3[i]<<","<<total4[i]<<","<<moneyA[i]<<endl;
    }
	}
	file.close();	
}

string parse_data(string line, int index)
{
   //For Comma Separting
    int comma_count = 1;
    string item;
    int idx = 0;
    char ch = '!';
    while (ch != '\0')
    {
	     ch = line[idx];
	if ( ch == ',')
	{
		 comma_count = comma_count + 1 ;   
	}
	if (comma_count == index)
	{
		if (ch != ',')
		{
		item = item + ch;   
		}
	}
	if (ch == '\0' )
	{
		return item;
	}
	idx++;          
    }
    return item;
}
//For Reading customer data
void loaduserdata()
{
	fstream newfile;
	newfile.open("user_data.txt" , ios::in);
    int index = 0;
    string line = "1";
    while (line != "\0")
    {
        getline(newfile , line );
        nameA[index]= parse_data(line ,1);
        nameAs[index]= parse_data(line ,1);
        usernameA[index] = parse_data(line ,2);
        usernameAs[index] = parse_data(line ,2);
        passwordA[index] = parse_data(line , 3);
        passwordAs[index] = parse_data(line , 3);
        typeA[index] = parse_data(line , 4);
        typeAs[index] = parse_data(line , 4);
        phoneA[index]= parse_data(line , 5); //String to Integer
        phoneAs[index]=parse_data(line , 5); 
        chk2= parse_data(line , 6); //String to Integer
        stringstream b(chk2);
        stringstream b1(chk2);
        b>>accountnumberA[index];
        b1>>accountnumberAs[index];
        chk3 = parse_data(line , 7); //String to Integer
        stringstream c(chk3);
        stringstream c1(chk3);
        c>>moneyA[index];
        c1>>moneyAs[index];
        count_user++;
        index++;
    }
		count_user=count_user-1;
		newfile.close(); 
}

void total_money()
{
	//For Storing Total Money
	fstream file;
	file.open("total_money_in_bank.txt",ios::out);
	file<<totalmoneyinbank;
	file.close();	
}
//For Reading Total Money in the bank
void loadtotal_money()
{
	
	fstream file;
	file.open("total_money_in_bank.txt",ios::in);
	string line;
	getline(file,line);
	stringstream a(line);
	a>>totalmoneyinbank;
	file.close();
}
//For Loading Deposit Money
void loaddepositmoney()
{
	fstream file;
	int temp;
	file.open("deposit_money.txt",ios::in);
	int index = 0;
    string line = "1";
    while (line != "\0")
    {
        getline(file , line );
        string ind= parse_data(line ,1);
        stringstream d(ind);
        d>>temp;
        string ck = parse_data(line ,2);
        stringstream a(ck);
        a>>dateA[temp];
        purposeA[temp]= parse_data(line , 3); 
        string ck1= parse_data(line , 4); 
        stringstream b(ck1);
        b>>balanceA[temp];
        count_user++;
        index++;
    }
    count_user=count_user-1;
    file.close(); 
}
//For loading withdraw Money
void loadwithdrawmoney()
{
	fstream file;
	int temp;
	file.open("withdraw_money.txt",ios::in);
	int index = 0;
    string line = "1";
    while (line != "\0")
    {
        getline(file , line );
        string ind= parse_data(line ,1);
        stringstream d(ind);
        d>>temp;
        string ck = parse_data(line ,2);
        stringstream a(ck);
        a>>dateA2[temp];
        purposeA2[temp]= parse_data(line , 3); 
        string ck1= parse_data(line , 4); 
        stringstream b(ck1);
        b>>balanceA2[temp];
        count_user++;
        index++;
    }
    count_user=count_user-1;
    file.close(); 
}
//For Load Money Of customers
void loadtotalmoney()
{
	fstream file;
	file.open("total_money.txt",ios::in);
	int index = 0;
    string line = "1";
    while (line != "\0")
    {
        getline(file , line );
        string ck1= parse_data(line ,1);
        stringstream a(ck1);
        a>>intial[index];
        string ck2 = parse_data(line ,2);
        stringstream b(ck2);
        b>>total1[index];
        string ck3= parse_data(line , 3); 
        stringstream c(ck3);
		c>>total2[index]; 
        string ck4= parse_data(line , 4); 
        stringstream d(ck4);
        d>>total3[index];
        string ck5= parse_data(line , 5); 
        stringstream e(ck5);
        e>>total4[index];
        string ck6= parse_data(line , 6); 
        stringstream f(ck6);
        f>>moneyA[index];
        count_user++;
        index++;
    }
    count_user=count_user-1;
    file.close(); 
}
//For Loading all Function
void loaddata()
{
	loaduserdata();
	loadtotal_money();
	loaddepositmoney();
	loadwithdrawmoney();
	loadtotalmoney();
}
void updateaccount()
{
	string fuser;
	header();
	cout<<"Home > Admin > EditAccount"<<endl;
	cout<<"--------------------------"<<endl;
	cout<<"Enter a User Name to Search : ";
	cin>>fuser;
	bool check=false;
	int breakk=0;
	for (int i=0 ; i<count_user ; i++)
	{
	if (fuser == usernameA[i])
	{
		check=true;
		if (breakk==1)
		{
			breakk=0;
			break;
		}
		editidx=i;
		while (true)
		{
			system("cls");
		header();
		cout<<"Home > Admin > EditAccount Menu"<<endl;
		cout<<"--------------------------"<<endl;
		cout<< "[1]- Edit a Account number"<<endl;
		cout<< "[2]- Edit a Balance "<<endl;
		cout<< "[3]- Edit a Phone Number "<<endl;
		cout<< "[4]- Exit                "<<endl;
		cout<< "Your Option.............. ";
		cin>>editoption;
		system("cls");
		if (editoption=="4") {
            breakk=1;
			userdata();
			break;
			
		}
		edit(editoption);
		}

	}
	}

	if (check==false) {
		cout<<"No Such Username Account available"<<endl;
		clearscreen();
	}
    

}
void edit(string n)
{
	if (editoption=="1") {
		header();
		cout<<"Home > Admin > Edit Account > Edit AccountNumber"<<endl;
		cout<<"------------------------------------------------"<<endl;
		cout<<"Old Account Number is :"<< accountnumberA[editidx]<<endl;
		while(accountnumberA) 
		{
		cout<<"Enter New AccountNumber to edit : ";
		cin>>accountnumberA[editidx];
		if (accountnumberA[editidx]<999999 && accountnumberA[editidx]>99999)
		{
			clearscreen();
			break;
		}
		else {
			SetConsoleTextAttribute(h,4);
			cout<<"Please enter 6 number Figure!!!!"<<endl;
			SetConsoleTextAttribute(h,11);
		}
		}
	}
	if (editoption=="2") {
		header();
		cout<<"Home > Admin > Edit Account > Edit Balance"<<endl;
		cout<<"------------------------------------------"<<endl;
		cout<<"Old Balance is :"<< moneyA[editidx]<<endl;
		cout<<"Enter New Balance to edit : ";
		cin>>moneyA[editidx];
		clearscreen();
	}
	if (editoption=="3") {
		header();
		cout<<"Home > Admin > Edit Account > Edit Phone"<<endl;
		cout<<"----------------------------------------"<<endl;
		cout<<"Old Phone Number is :"<< phoneA[editidx]<<endl;
		cout<<"Enter New PhoneNumber to edit : ";
		cin>>phoneA[editidx];
		clearscreen();
	}
}
//Function Defination End----------------------------------------------------------
