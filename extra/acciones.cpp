#include "acciones.h"

/*Pre: El valor de la variable "posicion_buscada" tiene que ser el correcto.
 *Post: Muesra por consola el producto buscado de forma individual.
*/
void mostrar_producto_individual(datos_producto gondola[], int posicion_buscada){
    cout<<"Nombre: "<<gondola[posicion_buscada].nombre<<endl;
    cout<<"Codigo de barras: "<<gondola[posicion_buscada].codigo_barra<<endl;
    cout<<"Precio: $ "<<gondola[posicion_buscada].precio<<endl;
    cout<<"Oferta: ";
    if(gondola[posicion_buscada].oferta==true){
        cout<<"En oferta!"<<endl;
    }else{
        cout<<"nop :("<<endl;
    }
    cout<<endl;
}

/*Pre: El arreglo chango debe estar correctamente definido.
 *Post: Imprime por pantalla el costo con oferta y el ahorro obtenido.
*/
void calcular_costo_productos(datos_producto chango[], int posicion_producto_chango){
    float costo_sin_oferta=0;
    float costo_oferta=0;
    float ahorro=0;
    for(int i =0; i < posicion_producto_chango+1; i++){
        costo_sin_oferta+= chango[i].precio;
        if(chango[i].oferta==true){
            costo_oferta+= (chango[i].precio)-(chango[i].precio/DESCUENTO);
        }else{
            costo_oferta+= chango[i].precio;
        }
    }
    ahorro = costo_sin_oferta - costo_oferta;
    cout<<"Costo total: $ "<<costo_oferta<<endl;
    cout<<"Ahorro:      $ "<<ahorro<<endl;
}

/*Pre:
 *Post: El arreglo chango quedara creado con los mismos productos que el arreglo "gondola".
*/
void crear_chango(datos_producto gondola[], int posicion_producto_gondola, datos_producto chango[], int &posicion_producto_chango){
    posicion_producto_chango = posicion_producto_gondola;
    for(int i =0; i < posicion_producto_chango+1; i++){
        chango[i].nombre =gondola[i].nombre ;
        chango[i].codigo_barra =gondola[i].codigo_barra ;
        chango[i].precio =gondola[i].precio ;
        chango[i].oferta =gondola[i].oferta  ;
    }
    cout<<"* Chango cargado! *"<<endl;
    calcular_costo_productos(chango, posicion_producto_chango);
}

void mostrar_productos_actuales(datos_producto gondola[], int posicion_producto_gondola){
    cout<<"------- Productos actuales en gondola -------"<<endl<<endl;
    for(int i=0; i < posicion_producto_gondola+1; i++){
        mostrar_producto_individual(gondola, i);
    }
}

/*Pre:
 *Post: Asigna el valor true al bool "encontrado" y procede a mostrar el producto encontrado.
*/
void producto_individual_encontrado(datos_producto gondola[], int posicion_buscada, bool &encontrado){
    encontrado=true;
    mostrar_producto_individual(gondola, posicion_buscada);
}

/*Pre:
 *Post: Elimina un producto del arreglo gondola.
*/
void quitar_producto_gondola(datos_producto gondola[], int &posicion_producto_gondola, int posicion_buscada){
    cout<<"Producto: "<<gondola[posicion_buscada].nombre<<" removido."<<endl<<endl;
    for(int i =posicion_buscada; i<posicion_producto_gondola+1; i++){
        gondola[i].nombre = gondola[i+1].nombre;
        gondola[i].codigo_barra = gondola[i+1].codigo_barra ;
        gondola[i].precio = gondola[i+1].precio;
        gondola[i].oferta = gondola[i+1].oferta;
    }
    posicion_producto_gondola--;
}

