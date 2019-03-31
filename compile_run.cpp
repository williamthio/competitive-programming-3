#include <iostream>
#include <unistd.h>
#include <limits.h>
#include <cstring>
#include <cstdio>
#include <sys/stat.h>

using namespace std;

int main(int argc, char** argv) {
    const char *kDirPath = "~/outputs";

    if (argc == 1) {
        cout << "File name required.\n";
        return 0;
    }

    char cwd[PATH_MAX];
    getcwd(cwd, sizeof(cwd));

    char filename[PATH_MAX];
    sprintf(filename, "%s/%s", cwd, argv[1]);

    struct stat fbuffer;
    if (stat(filename, &fbuffer) != 0) {
        cout << "File not exist.\n";
        return 0;
    }

    char *dot = strrchr(filename, '.');
    if (!dot) {
        cout << "Invalid file type.\n";
        return 0;
    }

    char cmd[PATH_MAX * 3 + 50];

    if (!strcmp(dot, ".cpp")) {
        sprintf(cmd, "g++ -o \"%s\"/bin \"%s\"", kDirPath, filename);
        system(cmd);
        sprintf(cmd, "\"%s\"/bin < \"%s\"/input.txt > \"%s\"/output.txt", kDirPath, kDirPath, kDirPath);
        system(cmd);
        sprintf(cmd, "rm \"%s\"/bin", kDirPath);
        system(cmd);
    }
    else if (!strcmp(dot, ".java")) {
        sprintf(cmd, "javac -d \"%s\" \"%s\"", kDirPath, filename);
        system(cmd);
        sprintf(cmd, "java -cp \"%s\" Main < \"%s\"/input.txt > \"%s\"/output.txt", kDirPath, kDirPath, kDirPath);
        system(cmd);
        sprintf(cmd, "rm \"%s\"/Main.class", kDirPath);
        system(cmd);
    }
    else {
        cout << "Unrecognized file type.\n";
    }

    sprintf(cmd, "cp \"%s\" \"%s\"/code.txt", filename, kDirPath);
    system(cmd);
    sprintf(cmd, "cat \"%s\"/code.txt", kDirPath);
    system(cmd);

    return 0;
}

