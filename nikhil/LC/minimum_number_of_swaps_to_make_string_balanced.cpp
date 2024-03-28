// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced

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

class Solution {
public:
    int minSwaps(string str) {
        int n = str.size();
        stack<int> st; // keep track of opening braces from end
        for(int i = 0; i<str.size(); i++) {
            if(str[i] == '[') st.push(i);
        }
        int min_swaps = 0;
        int opening_count = 0, closing_count = 0;
        for(int i = 0; i<n; i++) {
            if(str[i] == '[') opening_count++;
            else closing_count++;
            
            // check if imbalance present
            if(closing_count > opening_count) {
                int index_from_end = st.top();
                st.pop();
                min_swaps++;
                swap(str[i], str[index_from_end]);
                closing_count--;
                opening_count++;
            }
        }
        return min_swaps;
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