#include <iostream>
#include "TMatrix.hpp"
#include "TVector.hpp"

using namespace std;

// Заполняет матрицу значениями из плоского массива
template <typename T>
void fillMatrix(TMatrix<T>& m, const T* data) {
    for (size_t i = 0; i < m.getLength(); i++)
        for (size_t j = 0; j < m[0].getLength(); j++)
            m[i][j] = data[i * m[0].getLength() + j];
}

int main() {
    cout << "===== TVector =====" << endl;

    TVector<int> v1(3), v2(3);           // конструктор по умолчанию (нули)
    v1[0] = 1; v1[1] = 2; v1[2] = 3;     // operator[]
    v2[0] = 4; v2[1] = 5; v2[2] = 6;
    cout << "v1 = " << v1 << "\nv2 = " << v2 << endl;

    cout << "v1 + v2 = " << v1 + v2 << endl;
    cout << "v1 * v2 = " << v1 * v2 << "  (скалярное произведение)" << endl;
    cout << "v1 * 2  = " << v1 * 2 << endl;

    TVector<int> copy(v1);               // копирующий конструктор
    cout << "copy v1 = " << copy << ", copy == v1: " << boolalpha << (copy == v1) << endl;

    int raw[3] = {7, 8, 9};
    TVector<int> fromArr(raw, 3);        // из массива
    cout << "fromArr = " << fromArr << endl;

    TVector<int> filled(4, 5);           // заполнение значением
    cout << "filled  = " << filled << endl;

    TVector<int> moved = std::move(fromArr); // перемещающий конструктор
    cout << "moved   = " << moved << ", fromArr length = " << fromArr.getLength() << endl;

    v2 = v1;                             // operator= (копия)
    cout << "v2 = v1            -> " << v2 << ", v2 == v1: " << (v2 == v1) << endl;
    v2[0] = 100;
    v2 = std::move(copy);                // operator= (перемещение)
    cout << "v2 = move(copy)     -> " << v2 << ", copy length = " << copy.getLength() << endl;

    try {
        v1[5] = 0;                       // проверка границ
    } catch (const char* msg) {
        cout << "v1[5]            -> исключение: " << msg << endl;
    }

    cout << "\n===== TMatrix =====" << endl;

    TMatrix<int> Z(2, 3);                // нулевая матрица
    cout << "Z(2,3) = " << Z << endl;

    int aData[4] = {1, 2, 3, 4};
    int bData[4] = {5, 6, 7, 8};
    TMatrix<int> A(2, 2), B(2, 2);
    fillMatrix(A, aData);
    fillMatrix(B, bData);
    cout << "A = " << A << "\nB = " << B << endl;

    cout << "A + B = " << A + B << endl;
    cout << "A - B = " << A - B << endl;
    cout << "A * B = " << A * B << "  (матричное умножение)" << endl;
    cout << "A * 3 = " << A * 3 << endl;

    TMatrix<int> C(A);                   // копирующий конструктор
    C[0][0] = 100;
    cout << "C = copy(A), C[0][0]=100 -> " << C << endl;
    cout << "A не изменилась        -> " << A << "  (глубокая копия)" << endl;

    TMatrix<int> D(1, 1);
    D = A;                               // operator= (копия)
    cout << "D = A -> " << D << ", D == A: " << (D == A) << ", D != B: " << (D != B) << endl;

    TMatrix<int> E(1, 1);
    E = std::move(C);                    // operator= (перемещение)
    cout << "E = move(C) -> " << E << ", C length = " << C.getLength() << endl;

    TVector<TVector<int>> vecOfVec = A;  // operator TVector<TVector<T>>
    cout << "A -> TVector: " << vecOfVec << endl;
    TMatrix<int> F(vecOfVec);            // конструктор из TVector<TVector<T>>
    cout << "F (из TVector) = " << F << endl;

    try {
        A[5][0] = 0;                     // проверка границ
    } catch (const char* msg) {
        cout << "A[5][0]        -> исключение: " << msg << endl;
    }

    return 0;
}
