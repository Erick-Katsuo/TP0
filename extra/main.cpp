#include "acciones.h"


/*Pre:
 *Post: Muestra por consola el menu de acciones disponibles.
*/
void mostrar_menu_acciones(datos_producto gondola[], int &posicion_producto_gondola, datos_producto chango[], int &posicion_producto_chango){
    int accion_elegida = SIN_ACCION;
    do{
        cout<<"--- Menu de acciones en gondola ---"<<endl<<endl;
        cout<<"[ * <- opcion disponible]"<<endl;
        cout<<"[ - <- opcion no disponible]"<<endl<<endl;
        cout<<" * Cargar nuevo producto        [1]"<<endl;
        cout<<" * Buscar producto por nombre   [2]"<<endl;
        cout<<"   - Cambiar precio de producto [2-C]"<<endl;
        cout<<"   - Quitar precio de producto  [2-C]"<<endl;
        cout<<" * Buscar producto por codigo   [3]"<<endl;
        cout<<"   - Cambiar precio de producto [3-C]"<<endl;
        cout<<"   - Quitar precio de producto  [3-C]"<<endl;
        cout<<" * Contar productos en oferta   [4]"<<endl;
        cout<<" * Cargar productos al chango   [5]"<<endl;
        cout<<" * Mostrar productos en gondola [9]"<<endl;
        cout<<" * Salir                        [0 - cualquier letra]"<<endl;
        cin>>accion_elegida;
        realizar_accion(gondola, posicion_producto_gondola, chango, posicion_producto_chango, accion_elegida);
        cout<<endl;
    }while(accion_elegida!=SIN_ACCION);
}

int main(){
    int posicion_producto_gondola= CANTIDAD_PRODUCTOS_GONDOLA_INICIAL;
    datos_producto gondola[MAX_PRODUCTOS];
    int posicion_producto_chango= CANTIDAD_PRODUCTOS_CHANGO_INICIAL;
    datos_producto chango[MAX_PRODUCTOS];
    ifstream productos_actuales("productos_actuales.txt");
    listar_productos_gondola(productos_actuales, gondola, posicion_producto_gondola);
    productos_actuales.close();
    mostrar_productos_actuales(gondola, posicion_producto_gondola);
    mostrar_menu_acciones(gondola, posicion_producto_gondola, chango, posicion_producto_chango);
    return 0;
}




