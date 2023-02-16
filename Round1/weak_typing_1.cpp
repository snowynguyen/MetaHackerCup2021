#include "bits/stdc++.h"
using namespace std;

int solve(int n, string s) 
{
    int ret = 0 ;
    char p = 'F';
    for (char c : s) 
    {
        if (c == 'F') continue;
        if (c == 'O') 
        {
            if (p == 'X') 
            {
                ++ret;
            }
            p = 'O';
        }
        if (c == 'X') 
        {
            if (p == 'O') 
            {
                ++ret;
            }
            p = 'X';
        }
    }
    return ret;
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