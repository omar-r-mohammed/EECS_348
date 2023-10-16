#include <stdio.h>

int main()
{
    int td = 6;
    int fg = 3;
    int sf = 2;
    int tdn2 = 8;
    int tdn1 = 7;
    int user_in;
    printf("Enter 0 or 1 to STOP\n");
    while (1) {
        printf("Enter the NFL score: ");
        scanf("%d", &user_in);
        if (user_in <= 1)
        {
            break;
        } else {
            printf(" \n");
            printf("possible combinations of scoring plays: \n");
            int score;
            for (int tdn2 = 0; tdn2 * 8 <= user_in; tdn2++)
            {
                for (int tdn1 = 0; tdn1 * 7 <= user_in; tdn1++)
                {
                    for (int td = 0; td * 6 <= user_in; td++)
                    {
                        for (int fg = 0; fg * 3 <= user_in; fg++)
                        {
                            for (int sf = 0; sf * 2 <= user_in; sf++)
                            {
                                score = (tdn2 * 8) + (tdn1 * 7) + (td * 6) + (fg * 3) + (sf * 2);
                                if (user_in == score)
                                {
                                    printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d sf\n", tdn2, tdn1, td, fg, sf);
                                }
                            }
                        }
                    }
                }
            }
            printf(" \n");
        }
    }
    return 0;
}
