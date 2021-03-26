#include<bits/stdc++.h>

using namespace std;
const int MAX = 10001;

int n;
int cache[MAX]; //i번째 값까지 중에서 가장 큰 값
int arr[MAX];
int ret;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++)
	{
		cache[i] = arr[i];
		for (int j = 0; j <= i; j++)
		if (arr[i] > arr[j] && cache[i] < cache[j] + arr[i])
			cache[i] = cache[j] + arr[i];

		if (cache[i] > ret)
			ret = cache[i];
	}

	cout << ret << "\n";
	
	return 0;
}

/*
#include<iostream>
#include<algorithm>

using namespace std;

int n;
int cache[1001];
int A[1001];


int search(void)
{
	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		cache[i] = A[i];

		for (int j = 0; j <= i; j++)
			if (A[i] > A[j] && cache[i] < cache[j] + A[i]) //수열에서 앞에꺼보다 뒤에 수열이 더 큰경우 && i로 나타내는 현재 값보다 전에서 계속 더한 값이 
				cache[i] = cache[j] + A[i];				//더 크다면 더 큰값으로 갱신한다

			if (cache[i] > ret)
				ret = cache[i];
	}


	return ret;
}

int main(int argc, int argv[])
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> A[i];

	cout << search() << endl;
}
*/
