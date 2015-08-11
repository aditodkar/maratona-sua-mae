// arrumar
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

const int MAX = 50009;
const int M = 802;
int x[MAX], y[MAX], deg[MAX], n, m;
vector<int> adj[MAX];
bool d;
inline int l(int i) { return i << 1; }
inline int r(int i) { return (i << 1) + 1; }
int tree[(M + 2) << 2][(M + 2) << 2];
int query_y(int x, int i, int y1, int y2, int y3, int y4) {
	if(y2 < y3 || y1 > y4) return 0;
	if(y1 >= y3 && y2 <= y4) { if(d)printf("got (%d, %d) %d\n", x, i, tree[x][i]); return tree[x][i]; }
	int my = (y1 + y2) / 2;
	int a = query_y(x, l(i), y1, my, y3, y4);
	int b = query_y(x, r(i), my + 1, y2, y3, y4);
	return max(a, b);
}
int query_t(int i, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	if(x3 > x2 || x4 < x1) return 0;
	if(x1 >= x3 && x2 <= x4) return query_y(i, 1, y1, y2, y3, y4);
	int mx = (x1 + x2) / 2;
	int a = query_t(l(i), x1, y1, mx, y2, x3, y3, x4, y4);
	int b = query_t(r(i), mx + 1, y1, x2, y2, x3, y3, x4, y4);
	return max(a, b);
}

void set_y(int x, int i, int y1, int y2, int y3, int val) {
	if(y1 == y2) { tree[x][i] = val; if(d)printf("set (%d, %d) %d\n", x, i, tree[x][i]);  return; }
	int my = (y1 + y2) / 2;
	if(y3 <= my) set_y(x, l(i), y1, my, y3, val);
	else set_y(x, r(i), my + 1, y2, y3, val);
	tree[x][i] = max(tree[x][l(i)], tree[x][r(i)]);
}
void set_t(int i, int x1, int y1, int x2, int y2, int x3, int y3, int val) {
	set_y(i, 1, y1, y2, y3, val);
	if(x1 == y1) return;
	int mx = (x1 + x2) / 2;
	if(x3 <= mx) set_t(l(i), x1, y1, mx, y2, x3, y3, val);
	else set_t(r(i), mx + 1, y1, x2, y2, x3, y3, val);
}

int mx;
void solve(int i) {
	int a = query_t(1, 0, 0, M, M, x[i] + 1, y[i] + 1, M, M) + 1;
	printf("%d--- %d\n", i, a);
	mx = max(mx, a);
	int g = query_t(1, 0, 0, M, M, x[i], y[i], x[i], y[i]);
	d = 1;
	if(a > g) set_t(1, 0, 0, M, M, x[i], y[i], a);
	printf("a %d\n", query_t(1, 0, 0, M, M, x[i], y[i], x[i], y[i]));
	d = 0;
	for(int v : adj[i])
		solve(v);
	if(a > g) set_t(1, 0, 0, M, M, x[i], y[i], g);
}

int main() {
	int i, a, b;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++) {
		scanf("%d %d", &x[i], &y[i]);
		x[i] += 401; y[i] += 401;
	}
	for(i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		adj[b].pb(a);
		deg[a]++;
	}
	mx = 0;
	for(i = 0; i < n; i++)
		if(!deg[i])
			solve(i);
	printf("%d\n", mx);
	return 0;
}
