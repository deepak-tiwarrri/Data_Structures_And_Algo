#include<bits/stdc++.h>
using namespace  std;
// void reverseArray(int arr[],int &n){
//    reverse(arr,arr+(n-1));
//    reverse(arr+(n-1),arr+n);
//    reverse(arr,arr+n);
// }
bool cmp(pair<int,string> &a, pair<int,string> &b){
   if(a.first == b.first){
      //freq is equal now sort bases of string
      return a.second < b.second;
   }
   return a.first > b.first;
}
vector<string> frequentWords(vector<string> &words,int k){
   vector<pair<int,string>> strFreqPair;
   vector<string> ansString;
   unordered_map<string,int> freqString;
   for(auto &it:words) freqString[it]++;
   //car->2 bus->1
   //car bus for answer
   for(auto &it:freqString){
      strFreqPair.push_back({it.second,it.first});
   }
   //2->car 1->bus
   sort(strFreqPair.begin(),strFreqPair.end(),cmp);
   for(int i=0;i<k;++i){
      ansString.push_back(strFreqPair[i].second);
   }
   return ansString;
}
int main() {
	int n, k;
	cin >> n;
	vector<string> v(n);
	for ( int i = 0; i < n; i++) cin >> v[i];
	cin >> k;
	vector<string> ans = frequentWords(v, k);
	for ( auto it : ans) {
		cout << it << endl;
	}
}
