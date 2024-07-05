// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 54;
int city[MAX_SIZE][MAX_SIZE];
vector<vector<int>> ChickenList;
vector<pair<int, int>> StoresPosition;
vector<pair<int, int>> HousePosition;
int n, m;
int ret = 987654321;

int GetChickenDistance(pair<int,int> house, vector<int> chList)
{
    int ChickenDistance = 0;    
    int MinChickenDistance = 987654321;     // 이거 안해서 오류. 그런데 테스트 케이스는 괜찮았음
    // 치킨 집 순회돌아서 집과의 거리중 최소값 반환
    for(int ch : chList)
    {
        ChickenDistance = abs(StoresPosition[ch].first - house.first) + abs(StoresPosition[ch].second - house.second);
        MinChickenDistance = min(MinChickenDistance, ChickenDistance);
    }
    return MinChickenDistance;
}

int GetCityChickenDistance(vector<int> chList)
{
    int CityChickenDistance = 0;
    // 모든 집의 치킨 거리 합
    for(int i = 0; i < HousePosition.size(); i++)
    {
        CityChickenDistance += GetChickenDistance(HousePosition[i], chList);
    }
    return CityChickenDistance;
}

void Input()
{    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> city[i][j];
            
            // 집 좌표 저장
            if(city[i][j] == 1)
            {
                HousePosition.push_back(make_pair(i,j));
            }
            // 치킨집 좌표 저장
            if(city[i][j] == 2)
            {
                StoresPosition.push_back(make_pair(i,j));
            }
            
        }
    }
}

void Combi(int start, vector<int> b)
{
    if(b.size() == m) 
    {
        // 인덱스 조합 추가
        ChickenList.push_back(b);
        return;
    }

    for(int i = start + 1; i < StoresPosition.size(); i++)
    {
        b.push_back(i);
        Combi(i,b);
        b.pop_back();
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();

    vector<int> v;
    Combi(-1, v);
    // 치킨집 좌표 리스트를 아니까 치킨집 인덱스로 구성된 배열을 
    // 조합으로 구해서 순회를 돌자. 
    for(vector<int> chList : ChickenList)
    {
        // 한 조합에서 치킨 거리 계산
        ret = min(ret, GetCityChickenDistance(chList));        
    }
    
    cout << ret;
    return 0;
}
