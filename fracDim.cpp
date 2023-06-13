#include <iostream>
#include "Matrix.h"

using namespace std;


int countOccupied(Matrix &x, int box){

	int count = 0;

	for(int i = 0; i < x.numRows - box + 1; i+= box){
		
		for(int j = 0; j < x.numCols - box + 1; j += box){
			
			int sum = 0;
			for( int k = i; k < i + box; k++){

				for(int l = j; l < j + box; l++){

					sum += x._(k,l);

					}

				}

				if(sum != 0) count+= 1;

			}


		}

	return count;

	}

			










int main(){

Matrix a(25,25) ;
a.initRand();
//cout << a << endl;
cout << countOccupied(a,2) << endl;

return 0;

}
