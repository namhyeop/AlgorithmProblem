#include<bits/stdc++.h>
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long

using namespace std;

vector<int> solution(vector<string> cmd) 
{
	vector<int> answer;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	priority_queue<int, vector<int>, less<int>> maxHeap;

	int plusCnt = 0, minusCnt = 0;
	for (int i = 0; i < cmd.size(); i++)
	{
		if (cmd[i][0] == 'I')
		{
			string str = cmd[i].substr(2, cmd.size() - 2);
			minHeap.push(stoi(str));
			maxHeap.push(stoi(str));
			plusCnt++;
		}
		else
		{
			if (plusCnt > 0)
			{
				if (cmd[i][2] == '-')
				{
					minHeap.pop();
					minusCnt++;
				}
				else
				{
					maxHeap.pop();
					minusCnt++;

				}
			}
		}

		if (plusCnt - minusCnt == 0)
		{
			while (!minHeap.empty())
			{
				minHeap.pop();
			}
			while (!maxHeap.empty())
			{
				maxHeap.pop();
			}
		}
	}

	if (plusCnt - minusCnt > 1 )
	{
		answer.push_back(maxHeap.top());
		answer.push_back(minHeap.top());
	}
	else if (plusCnt - minusCnt == 1)
	{
		answer = { minHeap.top(), minHeap.top() };
	}
	else
	{
		answer = { 0, 0 };
	}

	return answer;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	vector<string> cmd = { "I 4", "I 3", "I 2", "I 1", "D 1", "D 1", "D -1", "D -1", "I 5", "I 6" };
	vector<int> ret = solution(cmd);

	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << " ";
}
