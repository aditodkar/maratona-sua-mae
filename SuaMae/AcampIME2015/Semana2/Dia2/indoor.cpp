#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
inline int count_1s(int x) { return __builtin_popcount(x); }
inline int count_1s(ull x) { return __builtin_popcountll(x); }
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
#ifndef ONLINE_JUDGE
#	define debug(args...) fprintf(stderr, "%3d| ", __LINE__); fprintf(stderr, args); fprintf(stderr, "\n");
#else
#	define debug(args...)
#endif
int n;
ull l;
ull d[20][20];

int solve(int a)


int main() {
	int i, j;
	while(scanf("%d %llu", &n, &l) != EOF) {
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				scanf("%llu", &d[i][j]);
		for(i = 0; i < n; i++)
			if(solve(0, i))
				break;
		if(i == n) puts("impossible");
		else puts("possible");
	}
	return 0;
}