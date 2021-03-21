#include<bits/stdc++.h>

using namespace std;
const int MAX = 1e4 * 8;
int N;
long long ret;
int height[MAX];
int main(void)
{
	cin >> N;
	
	stack<int> s;
	for (int i = 0; i < N; i++)
		cin >> height[i];

	for (int i = 0; i < N; i++)
	{
		while (!s.empty() && s.top() <= height[i])
			s.pop();
		
		s.push(height[i]);
		ret += s.size() - 1;
	}
	cout << ret << "\n";

	return 0;
}
