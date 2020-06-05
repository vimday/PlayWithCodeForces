/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :D.cpp
 * @Created Time:2020-06-05 00:16:15
 * @E-mail      :lwftx@outlook.com
 * @GitHub      :https://github.com/vimday
 */
#include <bits/stdc++.h>
using namespace std;
void debug() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}
int m, n;
vector<vector<int>> g;
vector<set<int>> gs;
vector<pair<int, int>> tg;
vector<int> res;
bool help() {
    res.resize(n + 1);
    sort(tg.begin(), tg.end());
    gs.clear();
    gs.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        int ith = tg[i].second, topic = tg[i].first;
        auto it = gs[ith].begin();
        int pre = 0;
        if (!gs[ith].empty() && *gs[ith].rbegin() >= topic)
            return false;
        while (it != gs[ith].end()) {
            if (*it != pre + 1) {
                //pre = pre + 1;
                break;
            } else {
                pre++;
                it++;
            }
        }
        pre++;
        if (pre != topic)
            return false;
        res[i] = ith;
        //cout << ith << endl;
        for (int nb : g[ith])
            gs[nb].insert(pre);
    }
    return true;
}
int main(int argc, char const *argv[]) {
    debug();
    cin >> n >> m;
    g.clear();
    tg.clear();
    res.clear();
    g.resize(n + 1);
    tg.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        tg[i + 1] = {t, i + 1};
    }
    if (!help())
        cout << -1 << endl;
    else {
        for (int i = 1; i < n; i++)
            cout << res[i] << " ";
        cout << res[n] << endl;
    }

    return 0;
}

#include <stdio.h>

#define N 500000
#define M 500000

int oo[1 + M * 2 + N], oj[1 + M * 2 + N];

int link(int o, int j) {
    static int _ = 1;

    oo[_] = o, oj[_] = j;
    return _++;
}

int main() {
    static int ae[N], af[N + 1], tt[N], qu[N];
    static char used[N + 1];
    int n, m, h, i, j, t, cnt;

    scanf("%d%d", &n, &m);
    for (h = 0; h < m; h++) {
        scanf("%d%d", &i, &j), i--, j--;
        ae[i] = link(ae[i], j);
        ae[j] = link(ae[j], i);
    }
    for (i = 0; i < n; i++) {
        scanf("%d", &t);
        af[t] = link(af[t], i);
    }
    cnt = 0;
    for (t = 1; t <= n; t++) {
        int o;

        for (o = af[t]; o; o = oo[o]) {
            int o_, k;

            i = oj[o];
            tt[i] = t, k = 0;
            qu[cnt++] = i;
            for (o_ = ae[i]; o_; o_ = oo[o_]) {
                int t_;

                j = oj[o_], t_ = tt[j];
                if (t_ == t) {
                    k = -1;
                    break;
                }
                if (t_ && !used[t_])
                    used[t_] = 1, k++;
            }
            if (k != t - 1) {
                printf("-1\n");
                return 0;
            }
            for (o_ = ae[i]; o_; o_ = oo[o_]) {
                int t_;

                j = oj[o_], t_ = tt[j];
                if (t_)
                    used[t_] = 0;
            }
        }
    }
    for (i = 0; i < n; i++)
        printf("%d ", qu[i] + 1);
    printf("\n");
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"
#define sz(x) ((int)x.size())
typedef long long ll;

const int nax = 500005;
vector<int> g[nax];
int t[nax];

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        t[i + 1] = x;
        ans.pb({x, i + 1});
    }
    sort(ans.begin(), ans.end());
    for (int i = 1; i <= n; i++) {
        set<int> s;
        for (auto &k : g[i])
            if (t[k] < t[i])
                s.insert(t[k]);
            else if (t[k] == t[i]) {
                cout << -1 << endl;
                exit(0);
            }
        if (sz(s) == t[i] - 1)
            continue;
        cout << -1 << endl;
        exit(0);
    }
    for (auto &k : ans)
        cout << k.second << " ";
    cout << endl;
}