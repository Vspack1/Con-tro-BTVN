#include <iostream>
using namespace std;

// Hàm cấp phát động ma trận
int** createMatrix(int rows, int cols) {
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    return matrix;
}

// Hàm nhập ma trận từ người dùng
void inputMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "matrix[" << i << "][" << j << "] = ";
            cin >> matrix[i][j];
        }
    }
}

// Hàm xuất ma trận
void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// Hàm tính tổng hai ma trận
int** addMatrices(int** matrixA, int** matrixB, int rows, int cols) {
    int** result = createMatrix(rows, cols);
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    
    return result;
}

// Hàm tính tích hai ma trận
int** multiplyMatrices(int** matrixA, int** matrixB, int rowsA, int colsA, int colsB) {
    // rowsA x colsA * colsA x colsB = rowsA x colsB
    int** result = createMatrix(rowsA, colsB);
    
    // Khởi tạo ma trận kết quả với giá trị 0
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
        }
    }
    
    // Tính tích ma trận
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    
    return result;
}

// Hàm giải phóng bộ nhớ ma trận
void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    int rowsA, colsA, rowsB, colsB;
    
    cout << "Nhap kich thuoc ma tran A (rows cols): ";
    cin >> rowsA >> colsA;
    
    cout << "Nhap kich thuoc ma tran B (rows cols): ";
    cin >> rowsB >> colsB;
    
    // Kiểm tra điều kiện tính tổng và tích ma trận
    bool canAdd = (rowsA == rowsB && colsA == colsB);
    bool canMultiply = (colsA == rowsB);
    
    if (!canAdd && !canMultiply) {
        cout << "Khong the tinh tong va tich voi kich thuoc ma tran da cho!" << endl;
        return 1;
    }
    
    // Tạo ma trận A
    int** matrixA = createMatrix(rowsA, colsA);
    cout << "\nNhap cac phan tu ma tran A:" << endl;
    inputMatrix(matrixA, rowsA, colsA);
    
    // Tạo ma trận B
    int** matrixB = createMatrix(rowsB, colsB);
    cout << "\nNhap cac phan tu ma tran B:" << endl;
    inputMatrix(matrixB, rowsB, colsB);
    
    // Xuất ma trận A
    cout << "\nMa tran A (" << rowsA << "x" << colsA << "):" << endl;
    printMatrix(matrixA, rowsA, colsA);
    
    // Xuất ma trận B
    cout << "\nMa tran B (" << rowsB << "x" << colsB << "):" << endl;
    printMatrix(matrixB, rowsB, colsB);
    
    // Tính và xuất tổng ma trận
    if (canAdd) {
        int** sumMatrix = addMatrices(matrixA, matrixB, rowsA, colsA);
        cout << "\nTong hai ma tran A + B:" << endl;
        printMatrix(sumMatrix, rowsA, colsA);
        freeMatrix(sumMatrix, rowsA);
    } else {
        cout << "\nKhong the tinh tong vi kich thuoc ma tran khong phu hop!" << endl;
    }
    
    // Tính và xuất tích ma trận
    if (canMultiply) {
        int** productMatrix = multiplyMatrices(matrixA, matrixB, rowsA, colsA, colsB);
        cout << "\nTich hai ma tran A * B:" << endl;
        printMatrix(productMatrix, rowsA, colsB);
        freeMatrix(productMatrix, rowsA);
    } else {
        cout << "\nKhong the tinh tich vi kich thuoc ma tran khong phu hop!" << endl;
    }
    
    // Giải phóng bộ nhớ
    freeMatrix(matrixA, rowsA);
    freeMatrix(matrixB, rowsB);
    
    return 0;
}