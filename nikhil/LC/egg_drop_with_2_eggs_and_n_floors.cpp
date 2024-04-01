// https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors/

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

class Solution
{
public:
    int twoEggDrop(int n)
    {
        // thinking of a dp state of dp[eggs][floors]
        // initial conditions

        vector<vector<int>> dp(3, vector<int>(n + 5));

        for (int i = 1; i <= n; i++)
            dp[1][i] = i; // need to try every floor to be sure

        dp[2][1] = 1; // on first floor

        for (int i = 2; i <= n; i++)
        { // total floors
            int lo = 1, hi = i, res = 1e5;
            while (lo <= hi)
            {
                int mid = (lo + hi) >> 1;
                int left = dp[1][mid - 1];      // broke
                int right = dp[2][i - mid];     // didnt break
                int ans = 1 + max(left, right); // max because we need to understand that only one of
                // left/right would contain the breaking floor, hence whichever does would return the answer
                // min would simply give us the partititon which doesn't contain the answer.
                res = min(ans, res);
                if (left < right)
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
            dp[2][i] = res;
        }
        return dp[2][n];
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