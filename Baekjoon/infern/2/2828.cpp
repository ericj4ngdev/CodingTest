#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int n, m, appleNum, applepos, cnt;
// m : 바구니 크기

int main()
{
    cin >> n >> m;
    cin >> appleNum;
    int curpos = 1;
    for(int i = 0; i < appleNum; i++)
    {
        cin >> applepos;
        int basketEnd = curpos + m - 1;
        // 바구니 범위에 있으면 패스
        if(applepos >= curpos && applepos <= basketEnd) continue;
        else
        {
            // 아니면 이동
            if(applepos < curpos)   
            {
                cnt += (curpos - applepos);
                curpos = applepos;
            }
            else
            {
                curpos += (applepos - basketEnd);
                cnt += (applepos - basketEnd);
            }
        }
    }

    cout << cnt;

    return 0;
}