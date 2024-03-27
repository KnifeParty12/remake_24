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

int n;
vector<int> seg_tree(MAX);

void build(vector<int> &arr, int start, int end, int tree_index)
{ // tree_index is the index where you will enter the value in the segtree
    // recursive building
    if (start == end)
    {
        seg_tree[tree_index] = arr[start];
        return;
    }
    int mid = (start + end) >> 1;
    build(arr, start, mid, 2 * tree_index);
    build(arr, mid + 1, end, 2 * tree_index + 1);
    seg_tree[tree_index] = seg_tree[2 * tree_index] + seg_tree[2 * tree_index + 1];
}

void update(vector<int> &arr, int start, int end, int tree_index, int update_index, int val)
{
    if (start == end)
    {
        arr[update_index] = val;
        seg_tree[tree_index] = val;
        return;
    }
    int mid = (start + end) >> 1;
    if (update_index > mid)
        update(arr, mid + 1, end, 2 * tree_index + 1, update_index, val);
    else
        update(arr, start, mid, 2 * tree_index, update_index, val);
    seg_tree[tree_index] = seg_tree[2 * tree_index] + seg_tree[2 * tree_index + 1];
}

int query(int start, int end, int tree_index, int q_start, int q_end)
{
    // the range queried is completely outside of our range
    if (q_start > end || q_end < start)
        return 0;
    // our segment tree is completely inside the queried range then we simply return our answer at current tree_index
    if (q_start <= start && q_end >= end)
        return seg_tree[tree_index];

    // our tree is partially outside/inside of the given range
    int mid = (start + end) >> 1;
    int ans1 = query(start, mid, 2 * tree_index, q_start, q_end);
    int ans2 = query(mid + 1, end, 2 * tree_index + 1, q_start, q_end);
    return ans1 + ans2;
}

void solve()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    n = arr.size();
    build(arr, 0, n - 1, 1);
    for (int i = 1; i < 2 * n; i++)
        cout << seg_tree[i] << " ";
    cout << endl;
    update(arr, 0, 8, 1, 2, 10);
    for (auto it : arr)
        cout << it << " ";
    cout << endl;
    for (int i = 1; i < 2 * n; i++)
        cout << seg_tree[i] << " ";
    cout << endl;
    cout << query(0, 8, 1, 4, 6) << endl;
    // each leaf node in the segment tree represents indivdual element of the array
    // 3 types of segement tree range-sum / min-max / range- update LAZY
    // if array indexed from 0...n then seg tree array would be from 0......2n (total 2n+1 elements)
    // but we index our seg_tree starting from (1 to 2n) to prevent multiplication by 0
    // indexing logic actual array elements are leaf node and hence start showing up from index n
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