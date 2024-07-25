#include <bits/stdc++.h>
using namespace std;

int main()
{
    int CoinCnt = 0;    
    int cash = 0;
    cin >> cash;

    if(cash < 2 || cash == 3) 
    {
        cout << "-1";
        return 0;
    }
    // 5로 나눈 나머지가 홀수라면 
    // 5로 나눈 몫에서 1뺀만큼이 5원 개수
    // 그러면 나머지는 짝수이므로 나머지 / 2만큼 2원 개수
    if((cash%5)%2 == 1)
    {
        CoinCnt += cash/5 - 1;    
    }
    else
    {
        CoinCnt = cash/5;        
    }
    cash -= CoinCnt * 5;
    CoinCnt += cash/2;

    cout << CoinCnt;   

    return 0;
}