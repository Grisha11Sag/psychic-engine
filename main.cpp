#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>


using namespace std;

struct BD
{
	string numberst;
	string sername;
	string name;
	string patronymic;
};

BD *stud, *stud1;
int kolvost=8;

void vivodspiska()
{
	cout<<endl<<"******************************\n\n\n\n\n"<<endl<<endl<<endl;
	for (int i=0; i<kolvost; i++)
	{
		cout<<stud[i].numberst<<" "<<stud[i].sername<<" "<<stud[i].name<<" "<<stud[i].patronymic<<endl;
		
	}
	
	
}

void dobavstd()
{
	for(int i=0;i<kolvost;i++)
	{
		stud1[i].numberst=stud[i].numberst;
		stud1[i].sername=stud[i].sername;
		stud1[i].name=stud[i].name;
		stud1[i].patronymic=stud[i].patronymic;
	}
		
	kolvost++;
	stud = new BD [kolvost];
	
	for(int i=0; i<kolvost-1;i++)
		{
			stud[i].numberst=stud1[i].numberst;
		stud[i].sername=stud1[i].sername;
		stud[i].name=stud1[i].name;
		stud[i].patronymic=stud1[i].patronymic;
		}
	
	cin>>stud[kolvost-1].numberst>>stud[kolvost-1].sername>>stud[kolvost-1].name>>stud[kolvost-1].patronymic;
	
	stud1= new BD[kolvost];
	
}

void udalstd()
{
	string tempo;
	cin>>tempo;
	for(int i=0;i<kolvost;i++)
	{
		stud1[i].numberst=stud[i].numberst;
		stud1[i].sername=stud[i].sername;
		stud1[i].name=stud[i].name;
		stud1[i].patronymic=stud[i].patronymic;
	}
	
	kolvost--;
	stud = new BD [kolvost];
	
	int j=0;
	
	for (int i=0; i<kolvost+1; i++)
	{
		if (stud1[i].numberst!=tempo)
		{
			stud[j].numberst=stud1[i].numberst;
			stud[j].sername=stud1[i].sername;
			stud[j].name=stud1[i].name;
			stud[j].patronymic=stud1[i].patronymic;
			j++;
		}
	}
	
	stud1= new BD [kolvost];	
	
}

void sortpoubv()
{
	string temp;
	for (int j=0;j<kolvost;j++)
	{
		for (int i=0;i<kolvost-1;i++)
		{
			if (stud[i].sername<stud[i+1].sername)
			 {
			 	temp =stud[i].sername;
			 	stud[i].sername=stud[i+1].sername;
			 	stud[i+1].sername=temp;
			 	
			 	temp=stud[i].name;
			 	stud[i].name=stud[i+1].name;
			 	stud[i+1].name=temp;
			 	
			 	temp=stud[i].numberst;
			 	stud[i].numberst=stud[i+1].numberst;
			 	stud[i+1].numberst=temp;
			 	
			 	temp=stud[i].patronymic;
			 	stud[i].patronymic=stud[i+1].patronymic;
			 	stud[i+1].patronymic=temp;
			 }
		}
	}
}

void sortpovzr()
{
	string temp1;
	for (int j=0;j<kolvost;j++)
	{
		for (int i=0;i<kolvost-1;i++)
		{
			if (stud[i].sername>stud[i+1].sername)
			 {
			 	temp1 =stud[i].sername;
			 	stud[i].sername=stud[i+1].sername;
			 	stud[i+1].sername=temp1;
			 	
			 	temp1=stud[i].name;
			 	stud[i].name=stud[i+1].name;
			 	stud[i+1].name=temp1;
			 	
			 	temp1=stud[i].numberst;
			 	stud[i].numberst=stud[i+1].numberst;
			 	stud[i+1].numberst=temp1;
			 	
			 	temp1=stud[i].patronymic;
			 	stud[i].patronymic=stud[i+1].patronymic;
			 	stud[i+1].patronymic=temp1;
			 }
		}
	}
}

void schit()
{
	
	ifstream fin("Baza.txt");
	for (int i=0; i<kolvost; i++ )
	{
		fin>>stud[i].numberst>>stud[i].sername>>stud[i].name>>stud[i].patronymic;
	}
	
}

void sohr()
{
	ofstream fout("Baza.txt");
	for (int i=0; i<kolvost; i++)
	{
		fout<<stud[i].numberst<<" "<<stud[i].sername<<" "<<stud[i].name<<" "<<stud[i].patronymic<<endl;
	}
}



int main() 
{
	
	
	
	stud = new BD[kolvost];
	stud1= new BD[kolvost];
	
	int k;

	while (true)
	{
	
	
	cout<<"************************"<<endl;
	cout<<"\tMenu"<<endl;
	cout<<"************************"<<endl<<endl;
	cout<<"Enter 0 to finish using the program"<<endl;
	cout<<"Enter 1 to display a list of students"<<endl;
	cout<<"Enter 2 to add a student to the list"<<endl;
	cout<<"Enter 3 to remove a student from the list"<<endl;
	cout<<"Enter 4 to sort the list descending"<<endl;
	cout<<"Enter 5 to sort the list in ascending order"<<endl;
	cout<<"Enter 6 to read the list from the file"<<endl;
	cout<<"Enter 7 to save the list to a file"<<endl<<endl;
	
	cout<<endl<<"--------------------------------"<<endl<<endl<<endl;
	cin>>k;
	
	if (k==0)
	{
		break;
	}
	  
	  switch (k)
	  {
	  	case (1):
	  		vivodspiska();
	  		break;
	  		
	  	case (2):
		  dobavstd();
		  break;
		  
		case (3):
		  udalstd();
		  break;
		  
		case (4):
		  sortpoubv();
		  break;
		  
		case (5):
		  sortpovzr();
		  break;
		  
		case (6):
		  schit();
		  break;
		  
		case (7):
		  sohr();
		  break;
		  
		default:
		  cout<<"ERROR!"<<endl;
		  break; 	
	  }
			
			
			 

}
	
		
	return 0;
}
