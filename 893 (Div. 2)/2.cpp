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

void solve()
{

    ll n, m, d;
    cin >> n >> m >> d;
    vector<ll> a(m);
    for (auto &x : a)
        cin >> x;

    int total = 0;
    for (int i = 0; i <= m; i++)
    {
        int k1, k2;
        if (i == 0)
            k1 = 1;
        else
            k1 = a[i - 1];
        if (i == m)
            k2 = n + 1;
        else
            k2 = a[i];

        total += ceil(((k2 - k1) * 1.0) / d);
    }

    /////------------------------------------------------

    vector<int> v(m, 0);

    for (int i = 0; i < m; i++)
    {
        int init;
        if (i == 0)
            init = v[i + 1] - 1;
        else if (i == m - 1)
            init = n + 1 - v[i - 1];
        else
            init = v[i + 1] - v[i - 1];

        init = ceil((init * 1.0) / d);

        int se, ft;
        if (i == 0)
            ft = ceil(((v[i] - 1) * 1.0) / d);
        else
            ft = ceil(((v[i] - v[i - 1]) * 1.0) / d);
        if (i == m - 1)
            se = ceil(((n + 1 - v[i]) * 1.0) / d);
        else
            se = ceil(((v[i + 1] - v[i]) * 1.0) / d);
        int fnl = ft + se - 1;
        v[i] = fnl - init;
        // if ((a[i] - a[i - 1]) % d == 1)
        // {
        //     v[i]++;
        // }
    }

    // int count = 0;

    // for (int i = 0; i < m; i++)
    // {
    //     if (v[i] > 0)
    //         count++;
    // }

    int lt = v[0];
    int count = 1;

    for (int i = 1; i < m; ++i)
    {
        if (v[i] == lt)
        {
            count++;
        }
        else if (v[i] > lt)
        {
            lt = v[i];
            count = 1;
        }
    }

    cout << total - lt << " " << count << endl;
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
