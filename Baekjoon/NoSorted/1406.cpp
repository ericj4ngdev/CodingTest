#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<list>
using namespace std;

void PrintList(list<char>& L)
{
    for(char c : L)
    {
        cout << c;
    }
    cout << '\n';
}

int main()
{
    list<char> memo;
    auto iter = memo.end();
    string input;
    cin >> input;

    for(char c : input)
    {
        memo.push_back(c);
    }    

    int CommandCount = 0;
    cin >> CommandCount;

    for(int i = 0; i < CommandCount; i++)
    {
        char Command;
        cin >> Command;
        if(Command == 'P')
        {
            char _char;
            cin >> _char;    
            // memo.push_back(_char);
            iter = memo.insert(iter, _char);
            iter++;
        }
        else if(Command == 'L')
        {
            if(iter == memo.begin()) continue;
            else iter--;
        }
        else if(Command == 'D')
        {
            if(iter == memo.end()) continue;
            else iter++;
        }
        else if(Command == 'B')
        {
            if(iter == memo.begin()) continue;
            else 
            {
                iter--;
                iter = memo.erase(iter);
            }
        }
        // cout << i << " : ";
        // PrintList(memo);
    }

    PrintList(memo);

    return 0;
}