#include<iostream>
using namespace std;

int parent[100];

void heightunion(int i, int j)
{
    int temp = parent[i] + parent[j];
    if(parent[i] > parent[j])
    {
        parent[i] = j;
        parent[j] = temp;
    }
    else
    {
        parent[j] = i;
        parent[i] = temp;
    }
}

int collapsingfind(int i)
{
    int move = 0;
    int root,trail,lead;
    for(root = i;parent[root] >= 0; root = parent[root])
        move++;
    for(trail = i; trail != root; trail = lead)
    {
        lead = parent[trail];
        parent[trail] = root;
        if(lead != root)
            move++;
    }
    return move;
}

int main()
{
    int tree;
    cin >>tree;
    for(int i = 0; i < tree; i++)
    {
        int node = 0;
        cin >> node;
        for(int j = 0; j < node; j++)
        {
            int index;
            cin >> index;
            cin >> parent[index];
        }
    }
    string option;
    cin >> option;
    while(1)
    {
        if(option == "UNION")
        {
            int i,j;
            cin >> i >> j;
            heightunion(i,j);
        }
        if(option == "FIND")
        {
        int i,move = 0;
        cin >> i;
        move = collapsingfind(i);
        cout << move << endl;
        }
        if(option == "STOP")
            break;
        cin >> option;
    }
    return 0;
}
