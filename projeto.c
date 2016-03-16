#include <stdio.h>
#include <string.h>
#include "projeto.h"


char labirinto[999][999];
int labX=0, labY=0;
struct ratPos posicaoRato;

/*  
    1
  0 + 2 
    3
*/

void constroiGrafico(){
    //"LIMPA" O TERMINAL
    for (int linha=0; linha<TERMINAL_LINES-labX; linha++) {
        printf("\n");
    }
	for (int linha=0; linha<labX; linha++) {
  		for (int coluna=0;coluna<labY;coluna++){
            if (linha == posicaoRato.x && coluna == posicaoRato.y) {
                switch(posicaoRato.direcao) {
                    case 0: printf("<"); break;
                    case 1: printf("^"); break;
                    case 2: printf(">"); break;
                    case 3: printf("v"); break;
                }
            } else {
                printf("%c",labirinto[linha][coluna]);
            }
        }
        printf("\n");
    }
}
void consomeQueijo() {
	if (labirinto[posicaoRato.x][posicaoRato.y] == 'C') {
		posicaoRato.barriga++;
		labirinto[posicaoRato.x][posicaoRato.y] = '.';
		printf("\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a");
	}
	return;
}

int ratoChegouNoFinal() {
	if (labirinto[posicaoRato.x][posicaoRato.y] == 'E') {
		return 1;
	}
	return 0;
}

void movimentaRato() {
	// vai em direcao a ., C, E
	while (1==1) {	
            		if (posicaoRato.decrementando == 0) {
			if (posicaoRato.direcao == 0) {
				if (labirinto[posicaoRato.x][posicaoRato.y-1] != '#') {
					posicaoRato.y--;
					return;
				} else {
					posicaoRato.direcao++;
				}
			}
			if (posicaoRato.direcao == 1) {
				if (labirinto[posicaoRato.x-1][posicaoRato.y] != '#') {
					posicaoRato.x--;
					return;
				} else {
					posicaoRato.direcao++;
				}
			}
			if (posicaoRato.direcao == 2) {
				if (labirinto[posicaoRato.x][posicaoRato.y+1] != '#') {
					posicaoRato.y++;
					return;
				} else {
					posicaoRato.direcao++;
				}
			}
			if (posicaoRato.direcao == 3) {
				if (labirinto[posicaoRato.x+1][posicaoRato.y] != '#') {
					posicaoRato.x++;
					return;
				} else {
					posicaoRato.direcao--;
					posicaoRato.decrementando = 1;
				}
			}
		}

		if (posicaoRato.decrementando == 1) {
			if (posicaoRato.direcao == 2) {
				if (labirinto[posicaoRato.x][posicaoRato.y+1] != '#') {
					posicaoRato.y++;
					return;
				} else {
					posicaoRato.direcao--;
				}
			}
			if (posicaoRato.direcao == 1) {
				if (labirinto[posicaoRato.x-1][posicaoRato.y] != '#') {
					posicaoRato.x--;
					return;
				} else {
					posicaoRato.direcao--;
					posicaoRato.decrementando = 0;
				}
			}
		}
	}
}

void colocaRatoNoInicio() {
	struct ratPos inicio = pegaPosicaoInicial();
	posicaoRato.x = inicio.x;
	posicaoRato.y = inicio.y;
	posicaoRato.direcao = 0;
	posicaoRato.decrementando = 0;
	posicaoRato.barriga = 0;
}

struct ratPos pegaPosicaoInicial() {
	struct ratPos ret;
	ret.x = -1;	
	ret.y = -1;

	for (int x=0; x<labX; x++) {
		for (int y=0;y<labY;y++) {
			if (labirinto[x][y] == 'S') {
				ret.x = x;
				ret.y = y;
				return ret;
			}
		}
	}

	return ret;
}

int carregaLabirinto(char *filename) {
/*	#E########
	#.......C#
	########.#
	#S......C#
	##########*/
	char tmp[999];
	FILE *fp;

	/* opening file for reading */
	fp = fopen(filename , "r");
	if(fp == NULL) 
	{
		printf("Erro ao abrir arquivo de labirinto.\n");
		return 0;
	}
	int line=0;
	while(fgets(tmp,999,fp)!=NULL) 
	{
		tmp[strlen(tmp)-1] = '\0';
		labY = strlen(tmp);
		strcpy(labirinto[line],tmp);
		//printf("[%s] %i\n",labirinto[line],labY);
		line++;
	}
	labX = line;
	fclose(fp);

	return 1;
}

int retornaZero() {
    return 0;
}
