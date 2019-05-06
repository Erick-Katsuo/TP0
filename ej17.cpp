#include <iostream>

using namespace std;

const int MAX_LISTA = 50;
const int POSICION_EXTREMO_MINIMO = 0;

/*
 * Pre: La variable "repetidos" tiene que tener el valor correspondiente cumpliendo con el enunciado.
 * Post: Muestra por consola la cantidad de veces que se encontro el valor numerico de la variable "extremo_maximo".
*/
void mostrar_repetidos(int repetidos){
    cout<<"Se encontro "<<repetidos<<" veces repetidas el numero ingresado para el tamaño de la lista"<<endl;
}

/*
 * Pre: El arreglo lista debe ser ordenado de menor a mayor como corresponde.
 * Post: Muestra por consola el numero mayor y el numero menor.
*/
void mostrar_extremos(int extremo_minimo, int extremo_maximo){
    cout<<"El mayor numero es: "<<extremo_maximo<<endl;
    cout<<"El menor numero es: "<<extremo_minimo<<endl;
}

/*
 * Pre:-.
 * Post: El arreglo "lista" es ordenado de menor a mayor.
*/
void ordenar_lista(int lista[], int cantidad_maxima){
    int aux=-1;
    for(int i=1; i< (cantidad_maxima) ; i++){
        for(int j=0; j< (cantidad_maxima-i) ; j++){
            if(lista[j]>lista[j+1]){
                aux = lista[j];
                lista[j]=lista[j+1];
                lista[j+1]=aux;
            }
        }
    }
}

/*
 * Pre:-.
 * Post: Las variables "extremo_minimo", "extremo_maximo" y "repetidos" obtienen sus valores correspondientes segun el enunciado.
*/
void leer_lista(int &extremo_minimo, int &extremo_maximo, int &repetidos, int lista[], int cantidad_maxima){
    int veces_encontrado=0;
    for(int i = 0; i < cantidad_maxima; i++){
        if(lista[i]==cantidad_maxima){
            veces_encontrado++;
        }
        repetidos= veces_encontrado;
    }
    ordenar_lista(lista, cantidad_maxima);
    extremo_minimo = lista[POSICION_EXTREMO_MINIMO];
    extremo_maximo = lista[cantidad_maxima-1];
}

/*
 * Pre:-.
 * Post: El arreglo "Lista" adquiere numeros ingresados por consola hasta la "cantidad_maxima" ingresada.
*/
void crear_lista(int lista[], int cantidad_maxima){
    cout<<"Ingrese "<<cantidad_maxima<<" numeros"<<endl;
    for(int i=0; i<cantidad_maxima;i++){
        cout<<"Cantidad de numeros en lista = "<<i<<endl;
        cin>>lista[i];
    }
    cout<<"Cantidad de numeros en lista = "<<cantidad_maxima<<endl;
    cout<<"Lista completada"<<endl;
}

/*
 * Pre:-.
 * Post: Se obtiene el valor de la variable "cantidad_maxima" mediante consola.
*/
void pedir_cantidad_lista(int &cantidad_maxima){
    cout<<"Ingrese cantidad maxima de lista"<<endl;
    cin>>cantidad_maxima;
}

int main(){
    int cantidad_maxima=0;
    int lista[MAX_LISTA]={0};
    int extremo_mayor;
    int extremo_menor;
    int repetido;
    pedir_cantidad_lista(cantidad_maxima);
    if(cantidad_maxima>0){
        crear_lista(lista, cantidad_maxima);
        leer_lista(extremo_menor, extremo_mayor, repetido, lista, cantidad_maxima);
        mostrar_extremos(extremo_menor, extremo_mayor);
        mostrar_repetidos(repetido);
    }else{
        cout<<"Lista vacia"<<endl;
    }
    return 0;
}
