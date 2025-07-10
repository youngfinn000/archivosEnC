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
