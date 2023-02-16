#include <bits/stdc++.h>

using namespace std;


class Solution
{
    public:
    int n, m; 
    vector<int> s;
    vector<vector<int> >p ;

    void enter () 
    {
        cin >> n >> m;
        s.assign(m, 0);
        for (auto &i: s)
            cin >> i;
        p.assign(n, vector<int>(m, 0));
        for (auto &i: p) 
            for (auto &j: i)
                cin >> j;
        sort (s.begin(), s.end());
        for (auto &i: p) 
            sort (i.begin(), i.end());
    }

    int solve() 
    {
        int ret = 0;
        vector<int> common = s, c2 = s;
        for (auto i : p) 
        {
            auto it = set_intersection(common.begin(), common.end(), i.begin(), i.end(), c2.begin());
            common = vector<int> (c2.begin(), it);
        }
        vector<int> current = s;
        for (auto i : p) 
        {
            c2.resize(n);
            auto it = set_difference(i.begin(), i.end(), current.begin(), current.end(), c2.begin());
            current = i;
            ret += it - c2.begin();
        }
        ret -= m - common.size();

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
        int ret = sol.solve();
        cout << "Case #" << t << ": " << ret << endl;
    }
}