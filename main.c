#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "gotoxy.h"
#include <windows.h>
///************************************************************ TP FINAL **************************************************************************************************

typedef struct {
    int id;
    int nroCliente;
    char nombre[30];
    char apellido [30];
    char dni[10];
    char email[30];
    char domicilio[45];
    char movil[12];
    int estado;
} stClientes;

typedef struct {
    int id;
    int idCliente;
    int anio;
    int mes;
    int dia;
    int datosConsumidos;
    int estado;
} stConsumos;


///PROT MENUES
char menuInicial();
char menuAltas();
char menuListados();
char menuBusca();
char menuModifica();
char menuConsumos();
char menuListadosCons();
char menuBusquedaCons();
char menuModificaCons();

/// PROT CLIENTES
void altaCliente (char archivo[]);
int cuentaRegistros(char archivo[], int tamanioSt);
void muestraUnCliente (stClientes cliente);
void muestraListaClientes (char archivo []);
void listaPorEstado(char archivo[], int estado);
int validaEmail(stClientes cliente);
int validaEmailChar(char a []);
void ubicaRegistroDni (char archivo [], char dni []);
void ubicaRegistroNroCliente (char archivo [], int nroCliente);
void ubicaRegistroMovil (char archivo [], char nroMovil []);
void ubicaRegistroEmail (char archivo [], char email []);
void modificaEmail(char archivo[], char eMailNEW [], char eMailActual []);
void modificaMovil(char archivo[], char movilNew [], char movilActual []);
void modificaDni(char archivo[], char dniNew [], char dniActual []);
void modificaEstado(char archivo[], int nroCliente);


/// PROT CONSUMOS
void muestraUnConsumo (stConsumos con);
void muestraListaConsumos (char archivo []);
void listaConsPorEstado(char archivo[], int estado);
void buscaConsumo(stConsumos con);
char menuConsumo();
void buscaConsumoPorFecha (char archivo[]);
stConsumos busquedaFecha();
void buscaConsumoPorIdCliente (char archivo[], int datoCliente);
int compruebaIdCliente(int idCliente);
int cargaMes(stConsumos con,int dato);
int cargaDia (stConsumos con, int mes[], int dato, int dato2);
int cargaAnio(stConsumos con, int mes[]);
int anioActual();
int mesActual();
void modificaFecha(char archivo[], int dato);
void modificaIdCliente(char archivo[], int dato);
void modificaDatosConsumidos(char archivo[], int dato);
void eliminaConsumo(char archivo[], int dato);
void cargaConsumoAleatorio (char archivo []);
void modificaCons(char archivo[], int idCarga, int consNew);
void buscaConsumoPorId (char archivo[], int idcarga);
void modificaEstadoCons(char archivo[], int idcarga);
int cargaDatosConsumidos (char archivo[],stConsumos nuevo);
void cargaNuevoConsumo (char archivo[], stConsumos nuevo);

