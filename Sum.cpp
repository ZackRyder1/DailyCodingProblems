#include <iostream>
#include <unordered_set>
using namespace std;

bool Sum(int arr[],int target,int size)
{
    unordered_set <int> pairSet;
    int pair = target - arr[0];
    pairSet.insert(pair);
    for(int i=1;i<size;i++)
    {

        if((pairSet.find(arr[i])) != pairSet.end())
        {
            return true;
        }
        else{
            pair = target - arr[i];
            pairSet.insert(pair);
        }
    }
    return false;
}

int main() {
    int size = 4;
    int arr[4] = {10,15,3,7};
    int target = 17;
    cout<<(Sum(arr,target,size)?"true":"false");
    return 0;
}
