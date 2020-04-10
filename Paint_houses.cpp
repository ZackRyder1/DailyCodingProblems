//
// Created by zack on 10/04/20.
//
#include<iostream>
using namespace std;

struct Min{
    int min;
    int sec_min;

public:
    Min(int min = INT32_MAX, int secMin = INT32_MAX) : min(min), sec_min(secMin) {}

    int getSecMin() const {
        return sec_min;
    }

    int getMin() const {
        return min;
    }

    void setMin(int min) {
        Min::min = min;
    }

    void setSecMin(int secMin) {
        sec_min = secMin;
    }

};

Min * findMin(int * arr,int size)
{
    Min * min = new Min();
   for(int i=0;i<size;i++)
   {
       if(min->getMin() > arr[i])
           min->setMin(arr[i]);
       if(arr[i]<min->getSecMin() && arr[i]>min->getMin())
           min->setSecMin(arr[i]);
   }
   return min;
}

int findMinCost(int * arr,int houses,int paints)
{
    int cost[houses][paints];

    for(int i=0;i<houses;i++)
        for(int j=0;j<paints;j++)
            cost[i][j] = arr[j+paints*i];

    Min * min = findMin(cost[0],paints);

    int  * min_cost = cost[0];

    for(int i=1;i<houses;i++)
    {
        int min_temp = INT32_MAX;
        int sec_min_temp = INT32_MAX;
        for(int j=0;j<paints;j++)
        {
            if(min->getMin() == min_cost[j])
                min_cost[j] = min->getSecMin() + cost[i][j];
            else
                min_cost[j] = min->getMin() + cost[i][j];

            if(min_temp > min_cost[j])
                min_temp = min_cost[j];
            if(min_cost[j]<sec_min_temp && min_cost[j]>min_temp)
                sec_min_temp = min_cost[j];
        }
        min->setMin(min_temp);
        min->setSecMin(sec_min_temp);
    }
    return min->getMin();
}


int main()
{
    int n = 3;
    int k = 3;
    int cost[3][3]={{5,10,15},{3,0,2},{1,12,10}};
    cout<<"The minimum cost of painting "<<n<<" houses with "<<k<<" paints is "<<findMinCost((int*)cost,n,k);
    return 0;
}

