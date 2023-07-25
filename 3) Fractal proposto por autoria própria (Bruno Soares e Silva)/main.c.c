#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *fazerfractal(char *axioma, const char *regraX, const char *regraY, int estagio) {
    if (estagio == 0) {
        return axioma;
    }

    char *temp = malloc(strlen(axioma) * 11);
    temp[0] = '\0';

    for (int i = 0; i < strlen(axioma); i++) {
        if (axioma[i] == 'X') {
            strcat(temp, regraX);
        } else if (axioma[i] == 'Y') {
            strcat(temp, regraY);
        } else {
            strncat(temp, &axioma[i], 1);
        }
    }
    return fazerfractal(temp, regraX, regraY, estagio - 1);
}
void tirarletra(char *sequencia, char c) {
    char *copia1 = sequencia;
    char *copia2 = sequencia;
    for(; *copia2 != 0; copia1++) {
        if((*copia1 == c) && *copia1) continue;
        *copia2 = *copia1;
        copia2++;
        if (!*copia1) return;
    }
}

int main() {
    FILE *arquivo;
    char* fractal;
    char axioma[] = "+X+";
    char regraX[] = "XF+F-FF-Y-FF-F+FX";
    char regraY[] = "YF-F+FF+X+FF+F-FY";

    arquivo = fopen("fractal_Bruno.txt", "wt");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return 0;
    }

    fprintf(arquivo, "3) Fractal proposto por autoria própria (Bruno Soares e Silva)\n");
    fprintf(arquivo, "Regras:  X => XF+F-FF-Y-FF-F+FX     Y => YF-F+FF+X+FF+F-FY \n");
    fprintf(arquivo, "Angulo(em graus): 60 \t Axioma: +X+ \n");
    fprintf(arquivo, "Aluno: Bruno Soares e Silva   Turma: TW\n");
    fprintf(arquivo, "Matrícula: 2021037082\n");

    for (int i = 0; i <= 4; i++) {
        fractal = fazerfractal(axioma, regraX, regraY, i);
        if (i != 0) tirarletra(fractal, 'X');
        if (i != 0) tirarletra(fractal, 'Y');
        fprintf(arquivo, "\nEstágio: %d", i);
        fprintf(arquivo, "\nFractal: %s\n", fractal);
    }
    fclose(arquivo);

    return 0;
}