#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<string>
#include<random>

using namespace std;

static double arr[6][3];
class NeuralNetwork
{
private:

public:
	int Activate(float t) 
	{
		float Act;
		int Exp;
		Act = t + arr[0][0];
		if (Act >= 0.00) 
		{

			return Exp = 1;
		}
		else 
		{
			return Exp = 0;
		}
	}
	void Network()
	{
		int Res = 0;
		srand(time(NULL));
		fstream inFile("Data.data", ios::in);
		int fileSize = 151;
		int X = 0;
		int Exp = 0;
		float total = 0;
		int x1 = 0, x2 = 1, x3 = 2;
		int z2;
		cout << setw(80) << "Expected value\t\t" << "Y value\n";
		while (fileSize > 0) {

			z2 = 1;
			for (z2 = 1; z2 < 6; z2++) {
				//assigns weight
				float f = (float)rand() / RAND_MAX; //generates random numbers b/w -2 to 2
				arr[z2][x2] = (-2) + f * (2 - (-2));
			}
			z2 = 0;
			for (z2 = 0; z2 < 6; z2++) {
				inFile >> X;
				arr[z2][x1] = X;
			}
			z2 = 1;
			for ( z2 = 1; z2 < 6; z2++) {
				//multiplies weight with their corresponding x value
				arr[z2][x3] = ((arr[z2][x1]) * (arr[z2][x2]));
			}
			z2 = 1;
			for (z2 = 1; z2 < 6; z2++) {
				//calculates the sum of each column cont. multiplied value.
				total = total + arr[z2][x3];
				z2++;
			}

			Exp = Activate(total);
			cout << endl;
			z2 = 0;

			for (z2 = 0; z2 < 6; z2++) {
				//display
				cout << arr[z2][x1] << "\t";
				
			}
			Res = (1 / (1 + exp(-(total))));//sigmoid func.  
			cout << setw(20) << Exp << setw(20) << Res;
			fileSize--;
		}

		inFile.close();
		cout << endl << "\t\t\t Data is Closed.\n ";
	}
};

int main() {
	NeuralNetwork obj;
	int choice;
	do
	{
		cout << "Enter 1 to Run Neural Network data file. OR 0 to Exit.\n";
		cin >> choice;
		switch (choice)
		{
		case 0:
			break;
		case 1:
			obj.Network();
		default:
			break;
		}
	} while (choice!=0);
	
	system("pause");
	return 0;
}
