#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<int> v;
int arr[9];

void func(int N, int cnt)
{
	if (N == m)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	bool visited[10000] = { false, };
	for (int i = 0; i < n; i++)
	{
		if (!visited[v[i]] && i >= cnt)
		{
			arr[N] = v[i];
			visited[v[i]] = true;
			func(N + 1, i + 1);
		}
	}
}
int main(int argc, char* argv[])
{
	cin >> n >> m;

	v.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	func(0,0);

}
