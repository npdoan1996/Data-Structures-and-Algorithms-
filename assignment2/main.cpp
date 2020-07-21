#include <iostream> 
#include <random>
#include <chrono>
#include <algorithm>  

#define ARRAY_SIZE 100000

void Menu(); 
void SortedArray(int*);
void RandomArray(int*);
void ReversedArray(int*);
void printArray(int*);
void duplicateArray(int*,int*);
void insertionSort(int*,int,int);
bool isOrdered(int*,int); 
int partition(int[],int,int,int);
void quickSort(int[],int,int);
void swap(int*,int*);
int medianOfThree(int[],int,int);

int main() {
    std::chrono::time_point<std::chrono::steady_clock> begin;
	std::chrono::time_point<std::chrono::steady_clock> end;
    int arr[ARRAY_SIZE];
    int dupArray1[ARRAY_SIZE], dupArray2[ARRAY_SIZE];
    char choice;
    double deltaT;

    Menu();
    choice = getchar();
    do { 
        while ((getchar()) != '\n'); 
        switch (choice){
            case '1': 
            {
                SortedArray(arr);
            }
                break; 
            case '2':
            {
                RandomArray(arr);
            }
                break;
            case '3':
            {
                ReversedArray(arr);
            }
                break;
            case '4':
                exit(0); 
                break; 
            default: 
                std::cout << "Invalid input \n" ;
                break;
        }

        // Insertion Sort 
        duplicateArray(arr, dupArray1);
        auto begin = std::chrono::high_resolution_clock::now();
        insertionSort(dupArray1, 0, ARRAY_SIZE-1);
        auto end = std::chrono::high_resolution_clock::now();
        deltaT = std::chrono::duration<double, std::milli>(end - begin).count();
        std::cout << "Insertion Sort:\n";
        std::cout << "Elapsed time: " << deltaT<< "ms\n"; 
        if (isOrdered(dupArray1, ARRAY_SIZE))
            std::cout << "The first duplicate array is sorted\n\n"; 
        else
            std::cout << "The first duplicate array is not sorted\n\n"; 

        // Quick Sort
        duplicateArray(arr, dupArray2);
        begin = std::chrono::high_resolution_clock::now();
        quickSort(dupArray2, 0, ARRAY_SIZE-1);
        end = std::chrono::high_resolution_clock::now();
        deltaT = std::chrono::duration<double, std::milli>(end - begin).count();
        std::cout << "Quick Sort\n";
        std::cout << "Elapsed time: " << deltaT<< "ms\n"; 
        if (isOrdered(dupArray2, ARRAY_SIZE))
            std::cout << "The second duplicate array is sorted\n"; 
        else
            std::cout << "The second duplicate array is not sorted\n"; 
        // printArray(dupArray2);
        Menu();
        choice = getchar(); 

    } while (choice != 4);
    return 0;
}   

void Menu() {
    std::cout << "Please select one of three arrays to sort:\n";
    std::cout << "*******************************************\n";
    std::cout << " 1 - Sorted\n"; 
    std::cout << " 2 - Random\n"; 
    std::cout << " 3 - Reverse\n"; 
    std::cout << " 4 - Quit the program\n";      
}

void SortedArray(int* arr) { 
    for (int i = 0; i < ARRAY_SIZE; i++){
        arr[i] = i + 1;
    }
}

void RandomArray(int* arr){ 
    int seed = 1; 
    int size = ARRAY_SIZE;
    std::mt19937 generator(seed);
    std::uniform_int_distribution<int> distribution(0,100000);  

    for (int i = 0; i < size; i++){    
        arr[i] =  distribution(generator);
    }
}

void ReversedArray(int* arr) {
    for (int i = 0; i < ARRAY_SIZE; i++){
        arr[i] = ARRAY_SIZE - i;
    }
}

void printArray(int* arr) {
    for (int i = 0; i < ARRAY_SIZE; i++){
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

void duplicateArray(int* arr, int* dupArray) { 
    for (int i = 0; i < ARRAY_SIZE; i++){
        dupArray[i] = arr[i];
    }
}

void insertionSort(int *arr, int start, int end) { 
        for (int i = start; i <= end; i++){
            int j, temp = arr[i]; 
            for (j = i -1; j >= 0; j--){ 
            if (arr[j] > temp)
                arr[j+1] = arr[j];
            else
                break;
        }
        arr[j+1] = temp;
    }   
}

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 


int partition(int arr[], int left, int right, int pivotIndex) { 
    int pivotValue = arr[pivotIndex]; 
    swap(&arr[pivotIndex], &arr[right]); // move pivotValue to end

    // partition the array, upon finding an element smaller than pivot
    // swap it to the next position in the "store"
    int store = left; 
    for (int i = left; i < right; i++) {
        if (arr[i] <= pivotValue){
            swap(&arr[store], &arr[i]);
            store++;
        }
    }
    swap(&arr[right], &arr[store]);
    return store;
}

void quickSort(int arr[], int start, int end) {
    if ((end - start) <= 9)
        insertionSort(arr, start, end);
    else{
        int pivot; 
        
        // find the pivot
        pivot = medianOfThree(arr, start, end);

        int store = partition(arr, start, end, pivot); 
        quickSort(arr, start, store - 1);
        quickSort(arr, store + 1, end);
    }
    
}

int medianOfThree(int arr[], int start, int end) {
    int mid = (start + end) / 2; 
    if ((arr[start] <= arr[mid] && arr[mid] <= arr[end]) 
        || (arr[end] <= arr[mid] && arr[mid] <= arr[start]))
        return mid; 
    else if ((arr[mid] <= arr[start] && arr[start] <= arr[end])
        || (arr[end] <= arr[start] && arr[start] <= arr[mid]))
        return start; 
    else 
        return end;
}

bool isOrdered(int *arr, int size) { 
    for (int i = 0; i < size-1; i++) {
        if (arr[i] > arr[i+1]) 
            return false; 
    }
    return true;
}
