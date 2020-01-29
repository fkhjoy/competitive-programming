#include <bits/stdc++.h>

using namespace std;


#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d %d", &a, &b)
#define siii(a, b, c) scanf("%d %d %d", &a, &b, &c)

#define sl(a) scanf("%lld", &a)
#define sll(a, b) scanf("%lld %lld", &a, &b)
#define slll(a, b, c) scanf("%lld %lld %lld", &a, &b, &c)

#define outi(a) printf("%d\n", a)
#define outii(a, b) printf("%d %d\n", a, b)
#define outiii(a, b, c) printf("%d %d %d\n", a, b, c)

#define outl(a) printf("%lld\n", a)
#define outll(a, b) printf("%lld %lld\n", a, b)
#define outlll(a, b, c) printf("%lld %lld %lld\n", a, b, c)

#define cel(n, k) ((n-1)/k+1)
#define sets(a) memset(a, -1, sizeof(a))
#define clr(a) memset(a, 0, sizeof(a))

#define fr(i, n) for(ll i=0; i<n;i++)
#define fr1(i, n) for(ll i=1; i<=n;i++)

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(v) v.begin, v.end()

typedef long long ll;

const int N = 1e5+5;

struct node{
    ll ver, cost;

    node(ll v, ll w){
        ver = v;
        cost = w;
    }
};

vector<node> v[N];
ll n, vis[N], dist[N], edges, parent[N], cnt = 0, t;

bool operator <(node a, node b){

    return a.cost>b.cost;
}

void reset(){
    clr(vis);
    sets(parent);
}

void dijkstra(ll source){

    priority_queue<node> q;
    q.push(node(source, 0));

    fr1(i, n)
        dist[i] = 10e15;

    dist[source] =  0;
    vis[source] = 1;

    while(!q.empty()){
        cnt++;
        ll u = q.top().ver;
        q.pop();

        fr(i, v[u].size()){
            ll nd = v[u][i].ver;

            if(dist[u]+v[u][i].cost < dist[u]){
                vis[nd] = 1;
                dist[nd] = dist[u]+v[u][i].cost;
                parent[nd] = u;
                q.push(node(nd, dist[nd]));

            }
        }

    }
}

void print_path(ll nod){
    if(parent[nod] == -1){
        printf("%lld", nod);
    }

    print_path(parent[nod]);
    printf(" %lld", nod);
}

int main(){
    reset();
    ll a, b, w;

    sll(n, edges);

    while(edges--){
        slll(a, b, w);

        v[a].pb(node(b,w));
        v[b].pb(node(a,w));
    }

    dijkstra(1);

    if(parent[n] == -1){
        puts("-1");
        return 0;
    }

    print_path(n);
    puts("");

    return 0;
}