int main() {
    char opcion;
    char opcionAltas;
    char opcionListados;
    char opcionBusca;
    char opcionModifica;
    char opcionConsumos;
    char opcionListadosCons;
    char opcionBusquedaCons;
    char opcionModificaCons;
    int emailValido=0;
    char dni [12];
    int nroCliente=0;
    char nroMovil [12];
    char eMail [30];
    char eMailActual [30];
    char eMailNew [30];
    char movilActual [30];
    char movilNew [30];
    char dniActual [30];
    char dniNew [30];
    int confirmacion=0;
    int idCarga=0;
    int consNew=0;
    int idCliente=0;


    ///PATO
    int x;
    int y;
    x=7;
    y=5;
    hidecursor(0);
    Beep(300,40);
    color(10);
    while (x<12) {
        gotoxy(x,y);
        printf("PATO");
        Sleep(80);
        system("cls");
        y--;
        x++;

    }

    Beep(200,100);
    while (x<17) {
        gotoxy(x,y);
        printf("   PATO");
        Sleep(80);
        system("cls");
        y++;
        x++;

    }
    gotoxy(x,y);
    printf("   PATO                       El      no me habla...");
    Sleep(800);
    Beep(300,40);

    while (x<22) {
        gotoxy(x,y);
        printf("   PATO");
        Sleep(80);
        system("cls");
        y--;
        x++;

    }
    Beep(200,100);
    while (x<27) {
        gotoxy(x,y);
        printf("   PATO");
        Sleep(80);
        system("cls");
        y++;
        x++;

    }
    gotoxy(x,y);
    printf("   PATO             El      no me habla...");
    Sleep(800);
    Beep(300,40);
    while (x<32) {
        gotoxy(x,y);
        printf("   PATO");
        Sleep(80);
        system("cls");
        y--;
        x++;

    }
    Beep(200,100);
    while (x<37) {
        gotoxy(x,y);
        printf("   PATO");
        Sleep(80);
        system("cls");
        y++;
        x++;

    }
    gotoxy(x,y);
    printf("   PATO   El      no me habla...");
    Sleep(800);
    Beep(300,40);
    while (x<42) {
        gotoxy(x,y);
        printf("   PATO");
        Sleep(80);
        system("cls");
        y--;
        x++;

    }
    Beep(200,100);
    while (x<47) {
        gotoxy(x,y);
        printf("   PATO");
        Sleep(80);
        system("cls");
        y++;
        x++;

    }
    int i=0;
    gotoxy(x,y);
    printf("El PATO no me habla...");
    Sleep(200);
    while(i!=-1) {
        color(i);
        i++;
        gotoxy(x,y);
        printf("El PATO no me habla...");
        Sleep(200);
        if(kbhit()) {
            i=-1;
            gotoxy(x,y);
            color(10);
            printf("El PATO no me habla...");
            printf("\n\n\n\n\t\t\t\t\t\t       by\n");
            printf("\n\n\n\n\t\t\t Victor Silva \t\t\ Franco Consorti \t\t\ Marcos Rosti\n\n\n\n");
            printf("\n\t\t\t\t\t\      Docente: Sergio Garguir \t\t\ \n\n\n\n\n\n\n\n\n");
            color(7);
            system("pause");
        }
    }


    do {
        opcion=menuInicial();

        switch(opcion) {
        case '1':
            /// MENU CLIENTES!!!!!!!!
            do {
                opcionAltas=menuAltas();
                switch(opcionAltas) {
                case '1':
                    ///altas clientes
                    altaCliente("clientes.dat");
                    break;
                case '2':
                    /// GENERAL LISTADOS
                    do {
                        opcionListados=menuListados();
                        switch(opcionListados) {
                        case '1':
                            ///lista clientes activos
                            listaPorEstado("clientes.dat", 0);;
                            system("pause");
                            break;
                        case '2':
                            ///lista clientes inactivos
                            listaPorEstado("clientes.dat", 1);
                            system("pause");
                            break;
                        case '3':
                            /// listado general de clientes
                            muestraListaClientes("clientes.dat");
                            system("pause");
                            break;
                        }
                    } while(opcionListados!=27);
                    break;
                case '3':
                    /// GENERAL BUSQUEDAS
                    do {
                        opcionBusca=menuBusca();
                        switch(opcionBusca) {
                        case '1':
                            ///Busca por Nro de Cliente
                            printf("\t\t\n Ingrese Nro de Cliente a buscar: ");
                            scanf("%d",&nroCliente);
                            ubicaRegistroNroCliente("clientes.dat", nroCliente);
                            system("pause");
                            break;
                        case '2':
                            ///Busca por DNI
                            printf("\t\t\n Ingrese DNI a buscar: ");
                            fflush(stdin);
                            scanf("%s",dni);
                            ubicaRegistroDni("clientes.dat", dni);
                            system("pause");
                            break;
                        case '3':
                            ///Busca por Movil
                            printf("\t\t\n Ingrese Nro de movil a buscar: ");
                            fflush(stdin);
                            scanf("%s",nroMovil);
                            ubicaRegistroMovil("clientes.dat", nroMovil);
                            system("pause");
                            break;
                        case '4':
                            ///Busca por Email
                            printf("\t\t\n Ingrese Email a buscar: ");
                            fflush(stdin);
                            scanf("%s",eMail);
                            ubicaRegistroEmail("clientes.dat", eMail);
                            system("pause");
                            break;
                        }
                    } while(opcionBusca!=27);

                    break;
                case '4':
                    /// GENERAL MODIFICACIONES
                    do {
                        opcionModifica=menuModifica();
                        switch(opcionModifica) {
                        case '1':
                            ///modifica mail
                            printf("Ingrese Email actual:  ");
                            gets(&eMailActual);
                            ubicaRegistroEmail("clientes.dat", eMailActual);
                            do {
                                printf("\n\n Ingrese nuevo Email:  ");
                                gets(&eMailNew);
                                emailValido=validaEmailChar(eMailNew);
                                if(emailValido==0) {
                                    printf("Email ingresado no es valido, Reingrese:  ");
                                }
                            } while (emailValido==0);
                            modificaEmail("clientes.dat", eMailNew, eMailActual);
                            printf("\nEl Email ha sido reemplazado con exito!");
                            system("pause");

                            break;

                        case '2':
                            ///modifica movil
                            printf("Ingrese Nro de movil actual:  ");
                            gets(&movilActual);
                            ubicaRegistroMovil("clientes.dat", movilActual);
                            printf("\n\n Ingrese nuevo Nro de movil:  ");
                            gets(&movilNew);
                            modificaMovil("clientes.dat", movilNew, movilActual);
                            printf("\nEl Nro de movil ha sido reemplazado con exito!");
                            system("pause");
                            break;

                        case '3':
                            ///modifica DNI
                            printf("Ingrese DNI actual:  ");
                            gets(&dniActual);
                            ubicaRegistroDni("clientes.dat", dniActual);
                            printf("\n\n Ingrese nuevo DNI:  ");
                            gets(&dniNew);
                            modificaDni("clientes.dat", dniNew, dniActual);
                            printf("\nEl DNI ha sido reemplazado con exito!");
                            system("pause");
                            break;

                        case '4':
                            ///modifica estado
                            printf("Ingrese Nro de cliente:  ");
                            scanf("%d",&nroCliente);
                            ubicaRegistroNroCliente("clientes.dat", nroCliente);
                            printf("\n\n Seguro desea modificar???? 1 (si) / 2 (no)");
                            scanf("%d", &confirmacion);
                            if (confirmacion==1) {
                                modificaEstado("clientes.dat", nroCliente);
                                printf("\n\n\nEl estado del cliente ha sido reemplazado con exito!\n\n\n");
                            } else {
                                printf("\n\n La modificacion se ha cancelado\n\n");
                            }
                            system("pause");
                            break;
                        }
                    } while(opcionModifica!=27);
                    break;
                }


            } while(opcionAltas!=27);
            break;
        case '2':
            /// consumos
            do {
                opcionConsumos=menuConsumos();
                switch(opcionConsumos) {
                case '1':
                    ///altas
                    altaConsumo("consumos.dat");
                    break;
                case '2':
                    ///listados
                    do {
                        opcionListadosCons=menuListadosCons();
                        switch(opcionListadosCons) {
                        case '1':
                            ///lista consumos activos
                            listaConsPorEstado("consumos.dat", 0);
                            system("pause");
                            break;
                        case '2':
                            ///lista consumos inactivos
                            listaConsPorEstado("consumos.dat", 1);
                            system("pause");
                            break;
                        case '3':
                            /// listado general
                            muestraListaConsumos("consumos.dat");
                            system("pause");
                            break;
                        }
                    } while(opcionListadosCons!=27);
                    break;
                    break;
                case '3':
                    ///busquedas
                    do {
                        opcionBusquedaCons=menuBusquedaCons();
                        switch(opcionBusquedaCons) {
                        case '1':
                            ///busca por fecha
                            buscaConsumoPorFecha("consumos.dat");
                            system("pause");
                            break;
                        case '2':
                            ///busca consumos por IDcliente
                            printf("\n Ingrese el numero de ID del cliente\n");
                            scanf("%d", &idCliente);
                            buscaConsumoPorIdCliente ("consumos.dat", idCliente);
                            system("pause");
                            break;
                        }
                    } while(opcionBusquedaCons!=27);
                    break;
                    break;
                case '4':
                    ///modificaciones
                    do {
                        opcionModificaCons=menuModificaCons();
                        switch(opcionModificaCons) {
                        case '1':
                            ///modifica estado de consumo
                            printf("Ingrese ID de consumo:  ");
                            scanf("%d",&idCarga);
                            buscaConsumoPorId("consumos.dat", idCarga);
                            printf("\n\n Seguro desea modificar???? 1 (si) / 2 (no)");
                            scanf("%d", &confirmacion);
                            if (confirmacion==1) {
                                modificaEstadoCons("consumos.dat", idCarga);
                                printf("\n\n\nEl estado del consumo ha sido reemplazado con exito!\n\n\n");
                            } else {
                                printf("\n\n La modificacion se ha cancelado\n\n");
                            }
                            system("pause");
                            break;
                        case '2':
                            ///modifica la fecha de un consumo por ID
                            idCarga=0;
                            printf("Ingrese ID del consumo a modificar:  ");
                            scanf("%d", &idCarga);
                            buscaConsumoPorId("consumos.dat", idCarga);
                            modificaFecha("consumos.dat", idCarga);
                            printf("\nLa fecha ha sido modificada con exito!");
                            system("pause");
                            break;

                        case '3':///modifica consumo (datos consumidos)
                            printf("Ingrese ID del consumo a modificar:  ");
                            scanf("%d", &idCarga);
                            buscaConsumoPorId("consumos.dat", idCarga);
                            printf("\n\n Ingrese nuevo consumo:  ");
                            scanf("%d", &consNew);
                            modificaCons("consumos.dat", idCarga, consNew);
                            printf("\nEl consumo ha sido reemplazado con exito!");
                            system("pause");
                            break;

                            break;
                        }
                    } while(opcionModificaCons!=27);
                    break;
                case '5':
                    ///carga consumos RANDOM
                    cargaConsumoAleatorio("consumos.dat");
                    system("pause");
                    break;

                    break;
                }
            } while(opcionConsumos!=27);
            break;
            break;
        }
    } while(opcion!=27);
    return 0;
}
///FUNCIONES///

