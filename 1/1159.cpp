#include <bits/stdc++.h>
using namespace std;

int A, B, C;
int a, b, cnt[104];
int ret;

int main(){
    cin >> A >> B >> C; 

    for(int i = 0; i < 3; i++)
    {
        cin >> a >> b;
        for(int j = a; j < b; j++) cnt[j]++;        
    }

    for(int j = 0; j < 104; j++)
    {
        if(cnt[j])
        {
            if(cnt[j]==1) ret += A;
            else if(cnt[j]==2) ret += 2 * B;
            else if(cnt[j]==3) ret += 3 * C;
        }
    }
    cout << ret << '\n';


    return 0;
}