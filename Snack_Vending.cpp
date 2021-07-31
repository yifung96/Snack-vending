//Programmer's details :
//name : CHOONG YI FUNG
//no.matrix: 130909
//School: Electrical and Electronic (Mechatronic)
//Project Title: Snack vending machine 
//Project purpose: To let user choose the snacks and receive orders .
//Assumption: User is able to read and understand the instructions given for example if it is out of stocks , dont
//			  pick the items .

#include <iostream>//for input , output
#include <cstring>//for string application
#include <cmath>//for math calculation
#include <fstream>//for file input/output
#include <stdlib.h>//for system("cls"), system ("pause")
#include <windows.h>//for Sleep()
#include<iomanip>//for setw 

using namespace std;

struct database // using structure named 'database'
{
	string snacks;
	string stock;
	
};

void wlc();//To display welcoming message
void menu(database[] , int&);//To display menu
void get_cash(float&);//to obtain money from user 
void display_stock();//To display the stocks left for the snacks
void display_choi(float );//To display the choices of snacks available 
void get_choi(int& , float);//To obtain choices made by user
void pchoice(int  , float , float& );//To process the choices obtained and return change
void edit_stock( int);//To edit the number of stocks left
void exit();//To display exit message 

float A,B,C,D,E,F,G,H,I,J;//To declare globally the number of stocks
float sum , chg;//To declare globally the sum and change

int main()
{
	database data[10];	// declare structure database with variable name 'data'
	int choi , j;//declare int j for array // int choi for choice 
	char opt1;//declare locally opt1 
	wlc();
	system("cls");
	menu(data , j);
	cout<<"\t\tIf you wish to proceed , kindly press '1' and we'll proceed to money input .\n"<<endl;
	cout<<"\t\tWhile press '0' to exit the program ."<<endl;
	bool opt1_repeat;//using boolean do-while
	do
	{
		
		cin>>opt1;
		if (opt1=='1')
		{
			opt1_repeat=false;
			system("cls");
			get_cash(sum);
			display_stock();
			display_choi(sum);	
			get_choi(choi , sum);
			edit_stock( choi );
			pchoice(choi , sum , chg );
			
			exit();
		}
		else if (opt1=='0')
		{
			opt1_repeat=false;
			system("cls");
			exit();
		}
		else
		{
			opt1_repeat=true;
			cout<<"\t\tINVALID Please press only either '1' OR '0'.\n\n "<<endl;
		}
	}
	while(opt1_repeat==true);
	
	
}

void wlc()//displaying welcoming message
{
	for(int repeat=0;repeat<3;repeat++)
	{
	
	cout<< "\n\n\n\n";
	cout<< "\t\t**               ** *********  **          ****      *****    ****      ****  *********       \n";
	cout<< "\t\t **     **      **  ****       **        **    **  **     **  ****      ****  ****            \n";
	cout<< "\t\t  **  ******   **   *********  **       **         **     **  ** **    ** **  *********       \n";  
	cout<< "\t\t   ** *** *** **    ****       **       **         **     **  **  **  **  **  ****            \n";
	cout<< "\t\t    ****   ****     ****       **        **    **  **     **  **   ****   **  ****            \n";
	cout<< "\t\t     **     **      *********  *********   *****     *****    **    **    **  *********       \n\n\n";
	
	cout<< "\t\t                                **********     *****                                   \n";
	cout<< "\t\t                                    **       **     **                                 \n";
	cout<< "\t\t                                    **       **     **                                 \n";
	cout<< "\t\t                                    **       **     **                                 \n";
	cout<< "\t\t                                    **       **     **                                 \n";
	cout<< "\t\t                                    **         *****                                   \n\n\n";
	Sleep (300);
	system("cls");		
	Sleep (300);
	}

	cout<< "\t\t\tWELCOME TO THE ULTIMATE SNACK MACHINE!!! \n\n";
	cout<< "\t\t\tThis machine contains up to 10 variations of snacks !!\n";
	cout << endl;
	cout << "\t\t\tA Mini C++ Project by CHOONG YI FUNG (134909)\n\n";
	cout << "**************************************************************************************************************";
	cout << endl << endl;

	cout<<"Press any key to proceed to menu ."<<endl;
	getchar();
}

