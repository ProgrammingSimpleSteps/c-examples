#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void renameFilesInFolder(const char *folderPath) {
    DIR *dir = opendir(folderPath);
    if (dir == NULL) {
        perror("Error opening folder");
        exit(EXIT_FAILURE);
    }

    struct dirent *entry;
    int count = 0;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Regular file
            count++;
            char oldPath[256];
            char newPath[256];
            char *extension = strrchr(entry->d_name, '.'); // Get file extension

            snprintf(oldPath, sizeof(oldPath), "%s/%s", folderPath, entry->d_name);

            if (extension) {
                snprintf(newPath, sizeof(newPath), "%s/f-%02d%s", folderPath, count, extension);
            } else {
                snprintf(newPath, sizeof(newPath), "%s/f-%02d", folderPath, count);
            }

            if (rename(oldPath, newPath) != 0) {
                perror("Error renaming file");
                exit(EXIT_FAILURE);
            }
            printf("Renamed: %s -> %s\n", oldPath, newPath);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <folder_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *folderPath = argv[1];
    renameFilesInFolder(folderPath);

    return EXIT_SUCCESS;
}

/*int main() {
    char currentPath[256];

    if (getcwd(currentPath, sizeof(currentPath)) == NULL) {
        perror("Error getting current working directory");
        return EXIT_FAILURE;
    }

    renameFilesInFolder(currentPath);

    return EXIT_SUCCESS;
}*/
