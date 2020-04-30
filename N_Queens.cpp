//
// Created by zack on 30/04/20.
//
#include<iostream>
using namespace std;
typedef pair<int,int> Pairs;

bool chessboard[10][10];
Pairs * queens_Placed[10];
bool complete_flag = false;


bool underAttack(int row,int col)
{
    for(int i=0;i<row;i++)
    {
        int row1 = queens_Placed[i]->first;
        int col1 = queens_Placed[i]->second;
        if(col == col1)
            return true;

        if(row1-col1 == row-col || row1+col1 == row+col)
            return true;
    }
    return false;
}


bool findNQueen(int depth,const int n)
{
    if(depth == n)
        return true;

    for(int i=0;i<n;i++)
    {
        if(complete_flag)
            return true;

        if(depth == 0)
        {
            queens_Placed[depth] = new Pairs(depth,i);
            complete_flag = findNQueen(depth+1,n);
        } else
        {
            if(underAttack(depth,i))
                continue;
            else{
                queens_Placed[depth] = new Pairs(depth,i);
                complete_flag = findNQueen(depth+1,n);
            }
        }
    }
    if(complete_flag)
        return true;
    return false;
}

void placeQueens(int n)
{
    for(int i=0;i<n;i++)
    {
        int row = queens_Placed[i]->first;
        int col = queens_Placed[i]->second;
        chessboard[row][col] = true;
    }
}

void printBoard(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(chessboard[i][j])
                cout<<'Q'<<'\t';
            else
                cout<<'B'<<'\t';
        }
        cout<<'\n';
    }
}


int main()
{
    findNQueen(0,8);
    placeQueens(8);
    printBoard(8);
    return 0;
}

