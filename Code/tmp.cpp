/*
        /\_/\.     
       (= ._.)    
       / >  \>  
._____________________..
|                      |
|   Md_Taminul_Islam   |
|   CSE @ BU           |
|______________________|
*/#include <bits/stdc++.h>
using namespace std;
#define faster() ios::sync_with_stdio(false); cin.tie(nullptr)
#define ll long long
#define yes cout << "YES\n"
#define no  cout << "NO\n"
#define nl  cout << "\n"
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
int mex(vector<int>& v) {
    int n = v.size();
    vector<bool> seen(n + 1, false);

    for (int x : v) {
        if (x >= 0 && x <= n)
            seen[x] = true;
    }

    for (int i = 0; i <= n; i++) {
        if (!seen[i])
            return i;
    }
    return n + 1; // never reached
}

void solve()
{
    
}
int main(){
    faster();
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}