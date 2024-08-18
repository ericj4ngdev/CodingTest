#include<iostream>
#include<vector>
#include <queue>
using namespace std;

void PrintVector(vector<int>& v)
{
    cout << '<';
    for(int i = 0; i < v.size(); i++)
    {
        if(i == v.size() - 1)
        {
            cout << v[i];
        }
        else
        {
            cout << v[i] << ", ";
        }
    }
    cout << '>';
    cout << '\n';
}

int main()
{
    queue<int> q;
    vector<int> vec;

    int n = 0, k = 0;
    cin >> n >> k;
    // 처음엔 다 담는다.
    for(int i = 1; i <= n; i++)
    {
        q.push(i);   
    }

    // 맨 앞에거 빼서 뒤에 넣고
    // k번째에 pop만 한다. 
    int cnt = 1;
    while(q.size())
    {
        if(cnt == k)
        {
            vec.push_back(q.front());
            q.pop();
            cnt = 1;
            // PrintVector(vec);
            continue;
        }
        q.push(q.front());
        q.pop();
        cnt++;
    }

    PrintVector(vec);
    
    return 0;
}

