//
// Created by zack on 23/03/20.
//
#include <iostream>
using namespace std;

int * Product_array(int arr [],int size)
{
    int * result = new int[size];
    int products[size];
    int prev_Product = 1;

    products[size-1] = 1;
    for(int i=size-2;i>=0;i--)
    {
         products[i] = products[i+1] * arr[i+1];
    }

    for(int i=0;i<size;i++)
    {
        result[i] = prev_Product * products[i];
        prev_Product *= arr[i];
    }

    return result;
}

int main()
{
    int arr [5] = {1,2,3,4,5};
    int size = 5;
    int * result = Product_array(arr,size);
    for(int i=0;i<size;i++)
        cout<< result[i] <<"\n";
    return 0;
}

