#include <bits/stdc++.h>
using namespace std;

struct tmp{
	bool operator() (pair<string,int> a,pair<string,int> b){
		return strcmp(a.first,b.first)<0;
	}
};

int main(){
	int n;
	cin>>n;
	priority_queue<pair<string,int>,vector<pair<string,int> >,tmp> q;
	
	for(int i=0;i<n;i++){
		pair<string,int> p;
		cin>>p.first;
		cin>>p.second;
		q.push(p);
	}
	
	//±éÀú
	while(!q.empty()){
		cout<<(q.top()).first<<" "<<(q.top()).second<<endl;
		q.pop();
	} 
	
	
}