/*Pre:
 *Post: Se actualizara el dato "precio" al producto deseado.
*/
void cambiar_precio_producto(datos_producto gondola[], int posicion_buscada){
    cout<<"Ingrese nuevo precio para "<<gondola[posicion_buscada].nombre<<": "<<endl;
    cin>>gondola[posicion_buscada].precio;
    system("cls");
    cout<<"Precio actual de "<<gondola[posicion_buscada].nombre<<" es: $ "<<gondola[posicion_buscada].precio<<endl;
}

/*Pre:
 *Post: Mostrara las opciones disponibles a realizar con el producto.
*/
void opciones_modificar_producto(datos_producto gondola[], int &posicion_producto_gondola, int posicion_buscada){
    char sub_menu;
    cout<<" --- Sub Menu ---"<<endl;
    cout<<" * Cambiar el precio de este producto [C]"<<endl;
    cout<<" * Quitar el producto                 [Q]"<<endl;
    cout<<" * Regresar al Menu                   [x]"<<endl;
    cin>>sub_menu;
        if(sub_menu == 'C'){
            cambiar_precio_producto(gondola, posicion_buscada);
        }else if(sub_menu == 'Q'){
            system("cls");
            quitar_producto_gondola(gondola, posicion_producto_gondola, posicion_buscada);
        }else if(sub_menu == 'x'){
            system("cls");
        }else{
            system("cls");
            cout<<"Ingreso no valido"<<endl<<endl;
            opciones_modificar_producto(gondola,posicion_producto_gondola, posicion_buscada);
        }
}

/*Pre:
 *Post: Contara y mostrara los productos en oferta encontrados asi como el total al finalizar.
*/
void buscar_producto_oferta(datos_producto gondola[], int &posicion_producto_gondola){
    int encontrado=0;
    for(int i = 0; i < posicion_producto_gondola+1 ; i++){
        if(gondola[i].oferta == true){
            cout<<"*** +1 ***"<<endl<<endl;
            encontrado++;
        }
    }
    cout<<"Se encontraron "<<encontrado<<" productos en oferta."<<endl;
}

/*Pre: La variable "codigo_buscado" solo recibira dato de tipo int mediante consola.
 *Post: Si encuentra el producto buscado se procedera a mostrarlo por pantalla, en caso contrario se notificara.
*/
void buscar_producto_usando_codigo(datos_producto gondola[], int &posicion_producto_gondola){
    int codigo_buscado;
    bool encontrado=false;
    cout<<"Ingrese el codigo del producto a buscar: ";
    cin>>codigo_buscado;
    cout<<endl;
    for(int i = 0; i < posicion_producto_gondola+1 ; i++){
        if(gondola[i].codigo_barra == codigo_buscado){
            system("cls");
            cout<<"*** Producto encontrado ***"<<endl<<endl;
            producto_individual_encontrado(gondola, i, encontrado);
            opciones_modificar_producto(gondola,posicion_producto_gondola, i);
            i=posicion_producto_gondola;
        }
    }
    if(encontrado==false){
        system("cls");
        cout<<"Codigo de producto no encontrado"<<endl;
    }
}

/*Pre:
 *Post: Si encuentra el producto buscado se procedera a mostrarlo por pantalla, en caso contrario se notificara.
*/
void buscar_producto_usando_nombre(datos_producto gondola[], int &posicion_producto_gondola){
    string producto_buscado;
    bool encontrado=false;
    cout<<"Ingrese el nombre del producto a buscar: ";
    cin>>producto_buscado;
    cout<<endl;
    for(int i = 0; i < posicion_producto_gondola+1 ; i++){
        if(gondola[i].nombre == producto_buscado){
            system("cls");
            cout<<"*** Producto encontrado ***"<<endl<<endl;
            producto_individual_encontrado(gondola, i, encontrado);
            opciones_modificar_producto(gondola,posicion_producto_gondola, i);
            i=posicion_producto_gondola;
        }
    }
    if(encontrado==false){
        system("cls");
        cout<<"Nombre del producto no encontrado D:"<<endl;
    }
}


