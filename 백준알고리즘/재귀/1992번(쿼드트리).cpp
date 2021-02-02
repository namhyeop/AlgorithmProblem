#include<iostream>
#include<string>
using namespace std;

string board[64];
int n;
string ans;
void divide(int startY, int startX, int endY, int endX)
{
	int flag = false;
	int signal = board[startY][startX];
	for (int i = startY; i < endY; i++)
	{
		for (int j = startX; j < endX; j++)
		{
			if (signal != board[i][j])
			{	
				flag = true;
				break;
			}
		}
	}

	if (!flag)
	{
		ans += (char)signal;
		return;
	}

	ans += "(";
	divide(startY, startX, (startY+ endY)/ 2, (startX + endX) / 2); //좌상
	divide(startY, (startX + endX) / 2, (endY + startY) / 2, endX); //우상
	divide((startY + endY) / 2, startX, endY, (startX+endX)/2);
	divide((startY + endY) / 2, (startX + endX) / 2, endY, endX);
	ans += ")";
}
int main(int argc, char*argv[])
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> board[i];

	//ans += '(';
	divide(0, 0, n, n);
	//ans += ')';

	cout << ans << "\n";

	return 0;
}
