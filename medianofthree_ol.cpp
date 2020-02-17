#include<iostream>
#include<ctime>
#include<algorithm>
using namespace std;

void quicksort(int a[], int left, int right)
{
    int pivot,i,j,middle;
    int temp;
    if(left < right)
    {
        i = left;
        j = right + 1;
        middle = (left + right) / 2;
        int b[3];
        b[0] = a[left];
        b[1] = a[right];
        b[2] = a[middle];
        sort(b, b + 3);
        pivot = b[1];
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
            quicksort(a, left, j - 1);
        }
    }
}

int main()
{
    clock_t start,end;
    double cpu_time_used;
    int a[150000];
    for(int i = 0; i < 150000; i++)
        cin >> a[i];
    start = clock();
    quicksort(a,0,149999);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "use median of three and longer first execution time = " << cpu_time_used << endl;
    return 0;
}
