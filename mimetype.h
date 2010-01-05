#ifndef MIMETYPE_H_INCLUDED
#define MIMETYPE_H_INCLUDED

#define MNO_MEM            -3
#define MNO_FILE_EXTENSION -2
#define M_FAIL             -1
#define M_OK                0

extern int   mime_type(char *filename, char **outMimeType);
extern char* mime_get_file_extension(char *filename);

#endif // MIMETYPE_H_INCLUDED
