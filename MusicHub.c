#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song
{
    char title[40];
    char artist[80];
    int duration;

    struct Song* next;
};

struct Song* playlist = NULL; // conf.1

void insertSong(char title[], char artist[], int duration){
    struct Song* newSong=(struct Song*)malloc(sizeof(struct Song));
    strcpy(newSong->title, title);
    strcpy(newSong->artist, artist);
    newSong->duration = duration;
    newSong->next = playlist;
    playlist = newSong;
    printf("\nSong added to the playlist successfully.\n\n");
    
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
            } else
            {
                playlist = current->next;
            }
            free (current);   
            printf("\nSong deleted from the playlist.\n\n");
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
            printf("\nSong found:\n\n");
            printf("Title: %s\n", current->title);
            printf("Artist: %s\n", current->artist);
            printf("Duration: %d seconds\n", current->duration);
            return;
        }
        current = current->next;
    }
    printf("\nSong not found in the playlist\n\n");
}
void disPlaylist(){}
void about(){
    printf("\nTeam SampleX\nAn open source project 2023.");
    return;
}
int main()
{

    int choice;
    char title[100];
    char artist[100];
    int duration;

    while(1)
    {
    int consoleWidth = 40;  
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
            printf("Titile: \n");
            scanf("%s", &title);
            printf("Artist:\n");
            scanf("%s", &artist);
            printf("Duration (in seconds): \n");
            scanf("%d", &duration);
            insertSong(title, artist, duration);


            break;
        case 2:
            printf("Enter song name to delete:\n");
            scanf("%s",title);
            deleteSong(title);
            
            break;
        
        case 3:
            printf("Enter song name to search:\n");
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
    return 0;
}