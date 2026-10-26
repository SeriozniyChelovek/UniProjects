#include <iostream>
#include "TMatrix.hpp"
#include "TVector.hpp"

using namespace std;

template <typename T>
void fillMatrix(TMatrix<T>& m, const T* data) {
    for (size_t i = 0; i < m.getRows(); i++)
        for (size_t j = 0; j < m.getCols(); j++)
            m[i][j] = data[i * m.getCols() + j];
}

int main() {
    cout << "TVector\n" << endl;

    int v1data[3] = {1, 2, 3};

    TVector<int> v1(v1data, 3), v2(3);

    v2[0] = 4; v2[1] = 5; v2[2] = 6;
    cout << "v1 = " << v1 << "\nv2 = " << v2 << endl;

    cout << "v1 + v2 = " << v1 + v2 << endl;
    cout << "v1 * v2 = " << v1 * v2 << endl;
    cout << "v1 * 2  = " << v1 * 2 << endl;

    cout << "v2 == v1: " << (v2 == v1) << endl;

    cout << "\nTMatrix\n" << endl;

    TMatrix<int> Z(2, 3);
    cout << "Z(2,3) :\n" << Z << endl;

    int aData[4] = {1, 2, 3, 4};
    int bData[4] = {5, 6, 7, 8};
    TMatrix<int> A(2, 2), B(2, 2);
    fillMatrix(A, aData);
    fillMatrix(B, bData);
    cout << "A :\n" << A << "\n\nB :\n" << B << endl;

    cout << "A + B :\n" << A + B << endl;
    cout << "A - B :\n" << A - B << endl;
    cout << "A * B :\n" << A * B << endl;
    cout << "A * 3 :\n" << A * 3 << endl;
    cout << "A == A: " << (A == A) << endl;
    cout << "A != B: " << (A != B) << endl;

    return 0;
}
