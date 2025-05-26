#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const int N = 7;
int arr[N][N];

// Чтение из файла
void readArr(string file) {
    ifstream f(file);
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            f >> arr[i][j];
        }
    }
    f.close();
}

// Запись в файл
void writeArr(string file) {
    ofstream f(file);
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            f << arr[i][j] << " ";
        }
        f << "\n";
    }
    f.close();
}

// Сортировка подсчетом для строк
void countSort() {
    for(int i=0;i<N;i++) {
        int count[1000] = {0};
        for(int j=0;j<N;j++) {
            count[arr[i][j]]++;
        }
        int index = 0;
        for(int k=0;k<1000;k++) {
            while(count[k] > 0) {
                arr[i][index++] = k;
                count[k]--;
            }
        }
    }
}

// Гномья сортировка
void gnomeSort() {
    for(int i=0;i<N;i++) {
        int j = 0;
        while(j < N) {
            if((i%2==0 && j==0) || 
               (i%2==0 && arr[i][j] >= arr[i][j-1]) ||
               (i%2!=0 && j==0) || 
               (i%2!=0 && arr[i][j] <= arr[i][j-1])) {
                j++;
            } else {
                swap(arr[i][j], arr[i][j-1]);
                j--;
            }
        }
    }
}

// Сортировка вставками для диагоналей
void insertSortDiag() {
    for(int k=0; k<2*N-1; k++) {
        vector<int> diag;
        int row = max(0, N-1-k);
        int col = max(0, k-(N-1));
        while(row < N && col < N){
            diag.push_back(arr[row][col]);
            row++;
            col++;
        }
        // Сортировка вставками
        for(int i=1;i<diag.size();i++) {
            int key = diag[i];
            int j = i-1;
            while(j>=0 && diag[j]>key){
                diag[j+1] = diag[j];
                j--;
            }
            diag[j+1] = key;
        }
        // Обновление диагонали
        row = max(0, N-1-k);
        col = max(0, k-(N-1));
        for(auto val:diag){
            arr[row][col] = val;
            row++;
            col++;
        }
    }
}

int main(){
    string in = "inputmas.txt";
    readArr(in);
    
    cout << "1 - Сортировка подсчётом\n"    
         << "2 - Гномья сортировка\n"
         << "3 - Сортировка вставками\n";
    int choice;
    cin >> choice;
    
    switch(choice){
        case 1:
            countSort();
            writeArr("outputmas2.txt");
            break;
        case 2:
            gnomeSort();
            writeArr("outputmas10.txt");
            break;
        case 3:
            insertSortDiag();
            writeArr("outputmas15.txt");
            break;
        default:
            cout << "Уволен";
    }
    
    return 0;
}