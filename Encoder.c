// C Program by Kyle. 2023102 14:31
// v1.4 解决功能选择输入无效值时循环报错问题    解决16进制输出第一位是0的问题
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#define LENGTH 1000

int main()
{
    int choice, raw, pw, len;
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

    char encode[LENGTH] = {};
    printf("\nPlease copy your result: \n");
    for (int i = 0; i < len; i++)
    {

        encode[i] = str[i] ^ pw;
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
    printf("%s", decode);
    printf("\n");
    scanf("%d", choice);
    exit(0);
}