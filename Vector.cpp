#include "Vector.h"

// Генерація простих дробових чисел
vector<double> generateVector(int size) {
    vector<double> v(size);
    for (size_t i = 0; i < size; i++) v[i] = (i * 37 % 100) / 10.0;
    return v;
}

// Групування по n
vector<double> groupSums(const vector<double>& v, int n) {
    vector<double> sums;
    for (size_t i = 0; i < v.size(); i += n) {
        double s = 0;
        for (size_t j = 0; j < n && i + j < v.size(); j++) s += v[i + j];
        sums.push_back(s);
    }
    return sums;
}

// Сума елементів вектора
double sumVector(const vector<double>& v) {
    double s = 0;
    for (double x : v) s += x;
    return s;
}

// Видалення повторів
vector<double> removeDuplicates(const vector<double>& v, int& repeatCount) {
    vector<double> unique;
    repeatCount = 0;
    for (double x : v) {
        bool found = false;
        for (double y : unique) if (x == y) found = true;
        if (found) repeatCount++;
        else unique.push_back(x);
    }
    return unique;
}

// Сортування ASC (selection sort)
void sortASC(vector<double>& v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[min_idx]) min_idx = j;
        }
        if (min_idx != i) { double t = v[i]; v[i] = v[min_idx]; v[min_idx] = t; }
    }
}

// Сортування DESC
void sortDESC(vector<double>& v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] > v[max_idx]) max_idx = j;
        }
        if (max_idx != i) { double t = v[i]; v[i] = v[max_idx]; v[max_idx] = t; }
    }
}

// Група з максимальною сумою
vector<double> maxGroup(const vector<double>& v, int n) {
    double maxSum = -1e9;
    vector<double> best;
    for (size_t i = 0; i < v.size(); i += n) {
        double s = 0;
        vector<double> temp;
        for (size_t j = 0; j < n && i + j < v.size(); j++) {
            s += v[i + j];
            temp.push_back(v[i + j]);
        }
        if (s > maxSum) {
            maxSum = s;
            best = temp;
        }
    }
    return best;
}