#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n;
    cin >> n;
    ll res = (n-2)*(n-1)*(2*n-3);
    res /= 6;
    res += n*(n-1);
    cout<<res<<endl;
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