char menuInicial() {
    char opcion;


    system("cls");
    system("color 3F");
    printf("\n\t\t\t Bienvenidos al sistema!!!\n\n");
    printf("\n 1 - Clientes");
    printf("\n 2 - Consumos");
    printf("\n\nESC para salir");
    printf("\n\t Elija una opcion\n\n");

    opcion=getch();

    return opcion;
}
char menuAltas() {
    char opcionAltas;


    system("cls");
    system("color 3F");
    printf("\n\t\t\t Menu Clientes!!!\n\n");
    printf("\n 1 - Altas");
    printf("\n 2 - Listados");
    printf("\n 3 - Busquedas");
    printf("\n 4 - Modificaciones");

    printf("\n\nESC para salir");
    printf("\n\t Elija una opcion\n\n");

    opcionAltas=getch();

    return opcionAltas;
}
char menuListados() {
    char opcionListados;


    system("cls");
    system("color 3F");
    printf("\n\t\t\t Menu Clientes!!!\n\n");
    printf("\n 1 - Lista Clientes Activos");
    printf("\n 2 - Lista Clientes Inactivos");
    printf("\n 3 - Listado Total de clientes");
    printf("\n\nESC para salir");
    printf("\n\t Elija una opcion\n\n");

    opcionListados=getch();

    return opcionListados;
}


