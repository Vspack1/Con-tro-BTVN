#include <iostream>
#include <cmath>
using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    
    for (int i = 5; i <= sqrt(num); i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

// Hàm nhập mảng 2 chiều
void inputMatrix(int **&matrix, int r, int c) {
    matrix = new int*[r];
    for (int i = 0; i < r; i++) {
        matrix[i] = new int[c];
        for (int j = 0; j < c; j++) {
            cout << "matrix[" << i << "][" << j << "] = ";
            cin >> matrix[i][j];
        }
    }
}

// Hàm xuất mảng 2 chiều
void outputMatrix(int **matrix, int r, int c) {
    cout << "Ma tran " << r << "x" << c << ":" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// Hàm tính tổng các số nguyên tố trong mảng 2 chiều
int sumPrimes(int **matrix, int r, int c) {
    int sum = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (isPrime(matrix[i][j])) {
                sum += matrix[i][j];
            }
        }
    }
    return sum;
}

// Hàm đếm số lượng số nguyên tố trong mảng 2 chiều
int countPrimes(int **matrix, int r, int c) {
    int count = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (isPrime(matrix[i][j])) {
                count++;
            }
        }
    }
    return count;
}

// Hàm trả về các số nguyên tố trong mảng 2 chiều
void getPrimes(int **matrix, int r, int c, int *primes, int &primeCount) {
    primeCount = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (isPrime(matrix[i][j])) {
                primes[primeCount++] = matrix[i][j];
            }
        }
    }
}

// Hàm giải phóng bộ nhớ của mảng 2 chiều
void freeMatrix(int **matrix, int r) {
    for (int i = 0; i < r; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    int r, c;
    int **matrix = NULL;
    
    cout << "Nhap so hang cua ma tran: ";
    cin >> r;
    cout << "Nhap so cot cua ma tran: ";
    cin >> c;
    
    if (r <= 0 || c <= 0) {
        cout << "Kich thuoc ma tran khong hop le!";
        return 1;
    }
    
    // Nhập ma trận
    cout << "Nhap cac phan tu cua ma tran:" << endl;
    inputMatrix(matrix, r, c);
    
    // Xuất ma trận
    cout << "\nMa tran vua nhap:" << endl;
    outputMatrix(matrix, r, c);
    
    // Tính tổng các số nguyên tố
    int sum = sumPrimes(matrix, r, c);
    cout << "\nTong cac so nguyen to trong ma tran: " << sum << endl;
    
    // Lấy danh sách các số nguyên tố
    int maxPrimes = r * c; // Số lượng tối đa số nguyên tố có thể có
    int *primes = new int[maxPrimes];
    int primeCount = 0;
    
    getPrimes(matrix, r, c, primes, primeCount);
    
    cout << "Cac so nguyen to trong ma tran: ";
    for (int i = 0; i < primeCount; i++) {
        cout << primes[i] << " ";
    }
    cout << endl;
    
    // Giải phóng bộ nhớ
    delete[] primes;
    freeMatrix(matrix, r);
    
    return 0;
}