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

int numOfPainters(vector<int> &arr, int n, int k, int target)
{

    int sum = 0, painters = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum >= target)
        {
            painters++;
            sum = arr[i];
        }
    }
    return painters;
}

int painterPartition(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> prefix(n, 0);
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + arr[i];
    int lo = *max_element(arr.begin(), arr.end()); // if we got n painters
    int hi = prefix[n - 1];                        // sum of all floors till now
    int res = -1;

    while (lo <= hi)
    {
        ll mid = (lo + hi) >> 1;
        int painters = numOfPainters(arr, n, k, mid);
        if (painters > k)
            lo = mid + 1, res = mid;
        else
            hi = mid - 1;
    }
    return res;
}

void solve()
{
    vector<int> temp = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << painterPartition(temp, 3) << endl;
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