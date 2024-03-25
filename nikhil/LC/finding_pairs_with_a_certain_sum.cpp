// https://leetcode.com/problems/finding-pairs-with-a-certain-sum/description/

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

bool cmp(vector<int> &v1, vector<int> &v2)
{
    return v1[1] < v2[1];
}

bool check(PII &p1, PII &p2)
{
    return p1.f > p2.f;
}


class FindSumPairs {
public:

    vector<ll> v1;
    vector<ll> v2;
    map<ll,ll> mp;
    unordered_map<ll,ll> mp2;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        // nums1 has max 10^3 elements
        // nums2 has max 10^5 elements,  hence better to iterate nums1 right?
        for(int i = 0; i<nums1.size(); i++) {
            v1.pb(nums1[i]);
            mp[nums1[i]]++;
        }

        for(int i = 0; i<nums2.size(); i++) {
            v2.pb(nums2[i]);
            mp2[nums2[i]]++;
        }
        sort(v1.begin(), v1.end());
    }
    
    void add(int index, int val) {
        mp2[v2[index]]--;
        mp2[v2[index] + val]++;
        v2[index] += val;
    }
    
    int count(int tot) {
        ll res = 0;
        for(auto it : mp) {
            if(it.first >= tot) break;
            res += it.second * (mp2[tot - it.first]);
        }
        return res;
    }
};


void solve()
{
    cout<<"Hello"<<endl;
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