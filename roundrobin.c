#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define QUANTUM 2
#define MAX_PROCESSOS 8

struct processo{
    int id;
    int tempo_execucao;
    bool terminou;
};

struct processo inicializa_processos(int id, int tempo_execucao){
    int id = id;
    int tempo_execucao = tempo_execucao;
    bool terminou = false;
}

void round_robin(){

}

int main(){

    return 0;
}