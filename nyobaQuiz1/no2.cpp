#include <iostream>
using namespace std;

int main()
{
    int matriksA[2][2]; 
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
            cout << "Masukkan nilai array A [" << i << "][" << j << "] : "; cin >> matriksA[i][j];
        }	
	}

    int matriksB[2][2]; 
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
            cout << "Masukkan nilai array B [" << i << "][" << j << "] : "; cin >> matriksB[i][j];
        }	
	}

    int matriksC[2][2];
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            matriksC[i][j] = 0;
            for(int k = 0; k < 2; k++)
            {
                matriksC[i][j] += matriksA[i][k] * matriksB[k][j];
            }
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << matriksC[i][j] << " ";
            if (j == 1)
            {
                cout << "\n";
            }
            
        }
    }       
}