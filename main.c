#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>
#include <locale.h>


typedef struct
{
    int matricula;
    char nombre[30];
    char genero;

} stAlumno;



void asignaNombreMasculinoRandom(char nombre[]);                                    /// FUNCION QUE ASIGNA UN NOMBRE ALEATORIO.

void asignaNombreFemeninoRandom(char nombre[]);                                     /// FUNCION QUE ASIGNA UN NOMBRE ALEATORIO.

stAlumno cargaUnAlumnoRandom ();                                                    /// CARGA DE FORMA RANDOM UN ALUMNO.

stAlumno cargaUnAlumno ();                                                          /// CARGA DE FORMA MANUAL UN ALUMNO.

void muestraUnAlumno (stAlumno alumno);                                             /// MUESTRA UN ALUMNO.

int cargaArregloAlumno (stAlumno alumnos [], int dim);                              /// EJERCICIO 1. /// CARGA UN ARREGLO DE ALUMNOS.

int cargarArregloAlumnoRandom (stAlumno alumnos[], int dim);                        /// EJERCICIO 1. /// CARGAD DE FORMA RANDOM UN ARREGLO DE ALUMNOS.

void mostrarArreglo (stAlumno alumnos[],int validos);                               /// EJERCICIO 2. /// MUESTRA ARREGLO DE ALUMNOS.

void muestraAlumnoXMatricula (stAlumno alumnos [], int validos, int matricula);     /// EJERCICIO 3. /// BUSCA AL ALUMNO QUE TENGA LA MATRICULA ENVIADA.

int buscaMenorMatricula (stAlumno alumnos [], int validos, int iterador);           /// EJERCICIO 4. /// BUSCA LA MATRICULA MAS CHICA.

void ordenamientoXSeleccion (stAlumno alumnos [],int validos);                      /// EJERCICIO 4. /// ORDENA EN BASE A LAS MATRICULAS.

void muestraAlumnoXGenero(stAlumno alumnos [],int validos, char genero);            /// EJERCICIO 5. /// MUESTRA TODOS LOS ALUMNOS DE UN DETERMINADO GENERO.

int insertaUnAlumno (stAlumno alumnos [], int validos, stAlumno alumno);            /// EJERCICIO 6. /// INSERTA UN ALUMNO EN UN ARREGLO ORDENADO.

void insertaMenor (stAlumno alumnos[],int validos,stAlumno alumno);                 /// EJERCICIO 7. /// INSERTA ALUMNO.

void ordenamientoXInsercion (stAlumno alumnos [], int validos);                     /// EJERCICIO 7. /// ORDENAMIENTO POR INSERCION.

int cuentaAlumnosDeXGenero (stAlumno alumnos [], int validos, char genero);         /// EJERCICIO 8. /// CUENTA TODOS LOS ALUMNOS DE UN SEXO DETERMINADO

int buscaPrimerLetra (stAlumno alumnos[],int validos,char dato);                    /// EJERCICIO QUE HICIMOS EN CLASE.





