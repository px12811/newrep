#include<stdio.h>
void Bin_Sea(int arr[],int &n,int temp);
int main(){
	int k,j=1,i,N,arr[100001],temp;
	scanf("%d",&N);
	scanf("%d",&arr[0]);
	for(i=0;i<N-1;i++){
		scanf("%d",&temp);
		Bin_Sea(arr,j,temp);	
		}
	for(i=0;i<j;i++)
	printf("arr[%d]=%d\n",i,arr[i]);
	printf("%d",j);
}
void Bin_Sea(int arr[],int &n,int temp){
	int l=0,r=n-1,m;
	while(l<r){
		m=(r+l)/2;
		if(temp<arr[m])
			r=m;
		else if(temp>arr[m])
			l=m+1;
	}
	if(arr[l]>=temp)
	arr[l]=temp;
	else{
	arr[n]=temp;
		n++;
	}	
}
