#include <iostream>

using namespace std;


int main(int argc, char const *argv[])
{
	int n,height,times;

	cin >> n;

	while(n-- && cin >> height >> times)
	{
		while(times--)
		{
			for (int i = 1; i <= height; ++i)
			{
				for (int j = 0; j < i; ++j)
				{
					cout << i;
				}
				cout << endl;
			}

			for (int i = height - 1 ; i >= 1; --i)
			{
				for (int j = 0; j < i; ++j)
				{
					cout << i;
				}
				cout << endl;
			}

			if(times) cout << endl;
		}
		if(n) cout << endl;
	}
	return 0;
}