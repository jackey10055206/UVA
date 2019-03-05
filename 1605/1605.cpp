#include <iostream>
#include <cstdio>

using namespace std;

char letter(int i){
	if (i < 26)
	{
		return 'A' + i;
	}
	else 
		return 'a' + i - 26;

}


int main(int argc, char const *argv[])
{
	int input;

	while(scanf("%d" , &input) != EOF){
		cout << "2 " << input << " " << input << endl;

		for (int i = 0; i < input; ++i)
		{
			for (int j = 0; j < input; ++j)
			{
				cout << letter(i);
			}
			cout << endl;

		}

		cout << endl;

		for (int i = 0; i < input; ++i)
		{
			for (int j = 0; j < input; ++j)
			{
				cout << letter(j);
			}
			cout << endl;
		}
	}


	return 0;
}