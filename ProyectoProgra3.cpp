#include<iostream>
#include<string>
#include <cstdlib>

using namespace std;


//proyecto de registro de vehiculos en un estacionamiento/

//La lista se trabajara usando struct//
struct Nodo{
    char placa[6]; //el numero de placa solo admite maximo 5 caracteres
    string modelo; //modelo del carro
    int hora_ingreso; //hora de entrada del parqueo
    Nodo* siguiente; //apuntador al siguiente nodo
};

/*

Agrega el elemento en la lista, se utiliza new

*/
void Agregar(Nodo*& cabeza, char plate[6], string model, int hour )
{
    Nodo* nuevo = new Nodo();

    nuevo->placa[6]=plate[6];
    nuevo->modelo=model;
    nuevo->hora_ingreso=hour;
    nuevo->siguiente=cabeza;

    cabeza=nuevo;
}

/*
Recorre todos los elementos de la lista.

	Existe un error en la ejecucion de mostrar
	Ejecuta sin parar el codigo
	Supongo que es un problema con que no se mueve al siguiente nodo
 	-Denis
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

void MostrarElemento(Nodo*& cabeza, char plate[6]){
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

void menu(Nodo*& cabeza){
    int opc;
    char placa[6];
    char blanco[1]; // valor solo sirve para comerse el /n de opc
    string modelo;
    int hora_ingreso;

    do {
        system("clear"); // Limpia la pantalla

        cout << "Seleccione una de las siguientes opciones" << endl;
        cout << "1. Lista de vehiculos estacionados" << endl;
        cout << "2. Agregar un vehiculo" << endl;
        cout << "3. Quitar un vehiculo del estacionamiento" << endl;
        cout << "4. Buscar un vehiculo" << endl;
        cout << "5. Salir" << endl;
        cout << "Escriba la Opcion que desea: ";
        cin >> opc;

        switch (opc) {
            case 1:
                Mostrar(cabeza);
                system("pause"); // Pausa para que el usuario pueda ver la lista
                break;

            case 2:
            	
                /*Validaciones adecuadas de entrada de datos
						Esta seccion valida que:
							Las placas sean de maximo 5 caracteres
							La hora de ingreso sea un int
				*/		
				cin.getline(blanco, 1); //getline lee el /n del cin pasado, entonces esta linea sirve solo para comerse ese /n
                cout << "Ingrese la placa: ";
                
                cin.getline(placa, 6); //getline lee la placa, y le sume un '/0'. De este manera, podemos encontrar cuantos caracteres han sido ingresados
				
				//este while asegura que el usuario no ingrese mas de 5 caracteres para la placa
				while((cin.fail() && strlen(placa) == 5)){
                	cout<<"Ingreso mas de 5 caracteres. Intente otravez.";
                	cin.clear();
	  				cin.ignore(10000, '\n');
                    cin.getline(placa, 6);				
				}                             
				
				
				cout << "Ingrese el modelo: ";
                cin >> modelo;
                
                //Este while asegura que el usuario no ingrese un valor distinto a un Int para la hora de ingreso
                cout << "Ingrese la hora de ingreso: ";
                while(!(cin >> hora_ingreso)){ // Si hora_ingreso no es un int, corre el while. Solo se permitira ingresar hasta que sea un int hora_ingreso
                	cout<<"Ingreso un valor que no es permitido. Intente otravez.";
                	cin.clear();
	  				cin.ignore(10000, '\n');
				}            
				
                
                Agregar(cabeza, placa, modelo, hora_ingreso);
                cout << "Vehiculo agregado exitosamente." << endl;
                system("pause");
                break;
            
            case 3:
                cout << "Ingrese la placa del vehiculo a salir: ";
                cin >> placa;
                Salida(cabeza, placa);
                cout << "Vehiculo retirado (si existe)." << endl;
                system("pause");
                break;

            case 4:
                cout << "Ingrese la placa del vehiculo a buscar: ";
                cin >> placa;
                MostrarElemento(cabeza, placa);
                system("pause");
                break;

            case 5:
                limpiar(cabeza); // Llama a limpiar antes de salir
                cout << "Saliendo del programa y liberando memoria." << endl;
                exit(0);
                break;

            default:
                cout << "Opcion seleccionada invalida, por favor intente de nuevo." << endl;
                system("pause");
                break;
        }
        system("cls");

    } while (opc != 5);
};


/* Bug extrano:
	Dice a la hora de ejecucion: 
		"clear" no se reconoce como un comando interno o externo,
		programa o archivo por lotes ejecutable.

*/
int main(){
    Nodo* cabeza = nullptr; // Declara e inicializa la cabeza de la lista
    menu(cabeza); // Pasa la cabeza al menú
	system("cls");
    return 0;
};
