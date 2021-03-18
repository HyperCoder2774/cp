#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int main (){
  ios_base::sync_with_stdio (false);
  cin.tie (NULL);
  ll T;
  cin>>T;
  while(T--){
      ll N;
      cin>>N;
      vector<pair<ll,ll>> arr;
      ll tm[N];
      for(ll i=0;i<N;i++){
          ll a,b;
          cin>>a>>b;
          arr.push_back(make_pair(a,b));
      }
      for(ll i=0;i<N;i++){
          cin>>tm[i];
      }
      ll E=tm[0],Dp=arr[0].first,Ar=Dp+E;
      for(ll i=0;i<N-1;i++){
          ll a=arr[i].first;
          ll b=arr[i].second;
          if(b-Ar>=(b-a+1)/2){
              Dp=b;
          }
          else{
              Dp=Ar+(b-a+1)/2;
          }
          Ar=Dp+(arr[i+1].first-b+tm[i+1]);
      }
      cout<<Ar<<"\n";
    //cout.precision(10);
    //cout<<fixed<<Ans<<"\n";
  }
}