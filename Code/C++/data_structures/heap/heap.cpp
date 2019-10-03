#include <string>
#include <iostream>

using namespace std;


int arrMin2Max[] ={0,1,2,3,4,5,6,7,8,9,10};
int arrMax2Min[] ={10,9,8,7,6,5,4,3,2,1,0};
int arrRandom[] ={5,1,8,9,2,10,3,7,4,1,0};
int arrSize = sizeof(arrMin2Max) / sizeof(10); // get size of array / /we gonna need to check for tree bounds on parent left and right funcs

void heapify( int arr[] ,int i ,int n){ // array, index, sizeofarray
	int largest = i; // assume current index is the largest?
	int l = 2*i; // left node
	int r = (2*i)+1; // right node

	if( l < n  && arr[l] > arr[largest] ){ // if element is larger than its parent, and is real element.
		// could do && left(i) != -1 // and actually use my functions hmmmmmmmm
		largest = l; // new biggest inded
	}
	if ( r < n && arr[r] > arr[largest] ){
		largest = r; // new biggest index
	} // if element is larger than its parent, and exists
	
	if( largest != i){ // if we found a larger element
		swap(arr[i] , arr[largest]); // do we need to include <algorithm> to use this functioun? idk
		heapify(arr , largest, n ); // recurse on our new largest node. // else done
	}

}
void buildHeap(int arr[] ,  int n) { // array, and size of array
	int startingIndex = ( n / 2) + 1; // should be largest non leaf node ?
	for(int i=startingIndex ; i >= 0 ; i-- ){ // starting at our last non leaf node, and moving to the front of array.
		heapify(arr , i , n);
		//cout << " I Heapified\n";
	}
}
int parent( int* arr, int i){
	int nodeIndex = (i-1)/2;
	int node = arr[nodeIndex];
		return node;
}
int left(int* arr, int i){
	int nodeIndex = (2*i)+1; // if heaped, left child should always be x
	if(nodeIndex < arrSize){ // check if child is inside of array bounds
		int node = arr[nodeIndex];
		return node;
	}
	else{
		cout << "IS LEAF NODE";
		return -1 ;		
	}
}
int right(int* arr , int i){
	int nodeIndex = (2*i)+2;
	if(nodeIndex < arrSize){ // check if child is inside of array bounds
		int node = arr[nodeIndex];
		return node;
	}
	else{
		cout << "IS LEAF NODE";
		return -1;		
	}

}
void printHeap(int arr[], int n)  // stole this whole function
{ 
   // cout << "Array representation of Heap is:\n"; 
  
    for (int i = 0; i < n; ++i) 
        cout << arr[i] << " "; 
    cout << "\n"; 
} 
void printFamily(int* arr, int size){
	for( int c = 0 ; c < (size/2) ; c++){	// loop thru array (minus leaf nodes hopefully);
		if(c==0){
			cout << "ROOT IS "<<arr[c] <<endl;
		}else{
			cout << "Index = " << c << " value = " << arr[c] <<endl;
			cout << "\tParentIndex = " << (c-1)/2 << " Parent Val =  " << parent(arr , c) <<endl;
			cout << "\t\tleftIndex = " << (c*2)+1 << " Left Val =  " << left(arr , c) <<endl;
			cout << "\t\trightIndex = " << (c*2)+2 << " Right Val =  " << right(arr , c) <<endl <<endl;
		}		
	}
}

int main(){
	// this is just driver program to try and display some output for me to make sense of whats going on
	cout << "Should heapify things?" <<endl;
	cout << " Arry min to max HEAPED\n";
	buildHeap(arrMin2Max, arrSize);
	printHeap(arrMin2Max, arrSize);

	cout << "Array max to min HEAPED\n";
	buildHeap(arrMax2Min, arrSize);
	printHeap(arrMax2Min, arrSize);

	cout << "Array random HEAPED\n";
	buildHeap(arrRandom, arrSize);
	printHeap(arrRandom, arrSize);	
	// these three heaps dont match up, im not sure whats up.
	cout << "\n\n Heres the printFamily for heaped min2max array \n";
	printHeap(arrMin2Max, arrSize);
	printFamily(arrMin2Max , arrSize);
	printHeap(arrMin2Max, arrSize);
	return 0;
}
