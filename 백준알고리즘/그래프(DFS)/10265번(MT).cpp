/*
DFS + DP 문제, 옛날에 풀었던 knapsack 문제의 개념과 병행해서 풀면 더 이해가 쉬움
아직 내가 풀 문제는 아닌거 같다.
일단 DP의 규칙을 시간을 좀 더 많이 주어져도 찾지 못했을꺼 같다.
너무 난이도가 높다 추후 다시 풀어봐야 할 문제.
*/
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

struct NODE
{
	int next;
	int cycle = 0;
	int cycleCnt = 0;
	int varCnt = 0;
};

int N; //사람 수
int K; //버스에 태울 사람의 수
int list_size;
int dp[1001][1001];
NODE node[1001];
bool visited[1001];
bool chcked[1001];
queue<int> q;
vector<pair<int, int>> list;

int dfs(int x)
{
	visited[x] = true;
	int next = node[x].next;
	int cycle = 0;
	if (!chcked[next])
	{
		if (visited[next])
		{
			int cnt = 1;
			node[x].cycle = x;
			while (next != x)
			{
				cnt++;
				node[next].cycle = x;
				next = node[next].next;
			}
			node[x].cycleCnt = cnt;
			node[x].varCnt = -cnt;
			q.push(x);
			cycle = x;
		}
		else
			cycle = dfs(next);
	}
	else
	{
		cycle = node[next].cycle;
	}
	chcked[x] = true;
	node[x].cycle = cycle;
	node[cycle].varCnt++;
	return cycle;
}
int main(int argc, char *argv[])
{
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		cin >> node[i].next;

	for (int i = 1; i <= N; i++)
	{
		if (!chcked[i])
			dfs(i);
	}

	int c = 0;
	while (!q.empty())
	{
		c = q.front();
		q.pop();
		if (node[c].cycleCnt > K)
			continue;
		list.push_back(make_pair(node[c].cycleCnt, node[c].varCnt));
	}

	list.push_back(make_pair(0, 0));
	sort(list.begin(), list.end());
	list_size = list.size();

	memset(dp, -1, sizeof(dp));
	int w, v;
	for (int i = 1; i < list_size; i++)
	{
		w = list[i].first;
		v = list[i].second;
		dp[i][w] = v;
		for (int j = 1; j <= K; j++)
		{
			if (j > w)
			{
				if (dp[i - 1][j - w] >= 0)
					dp[i][j] = max(dp[i - 1][j - w] + v, dp[i - 1][j]);
				else
					dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			}
			else
				dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}

	int ans = 0;
	for (int i = 1; i <= K; i++)
	{
		if (dp[list_size - 1][i] >= 0)
		{
			ans = max(ans, i + dp[list_size - 1][i]);
		}
	}
	if (ans > K)
		cout << K << "\n";
	else
		cout << ans << "\n";
	return 0;
}
