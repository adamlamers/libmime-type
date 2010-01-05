/* This library determines the Mime-Type of a file based on it's file extension. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mimetype.h"
#include "mime_extensions.h"
#include "mime_types.h"


int mime_type(char *filename, char **outMimeType)
{
    int i;
    char *file_ext = mime_get_file_extension(filename);
    if(file_ext == NULL) return MNO_FILE_EXTENSION;
    
    for(i = 0; i < MNUM_MIME_EXTENSIONS; i++)
    {
        if(strcmp(file_ext, mime_extensions[i]) == 0)
        { 
            *outMimeType = (char*)malloc(strlen(mime_types[i]));
            if(*outMimeType == NULL) return MNO_MEM;
            strcpy(*outMimeType, mime_types[i]);
            return M_OK;
        }
    }
    
    return M_FAIL;
}

/**
  * @param filename A string of the basename of a filename to retrieve the extension of.
  * @return Pointer to a string containing the file extension. (test.txt would return txt)
  */
char* mime_get_file_extension(char *filename)
{
    int i;
    int start_substr = 0;
    int filename_length = strlen(filename);
    
    for(i=0;i<filename_length;i++)
    {
        if(filename[i] == '.') start_substr = i + 1;
    }
    
    //If no file extension is found, return NULL
    if(start_substr == 0) return NULL;
    char *file_ext = (char*)malloc(filename_length - start_substr);
    if(file_ext == NULL) return NULL; //Not enough memory.
    strcpy(file_ext, filename + start_substr);
    
    return file_ext;
}
