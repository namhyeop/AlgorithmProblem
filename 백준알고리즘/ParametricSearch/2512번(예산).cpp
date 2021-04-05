
#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;
const int MAX = 10001;
ll arr[MAX];
ll maxValue = INT_MIN;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n,k;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (maxValue < arr[i])
			maxValue = arr[i];
	}
	cin >> k;

	ll left = 0, right = maxValue;

	ll ret = 0;
	ll retLen = 0;
	while (left <= right)
	{
		int mid = (left + right) / 2;

		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (mid < arr[i])
				sum += mid;
			else
				sum += arr[i];
		}
		
		if (ret < sum  && sum <= k)
		{
			ret = sum;
			retLen = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	cout << retLen << "\n";
}
