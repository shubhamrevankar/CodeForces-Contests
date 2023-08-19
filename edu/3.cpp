#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

const int M = 1e9 + 7;
long long mod(long long x)
{
    return ((x % M + M) % M);
}
long long add(long long a, long long b)
{
    return mod(mod(a) + mod(b));
}
long long mul(long long a, long long b)
{
    return mod(mod(a) * mod(b));
}

void rec(ll i, vector<ll> &a, vector<ll> &temp, ll n, vector<vector<ll>> &v)
{
    if (i == n)
    {
        v.push_back(temp);
        return;
    }
    if (temp.size() == 0 || temp.back() < a[i])
    {
        temp.push_back(a[i]);
        rec(i + 1, a, temp, n, v);
        temp.pop_back();
    }
    rec(i + 1, a, temp, n, v);
}

void solve()
{

    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;

    vector<vector<ll>> v;

    vector<ll> temp;
    rec(0, a, temp, n, v);

    // for (auto x : v)
    // {
    //     for (auto y : x)
    //     {
    //         cout << y << " ";
    //     }
    //     cout << endl;
    // }

    ll size = v.size();
    unordered_set<ll> s;

    for (ll i = 0; i < size; i++)
    {
        if (v[i].size() >= 2)
            s.insert(v[i][1]);
    }

    for (auto x : v)
    {
        ll sz = x.size();
        for (ll i = 0; i < sz; i++)
        {
            if (i != 1 && i != 0)
            {
                if (s.find(x[i]) != s.end())
                {
                    s.erase(x[i]);
                }
            }
        }
    }

    // for (auto x : s)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;

    cout << s.size() << endl;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}