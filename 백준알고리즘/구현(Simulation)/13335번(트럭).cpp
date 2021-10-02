#include<bits/stdc++.h>

using namespace std;

int n, w, l;
int arr[1001];

int parent[1001];
int main(void)
{
	cin >> n >> w >> l;

	int ans = 0;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	queue<int> q;
	int weight = 0;

	for (int i = 0; i < n; i++)
	{
		while (1)
		{
			if (q.size() == w)
			{
				weight -= q.front();
				q.pop();
			}
			if (weight + arr[i] <= l)
				break;
			q.push(0);
			ans++;
		}
		q.push(arr[i]);
		weight += arr[i];
		ans++;
	}
	ans += w;

	cout << ans << "\n";
	return 0;
}
