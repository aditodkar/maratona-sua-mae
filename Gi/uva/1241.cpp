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
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }

int main(){
	int t;
	while(scanf("%d", &t) != EOF){
		while(t--){
			ull resp = 0;
			int f; scanf("%d", &f);
			while(f--){
				int a, n, p;
				scanf("%d %d %d", &a, &n, &p);
				resp += a*p;
			}
			printf("%lld\n", resp);
		}

	}
	
	return 0;
}
