//Дано множество точек на плоскости. Определить сколько точек находятся внутри треугольника с координатами вершин A(Xa, Ya), B(Хb, Yb), C(Xc, Yc)

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

struct point {
    double x, y;
};

double area (point a, point b, point c){
    return (0.5 * abs((b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y)));
}


point *create(int n){
    point *a = new point [n];
    for(int i = 0; i < n; i++){
        cout << "Введите координаты " << i + 1 << " точки (x, y): \n";
        cin >> a[i].x >> a[i].y;
    }
    return a;
}


int count_t(point *mas, point *tr, int n){
    int k = 0;
    point A = tr[0];
    point B = tr[1];
    point C = tr[2];
    double S1 = area(A, B, C);

    for(int i = 0; i < n; i++){
        point D = mas[i];
        double S2 = area(D, A, B);
        double S3 = area(D, B, C);
        double S4 = area(D, A, C);
        if (S1 == S2+S3+S4) k++;
    }
    return k;
}

int main(){
    setlocale(LC_ALL, "RUS");

    int n;
    cout << "Введите количество точек\n";
    cin >> n;
    point *mas = create(n); 

    int t = 3;
    cout << "Введите координаты треугольника\n";
    point *tr = create(t);
    cout << count_t(mas, tr, n) << endl;
    return 0;
}

/*
Входные данные: p = (0, 0), q = (0, 5) и r = (5,0) - треугольник
Объяснение: Точки (1,1) (1,2) (1,3) (2,1) (2,2) и (3,1) являются целыми точками внутри треугольника. 
                       (8,50) - не в треуголнике
*/