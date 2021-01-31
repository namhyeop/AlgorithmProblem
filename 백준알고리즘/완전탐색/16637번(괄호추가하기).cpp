#include<iostream>
#include<string>
#include<algorithm>
#include<climits>

using namespace std;
int n;
string s;
int result = INT_MIN;

int calculate(int a, int b, char op)
{
	switch (op)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case'*':
		return a * b;
	}
}
void Function(int idx, int value, int i)
{	
	if (idx >= n)
	{
		result = max(result, value);
		return;
	}
	char op = idx >= 1 ? s[idx - 1] : '+';
	int temp = calculate(value, s[idx] - '0', op);
	Function(idx + 2, temp, i + 1);

	if (idx < n - 2)
	{
		temp = calculate(s[idx] - '0', s[idx + 2] - '0', s[idx + 1]);
		temp = calculate(value, temp, op);
		Function(idx + 4, temp, i + 1);
	}
}
int main(int argc, char *argv[])
{
	cin >> n;
	cin >> s;
	
	Function(0, 0, 1);

	cout << result << "\n";

	return 0;
}
