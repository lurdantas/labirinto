struct ratPos {
	int x;
	int y;
	int direcao;
	int decrementando;
	int barriga;
};
int carregaLabirinto();
struct ratPos pegaPosicaoRato();
struct ratPos pegaPosicaoInicial();
void colocaRatoNoInicio();
void movimentaRato();
int ratoChegouNoFinal();
void consomeQueijo();
void constroiGrafico();

#define TERMINAL_LINES 24

