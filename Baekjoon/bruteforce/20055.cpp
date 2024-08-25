#include<bits/stdc++.h>
using namespace std;

// 그냥 배열은 가만히 있고 돌리자.
int belt[202];
int n, k;
bool robot[202];
int startIdx;
int endIdx;

void Rotate()
{
    // 1 이동
    // 벨트 회전. 범위 바뀌기
    // 0 ~ n-1
    // 1~n-2, 2n - 1
    if(startIdx == 0)
    {
        startIdx = 2*n-1;
    }
    else
    {
        startIdx--;
    }

    if(endIdx == 0)
    {
        endIdx = 2*n-1;
    }
    else
    {
        endIdx--;
    }
    
    if(robot[endIdx])
    {
        // 로봇 내리기
        robot[endIdx] = false;
    }    
    
}

void MoveRobot()
{
    for(int i = 0; i < n - 1; i++)
    {
        // int next = idx;
    }
}

void PutRobot()
{

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n * 2; i++)
    {
        cin >> belt[i];      
    }
    endIdx = n - 1;
    Rotate();
    MoveRobot();
    PutRobot();


    return 0;
}