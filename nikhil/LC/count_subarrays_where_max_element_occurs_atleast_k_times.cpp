// https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/

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
    long long countSubarrays(vector<int> &nums, int k)
    {
        ll res = 0;
        int n = nums.size();
        if (k > n)
            return 0;
        int target = *max_element(nums.begin(), nums.end());

        int lo = 0, hi = 0;
        ll curr_count = 0;

        for (int i = 0; i < k; i++)
        {
            if (nums[i] == target)
            {
                curr_count++;
            }
        }
        hi = k - 1;

        while (1)
        {
            if (curr_count > k)
            {
                res += n - hi; // this will include the current sub-array
                if (lo == n - k)
                    break;
                if (nums[lo] == target)
                    curr_count--;
                lo++;
            }
            else if (curr_count == k)
            {
                res += n - hi; // count current and right side
                if (lo == n - k)
                    break;
                else
                {
                    if (nums[lo] == target)
                        curr_count--;
                    lo++;
                    continue;
                }
            }
            else
            {
                // less than k
                if (hi == n - 1)
                    break;
                hi++;
                if (nums[hi] == target)
                    curr_count++;
            }
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