#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Nhap so phan tu cua mang (toi da 30): ";
    cin >> n;
    
    if (n <= 0 || n > 30) {
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
    
    // Xuất các phần tử lẻ trong mảng
    cout << "Cac phan tu le trong mang: ";
    for (int i = 0; i < n; i++) {
        if (*(arr + i) % 2 != 0) {
            cout << *(arr + i) << " ";
        }
    }
    cout << endl;
    
    // Tìm địa chỉ của phần tử lớn nhất
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (*(arr + i) > *(arr + maxIndex)) {
            maxIndex = i;
        }
    }
    
    cout << "Gia tri lon nhat trong mang: " << *(arr + maxIndex) << endl;
    cout << "Dia chi cua phan tu lon nhat: " << (arr + maxIndex) << endl;
    
    // Giải phóng bộ nhớ
    delete[] arr;
    
    return 0;
}