#include<bits/stdc++.h>

using namespace std;
const int MAX = 1e6 * 2;
int N;
int arr[MAX];
int head, tail;
string cmd;

void push(int n)
{
	arr[tail++] = n;
}

void pop()
{
	if (tail - head == 0)
	{
		cout << "-1" << "\n";
		return;
	}
	cout << arr[head++] << "\n";
}

int size()
{
	return tail - head;
}

int empty()
{
	return tail - head == 0 ? 1 : 0 ;
}

int front()
{
	return tail - head == 0 ? -1 : arr[head];
}

int back()
{
	return tail - head == 0 ? -1 : arr[tail -1];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> cmd;

		if (cmd == "push")
		{
			int num;
			cin >> num;
			push(num);
		}
		else if (cmd == "pop")
		{
			pop();
		}
		else if (cmd == "size")
		{
			cout << size() << "\n";
		}
		else if (cmd == "empty")
		{
			cout << empty() << "\n";
		}
		else if (cmd == "front")
		{
			cout << front() << "\n";
		}
		else if (cmd == "back")
		{
			cout << back() << "\n";
		}
	}
}
