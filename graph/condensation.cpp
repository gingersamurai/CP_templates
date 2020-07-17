
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