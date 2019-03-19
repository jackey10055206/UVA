#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[])
{
	char s[1001];
	while(gets(s))
	{
		int i,count = 0 , flag = 0;

		
		for (i = 0; s[i]; i++)
		{
			if ( (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
			{
				flag = 1;
			}

			else
			{
				count += flag;
				flag = 0;
			}
		}

		count += flag;

		cout << count << endl;
	}
	return 0;
}