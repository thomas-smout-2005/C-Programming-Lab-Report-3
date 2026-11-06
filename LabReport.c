#include <stdio.h>
#define MAX 100


// create a structure with our 4 catagories; Name of band, name of song, price, release year
struct cg {
    char band_name[100];
    char song_name[100];
    float price;
    int year;
};


void enter_data(void); // function to enter data into the array
void save_data(void); // function to save data to a file
int read_data(void); // function to read data from a file
void display_catalogue(void); // function to display the catalogue


// turn out structure into an array
struct cg song_catalogue[MAX];


int count = 0; // variable to keep track of how many songs are in the catalogue


int main(void) {
    // open loop
    while (1) {
        // print out the options for the user
        printf("Welcome to the Song Catalogue Program!\n");
        printf("Your options are:\n");
        printf("1. Enter song data\n");
        printf("2. Save data to file\n");
        printf("3. Read data from file\n");
        printf("4. Display catalogue\n");
        printf("5. Exit\n");
        printf("Enter your choice now: ");

        // variable to hold the user input
        int choice;

        // ask for option printf("Enter choice number: ");
        if (scanf("%i", &choice) != 1) {
            // Validate input
            printf("Invalid input. Please enter a number. \n");
        }

        // if statements to call the correct function based on the option chosen
        if (choice==1) {
            enter_data(); // call the function to enter n songs
        }
        else if (choice==2) {
            save_data(); // call the function to save the data to a file
        }
        else if (choice==3) {
            read_data(); // call the function to read the data from a file
        }
        else if (choice==4) {
            display_catalogue(); // call the function to display the catalogue
        }
        else if (choice==5) {
            break;
        }
        else {
            printf("Invalid choice. Please try again.\n");
        }
        return 0; // return 0 to indicate successful completion of the program
    }
    return 0; // return 0 to indicate successful completion of the program
}



void enter_data(void) {
    
    if (count >= MAX) {
        printf("Catalogue is full. Cannot add more songs.\n");
        return;
    }
    
    // ask for user input
    printf("Please enter the band/singer, song name, price and year of release (e.g. Beatles, HeyJude, 1.99, 1968): ");
    // take the input and put it into the array
    scanf("%99s %99s %f %d", 
        song_catalogue[count].band_name,
        song_catalogue[count].song_name,
        &song_catalogue[count].price,
        &song_catalogue[count].year);
    count++; // increment the count variable to keep track of how many songs are in the catalogue
}



void save_data(void) {
    // send all data in the array to file
    FILE *fp = fopen("song_catalogue.txt", "w");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    // for length of array, print each element to file
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s %s %f %d\n", 
            song_catalogue[i].band_name,
            song_catalogue[i].song_name,
            song_catalogue[i].price,
            song_catalogue[i].year);
    }

    fclose(fp);
    printf("Data saved to file successfully.\n");
}



int read_data(void) {
    count = 0; // reset count to 0 before reading data from file
    // read data from file to array
    FILE *fp = fopen("song_catalogue.txt", "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int i = 0;
    while (fscanf(fp, "%99s %99s %f %d",
        song_catalogue[i].band_name,
        song_catalogue[i].song_name,
        &song_catalogue[i].price,
        &song_catalogue[i].year) == 4) {
        i++;
    }

    count = i; // set count to the number of songs read from the file

    fclose(fp);
    printf("%d songs loaded.\n", count);
    return 0;
}



void display_catalogue(void) {
    // organise array into Year of Release: Newer to Older
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
        printf("%s %s %f %d\n",
            song_catalogue[i].band_name,
            song_catalogue[i].song_name,
            song_catalogue[i].price,
            song_catalogue[i].year);
    }
}