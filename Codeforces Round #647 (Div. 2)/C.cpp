/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :C.cpp
 * @Created Time:2020-06-04 23:27:44
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

long long help(long long n) {
    if (n < 1) return 0;
    if (n == 1) return 1;
    if (n == 2) return 3;
    if (n == 3) return 4;
    long long dp[65];
    memset(dp, 0, sizeof dp);
    //
    dp[1] = 1;
    for (int i = 2; i < 65; i++) {
        long long mx = (1ll << i) - 1;
        if (mx <= n) {
            dp[i] = (dp[i - 1] << 1) + i;
            if (mx == n)
                return dp[i];
        } else {
            return i + dp[i - 1] + help(n - (1ll << (i - 1)));
        }
    }
    return -1;
}
int main(int argc, char const *argv[]) {
    debug();
    int T;
    cin >> T;
    while (T--) {
        long long t;
        cin >> t;
        cout << help(t) << endl;
    }
    return 0;
}
// 0000
// 000100010001
// 001000100010
// 001100110011
// 010001000100
// 010101010101
// 011001100110
// 011101110111
// 100010001000

// 可以发现第一位二进制一直是01变化,所以第一位的贡献是n(第一位二进制是最后一列)可以发现第一位二进制一直是01变化,所以第一位的贡献是n(第一位二进制是最后一列)可以发现第一位二进制一直是01变化,所以第一位的贡献是n(第一位二进制是最后一列)

// 二进制第二位逢2进1,所以只有进1的时候和前面的0不同,贡献就是n/2二进制第二位逢2进1,所以只有进1的时候和前面的0不同,贡献就是n/2二进制第二位逢2进1,所以只有进1的时候和前面的0不同,贡献就是n/2

// 所以推到二进制第i位,贡献是n<<(i−1)所以推到二进制第i位,贡献是n<<(i-1)所以推到二进制第i位,贡献是n<<(i−1)

// 累加即可累加即可累加即可
// ————————————————
// 版权声明：本文为CSDN博主「jziwjxjd」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
// 原文链接：https://blog.csdn.net/jziwjxjd/article/details/106561665

#define pb(x) push_back(x)
typedef long long ll;
const int maxn = 2e5 + 10;
ll n;
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        ll now = n, i = 1, ans = 0;
        while (now) {
            ans += n / i;
            i *= 2;
            now >>= 1;  //看下一位二进制
        }
        cout << ans << endl;
    }
}
