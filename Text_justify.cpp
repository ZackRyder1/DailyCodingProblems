//
// Created by zack on 20/04/20.
//

#include<iostream>
using namespace std;
int badness_table[10][10];
int Solution[10];
int min_badness[10];

int findWidth(string words[],int i,int j)
{
    if(j == i)
        return words[i].length();
    int width = j-i;
    for(;i<=j;i++)
       width+= words[i].length();
    return width;
}

void findBadness(string words[],int size,int page_width)
{
    for(int i=0;i<size;i++) {
        for (int j = i; j < size; j++) {
            int words_width  = findWidth(words,i,j);
            if (page_width - words_width >= 0) {
                words_width = page_width - words_width;
                badness_table[i][j] = words_width * words_width;
            } else
                badness_table[i][j] = INT32_MAX;
        }
    }
}

int findMin(int i,int * j)
{
    int min = INT32_MAX;
    int split_index = *j;
    for(;*j>i;(*j)--)
    {
        if(badness_table[i][*j-1] != INT32_MAX) {
            int current = badness_table[i][*j - 1] + min_badness[*j];
            if (current < min) {
                min = current;
                split_index = *j;
            }
        }
    }
    *j = split_index;
    return min;
}

int * findJustifySolution(string words[],int size,int page_width) {

    findBadness(words, size, page_width);

    for (int i = size - 1; i >= 0; i--) {
        int j = size - 1;
        if (badness_table[i][j] != INT32_MAX) {
            min_badness[i] = badness_table[i][j];
            Solution[i] = j + 1;
        } else {
            min_badness[i] = findMin(i, &j);
            Solution[i] = j;
        }
    }
}

string * buildSolution(string words[],int size)
{
    string * result = new string("");
    for(int i=0;i<size;result->push_back('\n'))
    {
        int split = Solution[i];
        int j;
        for(j=i;j<split-1;j++)
            result->append(words[j] + " ");
        result->append(words[j]);
        i = split;
    }
    return result;
}


int main()
{
    string words [9] = {"The","quick","brown","fox","jumps","over","the","lazy","dog"};
    int page_width = 16;
    int size = 9;
    findJustifySolution(words,size,page_width);
    cout<< *buildSolution(words,size)<<endl;
    return  0;
}
