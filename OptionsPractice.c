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
    // options from 1 to 5
    // (1) Enter Data Function
    // (2) Send Data to File Function
    // (3) Read Data from File Function
    // (4) Print out the Catalogue to Screen Function
    // (5) Exit Program (end loop)
    // Enter your choice now (e.g. 4): 
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
    
};