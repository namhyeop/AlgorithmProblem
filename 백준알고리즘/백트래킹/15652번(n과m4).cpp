#include<bits/stdc++.h>
#define MAX 9
using namespace std;

int n, m;
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

	for (int i = N == 0 ? 1 : arr[N - 1]; i <= n; i++)
	{
		arr[N] = i;
		func(N + 1);
	}
}
int main(int argc, char *argv[])
{
	cin >> n >> m;
	func(0);
}
