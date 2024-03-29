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

vector<bool> visited(10005);

class graph
{
public:
    int v, e;
    vector<int> adj[1005];

    graph(int v, int e)
    {
        this->v = v;
        this->e = e;
        adj->resize(v); // keep in mind important
        adj->clear();
        visited.clear();
        for (int i = 0; i < e; i++)
        {
            int f, s;
            cin >> f >> s; // our links or basically edges
            adj[f].pb(s);
            adj[s].pb(f); // only for a bi-directional graph
        }
    }

    void dfs(int sv)
    {
        visited[sv] = true;
        for (auto it : adj[sv])
        {
            if (!visited[it])
                dfs(it);
        }
    } // this will mark all vertices connnected to sv as a component

    void bfs(int sv)
    {
        queue<int> current_level;
        current_level.push(sv);
        visited[sv] = true;

        while (!current_level.empty())
        {
            int curr = current_level.front();
            current_level.pop();
            for (auto it : adj[curr])
            {
                if (!visited[it])
                {
                    current_level.push(it);
                    visited[it] = true; // mark it
                }
            }
        }
    }

    vector<int> *getPathDfs(int sv, int ev)
    {
        if (sv == ev)
        {
            vector<int> *path = new vector<int>();
            path->push_back(ev);
            return path;
        }
        visited[sv] = true;
        for (auto it : adj[sv])
        {
            if (!visited[it])
            {
                vector<int> *path = getPathDfs(it, ev);
                if (path != NULL)
                {
                    path->pb(sv);
                    return path;
                }
            }
        }
        return NULL;
    }

    void getPathBfs(int sv, int ev)
    {
        queue<int> current_level;
        current_level.push(sv);
        visited[sv] = true;
        bool flag = false;
        map<int, int> parent;

        while (!current_level.empty() && flag)
        {
            int curr = current_level.front();
            current_level.pop();
            for (auto it : adj[curr])
            {
                if (!visited[it])
                {
                    visited[it] = true;
                    parent[it] = curr;
                    current_level.push(it);
                    if (it == ev)
                    { // found it
                        flag = true;
                        break;
                    }
                }
            }
        }
        if (!flag)
            return;
        vector<int> path;
        path.pb(ev);
        auto it = parent[ev];
        while (it != sv)
            path.pb(it), it = parent[it];
        path.pb(sv);
        reverse(path.begin(), path.end()); //  we have our path
    }

    bool hasPath(int sv, int ev)
    {
        if (sv == ev)
            return true;
        visited[sv] = true;
        for (auto it : adj[sv])
        {
            if (!visited[it])
            {
                if (hasPath(it, ev))
                    return true;
            }
        }
        return false;
    }

    bool is_connected()
    {
        visited.clear();
        int cnt = 0;
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                dfs(i);
                cnt++;
            }
        }
        return cnt == 1;
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