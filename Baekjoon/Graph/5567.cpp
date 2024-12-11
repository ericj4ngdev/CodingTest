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

	// ���� ��带 ��ͷ� ã��
	for (int i = 0; i < v[start].size(); ++i)
	{
		// v[start][i] = start�� ������ ģ�� �й�
		// v[start] : start�� ģ���� �й�
		// ģ���� �й� ��ȸ�ϸ鼭 dfs������
		// �����鼭 ģ�� ǥ��. ���߿� �Ѳ����� ����ϱ�
		dfs(v[start][i], count + 1);
	}	
}

int main()
{
	// �׷��� ���� ���
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int left, right;
		cin >> left >> right;
		v[left].push_back(right);
		v[right].push_back(left);
	}

	// ��ͷ� ���� ��� ����
	dfs(1);

	for (bool isFriend : adj)
	{
		if (isFriend)
			answer++;
	}

	// �������� ���� ���� �ʴ��ϴ� ���̹Ƿ� -1�ؾ� ��
	cout << answer - 1;


	return 0;
}