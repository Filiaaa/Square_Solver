#include "work.c"
#include "parsing.h"


const char* using_warning_string = "Using: -t (if you want to work with console) -i <input file>-o <output file>. If you want to work with console you shouldnt write file names.\n";

void Flag1Func(Flag *flag, Parser *parser)
{
    parser->work_with_console = 1;
}

void Flag2Func(Flag *flag, Parser *parser)
{

    parser -> file = fopen(flag->argument, "r");
}

void Flag3Func(Flag *flag, Parser *parser)
{
    parser -> result_file = fopen(flag->argument, "w");
}

void AnalyzeParser(Parser parser)
{
    if((parser.file != NULL || parser.result_file != NULL) && parser.work_with_console == 1)
    {
        printf("%s", using_warning_string);
        return;
    }


    if(parser.work_with_console == 1)
    {
        WorkWithConsole();
        return;
    }

    if(parser.file == NULL || parser.result_file == NULL)
    {
        printf("%s", using_warning_string);
        return;
    }
    WorkWithFile(parser.file, parser.result_file);
}

void Parsing(int argc, char* argv[])
{
    if(argc == 1)
    {
        WorkWithConsole();
        return;
    }
    Parser parser;
    Flag flag1 = {"-c", "-console", 0, NULL, Flag1Func};
    Flag flag2 = {"-i", "-input", 1, NULL, Flag2Func};
    Flag flag3 = {"-o", "-output", 1, NULL, Flag3Func};

    Flag flags[3] = {flag1, flag2, flag3};
    int flags_numb = 3;


    for(int i = 1; i < argc; i+=2)
    {
        int has_flag = 0;
        for(int j = 0; j < flags_numb; j++)
        {
             if(strcmp(argv[i], flags[j].short_version) == 0 || strcmp(argv[i], flags[j].long_version) == 0)
             {
                if(flags[j].arguments_numb > 0)
                {
                    flags[j].argument = argv[i + 1];
                }
                else
                {
                    i -= 1;
                }
                flags[j].function(&flags[j], &parser);
                has_flag = 1;
                break;
             }
        }
        if(has_flag == 0)
        {
            return;
        }
    }
    AnalyzeParser(parser);

}
