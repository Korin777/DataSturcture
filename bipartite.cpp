#include<iostream>
using namespace std;

struct nodee
{
    nodee *next;
    int vertex;
};

struct node
{
    nodee *next = NULL;
    int group;
};


void insert(nodee **first,int vertex)
{
    nodee *tmp = new nodee;
    tmp -> vertex = vertex;
    nodee *current = *first;
    if(*first)
    {
    while(current -> next != NULL)
    {
        current = current -> next;
    }
    current -> next = tmp;
    }
    else
    {
        *first = tmp;
    }
    return;
}

nodee *v1 = NULL,*v2 = NULL;


bool bipartite(node vertex[], int nvertex)
{
    for(int i = 0; i < nvertex; i++)        
    {
        if(vertex[i].group == 0)
        {
            vertex[i].group = 1;
            insert(&v1,i);
        }
        nodee *current = vertex[i].next;
        while(current != NULL)
        {
            if(vertex[i].group == 1)
            {
                if(vertex[current -> vertex].group == 1)
                    return false;
                else
                {			
                    if(vertex[current -> vertex].group != 2)
                        insert(&v2, current -> vertex);
                    vertex[current -> vertex].group = 2;
                }
            }
            else
            {
                if(vertex[current -> vertex].group == 2)
                    return false;
                else
                {			
                    if(vertex[current -> vertex].group != 1)
                        insert(&v1, current -> vertex);
                    vertex[current -> vertex].group = 1;
                }
            }
            current = current ->next;
        }
    }
    cout << "true" << endl;
    nodee *current = v1;
    nodee *current2 = v2;
    while(current)
    {
		cout << current -> vertex << " ";
        current = current -> next;
    }
	cout << endl; 
	while(current2)
    {
		cout << current2 -> vertex << " ";
        current2 = current2 -> next;
    }
    cout << endl;    
    return true;
}


int main()
{
    int nvertex,nedge;
    cin >> nvertex >> nedge;
    node vertex[nvertex];
    for(int i = 0; i < nvertex; i++)
    {
        vertex[i].group = 0;
    }
    for(int i = 0; i < nedge; i++)
    {
        int m,n;
        cin >> m >> n;
        insert(&(vertex[m].next), n);    
    }
    bool isbipartite;
    isbipartite = bipartite(vertex, nvertex);
    if(!isbipartite)
    	cout << "false" << endl;
    return 0;
}
