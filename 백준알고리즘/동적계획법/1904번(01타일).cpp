/*
n-2(00을 붙이는게 가능한 경우)와 n-1(1을 붙이는게 가능한 경우)을 가지고 점화식을 세운다.
n-2뒤에도 1을 붙이면 되는것이냐라는 생각을 가질 수 있는데 이는 중복되는 경우다.
*/
#include<bits/stdc++.h>

using namespace std;
const int MAX = 1e6 + 1;
int n;
int cache[MAX];
int main()
{
	cin >> n;
	
	cache[1] = 1;
	cache[2] = 2;

	for (int i = 3; i <= n; i++)
		cache[i] = (cache[i - 1] + cache[i - 2]) % 15746;

	cout << cache[n] << "\n";
}
