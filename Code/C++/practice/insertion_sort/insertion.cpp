#include <string>
#include <iostream>


using namespace std;
void printArray(int *arr , int arrSize) {
	//cout << "Array Size : " << arrSize << " \n";
	for(int i = 0; i < arrSize ; i++){
		//cout << "i" << i  << " :";
		cout << arr[i] << " ,";
	}
	cout << "\n\n";
}
void sortArray(int *arr , int size){
	 int key , j;
	for(int i = 1 ; i < size ; i++){
		key = arr[i];
		j = i;
		while( j > 0 && arr[j-1] > key){
			arr[j] = arr[j-1];
			j--;
			//cout << " I go \n";
		}
		arr[j] = key;

		}
	}




int main(){
	int arr[] = {6 , 1 , 3 , 2 , 4 , 5 , 4};
	int arrSize = sizeof(arr) / sizeof(arr[0]);
	cout << "size is " << arrSize << " \n";
	printArray(arr , arrSize);
		//cout << "\nDONE PRINT\n";
	sortArray(arr , arrSize);
		//cout << "\nDONE SORT\n";

	// print the array
	printArray(arr , arrSize);

	return 0;
}

