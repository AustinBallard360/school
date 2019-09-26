// this is selection sort java Test
class SelectionSort {
	public static void main(String[] args){
		int[] arr1 = {13,6,18,3,12,7,2,10};
		int min,temp,i,j;
		int index=0;
		for(int ix=0;ix<arr1.length;ix++){
			System.out.print(arr1[ix] + ",");
		}

		System.out.println("OK, so thats the array \n");
		min = arr1[index];
		for(i=0;i<arr1.length;i++){
			min = arr1[i];

			for (j=i+1 ; j<arr1.length;j++){
				if(arr1[j]<min){
					min = arr1[j];
					index = j;
					System.out.println("Minimum element is now "+min);
				}
			}
		temp = arr1[i];
		arr1[i] = arr1[index];
		arr1[index] = temp;

		} // end for i
		System.out.print("\n\n\n The finaly is ");
		for(int z = 0 ; z<arr1.length ; z++){
			System.out.print(arr1[z]+", ");
		}

		}// END CLASS
}


