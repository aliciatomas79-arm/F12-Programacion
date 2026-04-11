/// Implementa el algoritmo de ordenamiento "Bubble Sort" para ordenar un vector de enteros en orden ascendente.
#include <iostream>
#include <vector>
#include <string>
void bubbleSort(std::vector<int>& v) {
    int n = v.size();
    bool intercambiado; // variable para verificar si se realizó un intercambio en la interacción actual 
    for (int paso = 0; paso < n-1; paso++) {
            intercambiado = false; // reiniciar la variable para cada paso
        for (int i = 0; i < n - paso - 1; i++) {
            if (v[i] > v[i + 1]) {
                int temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp ;
                intercambiado = true; // se realizó un intercambio
            }
        }
        // si no se realizó ningún intercambio, el vector ya está ordenado
        if ( !intercambiado) break;
    }
 }


 // ordenamiento por selección (palabra clave seleccion)
 void selectionSort(std::vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // índice del elemento mínimo
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v [minIndex]) {
                minIndex = j; // actualizar el índice del elemento mínimo
            }
        }
        // intercambiar el elemento en la posición i con el elemento mínimo
        int temp = v[i];
        v[i] = v[minIndex];
        v[minIndex] = temp;
    }
 }

 // Merge Sort (Ordenamieno por Fusión) (palabra clave merge)
    void merge(std::vector<int>& v, int inicio, int medio, int fin) {
        int n1 = medio - inicio + 1; // tamaño de la sublista izquierda
        int n2 = fin -medio; // tamaño de la sublista derecha

        std::vector<int> izquierda(n1), derecha(n2); // crear sublistas
        
        for (int i = 0; i < n1; i++)  izquierda[i] = v[inicio + i];
        
        for (int j = 0; j < n2; j++)  derecha[j] = v[medio + 1 + j];
        
        int i = 0, j = 0, k = inicio; // índice para izquierda, derecha y listas original
        while (i < n1 && j < n2) {
            if (izquierda[i] <= derecha {j]) {
                v[k] = izquierda[i];
                i++; 
            } else {
                v[k] = derecha[j];
                j++; 
            }
            k++;
        }
        
        while (i < n1) {
            v[k] = izquierda[i];
            i++;
            k++;
        while (j < n2) {
            v[k] = derecha[j];
            j++;
            k++;
        }
        
        void mergeSort(std::vector<int>& v, int inicio, int fin) {
            if (inicio < fin) {
                int medio = inicio + (fin - inicio) / 2; // encontrar el punto medio
                mergeSort(v, inicio, medio); // ordenar la sublista izquierda
                mergeSort(v, medio + 1, fin); // ordenar la sublista derecha
                merge(v, inicio, medio, fin); // fusionar las sublistas ordanadas)}
            }
        }


int main() {
    std::string algoritmo; // Nombre corregido
    int n;

    // 1. Leer el nombre del algoritmo y la cantidad de elementos
    if (!(std::cin >> algoritmo >> n)) return 0; 

    // 2. Leer los n números
    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    // 3. Selección del algoritmo con las palabras clave correctas
    if (algoritmo == "burbuja") {
        bubbleSort(v);
    } else if (algoritmo == "seleccion") {
        selectionSort(v);
    } else if (algoritmo == "mergesort") {
        mergeSort(v, 0, n - 1); // Asegúrate de pasar los índices inicio y fin
    }

    // 4. Salida en una sola línea separada por espacios
    for (int i = 0; i < n; i++) {
        std::cout << v[i] << (i == n - 1 ? "" : " ");
    }
    std::cout << std::endl; // Salto de línea final para el autograder

    return 0;
}