void menu(database data[] , int&j)//Displaying menu from text file ("Snacks.txt)
{
	string snacks;
	ifstream file_in;
	file_in.open("Snacks.txt");
	cout<<"\t\t\t-------MENU-------\t\t\t\n\n"<<endl;
	cout<<"\t\tSNACKS\n\n"<<endl;
	for (int i=0 ; i<10 ; i++)
	{
		file_in>>data[j].snacks;
		file_in.ignore();
		cout<<"\t\t"<<data[j].snacks<<"\n\n";
	}
	file_in.close();
	
}



void get_cash(float&sum)//To obtain money in purchasing the snacks 
{
	int m1,m2,m3;
	cout<<"\t\t*********************************************************************************"<<endl;
	cout<<"\t\t"<<setw(50)<<"TERMS AND CONDITIONS"<<setw(10)<<""<<endl;
	cout<<"\t\t"<<setw(56)<<"****************************\n\n\n"<<setw(10)<<""<<endl;
	cout<<"\t\t"<<setw(40)<<"1. THIS MACHINE ONLY ACCEPT RM1 , RM5 AND RM10\n\n"<<setw(10)<<""<<endl;
	cout<<"\t\t"<<setw(40)<<"2. PLEASE PLACE YOUR MONEY APPROPRIATELY INTO THE SECTION PROVIDED\n\n"<<setw(5)<<""<<endl;
	cout<<"\t\t"<<setw(35)<<"3. PLEASE USE THE MACHINE WISELY .\n\n\n"<<setw(10)<<""<<endl;
	cout<<"\t\t*********************************************************************************"<<endl;
	
	bool cash_repeat;//Using boolean to make sure the amount input is on par with the conditions
	do
	{
		cout<<"\t\tPlease kindly place the amount of money into the section provided .\n\n\n"<<endl;
		cout<<"\t\t\tRM 1.00 = ";
		cin>>m1;
		cout<<"\t\t\tRM 5.00 = ";
		cin>>m2;
		cout<<"\t\t\tRM 10.00 = ";
		cin>>m3;
		system("cls");
		sum=(m1*1)+(m2*5)+(m3*10);
		
		if (sum<= 0)
		{
			cash_repeat=true;
			cout<<"\n\t\tPlease make sure the amount of money is at least RM 1\n"<<endl;
		}
		else
		{
			cash_repeat=false;
		}
	}
	while(cash_repeat==true);
	
	for(int repeat=0;repeat<3;repeat++)//Display loading message
	{
		system("cls");
    	cout << "\n\n\n";
    	cout << "\t\t  @@     @@@      @@    @@@@    @@    @    @@    @@@@@    \n";
  		cout << "\t\t  @@    @   @    @  @   @   @   @@    @@   @@  @@    @    \n";
  		cout << "\t\t  @@    @   @   @    @  @   @   @@    @@@  @@  @@         \n";
  		cout << "\t\t  @@    @   @   @@@@@@  @   @   @@    @@ @ @@  @@   @@@   @@  @@  @@  @@ \n";
  		cout << "\t\t  @@@@   @@@    @    @  @@@@    @@    @@  @@@   @@@@@@    @@  @@  @@  @@ \n";
  		Sleep (300);
		system("cls");
		Sleep (300);
		}
	cout<<"\n\n\n\t\tThe amount input is RM  "<<sum<<"\n\n\n"<<endl;//Display sum input 
	
	cout<<"Press any key to proceed to snacks selection ."<<endl;
	getchar();	
}