int main()
{

    srand(time(NULL));
    setlocale(LC_ALL, "");

    int dim=4;
    int contador=0;
    int ejercicio=0,opcion=0;

    char control,genero;

    stAlumno alumnos [dim];
    int validos=0;

    stAlumno alumno;


    do
    {

        system("cls");
        printf("\n1.Hacer una función que cargue un arreglo de alumnos, hasta que el usuario lo decida.\n");
        printf("\n2.Hacer una función que muestre un arreglo de alumnos por pantalla. Modularizar.\n");
        printf("\n3.Hacer una función que muestre por pantalla los datos de un alumno, conociendo su matrícula. Modularizar.\n");
        printf("\n4.Hacer una función que ordene el arreglo de alumnos por medio del método de selección. El criterio de ordenación es el número de matrícula.\n");
        printf("\n5.Hacer una función que muestre por pantalla los datos de los estudiantes de un género determinado (se envía por parámetro). Modularizar.\n");
        printf("\n6.Hacer una función que inserte en un arreglo ordenado por matrícula un nuevo dato, conservando el orden.\n");
        printf("\n7.Hacer una función que ordene el arreglo de alumnos por medio del método de inserción. El criterio de ordenación es el nombre.\n");
        printf("\n8.Hacer una función que cuente y retorne la cantidad de estudiantes de un género determinado (se envía por parámetro) que tiene un arreglo de alumnos.\n");
        printf("\n9.EJERCICIO QUE VIMOS EN CLASE.\n");

        printf("\nELIJA UN EJERCICIO : \n");
        scanf("%d",&ejercicio);

        system("cls");

        switch(ejercicio)
        {

        case 1:

            printf("\nDe que manera desea cargar el arreglo ? \n");
            printf("\n\tRANDOM ---> 1\n");
            printf("\n\tMANUAL ---> 2\n");
            scanf("%d",&opcion);


            if(opcion ==1)
            {

                validos=cargarArregloAlumnoRandom(alumnos,dim);

            }
            else
            {

                validos=cargaArregloAlumno(alumnos,dim);

            }

            break;

        case 2:

            printf("\nArreglo de alumnos : \n");
            mostrarArreglo(alumnos,validos);
            system("pause");


            break;

        case 3 :

            printf("\nIngrese matricula del alumno que desea buscar : \n");
            scanf("%d",&opcion);

            muestraAlumnoXMatricula(alumnos,validos,opcion);
            system("pause");

            break;

        case 4:

            mostrarArreglo(alumnos,validos);

            printf("\nOrdenando alumnos ....\n");
            system("pause");
            ordenamientoXSeleccion(alumnos,validos);

            mostrarArreglo(alumnos,validos);
            system("pause");

            break;

        case 5 :

            printf("\nIngrese el genero de los alumnos que desea buscar : \n");
            fflush(stdin);
            scanf("%c",&genero);

            muestraAlumnoXGenero(alumnos,validos,genero);
            system("pause");

            break;

        case 6:

            printf("\nVAMOS A CARGAR UN NUEVO ALUMNO : \n");
            alumno=cargaUnAlumno();
            printf("\n\n");
            system("pause");
            system("cls");

            ordenamientoXSeleccion(alumnos,validos);

            mostrarArreglo(alumnos,validos);

            printf("\nINSERTANDO EL NUEVO ALUMNO..\n");
            printf("\n");
            system("pause");

            validos=insertaUnAlumno(alumnos,validos,alumno);

            mostrarArreglo(alumnos,validos);
            system("pause");

            break;

        case 7 :

            mostrarArreglo(alumnos,validos);
            system("pause");

            printf("\nORDENANDO POR INSERCION...\n");

            ordenamientoXInsercion(alumnos,validos);
            mostrarArreglo(alumnos,validos);

            system("pause");

            break;

        case 8 :

            printf("\nIngrese genero : \n");
            fflush(stdin);
            scanf("%c",&genero);

            contador=cuentaAlumnosDeXGenero(alumnos,validos,genero);

            break;

        case 9 :


            contador=buscaPrimerLetra(alumnos,validos,'a');

            printf("\ncontador %d\n",contador);

            break;

        default :

            printf("\nEse ejercicio no existe.\n");

        }


        system("cls");

        printf("\nDesea ver otro ejercicio ? s/n\n");
        fflush(stdin);
        scanf("%c",&control);

    }
    while(control=='s' || control=='S');




    return 0;
}








//////////////////////////////////////////////////////////////////////
/*****************************************************************//**
*
*   \brief  Funcion que carga un alumno.
*   \return variable de tipo alumno ya cargada de datos.
*
*********************************************************************/

stAlumno cargaUnAlumno ()
{

    stAlumno aux;

    printf("\nIngrese MATRICULA : ");
    scanf("%d",&aux.matricula);
    printf("\nIngrese NOMBRE : ");
    fflush(stdin);
    gets(aux.nombre);
    printf("\nIngrese GENERO : ");
    fflush(stdin);
    scanf("%c",&aux.genero);

    return aux;
}

//////////////////////////////////////////////////////////////////////
/*****************************************************************//**
*
*   \brief  Muestra un alumno.
*   \param  Recibe una variable de tipo alumno.
*
*********************************************************************/

void muestraUnAlumno (stAlumno alumno)
{

    printf("\nMATRICULA : %d \n",alumno.matricula);
    printf("\n   NOMBRE : %s \n",alumno.nombre);
    printf("\n   GENERO : %c \n",alumno.genero);

    printf("\n---------------------------------------------\n");

    return;
}


//////////////////////////////////////////////////////////////////////
/*****************************************************************//**
*
*   \brief  EJERCICIO 1.
*   \brief  Carga arreglo de alumnos.
*   \param  Arreglo de tipo alumno.
*   \param  Dimension de tipo int.
*   \return i (validos).
*
*********************************************************************/

int cargaArregloAlumno (stAlumno alumnos [], int dim)
{

    int i=0;
    char control= 's';

    while(i<dim && control =='s')
    {

        alumnos[i]=cargaUnAlumno();

        printf("\nDesea seguir cargando ? s/n\n");
        fflush(stdin);
        scanf("%c",&control);

        i++;
    }

    return i;
}

//////////////////////////////////////////////////////////////////////
/*****************************************************************//**
*
*   \brief  EJERCICIO 2.
*   \brief  Muestra arreglo de alumnos.
*   \param  Arreglo de tipo alumno.
*   \param  Validos de tipo int.
*
*********************************************************************/