char menuBusca() {
    char opcionBusca;


    system("cls");
    system("color 3F");
    printf("\n\t\t\t Menu Busquedas!!!\n\n");
    printf("\n 1 - Busca por Nro de Cliente");
    printf("\n 2 - Busca por Nro DNI");
    printf("\n 3 - Busca por Nro Movil");
    printf("\n 4 - Busca por Email");


    printf("\n\nESC para salir");
    printf("\n\t Elija una opcion\n\n");

    opcionBusca=getch();

    return opcionBusca;
}

char menuModifica() {
    char opcionModifica;


    system("cls");
    system("color 3F");
    printf("\n\t\t\t Menu de modificaciones!!!\n\n");
    printf("\n 1 - Modifica Email");
    printf("\n 2 - Modifica Nro de movil");
    printf("\n 3 - Modifica DNI");
    printf("\n 4 - Modifica Estado del cliente");
    printf("\n\nESC para salir");
    printf("\n\t Elija una opcion\n\n");

    opcionModifica=getch();

    return opcionModifica;
}

char menuConsumos() {
    char opcionConsumos;

    system("cls");
    system("color 3F");
    printf("\n\t\t\t Menu Consumos!!!\n\n");
    printf("\n 1 - Altas");
    printf("\n 2 - Listados");
    printf("\n 3 - Busquedas");
    printf("\n 4 - Modificaciones");
    printf("\n 5 - Carga consumos RANDOM");

    printf("\n\nESC para salir");
    printf("\n\t Elija una opcion\n\n");

    opcionConsumos=getch();

    return opcionConsumos;
}

char menuListadosCons() {
    char opcionListadosCons;


    system("cls");
    system("color 3F");
    printf("\n\t\t\t Menu listados de consumos!!!\n\n");
    printf("\n 1 - Lista consumos en estado activo");
    printf("\n 2 - Lista consumos en estado inactivo");
    printf("\n 3 - Listado general de Consumos");
    printf("\n\nESC para salir");
    printf("\n\t Elija una opcion\n\n");

    opcionListadosCons=getch();

    return opcionListadosCons;
}

char menuBusquedaCons() {
    char opcionBusquedaCons;


    system("cls");
    system("color 3F");
    printf("\n\t\t\t Menu busqueda de consumos!!!\n\n");
    printf("\n 1 - Busca consumos por fecha");
    printf("\n 2 - Busca consumos por cliente");
    printf("\n\nESC para salir");
    printf("\n\t Elija una opcion\n\n");

    opcionBusquedaCons=getch();

    return opcionBusquedaCons;
}

char menuModificaCons() {
    char opcionModificaCons;


    system("cls");
    system("color 3F");
    printf("\n\t\t\t Menu modificaciones de consumos!!!\n\n");
    printf("\n 1 - Modifica estado de consumo");
    printf("\n 2 - Modifica fecha de consumo");
    printf("\n 3 - Modifica Consumo por ID");
    printf("\n\nESC para salir");
    printf("\n\t Elija una opcion\n\n");

    opcionModificaCons=getch();

    return opcionModificaCons;
}


///************************************************** F U N C I O N E S   C L I E N T E S ****************************************************************************


///ALTA DE CLIENTES////

void altaCliente (char archivo[]) {
    int emailValido=0;
    char opcion=0;
    int id = cuentaRegistros("clientes.dat", sizeof(stClientes));
    stClientes cliente;
    FILE *pClientes = fopen(archivo,"ab");
    if (pClientes!= NULL) {
        do {
            do {

                printf("\n Nro de Cliente............: ");
                scanf("%d", &cliente.nroCliente);
                if (CompruebaNumCliente(cliente.nroCliente)==1) {
                    printf("El numero de clientes ingresado ya existe-Ingrese otro");
                }
            } while(CompruebaNumCliente(cliente.nroCliente)==1);

            printf("\n Nombre....................: ");
            fflush(stdin);
            gets(&cliente.nombre);
            printf("\n Apellido..................: ");
            fflush(stdin);
            gets(&cliente.apellido);
            printf("\n DNI.......................: ");
            fflush(stdin);
            gets(&cliente.dni);
            do {
                printf("\n Email.....................: ");
                fflush(stdin);
                gets(&cliente.email);
                emailValido=validaEmail(cliente);
                if(emailValido==0) {
                    printf("Email ingresado no es valido, Reingrese");
                }
            } while (emailValido==0);
            printf("\n Domicilio.................: ");
            fflush(stdin);
            gets(&cliente.domicilio);
            printf("\n Movil.....................: ");
            fflush(stdin);
            gets(&cliente.movil);
            cliente.estado=0;
            id++;
            cliente.id = id;

            fwrite(&cliente, sizeof(stClientes), 1, pClientes);
            printf("\n ESC para salir, otra para continuar...");
            opcion=getch();
            system("cls");
        } while(opcion!=27);
        fclose(pClientes);
    } else {
        printf("/n ERROR DE APERTURA DE ARCHIVO ");
    }
}

/// VALIDA QUE EL MAIL INGRESADO CONTENGA @
int validaEmail(stClientes cliente) {
    int flag=0;
    char caracter = '@';
    char caracterEnCadena[] = {caracter, '\0'};

    if (strstr(cliente.email, caracterEnCadena) != NULL) {
        flag=1;
    }

    return flag;
}
/// Valida email de char
int validaEmailChar(char eMailNew []) {
    int flag=0;
    char caracter = '@';
    char caracterEnCadena[] = {caracter, '\0'};

    if (strstr(eMailNew, caracterEnCadena) != NULL) {
        flag=1;
    }

    return flag;
}

