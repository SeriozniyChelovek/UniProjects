#include <iostream>
#include "TMatrix.hpp"
#include "TVector.hpp"

using namespace std;

static int failures = 0;

#define CHECK(cond, msg)                                  \
    do {                                                  \
        if (!(cond)) {                                    \
            cout << "FAIL: " << msg << endl;              \
            failures++;                                   \
        }                                                 \
    } while (0)

#define CHECK_THROW(expr)                                 \
    do {                                                  \
        bool threw = false;                               \
        try { expr; } catch (const char*) { threw = true; } \
        CHECK(threw, #expr " должен бросать исключение"); \
    } while (0)

// Заполняет матрицу i*10+j
static void fillSeq(TMatrix<int>& m) {
    for (size_t i = 0; i < m.getLength(); i++)
        for (size_t j = 0; j < m[0].getLength(); j++)
            m[i][j] = int(i * 10 + j);
}

static void testDefaultCtor() {
    TMatrix<int> m(5, 5);
    bool zeros = true;
    for (size_t i = 0; i < 5; i++)
        for (size_t j = 0; j < 5; j++)
            if (m[i][j] != 0) zeros = false;
    CHECK(zeros, "TMatrix(5,5) должен быть нулевым");

    TMatrix<int> ns(3, 4);
    bool nsOK = true;
    for (size_t i = 0; i < 3; i++)
        for (size_t j = 0; j < 4; j++)
            if (ns[i][j] != 0) nsOK = false;
    CHECK(nsOK, "TMatrix(3,4) должен быть нулевым");

    TVector<int> v(7);
    CHECK(v[0] == 0 && v[3] == 0 && v[6] == 0, "TVector(7) должен быть нулевым");

    TMatrix<int> m0(0, 0);
    CHECK(m0.getLength() == 0, "пустая матрица: length == 0");
}

static void testElementAccess() {
    TMatrix<int> m(4, 6);
    m[1][3] = 42;
    CHECK(m[1][3] == 42, "запись/чтение m[1][3]");

    const TMatrix<int>& cm = m;
    CHECK(cm[1][3] == 42, "чтение через const operator[]");
}

static void testCopyCtor() {
    TMatrix<int> a(3, 3);
    fillSeq(a);
    TMatrix<int> b(a);
    b[0][0] = 999;
    CHECK(a[0][0] == 0, "копия не должна менять оригинал (глубокая копия)");
    CHECK(b[1][2] == 12, "копирующий конструктор копирует значения");
}

static void testMoveCtor() {
    TMatrix<int> a(3, 3);
    fillSeq(a);
    TMatrix<int> b(std::move(a));
    CHECK(b[2][2] == 22, "перемещённая матрица хранит данные");
    CHECK(a.getLength() == 0, "источник после перемещения пуст");
    cout << "moved-from: " << a << endl; // безопасно: length == 0
}

static void testConvertingCtor() {
    TVector<TVector<int>> v(2, TVector<int>(3));
    v[0][0] = 1; v[0][2] = 3;
    v[1][1] = 5;
    TMatrix<int> m(v);
    CHECK(m.getLength() == 2 && m[0].getLength() == 3, "размеры из TVector");
    CHECK(m[0][0] == 1 && m[0][2] == 3 && m[1][1] == 5 && m[1][0] == 0, "значения скопированы");

    TVector<TVector<int>> empty(0);
    TMatrix<int> e(empty);
    CHECK(e.getLength() == 0, "конвертация пустого вектора");
}

static void testConversionOperator() {
    TMatrix<int> m(2, 3);
    fillSeq(m);
    TVector<TVector<int>> v = m;
    CHECK(v.getLength() == 2 && v[0].getLength() == 3, "размеры при конвертации в TVector");
    CHECK(v[1][2] == 12, "значения при конвертации в TVector");
}

static void testAssignCopy() {
    TMatrix<int> a(3, 4), b(3, 4);
    fillSeq(a);
    b = a;
    CHECK(b[2][3] == 23 && b[0][1] == 1, "operator= копирует значения");
    a[1][1] = 777;
    CHECK(b[1][1] == 11, "operator= делает глубокую копию");
    b = b; // self-assignment
    CHECK(b[1][1] == 11, "самоприсваивание безопасно");

    // присваивание матрицы другого размера
    TMatrix<int> c(2, 2);
    c[0][0] = 9; c[1][1] = 9;
    b = c;
    CHECK(b.getLength() == 2 && b[0].getLength() == 2, "operator= меняет размер");
    CHECK(b[1][1] == 9, "operator= копирует значения нового размера");
}

static void testAssignMove() {
    TMatrix<int> a(3, 3);
    fillSeq(a);
    TMatrix<int> b(1, 1);
    b = std::move(a);
    CHECK(b[2][2] == 22, "operator=(&&) перемещает данные");
    CHECK(a.getLength() == 0, "источник после перемещающего присваивания пуст");
}

static void testCompare() {
    TMatrix<int> a(2, 2), b(2, 2);
    a[1][1] = 3;
    b[1][1] = 3;
    CHECK(a == b, "operator==: одинаковые матрицы");
    CHECK(!(a != b), "operator!=: одинаковые матрицы");
    b[0][0] = 5;
    CHECK(a != b, "operator!=: разные матрицы");
    TMatrix<int> c(2, 3);
    CHECK(a != c, "разные размеры -> не равны");
    CHECK(!(a == c), "разные размеры -> не равны");
}

static void testArithmetic() {
    TMatrix<int> a(2, 3), b(2, 3);
    fillSeq(a);              // 0..12
    b[0][0] = 1; b[1][2] = 2;
    TMatrix<int> s = a + b;
    CHECK(s[0][0] == 1 && s[1][2] == 14 && s[0][1] == 1, "operator+ поэлементно");

    TMatrix<int> d = a - b;
    CHECK(d[0][0] == -1 && d[1][2] == 10 && d[0][2] == 2, "operator- поэлементно");

    TMatrix<int> sc = a * 2;
    CHECK(sc[1][2] == 24 && sc[0][0] == 0, "operator*(скаляр)");

    // матричное умножение: [[1,2],[3,4]] * [[5,6],[7,8]] = [[19,22],[43,50]]
    TMatrix<int> m1(2, 2), m2(2, 2);
    m1[0][0] = 1; m1[0][1] = 2; m1[1][0] = 3; m1[1][1] = 4;
    m2[0][0] = 5; m2[0][1] = 6; m2[1][0] = 7; m2[1][1] = 8;
    TMatrix<int> r = m1 * m2;
    CHECK(r[0][0] == 19 && r[0][1] == 22 && r[1][0] == 43 && r[1][1] == 50,
          "operator*(матрица) — матричное умножение");

    // прямоугольное: (2x3)*(3x2)
    TMatrix<int> p(2, 3), q(3, 2);
    p[0][0] = 1; p[0][1] = 2; p[0][2] = 3;
    p[1][0] = 4; p[1][1] = 5; p[1][2] = 6;
    q[0][0] = 7; q[0][1] = 8;
    q[1][0] = 9; q[1][1] = 10;
    q[2][0] = 11; q[2][1] = 12;
    TMatrix<int> pq = p * q; // [[58,64],[139,154]]
    CHECK(pq.getLength() == 2 && pq[0].getLength() == 2, "размер произведения (2x3)*(3x2)");
    CHECK(pq[0][0] == 58 && pq[0][1] == 64 && pq[1][0] == 139 && pq[1][1] == 154,
          "умножение прямоугольных матриц");

    // несовместимые размеры
    TMatrix<int> bad1(2, 3), bad2(2, 3);
    CHECK_THROW(TMatrix<int> x = bad1 * bad2);
    TMatrix<int> odd1(2, 3), odd2(2, 4);
    CHECK_THROW(TMatrix<int> x = odd1 + odd2);
    CHECK_THROW(TMatrix<int> x = odd1 - odd2);
}

static void testMainScenario() {
    TMatrix<int> matr1(5, 5), matr2(5, 5), matr3(5, 5);
    matr1[1][3] = 5;
    matr3 = matr1 + matr2;
    CHECK(matr3[1][3] == 5, "сценарий из main.cpp: matr3[1][3] == 5");
    CHECK(matr3[0][0] == 0 && matr3[4][4] == 0, "остальные нули");
}

static void testIndexThrow() {
    TMatrix<int> m(2, 3);
    CHECK_THROW(m[2]);
    CHECK_THROW(m[0][3]);
    const TMatrix<int>& cm = m;
    CHECK_THROW(cm[0][3]);
}

static void testVectorOps() {
    TVector<int> v1(3), v2(3);
    v1[0] = 1; v1[1] = 2; v1[2] = 3;
    v2[0] = 4; v2[1] = 5; v2[2] = 6;
    TVector<int> s = v1 + v2;
    CHECK(s[0] == 5 && s[1] == 7 && s[2] == 9, "TVector operator+");
    CHECK(v1 * v2 == 32, "TVector скалярное произведение");
    CHECK((v1 * 2)[2] == 6, "TVector operator*(скаляр)");
    CHECK(v1 == TVector<int>(v1), "TVector operator==");
    CHECK(!(v1 == v2), "TVector operator== разные");

    TVector<int> mv(3);
    mv[0] = 9;
    TVector<int> stolen = std::move(mv);
    CHECK(stolen[0] == 9 && mv.getLength() == 0, "TVector move-семантика");

    TVector<int> self(2);
    self[0] = 1; self[1] = 2;
    self = self;
    CHECK(self[0] == 1 && self[1] == 2, "TVector самоприсваивание безопасно");
}

int main() {
    testDefaultCtor();
    testElementAccess();
    testCopyCtor();
    testMoveCtor();
    testConvertingCtor();
    testConversionOperator();
    testAssignCopy();
    testAssignMove();
    testCompare();
    testArithmetic();
    testMainScenario();
    testIndexThrow();
    testVectorOps();

    if (failures == 0) {
        cout << "ALL TESTS PASSED" << endl;
        return 0;
    }
    cout << failures << " TEST(S) FAILED" << endl;
    return 1;
}
