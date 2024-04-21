// TUGAS KELOMPOK 3

#include <iostream>

using namespace std;

int main() 
{
	int array1[2][2]; 
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
            cout << "Masukkan nilai array A [" << i << "][" << j << "] : "; cin >> array1[i][j];
        }	
	}

	
	int array2[2][2]; 
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
            cout << "Masukkan nilai array B [" << i << "][" << j << "] : "; cin >> array2[i][j];
        }	
	}


	int count1 = 0;
    	cout << "\nArray A =\n";
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			cout << array1[i][j] << " ";
			count1 += 1;
			if(count1 == 2) 
			{
				cout << "\n";
				count1 = 0;
			}
		}
	}
	
	int count2 = 0;
    	cout << "\nArray B =\n";
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			cout << array2[i][j] << " ";
			count2 += 1;
			if(count2 == 2) 
			{
				cout << "\n";
				count2 = 0;
			}
		}
	}
	
    cout << "\nPenjumlahan matrix array A + B =\n";

    int count3 = 0;
	for(int i = 0; i < 2; i++) 
    {
		for(int j = 0; j < 2; j++) 
        {
			int c = array1[i][j]+array2[i][j];
			cout << c << " ";
			count3 +=1;
			if(count3 == 2) 
            {
				cout << "\n";
				count3 = 0;
			}
	    }
    }

	return 0;
}