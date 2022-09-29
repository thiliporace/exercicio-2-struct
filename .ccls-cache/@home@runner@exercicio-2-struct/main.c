#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char nome[100], sexo[100];
  int cpf;
  float altura, peso, IMC;
} dados;
int main(void) {
  int quantidade_pessoas;
  int cpf_input;
  dados dado[200];
  printf("Quantas pessoas? \n");
  scanf("%i", &quantidade_pessoas);
  setbuf(stdin, NULL);
  for (int i = 0; i < quantidade_pessoas; i++) {
    printf("Digite seu nome:\n");
    fgets(dado[i].nome, 100, stdin);
    setbuf(stdin, NULL);
    printf("Digite seu sexo:\n");
    setbuf(stdin, NULL);
    scanf("%s", dado[i].sexo);
    printf("Digite seu CPF:\n");
    setbuf(stdin, NULL);
    scanf("%i", &dado[i].cpf);
    printf("Digite sua altura e seu peso:\n");
    setbuf(stdin, NULL);
    scanf("%f %f", &dado[i].altura, &dado[i].peso);
    setbuf(stdin, NULL);
    // dado[i].media = (dado[i].n1 + dado[i].n2) / 2;
    // printf("Sexo: %s \n", dado[i].sexo);
    // printf("Nome: %s", dado[i].nome);
    // printf("Media: %f \n", dado[i].cpf);
    if (i + 1 == quantidade_pessoas) {
      printf("Digite o CPF da pessoa que deseja encontrar: \n");
      scanf("%i", &cpf_input);
      if (cpf_input == dado[i].cpf) {
        dado[i].IMC = (dado[i].peso / (dado[i].altura * dado[i].altura));
        if (dado[i].IMC <= 18.4) {
          printf("Abaixo do peso\n");
        } else if (dado[i].IMC <= 24.9) {
          printf("Peso normal\n");
        } else if (dado[i].IMC <= 29.9) {
          printf("Sobrepeso\n");
        } else if (dado[i].IMC <= 34.9) {
          printf("Obesidade Grau 1\n");
        } else if (dado[i].IMC <= 39.9) {
          printf("Obesidade Grau 2\n");
        } else {
          printf("Obesidade Grau 3\n");
        }
      }
    }
  }
}