#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

static char buffer[50];
static int int_buffer;

/* Test for simple output functions */
static void simple_out(void) {
    const char one_by_one[] = "short msg";
    for (int i = 0; i < strlen(one_by_one); i++) {
        putchar(one_by_one[i]);
        putchar('\n');
    }
    puts("Print a simple string");
    fputs("This string is printed to stdout\n", stdout);
    fprintf(stdout, "This formatted string is printed to %s\n", "stdout");
    printf("This formatted string is printed using %s\n", "printf()");
}

/* Test for simple input functions */
static void simple_in(void) {
    puts("Please input a character:");
    fprintf(stdout, "Your input is a '%c'\n", getchar());
    getchar();
    puts("Please input a string:");
    fgets(buffer, 20, stdin); 
    fprintf(stdout, "The input string using fgets is %s\n", buffer);
    puts("Please input a string:");
    scanf("%s", buffer);
    fprintf(stdout, "The input string using scanf() is %s\n", buffer);
    puts("Please input an int:");
    scanf("%d", &int_buffer);
    fprintf(stdout, "The input integer using scanf() is %d\n", int_buffer);
}

int main(int argc, char **argv) {
    int i = 0;
    simple_out(); 
    simple_in();
    return 0;
}
