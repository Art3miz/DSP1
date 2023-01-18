#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>

using namespace std;

int main(int argc, char* argv[])
{
    int len;
    int buff;
    list<int> ffList; 
    ifstream fstr(argv[1]);
    fstr >> len;
    for(int i = 0; i < len; i++)
    {
        fstr >> buff;
        ffList.push_back(buff);
        
    }

    return 0;
}