#include<bits/stdc++.h>
#define MAX 1001
using namespace std;

int N,M;
int dp[MAX];
int cost[MAX];
vector<pair<int, int>> v[MAX];
priority_queue<pair<int, int>> pq;

int main(int argc, char *argv)
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

	while (pq.empty())
	{
		//pq의 first는 길이
		//pq의 second는 노드
		int h = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();

		if (cost[h] != distance)
			continue;

		//입력값과 연관
		//idx.first == node
		//idx.second == length
		for (auto idx : v[h])
		{
			int idxDistance = idx.second + distance;
			if (idxDistance < cost[idx.first])
			{
				cost[idx.first] = idxDistance;
				pq.push({ -idxDistance, idx.first });
			}
			if (cost[idx.first] < distance)
				dp[h] += dp[idx.first];
		}
	}

	cout << dp[1] << "\n";

	return 0;
}
