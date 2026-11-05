#include <stdio.h>
#define MAX 100

// create a structure with our 4 catagories; Name of band, name of song, price, release year
struct cg {
    char band_name;
    char song_name;
    float price;
    int year;
};

// turn out structure into an array
struct cg song_catalogue[MAX];


int main() {
    // open loop
    if (1) {
        // print out the options for the user
        printf("Welcome to the Song Catalogue Program!\n");
        printf("Your options are:\n");
        printf("1. Enter song data\n");
        printf("2. Save data to file\n");
        printf("3. Read data from file\n");
        printf("4. Display catalogue\n");
        printf("5. Exit\n");
        printf("Enter your choice now: ");
    }

    // variable to hold the user input
    int choice;

    // ask for option printf("Enter choice number: ");
    if (scanf("%i", &choice) != 1) {
        // Validate input
        printf("Invalid input. Please enter a number. \n");
        return 0;
    }

    // if statements to call the correct function based on the option chosen
    if (choice==1) {
        enter_song_data(); // call the function to enter n songs
    }
    elseif (choice==2) {
        save_data_to_file(); // call the function to save the data to a file
    }
    else if (choice==3) {
        read_data_from_file(); // call the function to read the data from a file
    }
    else if (choice==4) {
        catalogue(); // call the function to display the catalogue
    } else if (choice==5) {
        exit(0); // exit the program
    else {
        printf("Invalid choice. Please try again.\n");
    }
};



int enter_data() {
    // ask for user input
    printf("Please enter the band/singer, song name, price and year of release (e.g. Beatles, Hey Jude, 1.99, 1968): ");
    int i =  sizeof(song_catalogue) / sizeof(song_catalogue[0]);
    // take the input and put it into the array
    scanf("%c %c %f %d", 
        &song_catalogue[i].band_name,
        &song_catalogue[i].song_name,
        &song_catalogue[i].price,
        &song_catalogue[i].year);
};



int save_data() {
    // send all data in the array to file
    FILE *fp = fopen("song_catalogue.txt", "a");

    // for length of array, print each element to file
    for (int i = 0; i < sizeof(song_catalogue) / sizeof(song_catalogue[0]); i++) {
        fprintf(fp, "%c %c %f %d\n", 
            song_catalogue[i].band_name,
            song_catalogue[i].song_name,
            song_catalogue[i].price,
            song_catalogue[i].year);
    }

    fclose(fp);
};



int read_data() {
    // read data from file to array
    FILE *fp = fopen("song_catalogue.txt", "r");

    int count = 0;
    while (fscanf(fp, "%c %c %f %d",
        &song_catalogue[count].band_name,
        &song_catalogue[count].song_name,
        &song_catalogue[count].price,
        &song_catalogue[count].year) == 4) {
        count++;
    }

    fclose(fp);
};



int display_catalogue() {
    // organise array into Year of Release: Newer to Older
    int count = sizeof(song_catalogue) / sizeof(song_catalogue[0]);
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (song_catalogue[j].year < song_catalogue[j + 1].year)
            {
                struct cg temp = song_catalogue[j];
                song_catalogue[j] = song_catalogue[j + 1];
                song_catalogue[j + 1] = temp;
            }
        }
    }

    // print out array for user
    printf("Catalogue:\n");
    for (int i = 0; i < count; i++) {
        printf("%c %c %f %d\n",
            song_catalogue[i].band_name,
            song_catalogue[i].song_name,
            song_catalogue[i].price,
            song_catalogue[i].year);
    }
};