#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Matran {
private:
    int m; // Số hàng
    int n; // Số cột
    vector<vector<int>> data; // Dữ liệu của ma trận

public:
    // Hàm khởi tạo
    Matran(int rows, int cols) : m(rows), n(cols), data(vector<vector<int>>(rows, vector<int>(cols, 0))) {}

    // Hàm nhập ma trận
    friend istream& operator>>(istream& is, Matran& matrix) {
        for (int i = 0; i < matrix.m; ++i) {
            for (int j = 0; j < matrix.n; ++j) {
                is >> matrix.data[i][j];
            }
        }
        return is;
    }

    // Hàm xuất ma trận
    friend ostream& operator<<(ostream& os, const Matran& matrix) {
        for (int i = 0; i < matrix.m; ++i) {
            for (int j = 0; j < matrix.n; ++j) {
                os << matrix.data[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }

    // Toán tử cộng hai ma trận
    Matran operator+(const Matran& other) const {
        Matran result(m, n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // Toán tử nhân ma trận với một số nguyên
    Matran operator*(int scalar) const {
        Matran result(m, n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                result.data[i][j] = data[i][j] * scalar;
            }
        }
        return result;
    }

    // Hàm bạn tính tổng các phần tử của ma trận
    friend int TongPhanTu(const Matran& matrix) {
        int sum = 0;
        for (int i = 0; i < matrix.m; ++i) {
            for (int j = 0; j < matrix.n; ++j) {
                sum += matrix.data[i][j];
            }
        }
        return sum;
    }

    // Hàm bạn toán tử ! để tính giá trị lớn nhất của ma trận
    friend int operator!(const Matran& matrix) {
        int max_value = numeric_limits<int>::min(); // Khởi tạo giá trị lớn nhất có thể
        for (int i = 0; i < matrix.m; ++i) {
            for (int j = 0; j < matrix.n; ++j) {
                if (matrix.data[i][j] > max_value) {
                    max_value = matrix.data[i][j];
                }
            }
        }
        return max_value;
    }
};

int main() {
    int m, n; // Số hàng và số cột của ma trận
    cout << "Nhap so hang cua ma tran: ";
    cin >> m;
    cout << "Nhap so cot cua ma tran: ";
    cin >> n;

    // Nhập ma trận A
    cout << "Nhap ma tran A:\n";
    Matran A(m, n);
    cin >> A;

    // Nhập ma trận B
    cout << "Nhap ma tran B:\n";
    Matran B(m, n);
    cin >> B;

    // Tính A + B, A * B
    Matran sum = A + B;
    Matran product = A * 2; // Nhân ma trận A với 2

    // Tính S1 + S2 / (M1 - M2)
    int S1 = TongPhanTu(A);
    int S2 = TongPhanTu(B);
    int M1 = !A;
    int M2 = !B;

    double result = static_cast<double>(S1 + S2) / (M1 - M2);

    // Hiển thị kết quả
    cout << "A + B:\n" << sum << endl;
    cout << "A * 2:\n" << product << endl;
    cout << "S1 + S2 / (M1 - M2): " << result << endl;

    return 0;
}
