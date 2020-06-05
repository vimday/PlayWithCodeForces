/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :A.cpp
 * @Created Time:2020-06-04 22:15:42
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
long long help(long long s, long long t) {
    unordered_set<long long> ms;
    queue<long long> q;
    q.push(s);
    int res = 0;
    ms.insert(s);
    while (!q.empty()) {
        int n = q.size();
        while (n--) {
            long long tmp = q.front();
            q.pop();
            if (tmp == t)
                return res;
            if (t / 2 >= tmp && ms.count(tmp * 2) == 0) {
                q.push(tmp * 2);
                ms.insert(tmp * 2);
            }
            if (t / 4 >= tmp && ms.count(tmp * 4) == 0) {
                q.push(tmp * 4);
                ms.insert(tmp * 4);
            }
            if (t / 8 >= tmp && ms.count(tmp * 8) == 0) {
                q.push(tmp * 8);
                ms.insert(tmp * 8);
            }
            if (tmp > t) {
                if (tmp % 2 == 0 && tmp / 2 >= t && ms.count(tmp / 2) == 0) {
                    q.push(tmp / 2);
                    ms.insert(tmp / 2);
                }
                if (tmp % 4 == 0 && tmp / 4 >= t && ms.count(tmp / 4) == 0) {
                    q.push(tmp / 4);
                    ms.insert(tmp / 4);
                }
                if (tmp % 8 == 0 && tmp / 8 >= t && ms.count(tmp / 8) == 0) {
                    q.push(tmp / 8);
                    ms.insert(tmp / 8);
                }
            }
        }
        res++;
    }
    return -1;
}
int main(int argc, char const *argv[]) {
    debug();
    int T;
    cin >> T;
    while (T--) {
        long long s, t;
        cin >> s >> t;
        cout << help(s, t) << endl;
    }
    return 0;
}
