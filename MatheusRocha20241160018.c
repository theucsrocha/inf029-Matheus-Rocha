// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Matheus Cerqueira Rocha Santos
//  email: theucsrocha@gmail.com
//  Matrícula:20241160018
//  Semestre:2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################
#include <string.h>
#include <stdio.h>
#include "MatheusRocha20241160018.h"  // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>

DataQuebrada quebraData(char data[]);

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;

  for (i = x; i > 1; i--)
    fat = fat * i;

  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[])
{
    int datavalida = 0;
DataQuebrada dq = quebraData(data);
if (dq.valido == 0){
    return 0;}
else{
    if (dq.iDia < 1 || dq.iDia > 31){
        return 0;}
    }
if (dq.iMes > 12 || dq.iMes < 1){
        return 0;}
    


if((dq.iAno % 4 == 0 && dq.iAno % 100 != 0) || dq.iAno % 400 == 0 ){
        if (dq.iDia > 29){
            return 0;
        }
    }
    else{
        if(dq.iMes == 2 && dq.iDia > 28){
            return 0;
        }
    }
if (dq.iMes == 1 || dq.iMes == 3 || dq.iMes == 5 || dq.iMes == 7 || dq.iMes == 8 || dq.iMes == 10 || dq.iMes == 12){
    if (dq.iDia > 31){
        return 0;
    }
}
if(dq.iMes == 4 || dq.iMes == 6 || dq.iMes == 9 || dq.iMes == 11 ){
    
    if (dq.iDia > 30){
        return 0;
    }
}

datavalida = 1;
  
   
    
    
   
    
    

  //quebrar a string data em strings sDia, sMes, sAno


  //printf("%s\n", data);

  if (datavalida)
      return 1;
  else
      return 0;
}



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{

    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;
    dma.qtdAnos = 0;
    dma.qtdDias = 0;
    dma.qtdMeses = 0;
    
    dma.retorno = 1;
    DataQuebrada dataInicial = quebraData(datainicial);
    DataQuebrada dataFinal = quebraData(datafinal);
    
    if(dataInicial.iMes > 12 || dataInicial.iDia > 31){
        dma.retorno = 2;
    }
    if(dataFinal.iMes > 12 || dataFinal.iDia > 31){
        dma.retorno = 2;
    }
    
    if(dataInicial.valido == 0){
        dma.retorno = 2;
    }
    if(dataFinal.valido == 0){
        dma.retorno = 3;
    }
    if((dataInicial.iAno > dataFinal.iAno) || (dataInicial.iAno == dataFinal.iAno) && (dataInicial.iMes > dataFinal.iMes) || (dataInicial.iAno == dataFinal.iAno) && (dataInicial.iMes > dataFinal.iMes) && (dataInicial.iDia > dataFinal.iDia) ){
        dma.retorno = 4;
    }
    dma.qtdAnos = dataFinal.iAno - dataInicial.iAno;
    dma.qtdMeses = dataFinal.iMes - dataInicial.iMes;
    dma.qtdDias = dataFinal.iDia - dataInicial.iDia;

    
    if (dma.qtdDias < 0) {
        dma.qtdDias += diasNoMes(dataFinal.iMes - 1, dataFinal.iAno); // Empresta dias do mês anterior
        dma.qtdMeses--;
    }
    if (dma.qtdMeses < 0) {
        dma.qtdMeses += 12;
        dma.qtdAnos--;
    }

    return dma;

}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = 0;
    if (isCaseSensitive == 1){
        for (int i = 0; texto[i] != '\0';i++){
            if (c == texto[i]){
                qtdOcorrencias++;
            }
            else if ((c == 'a' && (strcmp(&texto[i], "á") == 0 || strcmp(&texto[i], "à") == 0 || 
                                   strcmp(&texto[i], "â") == 0 || strcmp(&texto[i], "ã") == 0)) ||
                     (c == 'e' && (strcmp(&texto[i], "é") == 0 || strcmp(&texto[i], "è") == 0 || 
                                   strcmp(&texto[i], "ê") == 0)) ||
                     (c == 'i' && (strcmp(&texto[i], "í") == 0 || strcmp(&texto[i], "ì") == 0 || 
                                   strcmp(&texto[i], "î") == 0)) ||
                     (c == 'o' && (strcmp(&texto[i], "ó") == 0 || strcmp(&texto[i], "ò") == 0 || 
                                   strcmp(&texto[i], "ô") == 0 || strcmp(&texto[i], "õ") == 0)) ||
                     (c == 'u' && (strcmp(&texto[i], "ú") == 0 || strcmp(&texto[i], "ù") == 0 || 
                                   strcmp(&texto[i], "û") == 0))) {
                qtdOcorrencias++;
            }
    }
    }
    else{
         for(int i = 0; texto[i] != '\0';i++){
             if(c == texto[i] || c == texto[i] - 32 || c == texto[i] + 32){
                 qtdOcorrencias++;
             }
             else if (((c == 'a' || c == 'A')  && (strcmp(&texto[i], "á") == 0 || strcmp(&texto[i], "à") == 0 || 
                                    strcmp(&texto[i], "â") == 0 || strcmp(&texto[i], "ã") == 0)) ||
                      ((c == 'e' || c == 'E') && (strcmp(&texto[i], "é") == 0 || strcmp(&texto[i], "è") == 0 || 
                                    strcmp(&texto[i], "ê") == 0)) ||
                      ((c == 'i' || c == 'I') && (strcmp(&texto[i], "í") == 0 || strcmp(&texto[i], "ì") == 0 || 
                                    strcmp(&texto[i], "î") == 0)) ||
                      ((c == 'o' || c == 'O') && (strcmp(&texto[i], "ó") == 0 || strcmp(&texto[i], "ò") == 0 || 
                                    strcmp(&texto[i], "ô") == 0 || strcmp(&texto[i], "õ") == 0)) ||
                      ((c == 'u' || c == 'U') && (strcmp(&texto[i], "ú") == 0 || strcmp(&texto[i], "ù") == 0 || 
                                    strcmp(&texto[i], "û") == 0))) {
                 qtdOcorrencias++;
             }
        }
    }
    

    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    
    int qtdOcorrencias = 0;
    int inicial=0;
    int fim=0;
    int prencher = 0;
    int i,j,k;
    for(i = 0;strTexto[i] != '\0';i++){
        
        if(strTexto[i] == strBusca[0]){
            inicial = i;
            for(k = i,j = 0;strBusca[j] != '\0';j++,k++){
                if(strBusca[j] != strTexto[k]){
                    break;
                }

        }
            fim = k;
    for(int o = 0;o<k ;o++){
        if((int)strTexto[o] == -61){
            inicial--;
            fim--;
            }
    }
       
        
        if(strBusca[j] == '\0'){
            if(prencher + 1 <30){
            posicoes[prencher]=inicial+1;
            posicoes[prencher+1]=fim;
            prencher+=2;
            qtdOcorrencias++;
        }}
        }}
    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
