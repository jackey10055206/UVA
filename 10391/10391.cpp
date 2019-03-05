
#include <iostream>
#include <cstring>
#include <set>

using namespace std;

set<string> str;
string s[120000];

int main(int argc, char const *argv[])
{
	int n,a = 0;

	while(scanf("%s" , &s[n]) != EOF)
	{
		
		str.insert(s[n++]);
	}

	for (int i = 0; i < n; ++i)
	{
		int l = s[i].length();

		for (int j = 1; j < l; ++j)
		{
			if ( str.count(s[i].substr(0,j)) && str.count(s[i].substr(j,l-j)))
			{
				cout << s[i] << endl;
				break;
			}
		}
	}



	return 0;
}
