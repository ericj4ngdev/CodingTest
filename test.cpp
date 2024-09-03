#include <bits/stdc++.h>
using namespace std;

int n, height, pos, cnt;
unordered_map<int, int> tree;
int ret;
char command;
int growth = 0;

void CutTree() 
{
    if (tree[pos] + growth >= height) 
    {
        ret += tree[pos] + growth;
        tree[pos] = -growth; // reset tree to 0 considering growth
    }    
}

void Move(char cmd) 
{
    if (cmd == 'L') 
    {
        pos = (pos == 1) ? n : pos - 1;
    } 
    else if (cmd == 'R') 
    {
        pos = (pos == n) ? 1 : pos + 1;
    }
}

void Simulate(char cmd) 
{
    CutTree();
    Move(cmd);
    growth++;
}

int main() 
{
    cin >> n >> height >> pos;

    for (int i = 1; i <= n; i++) {
        int h;
        cin >> h;
        tree[i] = h;
    }

    cin >> cnt;

    for (int i = 0; i < cnt; i++) {
        cin >> command;
        Simulate(command);
    }

    cout << ret;

    return 0;
}
