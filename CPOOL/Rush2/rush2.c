/*
** EPITECH PROJECT, 2023
** step3.c
** File description:
** Calculates the percentage of occurences
*/

float alphabet_frequency[26][4] = {
    {8.17, 7.64, 6.52, 11.53},
    {1.49, 0.9, 1.89, 2.22},
    {2.78, 3.26, 2.73, 4.02},
    {4.25, 3.67, 5.08, 5.01},
    {12.72, 14.71, 16.40, 12.18},
    {2.23, 1.07, 1.67, 0.69},
    {2.01, 0.87, 3.01, 1.77},
    {6.09, 0.74, 4.58, 0.70},
    {6.97, 7.53, 6.55, 6.25},
    {0.15, 0.61, 0.27, 0.49},
    {0.77, 0.07, 1.42, 0.01},
    {4.02, 5.46, 3.44, 4.97},
    {2.41, 2.97, 2.53, 3.16},
    {6.75, 7.09, 9.78, 6.71},
    {7.51, 5.80, 2.59, 8.68},
    {1.93, 2.52, 0.67, 2.51},
    {0.09, 1.36, 0.02, 0.88},
    {5.99, 6.69, 7.00, 6.87},
    {6.33, 7.94, 7.27, 7.98},
    {9.06, 7.24, 6.15, 4.63},
    {2.76, 6.31, 4.17, 2.93},
    {0.98, 1.84, 0.85, 1.14},
    {2.36, 0.05, 1.92, 0.02},
    {0.15, 0.43, 0.03, 0.21},
    {1.97, 0.13, 0.04, 1.01},
    {0.07, 0.33, 1.13, 0.47}
};

static int ignore_character(char *sentence, int sentence_len)
{
    int counter = 0;

    for (int i = 0; i < sentence_len; i++) {
        if (sentence[i] >= 97 && sentence[i] <= 122)
            counter++;
    }
    return counter;
}

float calculate_percentage(char *sentence, int counter, int sentence_len)
{
    return ((float)counter / ignore_character(sentence, sentence_len)) * 100;
}

static char lowcase_character(char character)
{
    if (character >= 65 && character <= 90)
        character += 32;
    return character;
}

static void counter_increment(char **argv, int i, int j, int *counter)
{
    if (argv[1][i] == lowcase_character(argv[j][0]))
        (*counter)++;
}

void print_all(char **argv, int j, int counter, int sentence_len)
{
    my_putchar(argv[j][0]);
    my_putchar(':');
    my_put_nbr(counter);
    my_putchar(' ');
    my_putchar('(');
    my_put_float(calculate_percentage(argv[1], counter, sentence_len));
    my_putchar('%');
    my_putchar(')');
    my_putchar('\n');
}

static void print_language(int language_index)
{
    switch (language_index) {
        case 0:
            my_putstr("=> English\n");
            break;
        case 1:
            my_putstr("=> French\n");
            break;
        case 2:
            my_putstr("=> German\n");
            break;
        case 3:
            my_putstr("=> Spanish\n");
            break;
        default:
            write(2, "Unknown", 5);
            break;
    }
}

static void interval_check(float *interval)
{
    if (*interval < 0)
        *interval = -(*interval);
}

int multiple_characters_occurences(int argc, char **argv, float *frequency)
{
    int sentence_len = my_strlen(argv[1]);
    int counter = 0;
    int index;

    if (sentence_len <= 0) {
        write(2, "NEED A STRING", 13);
        return 84;
    }
    my_strlowcase(argv[1]);
    for (int i = 0; i < sentence_len; i++) {
            index = argv[1][i] - 'a';
            frequency[index] += 1.0;
    }
    for (int j = 2; j < argc; j++) {
        for (int i = 0; i < sentence_len; i++)
            counter_increment(argv, i, j, &counter);
        print_all(argv, j, counter, sentence_len);
        counter = 0;
    }
    return 0;
}

void normalize_frequency(int argc, char **argv)
{
    int language_index = 0;
    float interval;
    float language_count[4] = {0, 0, 0, 0};
    float frequency[26] = {0.0};

    if (multiple_characters_occurences(argc, argv, frequency) > 0)
        return;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 4; j++) {
            interval = frequency[i] - alphabet_frequency[i][j];
            interval_check(&interval);
            language_count[j] += interval;
        }
    }
    for (int i = 1; i < 4; i++) {
        if (language_count[language_index] > language_count[i])
            language_index = i;
    }
    print_language(language_index);
}

int main(int argc, char **argv)
{
    if (argc > 1)
        normalize_frequency(argc, argv);
    else {
        write(2, "NEED MORE ARGUMENT", 18);
        return 84;
    }
    return 0;
}
