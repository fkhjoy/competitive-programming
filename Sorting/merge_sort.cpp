#include<bits/stdc++.h>

using namespace std;

void merge_sort(int A[], int start, int end)
{

    if(start<end)
    {

        int mid = (start+end)/2;


        merge_sort(A, start, mid);

        merge_sort(A, mid+1, end);

        int p= start, q= mid+1, k=0, sz= end-start+1;

        int arr[sz];


        for(int i= start; i<=end; ++i)
        {
            if(p>mid)arr[k++]= A[q++];

            else if(q>end)arr[k++]= A[p++];

            else if(A[p]>A[q])arr[k++]=  A[q++];

            else arr[k++]= A[p++];


        }
        for(int p=0; p<k; p++)
        {
            A[start++]= arr[p];
        }
    }
   //return ;
}

int main()
{
    int a[]={20, 30, -50, 1, 100, 20, 12, 13};

    merge_sort(a, 0, 7);

    for(int i=0; i<8; ++i)cout<<a[i]<<" ";
    cout<<endl;

    return 0;
}
