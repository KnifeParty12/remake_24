// https://leetcode.com/problems/task-scheduler-ii/

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
    long long taskSchedulerII(vector<int> &tasks, int k)
    {
        int n = tasks.size();
        unordered_map<ll, ll> hash;

        ll timer = 0;
        for (int i = 0; i < n; i++)
        {
            timer++;
            if (!hash.count(tasks[i]))
            {
                // new task found
                hash[tasks[i]] = timer + k + 1;
            }
            else
            { // encountered before
                if (timer >= hash[tasks[i]])
                { // can be picked today
                    hash[tasks[i]] = timer + k + 1;
                }
                else
                { // need to add breaks
                    // breaks = hash[tasks[i]] - timer;
                    timer += hash[tasks[i]] - timer; // add breaks
                    // now I am on the day where I can pick it
                    hash[tasks[i]] = timer + k + 1;
                }
            }
        }
        return timer;
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