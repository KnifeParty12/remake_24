// https://leetcode.com/problems/strange-printer/

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

#define pb push_back
class Solution
{
public:
    int n;

    int solve(string str, int start, int end, vector<vector<int>> &dp)
    {
        if (start == end)
            return 1;
        if (start > end)
            return 0;

        if (dp[start][end] != -1)
            return dp[start][end];
        // cases
        int res = INT_MAX;
        if (str[start] == str[end])
            res = solve(str, start, end - 1, dp);
        else
        {
            res = 1 + solve(str, start, end - 1, dp); // last char diff

            for (int i = start + 1; i < end; i++)
            {
                if (str[i] == str[end])
                    res = min(res, solve(str, start, i - 1, dp) + solve(str, i, end - 1, dp));
            }
        }
        return dp[start][end] = res;
    }

    int strangePrinter(string str)
    {
        string res = "";
        char last = str[0];
        res.pb(last);
        for (int i = 1; i < str.size(); i++)
        { // first compress it
            if (str[i] != last)
            {
                res.pb(str[i]);
                last = str[i];
            }
        }

        n = res.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(res, 0, n - 1, dp);
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