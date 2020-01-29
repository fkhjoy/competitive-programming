#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5; // total node numbers

typedef long long int ll;
typedef pair<ll, int> pii;
bool marked[MAX];
vector<pii> graph[MAX];

long long prim(int x)
{
  priority_queue<pii, vector<pii>, greater<pii> > Q;
  ll cost;
  ll minimumcost = 0;
  pii p;
  Q.push(make_pair(0,x));

  while(!Q.empty())
  {

    p = Q.top();
    Q.pop();

    cost = p.first;
    x = p.second;
    //checking for cycle
    if(marked[x])continue;

    marked[x] = true;

    minimumcost += cost;

    for(int i = 0; i < graph[x].size(); ++i)
    {
      int node = graph[x][i].second;

      if(!marked[node])Q.push(graph[x][i]);
    }
  }
  return minimumcost;

}

int main()
{
  int nodes, edges, x, y;
  ll weight, minimumcost;

  scanf("%d %d", &nodes, &edges);

  for(int i = 0; i < edges; ++i)
  {

    scanf("%d %d %lld", &x, &y, &weight);
    graph[x].push_back(make_pair(1, y));
    graph[y].push_back(make_pair(1, x));
  }

  minimumcost = prim(1);
  printf("%lld\n",minimumcost);
  return 0;
}
