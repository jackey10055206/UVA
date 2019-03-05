#include <iostream>
#include <cstdio>

using namespace std;


int main(int argc, char const *argv[])
{
	
	int k,x,y;
	int count = 0;


	while(scanf("%d", &k ) != EOF)
	{
		int a[30010] , b[30010];

		for (int y = k+1; y <= 2*k; ++y)
		{
			if ((k*y)%(y-k) == 0)
			{
				a[count] = (k*y)/(y-k);
				b[count] = y;
				++count;
			}
		}
		for (int i = 0; i < count; ++i)
		{
			printf("1/%d = 1/%d + 1/%d\n",k,a[i],b[i] );
		}
		
		count = 0;
		
	}

	return 0;
}