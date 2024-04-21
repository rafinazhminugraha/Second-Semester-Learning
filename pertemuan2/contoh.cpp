#include <iostream>

using namespace std;

int main() {
    
	int a[2][2] = {{1,2},{3,4}};
	int b[2][2] = {{5,6},{7,8}};

	for(int i = 0; i < 2; i++) {
		for(int j = 0; j <2; j++) {
			cout << "Nilai A [" << i << "][" << j << "] = " << a[i][j] << "\n";
			cout << "Nilai B [" << i << "][" << j << "] = " << b[i][j] << "\n";
		}
	} 
	
	return 0;
}