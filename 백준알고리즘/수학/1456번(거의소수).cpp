#include<bits/stdc++.h>
#define ll long long
using namespace std;
const long long MAX = 1e7 + 1;
bool visited[MAX + 1];
vector<ll> prime;
ll ret;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll a, b;
	cin >> a >> b;
	
	long long sqrt_value = sqrt(MAX - 1);
	for (int i = 2; i <= sqrt_value; i++)
	{
		if (visited[i] == false)
		{
			for (int j = i * i; j < MAX; j += i)
				visited[j] = true;
		}
	}

	for (int i = 2; i < MAX; i++)
	{
		if (!visited[i])
			prime.push_back(i);
	}

	for (int i = 0; i < prime.size(); i++)
	{
		ll num = prime[i];
		while (prime[i] <= b/num)
		{
			if (prime[i] * num >= a)
				ret++;
			num *= prime[i];
		}
	}
	cout << ret << "\n";
	return 0;
}
