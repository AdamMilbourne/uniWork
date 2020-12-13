#include <iostream>

int main()
{
	int numberOfStudents = 14;
	int packetsInTotal = 40;
	int packetsPerStudent = packetsInTotal / numberOfStudents;
	int packetsLeftForMe = packetsInTotal %= numberOfStudents;

	std::cout << "Packets For Each Student: " << packetsPerStudent << std::endl;
	std::cout << "Packets Left For Me: " << packetsLeftForMe << std::endl;

	return 0;
}