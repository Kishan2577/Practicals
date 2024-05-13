#include<iostream>
using namespace std;

int arr1[100];
int size = 0;
void insert(int data)
{
    size++;
    int i = size;
    arr1[i] = data;
    

    while(i>1)
    {
        int parent = i/2;
        if(arr1[parent]<arr1[i])
        {
        swap(arr1[parent],arr1[i]);
        i = parent;
        }
        else
        {
            return;
        }
    }
    
}
int main()
{
    insert(50);
    insert(10);
    insert(60);
    insert(30);
    insert(20);
    insert(90);
    cout<<" MAX HEAP "<<arr1[1]<<endl;
    return 0;
}