/// VALIDA SI NUM DE CLIENTE YA EXISTE
int CompruebaNumCliente (int numCliente) {
    int flag = 0;
    stClientes cliente;
    FILE *pCliente=fopen("clientes.dat","rb");
    if (pCliente) {
        while(flag==0 && fread(&cliente,sizeof(stClientes),1,pCliente)>0) {
            if (cliente.nroCliente==numCliente) {
                flag=1;
                return flag;
            }
        }
        fclose(pCliente);
    }
    return flag;
}


///MUESTRA UN CLIENTE ////
void muestraUnCliente (stClientes cliente) {

    printf("\n Id........................: %d", cliente.id);
    printf("\n Nro de Cliente............: %d", cliente.nroCliente);
    printf("\n Nombre....................: %s", cliente.nombre);
    printf("\n Apellido..................: %s", cliente.apellido);
    printf("\n DNI.......................: %s", cliente.dni);
    printf("\n Email.....................: %s", cliente.email);
    printf("\n Domicilio.................: %s", cliente.domicilio);
    printf("\n Movil.....................: %s", cliente.movil);
    printf("\n Situacion del cliente.....: %d", cliente.estado);
    printf("\n-------------------------------------------------------");
}
///MUESTRA LISTADO DE CLIENTES ////

void muestraListaClientes (char archivo []) {
    stClientes cliente;
    FILE *pClientes = fopen(archivo, "rb");
    if(pClientes != NULL) {
        while(fread(&cliente, sizeof(stClientes), 1, pClientes)>0) {
            muestraUnCliente(cliente);
        }
        fclose(pClientes);

    } else {
        printf("/n ERROR DE APERTURA DE ARCHIVO ");
    }
}

///CUENTA REGISTROS DE UN ARCHIVO///

int cuentaRegistros(char archivo[], int tamanioSt) {

    int cantidadRegistros = 0;
    FILE *pArchi = fopen(archivo, "rb");

    if(pArchi) {
        fseek(pArchi, 0, SEEK_END);
        cantidadRegistros=ftell(pArchi)/tamanioSt;
        fclose(pArchi);
    }

    return cantidadRegistros;
}
/// MUESTRA REGISTROS INACTIVOS O ACTIVOS SEGUN PARAMETRO
void listaPorEstado(char archivo[], int estado) {
    stClientes cliente;
    FILE *pArchi = fopen(archivo, "rb");

    if(pArchi) {
        while(fread(&cliente, sizeof(stClientes), 1, pArchi)>0) {
            if (estado==cliente.estado) {
                muestraUnCliente(cliente);
            }
        }
        fclose(pArchi);
    }
}

///Busca registro por Nro de Cliente
void ubicaRegistroNroCliente (char archivo [], int nroCliente) {
    int flag=0;
    stClientes cliente;
    FILE *pArchi = fopen(archivo, "rb");
    if(pArchi) {
        while(fread(&cliente, sizeof(stClientes), 1, pArchi)>0) {

            if(cliente.nroCliente == nroCliente) {
                muestraUnCliente(cliente);
                flag=1;
            }
        }
        fclose(pArchi);
    } else {
        printf("/n ERROR DE APERTURA DE ARCHIVO ");
    }
    if(flag==0) {
        printf("\nNo existe");
    }
}

///Busca registro por Nro de movil
void ubicaRegistroMovil (char archivo [], char nroMovil []) {
    int flag=0;
    stClientes cliente;
    FILE *pArchi = fopen(archivo, "rb");
    if(pArchi) {
        while(fread(&cliente, sizeof(stClientes), 1, pArchi)>0) {

            if(strcmp(cliente.movil,nroMovil)==0) {
                muestraUnCliente(cliente);
                flag=1;
            }
        }
        fclose(pArchi);
    } else {
        printf("/n ERROR DE APERTURA DE ARCHIVO ");
    }
    if(flag==0) {
        printf("\nNo existe");
    }
}

///Busca registro por DNI
void ubicaRegistroDni (char archivo [], char dni []) {
    int flag=0;
    stClientes cliente;
    FILE *pArchi = fopen(archivo, "rb");
    if(pArchi) {
        while(fread(&cliente, sizeof(stClientes), 1, pArchi)>0) {

            if(strcmp(cliente.dni,dni)==0) {
                muestraUnCliente(cliente);
                flag=1;
            }
        }
        fclose(pArchi);
    } else {
        printf("/n ERROR DE APERTURA DE ARCHIVO ");
    }
    if(flag==0) {
        printf("\nNo existe");
    }
}
///Busca registro por Email
void ubicaRegistroEmail (char archivo [], char email []) {
    int flag=0;

    stClientes cliente;
    FILE *pArchi = fopen(archivo, "rb");
    if(pArchi) {
        while(fread(&cliente, sizeof(stClientes), 1, pArchi)>0) {

            if(strcmp(cliente.email,email)==0) {

                muestraUnCliente(cliente);
                flag=1;
            }
        }
        fclose(pArchi);
    } else {
        printf("/n ERROR DE APERTURA DE ARCHIVO ");
    }
    if(flag==0) {
        printf("\nNo existe");
    }

}

