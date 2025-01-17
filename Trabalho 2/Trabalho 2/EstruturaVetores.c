#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"



/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{


 if (tamanho < 1){
    return TAMANHO_INVALIDO;
 }
 else if(posicao > 10 || posicao < 1){
    return POSICAO_INVALIDA;
 }
 else if(VetorPrincipal[posicao - 1] != NULL){
    return JA_TEM_ESTRUTURA_AUXILIAR;
 }else{
    VetorPrincipal[posicao - 1] = (Auxiliar*)malloc(sizeof(Auxiliar));
    VetorPrincipal[posicao - 1] ->elementos = (int*)malloc(tamanho * sizeof(int));
    if (VetorPrincipal[posicao - 1]->elementos == NULL){
        free(VetorPrincipal[posicao - 1]);
        return SEM_ESPACO_DE_MEMORIA;
    }else{
        VetorPrincipal[posicao - 1]->qtdElementos = 0;
        VetorPrincipal[posicao - 1]->tam = tamanho;
        return SUCESSO;
    }
 }

 
    













    /*int retorno = 0;
    // a posicao pode já existir estrutura auxiliar
    retorno = JA_TEM_ESTRUTURA_AUXILIAR;
    // se posição é um valor válido {entre 1 e 10}
    retorno = POSICAO_INVALIDA;
    // o tamanho ser muito grande
    retorno = SEM_ESPACO_DE_MEMORIA;
    // o tamanho nao pode ser menor que 1
    retorno = TAMANHO_INVALIDO;
    // deu tudo certo, crie
    retorno = SUCESSO;

    return retorno;*/
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int retorno = 0;
  

    if (posicao > 10 || posicao < 1){
        retorno = POSICAO_INVALIDA;}
    else
    {
        // testar se existe a estrutura auxiliar
        if (VetorPrincipal[posicao- 1] == NULL){
            return SEM_ESTRUTURA_AUXILIAR;
        }
        {
            if (VetorPrincipal[posicao-1]->qtdElementos < VetorPrincipal[posicao-1]->tam )
            {
                VetorPrincipal[posicao - 1]->elementos[VetorPrincipal[posicao - 1]->qtdElementos] = valor;
                VetorPrincipal[posicao - 1]->qtdElementos +=1;
                retorno = SUCESSO;
            }
            else
            {
                retorno = SEM_ESPACO;
            }
        }
       
    }

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
   if(posicao>10 || posicao < 1){
    return POSICAO_INVALIDA;
   }else if(VetorPrincipal[posicao-1] == NULL){
    return SEM_ESTRUTURA_AUXILIAR;
   }
   else if(VetorPrincipal[posicao-1]->qtdElementos == 0){
    return ESTRUTURA_AUXILIAR_VAZIA;
   }else{
    VetorPrincipal[posicao - 1]->qtdElementos -= 1;
    return SUCESSO;
   }
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    
    int achou = 1;
    if(VetorPrincipal[posicao-1] == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }else if(VetorPrincipal[posicao-1]->qtdElementos == 0){
        return ESTRUTURA_AUXILIAR_VAZIA;
    }else if(posicao < 1 || posicao > 10){
        return POSICAO_INVALIDA;
    }else{
        for(int i = 0;i< VetorPrincipal[posicao-1]->tam;i++){
            if(valor == VetorPrincipal[posicao-1]->elementos[i]){
                achou = 0;
                for(int j = i;j < VetorPrincipal[posicao - 1]->qtdElementos-1;j++){
                    VetorPrincipal[posicao-1]->elementos[j] = VetorPrincipal[posicao-1]->elementos[j + 1];
                    
                   
                }
                VetorPrincipal[posicao-1]->qtdElementos -= 1;
            }
        }
    }
    if(achou == 1){
        return NUMERO_INEXISTENTE;
    }
    else
    return SUCESSO;
    
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    if(posicao < 1 || posicao > 10){
        return POSICAO_INVALIDA;}
    else if(VetorPrincipal[posicao-1] == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }else{
        for(int i = 0,j = 0;i < VetorPrincipal[posicao-1]->qtdElementos;i++,j++){
            vetorAux[i] = VetorPrincipal[posicao-1]->elementos[j];
        }
        return SUCESSO;
    }
                

}
/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
int i,j,tamanho,aux;
     if(posicao < 1 || posicao > 10){
        return POSICAO_INVALIDA;}
    else if(VetorPrincipal[posicao-1] == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }else{
        for(i = 0,j = 0;i < VetorPrincipal[posicao-1]->qtdElementos;i++,j++){
            vetorAux[i] = VetorPrincipal[posicao-1]->elementos[j];
        }
            tamanho = i;
            for(i = 0;i<tamanho - 1;i++){
                for(j = 0;j< tamanho - i - 1; j++){
                    if(vetorAux[j]>vetorAux[j+1]){
                        aux = vetorAux[j];
                        vetorAux[j] = vetorAux[j+1];
                        vetorAux[j+1]= aux;}
                }

            }
            return SUCESSO;
    }
   
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int j,i,k = 0;
    int contador = 0;
    for(i = 0;i<10;i++){
        if(VetorPrincipal[i] == NULL){
            contador++;
        }else if(VetorPrincipal[i]->qtdElementos <=0 ){
            contador++;
        }
    }if(contador == 10){
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }
    
    for(i= 0; i<10;i++){
        if(VetorPrincipal[i] != NULL){
        for(j = 0;j < VetorPrincipal[i]->qtdElementos;j++,k++){
            vetorAux[k] = VetorPrincipal[i]->elementos[j];
            
        }

    }}
    return SUCESSO;
 
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
int j,i,aux,tamanho,k = 0;
    int contador = 0;
    for(i = 0;i<10;i++){
        if(VetorPrincipal[i] == NULL){
            contador++;
        }else if(VetorPrincipal[i]->qtdElementos <=0 ){
            contador++;
    }}
    if(contador == 10){
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }
    
    for(i= 0; i<10;i++){
        if(VetorPrincipal[i] != NULL){
        for(j = 0;j < VetorPrincipal[i]->qtdElementos;j++,k++){
            vetorAux[k] = VetorPrincipal[i]->elementos[j];
            
        }

    }}
    tamanho = k;
    
     for(i = 0;i<tamanho - 1;i++){
                for(j = 0;j< tamanho - i - 1; j++){
                    if(vetorAux[j]>vetorAux[j+1]){
                        aux = vetorAux[j];
                        vetorAux[j] = vetorAux[j+1];
                        vetorAux[j+1]= aux;}
                }

            }
    return SUCESSO;
   
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    if (posicao > 10 || posicao < 1) {
        return POSICAO_INVALIDA;
    } else if (VetorPrincipal[posicao-1] == NULL) {
        return SEM_ESTRUTURA_AUXILIAR;
    } else if (VetorPrincipal[posicao-1]->tam + novoTamanho < 1) {
        return NOVO_TAMANHO_INVALIDO;
    } else {
        int novoTam = VetorPrincipal[posicao-1]->tam + novoTamanho;  // Corrigido o índice aqui
        int* novaEstrutura = realloc(VetorPrincipal[posicao-1]->elementos, novoTam * sizeof(int));  // Ajustando também o ponteiro de elementos
        if (novaEstrutura == NULL) {
            return SEM_ESPACO_DE_MEMORIA;
        } else {
            VetorPrincipal[posicao-1]->elementos = novaEstrutura;  // Atribuindo o novo ponteiro à estrutura
            VetorPrincipal[posicao-1]->tam = novoTam;  // Atualizando o tamanho da estrutura
            return SUCESSO;
        }
    }
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    if(posicao > 10 || posicao < 1){
        return POSICAO_INVALIDA;
    }else if(VetorPrincipal[posicao-1]== NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }else if(VetorPrincipal[posicao-1]->qtdElementos==0){
        return ESTRUTURA_AUXILIAR_VAZIA;
    }else{
        return VetorPrincipal[posicao-1]->qtdElementos;
    }
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{
    // Alocar o nó cabeçote
    No *inicio = (No *)malloc(sizeof(No));
    if (!inicio)
        return NULL; 

    inicio->prox = NULL; 
    No *ultimo = inicio;


    for (int i = 0; i < 10; i++)
    {
        if (VetorPrincipal[i] && VetorPrincipal[i]->qtdElementos > 0)
        {
            for (int j = 0; j < VetorPrincipal[i]->qtdElementos; j++)
            {
                // Criar um novo nó para cada elemento
                No *novo = (No *)malloc(sizeof(No));
                if (!novo)
                {
                    destruirListaEncadeadaComCabecote(&inicio);
                    return NULL; 
                }
                novo->conteudo = VetorPrincipal[i]->elementos[j];
                novo->prox = NULL;

                
                ultimo->prox = novo;
                ultimo = novo;
            }
        }
    }

    
    if (inicio->prox == NULL)
    {
        free(inicio); // Liberar o cabeçote vazio
        return NULL;
    }

    return inicio;

}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
      if (!inicio)
        return; 

    No *atual = inicio->prox; 
    int i = 0;

    while (atual)
    {
        vetorAux[i++] = atual->conteudo;
        atual = atual->prox;
    }
    
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
   if (!inicio || !(*inicio))
        return; 

    No *atual = *inicio;
    while (atual)
    {
        No *prox = atual->prox;
        free(atual);
        atual = prox;
    }

    *inicio = NULL; 
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar()
{
   
    for(int i = 0; i<10;i++){
        VetorPrincipal[i] = NULL;
    }
   
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
  for(int i = 0; i < 10;i++){
    if(VetorPrincipal[i] != NULL){
        free(VetorPrincipal[i]->elementos);
        free(VetorPrincipal[i]);
    }
  }
}
