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
        for (auto i = 0; i < height; i++) {
            delete arr[i];
        }
        delete []arr;
    }
    
    void input(vector<float> input) {
        
        for (auto i = 0; i < input.size(); i++) {
            arr[i/height][i%width] = input[i];
        }
        
    }
    
    void print() {
        for (auto i = 0; i < height*width; i++) {
            cout << arr[i/height][i%width] << "\t";
        }
        cout << endl;
    }
    
private:
    float** arr;
    int width = 4;
    int height = 4;
    
};


int main(int argc, const char * argv[]) {
    Matrix tmp;
    vector<float> array = {
        1.3, 1.62, 43.0, 65.5,
        654.32, 1.0, 3.2, 5.4,
        13.3, 5.67, 13.0, 23.5,
        6.2, 1.056, 31.2, 55.4
    };
    
    
    tmp.input(array);
    tmp.print();
    
    return 0;
}
