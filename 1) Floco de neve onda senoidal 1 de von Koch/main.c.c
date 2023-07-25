#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *fazerfractal(char *axioma, const char *regraF, int estagio) {
    if (estagio == 0) {
        return axioma;
    }

    char *temp = malloc(strlen(axioma) * 11);
    temp[0] = '\0';

    for (int i = 0; i < strlen(axioma); i++) {
        if (axioma[i] == 'F') {
            strcat(temp, regraF); 
        } else {
            strncat(temp, &axioma[i], 1);
        }
    }
    return fazerfractal(temp, regraF, estagio - 1);
}

int main() {
    FILE *arquivo;
    char* fractal;
    char axioma[] = "F";
    char regraF[] = "F-F++FF--F+F";

    arquivo = fopen("fractal_Bruno.txt", "wt");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return 0;
    }

    fprintf(arquivo, "1) Floco de neve onda senoidal 1 de von Koch\n");
    fprintf(arquivo, "Regra:  F => F-F++FF--F+F \t Angulo(em graus): 60 \t Axioma: F \n");
    fprintf(arquivo, "Aluno: Bruno Soares e Silva   Turma: TW\n");
    fprintf(arquivo, "Matrícula: 2021037082\n");

    for (int i = 0; i <= 4; i++) {
        fractal = fazerfractal(axioma, regraF, i);
        fprintf(arquivo, "\nEstágio: %d", i);
        fprintf(arquivo, "\nFractal: %s\n", fractal);
    }
    fclose(arquivo);

    return 0;
}