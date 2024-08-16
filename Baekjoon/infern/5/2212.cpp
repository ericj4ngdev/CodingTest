#include<bits/stdc++.h>
using namespace std;

const int MAXSIZE = 10004;
int senser, station, ret;
int sens[MAXSIZE];
int dist[MAXSIZE];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> senser >> station;
    
    for(int i = 0; i < senser; i++)
    {
        cin >> sens[i];
    }
    sort(sens, sens + senser);

    for(int i = 1; i < senser; i++)
    {
        dist[i-1] = sens[i] - sens[i-1];
    }
    sort(dist, dist + senser);

    for(int i = 0; i < senser - (station - 1); i++)
    {
        ret += dist[i];
    }

    cout << ret;
    return 0;
}