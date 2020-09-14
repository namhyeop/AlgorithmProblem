#include<iostream>
#include<deque>
#include<queue>
#include<string>
using namespace std;

void rev(deque<string> & d)
{
	string temp;
	for (deque<string>::size_type i = 0; i < d.size() / 2; i++)
	{
		temp = d[i];
		d[i] = d[d.size() - i - 1];
		d[d.size() - i - 1] = temp;
	}
}

int main()
{
	int Testcase;
	cin >> Testcase;

	for (int i = 0; i < Testcase; i++)
	{
		string comds;
		int Asize;
		string inputA;
		queue<char> q;
		deque<string> dq;
		cin >> comds;
		cin >> Asize;
		cin >> inputA;
		
		for (int i = 0; i < comds.size(); i++)
			q.push(comds[i]);

		for (int i = 0; i < inputA.size(); i++)
		{
			if (inputA[i] == '[')
			{
				i++;
				string ret ="";
				while (inputA[i] != ',' && inputA[i] != ']')
				{
					ret += inputA[i];
					i++;
				}
				dq.push_back(ret);
			}
			else
			{
				string ret="";
				while (inputA[i] != ',' && inputA[i] != ']')
				{
					ret += inputA[i];
					i++;
				}
				dq.push_back(ret);
			}
		}

		cout << dq.front() << endl;
		if (dq.empty())
		{
			cout << "error" << endl;
			break;
		}

		int error_sign = 0;
		while (!q.empty())
		{
			char command = q.front();
			q.pop();

			if (command == 'D' && dq.empty())
			{
				cout << "error" << endl;
				error_sign = 1;
				break;
			}

			switch (command)
			{
			case 'R':
				rev(dq);
				break;
			case 'D':
				dq.pop_front();
				break;
			}
		}

		if (error_sign != 1)
		cout << "[";

		while (error_sign != 1 && !dq.empty())
		{
			string alpha = dq.front();
			dq.pop_front();
			cout << alpha;
			if (dq.size() != 0)
				cout << ",";
		}
		if (error_sign != 1)
		cout << "]" << endl;
	}

	return 0;
}
