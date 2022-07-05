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

//<------------------defines ends here-------------------->

void merge(vll &v, ll start, ll mid, ll end)
{
    vll left, right;
    ll l1 = mid - start + 1, l2 = end - mid;
    for (ll i = start; i <= mid; i++) // storing the 1st sorted array
        left.pb(v[i]);
    for (ll i = mid + 1; i <= end; i++) // storing the 2nd sorted array
        right.pb(v[i]);
    ll i = 0, j = 0;
    while (i < l1 and j < l2) // merging the 2 sorted array
    {
        if (left[i] < right[j])
            v[start++] = left[i++];
        else
            v[start++] = right[j++];
    }
    while (i < l1) // if 1st sorted array have extra elements
    {
        v[start++] = left[i++];
    }
    while (j < l2) // if 2st sorted array have extra elements
    {
        v[start++] = right[j++];
    }
}
void mergeSort(vll &v, ll start, ll end)
{
    if (start < end)
    {
        ll mid = (start + end) / 2; // dividing the arr in 2 halves from mid
        mergeSort(v, start, mid);   // sorting the first half
        mergeSort(v, mid + 1, end); // sorting the 2nd half
        merge(v, start, mid, end);  // for merging the 2 sorted halves
    }
    return;
}

/*___________________*workplace*_______________________*/

void solve()
{
    ll n, i, a;
    cin >> n;
    vll v;
    for (ll i = 0; i < n; i++)
    {
        cin >> a;
        v.pb(a);
    }
    mergeSort(v, 0, n - 1);
    cout << "mergeSort() -> ";
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
