#include<bits/stdc++.h>

using namespace std;

#define MAX 10000

vector<int> graph[MAX];

bool visited[MAX];

void dfs(int  s)
{
  if(visited[s])return ;

  for(int i = 0; i < graph[s].size(); ++i)
  {
    int top = graph[s][i];
    if(!visited[top)
    dfs(top);
  }
}

int main()
{

  return 0;
}