char str[10];
char strInvertida[10];
    int i = 0;
    int j = 0;
    

    while (num > 0){
        str[i] = (num%10)+ '0';
        num = num/10;
        i++;  
    }
    str[i] = '\0';
    
    num = atoi(str);
    
    return num;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    char StrBase[10];
    char StrBusca[10];
    int qtdOcorrencias = 0,j,k,i;
    sprintf(StrBase,"%d",numerobase);
    sprintf(StrBusca, "%d", numerobusca);
    for(int i = 0; StrBase[i] != '\0';i++){
        if(StrBase[i] == StrBusca[0]){
            for(j = i, k = 0; StrBusca[k] != '\0';j++,k++){
                if(StrBusca[k] != StrBase[j]){
                    break;
                }
            }
            if(StrBusca[k] == '\0'){
                qtdOcorrencias++;
            }
        }
    }
    
    
    return qtdOcorrencias;
}



/*
DataQuebrada qebraDataq2(char data[]){
    DataQuebrada dq;
    DataQuebrada dq2;
  char sDia[3];
  char sMes[3];
  char sAno[5];
  int i; 

  for (i = 0; data[i] != '/'; i++){
    sDia[i] = data[i];	
  }
  if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
    sDia[i] = '\0';  // coloca o barra zero no final
  }else {
    dq.valido = 0;
    return dq;
  }  


  int j = i + 1; //anda 1 cada para pular a barra
  i = 0;

  for (; data[j] != '/'; j++){
    sMes[i] = data[j];
    i++;
  }

  if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
    sMes[i] = '\0';  // coloca o barra zero no final
  }else {
    dq.valido = 0;
    return dq;
  }


  j = j + 1; //anda 1 cada para pular a barra
  i = 0;

  for(; data[j] != '\0'; j++){
    sAno[i] = data[j];
    i++;
  }

  if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
    sAno[i] = '\0';  // coloca o barra zero no final
  }else {
    dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 
    return dq;
}

*/
DataQuebrada quebraData(char data[]){
    char sDias[3];
    char sMes[3];
    char sAno[5];
    DataQuebrada dq;
int i,j;
int cont;
    for (i = 0,cont = 0; data[i]!= '/';i++){
        sDias[i] = data[i];
    
    if(data[i] < '0' || data[i] > '9'){
        return dq;
    }
        
    }
   
    sDias[i] = '\0';
    i++;
    for (j = 0; data[i]!= '/';i++,j++){
        sMes[j] = data[i];
    
    if(data[i] < '0' || data[i] > '9'){
        return dq;
    }

    }
    
        
    sMes[j] = '\0';
        i++;
    for ( j = 0; data[i]!= '\0';i++,j++){
        sAno[j] = data[i];
        if(data[i] < '0' || data[i] > '9'){
            return dq;
        }

        
    }
    sAno [j] = '\0';
    
   if (strlen(sDias) != 1 && strlen(sDias) != 2){
       return dq;
   }
    if (strlen(sMes) != 1 && strlen(sMes) != 2){
       return dq;
   }
    if (strlen(sAno) != 2 && strlen(sAno) != 4){
       return dq;
   }
    dq.iDia = atoi(sDias);
    dq.iMes = atoi(sMes);
    dq.iAno = atoi(sAno);
    dq.valido = 1;
    if(dq.iMes>12 || dq.iDia>31){
        dq.valido = 0;
    }
    return dq;    
    
}
int diasNoMes(int mes, int ano) {
    if (mes == 2) {
        // Verifica se é ano bissexto
        return (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)) ? 29 : 28;
    }
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        return 30;
    }
    return 31; // Meses com 31 dias
}