void display_stock()//To display stocks from 10 text files 
{	
	cout<<"\n\n\tSTOCKS left in the machine : \n"<<endl;
	ifstream aout;
	aout.open("A.txt");
	for(int i=1 ; i<2 ; i++)
	{
		aout>>A;
		if(A==0)
			cout<<"Alphabets is currently out of stocks .\n"<<endl;//condition of out of stock
		else
			cout<<"Alphabets == "<<A<<""<<endl;
	}
	aout.close();
	
	ifstream bout;
	bout.open("B.txt");
	for(int i=1 ; i<2 ; i++)
	{
		bout>>B;
		if(B==0)
		{
			cout<<"Bika is currently out of stocks .\n"<<endl;
		}
		else
			cout<<"Bika      == "<<B<<""<<endl;
	}
	bout.close();
	
	ifstream Cout;
	Cout.open("C.txt");
	for(int i=1 ; i<2 ; i++)
	{
		Cout>>C;
		if(C==0)
		{
			cout<<"Choki is currently out of stocks .\n"<<endl;
		}
		else
			cout<<"Choki     == "<<C<<""<<endl;
	}
	Cout.close();
	
	ifstream dout;
	dout.open("D.txt");
	for(int i=1 ; i<2 ; i++)
	{
		dout>>D;
		if(D==0)
		{
			cout<<"Decker is currently out of stocks .\n"<<endl;
		}
		else
			cout<<"Decker    == "<<D<<""<<endl;
	}
	dout.close();
	
	ifstream eout;
	eout.open("E.txt");
	for(int i=1 ; i<2 ; i++)
	{
		eout>>E;
		if(E==0)
			cout<<"Nachos is currently out of stocks .\n"<<endl;
		else
			cout<<"Nachos    == "<<E<<""<<endl;
	}
	eout.close();
	
	ifstream Fout;
	Fout.open("F.txt");
	for(int i=1 ; i<2 ; i++)
	{
		Fout>>F;
		if(F==0)
			cout<<"Fries is currently out of stocks .\n"<<endl;
		else
			cout<<"Fries     == "<<F<<""<<endl;
	}
	Fout.close();
	
	ifstream gout;
	gout.open("G.txt");
	for(int i=1 ; i<2 ; i++)
	{
		gout>>G;
		if(G==0)
			cout<<"Apollo is currently out of stocks .\n"<<endl;
		else
			cout<<"Apollo    == "<<G<<""<<endl;
	}
	gout.close();
	
	ifstream hout;
	hout.open("H.txt");
	for(int i=1 ; i<2 ; i++)
	{
		hout>>H;
		if(H==0)
			cout<<"Roller is currently out of stocks .\n"<<endl;
		else
			cout<<"Roller    == "<<H<<""<<endl;
	}
	hout.close();
	
	ifstream iout;
	iout.open("I.txt");
	for(int i=1 ; i<2 ; i++)
	{
		iout>>I;
		if(I==0)
			cout<<"M&M is currently out of stocks .\n"<<endl;
		else
			cout<<"M&M       == "<<I<<""<<endl;
	}
	iout.close();
	
	ifstream jout;
	jout.open("J.txt");
	for(int i=1 ; i<2 ; i++)
	{
		jout>>J;
		if(J==0)
			cout<<"Chupa is currently out of stocks .\n"<<endl;
		else
			cout<<"Chupa     == "<<J<<""<<endl;
	}
	jout.close();
}
void display_choi(  float sum )//To display choice for snacks based on the condition of sum
{
	cin.ignore();
	string snacks[10];
	ifstream fout;
	fout.open("Snacks.txt");

	for(int i=0;i<10;i++)//Every line is read
	{
		getline(fout , snacks[i]);
	}
	
	if (sum==1)
	{
		for(int i=0 ; i<3 ; i++)//Only specified line is read
		{
			cout<<snacks[i]<<endl;
			ifstream fout;
			
		}
	}
	else if (sum<=2)
	{
		for (int i=0 ; i<6 ; i++)
		{
			cout<<snacks[i]<<endl;
		}
	}
	else if (sum<=3)
	{
		for (int i=0 ; i<9 ; i++)
		{
			cout<<snacks[i]<<endl;
		}
	}
	else
	{
		for(int i=0 ; i<10 ; i++)
		{
			cout<<snacks[i]<<endl;
		}
	}
	fout.close();	
}
void get_choi(int& choi, float sum )//To obtain choices 
{									//Declare call by ref 
	if (sum==1)
	{
		bool choi_repeat1;//Usinf boolean to identiy the outcome according to the condition
		do
		{
			cout<<"Please make your selection based on the snack code (1-3) ."<<endl;
			cin>>choi;
			
			if(choi > 0 && choi<= 3 )
			{
				choi_repeat1=false;
			}
			else
			{
				choi_repeat1=true;
				cout<<"\t\t\tINVALID INPUT\n"<<endl;
				cout<<"Please make your selection again ."<<endl;
			}
		}
		while (choi_repeat1==true);
	}
	else if (sum<=2)
	{
		bool choi_repeat2;
		do
		{
			cout<<"Please make your selection based on the snack code (1-6) ."<<endl;
			cin>>choi;
			if(choi > 0 && choi<= 6 )
			{
				choi_repeat2=false;
			}
			else
			{
				choi_repeat2=true;
				cout<<"\t\t\tINVALID INPUT\n"<<endl;
				cout<<"Please make your selection again ."<<endl;
			}
		}
		while (choi_repeat2==true);
	}
	else if (sum<=3)
	{
		bool choi_repeat3;
		do
		{
			cout<<"Please make your selection based on the snack code (1-9) ."<<endl;
			cin>>choi;
			if(choi > 0 && choi<= 9 )
			{
				choi_repeat3=false;
			}
			else
			{
				choi_repeat3=true;
				cout<<"\t\t\tINVALID INPUT\n"<<endl;
				cout<<"Please make your selection again ."<<endl;
			}
		}
		while (choi_repeat3==true);
	}
	else 
	{
		bool choi_repeat4;
		do
		{
			cout<<"Please make your selection based on the snack code (1-10) ."<<endl;
			cin>>choi;
			if(choi > 0 && choi<= 10)
			{
				choi_repeat4=false;
			}
			else
			{
				choi_repeat4=true;
				cout<<"\t\t\tINVALID INPUT\n"<<endl;
				cout<<"Please make your selection again ."<<endl;
			}
		}
		while (choi_repeat4==true);
	}
	
}

