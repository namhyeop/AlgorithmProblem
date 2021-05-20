#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pill pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 1e6 + 1;
bool visited[MAX];

int Testcase;
int main(void)
{
	fastio;
	cin >> Testcase;

	while (Testcase--)
	{
		int size;
		cin >> size;

		priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> maxHeap;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

		int idx = 0;
		int cycleSize = size;
		while (cycleSize--)
		{
			char c;
			int num;
			cin >> c >> num;

			if (c == 'I')
			{
				minHeap.push({ num, idx });
				maxHeap.push({ num, idx });
				visited[idx] = true;
			}
			else if (c == 'D')
			{
				if (num == 1)
				{
					while (!maxHeap.empty() && !visited[maxHeap.top().second])
						maxHeap.pop();
					if (!maxHeap.empty())
					{
						visited[maxHeap.top().second] = false;
						maxHeap.pop();
					}
				}
				else if (num == -1)
				{
					while (!minHeap.empty() && !visited[minHeap.top().second])
						minHeap.pop();
					if (!minHeap.empty())
					{
						visited[minHeap.top().second] = false;
						minHeap.pop();
					}
				}
			}
			idx++;
		}

		while (!maxHeap.empty() && !visited[maxHeap.top().second])
			maxHeap.pop();
		while (!minHeap.empty() && !visited[minHeap.top().second])
			minHeap.pop();

		if (minHeap.empty() && maxHeap.empty())
			cout << "EMPTY" << "\n";
		else
			cout << maxHeap.top().first << " " << minHeap.top().first << "\n";
	}
}
