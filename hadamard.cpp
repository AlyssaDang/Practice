#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Written by Alyssa Dang
// Part 1: Notes ------------------------------------------------------------------------------
/*
Hadamard Matrix : an algorithm where the first square matrix is H(1) = 1
		and each of the following matrices H(n+1) =	H(n) H(n)
								H(n) -H(n)

For the purposes of this program, -H(n) is represented using a 0 (or false boolean).

Example:	H(1) =	1

		H(2) =	1  1
			1  0

		H(4) =	1 1  1 1
			1 0  1 0
			1 1  0 0
			1 0  0 1

		H(8) =	1 1 1 1 1 1 1 1
			1 0 1 0 1 0 1 0
			1 1 0 0 1 1 0 0
			1 0 0 1 1 0 0 1
			1 1 1 1 0 0 0 0
			1 0 1 0 0 1 0 1
			1 1 0 0 0 0 1 1
			1 0 0 1 0 1 1 0
					
The number of rows and columns of the matrix is given by 'n' in H(n)
It must be a power of 2.
*/

// Written by Alyssa Dang
// Part 2: Implementation ---------------------------------------------------------------------
vector<vector<bool>> hadamard(int);
void print (vector <vector<bool>>const&);

int main()
{
	int n = 0;
	cout << "Enter a number n: ";
	cin >> n;
	
	if(n == 0 || ceil(log2(n) != floor(log2(n))))
	{
		cout << "n must be a power of 2 greater than 0" << endl;
	}
	else
	{
		vector<vector<bool>> hadamardVector = hadamard(n);
		print(hadamardVector);
	}
	return 0;
}




// Hadamard Algorithm
vector<vector<bool>> hadamard(int times)
{
	vector <vector<bool>> hadamardMatrix(times, vector<bool>(times));
	hadamardMatrix.at(0).at(0) = true;
	
	for(int n = 1; n < times; n = n*2) // Hadamard(n++) until the number the user specifies
	{
		/*
		The following loops sets the values of the rows and columns 
		of the matrix by copying the previous ( H(n-1) ) values to 
		the right and bottom left. The right botton is inverse using '!'
		
		Will try doing it recursively later...
		*/
		
		for(int i = 0; i < n; i++)
		{			
			for(int j = 0; j < n; j++)
			{
				hadamardMatrix.at(i+n).at(j) = hadamardMatrix.at(i).at(j);
				hadamardMatrix.at(i).at(j+n) = hadamardMatrix.at(i).at(j);
				hadamardMatrix.at(i+n).at(j+n) = !(hadamardMatrix.at(i).at(j));
			}
		}
	}
	return hadamardMatrix;
}




// Printing the Matrix
void print(vector <vector<bool>> const&v)
{
	for(int i = 0; i < v.size(); i++)
	{
		for(int j = 0; j < v.at(i).size(); j++)
		{
			cout << v.at(i).at(j) << ' ';
		}
		cout << endl;
	}
}
