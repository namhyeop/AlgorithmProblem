#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

int n;
int main(void)
{
	fastio;
	cin >> n;
	int arr[3];
	int dpmin[3];
	int dpmax[3];
	cin >> arr[0] >> arr[1] >> arr[2];

	for (int i = 0; i < 3; i++)
		dpmin[i] = dpmax[i] = arr[i];

	n--;
	while (n--)
	{
		cin >> arr[0] >> arr[1] >> arr[2];

		dpmax[0] = max(dpmax[0], dpmax[1]);
		dpmax[2] = max(dpmax[1], dpmax[2]);
		dpmax[1] = max(dpmax[0], dpmax[2]) + arr[1];
		dpmax[0] += arr[0];
		dpmax[2] += arr[2];

		dpmin[0] = min(dpmin[0], dpmin[1]);
		dpmin[2] = min(dpmin[1], dpmin[2]);
		dpmin[1] = min(dpmin[0], dpmin[2]) + arr[1];
		dpmin[0] += arr[0];
		dpmin[2] += arr[2];
	}

	cout << max({ dpmax[0], dpmax[1], dpmax[2] }) << " " << min({ dpmin[0], dpmin[1], dpmin[2] });
}