///MODIFICACIONES

///Modifica campo Email
void modificaEmail(char archivo[], char eMailNew [], char eMailActual []) {
    stClientes cliente;
    int flag=0;
    int pos=0;
    FILE *pArchi = fopen(archivo, "r+b");
    if(pArchi) {
        while(flag==0 && fread(&cliente, sizeof(stClientes), 1, pArchi)>0) {
            if(strcmp(cliente.email, eMailActual)==0) {
                strcpy(cliente.email, eMailNew);
                pos=ftell(pArchi)-sizeof(stClientes);
                fseek(pArchi,pos,SEEK_SET);
                fwrite(&cliente, sizeof(stClientes), 1, pArchi);
                flag=1;
            }
        }
    }
    fclose(pArchi);
}

///Modifica campo movil
void modificaMovil(char archivo[], char movilNew [], char movilActual []) {
    stClientes cliente;
    int flag=0;
    int pos=0;
    FILE *pArchi = fopen(archivo, "r+b");
    if(pArchi) {
        while(flag==0 && fread(&cliente, sizeof(stClientes), 1, pArchi)>0) {
            if(strcmp(cliente.movil, movilActual)==0) {
                strcpy(cliente.movil, movilNew);
                pos=ftell(pArchi)-sizeof(stClientes);
                fseek(pArchi,pos,SEEK_SET);
                fwrite(&cliente, sizeof(stClientes), 1, pArchi);
                flag=1;
            }
        }
    }
    fclose(pArchi);
}

///Modifica DNI
void modificaDni(char archivo[], char dniNew [], char dniActual []) {
    stClientes cliente;
    int flag=0;
    int pos=0;
    FILE *pArchi = fopen(archivo, "r+b");
    if(pArchi) {
        while(flag==0 && fread(&cliente, sizeof(stClientes), 1, pArchi)>0) {
            if(strcmp(cliente.dni, dniActual)==0) {
                strcpy(cliente.dni, dniNew);
                pos=ftell(pArchi)-sizeof(stClientes);
                fseek(pArchi,pos,SEEK_SET);
                fwrite(&cliente, sizeof(stClientes), 1, pArchi);
                flag=1;
            }
        }
    }
    fclose(pArchi);
}

///modifica situacion de cliente (baja o alta)
void modificaEstado(char archivo[], int nroCliente) {
    stClientes cliente;
    int flag=0;
    int pos=0;
    FILE *pArchi = fopen(archivo, "r+b");
    if(pArchi) {
        while(flag==0 && fread(&cliente, sizeof(stClientes), 1, pArchi)>0) {
            if(cliente.nroCliente==nroCliente) {
                if(cliente.estado==1){
                    cliente.estado=0;
                }else{
                    cliente.estado=1;
                }
                pos=ftell(pArchi)-sizeof(stClientes);
                fseek(pArchi,pos,SEEK_SET);
                fwrite(&cliente, sizeof(stClientes), 1, pArchi);
                flag=1;
            }
        }
    }
    fclose(pArchi);
}


///********************************************************* F U N C I O N E S    C O N S U M O S **************************************************************************

///ALTA DE CONSUMOS

