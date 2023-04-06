#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void black_jack(char *cards)
{
    int len = strlen(cards);
    int hand = 0;
    int i = 0;
    while(i < len)
    {
        if (cards[i] >= '3' && cards[i] <= '9')
        {
            hand += cards[i] - 48;
            
        }
        else if (cards[i] == 'A' && hand + 11 == 21)
            hand += 11;
        else if (cards[i] == 'A')
            hand += 1;
        else
            hand += 10;
        if (hand == 21)
        {
            printf("Blackjack!\n");
            return ;
        }
        else if (hand >= 22)
        {
            printf("%d\n", hand);
            return ;
        }
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac == 2)
        black_jack(av[1]);
    else
        printf("wrong argument\n");
}