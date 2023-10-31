// C Program by Kyle. 20231026 16:55
// v2 提高加密安全性
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#define LENGTH 1000

int main()
{
    int choice, raw, pw, pw2, len, skip;
    char str[LENGTH] = {};
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
    scanf("%d", &raw);

    len = strlen(str);
    pw = raw % 128;
    pw2 = (raw + 1000) / 7 % 128;
    skip = raw % 3+2;

    char encode[LENGTH] = {};
    printf("\nPlease copy your result: \n");
    for (int i = 0; i < len; i++)      //第一次加密
    {
        encode[i] = str[i] ^ pw;
    }

    for (int j = 0; j < len; j += skip)    //第二次加密
    {
        encode[j] = encode[j] ^ pw2;
    }

    for (int i = 0; i < len; i++)   //输出：注意第一位是0的情况
    {
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
    }

    printf("\n");
    scanf("%d", choice);
    exit(0);

decode:

    char str2[LENGTH][2] = {};
    char format[LENGTH][3] = {};
    char pretext[LENGTH] = {};
    char decode[LENGTH] = {};
    printf("Input your text to be decoded:\n");
    scanf("%s", &str2);
    printf("\nInput your password: \n");
    scanf("%d", &raw);

    len = strlen(str2);
    pw = raw % 128;
    pw2 = (raw + 1000) / 7 % 128;
    skip = raw % 3+2;

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

        pretext[i] = hex_value;

        decode[i] = hex_value ^ pw;
    }

    for (int j = 0; j < len; j += skip)
    {
        decode[j] = decode[j] ^ pw2;
    }

    printf("%s", decode);
    printf("\n");
    scanf("%d", choice);
    exit(0);
}