#include <iostream>
#include <vector>

using namespace std;

class Matrix {
public:
    
    Matrix() {
        arr = new float*[height];
        for (auto i = 0; i < width; i++) {
            arr[i] = new float[width];
        }
        
        for (auto i = 0; i < height*width; i++) {
            arr[i/height][i%width] = 0;
        }
        
    }
    
    Matrix(vector<float> input) {
        arr = new float*[height];
        for (auto i = 0; i < width; i++) {
            arr[i] = new float[width];
        }
        
        for (auto i = 0; i < height*width; i++) {
            arr[i/height][i%width] = 0;
        }
        
        for (auto i = 0; i < input.size(); i++) {
            arr[i/height][i%width] = input[i];
        }
        
    }
    
    
    ~Matrix() {
        // тут пока утечка памяти
        
        
//        for (auto i = 0; i < height; i++) {
//            delete arr[i];
//        }
//        delete []arr;
    }
    
    void input(vector<float> input) {
        
        for (auto i = 0; i < input.size(); i++) {
            arr[i/height][i%width] = input[i];
        }
        
    }
    
    void print() {
        for (auto i = 0; i < height*width; i++) {
            if ( i%width == 0 ) {
                cout << endl;
            }
            cout << arr[i/height][i%width] << "\t";
        }
        cout << endl;
    }
    
    void transparent() {
        float buf;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if ( j >= i) {
                    buf = arr[i][j];
                    arr[i][j] = arr[j][i];
                    arr[j][i] = buf;
                }
            }
        }

    }
    
    void minus(float num) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                arr[i][j] -= num;
            }
        }
    }
    
    void multiply(float num) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                arr[i][j] *= num;
            }
        }
    }
    
    float& operator[] (const int index) const
    {
        return arr[index/height][index%width];
    }
    
    Matrix operator-(float num) {
        Matrix tmp = *this;
        tmp.minus(num);
        return tmp;
    }
    
    Matrix operator*(float num) {
        Matrix tmp = *this;
        tmp.multiply(num);
        return tmp;
    }
    
    Matrix& operator=(const Matrix& right) {
        if (this == &right) {
            return *this;
        }
        arr = new float*[right.height];
        for (auto i = 0; i < width; i++) {
            arr[i] = new float[right.width];
        }
        
        for (auto i = 0; i < right.height * right.width; i++) {
            arr[i/right.height][i%right.width] = 0;
        }
        
        for (int i = 0; i < right.height; i++) {
            for (int j = 0; j < right.width; j++) {
                arr[i][j] = right[i*right.height + j ];
            }
        }
        return *this;
    }
    
public:
    int width = 4;
    int height = 4;
private:
    float** arr;
    
};


int main(int argc, const char * argv[]) {
    Matrix tmp;
    vector<float> array = {1.3, 1.62, 43.0, 65.5, 654.32, 1.0,3.2, 5.4, 13.3, 5.67, 13.0, 23.5, 6.2, 1.056, 31.2, 55.4};
    
    
    tmp.input(array);
    tmp.print();
    tmp.transparent();
    tmp.print();
    Matrix tmp_for_minus_operation;
    tmp_for_minus_operation = tmp - 20;
    tmp_for_minus_operation.print();

    Matrix tmp_for_multiply_operation;
    tmp_for_multiply_operation = tmp * 2;
    tmp_for_multiply_operation.print();
    
    return 0;
}
