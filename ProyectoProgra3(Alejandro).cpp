#include<iostream>

using namespace std;


//proyecto de registro de vehiculos en un estacionamiento/

//La lista se trabajara usando struct//
struct Nodo{
    char placa[5]; //el numero de placa solo admite maximo 5 caracteres
    string modelo; //modelo del carro
    int hora_ingreso; //hora de entrada del parqueo
    Nodo* siguiente; //apuntador al siguiente nodo
};

/*

Agrega el elemento en la lista, se utiliza new

*/
void Agregar(Nodo*& cabeza, char plate[5], string model, int hour )
{
    Nodo* nuevo = new Nodo();

    nuevo->placa[5]=plate[5];
    nuevo->modelo=model;
    nuevo->hora_ingreso=hour;
    nuevo->siguiente=cabeza;

    cabeza=nuevo;
}

/*
Recorre todos los elementos de la lista.
*/

void Mostrar(Nodo*& cabeza){
    Nodo* actual = cabeza;
    while(actual!=nullptr){
        cout<<actual->placa<<" -> "<<actual->modelo<<" -> "<<actual->hora_ingreso<<" \n";
    }
    cout<<"nulo X_X"<<endl;
}

/*

Aqui uno ingresa el numero de placa del vehiculo a buscar y se imprime
TODO: realizar pruebas de que funciona
para su funcion se tiene que ingresar el nodo y el numero de placa

*/

void MostrarElemento(Nodo*& cabeza, char plate[5]){
    Nodo* seleccion = cabeza;
    while(seleccion!=nullptr){
        if(seleccion->placa==plate){
            cout<<seleccion->placa<<" -> "<<seleccion->modelo<<" -> "<<seleccion->hora_ingreso<<" \n";
        }else{
            cout<<"No se encuentra el vehiculo :(";
        }
    }
}


/*libera la memoria 

utiliza delete
Este se coloca a la hora de salir en la seccion Menu.

*/

void limpiar(Nodo*& cabeza){
    Nodo* actual=cabeza;
    while(actual != nullptr){
        Nodo* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }
    cabeza=nullptr;
}

/*

Salida de los vehiculo

*/

void Salida(Nodo*& cabeza, char plate[5]){

    Nodo* actual=cabeza;
    while(actual != nullptr){

        if(actual->placa==plate){
            Nodo* temp = actual;
            actual = actual->siguiente;
            delete temp;
        }
    }
    cabeza=nullptr;
}

/*

TODO: crear el menu el e implementar
cada funcion dentro del menu utilizando switch-case por medio de ingreso de variables
que se especifican dentro de cada metodo. Implementar el metodo limpiar en la opcion de salir
para liberar toda la memoria al terminar de trabajar.

*/
void menu(){

}



int main(){

}







/*











Denis si lees esto, fok you >:)

//borrar esto despues//















*/