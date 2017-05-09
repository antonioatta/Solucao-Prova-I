#ifndef PROVAI_H_INCLUDED
#define PROVAI_H_INCLUDED

#define MAX_ALUNOS 1000
#define MAX_DISC_ESCOLA 1000
#define MAX_DISCIPLINAS 5
#define MAX_NOTAS 5

typedef
struct {
    float valor[MAX_NOTAS];
    float media;
} NOTA;

typedef
struct {
    char codigo[4];
    char descr[21];
} DISCIPLINA;

typedef
struct {
    char matric[7];
    char nome[31];
    float mediaGlobal;
    char codDisc[MAX_DISCIPLINAS][4];
    float medias[MAX_DISCIPLINAS];
} ALUNO;


#endif // PROVAI_H_INCLUDED
