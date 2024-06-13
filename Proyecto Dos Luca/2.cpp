#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//CASE 1 SWTICH
void llenarConNumerosAleatorios(int matriz[][3], int N);
void cargarMatriz(int matriz[][3], int N);
void caseUno(int matriz[][3], int N);

//CASE 2 SWITCH
void mostrarMatriz(int matriz[][3], int N);

//CASE 3 SWITCH
void caseTres(int matriz[][3], int N, int arreglo[9]);

//CASE 4 SWITCH
void caseCuatroSwitch(int matriz[][3], int N);
int valorMaximo(int matriz[][3], int N);
int valorMinimo(int matriz[][3], int N);

//CASE 5 SWITCH
void caseCinco(int matriz[][3], int N, int arreglo[9]);
void ascendente(int matriz[][3], int N, int arreglo[9]);
void descendente(int matriz[][3], int N, int arreglo[9]);


int main(){
    const int N = 3;
    int matriz[N][N];
    int opcion;
    bool matrizCargada = false;
    int arreglo[9];

    // MENU DEL PROGRAMA
    do{
        cout << "***  MENU  ***" << endl;
        cout << "1. CARGAR LA MATRIZ. \n";
        cout << "2. MOSTRAR LOS VALORES DE LA MATRIZ. \n";
        cout << "3. BUSCAR UN VALOR ESPECIFICO INGRESADO POR EL USUARIO DENTRO DE LA MATRIZ. \n";
        cout << "4. DEVOLVER EL VALOR MAXIMO O MINIMO DE LA MATRIZ. \n";
        cout << "5. ORDENAR LOS VALORES DE LA MATRIZ DE FORMA ASCENDENTE O DESCENDENTE. \n";
        cout << "6. SALIR. \n";

        cout << "    ----    \n";
        cout << "INGRESE UNA OPCION: ";
        cin >> opcion;

        switch(opcion){
            case 1:
                caseUno(matriz, N);
                matrizCargada = true;
                break;
            
            case 2:
                if(matrizCargada == true){
                    mostrarMatriz(matriz, N);
                } else{
                    cout << "PRIMERO DEBE CARGAR LA MATRIZ." << endl;
                }
                break;
            
            case 3:
                if(matrizCargada == true){
                    caseTres(matriz, N, arreglo);
                } else{
                    cout << "PRIMERO DEBE CARGAR LA MATRIZ." << endl;
                }
                break; 
            case 4:
                if(matrizCargada == true){
                    caseCuatroSwitch(matriz, N);
                } else{
                    cout << "PRIMERO DEBE CARGAR LA MATRIZ." << endl;
                }
                
                break;
            case 5:
                if(matrizCargada == true){
                    caseCinco(matriz, N, arreglo);
                } else{
                    cout << "PRIMERO DEBE CARGAR LA MATRIZ." << endl;
                }
                break;
            case 6:
                break;
            default:
                cout << "NUMERO NO VALIDO." <<  endl;
        }

    }while(opcion != 6);

    
    return 0;
}

//CASE 1 SWITCH
void caseUno(int matriz[][3], int N){
    int caseUnoOpcion;
    cout << "LO PUEDE HACER: \n";
    cout << "1. CON NUMEROS ALEATORIOS EN EL RANGO DEL 1 A 100." << endl;
    cout << "2. DE FORMA MANUAL, INGRESANDO LOS VALORES UNO POR UNO." << endl;
    cout << "INGRESE UNA OPCION: ";
    cin >> caseUnoOpcion;

    while(caseUnoOpcion < 1 || caseUnoOpcion > 2){
        cout << "LA OPCION PUEDE SER 1 O 2, ingrese nuevamente:";
        cin >> caseUnoOpcion;
    }

    if(caseUnoOpcion == 1){
        llenarConNumerosAleatorios(matriz, N);
    } else if(caseUnoOpcion == 2){
        cargarMatriz(matriz, N);
    }


}


void llenarConNumerosAleatorios(int matriz[][3], int N){
    srand(time(NULL));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            matriz[i][j] = rand() % 100 + 1;
        }
    }
}

