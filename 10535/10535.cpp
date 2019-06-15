#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const double eps = 1e-9;
const double pi = acos(-1.0);
const int N = 1005;

struct state
{
	double t;
	int k;
}s[N*2];

struct point
{
	double x1,x2,y1,y2;
}p[N];

int n,m;
double x,y;

bool cmp(const state& a,const state& b)
{
	if (fabs(a.t - b.t) > eps)
		return a.t < b.t;
	return a.k > b.k;
}

void init()
{
	m = 0;

	for (int i = 0; i < n; ++i)
		cin >> p[i].x1 >> p[i].y1 >> p[i].x2 >> p[i].y2;
	cin >> x >> y;

	for (int i = 0; i < n; ++i)
	{
		double l = atan2(p[i].y1 - y , p[i].x1 - x);
		double r = atan2(p[i].y2 - y , p[i].x2 - x);

		if(l> r)
			swap(r,l);

		if (r - l >= pi)
		{
			s[m].t = -pi; s[m++].k = -1;
			s[m].t = l; s[m++].k = 1;
			l = r; r = pi;
		}

		s[m].t = l; s[m++].k = 1;
		s[m].t = r; s[m++].k = -1;
	}

	sort(s,s+m,cmp);

}


int solve(){
	int ans = 0, c = 0;
	for (int i = 0; i < m; ++i)
	{
		c += s[i].k;
		ans = max(ans,c);
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	#ifdef DBG
	freopen("10535.in","r",stdin);
	freopen("10535.out","w",stdout);
	#endif
	while(scanf("%d" , &n) == 1 && n)
	{
		init();
		cout << solve() << endl;
	}
	return 0;
}
