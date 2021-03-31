#include<bits/stdc++.h>

using namespace std;
const int MAX = 1e5 + 1;

int n;
int arr[MAX];

int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);
	int ret = 0;
	for (int i = 1; i <= n; i++)
		ret = max(ret, arr[n - i] * i);
	cout << ret;
}
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	int N;
	int max = 0;
	cin >> N ;
	
	vector<int>t(N);
	for (int i = 0; i < N; i++)
	{
		cin >> t[i];
	}

	sort(t.begin(), t.end(), less<int>());

	for (int i = 0; i < N; i++)
	{
		if (max < (t[i] * (N - i)))
		{
			max = (t[i] * (N - i));
		}
	}

	cout << max << endl;
		

}*/
