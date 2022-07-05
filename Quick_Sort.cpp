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

//<------------------defines end here--------------------->

ll partition(vll &v, ll start, ll end)
{
    ll pivot = v[start]; // taking the 1st elemnt as pivot
    ll count = 0;
    for (ll i = start + 1; i <= end; i++) // for counting the elements smaller than pivot element
    {
        if (v[i] < pivot)
            count++;
    }
    ll pivotIndex = start + count;
    swap(v[pivotIndex], v[start]); // puting the pivot element in the correct position
    ll i = start, j = end;
    while (i < pivotIndex and j > pivotIndex) // for putting the smaller elements on left and larger elements on right
    {
        while (v[i] < v[pivotIndex]) // while element is smaller
            i++;
        while (v[j] > v[pivotIndex]) // while element is larger
            j--;
        if (i < pivotIndex and j > pivotIndex) // if the element is smaller in right and larger in left
            swap(v[i++], v[j--]);
    }
    return pivotIndex; // return the pivot element's index so that we can dvide the array across that
}
void quickSort(vll &v, ll start, ll end)
{
    if (start < end)
    {
        ll pivot = partition(v, start, end); // for partitioning the array or for dividing the array from pivot element
        quickSort(v, start, pivot - 1);      // sorting the left part
        quickSort(v, pivot + 1, end);        // sorting the right part
    }
}

/*____________________________*workplace*__________________________*/

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
    quickSort(v, 0, n - 1);
    cout << "after QuickSort() -> ";
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
