#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;
const int MAX = 1e5;

int n, t;
int arr[MAX + 1];
int copyArr[MAX + 1];
int ret[MAX + 1];

bool isValid(int creValue)
{
	for (int i = 0; i < n; i++)
		copyArr[i] = arr[i];
	
	ll cnt = 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (copyArr[i + 1] - copyArr[i] > creValue)
		{
			cnt += copyArr[i + 1] - (copyArr[i] + creValue);
			copyArr[i + 1] = copyArr[i] + creValue;
		}
	}

	for (int i = n - 1; i > 0; i--)
	{
		if (copyArr[i - 1] - copyArr[i] > creValue)
		{
			cnt += copyArr[i - 1] - (copyArr[i] + creValue);
			copyArr[i - 1] = copyArr[i] + creValue;
		}
	}

	if (cnt <= t)
		return true;
	return false;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> t;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int left = -1, right = 1e9;

	while (left +1 < right)
	{
		int mid = (left + right) / 2;

		if (isValid(mid))
		{
			right = mid;

			for (int i = 0; i < n; i++)
				ret[i] = copyArr[i];
		}
		else
			left = mid;
	}

	for (int i = 0; i < n; i++)
		cout << ret[i] << " ";
	cout << "\n";
	return 0;
}
