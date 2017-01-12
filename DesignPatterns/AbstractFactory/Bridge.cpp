#include <iostream>

using namespace std;

class Character {
public:
	Character() {}
	~Character() {}
	void Print() { cout << "Printing Character" << endl; }
};
class HandleToCharacter {
public:
	~HandleToCharacter() { delete character; }
	HandleToCharacter() : character(new Character()) {}
	Character* operator->() { return character; } //overloaded ->
private:
	Character* character;
};

int main() {
	HandleToCharacter handle; handle->Print();
	system("PAUSE");
}
