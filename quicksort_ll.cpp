#include<iostream>
#include<ctime>
using namespace std;

void quicksort(int a[], int left, int right)
{
    int pivot,i,j;
    int temp;
    if(left < right)
    {
        i = left;
        j = right + 1;
        pivot = a[left];
        do
        {
            do
                i++;
            while(a[i] < pivot);
            do
                j--;
            while(a[j] > pivot);
            if(i < j)
                swap(a[i], a[j]);
        }
        while(i < j);
        swap(a[left], a[j]);
        if(j - 1 - left > right - j - 1)
        {
            quicksort(a, left, j - 1);
            quicksort(a, j + 1, right);
        }
        else
        {
            quicksort(a, j + 1, right);
            quicksort(a , left, j - 1);
        }
    }
}

int main()
{
    clock_t start,end;
    int n = 0;
    int a[150000];
    double cpu_time_used;
    for(int i = 0; i < 150000; i++)
        cin >> a[i];
    start = clock();
    quicksort(a,0,149999);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "use leftmost and longer first execution time = " << cpu_time_used << endl;
    return 0;
}
