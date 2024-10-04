#include <iostream>
#include <vector>
using namespace std;

int dp[1001][1001];
string st1, st2;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    // segmentation fault를 막기위해 0을 처음에 넣고 시작
    cin >> st1 >> st2;
    st1 = "0" + st1;
    st2 = "0" + st2;


    for(int i = 0; i < st1.size(); i++)
    {
        for(int j = 0; j < st2.size(); j++)
        {
            if(i == 0 || j == 0)
            {
                dp[i][j] = 0;                
            }
            else if(st1[i] == st2[j])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[st1.size() - 1][st2.size()-1];

    return 0;
}