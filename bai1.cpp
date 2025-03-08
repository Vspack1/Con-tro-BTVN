#include <iostream>
using namespace std;

int main() {
    // a. Khai báo 2 biến x và y kiểu số nguyên.
    int x, y;
    
    // b. Khai báo con trỏ p để trỏ đến biến kiểu số nguyên.
    int *p;
    
    // c. Cho con trỏ p trỏ đến x.
    p = &x;
    
    // d. Con trỏ p nhận giá trị lưu trữ là 80.
    *p = 80;
    
    // e. Xuất địa chỉ của biến x.
    cout << "Dia chi cua bien x: " << &x << endl;
    
    // f. Xuất địa chỉ lưu trong con trỏ p.
    cout << "Dia chi luu trong con tro p: " << p << endl;
    
    // g. Xuất giá trị của biến mà p trỏ đến.
    cout << "Gia tri cua bien ma p tro den: " << *p << endl;
    
    // h. Xuất giá trị của biến x. Giá trị này có phải là giá trị mà p lưu trữ?
    cout << "Gia tri cua bien x: " << x << endl;
    cout << "Gia tri nay chinh la gia tri ma p luu tru" << endl;
    
    return 0;
}