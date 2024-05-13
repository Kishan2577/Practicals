/*
Problem Statement: Min/max Heaps: Marks obtained by students of second year in an online examination of a particular subject are stored by 			the teacher.Teacher wants to find the minimum and maximum marks of the subject. Write a menu driven C++ program to find out maximum 		and minimum marks obtained in that subject using heap data structure. Analyze the algorithm

Name: Harish Lukare
Roll No. : 35
Division : A
*/

#include <iostream>
#include <climits> 
using namespace std;

int num, num1, num2;
class Data { 
    int* arr; 
    int maxSize; 
    int heapSize; 

public:  
    Data(int maxSize) {
        this->maxSize = maxSize;
        this->heapSize = 0;
        this->arr = new int[maxSize];
    }

    void max(int i) { 
        int l = lChild(i); 
        int r = rChild(i); 
        int largest = i; 
        if (l < heapSize && arr[l] > arr[i]) 
            largest = l; 
        if (r < heapSize && arr[r] > arr[largest]) 
            largest = r; 
        if (largest != i) { 
            swap(arr[i], arr[largest]); 
            max(largest); 
        } 
    } 
    
    int min(int i) {
    int l = lChild(i);
    int r = rChild(i);
    int smallest = i;
    if (l < heapSize && arr[l] < arr[i])
        smallest = l;
    if (r < heapSize && arr[r] < arr[smallest])
        smallest = r;
    if (smallest != i)
        return min(smallest);
    return arr[smallest];
	}

	int findMin() {
    int min_val = arr[heapSize / 2];
    for (int i = heapSize / 2; i < heapSize; ++i) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }

    return min_val;
	}

    
    int parent(int i) { 
        return (i - 1) / 2; 
    } 
    
    int lChild(int i) { 
        return (2 * i + 1); 
    } 
    
    int rChild(int i) { 
        return (2 * i + 2); 
    } 
    
    int removeMax() {
        if (heapSize <= 0) 
            return INT_MIN; 
        if (heapSize == 1) { 
            heapSize--; 
            return arr[0]; 
        } 
        int root = arr[0]; 
        arr[0] = arr[heapSize - 1]; 
        heapSize--; 
        max(0); 
        return root; 
    } 
    
    void increaseKey(int i, int newVal) { 
        arr[i] = newVal; 
        while (i != 0 && arr[parent(i)] < arr[i]) { 
            swap(arr[i], arr[parent(i)]); 
            i = parent(i); 
        } 
    }
    
    int getMax() { 
        return arr[0]; 
    } 

    int curSize() { 
        return heapSize; 
    } 
    
    void deleteKey(int i) { 
        increaseKey(i, INT_MAX); 
        removeMax(); 
    }
     
    void insertKey(int key) {
        if (heapSize == maxSize) { 
            cout << "\nCould not insertKey!\n"; 
            return; 
        } 
        int i = heapSize; 
        heapSize++; 
        arr[i] = key; 
        while (i != 0 && arr[parent(i)] < arr[i]) { 
            swap(arr[i], arr[parent(i)]); 
            i = parent(i); 
        } 
    }  
};

int main() {
    Data h(15); 
    int ch;
    int key;
    while(1){
    cout<<"Enter your choice: "<<endl;
    cout<<"0. Insert keys\n1. Find Minimum element from whole heap\n2. Find current minimum element\n3. Find maximum element\n4. Delete element\n5. Exit"<<endl;
    cin>>ch;
    switch(ch){
    case 0: 
    	cout << "Enter number of keys: ";
    	cin >> num;
    	for(int i = 0; i < num; i++) {
        cout << "Enter key " << i + 1 << ": ";
        cin >> key;
        h.insertKey(key);
    	}
    	break;
    	
    case 1:
    	cout << "The minimum element is " << h.findMin() << "\n";
    	break;
    	
    case 2:
    	cout << "The current minimum element is " << h.min(0) << "\n";
    	break;
    	
    case 3:
    	cout << "The maximum element is " << h.getMax() << "\n";
    	break;
    	
    case 4:
    	cout<<"Enter key to delete: ";
    	cin>>num2;
    	h.deleteKey(num2); 
    	cout<<"Element deleted successfully."<<endl;
    	break;
    	
    case 5:
    	exit(1);
    	
    default:
    	cout<<"Enter correct choice.\n";
    }}
   return 0; 
}