void mostrarArreglo (stAlumno alumnos[],int validos)
{

    int i;

    for(i=0; i<validos; i++)
    {

        muestraUnAlumno(alumnos[i]);
        printf("\n");
    }

    return;

}

///////////////////////////////////////////////////////////////////////////////////////////
/**************************************************************************************//**
*
*   \brief  EJERCICIO EXTRA.
*   \brief  Busca que nombres comienzan con la letra enviada.
*   \param  Arreglo de alumnos.
*   \param  Validos de tipo int.
*   \param  Dato de tipo char (letra con la cual comparamos).
*   \return contador de tipo int. (para saber cuantos nombres comienzan con esa letra).
*
******************************************************************************************/

int buscaPrimerLetra (stAlumno alumnos[],int validos,char dato)
{

    int contador=0;
    int i;

    for(i=0; i<validos; i++)
    {

        if(alumnos[i].nombre[0] == dato )
        {
            contador++;
        }

    }

    return contador;
}


////////////////////////////////////////////////////////////////////////////////////////////
/***************************************************************************************//**
*
*   \brief  Funcion que carga nombres masculinos random.
*   \param  Arreglo de tipo char.
*
*******************************************************************************************/

void asignaNombreMasculinoRandom(char nombre[])
{

    char nombresRandom[][30]= {"Agustin","Manuel","Pepe","Juan","Carlos","Nicolas","Horacio","Federico","Miguel","Gabriel","Lucas","Diego","Oscar","Norberto",
                               "Cristian","Francisco","Martin","Pedro","Gustavo","Sergio","Kevin","Tomas","Roberto","Miguel","Alfredo","Mauro","Marcial","Nacho","Luciano","Pablo"
                              };

    ///sizeof devuelve cuanto pesa en bites el arreglo de nombresRandom (la dimension de las columnas por la cantidad de nombres)
    ///Entonces lo que me devuelve lo tengo que dividir por 30 para saber la cantidad de validos

    strcpy(nombre,nombresRandom[rand()%sizeof(nombresRandom)/30]);

    return;

}

////////////////////////////////////////////////////////////////////////////////////////////
/***************************************************************************************//**
*
*   \brief  Funcion que carga nombres femeninos random.
*   \param  Arreglo de tipo char.
*
*******************************************************************************************/

void asignaNombreFemeninoRandom(char nombre[])
{

    char nombresRandom[][30]= {"Sofia","Melany","Magali","Clara","Juana","Paz","Karen","Ana","Romina","Valentina","Indira","Ludmila","Carolina","Carmen","Lucia","Martina","Maria","Mariana","Emma","Jimena","Valeria","Lola"," Josefina","Sara","Belen","Chloe","Mara","Alma","Mia","Zoe","Daniela","Candela","Camila","Luciana","Gala"," Ariadna","Paula"};

    strcpy(nombre,nombresRandom[rand()%sizeof(nombresRandom)/30]);

    return;
}

/////////////////////////////////////////////////////////////////////////////////////////
/************************************************************************************//**
*
*   \brief  Cargamos un alumno de forma random.
*   \return Devolvemos un alumno cargado.
*
****************************************************************************************/

stAlumno cargaUnAlumnoRandom ()
{

    stAlumno aux;
    int numero=0;


    aux.matricula=rand()%800+1;

    numero=rand()%100+1;

    if(numero %2 == 0)
    {
        asignaNombreMasculinoRandom(aux.nombre);
        aux.genero='m';
    }
    else
    {
        asignaNombreFemeninoRandom(aux.nombre);
        aux.genero='f';
    }

    return  aux;

}

////////////////////////////////////////////////////////////////////////////////
/***************************************************************************//**
*
*   \brief  Carga arreglo de alumnos random.
*   \param  Arreglo de tipo alumno.
*   \param  Dimension de tipo int.
*   \return i ---> (validos).
*
*******************************************************************************/

int cargarArregloAlumnoRandom (stAlumno alumnos[], int dim)
{

    int i;

    for(i=0; i<dim; i++)
    {
        alumnos[i]=cargaUnAlumnoRandom();
    }

    return i;

}

/////////////////////////////////////////////////////////////////////////////////////////
/************************************************************************************//**
*
*   \brief  EJERCICIO 3.
*   \brief  Busca alumno con matricula ingresada.
*   \param  Arreglo de tipo alumno.
*   \param  Validos de tipo int.
*   \param  Matricula de tipo int.
*
****************************************************************************************/

void muestraAlumnoXMatricula (stAlumno alumnos [], int validos, int matricula)
{

    int flag=0;
    int i=0;
    int pos=0;

    while(i<validos && flag == 0)
    {

        if(alumnos[i].matricula == matricula)
        {
            flag=1;
            pos=i;
        }
        i++;
    }

    if(flag==1)
    {
        muestraUnAlumno(alumnos[pos]);

    }
    else
    {
        printf("\nNo hay ningun alumno con esa matricula.\n");
    }

    return;

}

