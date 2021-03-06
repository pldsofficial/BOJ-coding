#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[100002],b[100002],tree[400005];

ll init(int node,int st,int ed)
{
    if(st==ed) return tree[node]=b[st];
    return tree[node]=init(node*2,st,(st+ed)/2)+init(node*2+1,(st+ed)/2+1,ed);
}

ll query(int node,int st,int ed,int left,int right)
{
    if(left>ed||right<st) return 0;
    if(left<=st&&ed<=right) return tree[node];
    return query(node*2,st,(st+ed)/2,left,right)+query(node*2+1,(st+ed)/2+1,ed,left,right);
}

void update(int node,int st,int ed,int index,int diff)
{
    if(index>ed||index<st) return;
    tree[node]+=diff;
    if(st==ed) return;
    update(node*2,st,(st+ed)/2,index,diff);
    update(node*2+1,(st+ed)/2+1,ed,index,diff);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=a[i-1]) b[i]=1;
    }
    init(1,1,n);

    while(k--)
    {
        int c,x,y;
        cin>>c>>x>>y;
        if(c==1)
        {
            cout<<query(1,1,n,x+1,y)+1<<"\n";
        }
        else
        {
            ll f1=b[x],f2=b[x+1];

            a[x]=y;

            b[x+1]=(a[x+1]!=a[x]);
            b[x]=(a[x]!=a[x-1]);

            update(1,1,n,x,b[x]-f1);
            update(1,1,n,x+1,b[x+1]-f2);
        }
    }
}

//first solve at 211206
