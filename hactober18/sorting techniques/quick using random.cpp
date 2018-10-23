#include<iostream>
using namespace std;
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
#include <cstdlib>
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];

    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
int partition2(int arr[], int low, int high)
{

    int random = low + rand() % (high - low);
//int random;
//cout<<"sir ji please... do me a favourr!!!"<<endl;
//cin>>random;
    // Swap A[random] with A[high]
    swap(arr[random], arr[high]);

    return partition(arr, low, high);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition2(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
  int main()
{
    int a[100],i,j,m,s;
    cin>>s;
    for(i=0;i<s;i++)
    {
        cin>>a[i];
    }
     quickSort(a,0,s-1);
     for (i=0;i<s;i++)
    {
        cout<<a[i]<<" ";
    }
}
