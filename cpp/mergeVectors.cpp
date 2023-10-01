#include<bits/stdc++.h>
using namespace std;
vector<int> merge(vector<int>& a, vector<int>& b){
    int n = a.size();
    int m = b.size();
    vector<int> ans;
    int i = 0, j = 0;
    while(i<n && j<m){
        if(a[i]<b[j]){
            ans.push_back(a[i]);
            i++;
        }else{
            ans.push_back(b[j]);
            j++;
        }
    }
    while(i<n){
        ans.push_back(a[i]);
        i++;
    }
    while(j<m){
        ans.push_back(b[j]);
        j++;
    }
    return ans;
}
 
int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int m;
	cin >> m;
	vector<int> b(m);
	for(int i=0;i<m;i++){
	    cin >> b[i];
	}
	vector<int> ans = merge(a,b);
	for(int i=0;i<ans.size();i++){
	    cout << ans[i] << " ";
	}
	cout << endl;
}
