#include "bits/stdc++.h"
using namespace std;

int mod = 1000000007;

int solve(int n, string s) 
{
    int ret = 0 ;
    s = " "  + s;
    int lasti = 0, pr = 0, cm = 0;
    char last = 'F';

    for (int i=1; i<=n; ++i) 
    {
        if (s[i] == 'X') 
        {
            if (last == 'O')
            {
                pr += lasti;
                lasti = i;
            }
            lasti = i;
            last = 'X';
        }
        if (s[i] == 'O') 
        {
            if (last == 'X') 
            {
                pr += lasti;
                lasti = i;
            }
            lasti = i;
            last = 'O';
        }
        cm += pr;
        cm %= mod;
        pr %= mod;
    }
    return cm;
}

int main()
{
    int tests;
    cin >> tests;
    for (int testid = 1; testid <= tests; ++testid) 
    {
        int n; string s; cin >> n >> s;
        cout << "Case #" << testid << ": " << solve(n, s) << '\n';
    }
}