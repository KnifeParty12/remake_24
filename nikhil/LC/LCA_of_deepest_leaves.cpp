
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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution
{
public:
    int height(TreeNode *root)
    {
        if (!root)
            return 0;

        return max(height(root->left), height(root->right)) + 1;
    }

    TreeNode *lcaDeepestLeaves(TreeNode *root)
    {
        // deepest leaf
        if (!root)
            return root;
        int lh = height(root->left);
        int rh = height(root->right);

        if (lh == rh)
            return root;
        return lh > rh ? lcaDeepestLeaves(root->left) : lcaDeepestLeaves(root->right);
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