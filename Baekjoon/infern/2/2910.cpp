#include <bits/stdc++.h>
using namespace std;
int n, c, a[1001];
map<int, int> mp, mp_first;
vector<pair<int,int>> v;

bool compare(pair<int,int> a, pair<int,int> b)
{
    // 빈도가 같으면 먼저 나온거
    if(a.first == b.first) 
        return mp_first[a.second] < mp_first[b.second];
    // 아니면 빈도가 큰거 
    return a.first > b.first;
}

int main()
{
    cin >> n >> c;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
        // 없으면 체크
        // 예를 들어 1이 3번째에 처음나왔으면 mp_first[1] = 3
        if(mp_first[a[i]] == 0) mp_first[a[i]] = i + 1;
    }

    // vector에 담기
    for(auto it : mp)
    {
        // {빈도, 숫자}
        v.push_back({it.second, it.first});
    }

    // 정렬
    sort(v.begin(), v.end(), compare);

    for(pair<int,int> i : v)
    {
        // 빈도만큼 출력
        for(int j = 0; j < i.first; j++)
        {
            cout << i.second << " ";
        }
    }

}
