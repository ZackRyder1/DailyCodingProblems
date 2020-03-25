//
// Created by zack on 26/03/20.
//
#include <iostream>
using namespace std;


int find_Missing(int arr[],int size)
{
    int positive_index = size;
    for(int i=0;i<size;i++) //Classify negatives and positives
    {
        if(arr[i] <= -1)
        {
            int temp = arr[--positive_index];
            arr[positive_index] = arr[i];
            arr[i] = temp;
        }
    }

    for(int i=0;i<positive_index;i++)
        arr[abs(arr[i])-1] *= -1;

    for(int i=0;i<positive_index;i++)
        if(arr[i]>0)
            return i+1;

    for(int i=positive_index;i<size;i++)
        if(arr[i]<=-1)
            return i+1;

    return 0;
}

int main()
{
    int arr[4] = {1,2,-4};
    int size = 4;
    int Missing_Int = find_Missing(arr,size);
    (Missing_Int == 0)?cout<<"EveryThing is Present"<<'\n':cout<<"The Missing Value is "<<Missing_Int<<'\n';
    return 0;
}

