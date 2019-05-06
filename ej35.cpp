
#include <iostream>

using namespace std;

const int MAX_FILA = 7;
const int MAX_COLUMNA = 7;

void mostrar_matriz_suma(int matriz_suma[][MAX_COLUMNA], int tope_fila, int tope_columna){
    for(int i=0; i< tope_fila; i++){
        for(int j=0;j < tope_columna; j++){
            cout<<matriz_suma[i][j]<<" ";
        }
        cout<<endl;
    }
}

void sumar_matrices(int primer_matriz[][MAX_COLUMNA], int segunda_matriz[][MAX_COLUMNA], int matriz_suma[][MAX_COLUMNA], int tope_fila, int tope_columna){
    for(int i=0; i< tope_fila; i++){
        for(int j=0;j < tope_columna; j++){
            cout<<"Sumando coordenadas en posicion ("<<i+1<<", "<<j+1<<") : ";
            cout<<primer_matriz[i][j]<<" + "<<segunda_matriz[i][j]<<endl;
            matriz_suma[i][j]=primer_matriz[i][j]+segunda_matriz[i][j];
        }
    }
    cout<<endl;
}

void agregar_coordenadas_matriz(int matriz_seleccionada[][MAX_COLUMNA], int tope_fila, int tope_columna){
    for(int i=0; i< tope_fila; i++){
        for(int j=0;j < tope_columna; j++){
            cout<<"Ingresando coordenada a la matriz en ("<<i+1<<", "<<j+1<<") : ";
            cin>>matriz_seleccionada[i][j];
        }
    }
    cout<<endl;
}

void crear_matrices(int primer_matriz[][MAX_COLUMNA], int segunda_matriz[][MAX_COLUMNA], int &tope_fila, int &tope_columna){
    cout<<"ingrese la cantidad de filas y columnas para las matrices a crear"<<endl<<"Ingrese fila: ";
    cin>>tope_fila;
    cout<<"Ingrese columna: ";
    cin>>tope_columna;
    cout<<"Agregando coordenadas a la primer matriz"<<endl;
    agregar_coordenadas_matriz(primer_matriz, tope_fila, tope_columna);
    cout<<"Agregando coordenadas a la segunda matriz"<<endl;
    agregar_coordenadas_matriz(segunda_matriz, tope_fila, tope_columna);
}

int main(){
    int primer_matriz[MAX_FILA][MAX_COLUMNA];
    int segunda_matriz[MAX_FILA][MAX_COLUMNA];
    int matriz_suma[MAX_FILA][MAX_COLUMNA];

    int tope_fila=0;
    int tope_columna=0;

    crear_matrices(primer_matriz, segunda_matriz, tope_fila, tope_columna);
    sumar_matrices(primer_matriz, segunda_matriz, matriz_suma, tope_fila, tope_columna);
    mostrar_matriz_suma(matriz_suma, tope_fila, tope_columna);

    return 0;
}
