// https://leetcode.com/problems/remove-boxes/description/?source=submission-ac

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
    int n;

    int solve(vector<int> &boxes, int start, int end, int curr_box_cnt,
              vector<vector<vector<int>>> &dp)
    {
        if (start > end)
            return 0;

        if (dp[start][end][curr_box_cnt] != -1)
            return dp[start][end][curr_box_cnt];

        int start0 = start, curr_box_cnt0 = curr_box_cnt;
        while (start + 1 <= end && boxes[start] == boxes[start + 1])
            start++, curr_box_cnt++;

        int ans =
            (curr_box_cnt + 1) * (curr_box_cnt + 1) +
            solve(boxes, start + 1, end, 0, dp); // including start as well

        for (int k = start + 1; k <= end; k++)
        {
            if (boxes[k] == boxes[start])
            {
                int a1 = solve(boxes, start + 1, k - 1, 0,
                               dp); // portion [2,......,2(k)]
                int a2 = solve(boxes, k, end, curr_box_cnt + 1,
                               dp); // portion [2(k)........end]
                ans = max(ans, a1 + a2);
            }
        }
        return dp[start0][end][curr_box_cnt0] = ans;
    }

    int removeBoxes(vector<int> &boxes)
    {
        n = boxes.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));
        return solve(boxes, 0, n - 1, 0, dp);
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