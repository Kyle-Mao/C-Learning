// C Program by Kyle. 20231026 18:07
// v3 滚动加密算法，大大提高安全性！
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#define LENGTH 1000
#define PLENGTH 50

int main()
{
    int choice, len, plen, i = 0, j = 0;
    char str[LENGTH] = {};
    char pw[PLENGTH] = {};
    printf("1-Encode\n");
    printf("2-Decode\n");
    printf("Type your choice: ");
option:
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        goto encode;
        break;
    case 2:
        goto decode;
        break;
    default:
        printf("Invalid. Type again:");
        fflush(stdin);
        goto option;
    }

encode:
    printf("Input your text to be encoded:\n");
    fflush(stdin);
    // scanf("%s", &str);
    fgets(str, LENGTH, stdin);

    // scanf("%[^\n]",&str);
    printf("\nInput your password: \n");
    fgets(pw, PLENGTH, stdin);
    len = strlen(str);
    plen = strlen(pw) - 1;
    // pw = raw % 128;

    char encode[LENGTH] = {};
    printf("\nPlease copy your result: \n");

    for (int i = 0; i < len; i++)
    {
        encode[i] = str[i] ^ pw[j];
        // printf("%x", encode[i]);

        if (encode[i] < 16)
        {
            printf("%d", 0);

            if (encode[i] == 0)
            {
                printf("%d", 0);
            }
            else
            {
                printf("%x", encode[i]);
            }
        }
        else
        {
            printf("%x", encode[i]);
        }

        j++;
        if (j == plen)
        {
            j = 0;
        }
    }
    printf("\n");
    scanf("%d", &choice);
    exit(0);

decode:

    char str2[LENGTH][2] = {};
    char format[LENGTH][3] = {};
    char decode[LENGTH] = {};
    printf("Input your text to be decoded:\n");
    scanf("%s", &str2);
    printf("\nInput your password: \n");

    fflush(stdin);
    fgets(pw, PLENGTH, stdin);

    len = strlen(str2);
    plen = strlen(pw) - 1;
    printf("\nPlease copy your result: \n");
    for (int i = 0; i < len / 2; i++)
    {
        format[i][0] = str2[i][0];
        format[i][1] = str2[i][1];

        char *str = format[i];
        char *endptr;
        long int hex_value;

        // 使用 strtol 函数将字符串转换为整数，基数为 16（十六进制）
        hex_value = strtol(str, &endptr, 16);

        decode[i] = hex_value ^ pw[j];
        j++;
        if (j == plen)
        {
            j = 0;
        }
    }
    printf("%s", decode);
    printf("\n");
    scanf("%d", &choice);
    exit(0);
}