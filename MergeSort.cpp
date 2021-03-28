#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
// by changing some thing on the void merge it can help us in other problems(count
// inversions,...)
void merge(ll arr[],ll l,ll m,ll r,ll size){
    ll i=l;
    ll j=m+1;
    ll k=l;
    ll temp[size];
    while(i<=m && j<=r){
        if(arr[i]<=arr[j]){
            temp[k]=arr[i];
            i++;
            k++;
        }
        else{
            temp[k]=arr[j];
            k++;
            j++;
        }
    }
    while(i<=m){
        temp[k]=arr[i];
        k++;
        i++;
    }
    while(j<=r){
        temp[k]=arr[j];
        j++;
        k++;
    }
    for(ll x=l;x<=r;x++){
        arr[x]=temp[x];
    }
}
void mergeSort(ll arr[],ll l,ll r,ll size){
    if(l<r){
        ll m=(l+r)/2;
        mergeSort(arr,l,m,size);
        mergeSort(arr,m+1,r,size);
        merge(arr,l,m,r,size);
    }
}
int main (){
  ios_base::sync_with_stdio (false);
  cin.tie (NULL);
  ll N;
  cin>>N;
  ll arr[N];
  for(ll i=0;i<N;i++){
      cin>>arr[i];
  }
  ll r=N-1,l=0;
  mergeSort(arr,l,r,N);
  for(ll i=0;i<N;i++){
      cout<<arr[i]<<" ";
  }
}
