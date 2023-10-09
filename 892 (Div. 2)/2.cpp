#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    vector<long long> a;
    long long smsm = LLONG_MAX;
    for (long long i = 0; i < n; i++)
    {
        long long m;
        cin >> m;
        long long first, second;
        first = second = LLONG_MAX;
        for (long long j = 0; j < m; j++)
        {
            long long t;
            cin >> t;
            if (t <= first)
            {
                second = first;
                first = t;
            }
            else if (t < second)
                second = t;
        }
        smsm = min(smsm, first);
        a.push_back(second);
    }
    sort(a.begin(), a.end(), greater<long long>());
    long long sum = 0;
    for (long long i = 0; i < n - 1; i++)
    {
        sum += a[i];
    }
    sum += smsm;
    cout << sum << endl;
}

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}