#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ProvaI.h"

#define MAX_ALUNOS 1000

int ler_alunos(ALUNO a[]) {

    int i;

    printf("Digite Alunos: \n");
    for (i=0; i<MAX_ALUNOS; i++) {
        scanf("%s %s %s %s %s %s %30[^\n]s",
              a[i].matric, a[i].codDisc[0], a[i].codDisc[1],
              a[i].codDisc[2], a[i].codDisc[3], a[i].codDisc[4], a[i].nome);
        fflush(stdin);
        a[i].medias[0] = a[i].medias[1] = a[i].medias[2] = a[i].medias[3] = a[i].medias[4] = 0.0;
        if (strcmp(a[i].matric, "000000")==0) break;
    }
    return i;
}

int ler_disciplinas(DISCIPLINA d[]) {

    int i;

    printf("Digite Disciplinas: \n");
    for (i=0; i<MAX_DISC_ESCOLA; i++) {
        scanf("%s %20[^\n]s", d[i].codigo, d[i].descr);
        fflush(stdin);
        if (strcmp(d[i].codigo, "000")==0) break;
    }
    return i;
}

int busca_aluno(char matric[], ALUNO a[], int numA) {

    int i;

    for (i=0; i<numA; i++) {
        if (strcmp(matric, a[i].matric)==0) return i;
    }
    return -1;
}


void ler_notas(ALUNO a[], int numA) {

    int i, j;
    char matric[7], codDisc[4];
    float n1, n2, n3;

    printf("Digite Notas: \n");
    while (1) {
        scanf("%s %s %f %f %f", matric, codDisc, &n1, &n2, &n3);
        fflush(stdin);
        if (strcmp(matric, "000000")==0) break;
        if ((i=busca_aluno(matric, a, numA))==-1) {
                printf("Erro grave! Nota digitada para aluno inexistente. Encerrando execucao...\n");
                exit(1);
        }
        for (j=0; j<MAX_DISCIPLINAS; j++)
            if (strcmp(codDisc, a[i].codDisc[j])==0) break;
        if (j>=MAX_DISCIPLINAS) {
            printf("Erro grave! Nota de disciplina inexistente para aluno. Encerrando execucao...\n");
            exit(1);
        }
        a[i].medias[j]=(n1+n2+n3)/3;
    }

}

void calcula_MG(ALUNO a[], int numA) {

    int i;

    for (i=0; i<numA; i++) {
        a[i].mediaGlobal=(a[i].medias[0]+a[i].medias[1]+a[i].medias[2]+
                          a[i].medias[3]+a[i].medias[4])/MAX_DISCIPLINAS;
    }
}

int busca_descricao(char codDisc[], DISCIPLINA d[], int numD) {

    int i;

    for (i=0; i<numD; i++) {
        if (strcmp(codDisc, d[i].codigo)==0) return i;
    }
    return -1;
}

void imprime_historico(ALUNO a[], int numA, DISCIPLINA d[], int numD) {

    int i, j, k;

    for (i=0; i<numA; i++) {
        printf("%s %s - Media Global %4.1f\n", a[i].matric, a[i].nome, a[i].mediaGlobal);
        for (j=0; j<MAX_DISCIPLINAS; j++) {
            if ((k=busca_descricao(a[i].codDisc[j], d, numD))==-1) {
                printf("Erro grave! Disciplina inexistente. Encerrando execucao...\n");
                exit(1);
            }
            printf("\t%s %s\t\t\t%4.1f\n", a[i].codDisc[j], d[k].descr, a[i].medias[j]);
        }
    }
}

int main()
{
    ALUNO alunos[MAX_ALUNOS];
    DISCIPLINA discValidas[MAX_DISC_ESCOLA];
    int numAlunos, numDiscEscola;

    numAlunos=ler_alunos(alunos);
    numDiscEscola=ler_disciplinas(discValidas);
    ler_notas(alunos, numAlunos);
    calcula_MG(alunos, numAlunos);
    imprime_historico(alunos, numAlunos, discValidas, numDiscEscola);

    return 0;
}
