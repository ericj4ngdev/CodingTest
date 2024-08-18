#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int senser[10001];
int diff[10001];

int main()
{
    int n = 0;
    int station = 0;
    cin >> n >> station;
    for(int i = 0; i < n; i++)
    {
        cin >> senser[i];
    }
    sort(senser, senser + n);

    for(int i = 1; i < n; i++)
    {
        diff[i-1] = senser[i] - senser[i-1];
    }
    sort(diff, diff + n);

    int ret = 0;
    for(int i = 0; i < n - station + 1; i++)
    {
        ret += diff[i];
    }
    cout << ret;
    // statation - 1 번 뺴기 
    // for문 끝점 제어 0 ~ n - station + 1
    // 1 3 6 6 7 9 
    //  2 3 0 1 2
    // 0 1 2 2 3(6 -2 + 1)
    // 2개면 가장 긴 부분 분할
    //  2     1 2 
    // 더하면 2+1+2 = 5
    // 3개면 가장 긴 2개 분할
    //      1  2 
    // 3



    return 0;
}

