#include <bits/stdc++.h>
using namespace std;

bool comp(pair<char,int> a,pair<char,int> b){
	return a.second<b.second;
}
int main(){
	ios::sync_with_stdio(0);
	
	int n;
	cout<<"ÇëÊäÈën:";
	cin>>n;
	
	vector<pair<char,int> > v;
		
	for(int i=0;i<n;i++){
		pair<char,int> p;
		cin>>p.first;
		cin>>p.second;
		v.push_back(p);
	}
	
	sort(v.begin(),v.end(),comp);
	
	for(int i=0;i<v.size();i++){
		cout<<v[i].first<<" "<<v[i].second<<endl;
	}
}
