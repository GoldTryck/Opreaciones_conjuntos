#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define MAX_CONJUNTO 20
#define MAX_RESULTADO 40

int leerNum() {
    int num;
    char input[10];
    while (1) {
        scanf("%s", input);
        int i = 0;
        while (input[i] != '\0') {
            if (!isdigit(input[i])) {
                printf("Error: Debe ingresar un numero entero.\n");
                break;
            }
            i++;
        }
        if (input[i] == '\0') {
            num = atoi(input);
            break;
        }
    }
    return num;
}
int agregarElemento(int size, int conjunto[], int elemento){
    for(int i = 0; i < size; i++){
        if(elemento == conjunto[i]) {
            printf("El elemento '%i' ya se encuentra en el conjunto.\n",elemento);
            return 0;
        }
    }
    conjunto[size] = elemento;
    return 1;        
}

int unionConjuntos(int conjunto1[], int size1, int conjunto2[], int size2, int conjuntoUnion[]){
    int i,j,contador;
    bool encontrar;

    for(i = 0; i< size1; i ++){

        conjuntoUnion[i] = conjunto1[i];
    }
    contador = size1;
    for(i = 0; i < size2; i ++){
        encontrar = false;
        for(j = 0; j < size1; j ++){
            if(conjunto2[i] == conjunto1[j]){
                encontrar = true;
                break;
            }
        }
        if(!encontrar){
                conjuntoUnion[contador] = conjunto2[i];
                contador ++;
            }
    }
    return contador;
}


int interseccionConjutnos(int conjunto1[], int size1, int conjunto2[], int size2, int conjuntoInter[]){

    int i,j,contador = 0;
    bool encontrar;

    for(i = 0; i < size2; i ++){
        encontrar = false;
        for(j = 0; j < size1; j ++){
            if(conjunto2[i] == conjunto1[j]){
                encontrar = true;
                break;
            }
        }
        if(encontrar){
                conjuntoInter[contador] = conjunto2[i];
                contador ++;
            }
    }


    return contador;
}

int diferenciaConjuntos(int conjunto1[],int size1,int conjunto2[],int size2,int conjuntoDif[]){
   
    int i,j,contador = 0;
    bool encontrar;

    for(i = 0; i < size1; i ++){
        encontrar = false;
        for(j = 0; j < size2; j ++){
            if(conjunto1[i] == conjunto2[j]){
                encontrar = true;
                break;
            }
        }
        if(!encontrar){
                conjuntoDif[contador] = conjunto1[i];
                contador ++;
            }
    }
    return contador;
}
int main(){
    int size1, size2, size3;
    int conjuntoElemento;
    int conjuntoUno[MAX_CONJUNTO];
    int conjuntoDos[MAX_CONJUNTO];
    int conjuntoResultado[MAX_RESULTADO];
    char opc;

    printf("\n\nCantidad de elementos que contiene el conjunto 1: ");
    do{
        size1 = leerNum();
        if(size1 <= 0 || size1 > MAX_CONJUNTO) printf("Debe ingresar un numero mayor que 0.\n");
    } while(size1 <= 0 || size1 > MAX_CONJUNTO);
    for(int i = 0; i < size1; i++){
        do {
            printf("\nIngrese el valor del elemento #%i del conjunto 1: ",i+1);
            conjuntoElemento = leerNum();
        }while(!agregarElemento(i,conjuntoUno,conjuntoElemento)); 
    }

    printf("\n\nCantidad de elementos que contiene el conjunto 2: ");
    scanf("%i",&size2);
    for(int i = 0; i < size2; i++){
        do {
            printf("\nIngrese el valor del elemento #%i del conjunto 2: ",i+1);
            scanf("%i",&conjuntoElemento);
        }while(!agregarElemento(i,conjuntoDos,conjuntoElemento)); 
    }

    printf("\nQue operacion con conjuntos desea realizar: \n\na) Union.\tb) Interseccion\t\tc) Diferencia A-B\td)Diferencia B-A\n");
    scanf(" %c",&opc);
    opc = tolower(opc);
    while(opc < 97 || opc > 100){
        printf("ERROR. Registre una opcion valida.\n");
        scanf(" %c",&opc);
    opc = tolower(opc);
    }
    switch(opc)
    {
        case 'a':
            size3 = unionConjuntos(conjuntoUno, size1, conjuntoDos, size2, conjuntoResultado);
            printf("La union de los conjuntos A:{ ");
            for (int i = 0; i < size1; i++) printf("%i%s", conjuntoUno[i], (i == size1-1) ? "" : ", ");
            printf("} & B:{ ");
            for (int i = 0; i < size2; i++) printf("%i%s", conjuntoDos[i], (i == size2-1) ? "" : ", ");
            printf("} es AUB:{ ");
            for (int i = 0; i < size3; i++) printf("%i%s", conjuntoResultado[i], (i == size3-1) ? "" : ", ");
            printf("}\n");          
            break;
        case 'b':
            size3 = interseccionConjutnos(conjuntoUno,size1,conjuntoDos,size2,conjuntoResultado);
            printf("La interseccion de los conjuntos A:{ ");
            for(int i = 0; i < size1; i ++) printf("%i%s",conjuntoUno[i],(i == size1-1) ? "" : ", ");
            printf(" } & B:{ ");
            for(int i = 0; i < size2; i ++) printf("%i%s",conjuntoDos[i],(i == size2-1) ? "" : ", ");
            printf(" } es AnB:{ ");
            for(int i = 0; i < size3; i ++) printf("%i%s",conjuntoResultado[i],(i == size3-1) ? "" : ", ");
            printf(" }\n"); 
            break;
        case 'c':
            size3 = diferenciaConjuntos(conjuntoUno,size1,conjuntoDos,size2,conjuntoResultado);
            printf("La diferencia de los conjuntos A:{ ");
            for(int i = 0; i < size1; i ++) printf("%i%s",conjuntoUno[i],(i == size1-1) ? "" : ", ");
            printf(" } & B:{ ");
            for(int i = 0; i < size2; i ++) printf("%i%s",conjuntoDos[i],(i == size2-1) ? "" : ", ");
            printf(" } es A-B:{ ");    
            for(int i = 0; i < size3; i ++) printf("%i%s",conjuntoResultado[i],(i == size3-1) ? "" : ", ");
            printf(" }"); 
            break;
        case 'd': 
            size3 = diferenciaConjuntos(conjuntoDos,size2,conjuntoUno,size1,conjuntoResultado);
            printf("La diferencia de los conjuntos B:{ ");
            for(int i = 0; i < size2; i ++) printf("%i%s",conjuntoDos[i],(i == size2-1) ? "" : ", ");
            printf(" } & A:{ ");
            for(int i = 0; i < size1; i ++) printf("%i%s",conjuntoUno[i],(i == size1-1) ? "" : ", ");
            printf(" } es B-A:{ ");
            for(int i = 0; i < size3; i ++) printf("%i%s",conjuntoResultado[i],(i == size3-1) ? "" : ", ");
            printf(" }"); 
            break;
    }
    return 0;
}
