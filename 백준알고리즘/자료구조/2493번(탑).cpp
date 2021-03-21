#include<bits/stdc++.h>

using namespace std;

int N;
int arr[500001];
int main(void)
{
	cin >> N;

	stack<pair<int, int>> s;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < N; i++)
	{
		while (!s.empty() && s.top().first < arr[i])
			s.pop();
		cout << (s.empty() ? 0 : s.top().second) << ' ';
		s.push({ arr[i], i + 1 });
	}
	
}
