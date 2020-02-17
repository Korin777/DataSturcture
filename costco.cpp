#include<iostream>
using namespace std;
struct node
{
	char data;
	node *next;
	int group;

};

void insert(node **first,node *x,char a,int b)
{
	node *temp = new node;
	temp->data = a;
	temp->group = b;
	if(*first)
	{
		temp->next = x->next;
		x->next = temp;
	}
	else
	{
		temp->next = NULL;
		*first = temp;
	}
}
void defront(node **first,node *next)
{
	node *de = *first;
	*first = next;
	delete de;
}
int main()
{
	int group;
	int membersum;
	cin>>group;
	char member[group][26];
	for(int i =0;i<group;i++)
	{
		cin>>membersum;
		int j;
		for(j=0;j<membersum;j++)
		{
			cin>>member[i][j];
		}
		for(;j<26;j++)
		{
			member[i][j] = '0';
		}
	}
	node *first = NULL;
	string enorde;
	node *current;
	node *enfront;
	char en;
	while(!cin.eof())
	{
		cin>>enorde;
		if(enorde=="ENQUEUE")
		{
			cin>>en;
			int rgroup = -2;
			for(int i =0;i<group;i++)
			{
				for(int j=0;j<26;j++)
				{
					if(member[i][j]=='0')
						break;
					else
					{
						if(member[i][j]==en)
						{
							rgroup = i; 
							break;
						}
					}
				}
			}
			if(first==NULL)
				insert(&first,NULL,en,rgroup);
			else
			{
				bool flag = true;
				current = first;
				if(current==first)
				{
					if(rgroup==current->group)
					{
						enfront = new node;
						enfront->data = en;
						enfront->group = rgroup;
						enfront->next = current;
						first = enfront;
						enfront = NULL;
						flag = false;
					}
				}
				if(flag)
				{
				while(current->next!=NULL)
				{
					if(current->next->group==rgroup)
					{
						insert(&first,current,en,rgroup);
						flag = false;
						break;
					}
					current = current->next;
				}
				if(flag)
					if(rgroup!=-2)
						insert(&first,current,en,rgroup);
					else
						insert(&first,current,en,-1);
				}
			}

		}
		if(enorde=="DEQUEUE")
		{
			if(first!=NULL)
			{
				cout<<first->data<<endl;
				defront(&first,first->next);
			}
		}

	}
	return 0;
}
