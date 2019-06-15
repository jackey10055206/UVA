#include <cstdio>
#include <iostream>

using namespace std;

int f(int n)
{
	return n == 1?1:f(n/2)+1;
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("11384.in","r",stdin);
	freopen("11384.out","w",stdout);
	#endif

	int n;
	while(cin >> n)
		cout << f(n) << endl;
	return 0;
}