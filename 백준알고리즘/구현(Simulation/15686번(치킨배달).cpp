#include<bits/stdc++.h>

using namespace std;

int board[55][55];
int n, m;
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;

int main(void)
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	{
		cin >> board[i][j];
		if (board[i][j] == 1)
			house.push_back({ i, j });
		if (board[i][j] == 2)
			chicken.push_back({ i, j });
	}
	vector<int> brute(chicken.size(), 1);
	fill(brute.begin(), brute.begin() + chicken.size() - m, 0);

	int mn = INT_MAX;
	do
	{
		int dist = 0;
		for (auto h : house) //집 마다 배치한 치킨집 과의 거리중 가장 짧은것들만 더해서 더한뒤 조합중에 가장 거리가 작은 값을 구한다
		{
			int tmp = INT_MAX;
			for (int i = 0; i < chicken.size(); i++)
			{
				if (brute[i] == 0)
					continue;
				tmp = min(tmp, abs(chicken[i].first - h.first) + abs(chicken[i].second - h.second));
			}
			dist += tmp;
		}
		mn = min(mn, dist);
	} while (next_permutation(brute.begin(), brute.end()));
	cout << mn;

	return 0;
}
