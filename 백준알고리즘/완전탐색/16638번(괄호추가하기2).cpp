#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<cstring>
#include<climits>
#include<map>

using namespace std;

const int MAX = 20;

int n;
int result = INT_MIN;
string s;
map<char, int> priority;
char parenthesis[MAX];

void setPriority(void)
{
	priority['('] = 2;
	priority['*'] = 1;
	priority['+'] = 0;
	priority['-'] = 0;
}
bool isNotParenthesis(int idx)
{
	return(parenthesis[idx] != '(' && parenthesis[idx] != ')');
}

bool isOperand(char c)
{
	return (c >= '0' && c <= '9');
}

int calculate(int a, int b, char op)
{
	switch (op)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	}
}

int calculatePostfix(string temps)
{
	stack<int> postfixStack;

	for (int i = 0; i < temps.size(); i++)
	{
		if (isOperand(temps[i]))
		{
			postfixStack.push(temps[i] - '0');
			continue;
		}

		if (postfixStack.size() >= 2)
		{
			int second = postfixStack.top();
			postfixStack.pop();
			int first = postfixStack.top();
			postfixStack.pop();

			int temp = calculate(first, second, temps[i]);
			postfixStack.push(temp);
		}
	}
	return postfixStack.top();
}

int postfixResult()
{
	string temps;
	stack<char> st;

	for (int i = 0; i < n; i++)
	{
		if (isOperand(s[i]))
		{
			temps += s[i];
		}

		switch (parenthesis[i])
		{
		case '(':
			st.push('(');
			break;

		case ')':
			while (st.empty() == false && st.top() != '(')
			{
				temps += st.top();
				st.pop();
			}
			st.pop();
			break;
		default:
			if (isOperand(s[i]))
			{
				break;
			}

			while (st.empty() == false && priority[st.top()] >= priority[s[i]])
			{
				if (st.top() == '(')
				{
					break;
				}
				temps += st.top();
				st.pop();
			}

			st.push(s[i]);
			break;
		}
	}

	while (st.empty() == false)
	{
		temps += st.top();
		st.pop();
	}

	return calculatePostfix(temps);
}
void func(int idx)
{
	if (idx >= n)
	{
		result = max(result, postfixResult());
			return;
	}

	for (int i = idx; i < n; i += 2)
	{
		if (i >= n - 2)
		{
			func(i + 1);
			continue;
		}

		if (isNotParenthesis(i) && isNotParenthesis(i + 2))
		{
			parenthesis[i] = '(';
			parenthesis[i + 2] = ')';
			func(i + 2);
			parenthesis[i] = ' ';
			parenthesis[i + 2] = ' ';
		}
	}
}
int main(int argc, char *argv[])
{
	cin >> n;
	cin >> s;

	setPriority();

	func(0);

	cout << result << "\n";

	return 0;
}
