#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("1121.in" , "r" , stdin);
	freopen("1121.out" , "w" , stdout);
	#endif

	int n ,s ;
	while(cin >> n >> s)
	{
		vector<int> sequence;
		for (int i = 0; i < n; ++i)
		{
			int num;
			cin >> num;
			sequence.push_back(num);
		}


		int sum = 0, minlength = n+1, max = 0;

		for (int i = 0; i < n; ++i)
		{
			sum += sequence[i];

			while(sum >= s)
			{
				minlength = min(minlength , i - max + 1);
				sum -= sequence[max];
				++max;
			}
		}

		printf("%d\n", (minlength == n + 1)? 0:minlength);
	}
	return 0;
}