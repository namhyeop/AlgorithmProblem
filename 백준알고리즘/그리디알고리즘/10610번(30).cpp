#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

bool desc(char a, char b){
	return a > b;
}

int main(int argc, char *argv[])
{
	bool sema = false;
	string input;
	vector<int>v;
	int sum = 0;
	cin >> input;
	
	for (int i = 0; i < input.length(); i++)
	{
		int tmp = input[i] - '0'; //아스키 코드를 응용한 문장려에서 아스키 코드 숫자를 빼서 정수형으로 만드는 일종의 기법
		if (tmp == 0)
			sema = true;
		sum += tmp;
		v.push_back(tmp);
	}

	if (((sum % 3) != 0) || !sema)
	{
		cout << "-1"<<endl;
		return 0;
	}

	sort(v.begin(), v.end(), desc);
	for (int i = 0; i < v.size(); i++)
	cout << v[i];
}
