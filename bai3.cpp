#include <iostream>
using namespace std;

// Hàm tìm UCLN bằng thuật toán Euclid
int findGCD(int *a, int *b) {
    int a_val = *a;
    int b_val = *b;
    
    while (b_val != 0) {
        int r = a_val % b_val;
        a_val = b_val;
        b_val = r;
    }
    
    return a_val;
}

int main() {
    // Cấp phát động cho 2 con trỏ
    int *num1 = new int;
    int *num2 = new int;
    
    // Nhập giá trị cho 2 số nguyên
    cout << "Nhap so nguyen thu nhat: ";
    cin >> *num1;
    cout << "Nhap so nguyen thu hai: ";
    cin >> *num2;
    
    // Tìm UCLN
    int gcd = findGCD(num1, num2);
    cout << "Uoc chung lon nhat cua " << *num1 << " va " << *num2 << " la: " << gcd << endl;
    
    // Giải phóng bộ nhớ
    delete num1;
    delete num2;
    
    return 0;
}