// https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/

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
    void solve(vector<int> &jobs, int k, int i, vector<int> &workers_time,
               int &curr_ans)
    {
        if (i == jobs.size())
        {
            int temp = INT_MIN;
            for (auto x : workers_time)
                temp = max(temp, x);

            curr_ans = min(curr_ans, temp);
            return;
        }

        // now current ith job can be taken up by any worker from 0 to k-1
        for (int j = 0; j < k; j++)
        {
            if (workers_time[j] + jobs[i] < curr_ans)
            {
                workers_time[j] += jobs[i]; // picked
                solve(jobs, k, i + 1, workers_time, curr_ans);
                workers_time[j] -= jobs[i]; // backtrack
                if (workers_time[j] == 0)
                    break;
                // as we already calculated for when a worker hasn't picked any task yet, hence to prevent de-dup
            }
        }
    }

    int minimumTimeRequired(vector<int> &jobs, int k)
    {
        vector<int> workers_time(k, 0);
        int res = INT_MAX;
        solve(jobs, k, 0, workers_time, res);
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