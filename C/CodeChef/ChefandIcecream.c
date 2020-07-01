#include <stdio.h>
#include <stdlib.h>
void checkIfPossible(int arr[],int n){
	int i=1;
	int coins[]={0,0,0};
	for(i=1;i<=n;i++){
		if(arr[i]==5) coins[0]+=1;
		else if(arr[i]==10){
			if(coins[0]==0) break;
			else {
				coins[0]-=1;
				coins[1]+=1;
			}
		}
		else{
			if(coins[0]<2 && coins[1]==0) break;
			else{
			    if(coins[1]>=1) coins[1]-=1;
				else if(coins[0]>=2) coins[0]-=2;
				coins[2]+=1;
			}
		}
		}
	if (i>n)
		printf("YES\n");
	else printf("NO\n");
	}
int main(void) {
	int i,j,test_cases,array_size,**arr;
	
	scanf("%d",&test_cases); 
	
	arr = (int **)malloc(sizeof(int*)*test_cases);
	
	for(i=0;i<test_cases;i++){
		scanf("%d",&array_size);
		arr[i] = (int*)malloc(sizeof(int)*(array_size+1));
		arr[i][0]=array_size;
		for(j=1;j<=array_size;j++) scanf("%d",&arr[i][j]);
	}
	for(i=0;i<test_cases;i++)
	checkIfPossible(arr[i],arr[i][0]);
	return 0;
}
