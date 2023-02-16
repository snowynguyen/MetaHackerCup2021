#include <bits/stdc++.h>
#include <sys/resource.h>
using namespace std;

const int K = 20;

class Solution
{
    public:
    int n;
    vector<vector< int> > g;
    vector<vector< int> > t;
    vector<int> depth,det;
    vector<int> p[K];

    void enter () 
    {
        cin >> n;
        g.assign(n + 1, {});
        t.assign(n + 1, {});
        for (int i=1, u, v; i<n; ++i) 
        {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for (int x,i=1; i<=n; ++i) 
        {
            cin >> x;
            t[x].push_back(i);
        }
    }

    void dfs (int u, int parent) 
    {
        for (int v : g[u]) 
        {
            if (v == parent) 
                continue;
            p[0][v] = u;
            depth[v] = depth[u] + 1;
            
            dfs(v, u);
        }
    }

    int lca (int u, int v) 
    {
        if (depth[u] > depth[v]) 
            swap(u, v);
        for (int k = K - 1; k>=0; --k) 
        {
            if (depth[v] - (1 << k) >= depth[u])
                v = p[k][v];
        }
        if (u == v)
            return u;
        for (int k = K - 1; k>=0; --k) 
        {
            if (p[k][u] != p[k][v]) 
            {
        return 0;
            }
        }
        return p[0][u];
    }

    int res = 0;

    int dfs2(int u, int parent)
    {
        int total = det[u];
        for (int v : g[u]) 
        {
            if (v != parent) 
            {
                total += dfs2(v, u);
            }
        }
        res += total == 0;
        return total;
    }

    int solve() 
    {
        depth.assign(n + 1, 0);
        for (int i=0; i<K; ++i) 
            p[i].assign(n + 1, 0);
        dfs(1, -1);

        for (int k=1; k<K; ++k)
            for (int u=1; u<=n; ++u)
                p[k][u] = p[k-1][p[k-1][u]];

        det.assign(n + 1, 0);

        for (int f=1; f<=n; ++f) 
        {
            if (t[f].size()) 
            {
                int l = t[f][0];
                for (auto x : t[f]) 
                {
                    l = lca(l, x);
                    det[x]++;
                }
                det[l]-=t[f].size();
            }
        }

        res = 0;
        dfs2(1, -1);
        return res-1;
    }


};

int main()
{

    const rlim_t kStackSize = 512 * 1024 * 1024;   // min stack size = 16 MB
    struct rlimit rl;
    int result;

    result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0)
    {
        if (rl.rlim_cur < kStackSize)
        {
            rl.rlim_cur = kStackSize;
            result = setrlimit(RLIMIT_STACK, &rl);
            if (result != 0)
            {
                fprintf(stderr, "setrlimit returned result = %d\n", result);
            }
        }
    }
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