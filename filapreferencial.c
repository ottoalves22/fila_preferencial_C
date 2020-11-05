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
  resposta = true;
  PONT atendido = f->inicioPref;
  if(atendido!=NULL){
    *id = atendido->id;
    f->inicioPref = atendido->prox;
    PONT aux = f->inicioGeral;
    PONT ant = NULL;
    if(f->inicioGeral->id == *id){
      f->inicioGeral = aux->prox;
    } else {
      while(aux->id != *id){
        ant = aux;
        aux = aux->prox;
      }
      ant->prox = aux->prox;
    }

    free(aux);
    free(atendido);
    resposta = true;
    return resposta;
  }
}



bool atenderPrimeiraDaFilaGeral(PFILA f, int* id){
  bool resposta = false;
  if(tamanho(f) == 0) return resposta;
  resposta = true;
  PONT atendido = f->inicioGeral;
  if(atendido!=NULL){
    *id = atendido->id;
    f->inicioGeral = atendido->prox;
    if(atendido->ehPreferencial == true) {
        PONT aux = f->inicioPref;
        while(aux->id != *id){
          aux = aux->prox;
        }
        f->inicioPref = aux->prox;
        free(aux);
    }
  free(atendido);
  }
  return resposta;
}


bool desistirDaFila(PFILA f, int id){
  bool resposta = false;
  PONT aux = buscarID(f, id);
  if(aux == NULL) return resposta;
  if(aux->ehPreferencial == true){
    //fila preferencial
    PONT pref = f->inicioPref;
    PONT ant = NULL;
    if(f->inicioPref->id == id){
      f->inicioPref = pref->prox;
    } else {
      while(pref->id != id){
        ant = pref;
        pref = pref->prox;
      }
      ant->prox = pref->prox;
    }
    if(ant != NULL)ant->prox = pref->prox;
    free(pref);
    //fila geral
    PONT geral = f->inicioGeral;
    ant = NULL;
    if(f->inicioGeral->id == id){
      f->inicioGeral = geral->prox;
    } else {
      while(geral->id != id){
        ant = geral;
        geral = geral->prox;
      }
      ant->prox = aux->prox;
    }
    if(ant != NULL)ant->prox = geral->prox;
    free(geral);

    resposta = true;
    return resposta;
  } else {
    PONT geral = f->inicioGeral;
    PONT ant = NULL;

    if(f->inicioGeral->id == id){
      f->inicioGeral = geral->prox;
    } else {
      while(geral->id != id){
        ant = geral;
        geral = geral->prox;
      }
      ant->prox = aux->prox;
    }
    if(ant != NULL)ant->prox = geral->prox;
    free(geral);
    resposta = true;
    return resposta;
  }
}
