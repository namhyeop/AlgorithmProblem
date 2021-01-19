#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#define MAX 200001

using namespace std;

int main(int argc, char* argv[])
{
	int n;
	pair<int, int> board[MAX];

	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> board[i].first >> board[i].second;
	
	sort(board, board + n);

	priority_queue<int, vector<int>, greater<int> > pq;
	pq.push(board[0].second);

	for (int i = 1; i < n; ++i)
	{
		if (pq.top() <= board[i].first)
		{
			pq.pop();
			pq.push(board[i].second);
		}
		else
		{
			pq.push(board[i].second);
		}
	}

	cout << pq.size() << endl;

	return 0;
}
