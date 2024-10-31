#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <stdio.h>  
#include <stdlib.h>
#include <cstdlib>
#include <string.h>
#define TECLA_ARRIBA 72 
#define TECLA_ABAJO 80 
#define ENTER 13
using namespace std;

//XY
void gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

//MENUS
void menu_principal();
void menuPila();
void menuCola();
void munuLista();
int menu(const char* titu, const char* opciones[], int n);

//MEJORAS 
void bien1();
void bien2();
void bien3();
void color(int);
void bienvenida();
void info();
void cabeceraDatosPilas();
void cabeceraDatosCola();
void avion();

//ESTRUCTURA NODO 
struct nodo {
	int datoABB;
	nodo* derABB;
	nodo* izqABB;
	nodo* padreABB;
};


//ESTRUCTURA NODO PARA PILA 
struct Pilas {
	string codigopila;
	string nombreprodpila;
	string tipoprodpila;
	string precio;
	Pilas* dir_codpila;
	Pilas* dir_nombreppila;
	Pilas* dir_tipoppila;
	Pilas* dir_aPrecio;
};

//APUNTADORES PARA PILA
Pilas* Codigo_Pila, * pila_auxcod;
Pilas* NombreP_Pila, * pila_auxnombre;
Pilas* TipoP_pila, * pila_auxTipoP;
Pilas* pila_precio, * pila_auxPrecio;

//FUNCIONES DE LA PILA 
void push();
void pop();
void show();
void search();
void modificarNombre();

//MOSTRAR PILA C
void mostrarColaM();


//PROTOTIPOS DE FUNCIONES
void MenuArbol();
nodo* crearNodoABB(int, nodo*);
void agregarNodoABB(nodo*&, int, nodo*);
void mostrarArbolABB(nodo*, int);
bool busquedaABB(nodo*, int);
void eliminarABB(nodo*, int);
void eliminarNodoABB(nodo*);
nodo* minimoABB(nodo*);
void reemplazarABB(nodo*, nodo*);
void destruirNodoABB(nodo*);

//INTEGRANTES DEL GRUPO 
void grupo();
void buscasCola();

nodo* arbol = NULL;

//MAIN
int main() {
	info();
	grupo();
	menu_principal();
	return 0;
}

//CABECERA MENU
void cabeceraDatosPilas() {
	gotoxy(1, 1); cout << " -----------------------------------------------------------------------------";
	gotoxy(1, 2); cout << "|CODIGO PRODUCTO   |NOMBRE DEL PRODUCTO   |TIPO DE PRODUCTO    |PRECIO       |";
	gotoxy(1, 3); cout << " -----------------------------------------------------------------------------";
}

void cabeceraDatosCOLA() {
	gotoxy(1, 1); cout << " -----------------------------------------------------------------------------";
	gotoxy(1, 2); cout << "|NOMBRE            |MUNICIPIO        |NIT                |DPI                |";
	gotoxy(1, 3); cout << " -----------------------------------------------------------------------------";
}

