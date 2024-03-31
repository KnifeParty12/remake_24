// https://leetcode.com/problems/snakes-and-ladders

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
    int snakesAndLadders(vector<vector<int>> &board)
    {

        int n = board.size(); // rows

        // hence we got n*n points starting from 1 - n^2

        map<int, int> hash; // check for each point coz input is BS

        int rev_check = 1;
        int counter = 1;

        for (int i = n - 1; i >= 0; i--)
        { // starting from last row
            if (rev_check & 1)
            {
                for (int j = 0; j < n; j++)
                {
                    hash[counter++] = board[i][j];
                }
            }
            else
            {
                for (int j = n - 1; j >= 0; j--)
                {
                    hash[counter++] = board[i][j];
                }
            }
            rev_check++;
        }

        int total = n * n;
        vector<bool> visited(total + 1, false);

        queue<PII> pq;
        pq.push({1, 0});
        int ans;

        while (!pq.empty())
        {
            int curr = pq.front().first;
            int d = pq.front().second;
            pq.pop();
            if (curr == total)
                return d; // BFS always gives shortest path
            for (int i = curr + 1; i <= (curr + 6) && i <= total; i++)
            {
                if (!visited[i])
                {
                    visited[i] = true;
                    int move = hash[i];
                    if (move == -1)
                        pq.push({i, d + 1});
                    else
                        pq.push({move, d + 1});
                }
            }
        }
        return -1;
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