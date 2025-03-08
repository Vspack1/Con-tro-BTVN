#include <iostream>
using namespace std;

int main() {
    int h;
    cout << "Nhap chieu cao cua tam giac Pascal (h > 0): ";
    cin >> h;
    
    if (h <= 0) {
        cout << "Chieu cao khong hop le!";
        return 1;
    }
    
    // Cấp phát động mảng 2 chiều
    int **pascal = new int*[h];
    for (int i = 0; i < h; i++) {
        pascal[i] = new int[i + 1];
    }
    
    // Tính giá trị của tam giác Pascal
    for (int i = 0; i < h; i++) {
        for (int j = 0; j <= i; j++) {
            // Các phần tử ở biên tam giác đều bằng 1
            if (j == 0 || j == i) {
                pascal[i][j] = 1;
            } else {
                // Phần tử bằng tổng 2 phần tử ở hàng trên
                pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
            }
        }
    }
    
    // Xuất tam giác Pascal
    cout << "Tam giac Pascal voi chieu cao " << h << ":" << endl;
    for (int i = 0; i < h; i++) {
        // In khoảng trắng để tạo hình tam giác
        for (int space = 0; space < h - i - 1; space++) {
            cout << "  ";
        }
        
        // In giá trị của hàng thứ i
        for (int j = 0; j <= i; j++) {
            cout << pascal[i][j] << "   ";
        }
        cout << endl;
    }
    
    // Giải phóng bộ nhớ
    for (int i = 0; i < h; i++) {
        delete[] pascal[i];
    }
    delete[] pascal;
    
    return 0;
}