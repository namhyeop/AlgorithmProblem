#include<iostream>
#include<string>
using namespace std;

int num[4];

void reset()
{
	for (int i = 0; i < 4; i++)
		num[i] = 0;

}
int main(int argc, char *argv[])
{
	char word =' ';

	while (word != '\n')
	{
		cin.get(word);

		if (word == 'w')
			num[0]++;
		else if (word == '\n')
		{
			if (num[0] == 0)
			{
				cout << "1" << "\n";
				return 0;
			}
			else
			{
				cout << "0" << "\n";
				return 0;
			}
		}
		else
		{
			if (word == 'o')
			{
				num[1]++;
				while (num[0] != num[1])
				{
					cin.get(word);
					if (word != 'o')
					{
						cout << "0" << "\n";
						return 0;
					}
					num[1]++;
				}

				while (num[0] != num[2])
				{
					cin.get(word);
					if (word != 'l')
					{
						cout << "0" << "\n";
						return 0;
					}
					num[2]++;
				}

				while (num[0] != num[3])
				{
					cin.get(word);
					if (word != 'f')
					{
						cout <<"0"<< "\n";
						return 0;
					}
					num[3]++;
				}
				reset();
			}	
			else
			{
				cout << "0" << "\n";
				return 0;
			}
		}
	}
	return 0;
}
