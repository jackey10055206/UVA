#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>


using namespace std;

int a[100005];

int solve(int amount , int max){
	int l = 0 , r = amount -1 , count = 0;
	while(l < r)
	{
		if (a[l] + a[r] <= max)
		{
			--r;
			++l;
			
		}
		
		else
		{
			--r;
		}
		
		++count;
	}
	if (l == r)
	{
		++count;
	}
	return count;


}


int main(int argc, char const *argv[])
{
	int times , amount , max;

	cin >> times;

	while(times--){
		
		cin >> amount >> max ;
		
		for (int i = 0; i < amount; ++i)
		{
			cin >> a[i];
		}

	sort(a,a+amount);

	cout << solve(amount , max) << endl;
	}
	return 0;
}