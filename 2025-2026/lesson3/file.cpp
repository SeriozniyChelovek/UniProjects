#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const char* ERROR_CODES[] = {
  "Программа завершилась успешно", // При отсутствии ошибок в коде - не используется
  "Неизвестная ошибка",
  "Ошибка ввода",
  "Введённая СЛУ несовместна",
  "Введённая СЛУ имеет более одного решения"
};

class Matrix {  
public:

  double** arr2d;
  int rows{0};
  int cols{0};
  
  void clear() {
    if (rows > 0) {
	  if (cols > 0) {
		for (unsigned r = 0; r < rows; r++) {
		  delete[] arr2d[r];
		}
	  }
      delete[] arr2d;
    }
    
    rows = 0;
    cols = 0;
  }
  
  int init(unsigned int inp_rows, unsigned int inp_cols) {
    
    clear();
    
    rows = inp_rows;
    cols = inp_cols;

	if ((rows <= 0) || (cols <= 0)) {
	  return 2;
	}
	
    arr2d = new double*[rows];
    for (unsigned int i = 0; i < rows; i++) {
      arr2d[i] = new double[cols];
    }
	return 0;
  }
  
  int init(string filename) {
    
    clear();
    
    ifstream file(filename);
    
    file >> rows >> cols;

	if ((rows <= 0) || (cols <= 0)) {
	  return 2;
	}
	
    arr2d = new double*[rows];
    for (unsigned int r = 0; r < rows; r++) {
      arr2d[r] = new double[cols];
      for (unsigned int c = 0; c < cols; c++) {
		file >> arr2d[r][c];
      }
    }
    file.close();
	return 0;
  }
  
  int init(Matrix matr) {
    
    clear();
    
    rows = matr.rows;
    cols = matr.cols;

	if ((rows <= 0) || (cols <= 0)) {
	  return 2;
	}
	
    arr2d = new double*[rows];
    for (unsigned int r = 0; r < rows; r++) {
      arr2d[r] = new double[cols];
      for (unsigned int c = 0; c < cols; c++) {
		arr2d[r][c] = matr.arr2d[r][c];
      }
    }
	return 0;
  }
  
  int swapr(unsigned int r1, unsigned int r2) {
    
    if ((r1 > rows - 1) || (r2 > rows - 1)) return -1;
    
    double* temp = arr2d[r1];
    arr2d[r1] = arr2d[r2];
    arr2d[r2] = temp;
    
    return 0;
  }
  
  int divider(unsigned int r, double div) {
    
    if (div == 0) return -1; // Неиспользуется. Отсутствует код ошибки
    
    for (int c = 0; c < cols - 1; c++) {
      arr2d[r][c] /= div;
    }
    
    return 0;
  }
  
  void substractr(unsigned int r1, unsigned int r2, double mult = 1) {
    
    for (int c = 0; c < cols; c++) {
      arr2d[r1][c] -= (arr2d[r2][c] * mult);
    }
  }
  
  void print() {
    
    for (unsigned int r = 0; r < rows; r++) {
      for (unsigned int c = 0; c < cols; c++) {
	cout << arr2d[r][c] << "\t";
      }
      cout << endl;
    }
  }

  int is_zero(unsigned int r) {
    // Проверяет только основную матрицу без столбца B
    static int ret = 1;
    for (unsigned int i = 0; i < cols - 1; i++) {
      if (arr2d[r][i] != 0) ret = 0;
    }
    return ret;
    
  } 
  
  int gauss_step(unsigned int row_id) {
    
    unsigned int cur_row = row_id;
    double* temp;
    
    while ((arr2d[cur_row][row_id] == 0) && (cur_row < rows - 1)) {
      cur_row++;
    }
    
    if (arr2d[cur_row][row_id] == 0) return -1;
    
    swapr(cur_row, row_id);
    
    for (cur_row = row_id + 1; cur_row < rows; cur_row++) {
      substractr(cur_row, row_id, arr2d[cur_row][row_id] / arr2d[row_id][row_id]);
    }
    
    return 0;
    
  }
};

int main() {

  int gauss_err = 0;	
  int error = 0;
  
  double* x;
  int size_x = 0;
  
  double right;
  double check;
  
  Matrix initial_matrix;	
  Matrix matrix;
  
  
  error = initial_matrix.init("input.txt");
  
  if (error) goto program_end;

  matrix.init(initial_matrix);
  
  x = new double[matrix.cols];
  size_x = matrix.cols;
  
  cout << "Изначальная матрица:" << endl;
  initial_matrix.print();
  cout << endl << "Рабочая матрица:" << endl;
  matrix.print();
	
	
  // Метод Гаусса

  for (unsigned int i = 0; i < matrix.rows; i++) {
    gauss_err -= matrix.gauss_step(i);
    cout << endl;
    cout << "Матрица на шаге номер " << i << ":" << endl;
    matrix.print();
  }

  // Вывод колличества ошибок для дебага метода Гаусса
  //cout << endl << "Кол-во пустых столбцов: " << gauss_err << endl;
  
  // Поиск корней

  // Проверка потенциально опасных строк

  for (int i = matrix.rows - 1; i > (matrix.cols - 3); i--) {
    if ((matrix.is_zero(i)) && (matrix.arr2d[i][matrix.cols - 1] != 0)) {
      error = 3;
      goto program_end;
    }
	cout << matrix.is_zero(i) << endl << matrix.arr2d[i][matrix.cols - 1] << endl;
  }
  
  // Подсчёт в строках треугольника
  for (int i = matrix.cols - 2; i >= 0; i--) {

    if (matrix.arr2d[i][i] == 0) {
      error = 4;
      goto program_end;
    }
    
    right = matrix.arr2d[i][matrix.cols - 1];
    
    for (int c = 0; c < matrix.cols - 1; c++) {
      if (c != i) {
		right -= x[c] * matrix.arr2d[i][c];
      }
    }
    
    x[i] = right / matrix.arr2d[i][i];
  }
  
  cout << "Корни уравнения в порядке возрастания номера:" << endl;
  for (int i = 0; i < size_x - 1; i++) cout << x[i] << " ";
  cout << endl;
  
  // Проверка
  
  cout << endl << "Проверка:" << endl << "Начальная матрица:" << endl;
  initial_matrix.print();
  cout << endl;
  
  cout << "Вектор B посчитанный с помощью найденых X:" << endl;
  
  for (int r = 0; r < initial_matrix.rows; r++) {
    check = 0;
    for (int c = 0; c < initial_matrix.cols; c++) {
      check += initial_matrix.arr2d[r][c] * x[c];
    }
    cout << check << endl;
  }

 program_end:

  if (error)
    cout << ERROR_CODES[error] << endl;
  
  // Очистка памяти
  initial_matrix.clear();
  matrix.clear();
  if (size_x) delete[] x;
  
  return error;
}
