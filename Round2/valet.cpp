#include <bits/stdc++.h>

using namespace std;


class Solution
{
    public:
    int m, n, k;
    vector<string> a;

    void enter () 
    {
        cin >> m >> n >> k;
        a.assign(m + 2, string(n + 2, '.'));
        string tt;
        for (int i=1; i<=m; ++i) 
        {
            cin >> tt; 
            tt = "." + tt + ".";
            a[i] = tt;
        }
    }

    int solve() 
    {
        int ret = 0;
        for (int i=1; i<=n; ++i)
            ret += a[k][i] == 'X';

        vector<int> c(n + 1, 0); 
        for (int j=0; j<=n; ++j)
        for (int i=1; i<=k; ++i) 
            c[j] += a[i][j] == 'X';
        for (int up = 1; up <= m - (k + 1) + 1+1; ++up)
        {
            int cur = up;
            for (int j=1; j<=n; ++j) 
            {
                c[j] += a[up + k][j] == 'X';
                cur += (c[j] >= k) || (a[up + k][j] == 'X');
            }
            ret = min(ret, cur);
        }

        c = vector<int> (n + 1, 0);
        for (int j=1; j<=n; ++j) 
        for (int i=k; i<=m; ++i) 
            c[j] += a[i][j] == 'X';
        for (int down = k - 1; down >= 0; --down) 
        {
            int cur = k - down;
            for (int j=1; j<=n; ++j) 
            {
                c[j] += a[down][j] == 'X';
                cur += ((a[down][j] == 'X')) || (c[j] >= m - k + 1);
            }
            ret = min(ret, cur);
        }
        return ret;
    }


};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    for (int t = 1; t <= tt; ++t)
    {
        Solution sol;
        sol.enter();
        cout << "Case #" << t << ": " << sol.solve() << '\n';
    }
}