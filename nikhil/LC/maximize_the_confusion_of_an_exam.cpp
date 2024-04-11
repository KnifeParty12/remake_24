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
    int maxConsecutiveAnswers(string str, int k)
    {
        int n = str.size();

        int lo = 0, hi = 0, res = 0, moves = k;
        while (hi < n)
        {
            if (str[hi] == 'F')
                hi++;
            else
            {
                if (moves)
                    hi++, moves--, res = max(res, hi - lo);
                else
                {
                    res = max(res, hi - lo);
                    if (str[lo] == 'T')
                        moves++;
                    lo++;
                }
            }
        }

        if (str[hi - 1] == 'F' || moves)
            res = max(res, hi - lo);

        lo = 0, hi = 0, moves = k;
        while (hi < n)
        {
            if (str[hi] == 'T')
                hi++;
            else
            {
                if (moves)
                    hi++, moves--, res = max(res, hi - lo);
                else
                {
                    res = max(res, hi - lo);
                    if (str[lo] == 'F')
                        moves++;
                    lo++;
                }
            }
        }

        if (str[hi - 1] == 'T' || moves)
            res = max(res, hi - lo);

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