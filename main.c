#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROZMIAR_TABLICY 15
#define MIN 2
#define MAX 10
#define Rozmiar_histogramu 11

void wypelenijTablice(int *tab, int min, int max);
int sumaTablicy(int *tab);
float sredniaTablicy(int *tab);
void generujHistogram(int *tab, int *hist);
void wypiszTablice(int *tab);
void wypiszStatystyki(int *tab, int suma, float srednia, int *hist);

int main() {
    int tablica[ROZMIAR_TABLICY];
    int histogram[Rozmiar_histogramu];
    for (int i = 0; i < Rozmiar_histogramu; i++) {
        histogram[i] = 0;
    }

    wypelenijTablice(tablica, MIN, MAX);
    generujHistogram(tablica, histogram);
    wypiszTablice(tablica);
    wypiszStatystyki(tablica, sumaTablicy(tablica), sredniaTablicy(tablica), histogram);
    return 0;
}

void wypelenijTablice(int *tab, int min, int max) {
    srand(time(0));

    for (int i = 0; i < ROZMIAR_TABLICY; i++) {
        tab[i] = MIN + rand() % (MAX - MIN + 1);
    }
}

int sumaTablicy(int *tab) {
    int suma = 0;
    for (int i = 0; i < ROZMIAR_TABLICY; i++) {
        suma = suma + tab[i];
    }
    return suma;
}

float sredniaTablicy(int *tab) {
    float srednia = 0;
    srednia = (float)sumaTablicy(tab) / ROZMIAR_TABLICY;
    return srednia;
}

void generujHistogram(int *tab, int *hist) {
    for(int i=0; i<ROZMIAR_TABLICY; i++){
        hist[tab[i]]=hist[tab[i]]+1;
    }
}

void wypiszTablice(int *tab) {
    printf("\n[");
    for (int i = 0; i < ROZMIAR_TABLICY; i++) {
        printf("%d ", tab[i]);
    }
    printf("]\n");
}

void wypiszStatystyki(int *tab, int suma, float srednia, int *hist){
    printf("Suma: %d \n", suma);
    printf("Srednia: %.2f \n", srednia);
    for (int i = 0; i < Rozmiar_histogramu; ++i) {
        printf("%d -> %d \n", i, hist[i]);
    }
}