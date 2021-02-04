#include<bits/stdc++.h>
#define MAX 7
using namespace std;

int n, m;
vector<int> v;
int arr[MAX];

void func(int N)
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
		arr[N] = v[i];
		func(N + 1);
	}
}
int main(int argc, char *argv[])
{
	cin >> n >> m;
	v.resize(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	func(0);
}
