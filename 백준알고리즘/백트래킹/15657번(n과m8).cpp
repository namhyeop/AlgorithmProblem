#include<bits/stdc++.h>

using namespace std;

int n, m;
int arr[9];
vector<int> v;

void func(int N, int cnt)
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
		if (i >= cnt)
		{
			arr[N] = v[i];
			func(N + 1, i);
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
