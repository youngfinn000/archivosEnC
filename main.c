#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


            break;

        case 2:


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