void altaConsumo (char archivoConsumos[]) {
    int mes[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
    int validacionId=0;
    int flag=0;
    char opcion=0;
    int id = cuentaRegistros("consumos.dat", sizeof(stConsumos));
    stConsumos con;
        do {
            validacionId=0;
            while(validacionId==0) {

                printf("\n Ingrese Id de Cliente................: ");
                scanf("%d", &con.idCliente);
                validacionId=compruebaIdCliente(con.idCliente);
                if(validacionId==0) {
                    printf("El cliente no existe\n");
                    system("pause");
                    system("cls");
                }
            }
            con.anio=cargaAnio(con, mes);
            con.mes=cargaMes(con,con.anio);
            con.dia=cargaDia(con, mes, con.mes,con.anio);
            printf("\n Datos consumidos...........: ");
            scanf("%d", &con.datosConsumidos);
            flag=cargaDatosConsumidos("consumos.dat", con);
                    con.estado=0;
                    if (flag==1){
                    id++;
                    con.id=id;
                    cargaNuevoConsumo("consumos.dat", con);
            }
            printf("\n ESC para salir, otra para continuar...");
            opcion=getch();
            system("cls");

        } while(opcion!=27);

}

void muestraUnConsumo (stConsumos con) {

        printf("\n Id........................: %d", con.id);
        printf("\n Id de Cliente.............: %d", con.idCliente);
        printf("\n A%co......................: %d",164, con.anio);
        printf("\n Mes.......................: %d", con.mes);
        printf("\n Dia.......................: %d", con.dia);
        printf("\n Datos consumidos..........: %d", con.datosConsumidos);
        printf("\n Estado....................: %d", con.estado);///0 para inactivo, 1 para activo
        printf("\n-------------------------------------------------------");

}

///MUESTRA LISTADO DE CONSUMO///
void muestraListaConsumos (char archivo []) {
    stConsumos con;
    FILE *pConsumo= fopen("consumos.dat", "rb");
    if(pConsumo) {
        fseek(pConsumo,0, SEEK_SET );
        while(fread(&con, sizeof(stConsumos), 1, pConsumo)>0) {
            muestraUnConsumo(con);
        }
        fclose(pConsumo);

    } else {
        printf("/n ERROR DE APERTURA DE ARCHIVO ");
    }
}

void listaConsPorEstado(char archivo[], int estado) {
    stConsumos con;
    FILE *pArchi = fopen(archivo, "rb");

    if(pArchi) {
        while(fread(&con, sizeof(stConsumos), 1, pArchi)>0) {
            if (estado==con.estado) {
                muestraUnConsumo(con);
            }
        }
        fclose(pArchi);
    }
}

void buscaConsumoPorFecha (char archivo[]) {
    stConsumos con;
    stConsumos fecha;
    fecha=busquedaFecha(&fecha);
    FILE *pArchiCons= fopen(archivo, "rb");
    if(pArchiCons != NULL) {
        while(fread(&con, sizeof(stConsumos), 1, pArchiCons)>0) {
            if(con.anio==fecha.anio && con.mes==fecha.mes && con.dia==fecha.dia) {
                muestraUnConsumo(con);
            }

        }
        fclose(pArchiCons);

    } else {
        printf("/n ERROR DE APERTURA DE ARCHIVO ");
    }
}

void buscaConsumoPorIdCliente (char archivo[], int datoCliente) {
    stConsumos con;


    FILE *pArchiCons= fopen(archivo, "rb");
    if(pArchiCons != NULL) {
        while(fread(&con, sizeof(stConsumos), 1, pArchiCons)>0) {
            if(con.idCliente==datoCliente) {
                muestraUnConsumo(con);
            }

        }
        fclose(pArchiCons);

    } else {
        printf("/n ERROR DE APERTURA DE ARCHIVO ");
    }
}

void buscaConsumoPorId (char archivo[], int idcarga) {
    stConsumos con;
    FILE *pArchiCons= fopen(archivo, "rb");
    if(pArchiCons != NULL) {
        while(fread(&con, sizeof(stConsumos), 1, pArchiCons)>0) {
            if(con.id==idcarga) {
                muestraUnConsumo(con);
            }
        }
        fclose(pArchiCons);
    } else {
        printf("/n ERROR DE APERTURA DE ARCHIVO ");
    }
}

stConsumos busquedaFecha() {

    stConsumos fecha;

    printf("\n ingrese el a%co\n", 164);
    scanf("\n %d", &fecha.anio);
    printf("\n ingrese el mes\n");
    scanf("\n %d", &fecha.mes);
    printf("\n ingrese un dia\n");
    scanf("\n %d", &fecha.dia);

    return fecha;
}

int sumaConsumo(int a) {
    int suma=0;
    suma= suma + a;
    return suma;
}

int compruebaIdCliente(int idCliente) {
    int flag=0;
    stClientes c;
    stConsumos con;
    FILE *archi= fopen("clientes.dat", "rb");
    if (archi) {
        while(fread(&c, sizeof(stClientes), 1, archi)>0 && flag==0) {
            if(c.id==idCliente) {
                con.idCliente=idCliente;
                flag=1;
                if(c.estado==1){
                    flag=0;
                }
            }
        }
        fclose(archi);
    }
    return flag;
}

int cargaMes(stConsumos con, int dato) {
    int flag=0;
    int mesHoy=mesActual();
    int anioHoy=anioActual();
    while (flag==0) {
        printf("\n Ingrese el mes.......................: ");
        scanf("%d", &con.mes);
        if (con.mes>=1 && con.mes <=12) {
            flag=1;
            if (dato==anioHoy) {
                if (con.mes<= mesHoy) {
                } else {
                    printf("\n Usted ingreso un mes mayor al vigente\n\n");
                    system("pause");
                    system("cls");
                    flag=0;
                }
            }
            if (dato!=anioHoy) {
                flag=1;
            }

        } else {
            printf(" El mes ingresado no es valido\n\n");
            system("pause");
            system("cls");
        }
    }
    return con.mes;
}

int cargaDia (stConsumos con, int mes[], int dato, int dato2) {
    int i=dato;
    int mesHoy=mesActual();
    int anioHoy=anioActual();
    int diaHoy=diaActual();
    int flag=0;

    while(flag==0) {
        printf("\n Dia.......................: ");
        scanf("%d", &con.dia);
        if (con.dia <= mes[i-1] && con.dia>0) {
            flag=1;
            if (dato2==anioHoy && dato==mesHoy) {
                if (con.dia <=diaHoy) {
                } else {
                    printf("\n Usted ingreso un dia mayor al vigente\n\n");
                    system("pause");
                    system("cls");
                    flag=0;
                }

            }
            if (dato2!=anioHoy) {
                flag=1;
            }
        } else {
            printf("\n Usted ingreso un numero mayor a lo que trae el mes.\n\n");
            system("pause");
            system("cls");
        }
    }
    return con.dia;
}

int cargaAnio(stConsumos con, int mes[]) {
    int flag=0;
    int anioHoy=anioActual();
    while(flag==0) {
        printf("\n Ingrese el a%co: \n", 164);
        scanf("%d",&con.anio);
        if(con.anio<=anioHoy && con.anio>1900) {
            flag=1;
        } else {
            printf("El a%co ingresado no es valido.\n", 164);
            system("pause");
            system("cls");
        }
        if(con.anio%4==0 && con.anio % 100 != 0 || con.anio % 400 == 0) {
            mes[1]=29;
        }
    }
    return con.anio;
}

int anioActual() {
    time_t ahora = time(NULL);
    struct tm* ahoralocal = localtime(&ahora);
    return ahoralocal->tm_year+1900;
}

int mesActual() {
    time_t ahora = time(NULL);
    struct tm* ahoralocal = localtime(&ahora);
    return ahoralocal->tm_mon +1;
}

int diaActual() {
    time_t ahora = time(NULL);
    struct tm* ahoralocal = localtime(&ahora);
    return ahoralocal->tm_mday;
}

void modificaCons(char archivo[], int idCarga, int consNew) {
    stConsumos con;
    int flag=0;
    int pos=0;
    FILE *pArchi = fopen(archivo, "r+b");
    if(pArchi) {
        while(flag==0 && fread(&con, sizeof(stConsumos), 1, pArchi)>0) {
            if(con.id==idCarga) {
                con.datosConsumidos=consNew;
                pos=ftell(pArchi)-sizeof(stConsumos);
                fseek(pArchi,pos,SEEK_SET);
                fwrite(&con, sizeof(stConsumos), 1, pArchi);
                flag=1;
            }
        }
    }
    fclose(pArchi);
}

void modificaEstadoCons(char archivo[], int idcarga) {
    stConsumos con;
    int flag=0;
    int pos=0;
    FILE *pArchi = fopen(archivo, "r+b");
    if(pArchi) {
        while(flag==0 && fread(&con, sizeof(stConsumos), 1, pArchi)>0) {
            if(con.id==idcarga) {
                if(con.estado==1) {
                    con.estado=0;
                } else {
                    con.estado=1;
                }
                pos=ftell(pArchi)-sizeof(stConsumos);
                fseek(pArchi,pos,SEEK_SET);
                fwrite(&con, sizeof(stConsumos), 1, pArchi);
                flag=1;
            }
        }
    }
    fclose(pArchi);
}

void modificaFecha(char archivo[], int dato) {
    stConsumos c;
    int mes[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
    int anioHoy=anioActual();
    int mesHoy=mesActual();
    int diaHoy=diaActual();
    int flag=0;
    FILE *pArchi = fopen(archivo, "r+b");

    if(pArchi) {
        while(flag ==0 && fread(&c, sizeof(stConsumos), 1, pArchi)>0) {
            if(c.id==dato) {
                c.anio=cargaAnio(c, mes);
                c.mes=cargaMes(c, c.anio);
                c.dia=cargaDia(c, mes, c.mes, c.anio);
                fseek(pArchi,-1 * sizeof (stConsumos),SEEK_CUR);
                fwrite(&c, sizeof(stConsumos), 1, pArchi);
                //fseek(pArchi, sizeof (stConsumos),1,SEEK_CUR);
                flag=1;
            }
        }
        fclose(pArchi);
    }
}

/// FUNCION CARGA RANDOM!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

void cargaConsumoAleatorio (char archivo []) {
    int cliente=cuentaRegistros("clientes.dat", sizeof(stClientes));
    int diasDelMes=0;
    int id=cuentaRegistros("consumos.dat",sizeof(stConsumos));
    int mes[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
    int anioHoy=anioActual();
    int mesHoy=mesActual();
    int diaHoy=diaActual();
    stConsumos con;
    int idCliente=1;
    int flag=0;
    do {
        for( int i=0; i<10; i++) {
            con.idCliente=rand()%(50)+1;
            con.anio=anioHoy;
            con.mes=rand()%(mesHoy)+1;
            diasDelMes=mes[con.mes];
            if (con.mes==mesHoy) {
                con.dia=rand()%(diaHoy)+1;
            } else {
                con.dia=rand()%(diasDelMes)+1;
            }
            con.datosConsumidos=rand()%(1000)+100;
            flag=cargaDatosConsumidos("consumos.dat", con);
            con.estado=0;
            if (flag==1) {
                id++;
                con.id=id;
                cargaNuevoConsumo("consumos.dat", con);
            }
        }
        idCliente++;
    } while(idCliente<=cliente);
}

int cargaDatosConsumidos (char archivo[],stConsumos nuevo) {
    stConsumos viejo;
    int flag=1;
    FILE *pArchi = fopen(archivo, "r+b");
    if(pArchi) {
        while(flag==1 && fread(&viejo, sizeof(stConsumos), 1, pArchi)>0) {

            if (viejo.idCliente== nuevo.idCliente && viejo.anio==nuevo.anio && viejo.mes==nuevo.mes && viejo.dia==nuevo.dia) {
                viejo.datosConsumidos=viejo.datosConsumidos+nuevo.datosConsumidos;
                fseek(pArchi,-1*sizeof(stConsumos), SEEK_CUR);
                fwrite(&viejo, sizeof(stConsumos),1, pArchi);
                flag=-1;
            }
        }
        fclose(pArchi);
    }
    return flag;
}

void cargaNuevoConsumo (char archivo[], stConsumos nuevo) {
    FILE *pArchi = fopen(archivo, "a+b");
    if(pArchi) {
        fwrite(&nuevo, sizeof(stConsumos),1, pArchi);
        fclose(pArchi);
    }
}
