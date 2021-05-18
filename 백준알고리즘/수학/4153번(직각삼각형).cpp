#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;

int main()
{
	fastio;
	int arr[3];
	while (1)
	{
		cin >> arr[0] >> arr[1] >>  arr[2];

		if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0)
			break;

		sort(arr, arr + 3, greater<int>());

		if ((arr[0] * arr[0]) == (arr[1] * arr[1]) + (arr[2] * arr[2]))
			cout << "right" << "\n";
		else
			cout << "wrong" << "\n";
	}
}
