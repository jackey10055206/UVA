#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

bool prime[32768];

void Prime(){

	memset(prime,true,sizeof(prime));
	prime[0] = false;
	prime[1] = false;

		for (int i = 2; i <= 32768; i++)
		{
			if (prime[i])
			{
				for (int j = i*i; j <= 32768; j = j + i)
				{
					prime[j] = false;
				}
			}
			
		}
}


int main(int argc, char const *argv[])
{
	int input,count;
	int a = 0;

	Prime();

	while(scanf("%d",&input) != EOF)
	{
		if (input == 0)
		{
			break;
		}

		count = 0;

		for (int i = 2; i <= input/2; ++i)
		{
			if (prime[i] == 1 && prime[input-i] == 1)
			{
				++count;
			}
		}
		
		cout << count << endl;

	}



	return 0;
}