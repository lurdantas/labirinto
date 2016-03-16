#include <stdio.h>
#include <unistd.h>
#include "projeto.h"

extern char labirinto[999][999];

extern int labX, labY;

extern struct ratPos posicaoRato;


int main() {
    carregaLabirinto("projeto.labirinto.test");
    colocaRatoNoInicio();
    while (ratoChegouNoFinal() == 0) {
        movimentaRato();
        consomeQueijo();
        constroiGrafico();
        usleep(300000);
    }
    printf("Queijos consumidos: %i.\n", posicaoRato.barriga);
}

