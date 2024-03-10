#include <bits/stdc++.h>
using namespace std;

int n;
int main()
{
    while(scanf("%d",&n) != EOF)
    {
        int cnt = 1; int ret = 1;
        while(true)
        {
            if(cnt % n == 0)
            {
                printf("%d\n", ret);
                break;
            }
            else
            {
                cnt = (cnt * 10) + 1;       // cnt갱신
                cnt %= n;                   // 이전 수 
                ret++;                            

            }
        }
    }
}