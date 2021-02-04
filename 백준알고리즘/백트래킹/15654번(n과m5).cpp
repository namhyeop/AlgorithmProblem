#include<bits/stdc++.h>
#define MAX 10000
using namespace std;

int n, m;
vector<int> v;
int arr[MAX];
bool visited[MAX];
void func(int N)
{
	if (N == m)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	for (int j = 0 ; j < n; j++)
	{
		if (!visited[v[j]])
		{
			arr[N] = v[j];
			visited[v[j]] = true;
			func(N + 1);
			visited[v[j]] = false;
		}
	}
}
int main(int argc, char *argv[])
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	func(0);
}
