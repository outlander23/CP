#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"

using namespace std;
using namespace __gnu_pbds;

#ifdef ONPC
#include "Debug/debug.h"
#else
#define print(...) 42
#define printarr(...) 42
#endif

#define int long long

void sv(int test_case)
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (n % 2)
    {
        int mx = 1e18;

        for (int i = 0; i < n; i++)
        {
            int res = 1;
            for (int j = 0; j < i; j += 2)
            {
                res = max(res, a[j + 1] - a[j]);
            }

            for (int j = i + 1; j < n; j += 2)
            {
                res = max(res, a[j + 1] - a[j]);
            }
            mx = min(res, mx);
        }

        cout << mx << endl;
    }
    else
    {
        int mx = 0;
        for (int i = 0; i < n - 1; i += 2)
        {
            int curr = a[i + 1] - a[i];
            mx = max(mx, curr);
        }
        cout << mx << endl;
    }
}

signed main()
{

#ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int ts;
    cin >> ts;
    for (int tc = 1; tc <= ts; tc++)
        sv(tc);

    return 0;
}