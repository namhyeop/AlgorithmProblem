#include<bits/stdc++.h>

using namespace std;
const int MAX = 1001;
int cache[MAX]; //i자리에서 올 수 있는 가장 긴 길이
int arr[MAX];
int v[MAX];

void go(int p)
{
	if (p == -1)
		return;
	go(v[p]);
	cout << arr[p] << " ";
}
int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	int p = 1;
	int ret = 1;
	for (int i = 1; i <= n; i++)
	{
		cache[i] = 1;
		v[i] = -1;
		for (int j = 1; j < i; j++)
		{
			if (arr[i] > arr[j] && cache[i] < cache[j] + 1)
			{
				cache[i] = cache[j] + 1;
				v[i] = j;
			}
		}
		if (ret < cache[i])
		{
			ret = cache[i];
			p = i;
		}
	}
	
	cout << ret << '\n';
	go(p);
	
	return 0;
}
