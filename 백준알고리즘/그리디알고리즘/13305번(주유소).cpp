#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;

int main(int argc, char *argv[])
{
	ll N;
	ll minPrice = 1000000000;
	ll allDistance = 0;
	cin >> N;

	vector<ll> distance(N-1);
	vector<ll> price;

	for (ll i = 0; i < N - 1; i++)
	{
		cin >> distance[i];
		allDistance += distance[i];
	}
	
	for (ll i = 0; i < N; i++)
	{
		ll tmp;
		cin >> tmp;
		if (i != N - 1)
		{
			price.push_back(tmp);
			minPrice = min(minPrice, tmp);
		}
	}

	ll ret = 0;

	for (int i = 0; i < N - 1; i++)
	{
		if (price[i] < minPrice)
			minPrice = price[i];
		ret += minPrice * distance[i];
	}

	/*
	반례
	5
	3 2 1 4
	5 8 9 4 1
	출력값 56
	실제값 46

	for (ll i = 0; i < N - 1; i++)
	{
		if (minPrice == price[i])
		{
			ret += allDistance * minPrice;
			break;
		}
		else
		{
			ret += distance[i] * price[i];
			allDistance -= distance[i];
		}
	}*/

	cout << ret << "\n";
	return 0;
}
