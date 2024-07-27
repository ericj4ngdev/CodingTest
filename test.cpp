#include<bits/stdc++.h>
using namespace std;

int temp;
priority_queue<int> pq;
vector<int> v;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int num;
    cin >> num;

    for(int i = 0; i < num; i++)
    {
        cin >> temp;
        pq.push(temp);  // 일단 넣는다.                 
    }

    // 남아있는 pq를 v에 넣는다. 
    while(pq.size())
    {
        v.push_back(pq.top());
        pq.pop();
    }

    for(int score : v)
    {
        cout << score << " ";
    }

    // v를 역순으로 하면 내림차순. 
    reverse(v.begin(), v.end());
    cout << "\n";

    for(int score:v)
    {
        cout << score << " ";
    }

    return 0;
}