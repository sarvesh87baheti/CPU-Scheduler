#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
#define csort(v) sort(begin(v),end(v))
#define rsort(v) sort(rbegin(v),rend(v))

vector<vector<pair<int,int>>> roundr(int n,vector<int>arrival_time,vector<int>burst_time,int tq){
    vector<pair<int,pair<int,int>>>v;
    for(int i=0; i<n; i++){
         v.push_back({arrival_time[i],{burst_time[i],i}});
    }
    csort(v);
    int time = v[0].first;
    vector<vector<pair<int,int>>>ans(n);
    bool done = 0;
    queue<int>q;
    int k = 0;
    int comp = 0;
    while(1) {
        while (k<n && arrival_time[v[k].second.second]<=time) q.push(v[k++].second.second);
        if(comp==n) break;
        if(q.empty()) {
            time = v[k].first;
            continue;
            }
        int curr = q.front();
        if(burst_time[curr]<=tq) {
            comp++;
            ans[curr].push_back({time,burst_time[curr]});
            time+=burst_time[curr];
            burst_time[curr] = 0;
            q.pop();
        }
        else {
            ans[curr].push_back({time,tq});
            time+=tq;
            burst_time[curr]-=tq;
            q.pop();
            q.push(curr);
        }
    }
    return ans;
}

signed main(){
     int n;
     cin>>n;
     vector<int>arr(n);
     vector<int>burst(n);
     vector<int>prio(n);
     for(int i=0; i<n; i++){
          cin>>arr[i];
     }
     for(int i=0; i<n; i++){
          cin>>burst[i];
     }
     for(int i=0; i<n; i++){
          cin>>prio[i];
     }
     auto it = roundr(n,arr,burst,5);
     string output = "";
     int waiting_time = 0;
     int turnar_time = 0;
     int comp_time = accumulate(burst.begin(),burst.end(),0);
     for(int i=0; i<n; i++){
          output+="P"+to_string(i+1)+" : ";
          for(auto &u:it[i]) {
               output+=to_string(u.first)+'-'+to_string(u.first+u.second);
               if(u!=it[i].back()) output+=", ";
          } 
          waiting_time+=it[i].back().second+it[i].back().first-arr[i]-burst[i];
          turnar_time+=it[i].back().second+it[i].back().first-arr[i];
          output+='\n';
     }
     double d1 = waiting_time/(n+0.0);
     double d2 = turnar_time/(n+0.0);
      double d3 = (n+0.0)/comp_time;
     cout<<fixed<<setprecision(5)<<output<<endl<<"Average Waiting Time : "<<d1<<endl<<"Average Turnaround Time : "<<d2<<endl<<"Throughput : "<<d3<<endl<<endl;
}