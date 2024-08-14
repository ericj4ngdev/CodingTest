#include<bits/stdc++.h>
using namespace std;

vector<int> stair;
int ret;
// i번째 계단에서의 최대점수
int dp[304];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int num = 0;
    cin >> num;


    for(int i = 0; i < num; i++)
    {
        int score;
        cin >> score;
        stair.push_back(score);
    }

       

    return 0;
}