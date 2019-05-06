#include <iostream>

using namespace std;

const int MAXIMO_DIVISORES = 50;


/* Pre: EL valor de la variable "minimo_comun_multiplo" debe ser el correcto.
 * Post: Muestra por consola el resultado del calculo pedido.
*/
void mostrar_resultados(int maximo_comun_divisor, int minimo_comun_multiplo, int primer_numero, int segundo_numero){
    if(minimo_comun_multiplo!=0){
        cout<<"El minimo comun multiplo de "<<primer_numero<<" y "<<segundo_numero<<" es: "<<minimo_comun_multiplo<<endl;
    }else{
        cout<<"minimo comun multiplo: Error"<<endl;
    }
    if(maximo_comun_divisor==0){
        cout<<"maximo comun divisor: Error"<<endl;
    }else{
        cout<<"El maximo comun divisor de "<<primer_numero<<" y "<<segundo_numero<<" es: "<<maximo_comun_divisor<<endl;
    }
}

/* Pre: Las variables "numero_mayor" y "numero_menor" deben ser correctamente asignadas.
 * Post: Queda asignado el valor correspondiente a la variable "maximo_comun_divisor" .
*/
void revisar_divisores_comun(int numero_mayor, int numero_menor, int &maximo_comun_divisor){
    for(int i= numero_menor-1 ; i>0;i--){
        if(numero_menor%i == 0){
            if(numero_mayor%i == 0){
                maximo_comun_divisor=i;
                i=1;
            }
        }
    }
}

/* Pre:-.
 * Post: Dependiendo de los valores de "primer_numero" y "segundo numero" quedara asignado el valor
 *       correspondiente a "maximo_comun_divisor".
*/
void analizar_maximo_comun_divisor(int &maximo_comun_divisor, int primer_numero, int segundo_numero){
    if(primer_numero == segundo_numero){
        maximo_comun_divisor = primer_numero;
    }else{
        if((primer_numero > segundo_numero) && (primer_numero%segundo_numero!=0)){
            revisar_divisores_comun(primer_numero, segundo_numero, maximo_comun_divisor);
        }else if((primer_numero < segundo_numero)&& (segundo_numero%primer_numero !=0)){
            revisar_divisores_comun(segundo_numero, primer_numero, maximo_comun_divisor);
        }else if((primer_numero > segundo_numero) && (primer_numero%segundo_numero==0)){
            maximo_comun_divisor=segundo_numero;
        }else if((primer_numero < segundo_numero)&& (segundo_numero%primer_numero==0)){
            maximo_comun_divisor=primer_numero;
        }
    }
}


/* Pre: Las variables "primer_numero" y "segundo_numero" deben ser numeros enteros.
 * Post: Queda asignado el valor correspondiente a la variable "minimo_comun_multiplo"
*/
void analizar_minimo_comun_multiplo(int &minimo_comun_multiplo, int maximo_comun_divisor, int primer_numero, int segundo_numero){
    if(maximo_comun_divisor==0){
        minimo_comun_multiplo=0;
    }else{
        minimo_comun_multiplo = (primer_numero * segundo_numero )/maximo_comun_divisor;
    }
}

/* Pre: Este procedimiento solo recibira enteros mediante consola.
 * Post: Asigna valores a las dos variables "primer_numero" y "segundo numero"
*/
void pedir_numeros(int &primer_numero, int &segundo_numero, bool &valido ){
    cout<<"Ingrese dos numeros enteros distintos de cero"<<endl;
    cin>>primer_numero;
    cin>>segundo_numero;
    if((primer_numero==0) || (segundo_numero==0)){
        cout<<"Alguno de los numeros ingresados tiene valor de cero"<<endl;
        valido=false;
    }
}

int main(){
    int primer_numero;
    int segundo_numero;
    int minimo_comun_multiplo;
    int maximo_comun_divisor;
    bool valido=true;
    pedir_numeros(primer_numero, segundo_numero, valido);
    if(valido==true){
        analizar_maximo_comun_divisor(maximo_comun_divisor, primer_numero, segundo_numero);
        analizar_minimo_comun_multiplo(minimo_comun_multiplo, maximo_comun_divisor, primer_numero, segundo_numero);
        mostrar_resultados(maximo_comun_divisor, minimo_comun_multiplo, primer_numero, segundo_numero);
    }
    return 0;
}
