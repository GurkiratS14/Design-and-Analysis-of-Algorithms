#include<iostream>
using namespace std;

int BinarySearch(int arr[],int tar,int st, int end){
    if(st<=end){
        int mid=st+(end-st)/2;

    if(tar>arr[mid]){
        return BinarySearch(arr,tar,mid+1,end);
    }
    else if(tar<arr[mid]){
        return BinarySearch(arr,tar,st,mid-1);
    }
    else{
        return mid;
    }
    }
    return -1;
}

int main(){
    int arr[]={2,5,8,12,16,23,38,56,72,91};
    int targetValue=23;
    int start=0;
    int end=sizeof(arr)/sizeof(arr[0]);
    cout<<"The target value found at index:"<<BinarySearch(arr,targetValue,start,end)<<endl;
}