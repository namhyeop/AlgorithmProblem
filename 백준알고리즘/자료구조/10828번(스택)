#include<iostream>
#include<stack>
#include<string>
using namespace std;
//라이브러리 써서 풀면 쉽기는 한데..흠
int main(int argc, char *argv[])
{
	stack<int> st;
	string command;
	int num;
	int Testcase;
	cin >> Testcase;

	for (int i = 0; i < Testcase; i++)
	{
		cin >> command;

		if (command == "push")
		{
			cin >> num;
			st.push(num);
		}
		else if (command == "pop")
		{
			if (st.empty())
				cout << "-1" << endl;
			else
			{
				cout << st.top() << endl;
				st.pop();
			}
		}
		else if (command == "size")
			cout << st.size() << endl;
		else if (command == "empty")
		{
			if (st.empty())
				cout << "1" << endl;
			else
				cout << "0" << endl;
		}
		else
		{
			if (st.empty())
				cout << "-1" << endl;
			else
				cout << st.top() << endl;
		}
	}

	return 0;
}
