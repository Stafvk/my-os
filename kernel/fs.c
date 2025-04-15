#include "../include/fs.h"
#include "../include/print.h" // For displaying messages

void init_fs(FileSystem* fs) {
    for (int i = 0; i < MAX_FILES; i++) {
        fs->files[i].in_use = 0;
    }
}

int create_file(FileSystem* fs, const char* name) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (!fs->files[i].in_use) {
            fs->files[i].in_use = 1;
            strcpy(fs->files[i].name, name);
            fs->files[i].content[0] = '\0'; // Empty content
            return 1; // Success
        }
    }
    return 0; // No space available
}

int delete_file(FileSystem* fs, const char* name) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (fs->files[i].in_use && strcmp(fs->files[i].name, name) == 0) {
            fs->files[i].in_use = 0;
            return 1; // Success
        }
    }
    return 0; // File not found
}

int write_file(FileSystem* fs, const char* name, const char* content) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (fs->files[i].in_use && strcmp(fs->files[i].name, name) == 0) {
            strncpy(fs->files[i].content, content, MAX_CONTENT_LEN);
            return 1; // Success
        }
    }
    return 0; // File not found
}

const char* read_file(FileSystem* fs, const char* name) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (fs->files[i].in_use && strcmp(fs->files[i].name, name) == 0) {
            return fs->files[i].content;
        }
    }
    return NULL; // File not found
}

void list_files(FileSystem* fs) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (fs->files[i].in_use) {
            print(fs->files[i].name);
            print("\n");
        }
    }
}
