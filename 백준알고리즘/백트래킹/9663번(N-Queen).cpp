#include<iostream>

using namespace std;

int n;
int cnt;

bool visited1[40];
bool visited2[40];
bool visited3[40];

void func(int cur)
{
	if (cur == n)
	{
		cnt++;
		return;
	}

	//cur == y, i == x
	for (int i = 0; i < n; i++)
	{
		if (visited1[i] || visited2[i + cur] || visited3[cur - i + n - 1])
			continue;

		visited1[i] = 1;
		visited2[i + cur] = 1;
		visited3[cur - i + n - 1] = 1;
		func(cur + 1);
		visited1[i] = 0;
		visited2[i + cur] = 0;
		visited3[cur - i + n - 1] = 0;

 }
}
int main(int argc, char *argv[])
{
	cin >> n;
	func(0);

	cout << cnt << "\n";
}
