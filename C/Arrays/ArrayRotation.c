#include<stdio.h>

/*
Array Rotation Approaches:
n-elements
d-elements to rotate.

1. rotate array d times.
2. use temp array of size d.
3. jugglers algo.
4. block swap method. :(
5. Reversal algorithm. * :)
*/

// Function to rotate elements in an array.
// 1. rotate array d times.
void rotate1(int array[],int rotations,int size){

int i,j;

rotations = rotations % size;

for(i=0;i<rotations;i++)
    for(j=0;j<size-1;j++)
        array[j]^=array[j+1]^=array[j]^=array[j+1];

}


//5. Reversal algorithm

void reverse_rotate(int array[], int d, int n){
	int i = d;
	while(i<=n/2-1) {
	array[i]^=array[n-i-1]^=array[i]^=array[n-i-1];
	i++;
	}
	
}

void rotate5(int array[], int d, int n){
	reverse_rotate(array,0,n);
	reverse_rotate(array,0,n-d);
	reverse_rotate(array+n-d,0,d);
}

int main(){

int n = 7, d = 2;
int arr[]={1,2,3,4,5,6,7};
int i;

//rotate1(arr,d,n);
rotate5(arr,d,n);
for(i=0;i<n;i++) printf("%d ",arr[i]);

}
