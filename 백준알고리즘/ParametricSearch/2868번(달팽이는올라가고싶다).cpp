#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;

int v, a, b;
int ret = INT_MAX;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> a >> b >> v;

	int left = 0;
	int right = (v + a) / (a - b);

	while (left <= right)
	{
		int mid = (left + right) / 2;
		int sum = (mid * a) - ((mid - 1) * b);

		if (sum >= v)
		{
			ret = min(ret, mid);
			right = mid - 1;
		}
		else
			left = mid + 1;
	}

	cout << ret << "\n";
	return 0;
}
