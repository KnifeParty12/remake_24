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

ll D[MAX];            // Distance array to keep track of shortest possible distance to reach a vertex
int n;                // vertices
vector<PII> adj[MAX]; // pair of {vertex, distance}

void dijkstra()
{
    for (int i = 1; i <= n; i++)
        D[i] = inf;
    D[1] = 0;              // starting point
    set<pair<ll, int>> pq; // distance - vertex
    pq.insert({0, 1});
    map<int, int> check;

    while (!pq.empty())
    {
        int u = pq.begin()->s;
        ll dist = pq.begin()->f;
        pq.erase(pq.begin()); // remove it

        if (D[u] < dist)
            continue; // not the optimal path

        for (PII pr : adj[u])
        {
            int v = pr.first;
            ll next_dist = dist + pr.second;

            if (next_dist < D[v])
            {
                pq.erase({D[v], v}); // erase this entry as we found a better path
                D[v] = next_dist;
                check[v] = u;              // best way to reach v is from u hence store it
                pq.insert({next_dist, v}); // better path
            }
        }
    }

    if (D[n] == inf)
        cout << -1 << endl; // cannot reach it

    // if asked to print the optimal path also
    vector<int> path;
    auto it = check[n];
    path.pb(n);
    while (it != 1)
    {
        path.pb(it);
        it = check[it];
    }
    path.pb(1);
    reverse(path.begin(), path.end());
}

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