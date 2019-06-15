#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;


int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("10668.in","r",stdin);
	freopen("10668.out","w",stdout);
	#endif

	double L,n,C,R;

	while(cin >> L >> n >> C)
	{
		if (L < 0 && n < 0 && C < 0)
			break;

		double S = (1+n*C)*L;
		double mid,l = 0.0,r = 0.5*L;

		while(r - l > 1e-6)
		{
			mid = (l+r)/2.0;
			R = (4*mid*mid + L*L)/8.0/mid;
			if(2*R*asin(L/R/2.0) < S)
				l = mid;
			else
				r = mid;
		} 


		printf("%.3lf\n", mid);
		
	}
	return 0;
}