#include <stdio.h>


struct Parser
{
    int work_with_console;
    FILE* file;
    FILE* result_file;
};

struct Flag
{
    const char *short_version;
    const char *long_version;
    int arguments_numb;
    char *argument;
    void (*function)(Flag *flag, Parser *parser);
};
