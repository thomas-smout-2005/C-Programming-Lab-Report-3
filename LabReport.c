#include <stdio.h> 
#define MAX 100 

// structure to hold band singer, song, price and year of release
struct cg {
    char band_singer;
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
        &song_catalogue[i].band_singer,
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
    enter_song_data(); // call the function to enter n songs
};