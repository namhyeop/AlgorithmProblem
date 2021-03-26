#include<bits/stdc++.h>

using namespace std;
const int MAX = 10001;
int n, k;
int cache[MAX];
int arr[MAX];
int main()
{
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	cache[0] = 1;
	for (int i = 1; i <= n; i++)
	for (int j = arr[i]; j <= k; j++)
	{
		cache[j] += cache[j - arr[i]];
	}
	cout << cache[k];
}
