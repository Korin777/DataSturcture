#include<iostream>
#include<cstring>
using namespace std;
struct element{
    int key;
};
int n = 0;
element heap[1000001];
void push(element item,int *n)
{
    int i;
    i = ++(*n);
    while((i != 1) && (item.key > heap[i/2].key))
    {
        heap[i] = heap[i/2];
        i /= 2;
    }
    heap[i] = item;
}
void pop(int *n)
{
    int parent,child;
    element item,temp;
    item = heap[1];
    temp = heap[(*n)--];
    parent = 1;
    child = 2;
    while(child <= *n)
    {
        if((child < *n) && (heap[child].key < heap[child+1].key))
        {
            child++;
        }
        if(temp.key >= heap[child].key)
            break;
        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }
    heap[parent] = temp;
}
int main()
{
    int T,M,N;
    int ticket_sell = 0;
    cin >> T;
    for(int j = 0 ; j < T ; j++)
    {
        cin >> M >> N;
        element e;
        for(int i = 0 ; i < M ; i++)
        {
            cin >> e.key;
            push(e,&n);
        }
        for(int i =0 ; i < N ; i++)
        {
            ticket_sell += heap[1].key; 
            heap[1].key--;
            e = heap[1];
            pop(&n);
            push(e,&n);
        }
        cout << ticket_sell << endl;
        n = 0;
        memset(heap,0,1000001);
        ticket_sell = 0;
    }
    return 0;
}