/////////////////////////////////////////////////////////////////////////////////////////
/************************************************************************************//**
*
*   \brief  EJERCICIO 4.
*   \brief  Busca la matricula mas chica.
*   \param  Arreglo de tipo alumno.
*   \param  Validos de tipo int.
*   \param  Iterador de tipo int.
*   \return Posicion del alumno con la matricula mas chica.
*
****************************************************************************************/

int buscaMenorMatricula (stAlumno alumnos [], int validos,int iterador)
{

    int menor = alumnos[iterador].matricula;
    int pos=iterador;
    int i=iterador+1;

    while(i<validos)
    {

        if(alumnos[i].matricula<menor)
        {
            menor=alumnos[i].matricula;
            pos=i;
        }
        i++;

    }

    return pos;

}

/////////////////////////////////////////////////////////////////////////////////////////
/************************************************************************************//**
*
*   \brief  EJERCICIO 4.
*   \brief  Ordenamiento por seleccion.
*   \param  Arreglo de tipo alumno.
*   \param  Validos de tipo int.
*
****************************************************************************************/

void ordenamientoXSeleccion (stAlumno alumnos [],int validos)
{

    int i=0;
    int pos=0;

    stAlumno aux;


    while(i<validos-1)
    {

        pos=buscaMenorMatricula(alumnos,validos,i);

        aux= alumnos[i];
        alumnos[i]=alumnos[pos];
        alumnos[pos]=aux;

        i++;

    }

    return;
}

/////////////////////////////////////////////////////////////////////////////////////////
/************************************************************************************//**
*
*   \brief  EJERCICIO 5.
*   \brief  Muestra todos los alumnos del genero ingresado.
*   \param  Arreglo de tipo alumno.
*   \param  Validos de tipo int.
*   \param  Genero de tipo char.
*
****************************************************************************************/

void muestraAlumnoXGenero(stAlumno alumnos [],int validos, char genero)
{

    for(int i=0; i<validos; i++)
    {

        if(alumnos[i].genero==genero)
        {
            muestraUnAlumno(alumnos[i]);
        }

    }

    return;

}

/////////////////////////////////////////////////////////////////////////////////////////
/************************************************************************************//**
*
*   \brief  EJERCICIO 6.
*   \brief  Inserta un alumno en un arreglo ordenado.
*   \param  Arreglo de tipo alumno.
*   \param  Validos de tipo int.
*   \param  Alumno de tipo alumno.
*   \return Validos +1;
*
****************************************************************************************/

int insertaUnAlumno (stAlumno alumnos [], int validos, stAlumno alumno)
{

    int i = validos-1;

    int matricula=alumno.matricula;

    while(i>=0 && alumnos[i].matricula>matricula)
    {

        alumnos[i+1]=alumnos[i];
        i--;

    }

    alumnos[i+1]=alumno;

    return validos+1;

}

/////////////////////////////////////////////////////////////////////////////////////////
/************************************************************************************//**
*
*   \brief  EJERCICIO 7.
*   \brief  Ordena por insercion.
*   \param  Arreglo de tipo alumno.
*   \param  Validos de tipo int.
*   \param  Alumno de tipo alumno.
*
****************************************************************************************/

void insertaMenor (stAlumno alumnos[],int validos,stAlumno alumno)
{

    int i = validos;


    while(i>=0 && strcmp(alumnos[i].nombre,alumno.nombre) >0)
    {

        alumnos[i+1]=alumnos[i];
        i--;

    }

    alumnos[i+1]=alumno;

    return;

}

/////////////////////////////////////////////////////////////////////////////////////////
/************************************************************************************//**
*
*   \brief  EJERCICIO 7.
*   \brief  ORDENAMIENTO POR INSERCION.
*   \param  Arreglo de tipo alumno.
*   \param  Validos de tipo int.
*
****************************************************************************************/

void ordenamientoXInsercion (stAlumno alumnos [], int validos)
{

    int i=0;

    while(i<validos-1)
    {

        insertaMenor(alumnos,i,alumnos[i+1]);
        i++;
    }

    return;

}

/////////////////////////////////////////////////////////////////////////////////////////
/************************************************************************************//**
*
*   \brief  EJERCICIO 8.
*   \brief  Cuenta los alumnos que son de determinado genero.
*   \param  Arreglo de tipo alumno.
*   \param  Validos de tipo int.
*   \param  Genero de tipo char.
*   \return Contador.
*
****************************************************************************************/

int cuentaAlumnosDeXGenero (stAlumno alumnos [], int validos, char genero)
{

    int contador=0;

    for(int i=0; i<validos; i++)
    {

        if(alumnos[i].genero == genero)
        {
            contador++;
        }
    }

    return contador;

}




