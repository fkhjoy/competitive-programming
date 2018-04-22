#include<bits/stdc++.h>

using namespace std;

#define MAX 10005

typedef long long int ll;

typedef pair<ll, int> pii;

#define inf 1000000000

vector<pii> graph[MAX];

vector<ll> cost(MAX);

bool visited[MAX];

void dijkstra(int s)
{
    cost.assign(MAX, inf);

    priority_queue<pii, vector<pii>, greater<pii> > pq;

    pq.push(make_pair(0,s));

    cost[s] = 0;

    ll v, w;

    while(!pq.empty())
    {

        pii temp = pq.top();

        ll nod = temp.second;

        ll c = temp.first;

        pq.pop();

        visited[nod] = true;

        if(c != cost[nod])continue;

        ll sz = graph[nod].size();

        for(ll i = 0; i < sz; ++i)
        {
             v = graph[nod][i].second;

             w = graph[nod][i].first;

                if(cost[v] > (w+cost[nod]))
                {
                    cost[v] = w + cost[nod];

                    pq.push(make_pair(cost[v], v));

                }

        }

    }

}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
