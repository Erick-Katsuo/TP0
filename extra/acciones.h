#ifndef _ACCIONES_
#define _ACCIONES_

#include <iostream>
#include <fstream>
#include <sstream>

#include <cstdlib>

using namespace std;

const int MAX_PRODUCTOS = 50;
const float DESCUENTO = 10;

const int CANTIDAD_PRODUCTOS_GONDOLA_INICIAL = 0;
const int CANTIDAD_PRODUCTOS_CHANGO_INICIAL = 0;

const int CONTADOR_DATO_NOMBRE = 0;
const int CONTADOR_DATO_CODIGO_BARRAS = 1;
const int CONTADOR_DATO_PRECIO = 2;
const int CONTADOR_DATO_OFERTA = 3;
const int REINICIO_CONTADOR_DATO = -1;

const string FIN_LECTURA = "0";

const int SIN_ACCION = 0;
const int CARGAR_PRODUCTO_GONDOLA = 1;
const int BUSCAR_PRODUCTO_NOMBRE = 2;
const int BUSCAR_PRODUCTO_CODIGO = 3;
const int CONTAR_PRODUCTOS_OFERTA = 4;
const int CARGAR_PRODUCTOS_CHANGO = 5;
const int MOSTRAR_PRODUCTOS_GONDOLA = 9;

struct datos_producto{
    string nombre;
    int codigo_barra;
    float precio;
    bool oferta;
};

/*Pre: Arreglo "gondola" debe poseer productos. Variable "`posicion_producto_gondola" debe corresponder a la cantidad de productos
       actuales en el arreglo "gondola".
 *Post: Muestra por consola la informacion de los productos actuales en el arreglo "gondola".
*/
void mostrar_productos_actuales(datos_producto gondola[], int posicion_producto_gondola);

/*Pre:
 *Post: Dependiendo del valor de la variable "accion_elegida" se realizara una accion en particular, incluyendo posiblemente
 *      que se limpie la consola.
*/
void realizar_accion(datos_producto gondola[], int &posicion_producto_gondola, datos_producto chango[], int &posicion_producto_chango, int accion_elegida);

/*Pre: Archivo "productos_actuales.txt" debe existir. Variable "posicion_producto_gondola" correctamente definido.
 *Post: Carga los productos del archivo "productos_actuales.txt" al arreglo "gondola" y asigna el valor actual de productos
 *      en la variable "posicion_producto_gondola".
*/
void listar_productos_gondola(ifstream &productos_actuales, datos_producto gondola[], int &posicion_producto_gondola);



#endif /*_ACCIONES_*/
