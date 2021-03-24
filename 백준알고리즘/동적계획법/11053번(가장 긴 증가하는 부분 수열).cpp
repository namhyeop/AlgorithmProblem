#include<bits/stdc++.h>

using namespace std;
const int MAX = 1001;

int cache[MAX];
int arr[MAX];
int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];


	fill_n(cache, 1001, 1);

	int ret = 1;
	for (int i = 0; i < n; i++)
	{
		int curValue = arr[i];
		for (int j = 0; j < i; j++)
		{
			int cmpValue = arr[j];
			if (curValue > arr[j])
				cache[i] = max(cache[i], cache[j] + 1);
		}
		ret = max(ret, cache[i]);
	}
	cout << ret << "\n";
}

/*
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int ArraySize;
int cache[1001];
int Array[1001];

int search(int start)
{
	if (start == ArraySize)
		return 1;

	int &ret = cache[start + 1];
	if (ret != -1)
		return ret;
	ret = 1;
	for (int next = start + 1; next < ArraySize; next++)
	{
		if (start == -1 || Array[start] < Array[next])
			ret = max(ret, search(next) + 1);
	}
	return ret;
}
int main(int argc, char * argv[])
{
	cin >> ArraySize;

	memset(cache, -1, sizeof(cache));
	for (int i = 0; i < ArraySize; i++)
	{
		cin >> Array[i];
	}

	cout << search(-1) - 1 << endl;
}
*/
