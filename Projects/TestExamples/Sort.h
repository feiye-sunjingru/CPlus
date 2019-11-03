// Sort.h ѡ������ĺ���ģ�� 

template <class T>
void mySwap(T&x, T&y){
	T temp = x;
	x = y;
	y = temp;
}

template <class T>
void selectionSort(T a[], int n){  // ��С�������� 
	for(int i=0; i<n-1; i++){
		int leaseIndex = i;
		for(int j=i+1; j<n; j++){ // �ҳ�һ�α�������С��ֵ 
			if(a[j]<a[leaseIndex]){
				leaseIndex = j;
			}
		}
		mySwap(a[i], a[leaseIndex]); 
	}
} 

template <class T>
void bubbleSort(T a[], int n){  // ��С�������� 
	int i = n-1;
	while(i > 0){
		int lastExchangeIndex = 0;  // ���һ�η����������±꣬���������������л�Ҫ�Ƚ� 
		for(int j=0; j<i; j++){ // һ�α����������Ƚ� 
			if(a[j+1] < a[j]){ 
				mySwap(a[j], a[j+1]);
				lastExchangeIndex = j;
			}
		}
		i = lastExchangeIndex;
	}
}