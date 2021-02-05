#include<bits/stdc++.h>

using namespace std;

int n, m;
int arr[8];
vector<int> v;

void func(int level, int cnt)
{
	if (level == m)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	bool visited[10000];
	memset(visited, false, sizeof(visited));

	for (int i = 0; i < n; i++)
	{
		if (!visited[v[i]] && i >= cnt)
		{
			visited[v[i]] = true;
			arr[level] = v[i];
			func(level + 1, i);
		}
	}
}
int main(int argc, char *argv[])
{
	cin >> n >> m;
	
	v.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	func(0, 0);
}
