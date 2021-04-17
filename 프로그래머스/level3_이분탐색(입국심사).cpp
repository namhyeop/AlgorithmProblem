#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;

long long solution(int n, vector<int> times)
{
	ll maxValue= *max_element(times.begin(), times.end());

	ll left = 1;
	ll right = maxValue * n;
	ll ret = maxValue * n;
	while (left <= right)
	{
		ll mid = (left + right) / 2;

		ll cnt = 0;
		for (auto &i : times)
			cnt += mid / i;

		if (cnt >= n)
		{
			right = mid - 1;
			if (ret > mid)
				ret = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
}
