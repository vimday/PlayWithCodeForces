/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :B.cpp
 * @Created Time:2020-06-04 23:04:17
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
int m[2049];
int cp[2049];
int help() {
    for (int i = 1; i < 1025; i++) {
        memset(cp, 0, sizeof cp);
        int j = 0;
        for (; j < 1025; j++) {
            if (m[j]) {
                if (!m[i ^ j] || cp[i ^ j])
                    break;
            }
            if (m[j] && m[i ^ j] && !cp[i ^ j])
                cp[i ^ j] = 1;
        }
        if (j == 1025)
            return i;
    }
    return -1;
}
int main(int argc, char const *argv[]) {
    debug();
    int T;
    cin >> T;
    while (T--) {
        memset(m, 0, sizeof m);
        int n, t;
        cin >> n;
        while (n--) {
            cin >> t;
            m[t] = 1;
        }
        cout << help() << endl;
    }
    return 0;
}