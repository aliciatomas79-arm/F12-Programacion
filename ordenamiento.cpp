#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void bubbleSort(vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (v[j] > v[j + 1]) swap(v[j], v[j + 1]);
}

void selectionSort(vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (v[j] < v[min_idx]) min_idx = j;
        swap(v[i], v[min_idx]);
    }
}

void merge(vector<int>& v, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = v[l + i];
    for (int j = 0; j < n2; j++) R[j] = v[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) v[k++] = L[i++];
        else v[k++] = R[j++];
    }
    while (i < n1) v[k++] = L[i++];
    while (j < n2) v[k++] = R[j++];
}

void mergeSort(vector<int>& v, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(v, l, m);
        mergeSort(v, m + 1, r);
        merge(v, l, m, r);
    }
}

int main() {
    string algoritmo;
    int n;
    // IMPORTANTE: Leer algoritmo y luego N
    if (!(cin >> algoritmo >> n)) return 0;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    if (algoritmo == "burbuja") bubbleSort(v);
    else if (algoritmo == "seleccion") selectionSort(v);
    else if (algoritmo == "mergesort") mergeSort(v, 0, n - 1);

    // Impresión limpia: sin espacios extra al final
    for (int i = 0; i < n; i++) {
        cout << v[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}