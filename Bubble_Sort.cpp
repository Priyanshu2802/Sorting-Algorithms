// LordNeo
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<pair<ll, ll>> vp;
typedef map<ll, ll> ml;
typedef unordered_map<ll, ll> uml;
#define pb push_back
#define ff first
#define ss second
const ll inf = INT_MAX;
const ll mod = 1000000007;

//<----------------- defines end here---------------------->

void bubbleSort(vll &v)
{
    ll n = v.size();
    bool flag;
    for (ll i = 0; i < n; i++)
    {
        flag = 1; // for checking at each stage whether the array is sorted or not
        for (ll j = 0; j < n - 1; j++)
        {
            if (v[j] > v[j + 1]) // for putting the largest element in the end
            {
                swap(v[j], v[j + 1]);
                flag = 0;
            }
        }
        if (flag) // if array is sorted and no swapping occurs last time then return
            return;
    }
}

/*___________________*workplace*_______________________*/

void solve()
{
    ll n, i, a;
    cin >> n;
    vll v;
    for (i = 0; i < n; i++)
    {
        cin >> a;
        v.pb(a);
    }
    bubbleSort(v);
    cout << "after bubbleSort() -> ";
    for (i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll test_case = 1;
    // cin >> test_case;
    while (test_case--)
    {
        solve();
    }
    return 0;
}
