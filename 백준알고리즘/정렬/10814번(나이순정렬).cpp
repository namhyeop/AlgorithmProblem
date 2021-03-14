#include<bits/stdc++.h>
#define MAX 100001
using namespace std;

int n;
pair<int, string> arr[MAX];

bool cmp(pair<int, string> a, pair<int, string> b)
{
	if (a.first < b.first)
		return true;
	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;
	
	stable_sort(arr, arr + n, cmp);
	
	for (int i = 0; i < n; i++)
		cout << arr[i].first << " " << arr[i].second << "\n";
	
	return 0;
}
