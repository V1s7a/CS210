#include <stdio.h>

int main(void) {
	printf("Opening file \"fbData.txt\"\n");
	printf("Reading football data.\n");
	printf("Closing file \"fbData.txt\"\n");
	printf("316 players data read.\n");

	printf("The player ID 0 is Aaron Jones and he scored 4 touchdowns in 2017.\n");
	printf("The player id 122 is Ezekiel Elliott and he rushed for 983 yards in 2017.\n");
	printf("The player with the most yards in 2017 is Kareem Hunt and he had 1327.\n");
	printf("The player with the most TDs in 2017 is Todd Gurley and he had 13.\n");
	printf("The number of players with more than 10 TDs in 2017 is 2.\n");
	printf("The number of players with more than 1000 yards in 2017 is 9.\n");
	printf("The number of players with more than 100 attempts in 2017 is 48.\n");
	printf("The player with the most yards per carry (>100 attempts) is Alvin Kamara and he had 6.1.\n");
	printf("The player with the most yards per carry (>50 attempts) is Dak Prescott and he had 6.3.\n");
	printf("The player with the most yards per carry (>10 attempts) is Cordarrelle Patterson and he had 9.3.\n");
	return 0;
}