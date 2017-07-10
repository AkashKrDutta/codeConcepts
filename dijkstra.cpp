using namespace std;
#define INF 0x3f3f3f3f

void dijkstra(vector <vector<pair<int,int> > > &vec,vector <int> &dist, int s, int n){
	set <pair<int,int> > setds;
	setds.insert(make_pair(0,s));
	while(!setds.empty()){
		pair<int,int> tmp = *(setds.begin());
		setds.erase(setds.begin());
		int vertex = tmp.second;
		vector <pair <int,int> > :: iterator it;
		for (it=vec[vertex].begin(); it!=vec[vertex].end(); ++it)
		{
			int adjW = (*it).first;
			int adjV = (*it).second;
			if( dist[adjV] > dist[vertex] + adjW )
			{
				if(dist[adjV] != INF)
					setds.erase(setds.find(make_pair(dist[adjV],adjV)));
				dist[adjV] = dist[vertex] + adjW;
				setds.insert(make_pair(dist[adjV],adjV));
			}
		}
	}
}

int main(){
	int q;
	cin>>q;
	while(q--){
		int n,m;
		cin>>n>>m;
		vector<vector<pair<int,int> > > vec (n+1);
		vector<int> dist (n+1,INF);
		for (int i = 0; i < m; ++i)
		{
			int a,b;
			cin>>a>>b;
			vec[a].push_back(make_pair(6,b));
			vec[b].push_back(make_pair(6,a));

		}
		int s;
		cin>>s;
		dist[s]=0;
		dijkstra(vec,dist,s,n);
		for (int i = 1; i <= n; ++i)
		{
			if(dist[i] == INF)
				cout<<"-1";
			else if(dist[i]!=0)
				cout<<dist[i];
			else
				continue;
			cout<<" ";
		}
		cout<<endl;
		vec.clear();
		dist.clear();
	}
}
