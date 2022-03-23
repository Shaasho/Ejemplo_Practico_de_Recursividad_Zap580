#include <iostream>
using namespace std;

//Inicializamos nodo 
struct nodo
{
    int data;
    nodo* next;
};

//creamos lista
class cola
{
    nodo* rear, * front;
public:
    cola()
    {
        rear = NULL; front = NULL;
    }
    void qinsert(int);
    void qdelete();
    void qdisplay();
    ~cola();
};

//Metodo  para insertar datos
void cola::qinsert(int newData)
{

	nodo* temp;
	temp = new nodo;
	temp->data = newData;
	temp->next = NULL;
	if (rear == NULL)
	{
		rear = temp;
		front = temp;
	}
	else
	{
		rear->next = temp;
		rear = temp;
	}

}

//Metodo para borar datos
void cola::qdelete()
{
    if (front != NULL)
    {
        nodo* temp = front;
        cout << front->data << "Dato Borrado \n";
        front = front->next;
        delete temp;
        if (front == NULL)
            rear = NULL;
    }
    else
        cout << "cola Empty..";
}

//Metodo para mostrar datos
void cola::qdisplay()
{
    nodo* temp = front;
    cout << "------------" << endl;
    while (temp != NULL)
    {
        cout << "El elefante numero " << temp->data << " se columpio!" << endl;
        temp = temp->next;
    }
    cout << "------------" << endl;
}


//Destructor, borra dato por dato
cola::~cola()
{
    while (front != NULL)
    {
        nodo* temp = front;
        front = front->next;
        delete temp;
    }
}

//Creamos una cola global capaz de llenarse por medio de un metodo recursivo hasta alcanzar la variable de control
cola elefantes;
//Inicializamos variable global para controlar los ciclos
int numeroInsertado = 0;

//metodo recursivo que insertara datos en la cola constantemente hasta alcanzar la variable de control
void metodoRecursivo(int numeroActual) {
    
    if (numeroActual <= numeroInsertado) {
        elefantes.qinsert(numeroActual);
        numeroActual++;
        metodoRecursivo(numeroActual);
    }
}



int main()
{
    //Pedimos valor de control al usuario
    cout << "Escribe cuantas veces se columpia un elefante: " << endl;
    cin >> numeroInsertado;

    //Comenzaremos a llenar los valores en la cola empezando desde el valor mas bajo.
    //Se llama al metodo recursivo
    metodoRecursivo(1);

    //Imprimimos valores dentro de la cola
    elefantes.qdisplay();

}

