#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

// Header function for user input.
void tagInput(std::string& givenName, std::string& givenDesc)
{
	std::cout << "Enter the tag name: ";
	std::getline(std::cin, givenName);
	std::cout << "\nNow, enter the tag description: ";
	std::getline(std::cin, givenDesc);

	// Remove all ampersands.
	givenDesc.erase(std::remove(givenDesc.begin(), 
		givenDesc.end(), '&'), givenDesc.end());
}

int main()
{
	// Variables.
	std::string tagName, tagDesc, contYesNo;
	int orderNum = 0;
	bool continueTag = true;

	// txt file setup.
	std::fstream file("message.txt", std::ios::in | std::ios::out);

	if (!file)
	{
		std::cout << "\nFile is not available.";
		return 1;
	}

	// Tag input.
	while (continueTag)
	{
		// Gather tag name and description from user.
		tagInput(tagName, tagDesc);
		
		// Increase order count.
		++orderNum;

		// Write to the txt file.
		file << "  " << tagName << ":" << std::endl;
		file << "     order: " << orderNum << std::endl;
		file << "     tag: '&f" << tagDesc << "&f] \'" << std::endl;
		file << "     description: \'" << tagDesc << "\'" << std::endl;
		file << "     permission: deluxetags.tag." << tagName << std::endl;

		// Ask user to continue.
		std::cout << "\nContinue? Type \"yes\" or \"no:\" ";
		std::cin >> contYesNo;
		std::cout << std::endl;
		std::cin.ignore();

		// Stop the program if the answer is no.
		if (contYesNo == "no")
		{
			continueTag = false;
		}
	}
	// Close the file.
	file.close();

	return 0;
}