#include<bits/stdc++.h>
using namespace std;

int binarySearch(int *A, int target,int left,int right){
    int mid = (left+right)/2;
    if(A[mid]==target) return mid;
    else if(A[mid]>target) return binarySearch(A,target,left,mid-1);
    else return binarySearch(A,target,mid+1,right);
}

int main(){
    int arr[11]= {0,5,13,19,22,41,55,68,72,81,98};
    int result = binarySearch(arr,72,0,10);
    cout<<result;
}
 
