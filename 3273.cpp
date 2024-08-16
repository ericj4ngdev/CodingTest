#include<bits/stdc++.h>
using namespace std;

int a[1000001];
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a,a+n);
    int x = 0;
    cin >> x;
    int ret = 0;
    int left = 0;
    int right = n - 1;

    while(left < right)
    {
        if(a[left] + a[right] == x)
        {
            cout << a[left] << ", " << a[right] << endl;
            // right--;            
            left++;
            ret++;
        }
        else if(a[left] + a[right] > x) 
        {
            cout << a[left] << ", " << a[right] << " > x " << endl;            
            right--;
        }
        else if(a[left] + a[right] < x) 
        {
            cout << a[left] << ", " << a[right] << " < x" << endl;            
            left++;
        }
    }

    cout << ret << '\n';
    return 0;
}