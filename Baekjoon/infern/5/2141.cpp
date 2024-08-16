#include<bits/stdc++.h>
using namespace std;

const int MAX = 100004;

int town[MAX];
int person[MAX];
int ret;
int minDist = 987654321;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> town[i] >> person[i];
    }
    sort(town + 1, town + n);

    // 우체국 위치 pos를 town[0] < i < town[n]에서 순회
    // dist에 pos - 마을 위치를 사람 수만큼 더한다. 
    // dist가 최소이면 pass 
    for(int i = town[0]; i < town[n]; i++)
    {
        int dist = 0;
        for(int j = 1; j <= n; j++)
        {
            dist += (abs(town[j] - i) * person[j]);
        }
        
        // dist가 최소일 때, i를 ret에 저장
        if(minDist > dist)
        {
            minDist = dist;
            ret = i;
        }
    }
    cout << ret;    

    return 0;
}