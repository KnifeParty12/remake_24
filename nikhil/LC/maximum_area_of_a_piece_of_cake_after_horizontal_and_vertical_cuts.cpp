// https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts

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

string yo = "Yes\n";
string no = "No\n";

#define mod 1000000007
typedef long long ll;

class Solution
{
public:
    ll mulmod(ll a, ll b)
    { // similar to fast_expo
        ll res = 0;
        a = a % mod;
        while (b > 0)
        {
            if (b % 2 == 1)
                res = (res + a) % mod;
            a = (a * 2) % mod;
            b /= 2;
        }
        return res % mod;
    }

    int maxArea(int h, int w, vector<int> &horizontalCuts,
                vector<int> &verticalCuts)
    {
        horizontalCuts.push_back(0), horizontalCuts.push_back(h);
        verticalCuts.push_back(0), verticalCuts.push_back(w);

        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        ll res = 0;
        // idea is to keep track of max diff between any 2 consecutive cuts
        // that would ideally give us our maxArea
        ll maxH = 0, maxV = 0;
        for (int i = 1; i < horizontalCuts.size(); i++)
        {
            maxH = max(maxH, (horizontalCuts[i] - horizontalCuts[i - 1]));
        }
        for (int i = 1; i < verticalCuts.size(); i++)
        {
            maxV = max(maxV, (verticalCuts[i] - verticalCuts[i - 1]));
        }

        res = mulmod(maxH, maxV);
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