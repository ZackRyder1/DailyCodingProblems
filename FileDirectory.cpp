//
// Created by zack on 08/04/20.
//
#include<iostream>
#include<stack>
using namespace std;


struct File{
    int length;
    int level;

public:
    File(int length, int level) : length(length), level(level) {}

    int getLength() const {
        return length;
    }

    void setLength(int length) {
        File::length = length;
    }

    int getLevel() const {
        return level;
    }

    void setLevel(int level) {
        File::level = level;
    }
};

int getFileLength(string & path,int * index)
{
    int length=0;
    while(path[(*index)++] != '\n')
        length++;
    return length+1;
}

int getCountTab(string & path,int * index)
{
    int count = 0;
    while(path[(*index)++] == '\t')
        count++;
    (*index)--;
    return count;
}

int findMaxLen(string path)
{
    int max_len = 0;
    stack<File*> files;
    int len_iterator = 0;
    int Filelen = getFileLength(path,&len_iterator);
    files.push(new File(Filelen,0));
    while(len_iterator<path.length())
    {
        int countTab = getCountTab(path,&len_iterator);
        int prev_level = files.top()->getLevel();
        if( prev_level == countTab)
        {
            int curr_len =files.top()->getLength();
            files.pop();
        }
        else if(prev_level>countTab)
            for(int pop=prev_level - countTab;pop>=0;pop--)
                files.pop();
        if(files.empty())
            Filelen =  getFileLength(path,&len_iterator);
        else
            Filelen = files.top()->getLength() + getFileLength(path,&len_iterator);
        if(max_len < Filelen)
            max_len = Filelen;
        files.push(new File(Filelen,countTab));
    }

    return max_len;

}


int main()
{
    string a ="Dir1\nsubdir1\n\tisknfkneivinenoiwinvioneonoieoi\nisknfkneivinenoiwinvioneonoieoi\n";
    cout<<a;
    cout<<"Length of Longest absolute path is "<<findMaxLen(a)<<'\n';
    return 0;
}



