#include<iostream>
#include<queue>
#include<functional>

using namespace std;

int main(int argc, char *argv[])
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int Testcase;
	cin >> Testcase;

	priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int,int>>> pq;
	for (int i = 0; i < Testcase; i++)
	{
		int cmd;
		cin >> cmd;

		if (cmd == 0 && pq.empty())
			cout << 0 << "\n";
		else if (cmd == 0)
		{
			cout << -pq.top().second << "\n";
			pq.pop();
		}
		else
			pq.push({ -abs(cmd), -cmd });
	}

	return 0;
}
