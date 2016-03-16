#!/bin/sh
gcc -std=c99 -Wall -I/usr/lib projeto.c projeto_test.c -L/usr/lib -lcunit -o projeto_test
gcc -std=c99 -Wall -I/usr/lib projeto.c projeto_main.c -L/usr/lib -lcunit -o projeto
