// https://leetcode.com/problems/rectangle-area/

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

class Solution {
public:
    bool isOverlap(int ax1, int ay1, int ax2, int ay2, int bx1, int by1,
                   int bx2, int by2) {
        if (bx1 >= ax2 || bx2 <= ax1 || by2 <= ay1 || by1 >= ay2)
            return false;
        return true;
    }

    ll calcArea(int x1, int x2, int y1, int y2) {
        ll len = x2 - x1, wid = y2 - y1;
        return len * wid;
    }

    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1,
                    int bx2, int by2) {
        ll a1 = calcArea(ax1, ax2, ay1, ay2), a2 = calcArea(bx1, bx2, by1, by2);
        ll overlap_area = 0;
        if (isOverlap(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2)) {
            ll len = min(ax2,bx2) - max(ax1,bx1);
            ll wid = min(ay2,by2) - max(ay1,by1);
            overlap_area = len * wid;
        }                                
        return a1 + a2 - overlap_area;
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