#include<bits/stdc++.h>
using namespace std;

int a[9], sum;

void go()
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(sum - a[i] - a[j] == 100)
            {
                a[i] = 0; 
                a[j] = 0;
                return;
            }
        }
    }
}


int main()
{
    for(int i = 0; i < 9; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    
    sort(a,a+9);
    go();
    for(int i = 0; i < 9; i++)
    {
        if(a[i] == 0) continue;
        cout << a[i] << ' ';
    }

    return 0;
}