#include <stdio.h>

int main(void)
{
    /*
        printf() writes "hello" to the stdout buffer.
        It does NOT immediately write to the terminal.
    */
    printf("hello");

    /*
        At this point, "hello" is still inside stdout's buffer.

        Before scanf() starts reading input from stdin,
        most C runtime libraries (glibc, MSVC CRT, etc.)
        automatically flush all line-buffered output streams
        connected to the terminal.

        This automatic flush ensures that prompts such as

            printf("Enter age: ");

        become visible before the program waits for user input.

        Internally, the runtime performs something equivalent to

            fflush(stdout);

        (This behavior is implementation-defined but is present on
        almost all modern systems.)
    */
    int success;
    scanf("%d", &success);

    /*
        If scanf() returns successfully and main() returns,
        the C runtime again flushes all remaining buffered output
        before terminating the program.

        Therefore, stdout can be flushed in multiple situations:
            1. Buffer becomes full.
            2. A newline ('\n') is written to a line-buffered stream.
            3. fflush(stdout) is called explicitly.
            4. Before terminal input (common implementation behavior).
            5. Program exits normally (return from main or exit()).
    */

    return 0;
}