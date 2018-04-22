#include<bits/stdc++.h>

using namespace std;

std::vector<int> v;

#defien MAX 100000

bool vis[MAX];

int level[MAX];


void bfs(int s)
{
  queue<int> q;

  q.push(s);

  level[s] = 0;

  vis[s] = true;

  while (!q.empty())
  {
    int front = q.front();

    q.pop();

    for(int i = 0; i < v[front].size(); ++i)
    {
      if(v[front][i] == 0)
      {
        level[v[front][i]] =  level[front] + 1;

        q.push(v[front][i]);

        vis[v[front][i]] = true;
      }
    }
  }
}

int  main()
{


    return 0;


}
