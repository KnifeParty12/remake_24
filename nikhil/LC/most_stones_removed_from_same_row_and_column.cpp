// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/

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
    vector<int> parent;

    int find(int a) { return parent[a] == a ? a : find(parent[a]); }

    void join(int a, int b)
    {
        parent[find(a)] = find(b);
    }

    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        unordered_map<int, vector<int>> rowmap, colmap; // store indexes of stones at row and col
        for (int i = 0; i < n; i++)
        {
            rowmap[stones[i][0]].pb(i);
            colmap[stones[i][1]].pb(i);
        }

        for (int i = 0; i < n; i++)
            parent.pb(i);
        for (int i = 0; i < n; i++)
        {
            for (auto it : rowmap[stones[i][0]])
                join(i, it);
            for (auto it : colmap[stones[i][1]])
                join(i, it);
        }

        unordered_set<int> cnt;
        for (auto it : parent)
            cnt.insert(find(it));

        return n - cnt.size();
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