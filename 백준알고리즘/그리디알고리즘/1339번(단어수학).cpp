/*
//98654 783
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<functional>

using namespace std;

int arr[26];
int main(int argc, char *argv[])
{
	int N;
	cin >> N;
	
	string tmp;


	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		for (int j = 0; j < tmp.length(); j++)
		{
			char c = tmp[j];
			int l = tmp.length() - j - 1;
			arr[c - 'A'] += pow(10, l);
		}
	}

	int ret = 0;
	int idx = 0;
	sort(arr, arr + 26, greater<int>());
	for (int i = 9; i >= 0; i--)
	{
		ret += arr[idx] * i;
		idx++;
	}

	cout << ret << "\n";

	return 0;
}
*/
