#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>
#include <chrono>

using namespace std;

int main(int argc, char* argv[])
{
    clock_t startTime = clock();
    int len;
    int buff;
    list<int> ffList;  //setup
    list<int>::iterator it1, it2;
    
    ifstream fstr(argv[1]); //opens file specified by 2nd comm. line argument (file name)
    
    fstr >> len; //1st line = length of input
    for(int i = 0; i < len; i++) //push file contents into std::list
    {
        fstr >> buff;
        ffList.push_back(buff);
    }
    int queries;
    fstr >> queries;
    list<int> queryList;

    for(int i = 0; i < queries; i++)
    {
        fstr >> buff;
        queryList.push_back(buff);
    }

    for(it1 = queryList.begin(); it1 != queryList.end(); ++it1)
    {
        for(it2 = ffList.begin(); it2 != ffList.end(); ++it2)
        {
            if(*it1 == *it2)
            {
                ffList.erase(it2);
                ffList.push_front(*it1);
                break;
            }
        }
    }
    cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    return 0;
}