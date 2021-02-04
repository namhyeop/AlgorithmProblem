#include<bits/stdc++.h>
#define MAX 8
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

	for (int i = 1; i <= n; i++)
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
