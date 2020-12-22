#include<iostream>
#include<queue>
#include<functional>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	int k;
	int n;
	cin >> k >> n;

	int arr[100];

	for (int i = 0; i < k; i++)
	{
		int tmp;
		cin >> tmp;
		arr[i] = tmp;
	}

	map<long long, bool> visited;
	priority_queue<long long, vector<long long>, greater<long long>> pq;
	pq.push(1);
	long long maxValue = 0;

	for (int i = 0; i < n; i++)
	{
		long long value = pq.top();
		pq.pop();

		for (int j = 0; j < k; j++)
		{
			long long nextValue = value * arr[j];

			if (pq.size() > n && nextValue > maxValue)
				continue;

			if (!visited.count(nextValue))
			{
				maxValue = max(maxValue, nextValue);
				visited[nextValue] = true;
				pq.push(nextValue);
			}
		}
	}

	cout << pq.top() << "\n";
}
