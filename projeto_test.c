#include "CUnit/Basic.h"
#include "projeto.h"

extern char labirinto[999][999];

extern int labX, labY;

extern struct ratPos posicaoRato;

// 0 = nao, 1 = sim
void testCONSOMEQUEIJO() {
	posicaoRato.x = 3;
	posicaoRato.y = 8;
	consomeQueijo();
	CU_ASSERT(posicaoRato.barriga == 1);
	CU_ASSERT(labirinto[posicaoRato.x][posicaoRato.y] == '.');
	posicaoRato.x = 2;
	posicaoRato.y = 8;
	consomeQueijo();
	CU_ASSERT(posicaoRato.barriga == 1);
	CU_ASSERT(labirinto[posicaoRato.x][posicaoRato.y] == '.');
}

void testRATOCHEGOUNOFINAL() {
	CU_ASSERT (ratoChegouNoFinal() == 1);
}

void testMOVIMENTARATO(void) {
	movimentaRato();
	CU_ASSERT (posicaoRato.x == 3);
	CU_ASSERT (posicaoRato.y == 2);
	movimentaRato();
	CU_ASSERT (posicaoRato.x == 3);
	CU_ASSERT (posicaoRato.y == 3);
	movimentaRato();
	CU_ASSERT (posicaoRato.x == 3);
	CU_ASSERT (posicaoRato.y == 4);
	movimentaRato();
	CU_ASSERT (posicaoRato.x == 3);
	CU_ASSERT (posicaoRato.y == 5);
	movimentaRato();
	CU_ASSERT (posicaoRato.x == 3);
	CU_ASSERT (posicaoRato.y == 6);
	movimentaRato();
	CU_ASSERT (posicaoRato.x == 3);
	CU_ASSERT (posicaoRato.y == 7);
	movimentaRato();
	CU_ASSERT (posicaoRato.x == 3);
	CU_ASSERT (posicaoRato.y == 8);
	movimentaRato();
	CU_ASSERT (posicaoRato.x == 2);
	CU_ASSERT (posicaoRato.y == 8);
	movimentaRato();
	CU_ASSERT (posicaoRato.x == 1);
	CU_ASSERT (posicaoRato.y == 8);
	movimentaRato();
	CU_ASSERT (posicaoRato.x == 1);
	CU_ASSERT (posicaoRato.y == 7);
	movimentaRato();
	CU_ASSERT (posicaoRato.x == 1);
	CU_ASSERT (posicaoRato.y == 6);
	movimentaRato();
	CU_ASSERT (posicaoRato.x == 1);
	CU_ASSERT (posicaoRato.y == 5);
	movimentaRato();
	CU_ASSERT (posicaoRato.x == 1);
	CU_ASSERT (posicaoRato.y == 4);
	movimentaRato();
	CU_ASSERT (posicaoRato.x == 1);
	CU_ASSERT (posicaoRato.y == 3);
	movimentaRato();
	CU_ASSERT (posicaoRato.x == 1);
	CU_ASSERT (posicaoRato.y == 2);
	movimentaRato();
	CU_ASSERT (posicaoRato.x == 1);
	CU_ASSERT (posicaoRato.y == 1);
	movimentaRato();
	CU_ASSERT (posicaoRato.x == 0);
	CU_ASSERT (posicaoRato.y == 1);
}

void testCOLOCARATONOINICIO(void) {
	colocaRatoNoInicio();
	CU_ASSERT (posicaoRato.x == 3);
	CU_ASSERT (posicaoRato.y == 1);
}

void testPEGAPOSICAOINICIAL(void) {
	struct ratPos pos = pegaPosicaoInicial();
	CU_ASSERT (pos.x == 3);
	CU_ASSERT (pos.y == 1);
}

void testCARREGALABIRINTO(void)
{
/*	#E########
	#.......C#
	########.#
	#S......C#
	########## */
	carregaLabirinto("projeto.labirinto.test");
	CU_ASSERT (labX == 5);
	CU_ASSERT (labY == 10);
	for (int x=0; x<labX; x++) {
		for (int y=0;y<labY;y++) {
			CU_ASSERT(labirinto[x][y] != 0);
		}
	}
}

int main() {
 CU_pSuite pSuite = NULL;


   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   /* add a suite to the registry */
   pSuite = CU_add_suite("Conjunto de Testes 1", NULL, NULL);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   /* NOTE - ORDER IS IMPORTANT - MUST TEST fread() AFTER fprintf() */
   if ((NULL == CU_add_test(pSuite, "teste carregaLabirinto", testCARREGALABIRINTO))
	|| (NULL == CU_add_test(pSuite, "teste pegaPosicaoInicial", testPEGAPOSICAOINICIAL))
 	|| (NULL == CU_add_test(pSuite, "teste colocaRatoNoinicio", testCOLOCARATONOINICIO))
	|| (NULL == CU_add_test(pSuite, "teste movimentaRato", testMOVIMENTARATO))
	|| (NULL == CU_add_test(pSuite, "teste ratoChegouNoFinal", testRATOCHEGOUNOFINAL))
	|| (NULL == CU_add_test(pSuite, "teste consomeQueijo", testCONSOMEQUEIJO))
	)

   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* Run all tests using the CUnit Basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}

