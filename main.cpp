#include <iostream> 
#include <random>
#include <chrono>
#include <algorithm>  

void Menu(); 
void InitArray();
int FreddyAlgo(int*,int);
int SophieAlgo(int*,int);
int JohnyAlgo(int*,int,int); 
int SallyAlgo(int*,int);
void testCase1();
void testCase2();
void testCase3();
void testCase4();
void testCase5();
void testCase6();

int *arr;
int size;

int main() {
    std::chrono::time_point<std::chrono::steady_clock> begin;
	std::chrono::time_point<std::chrono::steady_clock> end;
    char choice;
    double deltaT;

    Menu();
    choice = getchar();
    do { 
        while ((getchar()) != '\n'); 
        switch (choice){
            case '1': 
                exit(0); 
                break; 
            case '2':
            {
                InitArray();
                auto begin = std::chrono::high_resolution_clock::now();
                FreddyAlgo(arr, size);
                auto end = std::chrono::high_resolution_clock::now();
                deltaT = std::chrono::duration<double, std::milli>(end - begin).count();
                std::cout << "Elapsed time: " << deltaT<< "ms\n"; 
            }
                break;
            case '3':
            {
                InitArray();
                auto begin = std::chrono::high_resolution_clock::now();
                SophieAlgo(arr, size);
                auto end = std::chrono::high_resolution_clock::now();
                deltaT = std::chrono::duration<double, std::milli>(end - begin).count();
                std::cout << "Elapsed time: " << deltaT<< "ms\n"; 
            }
                break;
            case '4':
            {
                InitArray();
                auto begin = std::chrono::high_resolution_clock::now();
                JohnyAlgo(arr, 0, size - 1);
                auto end = std::chrono::high_resolution_clock::now();
                deltaT = std::chrono::duration<double, std::milli>(end - begin).count();
                std::cout << "Elapsed time: " << deltaT<< "ms\n"; 
            }
                break;
            case '5':
            {
                InitArray();
                auto begin = std::chrono::high_resolution_clock::now();
                SallyAlgo(arr, size);
                auto end = std::chrono::high_resolution_clock::now();
                deltaT = std::chrono::duration<double, std::milli>(end - begin).count();
                std::cout << "Elapsed time: " << deltaT<< "ms\n"; 
            }
                break;
            default: std::cout << "Invalid input \n" ;
                     break;
        }
        Menu();
        while ((getchar()) != '\n'); 
        choice = getchar(); 
        // fflush(stdin);   
        // std::cin >> choice;
        // std::cout << choice;
        // fflush(stdin);
    } while (choice != 1);
    return 0;
}   

int testmain(){ 
    testCase1();
    testCase2();
    testCase3();
    testCase4();
    testCase5();
    testCase6();
    return 0;
}

void testCase1(){ 
    int testcase1[] = {-2,-3,4,-6,7,9,-10,1,12,-8};
    arr = testcase1; 
    size = 10;
    std::cout << "Test case 1: \n";
    int result = FreddyAlgo(arr, size); 
    std::cout << "Result of Freddy's Algorithm: \t" << result << std::endl;
    result = SophieAlgo(arr, size); 
    std::cout << "Result of Sophie's Algorithm: \t" << result << std::endl;
    result = JohnyAlgo(arr, 0, size -1); 
    std::cout << "Result of Johny's Algorithm: \t" << result << std::endl;
    result = SallyAlgo(arr, size); 
    std::cout << "Result of Sally's Algorithm: \t" << result << std::endl;
}

void testCase2(){ 
    int testcase2[] = {-2,20,-3,4,-6,7,9,-10,1,12,-8};
    size = 11;
    arr = testcase2; 
    std::cout << "Test case 2: \n";
    int result = FreddyAlgo(arr, size); 
    std::cout << "Result of Freddy's Algorithm: \t" << result << std::endl;
    result = SophieAlgo(arr, size); 
    std::cout << "Result of Sophie's Algorithm: \t" << result << std::endl;
    result = JohnyAlgo(arr, 0, size -1); 
    std::cout << "Result of Johny's Algorithm: \t" << result << std::endl;
    result = SallyAlgo(arr, size); 
    std::cout << "Result of Sally's Algorithm: \t" << result << std::endl;
}

void testCase3(){ 
    int testcase3[] = {};
    size = 0;
    arr = testcase3; 
    std::cout << "Test case 3: \n";
    int result = FreddyAlgo(arr, size); 
    std::cout << "Result of Freddy's Algorithm: \t" << result << std::endl;
    result = SophieAlgo(arr, size); 
    std::cout << "Result of Sophie's Algorithm: \t" << result << std::endl;
    result = JohnyAlgo(arr, 0, size -1); 
    std::cout << "Result of Johny's Algorithm: \t" << result << std::endl;
    result = SallyAlgo(arr, size); 
    std::cout << "Result of Sally's Algorithm: \t" << result << std::endl;
}

