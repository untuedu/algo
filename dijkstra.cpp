/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
int g,v;
const int maxn = 100001;
int n, m, s, t;
vector<pair<int, int>> adj[maxn];
const int INF = 1e9;
int pre[maxn];
void docfile(){
    ifstream fi("input.txt",ios::in);
    fi>>n>>m>>s;
    	for(int i = 0; i < m; i++){
		int x, y, w; fi >> x >> y >> w;
		adj[x].push_back({y, w});
	}
    fi.close();
}
void dijkstra(int s){
    vector<long long> d(n+1,INF);
    d[s]=0;
    priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int,int>>> Q;
	Q.push({0, s});
	while(!Q.empty()){
		pair<int, int> top = Q.top(); Q.pop();
		int u = top.second;
		int kc = top.first;
		if(kc > d[u]) continue;
		for(auto it : adj[u]){
			int v = it.first;
			int w = it.second;
			if(d[v] > d[u] + w){
				d[v] = d[u] + w;
				Q.push({d[v], v});
			}
		}
	    
	}
		for(int i = 1; i <= n; i++){
		cout << d[i] << ' ';
	}	
}

void ghifile(){
    ofstream fo("output.txt",ios::out);
    fo<<g<<" "<<v;
    fo.close();
}
int main()
{
    std::cout<<"Hello World";
    docfile();
    dijkstra(s);
    ghifile();
    return 0;
}