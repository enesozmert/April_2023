#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **ft_split(char *str)
{
    int i;
    int k;
    int j;
    char **split;

    i = 0;
    k = 0;
    if (!(split = (char **)malloc(sizeof(char) * 256)))
        return (NULL);
    while (str[i] <= 32)
        i++;
    while (str[i])
    {
        j = 0;
        if (!(split[k] = (char *)malloc(sizeof(char) * 4096)))
            return (NULL);
        while (str[i] > 32 && str[i])
            split[k][j++] = str[i++];
        while (str[i] <= 32 && str[i])
            i++;
        split[k][j] = '\0';
        k++;
    }
    split[k] = NULL;
    return (split);
}

void print_frame_start_end(int index, int query, int max_len)
{
    if (index == query)
    {
        for (int i = 0; i < max_len + 4; i++)
            printf("*");
        printf("\n");
    }
}

void print_frame(int index, int size, int max_len, char *str)
{
    int len = strlen(str);

    print_frame_start_end(index, 0, max_len);
    printf("* ");
    printf("%s", str);
    while (len++ < max_len)
        printf(" ");
    printf(" *\n");
    print_frame_start_end(index, size - 1, max_len);
}

int max_word_len(char **lines)
{
    int i = -1;
    static unsigned int max = 0;
    static unsigned int tmp_max = 0;
    while (lines[++i])
    {
        tmp_max = strlen(lines[i]);
        if (tmp_max > max)
            max = tmp_max;
    }
    return (max);
}

int main(int argc, char **argv)
{
    if (argc == 1)
        return 0;
    int i = -1;
    int j = 0;
    char **lines = NULL;
    unsigned int max_len;
    unsigned int size;
    unsigned int arg_size;

    size = 0;
    max_len = 0;
    arg_size = 0;
    while (argv[++j])
    {
        i = -1;
        lines = ft_split(argv[j]);
        max_len = max_word_len(lines);
        while (lines[++i])
            ;
        size += i;
    }
    j = 0;
    while (argv[++j])
    {
        i = -1;
        lines = ft_split(argv[j]);
        while (lines[++i])
            print_frame(arg_size++, size, max_len, lines[i]);
    }

    return 0;
}