void testCase4(){ 
    int testcase4[] = {-1,-2,-3,-4,-5,-6,-7,-8,-9,-10};
    size = 10;
    arr = testcase4; 
    std::cout << "Test case 4: \n";
    int result = FreddyAlgo(arr, size); 
    std::cout << "Result of Freddy's Algorithm: \t" << result << std::endl;
    result = SophieAlgo(arr, size); 
    std::cout << "Result of Sophie's Algorithm: \t" << result << std::endl;
    result = JohnyAlgo(arr, 0, size -1); 
    std::cout << "Result of Johny's Algorithm: \t" << result << std::endl;
    result = SallyAlgo(arr, size); 
    std::cout << "Result of Sally's Algorithm: \t" << result << std::endl;
}

void testCase5(){ 
    int testcase5[] = {0,0,0,0,0,0,0,0,0,0};
    size = 10;
    arr = testcase5; 
    std::cout << "Test case 5: \n";
    int result = FreddyAlgo(arr, size); 
    std::cout << "Result of Freddy's Algorithm: \t" << result << std::endl;
    result = SophieAlgo(arr, size); 
    std::cout << "Result of Sophie's Algorithm: \t" << result << std::endl;
    result = JohnyAlgo(arr, 0, size -1); 
    std::cout << "Result of Johny's Algorithm: \t" << result << std::endl;
    result = SallyAlgo(arr, size); 
    std::cout << "Result of Sally's Algorithm: \t" << result << std::endl;
}

void testCase6(){ 
    int testcase6[] = {1,2,3,4,5,6,7,8,9,10};
    size = 10;
    arr = testcase6; 
    std::cout << "Test case 6: \n";
    int result = FreddyAlgo(arr, size); 
    std::cout << "Result of Freddy's Algorithm: \t" << result << std::endl;
    result = SophieAlgo(arr, size); 
    std::cout << "Result of Sophie's Algorithm: \t" << result << std::endl;
    result = JohnyAlgo(arr, 0, size -1); 
    std::cout << "Result of Johny's Algorithm: \t" << result << std::endl;
    result = SallyAlgo(arr, size); 
    std::cout << "Result of Sally's Algorithm: \t" << result << std::endl;
}

void Menu() {
    
    std::cout << "*******************************************\n";
    std::cout << " 1 - Quit the program\n"; 
    std::cout << " 2 - Time Freddy's algorithm\n"; 
    std::cout << " 3 - Time Sophie's algorithm\n"; 
    std::cout << " 4 - Time Johnny's algorithm\n"; 
    std::cout << " 5 - Time Sally's algorithm\n"; 
}

void InitArray(){ 
    int seed; 
    std::cout << "Please input seed value: \n";
    std::cin >> seed;
    std::cout << "Please input size value: \n";
    std::cin >> size;
    std::mt19937 generator(seed);
    std::uniform_int_distribution<int> distribution(-100,100);  
    arr = new int[size]; 

    for (int i = 0; i < size; i++)
        {
            arr[i] =  distribution(generator);
        }
}

int FreddyAlgo(int* a, int size){ 
    int max = 0;
    int thisSum; 
    for (int i = 0; i < size; i++){ 
        for (int j = i; j < size; j++){
            thisSum = 0;
            for (int k = i; k <= j; k++){ 
                thisSum += a[k];
            }
            if (thisSum > max){
                max = thisSum; 
            }
        }
    }
    return max;
} 

int SophieAlgo(int* a, int size){ 
    int max = 0;
    int thisSum;
    for (int i = 0; i < size; i++){ 
        thisSum = 0; 
        for (int j = i; j < size; j++){
            thisSum += a[j]; 
            if (thisSum > max){ 
                max = thisSum; 
            }
        }
    }
    return max;
}

int JohnyAlgo(int* a, int left, int right){ 
    if (left < 0 || right < 0){ 
        return 0;
    }
    int center, maxLeftSum, maxRightSum; 
    if (left == right){ 
        if (a[left] > 0)
            return a[left]; //base case
        return 0;
    }

    //split the array in 2 and find each half's max sum
    center = (left + right) / 2; 
    maxLeftSum = JohnyAlgo(a, left, center); 
    maxRightSum = JohnyAlgo(a, center + 1, right); 

    // find the max sum starting at center and moving left
    int maxLeftBorder = 0;
    int leftBorder = 0;
    for (int i = center; i >= left; i--){ 
        leftBorder += a[i];
        if (leftBorder > maxLeftBorder)
           maxLeftBorder = leftBorder; 
    }

    // find the max starting at center and moving right 
    int maxRightBorder = 0;
    int rightBorder = 0; 
    for (int i = center + 1; i <= right; i++){
        rightBorder += a[i]; 
        if (rightBorder > maxRightBorder)
            maxRightBorder = rightBorder; 
    }

    // the max sum is the largest of the three sums found
    return std::max(std::max(maxLeftSum, maxRightSum), maxLeftBorder + maxRightBorder);

}

int SallyAlgo(int* a, int size){ 
    int max = 0; 
    int thisSum = 0;
    for (int i = 0; i < size; i++){
        thisSum += a[i];
        if (thisSum > max)
            max = thisSum;
        else if (thisSum < 0)
            thisSum = 0; 
    }
    return max;
}


