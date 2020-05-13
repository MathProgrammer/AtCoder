//Question Link https://atcoder.jp/contests/dp/tasks/dp_j
#include <bits/stdc++.h>
#include <cstring>
#include <limits>
//author Bhaskar Joshi
using namespace std;
#define ll long long int
#define X first
#define Y second
#define fw(i, start, end) for (ll i = start; i < end; ++i)
#define fe(i, start, end) for (ll i = start; i <= end; ++i)
#define L(T)  \
    ll T;     \
    cin >> T; \
    while (T--)
#define FASTIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);
#define endl '\n'

double dp[302][302][302];
double ev[302][302][302];

int main()

{
    FASTIO
    ll n;
    cin >> n;
    ll
        a[n + 5];
    int one = 0, two = 0, three = 0;
    fe(i, 1, n)
    {
        cin >> a[i];
        if (a[i] == 1)
            one++;
        if (a[i] == 2)
        {
            two++;
        }
        if (a[i] == 3)
            three++;
    }
    memset(dp, -1, 0);
    // cout << "one  " << one << "  two  " << two << "  three  " << three << endl;
    dp[one][two][three] = 1;
    for (ll k = n; k >= 0; k--)
    {
        for (ll j = n; j >= 0; j--)
        {
            for (ll i = n; i >= 0; i--)
            {
                if (i == 0 && j == 0 && k == 0)
                    continue;
                if (i + j + k > n)
                    continue;
                double pw = (double)(n - (i + j + k)) / n;
                double ew = pw / (1 - pw) + 1;
                ev[i][j][k] += ew * dp[i][j][k];
                if (i != 0)
                {
                    dp[i - 1][j][k] += (double)((double)(dp[i][j][k] * i) / (i + j + k));
                    ev[i - 1][j][k] += (double)((double)(ev[i][j][k] * i) / (i + j + k));
                }
                if (j != 0)
                {
                    dp[i + 1][j - 1][k] += (double)((double)(dp[i][j][k] * j) / (i + j + k));
                    ev[i + 1][j - 1][k] += (double)((double)(ev[i][j][k] * j) / (i + j + k));
                }
                if (k != 0)
                {
                    dp[i][j + 1][k - 1] += (double)((double)(dp[i][j][k] * k) / (i + j + k));
                    ev[i][j + 1][k - 1] += (double)((double)(ev[i][j][k] * k) / (i + j + k));
                }
            }
        }
    }
    double ans = ev[0][0][0];
    // cout << ans << "\n";
    printf("%.10lf\n", ans);
    return 0;
}
