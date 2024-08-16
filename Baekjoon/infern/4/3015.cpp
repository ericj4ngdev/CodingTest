#include<bits/stdc++.h>
using namespace std;

int n, cnt,temp;
int a[500004];
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        a[i] = temp;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n-i; j++)
        {
            if(a[i] > a[i+j]) cnt++;
            else 
            {
                cnt++;
                continue;
            }
        }
    }

    return 0;
}