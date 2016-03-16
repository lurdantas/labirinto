#define _BSD_SOURCE
#include <stdio.h>
#include <unistd.h>
#include "projeto.h"

extern char labirinto[999][999];

extern int labX, labY;

extern struct ratPos posicaoRato;


int main(int argc, char *argv[]) {
    int cl = 0;
	if (argc != 2) {
		printf("uso: ./projeto <nome do labirinto>\n");
		return 1;
	}

        printf("Carregando labirinto: %s.\n", argv[1]);
	cl = carregaLabirinto(argv[1]);
	if (cl == 0) {
		printf("Erro ao carregar labirinto.\n");
		return 1;
	}

	colocaRatoNoInicio();
	while (ratoChegouNoFinal() == 0) {
		movimentaRato();
		consomeQueijo();
		constroiGrafico();
		usleep(300000);
	}

    printf("Queijos consumidos: %i.\n", posicaoRato.barriga);
}

