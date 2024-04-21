// TUGAS KELOMPOK 1

#include <iostream>

using namespace std;

int main() {
	
	int a[2][2]= {{1,2},{3,4}};
	int b[2][2] = {{1,2},{3,4}};
	
	int count = 0;

	for(int i = 0; i < 2; i++) 
    {
		for(int j = 0; j < 2; j++) 
        {
			int c = a[i][j]+b[i][j];
			cout << c << " ";
			count +=1;
			if(count == 2) 
            {
				cout << "\n";
				count = 0;
			}
	    }
    }
	return 0;
}