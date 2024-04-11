// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/

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

typedef long long ll;

class Solution
{
public:
    bool isValid(vector<int> &arr, int m, int k, int days)
    {
        int bouqets = 0, flowers = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            // need to check if subarrays have a max of days and not more than
            // that
            if (arr[i] <= days)
            {
                flowers++;
                if (flowers == k)
                {
                    bouqets++;
                    flowers = 0;
                }
            }
            else
                flowers = 0;
            if (bouqets == m)
                return true;
        }
        return bouqets == m;
    }

    int minDays(vector<int> &bloomDay, int m, int k)
    {

        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int lo = *min_element(bloomDay.begin(), bloomDay.end());
        int res = -1;

        if ((ll)m * k > bloomDay.size())
            return -1;

        while (lo <= high)
        {
            int mid = lo + (high - lo) / 2;
            if (isValid(bloomDay, m, k, mid))
                res = mid, high = mid - 1;
            else
                lo = mid + 1;
        }
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