// https://leetcode.com/problems/super-egg-drop/description/

#include <bits/stdc++.h>

#define endl "\n"
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define PII pair<int, int>
#define MAX 1000005
#define inf 1000000000000000LL
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

typedef long long ll;

// auto it = [&]() {
// cout<<"Nikhil"
// };
// it();

template <typename T>
string to__string(T x)
{
    ostringstream ss;
    ss << x;
    return ss.str();
}

int fast_expo(ll a, ll b, ll p) // usually p is 10^9 + 7(prime)
{
    if (a == 0)
        return 0;

    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans *= a, ans %= p;
        a *= a, a %= p;
        b /= 2;
    }
    return ans;
}

ll inv(ll a, ll p) // modulo inverse signifies a value "b" such that a*b = 1(mod p)
{
    return fast_expo(a, p - 2, p);
}

/* ll nCk(ll n, ll k, ll p){
    return ((fact[n] * inv(fact[k],p)%p) * inv(fact[n-k],p)) % p;
} */

ll max(ll a, ll b)
{
    if (a >= b)
        return a;
    return b;
}

ll min(ll a, ll b)
{
    if (a >= b)
        return b;
    return a;
}

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

/*----------GLOBAL BOIS--------------- */

int dp[105][10005];

class Solution
{
public:
    int superEggDrop(int k, int n)
    {
        for (int i = 0; i <= k; i++)
        {
            for (int j = 0; j <= n; j++)
                dp[i][j] = 0;
        }

        for (int i = 0; i <= n; i++)
            dp[0][i] = 0, dp[1][i] = i; // need to try every floor

        for (int i = 1; i <= k; i++)
        {
            dp[i][0] = 0;
            dp[i][1] = 1;
        }

        for (int egg = 2; egg <= k; egg++)
        {
            for (int floor = 2; floor <= n; floor++)
            {
                int lo = 1, hi = floor, res = 1e5;
                while (lo <= hi)
                {
                    int mid = (lo + hi) >> 1;
                    int left =
                        dp[egg - 1][mid - 1];         // if it broke on curr floor
                    int right = dp[egg][floor - mid]; // didnt break
                    int ans = 1 + max(left, right);
                    if (left > right)
                        hi = mid - 1;
                    else
                        lo = mid + 1;
                    res = min(res, ans);
                }
                dp[egg][floor] = res;
            }
        }
        return dp[k][n];
    }
};

void solve()
{
}

int main()
{
    fast_io int tc = 1;

    while (tc--)
    {
        solve();
    }
    return 0;
}