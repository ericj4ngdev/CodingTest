#include <bits/stdc++.h>
using namespace std;

int a[104][104];
int visited[104][104];
int n, m, x, y;

int dy[4] = { -1, 0, 1 ,0 };
int dx[4] = { 0,1,0,-1 };

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &a[i][j]);
		}
	}

	queue<pair<int, int>> q;
	visited[0][0] = 1;
	q.push({ 0,0 });
	while (q.size())
	{
		// q에서 좌표 얻기
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			// 인접 노드 좌표
			int ny = y + dy[i];
			int nx = x + dx[i];

			// 거르기
			if (ny > n || ny < 0 || nx > m || nx < 0 || a[ny][nx] == 0) continue;		// 외부 또는 벽
			if (visited[ny][nx]) continue;		// 이미 방문

			// 인접 시 담기
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny,nx });
		}
	}

	printf("%d", visited[n - 1][m - 1]);
	return 0;
}