void mostrarColaM() {
	system("mode con: cols=103 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 110 COLUMNAS Y 25 FILAS
	gotoxy(1, 1); cout << " ---------------------------------------------------------------------------------------------------- ";
	gotoxy(1, 2); cout << "|NOMBRE            |MUNICIPIO        |NIT                |DPI                 | DIRECCION DE MEMORIA |";
	gotoxy(1, 3); cout << " ---------------------------------------------------------------------------------------------------- ";
}

void grupo() {
	system("cls");
	system("mode con: cols=80 lines=25");
	system("color f0");

	gotoxy(27, 5); cout << "INTEGRANTES DEL GRUPO #2";

	gotoxy(5, 10); cout << "Johny Abel Ajcalón Samines                CARNET: 2290-21-2725";
	Sleep(1000);
	gotoxy(5, 11); cout << "Yoshua Kevin Yafeth de León Ovalle        CARNET: 2290-21-19116";
	Sleep(1000);
	gotoxy(5, 12); cout << "Cristian Danaiel Mendoza Hernández        CARNET: 2290-21-20201";
	Sleep(1000);
	gotoxy(5, 13); cout << "Oscar Branly Pixabaj Alva                 CARNET: 2290-21-17382";
	Sleep(1000);
	gotoxy(5, 14); cout << "Santos Benitez Santiago Simón Hernández   CARNET: 2290-21-9304";
	_getch();
}

void info() {
	system("cls");
	system("mode con: cols=80 lines=25");
	system("color f0");
	//SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	//dibujarCuadro(0, 0, 78, 24); //SE DIBUJA EL CUADRO PRINCIPAL
	//dibujarCuadro(1, 1, 77, 3); //SE DIBUJA EL CUADRO DEL TITULO
	gotoxy(29, 8); cout << "ABARROTERIA DON CABAL";
	gotoxy(18, 10); cout << "Este sistema es para llevar el control de clientes";
	gotoxy(25, 11); cout << " y productos en una abarroteria";
	Sleep(1000);
	_getch();
}

//CONTADOR
int j = 1;

//INGRESO DE DATOS PARA METODO PILA 
void push() {
	system("cls");
	system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	cabeceraDatosPilas();
	gotoxy(1, 4); cout << "|";
	gotoxy(78, 4); cout << "|";
	if (Codigo_Pila == NULL) {
		Codigo_Pila = new (Pilas);
		gotoxy(3, 4);  cin >> Codigo_Pila->codigopila;
		getchar();
		Codigo_Pila->dir_codpila = NULL;
		NombreP_Pila = new (Pilas);
		gotoxy(29, 4); cin >> NombreP_Pila->nombreprodpila;
		getchar();
		NombreP_Pila->dir_nombreppila = NULL;
		j = j++;
		TipoP_pila = new(Pilas);
		gotoxy(47, 4); cin >> TipoP_pila->tipoprodpila;
		getchar();
		TipoP_pila->dir_tipoppila = NULL;
		j = j++;
		pila_precio = new(Pilas);
		gotoxy(67, 4); cin >> pila_precio->precio;
		getchar();
		pila_precio->dir_aPrecio = NULL;
		j = j++;
		gotoxy(15, 20); cout << " Se han ingresado " << j << " nodos a la estructura...";
		gotoxy(25, 21); cout << " DATOS CORRECTAMENTE INGRESADOS";
		getchar();
		return;
	}
	else {

		pila_auxcod = new(Pilas);
		gotoxy(3, 4); cin >> pila_auxcod->codigopila;
		getchar();
		pila_auxcod->dir_codpila = Codigo_Pila;
		Codigo_Pila = pila_auxcod;
		j = j++;
		pila_auxnombre = new(Pilas);
		gotoxy(29, 4); cin >> pila_auxnombre->nombreprodpila;
		getchar();
		pila_auxnombre->dir_nombreppila = NombreP_Pila;
		NombreP_Pila = pila_auxnombre;
		j = j++;
		pila_auxTipoP = new(Pilas);
		gotoxy(47, 4); cin >> pila_auxTipoP->tipoprodpila;
		getchar();
		pila_auxTipoP->dir_tipoppila = TipoP_pila;
		TipoP_pila = pila_auxTipoP;
		j = j++;
		pila_auxPrecio = new(Pilas);
		gotoxy(67, 4); cin >> pila_auxPrecio->precio;
		getchar();
		pila_auxPrecio->dir_aPrecio = pila_precio;
		pila_precio = pila_auxPrecio;
		j = j++;
		gotoxy(15, 20); cout << " Se han ingresado " << j << " nodos a la estructura...";
		gotoxy(25, 21); cout << " DATOS CORRECTAMENTE INGRESADOS";
		getchar();
	}
}

//ELIMINACION DE DATOS EN METODO PILA
void pop() {
	system("cls");
	system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	cabeceraDatosPilas();
	cout << endl;
	if (Codigo_Pila == NULL && NombreP_Pila == NULL && TipoP_pila == NULL && pila_precio == NULL) {
		gotoxy(3, 4); cout << "No existen datos para eliminar..." << endl;
		getchar();
		getchar();
		return;
	}
	else {
		pila_auxcod = new(Pilas);
		pila_auxcod = Codigo_Pila;
		gotoxy(3, 4); cout << pila_auxcod->codigopila;
		getchar();
		Codigo_Pila = pila_auxcod->dir_codpila;
		delete(pila_auxcod);
		pila_auxnombre = new(Pilas);
		pila_auxnombre = NombreP_Pila;
		gotoxy(29, 4); cout << pila_auxnombre->nombreprodpila;
		getchar();
		NombreP_Pila = pila_auxnombre->dir_nombreppila;
		delete(pila_auxnombre);
		pila_auxTipoP = new(Pilas);
		pila_auxTipoP = TipoP_pila;
		gotoxy(47, 4); cout << pila_auxTipoP->tipoprodpila;
		getchar();
		TipoP_pila = pila_auxTipoP->dir_tipoppila;
		delete(pila_auxTipoP);
		pila_auxPrecio = new(Pilas);
		pila_auxPrecio = pila_precio;
		gotoxy(67, 4); cout << pila_auxPrecio->precio;
		getchar();
		pila_precio = pila_auxPrecio->dir_aPrecio;
		delete(pila_auxPrecio);
		gotoxy(25, 6); cout << "-----------------------------";
		gotoxy(25, 6); cout << "ELIMINANDO DATOS DEL CLIENTE."; Sleep(500);
		gotoxy(25, 6); cout << "ELIMINANDO DATOS DEL CLIENTE.."; Sleep(500);
		gotoxy(25, 6); cout << "ELIMINANDO DATOS DEL CLIENTE..."; Sleep(500);
		gotoxy(25, 6); cout << "                               "; Sleep(500);
		gotoxy(25, 6); cout << "ELIMINANDO DATOS DEL CLIENTE."; Sleep(500);
		gotoxy(25, 6); cout << "ELIMINANDO DATOS DEL CLIENTE.."; Sleep(500);
		gotoxy(25, 6); cout << "ELIMINANDO DATOS DEL CLIENTE..."; Sleep(500);
		gotoxy(25, 6); cout << "                               "; Sleep(500);
		gotoxy(25, 6); cout << "DATOS DEL CLIENTE ELIMINADOS"; Sleep(500);
		getchar();
		return;
	}
}

//MOSTRAR DATOS EN METODO PILA 
void show() {
	system("cls");
	system("mode con: cols=80 lines=1000"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 100 COLUMNAS Y 25 FILAS
	gotoxy(26, 2); cout << "DATOS INGRESADOS EN FORMA DE PILA";
	if (Codigo_Pila == NULL) {
		gotoxy(5, 8); cout << "La pila no contiene datos a mostrar" << endl;
		getchar();
	}
	pila_auxcod = Codigo_Pila;
	pila_auxnombre = NombreP_Pila;
	pila_auxTipoP = TipoP_pila;
	pila_auxPrecio = pila_precio;
	int i = 1;
	gotoxy(2, 4);    cout << " -------------------------------------------------------------------------- " << endl;
	gotoxy(2, 5);     cout << "|                                     FIN                                  |" << endl;
	gotoxy(2, 6);     cout << " -------------------------------------------------------------------------- " << endl;
	while (pila_auxcod != NULL && pila_auxnombre != NULL && pila_auxTipoP != NULL && pila_auxPrecio != NULL)
	{
		cout << endl;
		cout << endl;
		gotoxy(2, 6 + i); cout << "|Codigo Producto: " << pila_auxcod->codigopila << endl;
		gotoxy(77, 6 + i); cout << "|";
		pila_auxcod = pila_auxcod->dir_codpila;
		i = i++;

		gotoxy(2, 6 + i); cout << "|Nombre Producto: " << pila_auxnombre->nombreprodpila << endl;
		gotoxy(77, 6 + i); cout << "|";
		pila_auxnombre = pila_auxnombre->dir_nombreppila;
		i = i++;

		gotoxy(2, 6 + i); cout << "|Tipo de producto: " << pila_auxTipoP->tipoprodpila << endl;
		gotoxy(77, 6 + i); cout << "|";
		pila_auxTipoP = pila_auxTipoP->dir_tipoppila;
		i = i++;

		gotoxy(2, 6 + i); cout << "|Precio: Q." << pila_auxPrecio->precio << endl;
		gotoxy(77, 6 + i); cout << "|";
		pila_auxPrecio = pila_auxPrecio->dir_aPrecio;
		i = i++;

		//DIRECCION DE MEMORIA
		gotoxy(2, 6 + i); cout << "|Direccion de Memoria: " << &pila_auxcod->codigopila << endl;
		gotoxy(77, 6 + i); cout << "|";
		i = i++;
		gotoxy(2, 6 + i); cout << " -------------------------------------------------------------------------- " << endl;

		//NUMERO DE REGISTRO
		i = i++;

	}

	gotoxy(2, 6 + i); cout << "|                                    INICIO                                |" << endl;
	i = i++;
	gotoxy(2, 6 + i); cout << " -------------------------------------------------------------------------- " << endl;

	getchar();
	system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
}

//BUSCAR DATOS EN FORMA DE PILA 
void search() {
	system("cls");
	system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	gotoxy(30, 2); cout << "BUSQUEDA DE CODIGO DEL PRODUCTO";

	//COMPROBACION PARA VER SI EXISTEN DATOS EN LA PILA
	if (Codigo_Pila == NULL) {

		gotoxy(20, 20); cout << "No hay datos ingresados de producto..." << endl;
	}

	//Variables para la busqueda
	string searchDestino;
	string searchBoleto;
	int searchEstadia;
	int searchPrecio;
	bool found = false;
	pila_auxcod = Codigo_Pila;
	gotoxy(5, 7); cout << "Ingrese codigo del producto a buscar:";
	cin >> searchDestino;

	while (pila_auxcod != NULL)
	{
		if (searchDestino == pila_auxcod->codigopila)
		{
			gotoxy(5, 9); cout << "Buscando."; Sleep(500);
			gotoxy(5, 9); cout << "Buscando.."; Sleep(500);
			gotoxy(5, 9); cout << "Buscando..."; Sleep(500);
			gotoxy(5, 9); cout << "                                                              ";
			gotoxy(5, 9); cout << "Buscando."; Sleep(500);
			gotoxy(5, 9); cout << "Buscando.."; Sleep(500);
			gotoxy(5, 9); cout << "Buscando..."; Sleep(500);
			gotoxy(5, 9); cout << "                                                              ";
			gotoxy(5, 9);  cout << "El codigo existe en los registros de los productos:  " << pila_auxcod->codigopila << endl;
			getchar();
			found = true;
			break;
		}
		pila_auxcod = pila_auxcod->dir_codpila;
	}
	if (found == false)
	{
		gotoxy(5, 9); cout << "No se encontro registro del producto" << endl;
		getchar();
	}
	getchar();
}

//MODIFICAR NOMBRE CLIENTE
void modificarNombre() {
	system("cls");
	system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	gotoxy(30, 2); cout << "MODIFICACION DE CODIGO DE PRODUCTO";

	//COMPROBACION PARA VER SI EXISTEN DATOS EN LA PILA
	if (Codigo_Pila == NULL) {

		gotoxy(20, 20); cout << "No hay datos ingresados del producto..." << endl;
	}
	string searchDestino;
	bool found = false;
	pila_auxcod = Codigo_Pila;
	gotoxy(5, 7); cout << "Ingrese el codigo del producto a modificar: ";
	cin >> searchDestino;
	while (pila_auxcod != NULL)
	{
		if (searchDestino == pila_auxcod->codigopila)
		{
			gotoxy(5, 8);  cout << "El codigo existe en los registros de los productos:  " << pila_auxcod->codigopila << endl;
			gotoxy(5, 9);  cout << "Ingrese el nuevo codigo: ";
			cin >> pila_auxcod->codigopila;
			gotoxy(5, 10); cout << "Modificando."; Sleep(500);
			gotoxy(5, 10); cout << "Modificando.."; Sleep(500);
			gotoxy(5, 10); cout << "Modificando..."; Sleep(500);
			gotoxy(5, 10); cout << "                                                              ";
			gotoxy(5, 11);  cout << "EL CODIGO A SIDO MODIFICADO";
			getchar();
			found = true;
			break;
		}
		pila_auxcod = pila_auxcod->dir_codpila;
	}
	if (found == false)
	{
		gotoxy(5, 9); cout << "No se encontro registro para modificar..." << endl;
		getchar();
	}
	getchar();
}

void menu_principal()
{
	system("cls");
	system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	system("color f0");
	bool repite = true;
	int opc;

	//TITULO Y OPCIONES DEL MENU
	const char* titu = { "" };
	const char* opciones[] = { "MODULO DE DATOS DE PRODUCTO  (PILA)", "MODULO DE DATOS DE CLIENTE  (COLA)", "MODULO DE DATOS DE INGRESOS PRODUCTOS  (LISTAS)","MODULO DE DATOS DE EXISTENCIA  (ABB)", "SALIDA" };
	int n = 5; //NUMERO DE OPCIONES
	do
	{
		opc = menu(titu, opciones, n);
		//MENU
		//ALTERNATIVAS 
		switch (opc)
		{
		case 1:
			menuPila();
			break;
		case 2:
			menuCola();
			break;
		case 3:
			munuLista();
			break;
		case 4:
			MenuArbol();
			break;
		case 5:repite = false;	break;
		}
	} while (repite);
}

void menuPila() {
	system("cls");
	system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	bool repite = true;
	int opc;

	gotoxy(9, 4); const char* titu = "INGRESO DE DATOS (METODO PILA)";
	const char* opciones[] = { "Ingreso de datos de (PILA)", "Ver datos en forma de (PILA)", "Modificar un dato ", "Buscar un dato ", "Eliminar un dato ", "Regresar al Menu Principal" };
	int n = 6;
	do
	{
		opc = menu(titu, opciones, n);
		//ALTERNATIVAS 
		switch (opc)
		{
		case 1:
			push();
			break;
		case 2:
			show();
			break;
		case 3:
			modificarNombre();
			break;
		case 4:
			search();
			break;
		case 5:
			pop();
			break;
		case 6:
			repite = false;
			break;
		}
	} while (repite);
}

int menu(const char* titu, const char* opciones[], int n) {
	int opcionSeleccionada = 1;
	int tecla;

	bool repite = true;

	do
	{
		system("cls");
		gotoxy(3, 6 + opcionSeleccionada); cout << "==>";
		gotoxy(30, 5); cout << titu;
		gotoxy(25, 2); cout << "TIENDA DE ABARROTERIA DON CABAL";
		//imprime las opciones

		for (int i = 0; i < n; i++)
		{
			gotoxy(10, 7 + i); cout << i + 1 << ") " << opciones[i];
		}

		do
		{
			tecla = _getch();
		} while (tecla != TECLA_ARRIBA && tecla != TECLA_ABAJO && tecla != ENTER);

		switch (tecla)
		{
		case TECLA_ARRIBA:
			opcionSeleccionada--;
			if (opcionSeleccionada < 1)
			{
				opcionSeleccionada = n;
			}
			break;

		case TECLA_ABAJO:
			opcionSeleccionada++;
			if (opcionSeleccionada > n)
			{
				opcionSeleccionada = 1;
			}
			break;

		case ENTER:
			repite = false;
			break;
		}

	} while (repite);

	return opcionSeleccionada;
}


//COLAS
//declarar estructura
struct datos
{
	char nombre[30];
	char municipio[30];
	int nit;
	int dpi;
};

//declarar colas
struct nodo1 {
	struct datos entrada;
	nodo1* siguientepilap;
}*ultimo = NULL, * cola = NULL, * primero = NULL;

//Segunda cola
struct nodo2 {
	struct datos salida;
	nodo2* destino_sig1;
}*ultimo1 = NULL, * cola1 = NULL, * primero1 = NULL;

//funciones
int cantidad = 2;
int x;

void ingresarCola() {
	system("cls");
	cabeceraDatosCOLA();
	gotoxy(1, 4); cout << "|";
	gotoxy(79, 4); cout << "|";
	cola = new(nodo1);
	gotoxy(3, 4); cin >> cola->entrada.nombre;
	x = x + 1;
	gotoxy(21, 4); cin >> cola->entrada.municipio;
	x = x++;;
	gotoxy(39, 4); cin >> cola->entrada.nit;
	x = x++;
	gotoxy(59, 4); cin >> cola->entrada.dpi;
	x = x++;
	getchar();

	if (ultimo != NULL) {
		ultimo->siguientepilap = cola;
		cola->siguientepilap = NULL;
		ultimo = cola;
		gotoxy(15, 20); cout << "Se han ingresado " << x << " nodos a la estructura...";
		gotoxy(25, 21); cout << "DATO INGRESADO CORRECTAMENTE " << endl;
		getchar();
	}
	else {
		primero = ultimo = cola;
		gotoxy(15, 20); cout << "Se han ingresado " << x << " nodos a la estructura...";
		gotoxy(25, 21); cout << "DATOS INGRESADOS CORRECTAMENTE " << endl;
		getchar();
	}
}

void Mostrar1Cola() {
	system("cls");
	mostrarColaM();
	int i = 1;
	if (ultimo == NULL) {
		gotoxy(25, 6); cout << " no se ingresaron nuevos datos " << endl;
		_getch();
		system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
		return;
	}
	cola = primero;
	gotoxy(1, 4);     cout << "|                                              INICIO                                                |" << endl;
	gotoxy(1, 5);     cout << " ---------------------------------------------------------------------------------------------------- " << endl;
	while (cola != NULL) {
		if (primero == ultimo) {
			gotoxy(1, 5 + i); cout << "|";
			gotoxy(102, 5 + i); cout << "|";
			gotoxy(3, 5 + i); cout << cola->entrada.nombre;
			gotoxy(20, 5 + i); cout << "|" << cola->entrada.municipio;
			gotoxy(39, 5 + i); cout << "|" << cola->entrada.nit;
			gotoxy(66, 5 + i); cout << "|" << cola->entrada.dpi;
			//DIRECCION DE MEMORIA 
			gotoxy(79, 5 + i); cout << "|" << &cola->entrada.nombre;
			i++;
			gotoxy(1, 5 + i);    cout << " ---------------------------------------------------------------------------------------------------- " << endl;
			cola = NULL;
			_getch();
			menuCola();
		}
		else {
			gotoxy(1, 5 + i); cout << "|";
			gotoxy(102, 5 + i); cout << "|";
			//cout << "Su Destino es: ";
			gotoxy(3, 5 + i); cout << cola->entrada.nombre;

			//cout << "Su tipo de boleto es: " 
			gotoxy(20, 5 + i); cout << "|" << cola->entrada.municipio;

			//cout << "Su tiempo de estadia es: " 
			gotoxy(39, 5 + i); cout << "|" << cola->entrada.nit;

			//cout << "Su monto a pagar es: " 
			gotoxy(65, 5 + i); cout << "|" << cola->entrada.dpi;

			//DIRECCION DE MEMORIA 
			gotoxy(79, 5 + i); cout << "|" << &cola->entrada.nombre;
			i++;
			gotoxy(1, 5 + i);    cout << " ---------------------------------------------------------------------------------------------------- " << endl;
			i++;
			cola = cola->siguientepilap;
			_getch();
		}
	}
	gotoxy(1, 5 + i);     cout << "|                                              FIN                                                   |" << endl;
	i++;
	gotoxy(1, 5 + i);     cout << " ---------------------------------------------------------------------------------------------------- " << endl;
	_getch();
	system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
}

void eliminarCola() {
	system("cls");
	cola1 = new(nodo2);
	//dibujarCuadro(0, 0, 78, 24); //SE DIBUJA EL CUADRO PRINCIPAL
	//dibujarCuadro(1, 1, 77, 3); //SE DIBUJA EL CUADRO DEL TITULO
	gotoxy(30, 2); cout << "ELIMINACION DE DATOS";
	if (ultimo == NULL) {

		gotoxy(25, 6); cout << "NO HAY DATOS INGRESADOS";
		_getch();
		return;
	}
	else {
		if (primero != NULL) {

			cola = primero; gotoxy(25, 6); cout << "-----------------------------";
			gotoxy(25, 6); cout << "ELIMINANDO DATOS DEL DESTINO."; Sleep(500);
			gotoxy(25, 6); cout << "ELIMINANDO DATOS DEL DESTINO.."; Sleep(500);
			gotoxy(25, 6); cout << "ELIMINANDO DATOS DEL DESTINO..."; Sleep(500);
			gotoxy(25, 6); cout << "                               "; Sleep(500);
			gotoxy(25, 6); cout << "ELIMINANDO DATOS DEL DESTINO."; Sleep(500);
			gotoxy(25, 6); cout << "ELIMINANDO DATOS DEL DESTINO.."; Sleep(500);
			gotoxy(25, 6); cout << "ELIMINANDO DATOS DEL DESTINO..."; Sleep(500);
			gotoxy(25, 6); cout << "                               "; Sleep(500);
			gotoxy(25, 6); cout << "DATOS DEL DESTINO ELIMINADOS"; Sleep(500);
			gotoxy(25, 7); cout << "Se elimino el cliente en la cola: " << cola->entrada.nombre << endl;
			getchar();

			strcpy_s(cola1->salida.nombre, cola->entrada.nombre);
			strcpy_s(cola1->salida.municipio, cola->entrada.municipio);
			cola1->salida.nit = cola->entrada.nit;
			cola1->salida.dpi = cola->entrada.dpi;
			if (ultimo != NULL) {
				ultimo1 = cola1->destino_sig1;
				cola1->destino_sig1 = NULL;
				ultimo1 = cola1;
			}
			else {
				primero1 = ultimo1 = cola1;
			}
		}
		primero = cola->siguientepilap;
		if (primero == NULL) {
			ultimo = NULL;
			cola = NULL;
		}
		_getch();
	}
}

void buscasCola() {
	system("cls");
	system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	gotoxy(30, 2); cout << "BUSQUEDA DE DATOS";

	nodo1* actual = new nodo1();
	actual = primero;
	bool encontrado = false;
	string nodoBuscado;
	gotoxy(20, 8); cout << "INGRESE EL NOMBRE DEL CLIENTE A BUSCAR : ";
	gotoxy(30, 9); cin >> nodoBuscado;
	if (primero != NULL) {
		while (actual != NULL && encontrado != true) {

			if (actual->entrada.nombre == nodoBuscado) {
				gotoxy(30, 10); cout << "Buscando."; Sleep(500);
				gotoxy(30, 10); cout << "Buscando.."; Sleep(500);
				gotoxy(30, 10); cout << "Buscando..."; Sleep(500);
				gotoxy(30, 10); cout << "                                                              ";
				gotoxy(30, 10); cout << "DATOS ENCONTRADOS";
				gotoxy(3, 11); cout << actual->entrada.nombre;
				gotoxy(20, 11); cout << actual->entrada.municipio;
				gotoxy(42, 11); cout << actual->entrada.nit;
				gotoxy(70, 11); cout << actual->entrada.dpi;
				encontrado = true;
				_getch();
				system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
				return;
			}

			actual = actual->siguientepilap;
		}
		if (!encontrado) {
			gotoxy(30, 10); cout << " CLIENTE NO ENCONTRADO";
			_getch();
			system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
			return;
		}
	}
	else {
		gotoxy(30, 10); cout << " NO HAY DATOS INGRESADOS " << endl;
		_getch();
		system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
		return;
	}
}

void modificarCola() {
	system("cls");
	system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	gotoxy(30, 2); cout << "MODIFICACION DE DATOS";

	nodo1* actual = new nodo1();
	actual = primero;
	bool encontrado = false;
	string nodoBuscado;

	gotoxy(20, 8); cout << "INGRESE NOMBRE A MODIFICAR: ";
	gotoxy(30, 9); cin >> nodoBuscado;

	if (primero != NULL) {
		while (actual != NULL && encontrado != true) {
			if (actual->entrada.nombre == nodoBuscado) {
				gotoxy(30, 10);  cout << "CLIENTE ( " << nodoBuscado << " ) ENCONTRADO";
				gotoxy(30, 11); cout << "INGRESE EL NUEVO NOMBRE DEL CLIENTE ";
				gotoxy(30, 12); cin >> actual->entrada.nombre;
				gotoxy(30, 13); cout << "Modificando."; Sleep(500);
				gotoxy(30, 13); cout << "Modificando.."; Sleep(500);
				gotoxy(30, 13); cout << "Modificando..."; Sleep(500);
				gotoxy(30, 13); cout << "                                                              ";
				gotoxy(30, 13); cout << "DATO MODIFICADO";
				encontrado = true;
				_getch();
				system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
				return;
			}

			actual = actual->siguientepilap;
		}
		if (!encontrado) {
			gotoxy(30, 12); cout << "Buscando."; Sleep(500);
			gotoxy(30, 12); cout << "Buscando.."; Sleep(500);
			gotoxy(30, 12); cout << "Buscando..."; Sleep(500);
			gotoxy(30, 12); cout << "                                                              ";

			gotoxy(30, 10); cout << "DATO NO ENCONTRADO";
			_getch();
			system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
			return;
		}
	}
	else {
		gotoxy(30, 10); cout << endl << "NO HAY DATOS INGRESADOS" << endl << endl;
		_getch();
		system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
		return;
	}
}

void menuCola() {
	system("cls");
	system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	bool repite = true;
	int opc;
	const char* titu = "INGRESO DE DATOS (METODO COLA)";
	const char* opciones[] = { "Ingreso de datos del cliente (COLA)", "Ver datos en forma de (COLA)", "Modificar un dato ", "Buscar un dato ", "Eliminar un dato ", "Regresar al Menu Principal" };
	int n = 6;

	do
	{
		opc = menu(titu, opciones, n);
		//ALTERNATIVAS 
		switch (opc)
		{
		case 1:
			ingresarCola();
			break;
		case 2:
			Mostrar1Cola();
			break;
		case 3:
			modificarCola();
			break;
		case 4:
			buscasCola();
			break;
		case 5:
			eliminarCola();
			break;

		case 6:
			repite = false;
			break;
		}
	} while (repite);
	system("cls");
}

//funciones de lstas simples
void insertarNodoqq();
void buscarNodoqq();
void modificarNodoqq();
void eliminarNodoqq();
void desplegarListaqq();

//listas dobles funciones
void insertarNododuo();
void buscarNododuo();
void modificarNododuo();
void eliminarNododuo();
void desplegarListaPUduo();
void desplegarListaUPduo();

//Listas circulare
void insertarNodocir();
void buscarNodocir();
void modificarNodocir();
void eliminarNodocir();
void desplegarListacir();

void munuLista() {
	system("cls");
	system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	bool repite = true;
	int opc;

	const char* titu = "INGRESO DE DATOS (METODO LISTAS)";
	const char* opciones[] = { "Listas Simples", "Listas doblemenete enlazadas", "Lista Circular","Salir" };
	int n = 4;

	do
	{
		opc = menu(titu, opciones, n);
		int opcion_menu;

		//ALTERNATIVAS 
		switch (opc)
		{
		case 1:

			do
			{
				system("mode con: cols=80 lines=25");
				cout << "\n|-------------------------------------|";
				cout << "\n|           ° LISTA SIMPLE °          |";
				cout << "\n|------------------|------------------|";
				cout << "\n| 1. Insertar      | 4. Eliminar      |";
				cout << "\n| 2. Buscar        | 5. Desplegar     |";
				cout << "\n| 3. Modificar     | 6. Salir         |";
				cout << "\n|------------------|------------------|";
				cout << "\n\n Escoja una Opcion: ";
				cin >> opcion_menu;
				switch (opcion_menu) {
				case 1:
					cout << "\n\n INSERTA NODO EN LA LISTA \n\n";
					insertarNodoqq();
					break;
				case 2:
					cout << "\n\n BUSCAR UN NODO EN LA LISTA \n\n";
					buscarNodoqq();
					break;
				case 3:
					cout << "\n\n MODIFICAR UN NODO DE LA LISTA \n\n";
					modificarNodoqq();
					break;
				case 4:
					cout << "\n\n ELIMINAR UN NODO DE LA LISTA \n\n";
					eliminarNodoqq();
					break;
				case 5:
					cout << "\n\n DESPLEGAR LISTA DE NODOS \n\n";
					desplegarListaqq();
					break;
				case 6:
					cout << "\n\n Programa finalizado...";
					break;
				default:
					cout << "\n\n Opcion No Valida \n\n";
				}
			} while (opcion_menu != 6);
			break;
		case 2:
			int opcion_menu1111;
			do
			{
				system("mode con: cols=80 lines=25");
				cout << "\n|-------------------------------------|";
				cout << "\n|           ° LISTA DOBLE °           |";
				cout << "\n|------------------|------------------|";
				cout << "\n| 1. Insertar      | 5. Desplegar P.U |";
				cout << "\n| 2. Buscar        | 6. Desplegar U.P |";
				cout << "\n| 3. Modificar     | 7. Salir         |";
				cout << "\n| 4. Eliminar      |                  |";
				cout << "\n|------------------|------------------|";
				cout << "\n\n Escoja una Opcion: ";
				cin >> opcion_menu1111;
				switch (opcion_menu1111) {
				case 1:
					cout << "\n\n INSERTA NODO EN LA LISTA \n\n";
					insertarNododuo();
					break;
				case 2:
					cout << "\n\n BUSCAR UN NODO EN LA LISTA \n\n";
					buscarNododuo();
					break;
				case 3:
					cout << "\n\n MODIFICAR UN NODO DE LA LISTA \n\n";
					modificarNododuo();
					break;
				case 4:
					cout << "\n\n ELIMINAR UN NODO DE LA LISTA \n\n";
					eliminarNododuo();
					break;
				case 5:
					cout << "\n\n DESPLEGAR LISTA DE NODOS DEL PRIMERO AL UTLIMO\n\n";
					desplegarListaPUduo();
					break;
				case 6:
					cout << "\n\n DESPLEGAR LISTA DE NODOS DEL UTLIMO AL PRIMERO\n\n";
					desplegarListaUPduo();
					break;
				case 7:
					cout << "\n\n Programa finalizado...";
					break;
				default:
					cout << "\n\n Opcion No Valida \n\n";
				}
			} while (opcion_menu1111 != 7);
			//Mostrar1Cola();ingresa el nombre aqui 
			break;
		case 3:
			int opcion_menu33;
			do
			{
				system("mode con: cols=80 lines=25");
				cout << "\n|-------------------------------------|";
				cout << "\n|      ° LISTA CIRCULAR SIMPLE °      |";
				cout << "\n|------------------|------------------|";
				cout << "\n| 1. Insertar      | 4. Eliminar      |";
				cout << "\n| 2. Buscar        | 5. Desplegar     |";
				cout << "\n| 3. Modificar     | 6. Salir         |";
				cout << "\n|------------------|------------------|";
				cout << "\n\n Escoja una Opcion: ";
				cin >> opcion_menu33;
				switch (opcion_menu33) {
				case 1:
					cout << "\n\n INSERTA NODO EN LA LISTA \n\n";
					insertarNodocir();
					break;
				case 2:
					cout << "\n\n BUSCAR UN NODO EN LA LISTA \n\n";
					buscarNodocir();
					break;
				case 3:
					cout << "\n\n MODIFICAR UN NODO DE LA LISTA \n\n";
					modificarNodocir();
					break;
				case 4:
					cout << "\n\n ELIMINAR UN NODO DE LA LISTA \n\n";
					eliminarNodocir();
					break;
				case 5:
					cout << "\n\n DESPLEGAR LISTA DE NODOS \n\n";
					desplegarListacir();
					break;
				case 6:
					cout << "\n\n Programa finalizado...";
					break;
				default:
					cout << "\n\n Opcion No Valida \n\n";
				}
			} while (opcion_menu33 != 6);
			//modificarCola();ingresa el nombre aqui 
			break;
		case 4:
			repite = false;
			break;
		}
	} while (repite);
	system("cls");
}

//Listas simples
//struct productosabo {
//	Producto
//};

struct nodo8 {
	int dato;
	nodo8* siggg;
} *primero11, * ultimo11;

void insertarNodoqq() {
	system("mode con: cols=80 lines=25");
	nodo8* nuevoaa = new nodo8();
	cout << " Ingrese el dato que contendra el nuevo Nodo: ";
	cin >> nuevoaa->dato;

	if (primero11 == NULL) {
		primero11 = nuevoaa;
		primero11->siggg = NULL;
		ultimo11 = nuevoaa;
	}
	else {
		ultimo11->siggg = nuevoaa;
		nuevoaa->siggg = NULL;
		ultimo11 = nuevoaa;
	}
	cout << "\n Nodo Ingresado\n\n";
	_getch();
}

void buscarNodoqq() {
	system("mode con: cols=80 lines=25");
	nodo8* actualqq = new nodo8();
	actualqq = primero11;
	bool encontradoll = false;
	int nodoBuscadoll = 0;
	cout << " Ingrese el dato del nodo a Buscar: ";
	cin >> nodoBuscadoll;
	if (primero11 != NULL) {

		while (actualqq != NULL && encontradoll != true) {

			if (actualqq->dato == nodoBuscadoll) {
				cout << "\n Nodo con el dato " << nodoBuscadoll << " Encontrado\n\n";
				encontradoll = true;
			}

			actualqq = actualqq->siggg;
		}
		if (!encontradoll) {
			cout << "\n Nodo No Encontrado\n\n";
		}
	}
	else {
		cout << "\n La Lista se Encuentra Vacia\n\n";
	}
	_getch();
}

void modificarNodoqq() {
	system("mode con: cols=80 lines=25");
	nodo8* actualpp = new nodo8();
	actualpp = primero11;
	bool encontradopp = false;
	int nodoBuscadopp = 0;
	cout << " Ingrese el dato del nodo a Buscar para Modificar: ";
	cin >> nodoBuscadopp;
	if (primero11 != NULL) {

		while (actualpp != NULL && encontradopp != true) {

			if (actualpp->dato == nodoBuscadopp) {
				cout << "\n Nodo con el dato " << nodoBuscadopp << " Encontrado";
				cout << "\n Ingrese el Nuevo dato para este Nodo: ";
				cin >> actualpp->dato;
				encontradopp = true;
			}

			actualpp = actualpp->siggg;
		}
		if (!encontradopp) {
			cout << "\n Nodo No Encontrado\n\n";
		}
	}
	else {
		cout << "\n La Lista se Encuentra Vacia\n\n";
	}
	_getch();
}


void eliminarNodoqq() {
	system("mode con: cols=80 lines=25");
	nodo8* actualoo = new nodo8();
	actualoo = primero11;
	nodo8* anterioroo = new nodo8();
	anterioroo = NULL;
	bool encontradooo = false;
	int nodoBuscadooo = 0;
	cout << " Ingrese el dato del nodo a Buscar para Eliminar: ";
	cin >> nodoBuscadooo;
	if (primero11 != NULL) {

		while (actualoo != NULL && encontradooo != true) {

			if (actualoo->dato == nodoBuscadooo) {
				cout << "\n Nodo con el dato " << nodoBuscadooo << " Encontrado\n\n";

				if (actualoo == primero11) {
					primero11 = primero11->siggg;
				}
				else if (actualoo == ultimo11) {
					anterioroo->siggg = NULL;
					ultimo11 = anterioroo;
				}
				else {
					anterioroo->siggg = actualoo->siggg;
				}

				cout << "\n Nodo ELiminado con exito\n\n";

				encontradooo = true;
			}

			anterioroo = actualoo;
			actualoo = actualoo->siggg;
		}
		if (!encontradooo) {
			cout << "\n Nodo No Encontrado\n\n";
		}
	}
	else {
		cout << "\n La Lista se Encuentra Vacia\n\n";
	}
	_getch();
}

void desplegarListaqq() {
	system("mode con: cols=80 lines=25");
	nodo8* actualuu = new nodo8();
	actualuu = primero11;
	if (primero11 != NULL) {

		while (actualuu != NULL) {
			cout << " " << actualuu->dato << endl;
			actualuu = actualuu->siggg;
		}
	}
	else {
		cout << "\n La Lista se Encuentra Vacia\n\n";
	}
	_getch();
}


//Listas Doblemente enlazada
struct nodo9 {
	int dato;
	nodo9* siguientedou;
	nodo9* atrasduo;
} *primero12, * ultimo12;

void insertarNododuo() {
	system("mode con: cols=80 lines=25");
	nodo9* nuevodd = new nodo9();
	cout << " Ingrese el dato que contendra el nuevo Nodo: ";
	cin >> nuevodd->dato;

	if (primero12 == NULL) {
		primero12 = nuevodd;
		primero12->siguientedou = NULL;
		primero12->atrasduo = NULL;
		ultimo12 = primero12;
	}
	else {
		ultimo12->siguientedou = nuevodd;
		nuevodd->siguientedou = NULL;
		nuevodd->atrasduo = ultimo12;
		ultimo12 = nuevodd;
	}
	cout << "\n Nodo Ingresado\n\n";
	_getch();
}

void buscarNododuo() {
	system("mode con: cols=80 lines=25");
	nodo9* actualbbb = new nodo9();
	actualbbb = primero12;
	bool encontradobbb = false;
	int nodoBuscadobbb = 0;
	cout << " Ingrese el dato del Nodo a Buscar: ";
	cin >> nodoBuscadobbb;
	if (primero12 != NULL) {

		while (actualbbb != NULL && encontradobbb != true) {

			if (actualbbb->dato == nodoBuscadobbb) {
				cout << "\n Nodo con el dato ( " << nodoBuscadobbb << " ) Encontrado\n\n";
				encontradobbb = true;
			}

			actualbbb = actualbbb->siguientedou;
		}

		if (!encontradobbb) {
			cout << "\n Nodo no Encontrado\n\n";
		}

	}
	else {
		cout << "\n La listas se encuentra Vacia\n\n";
	}
	_getch();
}

void modificarNododuo() {
	system("mode con: cols=80 lines=25");
	nodo9* actualmm = new nodo9();
	actualmm = primero12;
	bool encontradomm = false;
	int nodoBuscadomm = 0;
	cout << " Ingrese el dato del Nodo a Buscar para Modificar: ";
	cin >> nodoBuscadomm;
	if (primero12 != NULL) {

		while (actualmm != NULL && encontradomm != true) {

			if (actualmm->dato == nodoBuscadomm) {
				cout << "\n Nodo con el dato ( " << nodoBuscadomm << " ) Encontrado";
				cout << "\n Ingrese el nuevo dato para este Nodo: ";
				cin >> actualmm->dato;
				cout << " Nodo Modificado\n\n";
				encontradomm = true;
			}

			actualmm = actualmm->siguientedou;
		}

		if (!encontradomm) {
			cout << "\n Nodo no Encontrado\n\n";
		}

	}
	else {
		cout << "\n La listas se encuentra Vacia\n\n";
	}
	_getch();
}



void eliminarNododuo() {
	system("mode con: cols=80 lines=25");
	nodo9* actualee = new nodo9();
	actualee = primero12;
	nodo9* anterioree = new nodo9();
	anterioree = NULL;
	bool encontradoee = false;
	int nodoBuscadoee = 0;
	cout << " Ingrese el dato del Nodo a Buscar para Eliminar: ";
	cin >> nodoBuscadoee;
	if (primero12 != NULL) {

		while (actualee != NULL && encontradoee != true) {

			if (actualee->dato == nodoBuscadoee) {
				cout << "\n Nodo con el dato ( " << nodoBuscadoee << " ) Encontrado";

				if (actualee == primero12) {
					primero12 = primero12->siguientedou;
					primero12->atrasduo = NULL;
				}
				else if (actualee == ultimo12) {
					anterioree->siguientedou = NULL;
					ultimo12 = anterioree;
				}
				else {
					anterioree->siguientedou = actualee->siguientedou;
					actualee->siguientedou->atrasduo = anterioree;
				}

				cout << "\n Nodo Eliminado";
				encontradoee = true;
			}
			anterioree = actualee;
			actualee = actualee->siguientedou;
		}

		if (!encontradoee) {
			cout << "\n Nodo no Encontrado\n\n";
		}

	}
	else {
		cout << "\n La listas se encuentra Vacia\n\n";
	}
	_getch();
}

void desplegarListaPUduo() {
	system("mode con: cols=80 lines=25");
	nodo9* actualdede = new nodo9();
	actualdede = primero12;
	if (primero12 != NULL) {

		while (actualdede != NULL) {
			cout << "\n " << actualdede->dato;
			actualdede = actualdede->siguientedou;
		}

	}
	else {
		cout << "\n La listas se encuentra Vacia\n\n";
	}
	_getch();
}

void desplegarListaUPduo() {
	system("mode con: cols=80 lines=25");
	nodo9* actualup = new nodo9();
	actualup = ultimo12;
	if (primero12 != NULL) {

		while (actualup != NULL) {
			cout << "\n " << actualup->dato;
			actualup = actualup->atrasduo;
		}

	}
	else {
		cout << "\n La listas se encuentra Vacia\n\n";
	}
	_getch();
}


//Listas Circulares 
struct nodo10 {
	int dato;
	nodo10* siguientecir;
} *primerocir, * ultimocir;

void insertarNodocir() {
	system("mode con: cols=80 lines=25");
	nodo10* nuevoinsert = new nodo10();
	cout << " Ingrese el dato que contendra el nuevo Nodo: ";
	cin >> nuevoinsert->dato;

	if (primerocir == NULL) {
		primerocir = nuevoinsert;
		primerocir->siguientecir = primerocir;
		ultimocir = primerocir;
	}
	else {
		ultimocir->siguientecir = nuevoinsert;
		nuevoinsert->siguientecir = primerocir;
		ultimocir = nuevoinsert;
	}
	cout << "\n Nodo Ingresado\n\n";
	_getch();
}

void buscarNodocir() {
	system("mode con: cols=80 lines=25");
	nodo10* actualbusc = new nodo10();
	actualbusc = primerocir;
	bool encontradobusc = false;
	int nodoBuscadobusc = 0;
	cout << "\n Ingrese el dato del nodo a Buscar: ";
	cin >> nodoBuscadobusc;
	if (primerocir != NULL) {
		do {

			if (actualbusc->dato == nodoBuscadobusc) {
				cout << "\n El nodo con el dato ( " << nodoBuscadobusc << " ) Encontrado\n\n";
				encontradobusc = true;
			}

			actualbusc = actualbusc->siguientecir;
		} while (actualbusc != primerocir && encontradobusc != true);
		if (!encontradobusc) {
			cout << "\n Nodo No Encontrado\n\n";
		}
	}
	else {
		cout << "\n La lista se encuentra vacia\n\n";
	}
	_getch();
}

void modificarNodocir() {
	system("mode con: cols=80 lines=25");
	nodo10* actualmodif = new nodo10();
	actualmodif = primerocir;
	bool encontradomodif = false;
	int nodoBuscadomodif = 0;
	cout << "\n Ingrese el dato del nodo a Buscar para Modificar: ";
	cin >> nodoBuscadomodif;
	if (primerocir != NULL) {
		do {

			if (actualmodif->dato == nodoBuscadomodif) {
				cout << "\n El nodo con el dato ( " << nodoBuscadomodif << " ) Encontrado";
				cout << "\n Ingrese el nuevo dato para este Nodo: ";
				cin >> actualmodif->dato;
				cout << "\n Nodo Modificado\n\n";
				encontradomodif = true;
			}

			actualmodif = actualmodif->siguientecir;
		} while (actualmodif != primerocir && encontradomodif != true);
		if (!encontradomodif) {
			cout << "\n Nodo No Encontrado\n\n";
		}
	}
	else {
		cout << "\n La lista se encuentra vacia\n\n";
	}
	_getch();
}

void eliminarNodocir() {
	system("mode con: cols=80 lines=25");
	nodo10* actualElimin = new nodo10();
	actualElimin = primerocir;
	nodo10* anteriorElimin = new nodo10();
	anteriorElimin = NULL;
	bool encontradoElimin = false;
	int nodoBuscadoElimin = 0;
	cout << "\n Ingrese el dato del nodo a Buscar para Eliminar: ";
	cin >> nodoBuscadoElimin;
	if (primerocir != NULL) {
		do {

			if (actualElimin->dato == nodoBuscadoElimin) {
				cout << "\n El nodo con el dato ( " << nodoBuscadoElimin << " ) Encontrado";

				if (actualElimin == primerocir) {
					primerocir = primerocir->siguientecir;
					ultimocir->siguientecir = primerocir;
				}
				else if (actualElimin == ultimocir) {
					anteriorElimin->siguientecir = primerocir;
					ultimocir = anteriorElimin;
				}
				else {
					anteriorElimin->siguientecir = actualElimin->siguientecir;
				}

				cout << "\n Nodo Eliminado\n\n";
				encontradoElimin = true;
			}
			anteriorElimin = actualElimin;
			actualElimin = actualElimin->siguientecir;
		} while (actualElimin != primerocir && encontradoElimin != true);
		if (!encontradoElimin) {
			cout << "\n Nodo No Encontrado\n\n";
		}
	}
	else {
		cout << "\n La lista se encuentra vacia\n\n";
	}
	_getch();
}

void desplegarListacir() {
	system("mode con: cols=80 lines=25");
	nodo10* actualdespleg = new nodo10();
	actualdespleg = primerocir;
	if (primerocir != NULL) {
		do {
			cout << "\n " << actualdespleg->dato;
			actualdespleg = actualdespleg->siguientecir;
		} while (actualdespleg != primerocir);
	}
	else {
		cout << "\n La lista se encuentra vacia\n\n";
	}
	_getch();
}



//Arboles

void MenuArbol() {
	system("cls");
	system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	bool repitevool = true;
	int opcabb;

	const char* tituabb = "INGRESO DE DATOS (METODO ABB)";
	const char* opcionesabb[] = { " Agregar elementos al arbol", " Mostrar el arbol completo", " Buscar un elemento ", " Eliminar un nodo del arbol", " Salir" };
	int ndatoabb = 5;
	int datoxabb, opcionabbdato, contadorabb = 0;

	do {
		opcabb = menu(tituabb, opcionesabb, ndatoabb);
		switch (opcabb) {
		case 1:
			system("cls");
			cout << "Ingrese el numero del producto: ";
			cin >> datoxabb;
			agregarNodoABB(arbol, datoxabb, NULL);
			cout << "\n";
			system("pause");
			break;
		case 2:
			system("cls");
			cout << "\nMostrando el arbol completo: \n\n";
			mostrarArbolABB(arbol, contadorabb);
			cout << "\n";
			system("pause");
			break;
		case 3:
			system("cls");
			cout << "\n Digite el producto a buscar:  ";
			cin >> datoxabb;

			if (busquedaABB(arbol, datoxabb) == true) {

				cout << "\nElemento " << datoxabb << " a sido encotrado en el arbol\n";
			}
			else {
				cout << "\nElemento no encontrado";
			}
			cout << "\n";
			system("pause");
			break;
		case 4:
			system("cls");
			cout << "\n digite el numero a eliminar:  ";
			cin >> datoxabb;
			eliminarABB(arbol, datoxabb);
			cout << "\n";
			system("pause");
			break;
		}
		system("cls");
	} while (opcabb != 5);
}

nodo* crearNodoABB(int n, nodo* padre) {
	nodo* NuevoNodoABB = new nodo();
	NuevoNodoABB->datoABB = n;
	NuevoNodoABB->derABB = NULL;
	NuevoNodoABB->izqABB = NULL;
	NuevoNodoABB->padreABB = padre;

	return NuevoNodoABB;
}

void agregarNodoABB(nodo*& arbol, int n, nodo* padre) {
	system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	if (arbol == NULL) {//verificando que arbol este vacio.
		nodo* nuevoNodo = crearNodoABB(n, padre);//agregando la raiz al nuevo nodo.
		arbol = nuevoNodo;
	}
	else {
		int ValorDeRaiz = arbol->datoABB;//Es para saber que valor tiene la RAIZ.
		if (n < ValorDeRaiz) {//Cuando el Valor es menor va al lado izquierdo.
			agregarNodoABB(arbol->izqABB, n, arbol);//Agregando al lado izquierdo.
		}
		else {
			agregarNodoABB(arbol->derABB, n, arbol);//Agregando al lado derecho.

		}
	}
}

void mostrarArbolABB(nodo* arbol, int cont) {

	system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	if (arbol == NULL) {
		return;
	}
	else
	{
		for (int i = 0; i < cont; i++) {
			cout << "   ";
			mostrarArbolABB(arbol->derABB, cont + 1);
			cout << arbol->datoABB << endl;
			mostrarArbolABB(arbol->izqABB, cont + 1);
		}
	}
}

bool busquedaABB(nodo* arbol, int n) {
	system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	if (arbol == NULL) { //si el arbol esta vacio
		return false;
	}
	else if (arbol->datoABB == n) { //si el nodo es igual al elemento
		return true;
	}
	else if (n < arbol->datoABB) {
		return busquedaABB(arbol->izqABB, n);
	}
	else {
		return busquedaABB(arbol->derABB, n);
	}
}
//funcion destruir nodo
void destruirNodoABB(nodo* nodo) {
	nodo->izqABB = NULL;
	nodo->derABB = NULL;

	delete nodo;
}

//funcion para encontronra un nodo
void eliminarABB(nodo* arbol, int n) {
	system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	if (arbol == NULL) { // si el arbol esta vacio
		return;   // no hace nada
	}
	else if (n < arbol->datoABB) { //si el valor es menor
		eliminarABB(arbol->izqABB, n); //busca por la izquierda
	}
	else if (n > arbol->datoABB) { //si el valor es mayor
		eliminarABB(arbol->derABB, n); //busca por la derecha
	}
	else {//si ya encontrate el valor
		eliminarNodoABB(arbol);
	}
}

//determinar el nodo m�s izquierdo posible
nodo* minimoABB(nodo* arbol) {  //si el arbol esta vacio
	system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	if (arbol == NULL) {  //retrona nulo
		return NULL;
	}
	if (arbol->izqABB) {  // si tiene hijo izquierdo
		return minimoABB(arbol->izqABB);  //busca la parte mas izquierda posible
	}
	else {  //si no tiene hijo izq
		return arbol;  //retorna el mismo nodo
	}
}

//funcion para remplazar dos nodos
void reemplazarABB(nodo* arbol, nodo* nuevoNodo) {
	system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	if (arbol->padreABB) {
		//arbol->padre hay que asignarle su nuevo hijo
		if (arbol->datoABB == arbol->padreABB->izqABB->datoABB) {
			arbol->padreABB->izqABB = nuevoNodo;
		}
		else if (arbol->datoABB == arbol->padreABB->derABB->datoABB) {
			arbol->padreABB->derABB = nuevoNodo;
		}
	}
	if (nuevoNodo) {
		//Procedmos a asignarle su nuevo padre
		nuevoNodo->padreABB = arbol->padreABB;
	}
}

//funcion para elminiar nodo encontrado
void eliminarNodoABB(nodo* nodoEliminar) {
	system("mode con: cols=80 lines=25"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
	if (nodoEliminar->izqABB && nodoEliminar->derABB) {//si el nodo tiene hijo izquierdo y derecho
		nodo* menor = minimoABB(nodoEliminar->derABB);
		nodoEliminar->datoABB = menor->datoABB;
		eliminarNodoABB(menor);
	}
	else if (nodoEliminar->izqABB) {  //si tiene hijo izquierdo
		reemplazarABB(nodoEliminar, nodoEliminar->izqABB);
		destruirNodoABB(nodoEliminar);
	}
	else if (nodoEliminar->derABB) { //si tiene un hijo drecho
		reemplazarABB(nodoEliminar, nodoEliminar->derABB);
		destruirNodoABB(nodoEliminar);
	}
	else {//No tiene hijos
		reemplazarABB(nodoEliminar, NULL);
		destruirNodoABB(nodoEliminar);
	}
}
