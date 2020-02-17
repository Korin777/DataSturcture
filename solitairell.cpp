#include<iostream>
#include<random>
using namespace std;
struct node
{
    string data;
    node *next;
};
void insert(node **first,string a)
{
    node *temp = new node;
    temp->data = a;
    node *current = *first;
    if(*first)
    {
        while(current->next!=NULL)
        {
            current = current->next;
        }
        current->next = temp;
        temp->next == NULL;
    }
    else 
    {
        *first = temp;
        temp->next == NULL;
    }
}
void defront(node **first,node *next)
{
    node *de = *first;
    *first = next;
    de->next = NULL;
    delete de;
}
int main()
{
    srand(time(NULL));
    node *card = NULL;
    string putcard[13] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    string takecard[13] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    int rd;
    int rp = 13;
    while(1)
    {
        if(rp==0)
            break;
        rd = rand() % rp;
        insert(&card,putcard[rd]);
        if(rd==rp-1)
            rp--;
        else
        {
            putcard[rd] = putcard[rp-1];
            rp--;
        }
    }
    int record = 12;
    int rt = 12;
    string tmp;
    int i =0;
    while(1)
    {
        if(card==NULL)
            break;
        node *current = card;
        while(current)
        {
            cout<<current->data<<" ";
            current = current->next;
        }
        cout<<endl;
        if(card->data == takecard[record])
        {
            defront(&card,card->next);
            rt--;
            record--;
        }
        else
        {
            tmp = card->data;
            defront(&card,card->next);
            insert(&card,tmp);
        }
    }
    return 0;
}
