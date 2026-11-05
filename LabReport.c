#include <stdio.h> 
#define MAX 100 

// structure to hold band singer, song, price and year of release
struct cg {
    char band_name;
    char song_name;
    float price;
    int year;
};

// creates the array
struct cg song_catalogue[MAX]; 



// function to enter the song data
int enter_song_data(void) {

  // defines the variable for the number of songs
  int n_songs;

  // ask for how many songs we will have
  printf("Enter number of songs: ");
  if (scanf("%d", &n_songs) != 1) { // Validate input
      printf("Invalid input. Please enter a number.\n");
      return 0;
  }

  // create a loop to get the info for each song
  int i = 0;
  while (i < n_songs) {
    // ask for the band/singer, song name, price and year of release
    printf("Enter band/singer, song name, price and year of release: ");
    // if statment prevents incorrect inputs
    // each input is put directly into the array
    if(scanf("%c %c %f %d", 
        &song_catalogue[i].band_name,
        &song_catalogue[i].song_name,
        &song_catalogue[i].price,
        &song_catalogue[i].year) != 4) {
      printf("Invalid input format.\n");
      return 0; // Exit with error
      };
    i++;
    } 
};



int main(void)
{
    printf("Welcome to the Song Catalogue Program!\n");
    printf("Your options are:\n");
    printf("1. Enter song data\n");
    printf("2. Save data to file\n");
    printf("3. Read data from file\n");
    printf("4. Display catalogue\n");
    printf("5. Exit\n");
    printf("Enter your choice now: ");

    // varibale for option choice
    int display_choice;

    // ask for option
    printf("Enter choice number: ");
    if (scanf("%i", &display_choice) != 1) { // Validate input
        printf("Invalid input. Please enter a number.\n");
         return 0;
    }

    // if statements to call the correct function based on the option chosen
    if (display_choice == 1) {
        enter_song_data(); // call the function to enter n songs
    } else if (display_choice == 2) {
        save_data_to_file(); // call the function to save the data to a file
    } else if (display_choice == 3) {
        read_data_from_file(); // call the function to read the data from a file
    } else if (display_choice == 4) {
        catalogue(); // call the function to display the catalogue
    } else if (display_choice == 5) {
        exit(0); // exit the program
    } else {
        printf("Invalid choice. Please try again.\n");
    }
};