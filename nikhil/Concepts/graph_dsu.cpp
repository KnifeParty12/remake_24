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

class disjointSet
{

public:
    vector<int> parent, rank, cnt, minimum, maximum; // parent, rank of a
    int cnt_cmp;                                     // total components

    disjointSet(int n)
    { // n vertices starting from 1 to n
        parent.resize(n + 1);
        rank.resize(n + 1);
        cnt.resize(n + 1);
        minimum.resize(n + 1);
        maximum.resize(n + 1);
        cnt_cmp = n;

        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
            rank[i] = 1;
            minimum[i] = i;
            maximum[i] = i;
            cnt[i] = 1;
        }
    }

    int find(int a)
    {
        return a == parent[a] ? a : find(parent[a]);
    }

    bool check(int a, int b)
    {                              // check if part of same component
        return find(a) == find(b); // check for same parent simply
    }

    int getCnt(int a)
    { // to find out number of elements in a component having vertex "a"
        a = parent[a];
        return cnt[a];
    }

    void join(int a, int b)
    {
        a = find(a), b = find(b);
        if (a != b)
        { // not part of same component already, i.e redundant join
            cnt_cmp--;
        }
        if (a == b)
            return;
        if (rank[a] == rank[b])
            rank[a]++; // merge into a
        if (rank[a] > rank[b])
        {
            parent[b] = a;
            minimum[a] = min(minimum[a], minimum[b]);
            maximum[a] = min(maximum[a], maximum[b]);
            cnt[a] += cnt[b];
        }
        else if (rank[b] > rank[a])
        {
            parent[a] = b;
            minimum[b] = min(minimum[a], minimum[b]);
            maximum[b] = min(maximum[a], maximum[b]);
            cnt[b] += cnt[a];
        }
    }
};

void solve()
{
    disjointSet d(5);
    cout << d.find(4) << endl;
    cout << d.check(1, 2) << endl;
    d.join(1, 2);
    cout << d.check(1, 2) << endl;
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