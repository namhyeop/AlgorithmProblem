#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

double cal(double a, double b, char operate)
{
	double ret = 0.0;
	switch (operate)
	{
	case '+':
		ret = b + a;
		break;
	case '-':
		ret = b - a;
		break;
	case '*':
		ret = b * a;
		break;
	case '/':
		ret = b / a;
		break;
	}
	return ret;
}

int main(int argc, char * argv[])
{
	int TestSize;
	string numerical;
	cin >> TestSize;

	vector<double> tranNum(TestSize, 0);
	stack<double> s;
	//cin.ignore();
	cin >> numerical;
	
	for (int i = 0; i < TestSize; i++)
		cin >> tranNum[i];

	for (int i = 0; i < numerical.size(); i++)
	{
		if ('A' <= numerical[i] && numerical[i] <= 'Z')
		{
			double tmp = tranNum[numerical[i] - 'A'];
			s.push(tmp);
		}
		else
		{
			double a = s.top();
			s.pop();
			double b = s.top();
			s.pop();
			double tmp = cal(a, b, numerical[i]);
			s.push(tmp);
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << s.top() << endl;

	return 0;
}
