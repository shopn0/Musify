#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song
{
    char title[50];
    char artist[70];
    int duration;

    struct Song* next;
};

struct Song* playlist = NULL; // conf.1

void insertSong(char title[], char artist[], int duration){
    struct Song* newSong=(struct Song*)malloc(sizeof(struct Song));
    strcpy(newSong->title, title);
    strcpy(newSong->artist, artist);
    newSong->duration = duration;
    newSong->next = newSong;
    printf("Song added to the playlist successfully.\n");
}

void deleteSong(){}
void searchSong(){}
void disPlaylist(){}
void about(){}
int main()
{

    int choice;
    char title[50];
    char artist[70];
    int duration;

    int consoleWidth = 80;  
    char text[] = "Musify"; 
    int len = strlen(text);
    int padding = (consoleWidth - len) / 2;
    
    for (int i = 0; i < padding; i++)
    {
        printf(" ");
    }
    printf("%s\n", text);
//Menu showcase
    printf("\nMenu: \n");
    printf("\n1. Add a song to playlist\n");
    printf("2. Remove a song from the playlist\n");
    printf("3. Search for a song\n");
    printf("4. Display current playlist\n");
    printf("5. About\n");
    printf("6. Exit\n");
    
    printf("Enter your choice: \n");
    scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter song details:\n");
            printf("Titile\n");
            scanf("%s", &title);
            printf("Artist\n");
            scanf("%s", &artist);
            printf("Duration (in seconds): \n");
            scanf("%d", &duration);
            insertSong(title, artist, duration);


            break;
        case 2:
            printf("Remove a song from the playlist\n");
            scanf("%s",title);
            deleteSong(title);
            
            break;
        
        case 3:
            printf("Search for a song\n");
            scanf("%s",&title);
            searchSong(title);
            
            break;
        case 4:
            disPlaylist();

            break;
        case 5:
            about();
            
            break;
        case 6: 
            exit(0);
                    
        default:
            printf("Invalid Choice. Please try again.\n");
        }
}