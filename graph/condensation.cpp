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

void dfs1(ll x, vector< vector<ll> >& g, vector< bool >& used, vector< ll >& order){
    used[x] = true;
    for(ll v: g[x]){
        if(!used[v]){
            dfs1(v, g, used, order);
        }
    }
    order.push_back(x);
}

void dfs2(ll x, vector< vector<ll> >& gr, vector< bool >& used, vector< ll >& comp, ll id){
    used[x] = true;
    comp[x] = id;
    for(ll v: gr[x]){
        if(!used[v]){
            dfs2(v, gr, used, comp, id);
        }
    }
}


int main() {
    ll n, m;
    cin >> n >> m;
    vector< vector <ll> > g(n), gr(n);
    vector< bool > used(n, false);
    vector<ll>comps(n), order;
    fi (0, m-1) {
        ll x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        gr[y].push_back(x);
    }
    fi(0, n-1){
        if(!used[i]){
            dfs1(i, g, used, order);
        }
    }
    reverse(all(order));
    fi(0, n-1) used[i] = false;
    ll id = 0;
    for(ll now: order){
        if(!used[now]){
            id++;
            dfs2(now, gr, used, comps, id);
        }
    }
    cout << id << endl;
    cout(comps);
    run();
}