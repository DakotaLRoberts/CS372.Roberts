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
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {

		arr[i] = i;
		cout << arr[i] << endl;// using this line to show what was put into the array 
	}


	int* secondpoint = arr;
	delete[] arr;
	for (int i = 0; i < 10; i++) {
		cout << secondpoint[i] << " ";
	}


}
void part2() {
	int const size = 15;

	int* firstpoint = new int[size];

	for (int i = 0; i < size; i++) {

		firstpoint[i] = i;
		cout << firstpoint[i] << endl;// using this line to show what was put into the array 
	}
	int* secondpoint = firstpoint;
	delete firstpoint;

	cout << &secondpoint << endl;

	for (int i = 0; i < 10; i++) {
		cout << secondpoint[i] << " ";
	}





}
void part3one(string& random) {
	string* str = new string("abcdefghijkl");
	random = *str;
	delete str;
}

void printpart3() {
	string finalstring;
	part3one(finalstring);

	cout << finalstring << endl;

}
