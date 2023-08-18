#include <iostream>
using namespace std;
void part1();
void part2();
string* part3one();
void printpart3();
int main() {
	//part1();
	//part2();
	printpart3();
	return 0;
}
void part1() {
	

	int const size = 15;
	int largearray[size];
	int* arr = largearray;
	for (int i = 0; i < size; i++) {
		int ran = (rand() % 10);
		arr[i] = ran;
	}


	int* secondpoint = arr;
	delete [] arr;
	for (int i = 0; i < 10; i++) {
		cout << secondpoint[i] << " ";
	}


}
void part2(){
	int const size = 15;
	int largearray[size];
	int* firstpoint = largearray;
	int* secondpoint = largearray;
	for (int i = 0; i < size; i++) {
		int ran = (rand() % 10);
		largearray[i] = ran;
	}

	delete firstpoint;

	cout << &secondpoint << endl;
	
	for (int i = 0; i < 10; i++) {
		cout << secondpoint[i] << " ";
	}
	

	


}
string* part3one() {
	string* str = new string("abcdefghijkl");
	return str;
}

void printpart3() {
	string* str = part3one();
	cout << *str << endl;
	delete str; 
}
