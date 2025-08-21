#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>

#define QUANTUM 2
#define NUM_PROCESSOS 8

struct processo{
    int id;
    int tempo_execucao;
    bool terminou;
};

struct processo inicializa_processos(int id, int tempo_execucao){
    struct processo p;
    p.id = id;
    p.tempo_execucao = tempo_execucao;
    p.terminou = false;
    return p;
}

void round_robin(struct processo p[], int num_processos){
    bool todos_terminaram = false;
    while(todos_terminaram == false){
        for(int i = 0; i < num_processos; i++){
            if(p[i].terminou == false){
                printf("O processo %d está sendo executado e tem %d de tempo restante\n", p[i].id, p[i].tempo_execucao);
                Sleep(1000);
                if(p[i].tempo_execucao <= QUANTUM){
                p[i].tempo_execucao = 0;
                p[i].terminou = true;
                printf("O processo %d terminou\n", p[i].id);
                Sleep(1000);
            }
            else{
                p[i].tempo_execucao -= QUANTUM;
            }
            }
        }
        todos_terminaram = true;
        for(int j = 0; j < num_processos; j++){
            if(p[j].terminou == false){
                todos_terminaram = false;
                break;
            }
        }
    }
    printf("Todos os processos terminaram\n");
}

int main(){
    srand(time(NULL));
    struct processo processos[NUM_PROCESSOS];
    for(int i = 0; i < NUM_PROCESSOS; i++){
        processos[i] = inicializa_processos(i+1, (rand() %10) + 1);
    }

    round_robin(processos, NUM_PROCESSOS);

    return 0;
}