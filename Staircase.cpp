//
// Created by zack on 03/04/20.
//
#include<iostream>
using namespace std;
int arr[3] = {1,3,5};
int size = 3;

void calSteps(string climb,int stairs)
{
    if(stairs<=0)
    {
        if(stairs == 0)
            cout<<climb<<'\n';
        return;
    }

    for(int i=0;i<size;i++) {
        calSteps(climb + to_string(arr[i]), stairs - arr[i]);
    }
}

int main()
{
    string s = "";
    calSteps(s,5);
    return 0;
}

