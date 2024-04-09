#include <iostream>
#include <algorithm>
using namespace std;

class MatrixTerm {
friend class SparseMatrix; 
public:
    void set(int r, int c, int v) {
        row = r;
        col = c;
        value = v;
    }
    int getRow() const { return row; }
    int getCol() const { return col; }
    int getValue() const { return value; }
private:
    int row, col, value;
};

class SparseMatrix {
public:
    SparseMatrix(int r = 0, int c = 0, int t = 0) : rows(r), cols(c), terms(0), capacity(t) {
        smArray = new MatrixTerm[capacity];
    }

    ~SparseMatrix() {
        delete[] smArray;
    }

    SparseMatrix(const SparseMatrix& rhs) : rows(rhs.rows), cols(rhs.cols), terms(rhs.terms), capacity(rhs.capacity) {
        smArray = new MatrixTerm[capacity];
        copy(rhs.smArray, rhs.smArray + terms, smArray);
    }

    SparseMatrix& operator=(const SparseMatrix& rhs) {
        if (this != &rhs) {
            delete[] smArray;
            rows = rhs.rows;
            cols = rhs.cols;
            terms = rhs.terms;
            capacity = rhs.capacity;
            smArray = new MatrixTerm[capacity];
            copy(rhs.smArray, rhs.smArray + terms, smArray);
        }
        return *this;
    }

    SparseMatrix Transpose() {
        SparseMatrix result(cols, rows, terms);
        if (terms > 0) {
            int currentB = 0;
            for (int c = 0; c < cols; c++) {
                for (int i = 0; i < terms; i++) {
                    if (smArray[i].col == c) {
                        result.smArray[currentB].row = c;
                        result.smArray[currentB].col = smArray[i].row;
                        result.smArray[currentB++].value = smArray[i].value;
                    }
                }
            }
        }
        return result;
    }

    SparseMatrix FastTranspose() {
    SparseMatrix result(cols, rows, terms);
    if (terms > 0) {
        int* rowSize = new int[cols]();
        int* rowStart = new int[cols];
        for (int i = 0; i < terms; i++) {
            rowSize[smArray[i].col]++;
        }
        rowStart[0] = 0;
        for (int i = 1; i < cols; i++) {
            rowStart[i] = rowStart[i - 1] + rowSize[i - 1];
        }
        for (int i = 0; i < terms; i++) {
            int j = rowStart[smArray[i].col];
            result.smArray[j].row = smArray[i].col;
            result.smArray[j].col = smArray[i].row;
            result.smArray[j].value = smArray[i].value;
            rowStart[smArray[i].col]++; // Correctly update rowStart after placing the term
        }
        delete[] rowSize;
        delete[] rowStart;
    }
    return result;
}


    SparseMatrix Add(SparseMatrix& b) {
        if (rows != b.rows || cols != b.cols) throw "Matrices dimensions do not match";
        SparseMatrix result(rows, cols, terms + b.terms);
        int aPos = 0, bPos = 0, count = 0;

        while (aPos < terms && bPos < b.terms) {
            int tIndex = smArray[aPos].row * cols + smArray[aPos].col;
            int bIndex = b.smArray[bPos].row * cols + b.smArray[bPos].col;
            if (tIndex < bIndex) {
                result.smArray[count++] = smArray[aPos++];
            } else if (tIndex == bIndex) {
                int addedValue = smArray[aPos].value + b.smArray[bPos].value;
                if (addedValue != 0) {
                    result.smArray[count].row = smArray[aPos].row;
                    result.smArray[count].col = smArray[aPos].col;
                    result.smArray[count++].value = addedValue;
                }
                aPos++;
                bPos++;
            } else {
                result.smArray[count++] = b.smArray[bPos++];
            }
        }

        for (; aPos < terms; aPos++) {
            result.smArray[count++] = smArray[aPos];
        }
        for (; bPos < b.terms; bPos++) {
            result.smArray[count++] = b.smArray[bPos];
        }
        result.terms = count;
        return result;
    }

