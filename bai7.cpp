#include <iostream>
using namespace std;

// Hàm tìm kiếm số nguyên trong mảng, trả về con trỏ đến vị trí đầu tiên tìm thấy
int* searchNumber(int *arr, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (*(arr + i) == value) {
            return (arr + i);
        }
    }
    return NULL;
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
    
    // Nhập giá trị cần tìm
    int searchValue;
    cout << "Nhap gia tri can tim: ";
    cin >> searchValue;
    
    // Tìm kiếm giá trị
    int *result = searchNumber(arr, n, searchValue);
    
    if (result != NULL) {
        int position = result - arr; // Tính vị trí của phần tử
        cout << "Tim thay " << searchValue << " tai vi tri " << position << endl;
    } else {
        cout << "Khong tim thay " << searchValue << " trong mang." << endl;
    }
    
    // Giải phóng bộ nhớ
    delete[] arr;
    
    return 0;
}