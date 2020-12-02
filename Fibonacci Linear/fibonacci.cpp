/*
    Aleix Ferré | https://github.com/CatalaHD
    -----------------------------------------
    Programa que calcula el n numero de Fibonacci fent servir un mètode tradicional recursiu
	un altre de recursiu optimitzat (memoitzant els resultats) i finalment arribem a una
	solució simple guardant només els dos numeros anteriors que volem calcular.
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

// O(2^n) on n=i inicial
int fibbonnaci(int i) {
    if (i <= 1)
        return i;
    return fibbonnaci(i-1) + fibbonnaci(i-2);
}

// O(n) on n=i inicial
int fibbonnaci_recursiveLinear(int i, vector<int>& sequencia) {
    int a, b;
    if (sequencia[i-1] == -1) {
        a = fibbonnaci(i-1);
        sequencia[i-1] = a;
    } else {
        a = sequencia[i-1];
    }
    if (sequencia[i-2] == -1) {
        b = fibbonnaci(i-2);
        sequencia[i-2] = b;
    } else {
        b = sequencia[i-2];
    }
    return a + b;
}

int addOvf(unsigned long long int* result, unsigned long long int a, unsigned long long int b) {
    if( a > ULLONG_MAX - b) {
        return -1;
    } else {
        *result = a + b;
        return 0;
    }
}

// O(n) on n=i inicial
unsigned long long int fibbonnaci_linear(int k) {
    unsigned long long int ant_ant = 0;
    unsigned long long int ant = 1;
    for (int i = 2; i <= k; i++) {
        unsigned long long int aux = ant;
        int res = addOvf(&ant, ant, ant_ant);
        if (res == -1) {
            return 0;
        }
        ant_ant = aux;
    }
    return ant;
}

int main() {
    unsigned long long int res = 1, valor = 0;
    int nivell = 1;

    while (res != 0) {
        nivell++;
        res = fibbonnaci_linear(nivell);
        if (res != 0)
            valor = res;
    }

    cout << setw(20) << "Fib" << " | Index" << endl;
    cout << setw(20) << valor << " | " << nivell <<  endl;
    return 0;
}
