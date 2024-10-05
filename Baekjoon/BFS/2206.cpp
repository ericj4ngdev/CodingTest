#include<iostream>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;

int n, m;
int arr[1001][1001];
int visit[1001][1001][2]; // 최단거리값
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int bfs() {
	queue <pair<pair<int, int>, int>> q; // x좌표, y좌표, 벽뚫 유무
	q.push({ { 1,1 }, 0 });
	// 벽 안부수고 첫번째 시작점
	visit[1][1][0] = 1;
	while (!q.empty())
	{

		int x = q.front().first.first;
		int y = q.front().first.second;
		// 벽 뚫은 횟수
		int wall = q.front().second;
		// 0 : 안 뚫음
		// 1 : 뚫음
		q.pop();
		// 도착하면 바로 탈출
		if (x == n && y == m) return visit[x][y][wall];

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || nx > n || ny < 1 || ny > m)  continue;

			// 길 & 미방문 => 현재 탐색 갱신(wall에 상관없이)
			if (arr[nx][ny] == 0 && visit[nx][ny][wall] == 0)
			{
				visit[nx][ny][wall] = visit[x][y][wall] + 1;
				q.push({ { nx,ny }, wall });
			}
			
			// 벽 & 벽뚫 한적 X
			if (arr[nx][ny] == 1 && wall == 0)
			{
				// 벽 뚫고 탐색
				visit[nx][ny][wall + 1] = visit[x][y][wall] + 1;
				// 벽 뚫은 횟수 증가하고 큐에 담기
				q.push({ {nx,ny}, wall + 1 });
			}
		}
	}
	return -1;
}

int main() {

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		string str;
		cin >> str;
		for (int j = 1; j <= m; j++)
		{
			arr[i][j] = str[j - 1] - '0';
		}
	}

	cout << bfs() << endl;
}