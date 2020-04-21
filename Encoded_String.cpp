//
// Created by zack on 21/04/20.
//
#include<iostream>
using namespace std;


string * encode(string & s)
{
    string * result = new string();
    char curr = s[0];
    int count = 1;
    for(int i=1;i<s.length();i++)
    {
        if(s[i] == curr)
            count++;
        else
        {
            result->push_back(curr);
            result->append(to_string(count));
            curr = s[i];
            count = 1;
        }
    }
    result->push_back(curr);
    result->append(to_string(count));
    return result;
}

int getNumber(int * i ,string & s)
{
    string num;
    for(;*i<s.length();(*i)++)
    {
        if(isdigit(s[*i]))
            num+=s[*i];
        else
            break;
    }
    return stoi(num);
}

string decode(string * s)
{
    int i = 0;
    string result;
    while(i<s->length())
    {
        char curr = (*s)[i++];
        int count = getNumber(&i,*s);
        for(int j =0;j<count;j++)
            result+=curr;
    }
    return result;
}

int main()
{
    string s = "AAAABBBBCCCCBBBBDDDEEEE";
    cout<< decode(encode(s));

    return 0;
}

