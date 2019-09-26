#include <string>
#include <iostream>

using namespace std;


int arr[] ={10,9,8,7,6,5,4,3,2,1,0};
int arrSize = sizeof(arr) / sizeof(10); // get size of array / /we gonna need to check for tree bounds on parent left and right funcs

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
		// int tempIVal = arr[i]; // just used swap()
		// arr[i] = arr[largest]; // just used swap()
		// arr[largest] = tempIVal; // just used swap()
		swap(arr[i] , arr[largest]); // do we need to include <algorithm> to use this functioun? idk
		heapify(arr , largest, n ); // recurse on our new largest node. // else done
	}

}
void buildHeap(int arr[] ,  int n) { // array, and size of array
	int startingIndex = ( n / 2) + 1; // should be largest non leaf node ?
	for(int i=startingIndex ; i >= 0 ; i-- ){ // starting at our last non leaf node, and moving to the front of array.
		heapify(arr , i , n);
	}
}
int left(int i){
	int nodeIndex = 2*i; // if heaped, left child should always be x
	if(nodeIndex > arrSize){ // check if child is inside of array bounds
		int node = arr[nodeIndex];
		return node;
	}
	else{
		cout << "invalid bounds, DNE";
		return -1 ;		
	}
}
int right(int i){
	int nodeIndex = (2*i)+1;
	if(nodeIndex > arrSize){ // check if child is inside of array bounds
		int node = arr[nodeIndex];
		return node;
	}
	else{
		cout << "invalid bounds, DNE";
		return -1;		
	}

}
void printHeap(int arr[], int n)  // stole this whole function
{ 
    cout << "Array representation of Heap is:\n"; 
  
    for (int i = 0; i < n; ++i) 
        cout << arr[i] << " "; 
    cout << "\n"; 
} 

int main(){
	cout << "Should heapify things?" <<endl;
	cout << "array is as follows" <<endl;
	printHeap(arr , arrSize);
	buildHeap(arr, arrSize);
	printHeap(arr, arrSize);

	return 1;
}
