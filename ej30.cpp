#include <iostream>

using namespace std;

const int MAX_VECTOR = 20;


/*
 * Pre: Los calculos del arreglo "vector_suma" y la variable "producto_escalar" deben cumplir con lo pedido en el ejercicio.
 * Post: Muestra por consola los resultados.
*/
void mostrar_resultados(int vector_suma[], int tope_vector, int producto_escalar){
    cout<<"El producto escalar de los dos vectores es: "<<producto_escalar<<endl;
    cout<<"Y el vector suma es: ";
    cout<<"(";
    for(int i=0; i<tope_vector; i++){
        cout<<vector_suma[i];
        if(i!=tope_vector-1){
            cout<<", ";
        }
    }
    cout<<")"<<endl;
}

/*
 * Pre:-.
 * Post: La variable "producto_escalar" queda definido como el producto escalar de los arreglos "primer_vector" y "segundo_vector".
*/
void calcular_producto_escalar(int &producto_escalar, int primer_vector[],int segundo_vector[], int tope_vector){
    for(int i=0; i<tope_vector; i++){
        producto_escalar=(primer_vector[i] * segundo_vector[i])+producto_escalar;
    }
}

/*
 * Pre:-.
 * Post: el arreglo "vector_suma" queda definido como la suma de los arreglos "primer_vector" y "segundo_vector".
*/
void calcular_vector_suma(int vector_suma[], int primer_vector[], int segundo_vector[], int tope_vector){
    for(int i=0; i<tope_vector; i++){
        vector_suma[i]=primer_vector[i]+segundo_vector[i];
    }
}

/*
 * Pre:-.
 * Post: Queda completadas las coordenadas del arreglo "vector_seleccionado".
*/
void pedir_coordenadas(int vector_seleccionado[], int tope_vector){
    for(int i=0;i<tope_vector;i++){
        cout<<"Coordenada a ingresar numero * "<<i+1<<" *  : ";
        cin>>vector_seleccionado[i];
        cout<<endl;
    }
}

/*
 * Pre:-.
 * Post: Los arreglos "primer_vector", "segundo_vector" y la variable "tope_vector" quedan definidos.
*/
void agregar_coordenadas(int primer_vector[], int segundo_vector[], int &tope_vector){
    cout<<"Ingrese la cantidad de coordenadas que desea ingresar para los dos vectores"<<endl;
    cin>>tope_vector;
    cout<<"Ingrese las coordenadas para el primer vector"<<endl<<endl;
    pedir_coordenadas(primer_vector, tope_vector);
    cout<<"Ingrese las coordenadas para el segundo vector"<<endl<<endl;
    pedir_coordenadas(segundo_vector, tope_vector);
}

int main(){
    int tope_vector=0;
    int primer_vector[MAX_VECTOR]={0};
    int segundo_vector[MAX_VECTOR]={0};
    int vector_suma[MAX_VECTOR]={0};
    int producto_escalar=0;
    agregar_coordenadas(primer_vector, segundo_vector, tope_vector);
    calcular_vector_suma(vector_suma, primer_vector, segundo_vector, tope_vector);
    calcular_producto_escalar(producto_escalar, primer_vector,segundo_vector, tope_vector);
    mostrar_resultados(vector_suma, tope_vector, producto_escalar);
    return 0;
}
