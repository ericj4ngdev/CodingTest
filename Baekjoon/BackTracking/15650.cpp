#include<bits/stdc++.h>
using namespace std;

int n, m;

void printVector(const vector<int>& v)
{
    for(int i : v)
    {
        cout << i << " ";
    }
    cout << '\n';
}

void combi(int start, vector<int> v)
{
    if(v.size() == m)
    {
        printVector(v);
        return;
    }

    for(int i = start + 1; i <= n; i++)
    {
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    vector<int> v;
    combi(0, v);

    return 0;
}