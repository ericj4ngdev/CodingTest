#include<bits/stdc++.h>
using namespace std;

const int SIZE = 21;
int n;
int mates[SIZE][SIZE];
int selected[SIZE];

void CalculateStat()
{
    
}

/// @brief 
/// @param cnt 뽑은 사람 수
/// @param idx 뽑은 사람 번호
void SelectTeam(int cnt, int idx)
{
    if(cnt == n/2)
    {
        // 다 뽑으면 능력치 계산
        CalculateStat();
        return;
    }

    // 1 2
    // 1 3
    // 1 4
    for(int i = idx; i < n; i++)
    {
        // 선택
        selected[i] = 1;
        // 재귀
        SelectTeam(cnt + 1, idx + 1);
        // 원복
        selected[i] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> mates[i][j];
        }
    }

    // 잘하는 사람부터 뽑기
    SelectTeam(0,0);


    return 0;
}