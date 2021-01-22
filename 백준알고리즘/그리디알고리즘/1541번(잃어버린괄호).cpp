#include<iostream>
#include <string>
using namespace std;

string str;

int operate()
{
	int ret = 0;
	bool flagMinus = false;
	string temp = "";

	for (int i = 0; i <= str.size(); i++)
	{
		//연산자일 경우
		if (str[i] == '+' || str[i] == '-' || str[i] == '\0')
		{
			if (flagMinus)
				ret -= stoi(temp);
			else
				ret += stoi(temp);

			temp = "";
			if (str[i] == '-')
				flagMinus = true;
		}
		else
			temp += str[i];
	}
	return ret;
}
int main(int argc, char * argv[])
{
	cin >> str;

	cout << operate() << "\n";
	
	return 0;
}
