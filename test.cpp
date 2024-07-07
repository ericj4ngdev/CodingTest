#include <bits/stdc++.h>
using namespace std;

int n, m, ret = 987654321;
const int MAX = 54;
int a[MAX][MAX];
vector<vector<int>> ChickenList;
vector<pair<int,int>> house, chicken;

int GetCityChickenDistance(vector<int>& chickenIdx)
{
	int CityChickenDistance = 0;
    int distance = 0;
    
	for(int i = 0; i < house.size(); i++)
	{
        // 여기서 문제 
	    int minDistance = 987654321;
		for(int idx : chickenIdx)
		{
			distance = abs(house[i].first - chicken[idx].first) + abs(house[i].second - chicken[idx].second);
			minDistance = min(minDistance, distance);
		}
		CityChickenDistance += minDistance;
	}

	return CityChickenDistance;
}

void Combi(int start, vector<int> v)
{
	if(v.size() == m)
	{
		// 인덱스 조합 추가
		ChickenList.push_back(v);
		return;
	}

	for(int i = start + 1; i < chicken.size(); i++)
	{
		// 인덱스 추가
		v.push_back(i);
		// 재귀
		Combi(i, v);
		v.pop_back();
	}
	return;
}

int main()
{	
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			if(a[i][j] == 1) house.push_back({i,j});
			if(a[i][j] == 2) chicken.push_back({i,j});
		}
	}
	vector<int> v;
	Combi(-1, v);


	for(vector<int> chList : ChickenList)
	{
		ret = min(ret, GetCityChickenDistance(chList));
	}

	cout << ret;

	return 0;
}