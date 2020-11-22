#include<bits/stdc++.h>
//#include<atcoder/all>
using namespace std;
using ll = long long;

int main()
{
	int n;
	cin >> n;
	string s;
	int ans =0;
	cin >> s;
	stack<char> S;
	for(int i = 0;i<n;i++){
		if(s[i]=='f'||s[i]=='o'){
			S.emplace(s[i]);
		}else if(s[i]=='x'){
			if(S.empty())continue;
			char o = S.top();
			S.pop();
			if(S.empty())continue;
			char f = S.top();
			if(f=='f'&&o=='o'){
				S.pop();
				ans += 3;
			}else{
				while(S.size())S.pop();
			}
		}
		else{
			while(S.size())S.pop();
		}
	}
	cout<<n-ans<<endl;
}
