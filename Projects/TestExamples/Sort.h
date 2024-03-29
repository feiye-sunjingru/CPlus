// Sort.h 选择排序的函数模板 

template <class T>
void mySwap(T&x, T&y){
	T temp = x;
	x = y;
	y = temp;
}

template <class T>
void selectionSort(T a[], int n){  // 从小到大排序 
	for(int i=0; i<n-1; i++){
		int leaseIndex = i;
		for(int j=i+1; j<n; j++){ // 找出一次遍历中最小的值 
			if(a[j]<a[leaseIndex]){
				leaseIndex = j;
			}
		}
		mySwap(a[i], a[leaseIndex]); 
	}
} 

template <class T>
void bubbleSort(T a[], int n){  // 从小到大排序 
	int i = n-1;
	while(i > 0){
		int lastExchangeIndex = 0;  // 最后一次发生交换的下标，避免后面的有序序列还要比较 
		for(int j=0; j<i; j++){ // 一次遍历中两两比较 
			if(a[j+1] < a[j]){ 
				mySwap(a[j], a[j+1]);
				lastExchangeIndex = j;
			}
		}
		i = lastExchangeIndex;
	}
}