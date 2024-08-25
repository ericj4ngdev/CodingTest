#include<bits/stdc++.h>
using namespace std;

int n, m, ret;
int a[10][10];

void MultipleNum(int num)
{
    float root = sqrt(num);
    if(root - (int)root != 0) return;
    if(root * root == num)
    {
        // 완전 제곱수
        // max인거 찾기
        ret = max(ret, num);
    }
}


void PickNum(int tolR, int tolC)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int num = 0;
            int x = i;
            int y = j;
            while (x >= 0 && x < n && y >= 0 && y < m)
            {
                num *= 10;
                num += a[x][y];
                x += tolR;
                y += tolC;
                MultipleNum(num);
            }
        }
    }
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ret = -1;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {        
        for(int j = 0; j < m; j++)
        {
            scanf("%1d", &a[i][j]);
        }
    }

    for(int tolR = -n; tolR < n; tolR++)
    {        
        for(int tolC = -m; tolC < m; tolC++)
        {
            if(tolR == 0 && tolC == 0) 
            {
                continue;
            }
            // 이런 공차일 때 뽑는 수
            PickNum(tolR,tolC);
        }
    }

    cout << ret;

    return 0;
}