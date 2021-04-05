#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;

const int MAX = 1e6 + 1;
ll n, m, ret;
ll arr[MAX];
ll maxValue;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if(maxValue < arr[i]) maxValue = arr[i];
	}
	
	ll left = 1, right = maxValue;

	while (left <= right)
	{
		ll mid;

		mid = (left + right) / 2;
		ll sum = 0;

		for (int i = 0; i < n; i++)
			sum += arr[i] / mid;

		if (sum >= m)
		{
			if (ret < mid)
				ret = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	cout << ret << "\n";
}
