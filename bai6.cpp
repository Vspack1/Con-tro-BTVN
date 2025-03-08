#include <iostream>
using namespace std;

// Hàm đảo ngược mảng dùng con trỏ
void reverseArray(int *arr, int size) {
    int *start = arr;
    int *end = arr + size - 1;
    
    while (start < end) {
        // Hoán đổi giá trị
        int temp = *start;
        *start = *end;
        *end = temp;
        
        // Di chuyển con trỏ
        start++;
        end--;
    }
}

int main() {
    int n;
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "So phan tu khong hop le!";
        return 1;
    }
    
    // Cấp phát động mảng
    int *arr = new int[n];
    
    // Nhập mảng
    cout << "Nhap " << n << " phan tu cua mang:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }
    
    // In mảng ban đầu
    cout << "Mang ban dau: ";
    for (int i = 0; i < n; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
    
    // Đảo ngược mảng
    reverseArray(arr, n);
    
    // In mảng sau khi đảo ngược
    cout << "Mang sau khi dao nguoc: ";
    for (int i = 0; i < n; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
    
    // Giải phóng bộ nhớ
    delete[] arr;
    
    return 0;
}