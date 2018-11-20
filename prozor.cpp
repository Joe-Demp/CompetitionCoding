/*	Solution to problem "Prozor" from open.kattis.com

	By Joseph Dempsey, 19/11/2018
*/

#include <iostream>
using namespace std;

int checkHit( char w[][100], int x, int y, int size );
void drawRacket( char w[][100], int x, int y, int size );

int main() {
	char window[100][100];
	int R, S, K;

	/* R corresponds to height (vertical)
	 * S corresponds to width  (horizontal)
	 * K corresponds to dimensions of square Racket
	 */
	cin >> R >> S >> K;

	//	take in the array of chars
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < S; ++j) {
			cin >> window[ i ][ j ];
		}
	}

	//	check each possible hit, recording the largest hit each time
	int r_x = 0, r_y = 0;
	int maxFlies = 0, tmp;
	//	outer moves vertical
	for (int i = 0; i + K <= R, ++i) {
		//	inner moves horizontal
		for (int j = 0; j + K <= S; ++j) {
			if ( (tmp = checkHit(window, j, i, K)) > maxFlies) {
				maxFlies = tmp;
				r_x = j;
				r_y = i;
			}
		}
	}

	//	place the largest hit on the window

	//	print out the largest hit

	return 0;
}

int checkHit( char w[][100], int x, int y, int size ) {
	return -1;
}

void drawRacket( char w[][100], int x, int y, int size ) {

}