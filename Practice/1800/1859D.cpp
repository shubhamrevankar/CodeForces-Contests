#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool comp(const vector<ll> &a, const vector<ll> &b)
{
    if (a[3] == b[3])
    {
        return a[1] <= b[1];
    }
    return a[3] < b[3];
}

void solve()
{
    ll n;
    cin >> n;
    vector<vector<ll>> v;
    for (ll i = 0; i < n; i++)
    {
        ll l, r, a, b;
        cin >> l >> r >> a >> b;
        v.push_back({l, r, a, b});
    }

    sort(v.begin(), v.end(), comp);

    ll e = v[0][3];

    vector<vector<ll>> a;
    a.push_back(v[0]);

    for (ll i = 1; i < n; i++)
    {
        if (v[i][0] > e)
        {
            a.push_back(v[i]);
            e = v[i][3];
        }
        else
        {
            a.back()[3] = max(a.back()[3], v[i][3]);
            a.back()[1] = max(a.back()[1], v[i][1]);
            a.back()[2] = min(a.back()[2], v[i][2]);
            a.back()[0] = min(a.back()[0], v[i][0]);
            e = a.back()[3];
        }
    }

    n = a.size();

    ll q;
    cin >> q;
    while (q--)
    {
        ll x;
        cin >> x;
        ll i;
        for (i = n - 1; i >= 0; i--)
        {
            if (x >= a[i][0] && x <= a[i][1])
            {
                break;
            }
        }
        if (i >= 0)
            cout << max(x, a[i][3]) << " ";
        else
            cout << x << " ";
    }
    cout << endl;
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

// 1 12 3 8
// 6 17 7 14
// 16 24 20 22

// 1 12 3 8
// 16 24 20 22

// 1 17 3 14
// 16 24 20 22

// for(auto x:a){
//     cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<" "<<x[3]<<endl;
// }

// 10 2 23 15 28 18

// 14 14 23 15 28 22
// 2*14 14 14 14 22 23 14 14 15
// 7 8 7
// 15 14 14 30 24 17 31 4 8
// 21*32 32 21*32 5 8 33 4 32

// 14 14 23 15 28 22 2 * 14 14 14 14 22 23 14 14 15 7 8 7 15 14 14 30 24 17 31 4 8 32 32 32 5 8 33 4 32

// 14 14 23 15 28 22 
// 14 14 14 14 22 23 14 14 15 
// 7 8 7 
// 15 14 14 30 24 17 31 4 8 
// 32 32 32 5 8 33 4 32 