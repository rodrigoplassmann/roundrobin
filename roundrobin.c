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

void round_robin(struct processo p[], int num_processos){
    bool todos_terminaram = false;
    while(todos_terminaram = false){
        for(int i = 0; i < num_processos; i++){
            printf("O processo %d está sendo executado e tem %d de tempo restante\n", p[i].id, p[i].tempo_execucao);
            if(p[i].tempo_execucao <= QUANTUM){
                p[i].tempo_execucao = 0;
                p[i].terminou = true;
                printf("O processo %d terminou", p[i].id);
            }
            else{
                p[i].tempo_execucao -= QUANTUM;
            }
        }
        todos_terminaram = true;
        for(int j = 0; j < num_processos; j++){
            if(p[j].terminou = false){
                todos_terminaram = false;
                break;
            }
        }
    }
}

int main(){

    return 0;
}