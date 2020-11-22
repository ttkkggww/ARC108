#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
using ll = long long;

vector<pair<int,int>> vp[100000];
int ans[100000];
int pass[100000];
int n,m;

void dfs(int idx,int par){
	for(auto &i:vp[idx]){
		if(pass[i.first]==1)continue;
		if(i.second==ans[idx]){
			ans[i.first] = (i.second+1)%n;
		}
		else ans[i.first] = i.second;
		pass[i.first]=1;
		dfs(i.first,idx);
	}
}

int main()
{
	cin >> n >> m;
	for(int i = 0;i<n;i++)ans[i]=-1;
	for(int i = 0;i<m;i++){
		int u,v,c;
		cin >>  u >> v >> c;
		u--;v--;c--;
		vp[u].emplace_back(v,c);
		vp[v].emplace_back(u,c);
	}
	ans[0]=vp[0][0].second;
	dfs(0,-1);
	for(int i = 0;i<n;i++){
		cout<<ans[i]+1<<endl;
	}
}
