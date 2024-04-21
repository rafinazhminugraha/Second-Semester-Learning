// TUGAS KELOMPOK 2

#include <iostream>

using namespace std;

int main() 
{
	int array[2][3]; 
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 3; j++)
		{
            cout << "Masukkan nilai array [" << i << "][" << j << "] : "; cin >> array[i][j];
        }	
	}


	int count = 0;
    cout << "\nNilai array 2 x 3 adalah:\n";
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			cout << array[i][j] << " ";
			count += 1;
			if(count == 3) 
			{
				cout << "\n";
				count = 0;
			}
		}
	}
	

	return 0;
}