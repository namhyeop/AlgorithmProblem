#include<bits/stdc++.h>

using namespace std;
const int MAX = 1001;

int n,m;
long long arr[MAX];
int main(void)
{
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < m; i++)
	{
		sort(arr, arr + n);
		long long sumValue = arr[0] + arr[1];
		arr[0] = arr[1] = sumValue;
	}

	long long sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];

	cout << sum << '\n';

	return 0;
}
