#include <iostream>
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
	#ifdef DBG
	freopen("11538.in" , "r" , stdin);
	freopen("11538.out", "w" ,stdout);
	#endif

    long long a,b;
    while (cin >> a >> b){
        if (!a && !b) break;
        if (a > b) swap(a,b);
        long long ans = a * b * (a-1) + a * b * (b-1);
        ans += 4* (2*(a*(a-1)*(a-2)/6) + (b-a+1)*a*(a-1)/2);
        cout << ans << endl;
    }
    return 0;
}