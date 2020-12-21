#include <bits/stdc++.h>

using namespace std;
//기본 출력 잠금 설정 안하면 시간 초과 발생함
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	priority_queue<int> pq;
	
	int Testcase;
	cin >> Testcase;

	for (int i = 0; i < Testcase; i++)
	{
		int cmd;
		cin >> cmd;

		if (pq.empty() && cmd == 0)
			cout << 0 << "\n";
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
