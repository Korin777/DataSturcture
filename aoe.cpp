#include<iostream>
#include<iomanip>
using namespace std;

struct pre_activity
{
    int vertex;
    int activity;
    int value;
    pre_activity *next = NULL;
};

struct aoe
{
    pre_activity *next = NULL;
};

int sum = 0;

void compute(int ee[],aoe Aoe[],int i,int vertex,int pre_act)
{
    if(Aoe[vertex].next != NULL)
    {
        pre_activity *cur = Aoe[vertex].next;
        while(cur != NULL)
        {
            sum += cur->value;
            compute(ee,Aoe,i,cur->vertex,cur->value);
            sum -= cur ->value;
            cur = cur->next;
        }
        return;
    }
    else
    {
        if(sum > ee[i])
            ee[i] = sum;
        return;
    }
}

void computele(int le[],aoe Aoe[],int i,int ee[])
{
    if(Aoe[i].next != NULL)
    {
        pre_activity *cur = Aoe[i].next;
        while(cur != NULL)
        {
            le[cur -> vertex] = le[i] - cur -> value;
            cur = cur -> next;
        }
    }
    return;
}

void computee(aoe Aoe[], int ee[],int e[],int i)
{
    if(Aoe[i].next != NULL)
    {
        pre_activity *cur = Aoe[i].next;
        while(cur != NULL)
        {
            e[cur -> activity - 1] = ee[cur -> vertex];
            cur = cur -> next;
        }
    }

}

void computel(aoe Aoe[],int le[],int l[],int i, int ee[])
{
    if(Aoe[i].next != NULL)
    {
        pre_activity *cur = Aoe[i].next;
        while(cur != NULL)
        {
            if(cur -> vertex == 0)
            {
                l[cur -> activity - 1] = le[i] - ee[i];
            }
            else
                l[cur -> activity - 1] = le[cur ->vertex];
            cur = cur -> next;
        }
    }
}

int main()
{
    int N;
    cin >> N;
    aoe Aoe[N];
    int vrecord;
    for(int i = 0; i < N; i++)
    {
        int activity, pre_vertex, cur_vertex, act_value;
        cin >> activity >> pre_vertex >> cur_vertex >> act_value;
        pre_activity *new_pa = new pre_activity;
        new_pa -> vertex = pre_vertex;
        new_pa -> activity = activity;
        new_pa ->value = act_value;
        if(!Aoe[cur_vertex].next)
        {
            Aoe[cur_vertex].next = new_pa;
        }
        else
        {
            pre_activity *pa = Aoe[cur_vertex].next;
            while(pa -> next != NULL)
            {
                pa = pa -> next;
            }
            pa -> next = new_pa;
        }
        if(i == N-1)
            vrecord = cur_vertex;
    }
    int ee[vrecord + 1], le[vrecord + 1], e[N], l[N], slack[N];
    
    

    for(int i = 0; i < vrecord + 1; i++)
    {
        sum = 0;
        ee[i] = 0;
        compute(ee,Aoe,i,i,0);
    } 
    le[vrecord] = ee[vrecord];
    for(int i = vrecord; i > 0; i--)
    {
        computele(le,Aoe,i,ee);
    }
    le[0] = 0;
    for(int i = vrecord; i > 0; i--)
        computee(Aoe,ee,e,i);
    for(int i = vrecord; i > 0; i--)
        computel(Aoe,le,l,i,ee);
    for(int i = 0; i < N; i++)
    {
        slack[i] = l[i] - e[i];
    }
    cout << "event       ee          le\n";
    cout.fill(' ');
    cout.width(12);
    for(int i = 0; i < vrecord + 1; i++)
    {
        cout.fill(' ');
        cout.width(12);
        cout << left << i;
        cout.fill(' ');
        cout.width(12);
        cout << left << ee[i];
        cout.fill(' ');
        cout.width(12);
        cout << left << le[i];
        cout << endl;
    }
    cout << endl;
    cout << "act.        e           l           slack       critical\n";
    for(int i = 0; i < N; i++)
    {
        cout.fill(' ');
        cout.width(12);
        cout << left << i + 1;
        cout.fill(' ');
        cout.width(12);
        cout << left << e[i];
        cout.fill(' ');
        cout.width(12);
        cout << left << l[i];
        cout.fill(' ');
        cout.width(12);
        cout << left << slack[i];
        cout.fill(' ');
        cout.width(12);
        if(slack[i] == 0)
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }
    cout << endl;
    for(int i = 0; i < N; i++)
    {
        if(slack[i] == 0)
            cout << i + 1 << " ";
    }
    cout << endl;
    return 0;
}
