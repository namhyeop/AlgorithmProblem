#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define mp(X,Y) make_pair(X,Y)
#define mt(X,Y) make_tuple(X,Y)
#define mtt(X,Y,Z) make_tuple(X,Y,Z)
#define ll long long
#define sz(v) (int)(v).size()

using namespace std;
const int MAX = 1e5 + 1;
vector<int> arr;
int n;

void insert(int num)
{
	arr.push_back(num);
	int current = arr.size() - 1;
	int parent = current / 2;
	while (true)
	{
		if (parent == 0 || arr[parent] <= arr[current])
		{
			break;
		}
		int tmp = arr[parent];
		arr[parent] = arr[current];
		arr[current] = tmp;

		current = parent;
		parent = current / 2;
	}
};

int remove()
{
	if (arr.size() == 1)
	{
		return 0;
	}

	int top = arr[1];
	arr[1] = arr[arr.size() - 1];
	arr.pop_back();

	int currentPos = 1;
	while (true)
	{
		int leftPos = currentPos * 2;
		int rightPos = currentPos * 2 + 1;

		if (leftPos >= arr.size())
		{
			break;
		}

		int minValue = arr[leftPos];
		int minPos = leftPos;

		if (rightPos < arr.size() && minValue > arr[rightPos])
		{
			minValue = arr[rightPos];
			minPos = rightPos;
		}

		if (arr[currentPos] > minValue)
		{
			int tmp = arr[currentPos];
			arr[currentPos] = arr[minPos];
			arr[minPos] = tmp;
			currentPos = minPos;
		}
		else
			break;
	}
	return top;
};

int main(void)
{
	fastio;
	cin >> n;
	arr.push_back(0);
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		if (num == 0)
		{
			cout << remove() << "\n";
		}
		else
		{
			insert(num);
		}
	}
}

/*
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
*/
