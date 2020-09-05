#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool VPS(string input)
{
	string opening = "(";
	string closing = ")";
	stack<char> st;
	for (int i = 0; i < input.size(); i++)
	{
		if (opening.find(input[i]) != -1)
			st.push(input[i]);
		else
		{
			if (st.empty())
				return false;

			st.pop();
		}
	}
	return st.empty();
}

int main(int argc, char*argv[])
{
	int Testcase;
	cin >> Testcase;

	for (int i = 0; i < Testcase; i++)
	{
		string input;
		cin >> input;
		int flag = VPS(input);
		if (flag == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}
