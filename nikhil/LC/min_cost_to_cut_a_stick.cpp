// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/

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
    int solve(vector<vector<int>> &cost, int i, int j, vector<int> &cuts)
    {
        if (j - i == 1)
            return 0;
        if (cost[i][j] != -1)
            return cost[i][j];

        int ans = INT_MAX;
        for (int k = i + 1; k < j; k++)
        {
            int res = solve(cost, i, k, cuts) + solve(cost, k, j, cuts) + cuts[j] - cuts[i];
            ans = min(res, ans);
        }
        cost[i][j] = ans;
        return cost[i][j];
    }

    int minCost(int n, vector<int> &cuts)
    {
        vector<int> newCuts = cuts;
        newCuts.pb(0);
        newCuts.pb(n);
        int sz = newCuts.size();
        vector<vector<int>> cost(sz + 1, vector<int>(sz + 1, -1));
        sort(newCuts.begin(), newCuts.end());
        return solve(cost, 0, sz - 1, newCuts);
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