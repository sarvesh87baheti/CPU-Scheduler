#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
#define csort(v) sort(begin(v),end(v))
#define rsort(v) sort(rbegin(v),rend(v))
vector<vector<pair<int,int>>> priority(int n,vector<int>arrival_time,vector<int>burst_time,vector<int>prio){
    vector<pair<pair<int,int>,pair<int,int>>>v;
    vector<vector<pair<int,int>>>ans(n);
    for(int i=0; i<n; i++){
         v.push_back({{arrival_time[i],prio[i]},{burst_time[i],i}});
    }
    csort(v);
    int time;
    multiset<pair<int,pair<int,int>>>curr;
    int j = 0;
    while(j<n || !curr.empty()){
        if(curr.empty()) time = v[j].first.first;
        while(j<n && v[j].first.first<=time) {
            curr.insert({v[j].first.second,v[j].second});
            j++;
        }
        int idx = curr.begin()->second.second;
        curr.erase(curr.begin());
        if(j==n || time+burst_time[idx]<=v[j].first.first){
            ans[idx].push_back({time,burst_time[idx]});
            time+=burst_time[idx];
        }
        else{
            ans[idx].push_back({time,v[j].first.first-time});
            burst_time[idx]-=v[j].first.first-time;
            curr.insert({prio[idx],{burst_time[idx],idx}});
            time=v[j].first.first;
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

     auto it = priority(n,arr,burst,prio);
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