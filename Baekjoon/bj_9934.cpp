#include <bits/stdc++.h>
using namespace std;

vector<int> ret[14];
int n, a[1030];
 
void go(int start, int end, int level)
{
		if(start>end) return;
		if(start == end)
		{
				ret[level].push_back(a[start]);
				return;
		}

		int mid = (start + end) / 2;
		ret[level].push_back(a[mid]);

		go(start,mid - 1, level + 1);
		go(mid + 1, end, level + 1);
        return;
}

int main()
{
    cin >> n;
    int end = (int)pow(2,n) - 1;
    for(int i = 0; i < end ; i++)
    {
        cin >> a[i];
    }
    go(0,end,1);

    for(int i = 1; i <= n; i++)
    {
        for(int j : ret[i])
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}