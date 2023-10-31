// C Program by Kyle. 20231025 8:47
// v1.2 中文支持
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <locale.h>
#define Length 15

int main()
{
    setlocale(LC_ALL, "");

    int choice, raw, pw, len;
    wchar_t str[Length] = {};
    // system("chcp 65001");
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
        goto option;
    }

encode:
    printf("Input your text to be encoded:\n");
    fflush(stdin);
    // scanf("%s", &str);
    fgetws(str, Length, stdin);
    // scanf("%[^\n]",&str);
    printf("\nInput your password: \n");
    scanf("%d", &raw);

    len = wcslen(str)*2;
    pw = raw % 255;

    wchar_t encode[Length] = {};
    // printf("%s", str);
    // printf("%d", pw);
    printf("\nPlease copy your result: \n");
    for (int i = 0; i < len; i++)
    {
        // printf("%x\n", str[i]);
        encode[i] = str[i] ^ pw;
        // printf("%x\n", encode[i]);
        printf("%x", encode[i]);
    }
    printf("\n");

    // scanf("%d", choice);
    // exit(0);

decode:

    char str2[Length][2] = {};
    char format[Length][3] = {};
    // wchar_t pretext[Length] = {};
    wchar_t decode[Length] = {};
    printf("Input your text to be decoded:\n");
    scanf("%s", &str2);
    printf("\nInput your password: \n");
    scanf("%d", &raw);

    len = wcslen(str2)*2;
    pw = raw % 255;

    printf("\nPlease copy your result: \n");
    for (int i = 0; i < len / 2; i++)
    {
        format[i][0] = str2[i][0];
        format[i][1] = str2[i][1];
        // format[i][2] = "\0";
        // char str2[i][2] = "\0";
        // printf("%.2s\n", format[i]);

        // printf("%s\n", format[i]);

        // sscanf(string, "%x", &data);
        // decode[i] = str2[i] ^ pw;
        char *str = format[i];
        char *endptr;
        long int hex_value;

        // 使用 strtol 函数将字符串转换为整数，基数为 16（十六进制）
        hex_value = strtol(str, &endptr, 16);
        // if (errno == ERANGE || *endptr != '\0')
        // {
        //     printf("转换失败\n");
        //     return 1;
        // }

        // printf("十六进制整数：%ld\n", hex_value);
        // pretext[i] = hex_value;
        decode[i] = hex_value ^ pw;
    }
    wprintf(L"%s", decode);
    printf("\n");
    scanf("%d", choice);
    exit(0);
}