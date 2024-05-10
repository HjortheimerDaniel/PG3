#include <stdio.h>
#include <vector>
#include <list>
using namespace std;


int main() {

	list<const char*> stations{ //original stations

		"Tokyo", "Kanda", "Akihabara", "Okachimachi","Ueno",
		"Uguisudani", "Nippori", "Tabata", "Komagome", "Sugamo",
		"Otsuka", "Ikebukuro", "Mejiro", "Takadanobaba", "Shin-Okubo",
		"Shinjuku", "Yoyogi", "Harajuku", "Shibuya", "Ebisu",
		"Meguro", "Gotanda", "Osaki", "Shinagawa", "Tamachi",
		"Hamamatsucho", "Shimbashi", "Yurakucho"
	};

	printf("º˜a3”N˜Hü}:\n\n");

	for (std::list<const char*>::iterator itr = stations.begin(); itr != stations.end(); itr++) //takes the first name to the last name of the list and goes through them in that order
	{
		printf("%s\n", *itr); //starts with Tokyo
	}

	printf("\nº˜a47”N˜Hü}:\n\n");


	for (std::list<const char*>::iterator itr = stations.begin(); itr != stations.end(); itr++) //takes the first name to the last name of the list and goes through them in that order
	{
		if (*itr == "Tabata") { //if the next word in the list is Tabata
			itr = stations.insert(itr, "Nishi-Nippori"); //instert this word before it
			printf("%s\n", *itr); //and print it
			itr++; //then go to the next word
		}
		printf("%s\n", *itr); 
	}

	printf("\n—ß˜a5”N˜Hü}:\n\n");


	for (std::list<const char*>::iterator itr = stations.begin(); itr != stations.end(); itr++) //takes the first name to the last name of the list and goes through them in that order
	{
		if (*itr == "Tamachi") { //if the next word is Tamachi
			itr = stations.insert(itr, "Takanawa Gateway"); //insert this word before it
			printf("%s\n", *itr); //print it
			itr++; //go the the next word in the list
		}
		printf("%s\n", *itr); //starts with Tokyo
	}

	return 0;
}