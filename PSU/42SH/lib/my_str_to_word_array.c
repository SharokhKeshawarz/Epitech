/*
** EPITECH PROJECT, 2023
** sum_numbers()
** File description:
** Sum all the numbers of the arguments
*/

#include <stdlib.h>

int est_separateur(char c, const char *separateurs)
{
    while (*separateurs != '\0') {
        if (c == *separateurs)
            return 1;
        separateurs++;
    }
    return 0;
}

static void compter_mots_2(int *compte, int *dans_mot)
{
    if (!(*dans_mot)) {
        (*dans_mot) = 1;
        (*compte)++;
    }
}

int compter_mots(const char *chaine, const char *separateurs)
{
    int compte = 0;
    int dans_mot = 0;

    while (*chaine != '\0') {
        if (!est_separateur(*chaine, separateurs))
            compter_mots_2(&compte, &dans_mot);
        else
            dans_mot = 0;
        chaine++;
    }
    return compte;
}

static void mstwa_4(char **mots, int *i, int l, int dans_mot)
{
    if (dans_mot) {
        mots[(*i)][l] = '\0';
        (*i)++;
    }
}

static void mstwa_3(char **mots, int *i, int l, int *dans_mot)
{
    if ((*dans_mot)) {
        mots[(*i)][l] = '\0';
        (*i)++;
        (*dans_mot) = 0;
    }
}

static void mstwa_2(char **mots, int i, int *l, int *dans_mot)
{
    if (!(*dans_mot)) {
        (*dans_mot) = 1;
        mots[i] = (char *)malloc(64 * sizeof(char));
        if (mots[i] == NULL)
            return;
        (*l) = 0;
    }
}

char **my_str_to_word_array(const char *chaine, const char *separateurs)
{
    int nb_mots = compter_mots(chaine, separateurs);
    char **mots = (char **)malloc((nb_mots + 1) * sizeof(char *));
    int index_mot = 0;
    int longueur_mot = 0;
    int dans_mot = 0;

    while (*chaine != '\0') {
        if (!est_separateur(*chaine, separateurs)) {
            mstwa_2(mots, index_mot, &longueur_mot, &dans_mot);
            mots[index_mot][longueur_mot] = *chaine;
            longueur_mot++;
        } else
            mstwa_3(mots, &index_mot, longueur_mot, &dans_mot);
        chaine++;
    }
    mstwa_4(mots, &index_mot, longueur_mot, dans_mot);
    mots[index_mot] = NULL;
    return mots;
}
