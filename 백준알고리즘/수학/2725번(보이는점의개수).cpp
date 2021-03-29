#include<bits/stdc++.h>

using namespace std;
const int MAX = 1001;

int Testcase;
int n;
int cache[MAX];
bool visited[MAX][MAX];

int GCD(int x, int y)
{
	if (y == 0)
		return x;

	return GCD(y, x%y);
}

void search(int cur)
{
	if (cur > 1000)
		return;

	int sum = 0;

	for (int i = 1; i < cur; i++)
	{
		int y = cur;
		int x = i;
		int g = GCD(y, x);
		//기약분수로 만들어준 이후
		x /= g;
		y /= g;
		//기울기에 존재하는 값은 막혀 있으므로 건너뛴다.
		if (visited[y][x])
			continue;
		sum ++;
		visited[y][x] = true;
	}

	//이전값과 추가되는값을 더 해준다. y축 x축이 존재하므로 더 해줘야 하는 값에는 2를 곱셈한다.
	cache[cur] = cache[cur - 1] + 2 * sum;
	search(cur + 1);
}

int main()
{
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); 
	cin.tie(NULL);

	cin >> Testcase;
	cache[1] = 3;
	visited[1][1] = true;

	search(2);

	while (Testcase--)
	{
		cin >> n;
		cout << cache[n] << "\n";
	}

	return 0;

}
