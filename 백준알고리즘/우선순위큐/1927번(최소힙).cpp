#include<iostream>
#include<queue>
#include<functional>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	priority_queue<int,vector<int>,greater<int>> pq;

	int Testcase;
	cin >> Testcase;

	for (int i = 0; i < Testcase; i++)
	{
		int cmd;
		cin >> cmd;

		if (cmd == 0 && pq.empty())
			cout << "0" << "\n";
		else if (cmd == 0)
		{
			cout << pq.top() << "\n";
			pq.pop();
		}
		else
			pq.push(cmd);
	}
	return 0;
}
