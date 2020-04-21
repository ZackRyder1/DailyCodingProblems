//
// Created by zack on 21/04/20.
//
#include <iostream>
using namespace std;

int calTrappedWater(int * towers,int size)
{
    int prev = towers[0],prev_index = 0;
    int total_water = 0;
    int temp_water = 0;

    for(int i=1;i<size;i++)
    {
        if(prev<=towers[i])
        {
            prev_index = i;
            prev = towers[i];
            temp_water = 0;
        }
        else
        {
            total_water+= (prev-towers[i]);
            temp_water+= (prev-towers[i]);
        }
    }


    if(prev_index<size-1)
    {
        total_water-=temp_water; //excess water

        prev = towers[size-1];
        for(int i =size-2;i>=prev_index;i--)
        {
            if(prev <= towers[i])
                prev = towers[i];
            else
                total_water+=(prev -towers[i]);
        }
    }
    return total_water;
}


int main()
{
    int towers[14] = {3,0,1,2,4,0,0,2,1,1,2,0,0,4};
    int size =14;
    cout<<"The Amount of Water trapped between towers is "<<calTrappedWater(towers,size)<<endl;
    return 0;
}

