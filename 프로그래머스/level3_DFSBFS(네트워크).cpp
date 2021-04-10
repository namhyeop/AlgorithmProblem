#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;
const int MAX = 201;

bool visited[MAX][MAX];
bool check[MAX];

void DFS(int cur, int &n, vector<vector<int>> &computers)
{
	for (int i = 0; i < n; i++)
	{
		if (visited[cur][i])
			continue;

		if (computers[cur][i] == 1)
		{
			check[i] = true;
			visited[cur][i] = true;
			visited[i][cur] = true;
			DFS(i, n, computers);
		}
	}
}

int solution(int n, vector<vector<int>> computers)
{
	int answer = 0;

	for (int i = 0; i < n; i++)
	{
		if (!check[i])
		{
			check[i] = true;
			visited[i][i] = true;
			DFS(i, n, computers);
			answer++;
		}
	}

	return answer;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<vector<int>> v(3);
	v[0] = { 1, 1, 0 };
	v[1] = { 1, 1, 1 };
	v[2] = { 0, 1, 1 };

	cout << solution(3, v);
}
