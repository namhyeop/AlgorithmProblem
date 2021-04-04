#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)

using namespace std;
const int MAX = 51;
int arr[MAX];
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	sort(arr, arr + n);

	cout << arr[0] * arr[n - 1] << "\n";

	return 0;
}
