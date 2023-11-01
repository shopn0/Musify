#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    int choice;
    char title[50];
    char artist[70];
    int duration;

// Print the centered project name text
    int consoleWidth = 80;  // Adjust this value based on your console's width
    char text[] = "Musify"; // Text to be centered
    int len = strlen(text);
    int padding = (consoleWidth - len) / 2;
    // Print spaces for padding on the left
    for (int i = 0; i < padding; i++)
    {
        printf(" ");
    }
    printf("%s\n", text);
//Menu showcase
    printf("\nMenu: \n;");
    printf("\n1. Add a song to playlist\n");
    printf("2. Remove a song from the playlist\n");
    printf("3. Search for a song\n");
    printf("4. Number of songs in current playlist\n");
    printf("5. About\n");
    printf("6. Exit\n");

    


    return 0;
}