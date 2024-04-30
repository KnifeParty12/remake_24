// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/description/

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
    int minOperations(vector<int> &arr)
    {
        int n = arr.size();

        int min_moves = INT_MAX;

        // we can't simply have our end points as pivots
        // any entry within the array can contribute to being left or right

        set<int> st;
        for (int i = 0; i < n; i++)
            st.insert(arr[i]);

        // consider each element as possible left
        // find its right using upper_bound
        // all elements in between them should be in range of [left, right]
        // all the rest, including dups need to be replaced
        // keep in mind in case of set iterators are bi-directional hence cannot
        // do it - st.begin()

        vector<int> temp;
        for (auto it : st)
            temp.pb(it);

        for (int i = 0; i < temp.size(); i++)
        {
            int left = temp[i];
            int right = left + n - 1;
            auto j = upper_bound(temp.begin(), temp.end(), right) -
                     temp.begin(); // right_index
            int in_range_count =
                j - i; // elements in ideal range of [left, right]
            int moves = n - in_range_count;
            min_moves = min(moves, min_moves);
        }

        return min_moves;
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