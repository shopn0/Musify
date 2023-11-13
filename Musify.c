#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 

struct Song
{
    char title[40];
    char artist[80];
    int duration;
    struct Song* next;
};

struct Song* playlist = NULL;

void insertSong(char title[], char artist[], int duration){
    struct Song* newSong=(struct Song*)malloc(sizeof(struct Song));
    strcpy(newSong->title, title);
    strcpy(newSong->artist, artist);
    newSong->duration = duration;
    newSong->next = NULL;

    
    if (playlist == NULL) {
        playlist = newSong;
    } else {
        
        struct Song* current = playlist;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newSong;
    }
    
}

void deleteSong(char title[]){
    struct Song* current = playlist;
    struct Song* prev = NULL;

    while (current!=NULL)
    {
        if (strcmp(current->title, title) == 0)
        {
            if (prev != NULL)
            {
                prev->next = current->next;
            }else
            {
                playlist = current->next;
            }
            free (current);
            printf("\nSong deleted from the playlist.\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Song not found in the playlist.\n");
}

void searchSong(char title[]){
    struct Song* current = playlist;
    while (current != NULL)
    {
        if (strcmp(current->title, title) == 0)
        {
            printf("\nSong found.\n\n");
            printf("Title: %s\n", current->title);
            printf("Artist: %s\n", current->artist);
            printf("Duration: %d seconds\n\n", current->duration);
            return;
        }
        current = current->next;
    }
    printf("\n\nSong not found in the playlist\n\n");
}

void disPlaylist(){
    int index = 1;
    int count = 0;
    struct Song* ptr = playlist;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    printf("\nTotal number of songs in the current playlist: %d\n", count);
    ptr = playlist; //conf.
    while (ptr != NULL)
    {
        printf("%d. %s\n", index, ptr->title);
        index++;
        ptr = ptr->next;
    }
}

void about(){
    printf("\nSoftware Version 1.0\nTeam SampleX\nAn open-source project 2023\n");
    printf("\n");
}

void savePlaylist() {
    FILE* file = fopen("playlist.txt", "w");
    if (file == NULL) {
        return;
    }
    struct Song* current = playlist;
    while (current != NULL)
    {
        fprintf(file, "%s;%s;%d\n", current->title, current->artist, current->duration);
        current = current->next;
    }
    fclose(file);
}

void loadPlaylist() {
    FILE* file = fopen("playlist.txt", "r");
    if (file == NULL) {
        return;
    }

    char title[40];
    char artist[80];
    int duration;

    while (fscanf(file, "%[^;];%[^;];%d\n", title, artist, &duration) == 3) {
        insertSong(title, artist, duration);
    }

    fclose(file);
}

void displayAsciiArt() {
    printf("\a"); // Beep sound
    usleep(300000); // Sleep for 300 milliseconds
    printf("\a"); // Beep sound

    // ASCII art lines
    const char lines[7][40] = {
        " ___ ___             __  ___       ",
        "|   Y   .--.--.-----|__.'  _.--.--.",
        "|.      |  |  |__ --|  |   _|  |  |",
        "|. \\_/  |_____|_____|__|__| |___  |",
        "|:  |   |                   |_____|",
        "|::.|:. |                          ",
        "`--- ---'                          ",
    };

    int consoleWidth = 80; 
    int artWidth = 40;    

    // Calculate padding for each line
    int padding = (consoleWidth - artWidth) / 2;

    // Print each line with padding
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < padding; j++) {
            printf(" ");
        }
        printf("%s\n", lines[i]);
        usleep(300000); // Sleep for 300 milliseconds between lines
    }
}

int main() {
    int choice;
    char title[100];
    char artist[100];
    int duration;

    loadPlaylist();
    displayAsciiArt();

    while (1) {
        
        // Menu showcase
        printf("\nMenu: \n");
        printf("\n1. Add a song to playlist\n");
        printf("2. Remove a song from the playlist\n");
        printf("3. Search for a song\n");
        printf("4. Display current playlist\n");
        printf("5. About\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: \n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\n-Enter song details-\n");
            printf("Title: \n");
            scanf("%s", &title);
            printf("Artist:\n");
            scanf("%s", &artist);
            printf("Duration (in seconds): \n");
            scanf("%d", &duration);
            insertSong(title, artist, duration);
            printf("\nSong added to playlist successfully.\n");
            break;

        case 2:
            printf("\n-Enter song name to delete-\n");
            scanf("%s", title);
            deleteSong(title);
            break;

        case 3:
            printf("\nEnter song name to search:\n");
            scanf("%s", &title);
            searchSong(title);
            break;

        case 4:
            disPlaylist();
            break;

        case 5:
            about();
            break;

        case 6:
            savePlaylist();
            exit(0);

        default:
            printf("\nInvalid Choice. Please try again.\n");
        }
    }

    return 0;
}
