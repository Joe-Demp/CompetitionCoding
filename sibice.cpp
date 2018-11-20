#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int N;			//	number of matches on floor
	int W, H; 		//	width and height of box
	double hyp;
	int L_i;		//	length of match i

	cin >> N >> W >> H;
	hyp = sqrt( ( W * W ) + ( H * H ) );

	for ( int i = 0; i < N; ++i )
	{
		cin >> L_i;
		if ( L_i <= hyp )
			cout << "\nDA";
		else
			cout << "\nNE";
	}	//	end for
	return 0;
}	//	end main