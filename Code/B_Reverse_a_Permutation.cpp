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
#define faster()                 \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define nl cout << "\n"
#define ll long long
void tamin()
{
    int n;
    cin >> n;
    vector<int> a(n), b;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    b = a;
    int l = 0, r = n - 1;
    sort(rall(b));
    for (int i = 0; i < n; i++)
    {
        if (a[i] < b[i])
            l = i;
        break;
    }
    for (int i = 0; i < n; i++)
    {
        if (b[l] == a[i])
            r = i;
    }
    reverse(a.begin() + l, a.begin() + r + 1);
    for (auto x : a)
        cout << x << " ";
    nl;
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