#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int n,d,r,temp = 0;
	int morning[100],evening[100];
	int reverse[100];

	while(cin >> n >> d >> r){
		
		if (n == 0 && d == 0 && r == 0)
		{
			break;
		}

		for (int i = 0; i < n; ++i)
		{
			cin >> morning[i];
		}

		for (int i = 0; i < n; ++i)
		{
			cin >> evening[i];
		}

		sort(morning , morning+n);
		sort(evening , evening+n);

		int max = n - 1;

		for (int i = 0; i < n; ++i)
		{
			reverse[max] = evening[i];
			max--;
		}

		for (int i = 0; i < n; ++i)
		{
			if (reverse[i] + morning[i] > d)
			{
				temp = temp + ((reverse[i] + morning[i]) - d);
			}
		}

		cout << temp * r << endl;
		temp = 0;
	}

	return 0;
}