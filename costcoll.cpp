#include<iostream>
using namespace std;
int main()
{
    int group;
    int membersum;
    cin>>group;
    char member[group][26];
    for(int i = 0;i < group;i++)
    {
        cin>>membersum;
        int j;
        for(j = 0;j < membersum;j++)
        {
            cin >> member[i][j];
        }
        for(;j<26;j++)
        {
            member[i][j] = '0';
        }
    }
    string enorder;
    char queue[27];
    for(int i = 0;i < 27; i++)
    {
        queue[i] = '0';
    }
    int rear = 0;
    char en;
    while(!cin.eof())
    {
        cin>>enorder;
        if(enorder=="ENQUEUE")
        {
            cin >> en;        
        bool flag = false;
        int rgroup = -1;
        int insert;
        for(int i =0;i < group;i++)
        {
            if(flag)
                break;
            for(int j = 0;j < 26;j++)
            {
                if(member[i][j]=='0')
                    break;
                if(en == member[i][j])
                {
                    flag = true;
                    rgroup = i;
                    break;
                }
            }
        }
        flag = false;
        if(rgroup==-1)
        {
            queue[rear] = en;
            rear++;
        }
        else
        {
            for(int i =0;i < rear;i++)
            {
                if(flag)
                    break;
                for(int j = 0;j < 26;j++)
                {
                    if(member[rgroup][j] == '0')
                        break;
                    if(queue[i] == member[rgroup][j])
                    {
                        insert = i;
                        flag = true;
                        break;
                    }
                }            
            }
            if(flag)
            {
                for(int i = rear;i > insert;i--)
                {
                    queue[i] = queue[i-1];
                }
                queue[insert] = en;
                rear++;
            }
            else
            {
                queue[rear] = en;
                rear++;
            }
            
            
        }
        }
        else if(enorder == "DEQUEUE")
        {
            if(queue[0] != '0')
            {
            cout << queue[0] << endl;
            for(int i = 0;i <rear-1;i++)
            {
                queue[i] = queue[i+1];
            }
            queue[rear-1] = '0';
            rear--;
            }
        }
    }
    return 0;
}
