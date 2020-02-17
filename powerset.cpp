#include<iostream>
#include<string>
using namespace std;

void powerset(int a,bool b[],int record,string c[])
{
	if(a==record)
	{
		bool flag =false;
		cout<<"{";
		for(int i=0;i<record;i++)
		{
			if(b[i])
			{
				if(flag)
					cout<<" ";
				cout<<c[i];
				flag = true;
			}
			
		}
		cout<<"}";
		return;
	}
	else
	{
		b[a] = false;
		powerset(a+1,b,record,c);
		b[a] =true;
		powerset(a+1,b,record,c);
	}	
} 



int main()
{
	string a;
	while(!cin.eof())
	{
		int record = 1;
		getline(std::cin,a);
		for(int i=0;i<a.length();i++)
		{
			if(a[i]==' ')
			{
				record++;
			}
		}
		string b[record];
		int record1 = 0;
		int record2 = 0;
		int record3 = 0;
		for(int i=0;i<a.length()+1;i++)
		{
			record3++;
			if(a[i]==' '||a[i]=='\0')
			{
				b[record2].assign(a,record1,record3-1);
				record2++;
				record1 = i+1;
				record3 = 0;
			}
		}
		bool c[record];
		if(a.length()==0)
		{
			cout<<"{}";
		}
		else
			powerset(0,c,record,b);
		cout<<"\n";
		
	}
	return 0;

}

