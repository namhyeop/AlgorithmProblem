#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;
const int MAX = 1e5;
int n, m;
int arr[MAX + 1];

ll maxValue = LLONG_MIN;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	ll max = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (maxValue < arr[i])
			maxValue = arr[i];
	}

	ll left = 1, right = maxValue * m;
	ll ret = maxValue * m;

	while (left <= right)
	{
		ll mid = (left + right) / 2;
		ll pass = 0;
		for (int i = 0; i < n; i++)
		{
			pass += mid/arr[i];
		}

		if (pass >= m)
		{
			if (ret > mid)
				ret = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	cout << ret << "\n";

	return 0;
}
