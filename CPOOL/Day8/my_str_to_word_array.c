/*
** EPITECH PROJECT, 2023
** my_str_to_word_array()
** File description:
** Convertes a string to an array of word
*/

struct WordInfo {
    int is_word;
    int counter;
} WordInfo;

static int is_alphanum(char c)
{
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
        return 1;
    else if (c >= 48 && c <= 57)
        return 1;
    else
        return 0;
}

int index_word_2(char *str, int i, struct WordInfo *wordInfo, int word)
{
    if (is_alphanum(str[i]) == 1) {
        if (wordInfo->is_word == 0) {
            wordInfo->is_word = 1;
            wordInfo->counter++;
        }
        if (wordInfo->counter == word)
            return i;
    } else {
        wordInfo->is_word = 0;
    }
    return -1;
}

static int index_word(char *str, int word)
{
    struct WordInfo wordInfo = {0, 0};
    int length = my_strlen(str);
    int i = 0;
    int result;

    while (i < length) {
        result = index_word_2(str, i, &wordInfo, word);
        if (result != -1)
            return result;
        i++;
    }
    return -1;
}

static void count_words_2(int *is_word, int *counter)
{
    if (*is_word == 0) {
        *is_word = 1;
        *counter = *counter + 1;
    }
}

int count_words(char *str)
{
    int counter = 0;
    int is_word = 0;
    int	length = my_strlen(str);
    int i = 0;

    while (i < length) {
        if (is_alphanum(str[i]) == 1)
            count_words_2(&is_word, &counter);
        else
            is_word = 0;
        i++;
    }
    return counter;
}

void count_word_letter_2(int *is_word, int *counter, int *letter, int word)
{
    if (*is_word == 0) {
        *is_word = 1;
        *counter = *counter + 1;
    }
    if (*counter == word)
        *letter = *letter + 1;
}

int count_word_letter(char *str, int word)
{
    int counter = 0;
    int is_word = 0;
    int letter = 0;
    int length = my_strlen(str);
    int i = 0;

    while (i < length) {
        if (is_alphanum(str[i]) == 1)
            count_word_letter_2(&is_word, &counter, &letter, word);
        else
            is_word = 0;
        i++;
    }
    return letter;
}

char **my_str_to_word_array(char const *str)
{
    int word_index;
    int word_size;
    char *strings;
    char **result = malloc(count_words(str) * sizeof(char *) + 1);
    int j = 0;

    for (int i = 0; i < count_words(str); i++) {
        word_index = index_word(str, i + 1);
        word_size = count_word_letter(str, i + 1);
        strings = malloc(word_size * sizeof(char) + 1);
        while (j < word_size) {
            strings[j] = str[word_index + j];
            j++;
        }
        j = 0;
        strings[word_size] = '\0';
        result[i] = strings;
    }
    result[count_words(str)] = '\0';
    return result;
}
