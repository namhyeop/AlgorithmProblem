  
#include<bits/stdc++.h>

using namespace std;
const int MAX = 1e5 + 1;

int arr[MAX];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n,m;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + n);

	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int tmp;
		cin >> tmp;

		if (binary_search(arr, arr + n, tmp))
		{
			cout << 1 << "\n";
			//cout << binary_search(arr, arr + n, tmp) << "\n";
		}
		else
		{
			cout << 0 << "\n";
			//cout <<binary_search(arr, arr + n, tmp) << "\n";
		}
	}

	return 0;
}
