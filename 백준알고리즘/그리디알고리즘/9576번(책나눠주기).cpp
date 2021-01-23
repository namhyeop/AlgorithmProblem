#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#define MAX 1001
using namespace std;

bool visited[MAX];

bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.second < b.second;
}

int main(int argc, char *argv[])
{
	int Testcase;
	cin >> Testcase;

	for (int i = 0; i < Testcase; i++)
	{
		memset(visited, false, sizeof(visited));
		int n, m;
		int ret = 0;
		cin >> n >> m;
		
		vector<pair<int, int>> v;
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;

			v.push_back({ a, b });
		}

		sort(v.begin(), v.end(), cmp);
		
		for (int i = 0; i < m; i++)
		for (int j = v[i].first; j <= v[i].second; j++)
		{
			if (!visited[j])
			{
				visited[j] = true;
				ret++;
				break;
			}
		}
		cout << ret << "\n";
	}
	return 0;
}