    SparseMatrix Multiply(SparseMatrix b) {
    if (cols != b.rows) throw "Incompatible matrices"; // Fixed missing semicolon and quotes
    SparseMatrix bXpose = b.FastTranspose();
    SparseMatrix d(rows, b.cols, terms + b.terms); // Adjust initial capacity as needed
    
    if (terms == capacity) ChangeSize1D(terms + 1);
    bXpose.ChangeSize1D(bXpose.terms + 1);
    smArray[terms].row = rows;
    bXpose.smArray[bXpose.terms].row = b.cols;
    bXpose.smArray[bXpose.terms].col = -1;
    
    int currRowIndex = 0, currRowBegin = 0, currRowA = smArray[0].row, sum = 0;
    
    while (currRowIndex < terms) {
        int currColB = bXpose.smArray[0].row;
        int currColIndex = 0;
        
        while (currColIndex <= b.terms) {
            if (smArray[currRowIndex].row != currRowA) {
                d.StoreSum(sum, currRowA, currColB);
                sum = 0;
                currRowIndex = currRowBegin;
                while (bXpose.smArray[currColIndex].row == currColB)
                    currColIndex++;
                currColB = bXpose.smArray[currColIndex].row;
            } else if (bXpose.smArray[currColIndex].row != currColB) {
                d.StoreSum(sum, currRowA, currColB);
                sum = 0;
                currRowIndex = currRowBegin;
                currColB = bXpose.smArray[currColIndex].row;
            } else {
                if (smArray[currRowIndex].col < bXpose.smArray[currColIndex].col) {
                    currRowIndex++;
                } else if (smArray[currRowIndex].col == bXpose.smArray[currColIndex].col) {
                    sum += smArray[currRowIndex].value * bXpose.smArray[currColIndex].value;
                    currRowIndex++;
                    currColIndex++;
                } else {
                    currColIndex++;
                }
            }
        }
        
        while (currRowIndex < terms && smArray[currRowIndex].row == currRowA)
            currRowIndex++;
        currRowBegin = currRowIndex;
        currRowA = smArray[currRowIndex].row;
    }
    
    return d;
}



    void ChangeSize1D(int newSize) {
        if (newSize < terms) throw "New size must be >= number of terms";
        MatrixTerm* temp = new MatrixTerm[newSize];
        copy(smArray, smArray + terms, temp);
        delete[] smArray;
        smArray = temp;
        capacity = newSize;
    }

    void StoreSum(int sum, int r, int c) {
    if (sum != 0) {
        if (terms == capacity) ChangeSize1D(2 * capacity); // Ensure capacity
        smArray[terms].set(r, c, sum); // Use the set method
        terms++;
    }
}


    friend istream& operator>>(istream& in, SparseMatrix& matrix);
    friend ostream& operator<<(ostream& out, const SparseMatrix& matrix);

private:
    int rows, cols, terms, capacity;
    MatrixTerm* smArray;
};

istream& operator>>(istream& in, SparseMatrix& matrix) {
    cout << "Enter rows, cols, and total number of non-zero terms: ";
    in >> matrix.rows >> matrix.cols >> matrix.terms;
    if (matrix.terms > matrix.capacity) {
        matrix.ChangeSize1D(matrix.terms);
    }
    int r, c, v;
    for (int i = 0; i < matrix.terms; i++) {
        cout << "Enter row, column, and value for term " << i + 1 << ": ";
        in >> r >> c >> v;
        matrix.smArray[i].set(r, c, v); // 使用setter方法
    }
    return in;
}

ostream& operator<<(ostream& out, const SparseMatrix& matrix) {
    if (matrix.terms == 0) {
        out << "The matrix is empty or all elements are zero." << endl;
        return out;
    }
    out << "Sparse Matrix: " << endl;
    for (int i = 0; i < matrix.terms; i++) {
        out << "(" << matrix.smArray[i].getRow() << ", "
            << matrix.smArray[i].getCol() << ", "
            << matrix.smArray[i].getValue() << ")" << endl;
    }
    return out;
}



int main() {
    SparseMatrix a, b, c;
    cout << "Enter matrix A (4x3, 4 terms):\n";
    cin >> a;
    cout << "Matrix A:\n" << a;

    cout << "\nEnter matrix B (4x3, 5 terms):\n";
    cin >> b;
    cout << "Matrix B:\n" << b;

    cout << "\nEnter matrix C (3x3, 4 terms):\n";
    cin >> c;
    cout << "Matrix C:\n" << c;

    cout << "\nTranspose of A:\n" << a.Transpose();
    cout << "\nFast Transpose of A:\n" << a.FastTranspose();

    cout << "\nTranspose of B:\n" << b.Transpose();
    cout << "\nFast Transpose of B:\n" << b.FastTranspose();

    cout << "\nTranspose of C:\n" << c.Transpose();
    cout << "\nFast Transpose of C:\n" << c.FastTranspose();

    try {
        cout << "\nA + B:\n" << a.Add(b);
    } catch (const char* msg) {
        cerr << msg << endl;
    }

    try {
        cout << "\nA * C:\n" << a.Multiply(c);
    } catch (const char* msg) {
        cerr << msg << endl;
    }

    return 0;
}