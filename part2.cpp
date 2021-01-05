/*
    Descripción


*/

// Directivas de preprocesador
#include <iostream>
#include <cstdio>

// Declaraciones globales
using namespace std;

// Prototipos de funciones
int arrayCreation(int nR, int nC, float **m);
int showArray(int nR, int nC, float **m);
int freeMemorySpace(int nR, float **m);

int getRowsCols(int &nR, int &nC, const char *fileName);
int getArrayData(int nR, int nC, float **m, const char *fileName);

// FUNCION PRINCIPAL

int main(void) {
    // Declaración e inicialización de variables
    int nR1, nR2, nR3, nR4;
    int nC1, nC2, nC3, nC4;

    // Presentación
    cout << "\nPARTE 2: Llenar las matrices con datos leidos desde archivos\n" << endl;

    // Obtener el número de renglones y columnas correspondiente de cada archivo
    getRowsCols(nR1, nC1, "values1.txt");
    getRowsCols(nR2, nC2, "values2.txt");
    getRowsCols(nR3, nC3, "values3.txt");
    getRowsCols(nR4, nC4, "values4.txt");

    // Creación de las matrices
    float **m1 = new float*[nR1], **m2 = new float*[nR2], **m3 = new float*[nR3], **m4 = new float*[nR4];

    // Creación de las matrices dinámicas
    arrayCreation(nR1, nC1, m1);
    arrayCreation(nR2, nC2, m2);
    arrayCreation(nR3, nC3, m3);
    arrayCreation(nR4, nC4, m4);

    // Obtener los datos del arreglo y capturarlos
    getArrayData(nR1, nC1, m1, "values1.txt");
    getArrayData(nR2, nC2, m2, "values2.txt");
    getArrayData(nR3, nC3, m3, "values3.txt");
    getArrayData(nR4, nC4, m4, "values4.txt");

    // Mostrar los datos de las matrices
    cout << "\n MATRIZ DATOS 1" << endl;
    showArray(nR1, nC1, m1);
    cout << "\n MATRIZ DATOS 2" << endl;
    showArray(nR2, nC2, m2);
    cout << "\n MATRIZ DATOS 3" << endl;
    showArray(nR3, nC3, m3);
    cout << "\n MATRIZ DATOS 4" << endl;
    showArray(nR4, nC4, m4);
    cout << endl;

    // Liberación del espacio utilizado por las matrices en la memoria
    freeMemorySpace(nR1, m1);
    freeMemorySpace(nR2, m2);
    freeMemorySpace(nR3, m3);
    freeMemorySpace(nR4, m4);
    return 0;
}

// FUNCION PARA CREAR UNA MATRIZ DINAMICA

int arrayCreation(int nR, int nC, float **m) {
    for(int i = 0; i < nR; i++) m[i] = new float[nC];

    for(int i = 0; i < nR; i++)
        for(int j = 0; j < nC; j++)
            m[i][j] = -1;

    return 0;
}

// FUNCION PARA MOSTRAR LOS DATOS DE LA MATRIZ

int showArray(int nR, int nC, float **m) {
    for(int i = 0; i < nR; i++) {
        for(int j = 0; j < nC; j++)
            printf("%4.0f ", m[i][j]);
        cout << endl;
    }

    cout << endl;

    return 0;
}

// FUNCION PARA LIBERAR MEMORIA

int freeMemorySpace(int nR, float **m) {
    for (int i = 0; i < nR; i++)
        delete[] m[i];
    delete[] m;

    return 0;
}

// FUNCION PARA OBTENER EL NUMERO DE RENGLONES Y COLUMNAS QUE ESTAN EN EL ARCHIVO

int getRowsCols(int &nR, int &nC, const char *fileName) {
    FILE *file = fopen(fileName, "rt");

    if (file == NULL) {
        cout << "\nNo se pudo abrir el archivo o no existe" << endl;
        return -1;
    }

    char line[80];

    fgets(line, 80, file);
    sscanf(line, "%d", &nR);
    fgets(line, 80, file);
    sscanf(line, "%d", &nC);

    return 0;
}

// FUNCION OBTENER LOS DATOS DEL ARCHIVO Y CAPTURARLOS EN EL ARREGLO

int getArrayData(int nR, int nC, float **m, const char *fileName) {
    char line[80];
    FILE *file = fopen(fileName, "rt");

    if (file == NULL) {
        cout << "\nNo se pudo abrir el archivo o no existe" << endl;
        return -1;
    }

    fgets(line, 80, file);
    sscanf(line, "%d ", &nR);
    fgets(line, 80, file);
    sscanf(line, "%d ", &nC);

    for(int i = 0; i < nR; i++)
        for(int j = 0; j < nC; j++)
            if(fscanf(file, "%f", &m[i][j]) != 1) return -1;

    fclose(file);

    return 0;
}
