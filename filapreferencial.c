/*********************************************************************/
/**   ACH2023 - Algoritmos e Estruturas de Dados I                  **/
/**   EACH-USP - Seugndo Semestre de 2020                           **/
/**   <turma> - Prof. Luciano Antonio Digiampietri                  **/
/**                                                                 **/
/**   EP2 - Fila Preferencial                                       **/
/**                                                                 **/
/**   Otto Alves                               10843361             **/
/**                                                                 **/
/*********************************************************************/

#include "filapreferencial.h"

PFILA criarFila(){
  PFILA res = (PFILA) malloc(sizeof(FILAPREFERENCIAL));
  res->inicioPref = NULL;
  res->fimPref = NULL;
  res->inicioGeral = NULL;
  res->fimGeral = NULL;
  return res;
}

int tamanho(PFILA f){
  PONT atual = f->inicioGeral;
  int tam = 0;
  while (atual) {
    atual = atual->prox;
    tam++;
  }
  return tam;
}

int tamanhoFilaPreferencial(PFILA f){
  PONT atual = f->inicioPref;
  int tam = 0;
  while (atual) {
    atual = atual->prox;
    tam++;
  }
  return tam;
}

PONT buscarID(PFILA f, int id){
  PONT atual = f->inicioGeral;
   while (atual) {
    if (atual->id == id) return atual;
    atual = atual->prox;
  }
  return NULL;
}

void exibirLog(PFILA f){
  int numElementos = tamanho(f);
  printf("\nLog fila geral [elementos: %i] - Inicio:", numElementos);
  PONT atual = f->inicioGeral;
  while (atual){
    printf(" [%i;%i]", atual->id, atual->ehPreferencial);
    atual = atual->prox;
  }
  printf("\n");
  numElementos = tamanhoFilaPreferencial(f);
  printf("\nLog fila preferencial [elementos: %i] - Inicio:", numElementos);
  atual = f->inicioPref;
  while (atual){
    printf(" [%i;%i]", atual->id, atual->ehPreferencial);
    atual = atual->prox;
  }
  printf("\n\n");
}


bool inserirPessoaNaFila(PFILA f, int id, int ehPreferencial){
  bool resposta = false;
  PONT aux, ant;
  aux = buscarID(f, id);
  if (id < 0 || aux!= NULL) return false;
  aux = (PONT) malloc(sizeof(ELEMENTO));
  aux->id = id;
  aux->ehPreferencial = ehPreferencial;
  ant = f->inicioGeral;
  if(ant == NULL){
    f->inicioGeral = aux;
    f->fimGeral = aux;
  } else {
    while(ant->prox != NULL) {
      ant = ant->prox;
    }
    (ant->prox) = aux;
    f->fimGeral = aux;
  }
  if(ehPreferencial == 1 || ehPreferencial == true) {
    PONT aux2 = (PONT) malloc(sizeof(ELEMENTO));
    aux2->id = id;
    aux2->ehPreferencial = ehPreferencial;
    ant = f->inicioPref;
    if(ant == NULL){
      f->inicioPref = aux2;
      f->fimPref = aux2;
    } else {
      while(ant->prox != NULL) {
        ant = ant->prox;
      }
      (ant->prox) = aux2;
      f->fimPref = aux2;
    }
  }
  resposta = true;
  return resposta;
}



bool atenderPrimeiraDaFilaPreferencial(PFILA f, int* id){
  bool resposta = false;
  if(tamanho(f) == 0) return resposta;
  PONT* atendido = f->inicioPref;
  f->inicioPref = atendido->prox;
  *id = atendido->id;
  //free(atendido)
  //usar id para buscar e tirar da fila geral
  resposta = true;
  return resposta;
}



bool atenderPrimeiraDaFilaGeral(PFILA f, int* id){
  bool resposta = false;
  if(tamanho(f) == 0) return resposta;
  /* COMPLETAR */
  resposta = true;
  return resposta;
}



bool desistirDaFila(PFILA f, int id){
  bool resposta = false;
  PONT aux = buscarID(f, id);
  if(aux == NULL) return resposta;

  /* COMPLETAR */
  resposta = true;
  return resposta;
}
