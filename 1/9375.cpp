#include<bits/stdc++.h>
using namespace std;

int main()
{
    int testcase, inputN; 
    string clothName, clothCategory;

    cin >> testcase;
    while(testcase--)
    {
        cin >> inputN;
        map<string, int> cloth;
        int ret = 1;

        // map 채우기
        for(int i = 0; i < inputN; i++)
        {
            cin >> clothName >> clothCategory;
            cloth[clothCategory]++;
        }

        // (의상 종류별 개수 + 1)끼리 곱하고 - 1
        for(pair i : cloth)
        {
            ret *= (i.second + 1);
        }

        cout << ret - 1 << '\n';
    }
}