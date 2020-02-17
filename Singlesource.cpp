#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int choose(int distance[], int n, bool found[])
{
    int i,min,minpos;
    min = INT_MAX - 1;
    minpos = -1;
    for(i = 0; i < n; i++)
    {
        if(distance[i] < min && !found[i] && distance[i]!=min)
        {
            min = distance[i];
            minpos = i;
        }
    }
    return minpos;
}

void shortestpath(int v,int cost[][10],int distance[],int n,bool found[],int cgroup,vector<int> vec[],int group[])
{
    int i,u,w;
    for(int i = 0; i < n; i++)
    {
        found[i] = false;
        distance[i] = cost[v][i];
    }
    found[v] = true;
    distance[v] = 0;
    for(i = 0; i < n ; i++)
    {
        u = choose(distance, n, found);
        if(u!=-1)
        {
            group[u] = cgroup;
            found[u] = true;
            vec[cgroup].push_back(u);
        }
        bool flag = false;
        for(w = 0; w < n; w++)
        {
            if(!found[w])
            {
                if(distance[u] + cost[u][w] < distance[w] && distance[u] + cost[u][w] > 0 && u!=-1)
                {
                    distance[w] = distance[u] + cost[u][w];
                    flag = true;
                }
            }
        }
        if(!flag)
            cgroup++;
    }
}






int main()
{

while(!cin.eof())
{
    int N,M;
    int currentgroup = 0;
    int group[10];
    cin >> N >> M;
    int cost[N][10];
    int tail,head,cost1;
    bool found[10];
    vector<int> v[10]; 
    for(int i = 0; i < 10; i++)
        v[i].push_back(0);
    int distance[10];
    for(int i = 0; i < 10; i++)
        found[i] = false;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cost[i][j] = INT_MAX;
    for(int i = 0; i < M; i++)
    {
        cin >> tail >> head >> cost1;
        cost[tail][head] = cost1;
    }
    shortestpath(0,cost,distance,N,found,currentgroup,v,group);
    for(int i = 1; i < N; i++)
    {   
        int j = 0;
        if(!found[i])
            cout << "Impossible" <<endl;
        else
        {
            while(v[group[i]][j] != i)
            {
                cout << v[group[i]][j] << ",";
                j++;
            }
            cout << v[group[i]][j] << " ";
            cout << distance[i] << endl;
        }
    }
    return 0;
}
}
