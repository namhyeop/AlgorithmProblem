#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;

ll n, c;
vector<ll> arr;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> c;

	arr.resize(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	sort(arr.begin(), arr.end());

	ll left = 1;
	ll right = arr[n - 1];
	ll ret = -1;

	while (left <= right)
	{
		ll mid = (left + right) / 2;
		ll beforIdx = 0;
		ll cctvSum = 1;

		for (int i = 1; i < n; i++)
		{
			if (arr[i] - arr[beforIdx] >= mid)
			{
				beforIdx = i;
				cctvSum++;
			}
		}

		if (cctvSum >= c)
			left = mid + 1;
		else
			right = mid - 1;

		if (ret < mid && cctvSum >= c)
			ret = mid;
	}

	cout << ret << "\n";

	return 0;
}