void pchoice(int choi , float sum , float&chg   )//Process the choices made and display the change returned 
{
	if (choi> 0 && choi<=10)
	{
		switch (choi)
		{
			case 1 :
				{
					cout<<"1.Alphabets....... is confirmed . Please wait for a while .\n"<<endl;
					chg=sum-1;
					cout<<"Change returned = RM "<<chg<<""<<endl;
					
				}
			break;
			case 2 :
				{
					cout<<"2.Bika....... is confirmed . Please wait for a while .\n"<<endl;
					chg=sum-1;
					cout<<"Change returned = RM "<<chg<<""<<endl;
					
				}
			break;
			case 3 :
				{
					cout<<"3.Choki....... is confirmed . Please wait for a while .\n"<<endl;				
					chg=sum-1;
					cout<<"Change returned = RM "<<chg<<""<<endl;
					
				}
			break;
			case 4 :
				{
					cout<<"4.Decker....... is confirmed . Please wait for a while .\n"<<endl;
					chg=sum-2;
					cout<<"Change returned = RM "<<chg<<""<<endl;
				}
			break;
			case 5 :
				{
					cout<<"5.Nachos....... is confirmed . Please wait for a while .\n"<<endl;
					chg=sum-2;
					cout<<"Change returned = RM "<<chg<<""<<endl;
				}
			break;
			case 6 :
				{
					cout<<"6.Fries....... is confirmed . Please wait for a while .\n"<<endl;
					chg=sum-2;
					cout<<"Change returned = RM "<<chg<<""<<endl;
					
				}
			break;
			case 7 :
				{
					cout<<"7.Apollo....... is confirmed . Please wait for a while .\n"<<endl;
					
					chg=sum-3;
					cout<<"Change returned = RM "<<chg<<""<<endl;
				
				}
			break;
			case 8 :
				{
					cout<<"8.Roller....... is confirmed . Please wait for a while .\n"<<endl;
					
					chg=sum-3;
					cout<<"Change returned = RM "<<chg<<""<<endl;
				
				}
			break;
			case 9 :
				{
					cout<<"9.M&M....... is confirmed . Please wait for a while .\n"<<endl;
					
					chg=sum-3;
					cout<<"Change returned = RM "<<chg<<""<<endl;
					
				}
			break;
			case 10 :
				{
					cout<<"10.Chupa....... is confirmed . Please wait for a while .\n"<<endl;
					
					chg=sum-1;
					cout<<"Change returned = RM "<<chg<<""<<endl;
				
				}
			break;
		}
	}
	else
	{
		cout<<"INVALID CHOICE :: ERROR"<<endl;
	}
	
}

