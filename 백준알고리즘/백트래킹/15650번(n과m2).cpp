#include<bits/stdc++.h>

using namespace std;

int n;
int m;
int arr[9];
bool visited[9];

void func(int N, int beforeV)
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
		if(!visited[i] && i > beforeV)
		{
			arr[N] = i;
			visited[i] = true;
			func(N + 1,i);
			visited[i] = false;
		}
	}
}
int main(int argc, char *argv[])
{
	cin >> n >> m;
	func(0,0);
}
