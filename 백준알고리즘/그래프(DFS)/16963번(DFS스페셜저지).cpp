#include<bits/stdc++.h>
#define MAX 100001

using namespace std;

int n;
vector<int> v[MAX];
int cmpOrder[MAX];
int expected[MAX];
bool visited[MAX];
int idx;

bool cmp(int a, int b)
{
	return cmpOrder[a] < cmpOrder[b];
}

void DFS(int cur)
{
	if (cur != expected[idx++])
	{
		cout << 0 << "\n";
		exit(0);
	}

	for (int i = 0; i < v[cur].size(); i++)
	{
		int next = v[cur][i];
		if (visited[next] == true)
			continue;

		visited[next] = true;
		DFS(next);
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		v[tmp1].push_back(tmp2);
		v[tmp2].push_back(tmp1);
	}

	for (int i = 0; i < n; i++)
	{
		cin >> expected[i];
		cmpOrder[expected[i]] = i + 1;
	}

	for (int i = 1; i <= n; i++)
		sort(v[i].begin(), v[i].end(), cmp);

	visited[1] = true;
	DFS(1);

	cout << 1 << "\n";

	return 0;
}
