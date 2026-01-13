/*
._____________________..
|                      |
|   Md_Taminul_Islam   |
|   CSE @ BU           |
|______________________|
*/

#include <bits/stdc++.h>
using namespace std;
#define faster() ios::sync_with_stdio(false); cin.tie(nullptr)
#define ll long long
#define ull unsigned long long
#define ld long double
#define yes cout << "YES\n"
#define no  cout << "NO\n"
#define nl  cout << "\n"
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define ff first
#define ss second
void _print(int x){ cerr << x; }
void _print(ll x){ cerr << x; }
void _print(string x){ cerr << x; }
void _print(char x){ cerr << x; }
void _print(double x){ cerr << x; }
void _print(vector<int> v){ cerr << "[ "; for(auto &i: v) cerr << i << " "; cerr << "]"; }
template<class T1, class T2> void _print(pair<T1,T2> p){ cerr<<"{"<<p.ff<<", "<<p.ss<<"}"; }
ll gcdll(ll a, ll b){ return (b == 0 ? a : gcdll(b, a % b)); }
ll lcmll(ll a, ll b){ return a / gcdll(a, b) * b; }
ll binpow(ll a, ll b){     // a^b 
    ll res = 1;
    while(b){
        if(b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}
ll binpow_mod(ll a, ll b, ll mod){   // (a^b) % mod
    ll res = 1 % mod;
    a %= mod;
    while(b){
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
bool isPrime(ll n){
    if(n < 2) return false;
    for(ll i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}
void solve()
{
    int a, b; 
    cin>>a>>b; 
    cout<<a*b + 1<<endl; 
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
