#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>& arr, int low, int mid, int high){
    vector<int> temp(high+1);
    int i = low, j = mid + 1;
    int k = 0;
    while(i<=mid && j<=high){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }else{
            temp[k++] = arr[j++];
        }
    }
    while(i <= mid){
        temp[k++] = arr[i++];
    }
    while(j <= high){
        temp[k++] = arr[j++];
    }
    k--;
    while(k >= 0){
        arr[k+low] = temp[k];
        k--;
    }
}

void mergeSort(vector<int>& arr, int low, int high){
    int mid;
    if(low < high){
        mid = (low + high) / 2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
