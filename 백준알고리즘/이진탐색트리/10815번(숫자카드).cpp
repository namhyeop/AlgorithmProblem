#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)

using namespace std;
const int MAX = 1e7;

int n,m;
int arr[MAX];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;

		if (binary_search(arr, arr + n, num))
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
	}

	return 0;
}
