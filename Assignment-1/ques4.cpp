#include<iostream>
using namespace std;

int maxCrossingSum(int arr[],int left,int mid,int right){
    int sum=0;
    int sumL=INT_MIN;

    for(int i=mid;i>=left;i--){
        sum+=arr[i];
        if(sum>sumL){
            sumL=sum;
        }
    }

        sum=0;
        int sumR=INT_MIN;
        
        for(int i=mid+1;i<=right;i++){
            sum+=arr[i];
            if(sum>sumR){
                sumR=sum;
            }
            
        }
        return sumL+sumR;
    
}

int maxSubArraySum(int arr[],int left,int right){
    if(left==right){
        return arr[left];
    }
    int mid=left+(right-left)/2;

    return max(max(maxSubArraySum(arr,left,mid),maxSubArraySum(arr,mid+1,right)),maxCrossingSum(arr,left,mid,right));
}

int main(){
    int arr[]={-2,-5,6,-2,-3,1,5,-6};
    int size=sizeof(arr)/sizeof(arr[0]);

    int maxsum=maxSubArraySum(arr,0,size-1);

    cout<<"Maximum Subarray Sum: "<<maxsum<<endl;

    return 0;
}
