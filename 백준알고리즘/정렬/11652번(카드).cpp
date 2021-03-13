#include<bits/stdc++.h>
#define ll long long
#define MAX 1000000

using namespace std;

int n;
ll a[MAX + 1];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);

	int cnt = 0;
	ll mxValue = -(1ll << 62);
	//cout << mxValue << "\n";
	int mxcnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			cnt++;
		else if (a[i] == a[i - 1])
			cnt++;
		else
		{
			if (cnt > mxcnt)
			{
				mxcnt = cnt;
				mxValue = a[i - 1];
			}
			cnt = 1;
		}
	}

	if (cnt > mxcnt)
		mxValue = a[n - 1];

	cout << mxValue << "\n";

	return 0;
}
