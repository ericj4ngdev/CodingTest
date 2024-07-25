#include <cctype>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

string name;
int num;
int inputN, inputM;
map<string, int> mp;
string pokemon[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> inputN >> inputM;

    for (int i = 1; i <= inputN; i++)
    {
        cin >> pokemon[i];
        mp[pokemon[i]] = i;
    }

    for (int i = 0; i < inputM; i++)
    {
        cin >> name;
        // 숫자이면 숫자로
        if (isdigit(name[0]) != 0)
        {
            num = stoi(name);
            cout << pokemon[num] << "\n";
        }
        else
        {
            // 문자
            cout << mp[name] << "\n";
            // auto ret = mp.find(name);
            // cout << ret->second << "\n";
        }
    }

    return 0;
}