#include<bits/stdc++.h>
using namespace std;

int parent[1000];
int Size[1000];
vector<int>adj[100];
map<int, vector<int> > mp;

void make_set(int v)
{
    parent[v]=v;
    Size[v]=1;
}
int find_set(int v)
{
    if(v==parent[v])
        return v;
    return parent[v]=find_set(parent[v]);
}
void union_set(int a, int b)
{
    a=find_set(a);
    b=find_set(b);
    if(a!=b)
    {
        if(Size[a]<Size[b])
            swap(a,b);
        parent[b]=a;
        Size[a]+=Size[b];
    }
}
int main()
{
    int v,e,a,b;
    cin>>v>>e;
    for(int i=1;i<=v;i++)
        make_set(i);
    while(e--)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        union_set(a,b);
    }

    for(int i=1;i<=v;i++)
        mp[find_set(i)].push_back(i);

    for(auto const &i: mp)
    {
        cout<<i.first<<": ";
        for(auto const &j: i.second)
            cout<<j<<" ";
        cout<<endl;
    }

    cout<<"Number of connected component : "<<mp.size()<<endl;
    return 0;
}
