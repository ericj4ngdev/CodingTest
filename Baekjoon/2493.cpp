#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int numTower = 0;
    cin >> numTower;

    stack<int> stk;
    vector<int> vec;
    vector<int> ans;
    // 가장 높은 타워 인덱스
    int idx = 0;
    // 가장 높은 타워 높이
    int maxVal = 0;
    // maxval의 idx로 수정
    for (int i = 0; i < numTower; i++)
    {
        int k;
        cin >> k;
        vec.push_back(k);
        // 1번째는 무조건 0 출력
        if(i == 0) 
        {
            maxVal = k;
            stk.push(k);
            ans.push_back(0);
            continue;
        }
        // 부딪힌 타워 max값
        // 인덱스 저장
        
        // 7 >= 5
        if(stk.top() >= k)
        {
            // top과 max 사이 값들과 비교
            for(int j = i - 1; j > idx; j--)
            {
                // 
                if(vec[j] >= k)
                {
                    // 수신
                    ans.push_back(j);
                    j = idx;
                }
            }
            // 같은 높이일 경우 수신
            // top에 수신. 기존꺼 그대로 
            ans.push_back(i);
            // top과 max 사이와 비교하기

        }
        else
        {         
            if(maxVal < k)
            {
                maxVal = k;                
                ans.push_back(0);   // 가장 큰 수이므로 수신탑 X
                idx = i + 1;
            }
            else
            {                
                ans.push_back(idx);
            }
        }

        stk.push(k);
    }

    for(int it : ans)
    {
        cout << it << " ";
    }
    
    return 0;
}