//
// Created by zack on 09/04/20.
//
#include<iostream>
using namespace std;

void findMaxSubArray(int * arr,int size,int k)
{
    int i;
    int max = INT32_MIN;
    int sec_max = INT32_MIN;
    for(i=0;i<k;i++)
    {
        if(max<arr[i])
            max = arr[i];

        if(arr[i]>sec_max && arr[i]<max)
            sec_max = arr[i];
    }
    int start= 0;
    int end = i-1;
    cout<<"The Max element for subarray("<<start<<","<<end<<") is "<<max<<'\n';
    while(end<size-1)
    {
        if(arr[start] == max)
            max =sec_max;

        if(arr[end+1] > max)
        {
            int temp = max;
            max = arr[end+1];
            sec_max = temp;
        }
        else if(arr[end+1] <= max)
            sec_max = arr[end];

        start++;
        end++;
        cout<<"The Max element for subarray("<<start<<","<<end<<") is "<<max<<'\n';
    }

}

int main()
{
    int arr[7] = {10,5,2,7,8,7,10};
    findMaxSubArray(arr,7,3);
    return 0;
}