/*Pre: La informacion de codigo de barras para el nuevo producto debe ser distinto a los existentes.
 *Post: Aumentara el valor de la variable "posicion_producto_gondola" y quedaran agregados los datos del nuevo producto.
*/
void agregar_producto_gondola(datos_producto gondola[], int &posicion_producto_gondola){
    posicion_producto_gondola++;
    char opcion_oferta;
    cout<<endl<<"Ingrese nombre del nuevo producto: ";
    cin>>gondola[posicion_producto_gondola].nombre;
    cout<<endl<<"*La informacion de codigo de barras para el nuevo producto debe"<<endl<<"ser distinto a los existentes*"<<endl;
    cout<<endl<<"Ingrese codigo de barras: ";
    cin>>gondola[posicion_producto_gondola].codigo_barra;
    cout<<endl<<"Ingrese precio: ";
    cin>>gondola[posicion_producto_gondola].precio;
    cout<<endl<<"Ingrese estado de oferta - s/n : ";
    cin>>opcion_oferta;
    if(opcion_oferta == 's'){
        gondola[posicion_producto_gondola].oferta = true;
    }else if(opcion_oferta == 'n'){
        gondola[posicion_producto_gondola].oferta = false;
    }else{
        cout<<"Ingreso invalido - producto quedara sin oferta"<<endl;
        gondola[posicion_producto_gondola].oferta = false;
    }
}

void realizar_accion(datos_producto gondola[], int &posicion_producto_gondola, datos_producto chango[], int &posicion_producto_chango, int accion_elegida){
    switch(accion_elegida){
        case CARGAR_PRODUCTO_GONDOLA:
            agregar_producto_gondola(gondola, posicion_producto_gondola);
            system("cls");
            break;
        case BUSCAR_PRODUCTO_NOMBRE:
            buscar_producto_usando_nombre(gondola, posicion_producto_gondola);
            break;
        case BUSCAR_PRODUCTO_CODIGO:
            buscar_producto_usando_codigo(gondola, posicion_producto_gondola);
            break;
        case CONTAR_PRODUCTOS_OFERTA:
            system("cls");
            buscar_producto_oferta(gondola, posicion_producto_gondola);
            break;
        case CARGAR_PRODUCTOS_CHANGO:
            system("cls");
            crear_chango(gondola, posicion_producto_gondola, chango, posicion_producto_chango);
            break;
        case MOSTRAR_PRODUCTOS_GONDOLA:
            system("cls");
            mostrar_productos_actuales(gondola, posicion_producto_gondola);
            break;
        case SIN_ACCION:
            system("cls");
            cout<<endl<<"Saliendo de la tienda..."<<endl;
            break;
        default:
            system("cls");
            cout<<endl<<"Ingrese un numero del menu valido"<<endl;
            break;
    }
}

void listar_productos_gondola(ifstream &productos_actuales, datos_producto gondola[], int &posicion_producto_gondola){
    string dato;
    int contador=CONTADOR_DATO_NOMBRE;
    getline(productos_actuales, dato);
    while(dato!=FIN_LECTURA){
        switch(contador){
            case CONTADOR_DATO_NOMBRE:
                gondola[posicion_producto_gondola].nombre = dato;
                break;
            case CONTADOR_DATO_CODIGO_BARRAS:{
                stringstream convert(dato);
                convert>>gondola[posicion_producto_gondola].codigo_barra;
                break;
            }
            case CONTADOR_DATO_PRECIO:{
                stringstream convert(dato);
                convert>>gondola[posicion_producto_gondola].precio;
                break;
            }
            case CONTADOR_DATO_OFERTA:{
                if (dato == "true"){
                    gondola[posicion_producto_gondola].oferta=true;
                }else if(dato=="false"){
                    gondola[posicion_producto_gondola].oferta=false;
                }
                break;
            }
            default:
                posicion_producto_gondola++;
                contador=REINICIO_CONTADOR_DATO ;
                break;
        }
        getline(productos_actuales,dato );
        contador++;
    }
}

