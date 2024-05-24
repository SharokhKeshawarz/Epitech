/*
** EPITECH PROJECT, 2023
** Str_to_word_array
** File description:
** Converts a string into an array of words
*/

#include "../../include/my.h"

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

static words_t *init(const char *chaine, const char *separateur)
{
    words_t *words = malloc(sizeof(words_t));

    words->nb_mots = compter_mots(chaine, separateur);
    words->mots = malloc((words->nb_mots + 1) * sizeof(char *));
    words->dans_mot = 0;
    words->in_quotes = 0;
    words->len = 0;
    words->index_mot = 0;
    return words;
}

char **my_str_to_word_array(const char *chaine, const char *separateurs)
{
    words_t *wor = init(chaine, separateurs);

    while (*chaine != '\0') {
        if (*chaine == '"') {
            wor->in_quotes = !wor->in_quotes;
            chaine++;
            continue;
        }
        if (!est_separateur(*chaine, separateurs) || wor->in_quotes) {
            mstwa_2(wor->mots, wor->index_mot, &wor->len, &wor->dans_mot);
            wor->mots[wor->index_mot][wor->len] = *chaine;
            wor->len++;
        } else
            mstwa_3(wor->mots, &wor->index_mot, wor->len, &wor->dans_mot);
        chaine++;
    }
    mstwa_4(wor->mots, &wor->index_mot, wor->len, wor->dans_mot);
    wor->mots[wor->index_mot] = NULL;
    return wor->mots;
}
