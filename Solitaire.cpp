#include<iostream>
#include<random>
using namespace std;
int main()
{
	string cards[13];
	srand(time(NULL));
	string a[13] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
	string b[13] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
	int record = 0;
	int rd;
	int i;
	int p = 13;
	while(1)
	{
		if(p==0)
		{
			break;
		}
		rd = rand() % p;	
		cards[record] = a[rd];
		if(rd==p-1)
		{
			record++;
			p--;
		}
		else
		{
			a[rd] = a[p-1];
			record++;
			p--;
		}
		
	}
	record = 12;
	int record2 = 12;
	while(1)
	{
		if(cards[0]=="0")
		{
			break;
		}	
		else
		{}
		for(int i = 0;i<record2 + 1;i++)
		{
			cout<<cards[i]<<" ";
		}
		cout<<endl;
		if(cards[0] == b[record])
		{
			for(int i = 0;i<record2;i++)
			{
				cards[i] = cards[i+1];
			}
			cards[record2] = "0";
			record2--;
			record--;
		}
		else
		{
			string record3 = cards[0];
			for(int i = 0;i<record2;i++)
			{
				cards[i] = cards[i+1];
			}
			cards[record2] = record3;
		}
	}
	return 0;
}
