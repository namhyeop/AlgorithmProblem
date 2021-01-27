#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#define MAX 1001
using namespace std;

int board[MAX][MAX];
int N;
int M;
int dp[MAX];
int cost[MAX];
vector<pair<int, int>> v[MAX];
priority_queue<pair<int, int>> pq;

int main(int argc, char *argv[])
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int node1, node2, value;
		cin >> node1 >> node2 >> value;
		v[node1].push_back({ node2, value });
		v[node2].push_back({ node1, value });
	}
	fill(cost + 1, cost + 1 + N, INT_MAX);
	cost[2] = 0;
	dp[2] = 1;
	pq.push({ 0, 2 });

	//pq.first == 길이
	//pq.second == node;
	int a = 0;
	while (!pq.empty())
	{
		int h = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();

		int tmp1 = cost[h] ^ distance;
		if (cost[h] ^ distance)
			continue;
		//distance는 이전길
		//idx.second는 이번 노드
		for (auto idx : v[h])
		{
			int idxDistance = idx.second + distance;
			if (idxDistance < cost[idx.first])
			{
				cost[idx.first] = idxDistance;
				pq.push({ -idxDistance, idx.first });
			}
			//이번 비용이 이전 비용보다 적다면 dp 기록
			if (cost[idx.first] < distance)
				dp[h] += dp[idx.first];
		}
		a++;
	}

	cout << dp[1] << "\n";
	return 0;
}