void cargarMatriz(int matriz[][3], int N){
    cout << "INGRESE LOS ELEMENTOS DE LA MATRIZ: " << endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }
}

//CASE 2 SWITCH
void mostrarMatriz(int matriz[][3], int N){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
}

//CASE 3 SWITCH

void caseTres(int matriz[][3], int N, int arreglo[9]){
    bool encontrado = false;
    int numeroBusqueda;
    cout << "INGRESE UN NUMERO A BUSCAR: ";
    cin >> numeroBusqueda;

    while(numeroBusqueda < 0 || numeroBusqueda > 100){
        cout << "EL NUMERO DEBE ESTAR ENTRE 1 Y 100, ingrese otro: ";
        cin >> numeroBusqueda;
    }

    


   for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
        if(numeroBusqueda == matriz[i][j]){
            encontrado = true;
        }
    }
   }

   if(encontrado == true){
    cout << "EL NUMERO ESTA :)" << endl;
   } else {
    cout << "EL NUMERO NO ESTA :(" << endl;
   }


}

//CASE 4 SWITCH
void caseCuatroSwitch(int matriz[][3], int N){
    valorMaximo(matriz, N);
    valorMinimo(matriz, N);
}

int valorMaximo(int matriz[][3], int N){
    int maximo = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(matriz[i][j] > maximo){
                maximo = matriz[i][j];
            }
        }
    }

    cout << "EL VALOR MAXIMO DE LA MATRIZ ES: " << maximo << endl << endl;
    return maximo;
}

int valorMinimo(int matriz[][3], int N){
    int minimo = matriz[0][0];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(matriz[i][j] < minimo){
                minimo = matriz[i][j];
            }
        }
    }

    cout << "EL VALOR MINIMO DE LA MATRIZ ES: " << minimo <<endl << endl;
    return minimo;

}

//CASE 5 SWITCH

void ascendente(int matriz[][3], int N, int arreglo[9]) {
    int contador = 0;
    // Convertir la matriz en un arreglo unidimensional
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            arreglo[contador] = matriz[i][j];
            contador++;
        }
    }

    // Ordenar el arreglo unidimensional usando burbuja
    int auxiliar;
    int total = N * 3;
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            if (arreglo[j] > arreglo[j + 1]) {
                auxiliar = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = auxiliar;
            }
        }
    }

    // Llenar la matriz con los valores ordenados del arreglo
    contador = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            matriz[i][j] = arreglo[contador];
            contador++;
        }
    }

    cout << "MATRIZ ORDENADA DE FORMA ASCENDENTE: " << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
}

void descendente(int matriz[][3], int N, int arreglo[9]){
    int contador = 0;
    // Convertir la matriz en un arreglo unidimensional
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            arreglo[contador] = matriz[i][j];
            contador++;
        }
    }

    // Ordenar el arreglo unidimensional usando burbuja
    int auxiliar;
    int total = N * 3;
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            if (arreglo[j] < arreglo[j + 1]) {
                auxiliar = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = auxiliar;
            }
        }
    }

    // Llenar la matriz con los valores ordenados del arreglo
    contador = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            matriz[i][j] = arreglo[contador];
            contador++;
        }
    }

    cout << "MATRIZ ORDENADA DE FORMA DESCENDENTE: " << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }

}

void caseCinco(int matriz[][3], int N, int arreglo[9]) {
    int opcionCaseCinco;
    cout << "ELIJA UNA OPCION: " << endl;
    cout << "1. ORDENAR LA MATRIZ DE FORMA ASCENDENTE" << endl;
    cout << "2. ORDENAR LA MATRIZ DE FORMA DESCENDENTE" << endl;
    cin >> opcionCaseCinco;

    while (opcionCaseCinco < 1 || opcionCaseCinco > 2) {
        cout << "EL NUMERO SOLO PUEDE SER UNO O DOS, ingrese otro: ";
        cin >> opcionCaseCinco;
    }

    if (opcionCaseCinco == 1) {
        ascendente(matriz, N, arreglo);
    } else{
        descendente(matriz, N, arreglo);
    }
}