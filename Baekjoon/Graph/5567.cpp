#include <iostream>
#include <vector>
using namespace std;

int n, m;
const int depth = 2;
vector<int> v[10004];
bool adj[504];
int answer;

void dfs(int start, int count = 0)
{
	adj[start] = true;

	if (count == depth)	
		return;

	// 인접 노드를 재귀로 찾기
	for (int i = 0; i < v[start].size(); ++i)
	{
		// v[start][i] = start와 인접한 친구 학번
		// v[start] : start의 친구들 학번
		// 친구들 학번 순회하면서 dfs돌리기
		// 돌리면서 친구 표시. 나중에 한꺼번에 계산하기
		dfs(v[start][i], count + 1);
	}	
}

int main()
{
	// 그래프 저장 방식
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int left, right;
		cin >> left >> right;
		v[left].push_back(right);
		v[right].push_back(left);
	}

	// 재귀로 인접 노드 추적
	dfs(1);

	for (bool isFriend : adj)
	{
		if (isFriend)
			answer++;
	}

	// 마지막에 본인 빼고 초대하는 것이므로 -1해야 함
	cout << answer - 1;


	return 0;
}