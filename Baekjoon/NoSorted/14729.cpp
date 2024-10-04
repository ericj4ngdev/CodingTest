#include<bits/stdc++.h>
using namespace std;

double temp;
priority_queue<double> pq;
vector<double> v;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int num;
    cin >> num;

    for(int i = 0; i < num; i++)
    {
        cin >> temp;
        // pq 크기가 7이면 temp를 넣고 기존꺼를 버린다. 
        if(pq.size() == 7)
        {
            pq.push(temp);
            pq.pop();
        }
        else
        {
            // 아직 안찼으면 계속 넣는다. 
            pq.push(temp);
        }
    }

    // 남아있는 pq를 v에 넣는다. 
    while(pq.size())
    {
        v.push_back(pq.top());
        pq.pop();
    }

    // for(double score:v)
    // {
    //     cout << score << " ";
    // }

    // v를 역순으로 하면 내림차순. 
    reverse(v.begin(), v.end());

    for(double score:v)
    {
        cout << score << "\n";
    }

    return 0;
}