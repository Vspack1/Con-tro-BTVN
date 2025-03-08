#include <iostream>
using namespace std;

// Hàm xuất n số Fibonacci dùng con trỏ
void printFibonacci(int *n) {
    if (*n <= 0) {
        cout << "So phan tu khong hop le!" << endl;
        return;
    }
    
    // Cấp phát mảng để lưu dãy Fibonacci
    int *fib = new int[*n];
    
    // Khởi tạo hai số đầu tiên
    *fib = 0;
    if (*n > 1) {
        *(fib + 1) = 1;
    }
    
    // Tính các số tiếp theo
    for (int i = 2; i < *n; i++) {
        *(fib + i) = *(fib + i - 1) + *(fib + i - 2);
    }
    
    // In dãy Fibonacci
    cout << "Day " << *n << " so Fibonacci: ";
    for (int i = 0; i < *n; i++) {
        cout << *(fib + i) << " ";
    }
    cout << endl;
    
    // Giải phóng bộ nhớ
    delete[] fib;
}

int main() {
    int *n = new int;
    
    cout << "Nhap so phan tu n cua day Fibonacci (n > 1): ";
    cin >> *n;
    
    printFibonacci(n);
    
    delete n;
    return 0;
}