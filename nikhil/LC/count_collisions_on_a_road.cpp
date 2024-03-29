// https://leetcode.com/problems/count-collisions-on-a-road/

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
    int countCollisions(string directions)
    {
        int collisions = 0;
        int n = directions.size();
        if (n == 1)
            return 0;
        // Collision logic :
        // RL -> +2 then RL becomes SS
        // RS -> +1 then R becomes S
        // SL -> +1 L becomes S

        // first try to weed off consecutive RL please?

        for (int i = 1; i < n; i++)
        {
            if (directions[i] == 'L' && directions[i - 1] == 'R')
            {
                collisions += 2;
                directions[i] = 'S', directions[i - 1] = 'S';
            }
        }
        // Now all we would have would not have any conscutive "RL"
        // SL & RS will contribute

        int left_count = 0, right_count = 0;
        for (int i = 0; i < n; i++)
        { // right_count
            if (directions[i] == 'R')
            {
                right_count++;
                directions[i] = 'S';
                continue;
            }
            if (directions[i] == 'S')
            {
                collisions += right_count;
                right_count = 0;
            }
        }

        for (int i = n - 1; i >= 0; i--)
        { // left_count
            if (directions[i] == 'L')
            {
                left_count++;
                directions[i] = 'S';
                continue;
            }
            if (directions[i] == 'S')
            {
                collisions += left_count;
                left_count = 0;
            }
        }
        return collisions;
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