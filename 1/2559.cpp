#include<bits/stdc++.h>
using namespace std;

int n, k;
int a[100004][100004];
int main()
{
    int ret = -1001;
    cin >> n >> k;

    for(int j = 0; j < n; j++)
    {
        cin >> a[1][j];
    }

    for(int i = 1; i < k; i++)
    {
        for(int j = 0; j < n - i; j++)
        {
            a[i+1][j] = a[i][j] + a[1][i+j];
            ret = max(ret, a[i+1][j]);
        }
    }

    cout << ret;
}