#include<bits/stdc++.h>

using namespace std;
const int MAX = 1e5 + 1;

int n;
long long cache[MAX][4];
int arr[MAX][4];

long long solve(int y, int x)
{
	if (y >= n || x < 0 || x > 2)
		return INT_MAX;
	
	if (y == n - 1 && x == 1)
		return arr[y][x];

	long long &result = cache[y][x];
	if (result != -1)
		return result;
	//cout << "y: " << y << "x: " << x << "\n";
	result = arr[y][x] + min(solve(y, x + 1), min(solve(y + 1, x - 1), min(solve(y + 1, x), solve(y + 1, x + 1))));
	//cout << "y: " << y << "x: " << x << "\n";
//	for (int i = 0; i <= n; i++)
//		cout << cache[i][0] << " " << cache[i][1] << " " << cache[i][2] << "\n";
	return result;
}


int main()
{
	int k = 1;
	while (1)
	{
		cin >> n;

		if (n == 0)
			break;

		memset(cache, -1, sizeof(cache));
		for (int i = 0; i < n; i++)
			cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
		
		cout << k++ << ". " << solve(0, 1) << "\n";
	}
	return 0;
}
