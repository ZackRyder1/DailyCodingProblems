//
// Created by zack on 31/03/20.
//
#include<iostream>
using namespace std;

int Max_Sum(int * arr,int size)
{
    int incl = arr[0],excl = 0;
    for(int i=1;i<size;i++)
    {
        int temp = excl;
        excl = max(excl,incl);
        incl = temp + arr[i];
    }

    return max(excl,incl);
}

int main()
{
    int arr[5] = {9,14,6,2,5};
    cout<<"The Max Non-Adjacent Sum is "<<Max_Sum(arr,5)<<'\n';
    return 0;
}

