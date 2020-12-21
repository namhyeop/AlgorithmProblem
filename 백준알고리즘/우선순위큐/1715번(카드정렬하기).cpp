#include<iostream>
#include<queue>
#include<functional>

using namespace std;

int ret = 0;

int main(int argc, char *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int N;
	cin >> N;

	priority_queue <int, vector<int>, greater<int>> pq;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		pq.push(tmp);
	}

	for (int i = 0; i < N - 1; i++)
	{
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();

		int merge = a + b;
		ret += a + b;
		pq.push(merge);
	}

	cout << ret << "\n";
	return 0;
}
