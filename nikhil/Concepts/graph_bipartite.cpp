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

vector<bool> visited(MAX);
vector<int> adj[MAX];
unordered_set<int> color[2];

int v, e;

bool bipartite(int sv)
{
    visited.clear();
    for (int i = 0; i < v; i++)
        visited[i] = false;

    visited[sv] = true;
    color[0].insert(sv); // add to a color of your choice
    vector<int> pq;
    pq.push_back(sv);

    while (!pq.empty())
    {
        int curr = pq.back();
        pq.pop_back();
        int currset = color[0].count(curr) > 0 ? 0 : 1;

        for (auto it : adj[curr])
        {
            if (color[0].count(it) == 0 && color[1].count(it) == 0)
            { // Not colored
                visited[it] = true;
                color[1 - currset].insert(it);
                pq.push_back(it);
            }
            else if (color[currset].count(it) > 0)
                return false;
        }
    }
    return true;
}

void flush()
{
    color[0].clear();
    color[1].clear();
    for (int i = 0; i <= v; i++)
    {
        visited[i] = false;
        adj[i].clear();
    }
}

void solve()
{
    cin >> v >> e;

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        adj[f].pb(s);
        adj[s].pb(f);
    }
    for (int i = 1; i <= v; i++)
        visited[i] = false;

    for (int i = 1; i <= v; i++)
    {
        if (!visited[i] && !bipartite(i)) // to check for disconnected components also
        {
            cout << "NOT BICOLORABLE\n";
            return;
        }
    }

    cout << "BICOLORABLE\n";
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