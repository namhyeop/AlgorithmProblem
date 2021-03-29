#include<bits/stdc++.h>

using namespace std;
const int MAX = 1e6 + 1;
vector<int> prime;
bool visited[MAX];

bool isValidNum(int n)
{
	map<int, bool> visited;
	int temp = n;

	while (1)
	{
		int result = 0;
		while (temp)
		{
			result += (temp % 10) * (temp % 10);
			temp /= 10;
		}

		if (result == 1)
			return true;

		if (!visited.count(result))
			visited[result] = true;
		else
			return false;

		temp = result;
	}
}
int main()
{
	int n;
	cin >> n;

	for (int i = 2; i < sqrt(MAX); i++)
	{
		if (!visited[i])
		for (int j = i *i; j < MAX; j+= i)
			visited[j] = true;
	}
	for (int i = 2; i < MAX; i++)
	if (visited[i] == false)
		prime.push_back(i);

	for (int i = 0; i < prime.size(); i++)
	{
		if (prime[i] > n)
			break;
		
		if (isValidNum(prime[i]))
			cout << prime[i] << "\n";
	}
	return 0;
}
