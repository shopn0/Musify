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
void disPlaylist(){
    int index = 1;
    int count = 0;
    struct Song* ptr = playlist;
    while (ptr!=NULL)
    {
        count++;
        ptr = ptr->next;
    }
    printf("\nTotal number of songs in current playlist: %d\n",count);
ptr = playlist; //conf.
    while (ptr!=NULL)
    {
        printf("\n %d no. song: %s\n\n",index, ptr->title);
        index++;
        ptr = ptr->next;
    }
    
}

void about(){
    printf("\nTeam SampleX\nAn open source project 2023.\n");
    return;
}

void savePlaylist() {
    FILE* file = fopen("playlist.txt", "w");
    if (file == NULL) {
        printf("Error opening the file for saving data.\n");
        return;
    }
    struct Song* current = playlist;
    while (current!= NULL)
    {
        fprintf(file, "%s;%s;%d\n", current->title, current->artist, current->duration);
        current = current->next;
    }
    fclose(file);
    printf("Playlist Saved!!\n");
}

void loadPlaylist() {
    FILE* file = fopen("playlist.txt", "r");
    if (file == NULL) {
        printf("No saved playlist found.\n");
        return;
    }

    char title[40];
    char artist[80];
    int duration;

    while (fscanf(file, "%[^;];%[^;];%d\n", title, artist, &duration) == 3) {
        insertSong(title, artist, duration);
    }

    fclose(file);
    //printf("Playlist loaded from 'playlist.txt'.\n");
}

int main()
{

    int choice;
    char title[100];
    char artist[100];
    int duration;

loadPlaylist();

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
            printf("\n-Enter song details-\n");
            printf("Titile: \n");
            scanf("%s", &title);
            printf("Artist:\n");
            scanf("%s", &artist);
            printf("Duration (in seconds): \n");
            scanf("%d", &duration);
            insertSong(title, artist, duration);


            break;
        case 2:
            printf("\n-Enter song name to delete-\n");
            scanf("%s",title);
            deleteSong(title);
            
            break;
        
        case 3:
            printf("\nEnter song name to search:\n");
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

            savePlaylist();
            exit(1);
                    
        default:
            printf("Invalid Choice. Please try again.\n");
           
        }
    }
    return 0;
}