void edit_stock( int choi)//To update the stocks available from the text files 
{
	for (int i=0 ; i<3 ; i++)
	{
		cout<<"\t\tEditing stocks ........"<<endl;
		Sleep(300);
		system ("cls");
		cout<<"\t\tEditing stocks......................"<<endl;
		Sleep(300);
		system("cls");
		Sleep(300);
	}
	float can[20];
	if (choi> 0 && choi<=10)
	{
		switch (choi)
		{
			case 1 :
				{
					ifstream fout;
					fout.open("A.txt" );
					float a;
					for (int i=1 ; i<2 ; i++)
					{
						fout>>can[1];
						can[1]--;//Decrease the stock by 1
			
						ofstream fin;
						fin.open("A.txt" );
						for (int i=1 ; i<2 ; i++)
						{fin<<can[1];}
						fin.close();
					}
					fout.close();	
				}
			break;
			case 2 :
				{
					ifstream fout;
					fout.open("B.txt" );
					float a;
					for (int i=1 ; i<2 ; i++)
					{
						fout>>can[1];
						can[1]--;
			
						ofstream fin;
						fin.open("B.txt" );
						for (int i=1 ; i<2 ; i++)
						fin<<can[1];
						fin.close();
					}
					fout.close();	
					
				}
			break;
			case 3 :
				{
					ifstream fout;
					fout.open("C.txt" );
					float a;
					for (int i=1 ; i<2 ; i++)
					{
						fout>>can[1];
						can[1]--;
			
						ofstream fin;
						fin.open("C.txt" );
						for (int i=1 ; i<2 ; i++)
						fin<<can[1];
						fin.close();
					}
					fout.close();	
					
				}
			break;
			case 4 :
				{
					ifstream fout;
					fout.open("D.txt" );
					float a;
					for (int i=1 ; i<2 ; i++)
					{
						fout>>can[1];
						can[1]--;
			
						ofstream fin;
						fin.open("D.txt" );
						for (int i=1 ; i<2 ; i++)
						fin<<can[1];
						fin.close();
					}
					fout.close();	
				}
			break;
			case 5 :
				{
					ifstream fout;
					fout.open("E.txt" );
					float a;
					for (int i=1 ; i<2 ; i++)
					{
						fout>>can[1];
						can[1]--;
			
						ofstream fin;
						fin.open("E.txt" );
						for (int i=1 ; i<2 ; i++)
						fin<<can[1];
						fin.close();
					}
					fout.close();	
				}
			break;
			case 6 :
				{
					ifstream fout;
					fout.open("F.txt" );
					float a;
					for (int i=1 ; i<2 ; i++)
					{
						fout>>can[1];
						can[1]--;
			
						ofstream fin;
						fin.open("F.txt" );
						for (int i=1 ; i<2 ; i++)
						fin<<can[1];
						fin.close();
					}
					fout.close();	
					
				}
			break;
			case 7 :
				{
					ifstream fout;
					fout.open("G.txt" );
					float a;
					for (int i=1 ; i<2 ; i++)
					{
						fout>>can[1];
						can[1]--;
			
						ofstream fin;
						fin.open("G.txt" );
						for (int i=1 ; i<2 ; i++)
						fin<<can[1];
						fin.close();
					}
					fout.close();	
				
				}
			break;
			case 8 :
				{
					ifstream fout;
					fout.open("H.txt" );
					float a;
					for (int i=1 ; i<2 ; i++)
					{
						fout>>can[1];
						can[1]--;
			
						ofstream fin;
						fin.open("H.txt" );
						for (int i=1 ; i<2 ; i++)
						fin<<can[1];
						fin.close();
					}
					fout.close();	
				
				}
			break;
			case 9 :
				{
					ifstream fout;
					fout.open("I.txt" );
					float a;
					for (int i=1 ; i<2 ; i++)
					{
						fout>>can[1];
						can[1]--;
			
						ofstream fin;
						fin.open("I.txt" );
						for (int i=1 ; i<2 ; i++)
						fin<<can[1];
						fin.close();
					}
					fout.close();	
					
				}
			break;
			case 10 :
				{
					ifstream fout;
					fout.open("J.txt" );
					float a;
					for (int i=1 ; i<2 ; i++)
					{
						fout>>can[1];
						can[1]--;
			
						ofstream fin;
						fin.open("J.txt" );
						for (int i=1 ; i<2 ; i++)
						fin<<can[1];
						fin.close();
					}
					fout.close();	
				
				}
			break;
		}
	}
	else
	{
		cout<<"INVALID CHOICE :: ERROR"<<endl;
	}
	
}




void exit()//Display exit message 
{
	cout<<"\n\n\n\t\t\tTHANK YOU for serving with us \n\n"<<endl;
	cout<<"\t\t\tWe hope to serve you again \n\n"<<endl;
}


