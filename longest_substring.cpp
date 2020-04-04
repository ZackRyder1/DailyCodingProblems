//
// Created by zack on 04/04/20.
//
#include<iostream>
#include<unordered_map>
using namespace std;

int findLongest(const string & s,int distinct)
{
    int start=0;

    int max_size = 1;

    unordered_map<char,int> distincts; //frequency of characters

    int curr_distinct=1;

    distincts.insert(pair<char,int>(s[0],1));

    for(int end=1;end<s.length();end++)
    {
        if(distincts.find(s[end]) == distincts.end())
        {
            if(curr_distinct != distinct)
                curr_distinct++;
            else {
                while (curr_distinct == distinct)
                {
                    if (distincts.at(s[start]) == 1)
                    {
                        distincts.erase(s[start++]);
                        curr_distinct--;
                    }
                    else
                        distincts.at(s[start++])--;
                }
                curr_distinct++;
            }
            distincts.insert(pair<char,int>(s[end],1));
        }
        else
            distincts.at(s[end])++;

        if(max_size< end-start + 1)
            max_size = end-start+1;
    }
    return max_size;
}

int main()
{
    string s = "abcdbdadabbbbbcccaaa";
    cout<<"The longest substring in the string " << s <<" is of length "<< findLongest(s,3)<<'\n';
    return 0;
}

