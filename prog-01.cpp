#include<bits/stdc++.h>
using namespace std;

int n,m;

struct DSU{
    vector<int>parent,sz;

    DSU(int n){
        for(int i=0; i<=n; i++){
            parent.push_back(i);
            sz.push_back(1);
        }
    }

    int getpar(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=getpar(parent[node]);
    }

    void unite(int u, int v){
        int pu=getpar(u);
        int pv=getpar(v);

        if(pu==pv)return;

        if(sz[pu]<sz[pv]){
            parent[pu]=pv;
            sz[pv]+=sz[pu];
        }else{
            parent[pv]=pu;
            sz[pu]+=sz[pv];
        }

    }

    int siz(int n){
        int p=getpar(n);
        return sz[p];
    }

};

void solve(){
    cin>>n>>m;
    DSU dsu(n);

    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        //gf[a].push_back(b);
        dsu.unite(a,b);
    }

    cout<<"////////////\n";

    map<int,vector<int>>mp;
    
    for(int i=0; i<n; i++){
        mp[dsu.getpar(i)].push_back(i);
    }

    map<int,vector<int>>todos;

    for(auto & p : mp){
        for(int i=0; i<p.second.size(); i++){
            todos[p.second.size()].push_back(p.second[i]);
        }
    }

    int ans=0;
    vector<pair<int,int>>connect;

    vector<int>cnt;

    for(auto & p : todos){
        if(cnt.empty()){
            cnt=p.second;
        }else{
            while(!cnt.empty()){
                int u=cnt[cnt.size()-1];
                int v=p.second[p.second.size()-1];
                connect.push_back({u,v});
                cnt.pop_back();
                p.second.pop_back();
            }
            cnt=p.second;
            cout<<cnt.size();
            return;
        }
    }

    cout<<connect.size()<<'\n';

    for(int i=0; i<connect.size(); i++){
        cout<<connect[i].first<<" "<<connect[i].second<<'\n';
    }



}


int main(){
    int t=1;

    while(t--)solve();

    return 0;
}