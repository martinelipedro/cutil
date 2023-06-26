#ifndef FILE_FILEREADER_H
#define FILE_FILEREADER_H

#include <stdlib.h>

typedef struct FILE_READER_STRUCT
{
    const char* filepath;
    long lenght;

} file_reader_T;

file_reader_T* init_file_reader(const char* filepath);

char* file_reader_get_contents(file_reader_T* file_reader);
size_t file_reader_get_line_count(file_reader_T* file_reader);
char** file_reader_get_lines_array(file_reader_T* file_reader);
char* file_reader_get_line(file_reader_T* file_reader, size_t line);

#endif