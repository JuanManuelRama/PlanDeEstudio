#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "aux.h"

FILE* archivo;
char* aux;

void getMateria(char*);
void cambiarNota(char*);
bool getCorrelativa(char*);
void mostrarMaterias();
bool verificarMateria(char*);
bool verificarNota(int);
OPCIONES pedirDatos();

int main(){
    char materia [5];
    char nota [3];
    long tam;

    

    while(1)
        switch(pedirDatos()){
            case AÑADIR:
                archivo = fopen("Programa.gv", "r+");
                fseek(archivo, 0, SEEK_END);
                tam = ftell(archivo);
                fseek(archivo, 0, SEEK_SET);
                aux = malloc(tam+100);
                aux[0] = '\0';
                mostrarMaterias();
                printf("Ingrese el nombre de la materia y la nota \n");
                scanf("%s %s", materia, nota);
                system("clear");
                if(!verificarMateria(materia))
                    break;
                if(!verificarNota(atoi(nota)))
                    break;
                getMateria(materia);
                cambiarNota(nota);
                while(getCorrelativa(materia))
                    strcat(aux, "color=green");
                fread(aux+strlen(aux), 1, tam-ftell(archivo), archivo);
                fclose(archivo);
                archivo = fopen("Programa.gv", "w+");
                fwrite(aux, 1, strlen(aux), archivo);
                fclose(archivo);
                break; 
            case GRAFICAR:
                system("dot -T png Programa.gv -o Programa.png");
                break;
            case SALIR:
                return 0;
            default:
                printf("Opción inválida \n");
        }
    mostrarMaterias();
    printf("Ingrese el nombre de la materia \n");
    scanf("%s %s", materia, nota);
    getMateria(materia);
    cambiarNota(nota);

    while(getCorrelativa(materia))
        strcat(aux, "color=green");
    fread(aux+strlen(aux), 1, tam-ftell(archivo), archivo);
    fclose(archivo);
    archivo = fopen("Programa.gv", "w+");
    fwrite(aux, 1, strlen(aux), archivo);
    fclose(archivo);
    //system("dot -T png Programa.gv -o Programa.png");
    free(aux);
    return 0;
}

void getMateria(char* materia){
    char c;
    int len = strlen(materia);
    while((c=fgetc(archivo)) != *materia)
        strncat(aux, &c, 1);
    strncat(aux, &c, 1);
    for(int i =1; i<len; i++){
        c = fgetc(archivo);
        strncat(aux, &c, 1);
        if(c!= *(materia+i))
            return getMateria(materia);
    }
    fread(aux+strlen(aux), 1, 1, archivo);
    strcat(aux, "fillcolor=green ");

}

void cambiarNota(char* nota){
    char c;
    while((c=fgetc(archivo)) != '(')
        strncat(aux, &c, 1);
    strncat(aux, &c, 1);
    strcat(aux, nota);
}

bool getCorrelativa(char* materia){
    char c;
    int len = strlen(materia);
    while((c=fgetc(archivo)) != *materia)
        if(c==EOF)
            return false;
        else 
            strncat(aux, &c, 1);
    strncat(aux, &c, 1);
    for(int i =1; i<len; i++){
        c = fgetc(archivo);
        strncat(aux, &c, 1);
        if(c!= *(materia+i))
            return getCorrelativa(materia);
    }
    c=fgetc(archivo);
    strncat(aux, &c, 1);
    if(c != '-')
        return getCorrelativa(materia);
    while((c=fgetc(archivo)) != '[')
        strncat(aux, &c, 1);
    strncat(aux, &c, 1);
    return true;
}

void mostrarMaterias(){
    printf("Materias: \n");
    printf("AMI = Análisis Matemático I \n AyGA = Álgebra y Geometría Analítica \n AyED = Algoritmos y Estructuras de Datos \n FI = Física I \n SyPdN = Sistemas y Procesos de Negocio \n LyED = Lógica y Estructuras Discretas \n AdC = Arquitectura de Computadoras \n ITI = Inglés Técnico I \n AMII = Análisis Matemático II \n FII = Física II \n IyS = Ingeniería y Sociedad \n PdP = Paradigmas de la Programación \n AdS = Análisis de Sistemas \n SySL = Sintaxis y Semántica de los Lenguajes \n ITII = Inglés Técnico II \n SO = Sistemas Operativos \n AN = Análisis Numérico \n E = Economía \n PyE = Probabilidad y Estadística \n DdS = Diseño de Sistemas \n DS = Desarrollo de Software \n BdD = Bases de Datos \n CdD = Comunicación de Datos \n L = Legislación \n TpA = Tecnologías para la Automatización \n IO = Investigación Operativa \n S = Simulación \n AddS = Administración de Sistemas \n IyCdS = Ingeniería y Calidad de Software \n RdD = Redes de Datos \n SdG = Sistemas de Gestión \n IA = Inteligencia Artificial \n CddD = Ciencia de Datos \n PPS = Práctica Profesional Supervisada \n GG = Gestión Gerencial \n SS = Seguridad en Sistemas \n ");
}

OPCIONES pedirDatos(){
    int opcion;
    printf("Seleccione la opción: \n %d. Ingresar una nueva materia \n %d. Generar Gráfico \n %d. Salir \n", AÑADIR, GRAFICAR, SALIR);
    scanf("%d", &opcion);
    return opcion;
}

bool verificarMateria(char* materia){
    if (!strcmp(materia, "AMI")) return true;
    if (!strcmp(materia, "AyGA")) return true;
    if (!strcmp(materia, "AyED")) return true;
    if (!strcmp(materia, "FI")) return true;
    if (!strcmp(materia, "SyPdN")) return true;
    if (!strcmp(materia, "LyED")) return true;
    if (!strcmp(materia, "AdC")) return true;
    if (!strcmp(materia, "ITI")) return true;
    if (!strcmp(materia, "AMII")) return true;
    if (!strcmp(materia, "FII")) return true;
    if (!strcmp(materia, "IyS")) return true;
    if (!strcmp(materia, "PdP")) return true;
    if (!strcmp(materia, "AdS")) return true;
    if (!strcmp(materia, "SySL")) return true;
    if (!strcmp(materia, "ITII")) return true;
    if (!strcmp(materia, "SO")) return true;
    if (!strcmp(materia, "AN")) return true;
    if (!strcmp(materia, "E")) return true;
    if (!strcmp(materia, "PyE")) return true;
    if (!strcmp(materia, "DdS")) return true;
    if (!strcmp(materia, "DS")) return true;
    if (!strcmp(materia, "BdD")) return true;
    if (!strcmp(materia, "CdD")) return true;
    if (!strcmp(materia, "L")) return true;
    if (!strcmp(materia, "TpA")) return true;
    if (!strcmp(materia, "IO")) return true;
    if (!strcmp(materia, "S")) return true;
    if (!strcmp(materia, "AddS")) return true;
    if (!strcmp(materia, "IyCdS")) return true;
    if (!strcmp(materia, "RdD")) return true;
    if (!strcmp(materia, "SdG")) return true;
    if (!strcmp(materia, "IA")) return true;
    if (!strcmp(materia, "CddD")) return true;
    if (!strcmp(materia, "PPS")) return true;
    if (!strcmp(materia, "GG")) return true;
    if (!strcmp(materia, "SS")) return true;
    
    printf("Materia inválida \n");
    return false;
}

bool verificarNota(int nota){
    if(nota < 0 || nota > 10){
        printf("Nota inválida \n");
        return false;
    }
    if(nota>0 && nota<6){
        printf("Desaprobado \n");
        return false;
    }
    return true;
}