#include "file_reader.h"
#include <stdio.h>
#include <string.h>

file_reader_T* init_file_reader(const char* filepath)
{
    file_reader_T* file_reader = calloc(1, sizeof(struct FILE_READER_STRUCT));

    file_reader->filepath = filepath;
    FILE* file = fopen(filepath, "rb");

    if (file)
    {
        fseek(file, 0, SEEK_END);
        file_reader->lenght = ftell(file);
        fclose(file);
        return file_reader;
    }
    
    printf("File not found: %s\n", filepath);
    exit(1);
}

char* file_reader_get_contents(file_reader_T* file_reader)
{
    FILE* file = fopen(file_reader->filepath, "rb");
    char* buffer = calloc(file_reader->lenght, file_reader->lenght);
    fread(buffer, 1, file_reader->lenght, file);
    fclose(file);

    return buffer;
}

size_t file_reader_get_line_count(file_reader_T* file_reader)
{
    FILE* file = fopen(file_reader->filepath, "rb");
    size_t count = 0;

    for (char c = getc(file); c != EOF; c = getc(file))
    {
        if (c == '\n')
        {
            count++;
        }
    }
    count++;
    fclose(file);

    return count;
}

char** file_reader_get_lines_array(file_reader_T* file_reader)
{
    FILE* file = fopen(file_reader->filepath, "rb");
    char** lines_array = calloc(file_reader_get_line_count(file_reader), sizeof(char*));
    size_t current_line = 0;

    for (char c = getc(file); c != EOF; c = getc(file))
    {
        lines_array[current_line] = realloc(lines_array[current_line], sizeof(lines_array[current_line]) + sizeof(char));
        lines_array[current_line][strlen(lines_array[current_line])] = c;

        if (c == '\n')
        {
            current_line++;
        }
    }

    fclose(file);
    return lines_array;
}

char* file_reader_get_line(file_reader_T* file_reader, size_t line)
{
    if (line > file_reader_get_line_count(file_reader))
    {
        printf("Requested line: %ld, does not exist on file: %s", line, file_reader->filepath);
        exit(1);
    }

    return file_reader_get_lines_array(file_reader)[line];
}
