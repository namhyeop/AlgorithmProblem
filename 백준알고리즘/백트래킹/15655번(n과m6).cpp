#include<bits/stdc++.h>

using namespace std;

int n, m;
int arr[8];
bool visited[10000];

vector<int> v;
void func(int N, int beforV)
{
	if (N == m)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (!visited[v[i]] && i >= beforV)
		{
			arr[N] = v[i];
			visited[v[i]] = true;
			func(N + 1, i);
			visited[v[i]] = false;
		}
	}
}
int main(int argc, char*argv[])
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());
	func(0,0);
}
