#include<bits/stdc++.h>
using namespace std;

int ret; 
int n;
vector<int> v;

int main()
{
	cin >> n;

	v.resize(n);
	int left = 0;
	int right = n - 1;

	for (int i = 0; i < n; i++)
		cin >> v[i];
	
	sort(v.begin(), v.end());

	while (left < right)
	{
		if (v[left] < 1 && v[left+1] < 1)
			ret += v[left] * v[left + 1];
		else
			break;

		left += 2;
	}

	while (right > 0)
	{
		if (v[right] > 1 && v[right-1] > 1)
			ret += v[right] * v[right - 1];
		else
			break;

		right -= 2;
	}

	while (left <= right)
	{
		ret += v[left];
		left++;
	}

	cout << ret << "\n";
}
/*
#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;

ll ret;
vector<ll> input;

int main(int argc, char *argv[])
{
	ll N;
	cin >> N;
	
	ll left = 0;
	ll right = N - 1;

	for (int i = 0; i < N; i++)
	{
		ll tmp;
		cin >> tmp;
		input.push_back(tmp);
	}

	sort(input.begin(), input.end());

	while (left < right)
	{
		if (input[left] < 1 && input[left + 1] < 1)
			ret += input[left] * input[left + 1];
		else
			break;

		left += 2;
	}
	
	while (right > 0)
	{
		if (input[right] > 1 && input[right - 1] > 1)
			ret += input[right] * input[right - 1];
		else
			break;

		right -= 2;
	}
	
	while (right >= left)
	{
		ret += input[right];
		right--;
	}

	cout << ret << "\n";

	return 0;
}
*/
