#include "bits/stdc++.h"
using namespace std;

#define int long long

#ifdef ONPC
#include "Debug/debug.h"
#else
#define print(...) 42
#endif

void solve_the_problem(int test_case)
{
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int test_cases = 1;
    cin >> test_cases;
    for (int test_case = 1; test_case <= test_cases; test_case++)
    {
        solve_the_problem(test_case);
#ifdef ONPC
        cout << "================================================================" << endln;
        cout << "Execution Time : " << 1.0 * clock() / CLOCKS_PER_SEC << "s";
#endif
    }

    return 0;
}