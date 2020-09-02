#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

//백스페이스를 입력했다면, '-'가 주어진다. 이때 커서의 바로 앞에 글자가 존재한다면, 그 글자를 지운다.
// 커서의 위치를 움직일 수 있다면, 왼쪽 또는 오른쪽으로 1만큼 움직인다
int main(int argc, char*argv[])
{
	int Testcase;
	cin >> Testcase;

	for (int i = 0; i < Testcase; i++)
	{
		string input;
		cin >> input;

		stack<char> left;
		stack<char> right;

		for (int i = 0; i < input.size(); i++)
		{

			if (input[i] == '<')
			{
				if (left.size() != 0)
				{
					right.push(left.top());
					left.pop();
				}
			}
			else if (input[i] == '>')
			{
				if (right.size() != 0)
				{
					left.push(right.top());
					right.pop();
				}
			}
			else if (input[i] == '-')
			{
				if (left.size() != 0)
					left.pop();
			}
			else
				left.push(input[i]);
		}
		
		while (!right.empty())
		{
			left.push(right.top());
			right.pop();
		}

		string answer;
		while (!left.empty())
		{
			answer += left.top();
			left.pop();
		}
		reverse(answer.begin(), answer.end());
		cout << answer << endl;
	}
	return 0;
}
