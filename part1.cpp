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
// 1)
int setRandomData(int nR, int nC, float **m);
int setAverageRow(int nR, int nC, float **m);
int setMaxRow(int nR, int nC, float **m);
int setAverageOfAverageAndMaxRow(int nR, int nC, float **m);
// 2)
int compareArray(int nR, int nC, float **m1, float **m2, float **comparison);
// 3)
int setSumRow(int nR, int nC, float **m);
int setIndexZero(int nR, int nC, float **m);
// 4)
int writeFile(int nR, int nC, float **m, int nM, const char *fileName);

// FUNCION PRINCIPAL

int main(void) {
    // Declaración e inicialización de variables
    int nR = 32;
    int nC = ((nR * 2) + 1);
    float **m1 = new float*[nR], **m2 = new float*[nR], **m3 = new float*[nR], **m4 = new float*[nR];
    float **m12 = new float*[nR], **m13 = new float*[nR], **m14 = new float*[nR], **m23 = new float*[nR], **m24 = new float*[nR], **m34 = new float*[nR];

    // Presentación
    cout << "\nPARTE 1: Matrices con datos aleatorios\n" << endl;

    // Creación de las matrices dinámicas
    arrayCreation(nR, nC, m1);
    arrayCreation(nR, nC, m2);
    arrayCreation(nR, nC, m3);
    arrayCreation(nR, nC, m4);
    // Asignación de valores aleatorios a las matrices
    setRandomData(nR, (nC - (nR + 1)), m1);
    setRandomData(nR, (nC - (nR + 1)), m2);
    setRandomData(nR, (nC - (nR + 1)), m3);
    setRandomData(nR, (nC - (nR + 1)), m4);
    // Calcular el promedio de los datos por renglon
    setAverageRow(nR, nC, m1);
    setAverageRow(nR, nC, m2);
    setAverageRow(nR, nC, m3);
    setAverageRow(nR, nC, m4);
    // Calcular el número mayor de los datos por renglon
    setMaxRow(nR, nC, m1);
    setMaxRow(nR, nC, m2);
    setMaxRow(nR, nC, m3);
    setMaxRow(nR, nC, m4);
    // Calcular el promedio de la suma del promedio por renglón y el máximo
    setAverageOfAverageAndMaxRow(nR, nC, m1);
    setAverageOfAverageAndMaxRow(nR, nC, m2);
    setAverageOfAverageAndMaxRow(nR, nC, m3);
    setAverageOfAverageAndMaxRow(nR, nC, m4);
    // Mostrar los datos de las matrices
    cout << "\n MATRIZ 1" << endl;
    showArray(nR, (nC - (nR + 1)), m1);
    cout << "\n MATRIZ 2" << endl;
    showArray(nR, (nC - (nR + 1)), m2);
    cout << "\n MATRIZ 3" << endl;
    showArray(nR, (nC - (nR + 1)), m3);
    cout << "\n MATRIZ 4" << endl;
    showArray(nR, (nC - (nR + 1)), m4);
    cout << endl;

    // Creación de las matrices dinámicas
    arrayCreation(nR, nC, m12);
    arrayCreation(nR, nC, m13);
    arrayCreation(nR, nC, m14);
    arrayCreation(nR, nC, m23);
    arrayCreation(nR, nC, m24);
    arrayCreation(nR, nC, m34);

    // Comparación de las matrices
    // 1 y 2
    compareArray(nR, nC, m1, m2, m12);
    // 1 y 3
    compareArray(nR, nC, m1, m3, m13);
    // 1 y 4
    compareArray(nR, nC, m1, m4, m14);
    // 2 y 3
    compareArray(nR, nC, m2, m3, m23);
    // 2 y 4
    compareArray(nR, nC, m2, m4, m24);
    // 3 y 4
    compareArray(nR, nC, m3, m4, m34);

    // Calcular la suma de los datos por renglón
    setSumRow(nR, nC, m12);
    setSumRow(nR, nC, m13);
    setSumRow(nR, nC, m14);
    setSumRow(nR, nC, m23);
    setSumRow(nR, nC, m24);
    setSumRow(nR, nC, m34);
    // Calcular los índices donde haya ceros
    setIndexZero(nR, nC, m12);
    setIndexZero(nR, nC, m13);
    setIndexZero(nR, nC, m14);
    setIndexZero(nR, nC, m23);
    setIndexZero(nR, nC, m24);
    setIndexZero(nR, nC, m34);

    // Mostrar los datos de las matrices comparativas
    cout << "\n COMPARACION DE MATRICES 1 Y 2" << endl;
    showArray(nR, nC, m12);
    cout << "\n COMPARACION DE MATRICES 1 Y 3" << endl;
    showArray(nR, nC, m13);
    cout << "\n COMPARACION DE MATRICES 1 Y 4" << endl;
    showArray(nR, nC, m14);
    cout << "\n COMPARACION DE MATRICES 2 Y 3" << endl;
    showArray(nR, nC, m23);
    cout << "\n COMPARACION DE MATRICES 2 Y 4" << endl;
    showArray(nR, nC, m24);
    cout << "\n COMPARACION DE MATRICES 3 Y 4" << endl;
    showArray(nR, nC, m34);
    cout << endl;

    // Guardar en un archivo las comparativas
    writeFile(nR, nC, m12, 1, "results.txt");
    writeFile(nR, nC, m13, 2, "results.txt");
    writeFile(nR, nC, m14, 3, "results.txt");
    writeFile(nR, nC, m23, 4, "results.txt");
    writeFile(nR, nC, m24, 5, "results.txt");
    writeFile(nR, nC, m34, 6, "results.txt");

    // Liberación del espacio utilizado por las matrices en la memoria
    freeMemorySpace(nR, m1);
    freeMemorySpace(nR, m2);
    freeMemorySpace(nR, m3);
    freeMemorySpace(nR, m4);
    freeMemorySpace(nR, m12);
    freeMemorySpace(nR, m13);
    freeMemorySpace(nR, m14);
    freeMemorySpace(nR, m23);
    freeMemorySpace(nR, m24);
    freeMemorySpace(nR, m34);
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
    int countColumnZero = 0, aux = 0;

    for(int j = 0; j < nC; j++) {
        for(int i = 0; i < nR; i++) {
            if(m[i][j] == -1) aux++;
        }

        if(aux == 5) countColumnZero++;
        aux = 0;
    }

    nC -= countColumnZero;

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

// FUNCION PARA ASIGNAR VALORES ALEATORIOS A LA MATRIZ

int setRandomData(int nR, int nC, float **m) {
    for (int i = 0; i < nR; i++)
        for (int j = 0; j < nC; j++)
            m[i][j] = rand() % 10;

    return 0;
}

// FUNCION PARA CALCULAR EL PROMEDIO POR RENGLON

int setAverageRow(int nR, int nC, float **m) {
    float averageRow;

    for(int i = 0; i < nR; i++) {
        for(int j = 0; j < (nC - 6); j++)
            averageRow += m[i][j];

        averageRow /= nR;
        m[i][(nC - 6)] = averageRow;
        averageRow = 0;
    }

    return 0;
}

// FUNCION PARA CALCULAR EL NUMERO MAXIMO POR RENGLON

int setMaxRow(int nR, int nC, float **m) {
    float maxRow;

    for(int i = 0; i < nR; i++) {
        maxRow = m[i][(nC - 6)];

        for(int j = 0; j < (nC - 6); j++)
            if(m[i][j] > maxRow)
                maxRow = m[i][j];

        m[i][(nC - 5)] = maxRow;
        maxRow = 0;
    }

    return 0;
}

// FUNCION PARA CALCULAR EL PROMEDIO DE LA SUMA DEL PROMEDIO Y EL MAXIMO POR RENGLON

int setAverageOfAverageAndMaxRow(int nR, int nC, float **m) {
    float averageAMRow;

    for(int i = 0; i < nR; i++) {
        for(int j = (nC - 6); j < (nC - 4); j++)
            averageAMRow += m[i][j];

        averageAMRow /= 2;
        m[i][(nC - 4)] = averageAMRow;
        averageAMRow = 0;
    }

    return 0;
}

// FUNCION PARA COMPARAR DOS MATRICES

int compareArray(int nR, int nC, float **m1, float **m2, float **comparison) {
    for(int i = 0; i < nR; i++)
        for(int j = 0; j < (nC - 6); j++) {
            if(m1[i][j] != 0 && m2[i][j] != 0) comparison[i][j] = 1;
            else comparison[i][j] = 0;
        }

    return 0;
}

// FUNCION PARA OBTENER LA SUMA DE LOS DATOS POR RENGLON

int setSumRow(int nR, int nC, float **m) {
    float addition;

    for(int i = 0; i < nR; i++) {
        for(int j = 0; j < (nC - 6); j++)
            addition += m[i][j];

        m[i][(nC - 6)] = addition;
        addition = 0;
    }

    return 0;
}

// FUNCION PARA OBTENER EL INDICE DE COLUMNA DONDE SEA IGUAL A CERO

int setIndexZero(int nR, int nC, float **m) {
    int aux = 5;

    for(int i = 0; i < nR; i++) {
        for(int j = 0; j < (nC - 6); j++)
            if(m[i][j] == 0) {
                m[i][(nC - aux)] = j;
                aux--;
            }

        aux = 5;
    }

    return 0;
}

// FUNCION PARA ESCRIBIR Y GUARDAR LAS MATRICES EN UN ARCHIVO

int writeFile(int nR, int nC, float **m, int nM, const char *fileName) {
    int countColumnZero = 0, aux = 0;
    FILE *file;

    file = fopen(fileName, "at");
    if (file == NULL) {
        printf("\nHubo un error al escribir en el archivo");
        return -1;
    }

    for(int j = 0; j < nC; j++) {
        for(int i = 0; i < nR; i++) {
            if(m[i][j] == -1) aux++;
        }

        if(aux == 5) countColumnZero++;
        aux = 0;
    }

    nC -= countColumnZero;

    fprintf(file, "Matriz resultante de comparación %d.\n\n", nM);

    for(int i = 0; i < nR; i++) {
        for(int j = 0; j < nC; j++)
            fprintf(file, "%4.0f ", m[i][j]);

        fprintf(file, "\n");
    }

    fprintf(file, "\n\n");

    fclose(file);

    return 0;
}
