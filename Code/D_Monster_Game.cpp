/*
        /\_/\.
       (= ._.)
       / >  \>
._____________________..
|                      |
|   Md_Taminul_Islam   |
|   CSE @ BU           |
|______________________|
*/#include<bits/stdc++.h>
using namespace std;
#define faster() ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define nl cout << "\n"
#define ll long long
void tamin()
{
    int n; cin>>n; 
    vector<int>a(n), b(n); 
    for(int i = 0; i<n; i++) cin>>a[i]; 
    for(int i = 0; i<n; i++) cin>>b[i]; 
    sort(all(a)); 
    int level = 0, strikes = 0; 
    for (int i = 0; i < n; i++)
    {
        level = a[i]; strikes = n-i-1; 
        if(a[i]>strikes) continue;
        else
        {
            pass++; strikes -= a[i]; 
        }
    }
    
}
int main()
{
    faster();
    int t = 1;
    cin >> t;
    while (t--)
        tamin();

    return 0;
}