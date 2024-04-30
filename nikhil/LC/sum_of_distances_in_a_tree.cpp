// https://leetcode.com/problems/sum-of-distances-in-tree/

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
    vector<vector<int>> adj;
    vector<int> cnt, res;

    void dfs(int i, int parent = -1)
    {
        for (auto it : adj[i])
        {
            // for all child nodes hence exclude parent
            if (it == parent)
                continue;
            dfs(it, i);
            cnt[i] += cnt[it];
            res[i] += res[it] + cnt[it];
        }
        cnt[i] += 1; // the node itself
    }

    void dfs2(int i, int n, int parent = -1)
    { // considering every node we get to as a root
        for (auto it : adj[i])
        {
            if (it == parent)
                continue;
            res[it] = res[i] - cnt[it] + n - cnt[it];
            dfs2(it, n, i);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {
        adj.resize(n);
        res.resize(n);
        cnt.resize(n);
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(0);
        dfs2(0, n);
        return res;
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