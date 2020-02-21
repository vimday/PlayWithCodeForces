#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 2e6 + 10;
struct node {
	int x, y, z, w;
	node() {}
	node(int _x, int _y, int _z, int _w) {
		x = _x, y = _y, z = _z, w = _w;
	}
} p[maxn];
int n, m, q, ans[maxn], fa[maxn << 1], num, tot, a[310][310], id[310][310];
int get(int x) {
	return fa[x] == x ? x : fa[x] = get(fa[x]);
}
void merge(int x, int y) {
	x = get(x), y = get(y);
	if (x != y) {
		fa[x] = y;
		num--;
	}
}
void calc(int x, int y) {
	if (a[x][y] == a[x - 1][y]) merge(id[x][y], id[x - 1][y]);
	if (a[x][y] == a[x + 1][y]) merge(id[x][y], id[x + 1][y]);
	if (a[x][y] == a[x][y - 1]) merge(id[x][y], id[x][y - 1]);
	if (a[x][y] == a[x][y + 1]) merge(id[x][y], id[x][y + 1]);
}
void solve1() {
	for (int i = 1; i <= q; i++) {
		int x = p[i].x, y = p[i].y;
		int z = p[i].z, w = p[i].w;
		if (w == z) continue;
		a[x][y] = z;
		id[x][y] = ++tot;
		fa[tot] = tot;
		num = 1;
		calc(x, y);
		ans[i] += num;
	}
}
void solve2() {
	for (int i = q; i >= 1; i--) {
		int x = p[i].x, y = p[i].y;
		int z = p[i].z, w = p[i].w;
		if (w == z) continue;
		a[x][y] = w;
		id[x][y] = ++tot;
		fa[tot] = tot;
		num = 1;
		calc(x, y);
		ans[i] -= num;
	}
}
int main() {
//	freopen("CF1303F.in", "r", stdin);
	scanf("%d %d %d", &n, &m, &q);
	int x, y, z;
	for (int i = 1; i <= q; i++) {
		scanf("%d %d %d", &x, &y, &z);
		p[i] = node(x, y, z, a[x][y]);
		a[x][y] = z;
	}
	memset(a, -1, sizeof a);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			a[i][j] = 0;
		}
	}
	ans[0] = 1;
	solve1();
	memset(fa, 0, sizeof fa);
	tot = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			id[i][j] = ++tot;
			fa[tot] = tot;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			calc(i, j);
		}
	}
	solve2();
	for (int i = 1; i <= q; i++) {
		ans[i] += ans[i - 1];
		printf("%d\n", ans[i]);
	}
	return 0;
}
