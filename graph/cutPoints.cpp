#include<vector>
#include <string>
#include<algorithm>
#include <iostream>
#include <queue>
#include<set>
#include<stack>
#include<cmath>
#include<math.h>
#include<map>
#include<unordered_map>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> pll;
#define mp make_pair
#define fi(b, c) for(auto i = b; i <= c; i++)
#define fj(b, c) for(auto j = b; j <= c; j++)
#define fk(b, c) for(auto k = b; k <= c; k++)
#define fq(b, c) for(auto q = b; q <= c; q++)
#define fw(b, c) for(auto w = b; w <= c; w++)
#define fim(b, c) for(auto i = b; i >= c; i--)
#define fjm(b, c) for(auto j = b; j >= c; j--)
#define fkm(b, c) for(auto k = b; k >= c; k--)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (ll)(a.size())
#define fs first
#define sd second
#define endl "\n"
#define cin(a) for(ll o = 0; o<a.size(); o++) cin>>a[o];
#define cout(a) for(ll o = 0; o<a.size(); o++) cout<<a[o]<<" ";
const ll inf = 1e9 + 123, llinf = 1e18 + 123;
void xru(){
 setlocale(LC_ALL, "rus");
 /*freopen(".in", "r", stdin);
 freopen(".out", "w", stdout);*/
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 cout.tie(NULL);
}
void run(){
    cout<<endl;
    system("pause");
}

ll timer = 0;
set<ll> ans;
vector< vector<ll> >g;
vector<bool> used;
vector<ll> tin, fup;

void pts(ll v, ll p = -1){
    used[v] = true;
	tin[v] = fup[v] = timer++;
	ll children = 0;
	for (ll i=0; i<g[v].size(); ++i) {
		ll to = g[v][i];
		if (to == p)  continue;
		if (used[to])
			fup[v] = min (fup[v], tin[to]);
		else {
			pts (to, v);
			fup[v] = min (fup[v], fup[to]);
			if (fup[to] >= tin[v] && p != -1)
				ans.insert(v+1);
			++children;
		}
	}
	if (p == -1 && children > 1)
		ans.insert(v+1);
}

int main() {
    ll n, m;
    cin >> n >> m;
    g.resize(n);
    used.resize(n);
    tin.resize(n);
    fup.resize(n);
    fi(0, m-1){
        ll x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    fi(0, n-1){
        if(!used[i]){
            pts(i);
        }
    }
    cout << ans.size() << endl;
    for(ll x: ans){
        cout << x << endl;
    }
    run();
}