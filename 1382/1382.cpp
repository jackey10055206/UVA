#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n, y[1005], on[1005], on2[1005], L[1005];  
struct point {
	int x, y;
};  
int cmp(point a, point b) {
	return a.x < b.x;
}
point p[1005];
int getAns(){  
	int ans = 0;  
	sort(p, p + n, cmp);  
	sort(y, y + n);  
	int m = unique(y, y + n) - y;
	if(m <= 2) return n;  
	for(int a = 0; a < m; a++)          
		for(int b = a + 1; b < m; b++){  
			int miny = y[a], maxy = y[b], k = 0;
			memset(on, 0, sizeof(on));  
			memset(on2, 0, sizeof(on2));  
			memset(L, 0, sizeof(L));  
			for(int i = 0; i < n; i++){         
				if(!i || p[i].x != p[i-1].x){  
					k++;  
					if(k > 1) L[k] = L[k - 1] + on2[k - 1] - on[k - 1]; //on2记录边界,on没记录边界，on2-on就是边界上的点的个数， 加上上一条竖线左侧，就是当前竖线左侧点的个数 
				}  
				if(p[i].y < maxy && p[i].y > miny) on[k]++;  
				if(p[i].y <= maxy && p[i].y >= miny) on2[k]++;  
			}  
			if(k <= 2) return n;  
			int Max = 0;  
			for(int i = 1; i <= k; i++){   
				ans = max(ans, L[i] + on2[i] + Max); 
				Max = max(Max, on[i] - L[i]);  
			}  
		}  
	return ans;  
}  
int main(int argc, char const *argv[]){  
	
	#ifdef DBG
	freopen("1382.in" , "r" , stdin);
	freopen("1382.out", "w" , stdout);
	#endif

	int Case = 1;  
	while(scanf("%d", &n), n){  
		for(int i = 0; i < n; i++){  
			scanf("%d %d", &p[i].x, &p[i].y);  
			y[i] = p[i].y;  
		}  
		printf("Case %d: %d\n", Case++, getAns());  
	}  
	return 0;  
}
