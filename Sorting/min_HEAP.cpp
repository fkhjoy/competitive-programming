#include <bits/stdc++.h>
using namespace std;
class minheap
{
private:
  int ara[1000];

  int length;
public:

  minheap(){length = 0;}


    void EnQ(int i)
    {
      ara[++length] = i;
      if(length >= 2)reHeapUp(length);
    }


  void reHeapDown(int i)
  {
      int left, right, smallest;

      while(1)
      {
          left = 2*i;//left index

          right = 2*i + 1;//right index

          smallest = i;

          if(left> length && right>length)break;

          else if(right>length)smallest = left;

          else if(left>length)smallest = right;

          else if(ara[right]< ara[left])smallest = right;

          else smallest = left;

          if(ara[i] <= ara[smallest])break;

          else
          {
              swap(ara[i], ara[smallest]);

              reHeapDown(smallest);
          }

      }
  }

  void reHeapUp(int i)
  {
    int parent = i/2;

    if(parent == 0)return ;

    if(ara[i] < ara[parent])
    {
      swap(ara[i], ara[parent]);

      reHeapUp(parent);

    }
  }

  int DeQ()
  {
    int t;

    if(length == 1)
    {
      t = ara[1];
      length--;
      return t;
    }
    else
    {
      t = ara[1];

     swap(ara[1], ara[length]);

     length--;

     reHeapDown(1);

     return t;
    }
  }

  bool IsEmpty()
  {
      if(length==0)return true;

      return false;
  }

  void print()
  {
      for(int i=1; i<=length; ++i)
      {
          cout<<DeQ()<<endl;
      }

  }

};

int main()
{

  return 0;
}
