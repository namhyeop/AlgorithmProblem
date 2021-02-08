#include<bits/stdc++.h>
#define MAX 10001
using namespace std;

int n;
int m;
int arr[MAX];

int main(int argc, char *argv[])
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int ret = 0;
	int sum = 0;
	int low = 0;
	int high = 0;

	while (1)
	{
		if (sum >= m)
		{
			sum -= arr[low];
			low++;
		}
		else if (high == n)
		{
			break;
		}
		else
		{
			sum += arr[high];
			high++;
		}

		if (sum == m)
			ret++;
	}

	cout << ret << "\n";

	return 0;
}
