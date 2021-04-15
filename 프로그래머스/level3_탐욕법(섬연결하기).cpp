#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;

int parent[101];


bool cmp(vector<int> a, vector<int> b)
{
	if (a[2] <  b[2])
		return true;
	else
		return false;
}

int find(int cur)
{
	if (cur == parent[cur])
		return cur;
	else
		return parent[cur] = find(parent[cur]);
}

bool merge(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a == b)
		return false;
	else
	{
		//더 작은 녀석이 부모가 되어야 한다.
		if (a > b)
			parent[a] = b;
		else
			parent[b] = a;
		return true;
	}
}

int solution(int n, vector<vector<int>> costs)
{
	int answer = 0;

	for (int i = 0; i < n; i++)
		parent[i] = i;

	sort(costs.begin(), costs.end(), cmp);

	for (int i = 0; i < costs.size(); i++)
	if (merge(costs[i][0], costs[i][1]))
		answer += costs[i][2];
	return answer;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
}
