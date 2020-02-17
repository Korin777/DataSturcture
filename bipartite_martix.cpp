#include<iostream>
using namespace std;
int main()
{
    int vertex,edge;
    cin >> vertex >> edge;
    int node[vertex + 2 * edge];
    int input[edge][2];
    int erecord[vertex][vertex - 1];
    int erecord2[vertex];
    for(int i = 0; i < vertex; i++)
    {
        for(int j = 0; j < vertex - 1; j++)
        {
            erecord[i][j] = -1;
        }
    }
    for(int i = 0; i <vertex; i++)
    {
        erecord2[i] = 0;
    }
    int nrecord[vertex];
    for(int i = 0; i < vertex; i++)
    {
        nrecord[i] = 0;
    }
    for(int i = 0; i < edge;i++)
    {
        cin >> input[i][0] >> input[i][1];
        nrecord[input[i][0]]++;
        nrecord[input[i][1]]++;
        erecord[input[i][0]][erecord2[input[i][0]]] = input[i][1];
        erecord[input[i][1]][erecord2[input[i][1]]] = input[i][0];
        erecord2[input[i][0]]++;
        erecord2[input[i][1]]++;
    }
    node[0] = vertex;
    int tmp = 0;
    for(int i = node[0]; i < node[0] + nrecord[0]; i++)
    {
        node[i] = erecord[0][tmp];
        tmp++;
    }
    for(int i = 1; i < vertex; i++)
    {
           node[i] = node[i - 1] + nrecord[i - 1];
           tmp = 0;
           for(int j = node[i]; j < node[i] + nrecord[i]; j++)
           {
                node[j] = erecord[i][tmp];
                tmp++;
           }
    }
    int v1[vertex],v2[vertex];
    int tmp1 = 0,tmp2 = 0;
    bool fail = false;
    for(int i = 0; i < vertex; i++)
    {
        bool flag1 = true,flag2 = true,exist = false;
        for(int j = 0; j < tmp1; j++)
        {
            if(i == v1[j])
            {
                exist = true;
                break;
            }
            else
            {
                for(int k = node[v1[j]]; k < node[v1[j]] + nrecord[v1[j]]; k++)
                {
                    if(i == node[k])
                    {
                        flag1 = false;
                        break;
                    }
                }
                if(!flag1)
                    break;
            }
        }
        if(flag1 && !exist)
        {
            v1[tmp1] = i;
            tmp1++;
        }
        else
        {
            for(int j = 0; j < tmp2; j++)
            {
                if(i == v2[j])
                {
                    exist = false;
                    break;
                }
                else
                {
                    for(int k = node[v2[j]]; k < node[v2[j]] + nrecord[v2[j]]; k++)
                    {
                        if(i == node[k])
                        {
                            flag2 = false;
                            break;
                        }
                    }
                    if(!flag2)
                        break;
                }
            }
            if(flag2 && !exist)
            {
                v2[tmp2] = i;
                tmp2++;
            }
            else
                fail = true;
        }
        if(fail)
            break;
    }
    if(!fail)
    {
        cout << "true" << endl;
        for(int i = 0; i < tmp1; i++)
            cout<< v1[i] << " ";
        cout << endl;
        for(int i = 0; i < tmp2; i++)
            cout<< v2[i] << " ";
        cout << endl;
    }
    else
        cout << "false" << endl;
    return 0;
}
