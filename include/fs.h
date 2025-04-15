#ifndef FS_H
#define FS_H

#define MAX_FILES 100
#define MAX_FILENAME_LEN 32
#define MAX_CONTENT_LEN 256

typedef struct {
    char name[MAX_FILENAME_LEN];
    char content[MAX_CONTENT_LEN];
    int in_use; // 0: free, 1: occupied
} File;

typedef struct {
    File files[MAX_FILES];
} FileSystem;

// Function declarations
void init_fs(FileSystem* fs);
int create_file(FileSystem* fs, const char* name);
int delete_file(FileSystem* fs, const char* name);
int write_file(FileSystem* fs, const char* name, const char* content);
const char* read_file(FileSystem* fs, const char* name);
void list_files(FileSystem* fs);

#endif
