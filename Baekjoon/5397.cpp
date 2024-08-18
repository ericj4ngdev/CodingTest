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
    int testcase = 0;
    cin >> testcase;    

    while(testcase--)
    {
        string log;
        cin >> log;
        list<char> pw;
        auto iter = pw.end();
        for(char key : log)
        {        
            if(key == '<')
            {
                if(iter == pw.begin()) continue;
                else
                {
                    iter--;
                }
            }
            else if(key == '>')
            {
                if(iter == pw.end()) continue;
                else
                {
                    iter++;
                }
            }
            else if(key == '-')
            {
                if(iter == pw.begin()) continue;
                else
                {
                    iter--;
                    iter = pw.erase(iter);
                }
            }
            else
            {
                pw.insert(iter,key);
            }
        }
        PrintList(pw);
    }

    return 0;
}