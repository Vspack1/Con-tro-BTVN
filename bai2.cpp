#include <iostream>
using namespace std;

int main() {
    // a. Khai báo 1 mảng số nguyên tối đa 30 phần tử.
    int arr[30];
    int n;
    
    // Nhập số phần tử thực tế muốn sử dụng (nhỏ hơn hoặc bằng 30)
    cout << "Nhap so phan tu cua mang (n <= 30): ";
    cin >> n;
    
    if (n <= 0 || n > 30) {
        cout << "So phan tu khong hop le!";
        return 1;
    }
    
    // b. Khởi tạo 1 mảng số nguyên với giá trị nhập từ người dùng
    cout << "Nhap " << n << " phan tu cua mang:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }
    
    // c. Khai báo biến con trỏ p trỏ đến mảng vừa khởi tạo.
    int *p = arr;
    
    // d. Dùng con trỏ và ký pháp độ dời để xuất các giá trị đang lưu trữ trong mảng.
    cout << "Xuat mang bang ky phap do doi: ";
    for (int i = 0; i < n; i++) {
        cout << *(p + i) << " ";
    }
    cout << endl;
    
    // e. Dùng con trỏ và ký pháp chỉ số để xuất các giá trị đang lưu trữ trong mảng.
    cout << "Xuat mang bang ky phap chi so: ";
    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;
    
    return 0;
}