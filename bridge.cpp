#include<iostream>
using namespace std;

struct nodee
{
    nodee *next = NULL;
    int vertex;
};

struct node
{
    nodee *next = NULL;
    int dfn = -1;
    int low = -1;
};

void bridge(node vertex[], int nvertex)
{
    for(int i = 0; i < nvertex; i++)
    {
        nodee *current = vertex[i].next;
        while(current)
        {
            if(vertex[i].low != vertex[current -> vertex].low && i < current -> vertex)
                cout << i << " " << current -> vertex << endl;
            current = current -> next;
        }
    }
    return;
}


void insert(nodee **first,int vertex)
{
    nodee *tmp = new nodee;
    tmp -> vertex = vertex;
    tmp ->next = NULL;
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

int num = 0;

void dfnlow(node vertex[], int u, int v)
{
    nodee *tmp;
    int w;
    vertex[u].dfn = vertex[u].low = num++;
    for(tmp = vertex[u].next; tmp; tmp = tmp ->next)
    {
        w = tmp -> vertex;
        if(vertex[w].dfn < 0)
        {
            dfnlow(vertex, w, u);
            if(vertex[w].low < vertex[u].low)
                vertex[u].low = vertex[w].low;
        }
        else if(w != v)
            if(vertex[w].low < vertex[u].low)
                vertex[u].low = vertex[w].low;
    }
}

int main()
{
    int nvertex,nedge;
    cin >> nvertex >> nedge;
    node vertex[nvertex];
    for(int i = 0; i < nedge; i++)
    {
        int m,n;
        cin >> m >> n;
        insert(&(vertex[m].next), n); 
        insert(&(vertex[n].next), m);
    }
    dfnlow(vertex, 0, -1);
    bridge(vertex, nvertex);
    return 0;
}
