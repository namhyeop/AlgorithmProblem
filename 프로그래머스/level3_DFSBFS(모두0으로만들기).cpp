#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 3e5 + 1;
vector<ll> A;
vector<int> board[MAX];
ll ret;

void DFS(int cur, int p)
{
	for (auto i : board[cur])
	{
		if (i == p)
			continue;

		if (board[i].size() != 1)
		{
			DFS(i, cur);
		}

		ret += abs(A[i]); //횟수를 더해주므로 절대값으로 더해줘야한다.
		A[cur] += A[i];
		A[i] = 0;
	}
}
long long solution(vector<int> a, vector<vector<int>> edges)
{
	ll checkValue = 0;
	int flag = 1;
	for (auto value : a)
	{
		checkValue += value;
		flag &= (value == 0);
	}
	if (checkValue != 0)
		return -1;
	if (flag)
		return 0;

	for (auto i : a)
		A.push_back(i);

	for (auto i : edges)
	{
		board[i[0]].push_back(i[1]);
		board[i[1]].push_back(i[0]);
	}

	DFS(0, -1);

	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	vector<int> a = { -5, 0, 2, 1, 2 };
	vector<vector<int>> edges = { { 0, 1 }, { 3, 4 }, { 2, 3 }, { 0, 3 }};
	cout << solution(a, edges) << "\n";

	a = { 0, 1, 0 };
	edges = { { 0, 1 }, { 1, 2 } };

	cout << solution(a, edges) << "\n";

	return 0;
}
