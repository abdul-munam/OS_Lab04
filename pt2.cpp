#include <stdio.h>
#include <sys/stat.h>

int main()
{
    struct stat st;
    const char *file = "LAB04_TWO";
    stat(file, &st);

    // Display stats
    printf("File name: %s\n", file);
    printf("Size: %ld\n", st.st_size);
}
