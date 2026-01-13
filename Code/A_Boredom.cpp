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
#define pb push_back
#define ff first
#define ss second
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
int main(){
    faster();

    ll n; cin>>n; 
    vector<ll>a(n), dp(100005, 0), dp2(100005, 0); 
    for (int i = 0; i < n; i++)
    {
        ll x; cin>>x; 
        dp[x]++; 
    }
    dp2[0] = 0, dp2[1] = dp[1];
    for(int i = 2; i<=100000; i++) dp2[i] = max(dp2[i-1], dp2[i-2]+i*dp[i]); 
    cout<<dp2[100000]<<endl; 
    return 0;
}