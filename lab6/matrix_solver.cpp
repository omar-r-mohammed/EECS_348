
#include <iostream> 
#include <fstream>
using namespace std;


const int MAX_SIZE = 100;
int output[MAX_SIZE][MAX_SIZE];
const char * filename = "matrix_input.txt";
ifstream file(filename);
int matrixA[MAX_SIZE][MAX_SIZE];
int matrixB[MAX_SIZE][MAX_SIZE];
int size;


int * addition(int one[MAX_SIZE][MAX_SIZE], int two[MAX_SIZE][MAX_SIZE], int size){
    for (int i =0; i<size; i++){
        for (int j=0;j<size;j++){
            output[i][j] = one[i][j] + two[i][j];
        }
    }
    return *output;
}

int * subtraction(int one[MAX_SIZE][MAX_SIZE], int two[MAX_SIZE][MAX_SIZE], int size){
    for (int i=0; i<size;i++){
        for (int j=0; j<size; j++){
            output[i][j] = (int)one[i][j] - (int)two[i][j];
        }
    }
    return *output;
}

int * multiply(int one[MAX_SIZE][MAX_SIZE], int two[MAX_SIZE][MAX_SIZE],int size){
    for (int i=0; i<size;i++){
        for (int j=0; j<size;j++){
            output[i][j]= 0;
            for(int k=0; k<size; k++){
                output[i][j]+= one[i][k] * two[k][j];
            }
        }
    }
    return *output;
}
// Function to read data from a file and store it in a 2D array
void  read(int matrix[MAX_SIZE][MAX_SIZE], int &size){
    file >> size;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            file >> matrixA[i][j];
        }
    }
    for (int i=0; i<size; ++i){
        for (int j =0; j<size; ++j){
            file >> matrixB[i][j];
        }
    }
}

// Function to display a matrix with nicely aligned columns
void display(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i <size; ++i){
        for (int j = 0; j < size; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    read(matrixA, size);
    read(matrixB, size);
    
    file.close();
    cout << "Omar Mohammed" << endl;
    cout << "Lab #6: Matrix manipulation\n" <<endl;

    cout << "Matrix A:" << endl;
    display(matrixA, size);

    cout << "\nMatrix B:" << endl;
    display(matrixB, size);

    cout << "\nMatrix Sum (A+B):"<<endl;
    addition(matrixA,matrixB,size);
    display(output,size);

    cout << "\nMatrix Product (A*B):" <<endl;
    multiply(matrixA,matrixB,size);
    display(output,size);

    cout << "\nMatrix Difference (A-B):" <<endl;
    subtraction(matrixA,matrixB,size);
    display(output,size);

    return 0;
}