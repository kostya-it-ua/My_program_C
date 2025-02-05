#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

const char *const AllowedFlags[] = {"-h", "--help", "-v", "--version", "-a", "--all", "-l", "--list", "-s", "--search", "-c", "--create", "-d", "--delete", "-u", "--update", "-r", "--read"};
const int const AllowedFlagsLength = sizeof(AllowedFlags) / sizeof(AllowedFlags[0]);

void validateFlags(const char *const flags[], const int const length)
{
    bool flagExists = false;
    printf("Validating flags:\n");
    for (int i = 1; i < length; i++) // Начинаем с 1, чтобы пропустить имя исполняемого файла
    {
        printf("Flag %d: %s\n", i, flags[i]);
        flagExists = false;
        for (int j = 0; j < AllowedFlagsLength; j++)
        {
            if (strcmp(flags[i], AllowedFlags[j]) == 0)
            {
                flagExists = true;
                break;
            }
        }
        if (flagExists)
        {
            printf("[+] Arg %d is allowed!\n", i);
        }
        else
        {
            printf("[-] Error: Incorrect flag was given at position %d: %s\n", i, flags[i]);
            exit(EXIT_FAILURE);
        }
    }
}

int main(int const args, const char *const argv[])
{
    if (args > 1) {
        printf("Number of arguments: %d\n", args - 1); // Вычитаем 1, чтобы не учитывать имя исполняемого файла
        validateFlags(argv, args);
    }

    return EXIT_SUCCESS;
}