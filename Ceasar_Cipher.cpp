#include <stdlib.h>
#include <stdio.h>

//Dich chuyen 1 ky tu qua ben phai
int rotate_right(int ch)
{
    if (ch == 'z')
        return 'a';
    if (ch == 'Z')
        return 'A';
    ch++;
    return ch;
}

//Dich chuyen 1 ky tu qua ben trai
int rotate_left(int ch)
{
    if (ch == 'a')
        return 'z';
    if (ch == 'A')
        return 'Z';
    ch--;
    return ch;
}

//Dich chuyen nhieu ky tu qua con so ASCII
int encode(int ch, int shift)
{
    if (shift == 0)
        return ch;
    else if (shift > 0)
    {
        for (int i = 1; i <= shift; i++)
        {
            ch = rotate_right(ch);
        }
        return ch;
    }
    else
    {
        for (int i = 1; i <= -shift; i++)
        {
            ch = rotate_left(ch);
        }
        return ch;
    }
}

int main()
{
    char letter[100];
    int shift, ch, i;
    int check = 1;

    while (check == 1)
    {
        system("clear");
        printf("Nhap ky tu can ma hoa:\n");
        fflush(stdin);
        fgets(letter, sizeof(letter), stdin);

        printf("Nhap so dich chuyen:\n");
        scanf("%d", &shift);

        for (i = 0; letter[i] != '\0'; i++)
        {
            if (letter[i] >= 'a' && letter[i] <= 'z')
            {
                letter[i] = encode(letter[i], shift);
            }
            if (letter[i] >= 'A' && letter[i] <= 'Z')
            {
                letter[i] = encode(letter[i], shift);
            }
        }

        printf("\n%s\n", letter);

        printf("Continue? (1: Yes / 2: No):");
        scanf("%d", &check);
    }

    return 0;
}