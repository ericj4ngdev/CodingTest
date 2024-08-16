#include<algorithm>
#include<iostream>
#include<list>
#include<vector>
using namespace std;

void printList(list<char>& pw)
{
    for (char c : pw)
    {
        cout << c;
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    int testcase = 0;
    cin >> testcase;

    while (testcase--)
    {
        list<char> pw;
        auto curpos = pw.end();
        string keylog;
        cin >> keylog;
        for (char c : keylog)
        {
            switch (c)
            {
            case '<':
                if (curpos != pw.begin()) curpos--;
                break;
            case '>':
                if (curpos != pw.end()) curpos++;
                break;
            case '-':
                if (curpos != pw.begin())
                {
                    curpos--;
                    curpos = pw.erase(curpos);
                }
                break;
            default:
                pw.insert(curpos, c);
                break;
            }
            // printList(pw);
        }
        printList(pw);
    }

    return 0;
}