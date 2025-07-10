#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///
int cargarArregloDin(int dim, int **arregloDinamico)
{
    (*arregloDinamico)=(int*) malloc(dim * sizeof(int));
    char conf='s';
    int validos=0;
    while (conf=='s' && validos<dim)
    {
        (*arregloDinamico)[validos]=cargarArregloDin();
    }
    
    return validos;
}

Vacunas* agregarUnElementoAlArreglo (Vacunas *arreglo, int *validos)
{
    (*validos)++; // aumentamos el tamano logico
    arreglo = (Vacunas*) realloc (arreglo,(*validos)*sizeof(Vacunas));

    printf("\nNueva vacuna a agregar...\n");
    arreglo[(*validos)-1] = cargarUnaVacuna();  

    FILE* archi = fopen(nombreArchi, "ab");

    if (archi!=NULL)
    {
        fwrite(&arreglo[(*validos)-1], sizeof(Vacunas), 1, archi);
        fclose(archi);
    }

    return arreglo;
}

int pasarDePilaAarreglo (Pila aCopiar, int arreglo[], int dim)
{
    int validos=0;
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(&aCopiar) && validos<dim)
    {
        if (tope(&aCopiar)>250 && tope(&aCopiar)<350)
        {
            validos = insertarEnArregloOrdenada(arreglo, validos, desapilar(&aCopiar));
        }
        else
        {
            apilar(&aux, desapilar(&aCopiar));
        }
    }

    return validos;
}


int insertarEnArregloOrdenada (int arreglo[], int validos, int aAgregar)
{
    int j=validos-1;

    while(j>=0 && arreglo[j]>aAgregar)
    {
        arreglo[j+1]=arreglo[j];
        j--;
    }

    arreglo[j+1]= aAgregar;

    return validos+1;
}

///


#define archivosNum "numeros.bin"

/// estructura  a utilizar para el tp
typedef struct
{
    int legajo;
    char nombreYapellido [30];
    int edad;
    int anio;
//año que cursa, recordar que no podemos utilizar la ñ para definir variables
} stAlumno;

/// PROTOTIPADO ///////////////////////////
void agregarDatoAlFinalDeUnArchivo ( char nombreDelArchivo []);
void mostrarArchivo (char nombreDeArchivo[]);



int main()
{
    int caso =0;
    char seguir='s';

    do
    {
        printf(" aca va cada ejercicio del tp\n");
        printf("ingrese el numero del ejercicio para verlo (caso 1 hasta caso 17):\n ");
        scanf("%d",&caso);
        switch(caso)
        {
        case 1:
            agregarDatoAlFinalDeUnArchivo ( archivosNum);

            break;

        case 2:
            mostrarArchivo (archivosNum);


            break;

        case 3:


            break;

        case 4:


            break;
        case 5:


            break;
        case 6:


            break;
        case 7:


            break;
        case 8:


            break;
        case 9:


            break;
        case 10:


            break;
        case 11:


            break;
        case 12:


            break;
        case 13:


            break;

        case 14:


            break;
        case 15:


            break;
        case 16:


            break;
        case 17:


            break;

        default :
            printf("error, caso inexistente\n ingrese un numero del 1 al 13:");
            scanf("%d",&caso);
        }
        printf("si desea ver otro ejercicio presione s, si quiere finalizar presione algo distinto de s:\n");
        fflush(stdin);
        scanf("%c",&seguir);
    }
    while(seguir == 's');
    return 0;
}

/// FUNCIONES //////////////////////////////


void agregarDatoAlFinalDeUnArchivo ( char nombreDelArchivo [])
{
    FILE* punteroArchivo=fopen(archivosNum, "ab");

    char control ='s';
    int num;
    if (punteroArchivo)
    {
        while(control=='s')
        {
            printf("ingresar un numero:\n");
            scanf("%d",&num);

            fwrite(&num,sizeof(int),1,punteroArchivo);

            printf("queres seguir?\n");
            fflush(stdin);
            scanf("%c", &control);

        }
        fclose(punteroArchivo);
    }
    else
    {
        printf("\nel archivo no se pudo abrir.\n");
    }
}

/// 2 mostrar archivo
void mostrarArchivo (char nombreDeArchivo[])
{
    FILE* punteroarchi =fopen(nombreDeArchivo,"rb");
    int num=0;

    if(punteroarchi)
    {
        while(fread(&num, sizeof(int), 1, punteroarchi) !=0)
        {
            printf("Valor: %d\n", num);
        }
        fclose(punteroarchi);
    }
    else
    {
        printf("error\n");

    }
}

