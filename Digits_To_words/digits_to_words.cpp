#include <iostream>

using namespace std;

const string EMPTY = "";

string X[] = {
	EMPTY, "One ", "Two ", "Three ", "Four ", "Five ", "Six ",
	"Seven ", "Eight ", "Nine ", "Ten ", "Eleven ", "Twelve ",
	"Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ",
	"Eighteen ", "Nineteen "
};

string Y[] = {
	EMPTY, EMPTY, "Twenty ", "Thirty ", "Forty ", "Fifty ",
	"Sixty ", "Seventy ", "Eighty ", "Ninety "
};

string convert_to_digit(int n, string suffix)
{
	// if n = 0
	if (n == 0)
		return EMPTY;

	// split n if it is more than 19
	if (n > 19)
		return Y[n / 10] + X[n % 10] + suffix;
	else
		return X[n] + suffix;
}

string number_to_words(unsigned long long int n)
{
	string res;

	//handles digits at one and tens
	res = convert_to_digit((n % 100), "");

	if (n > 100 && n % 100)
		res = "and " + res;

	//handle digits at hundreds
	res = convert_to_digit(((n / 100) % 10), "Hundred ") + res;

	//handles digits at thousands and tens of thousands
	res = convert_to_digit(((n / 1000) % 100), "Thousand ") + res;

	//handles digits at hundreds of thousands
	res = convert_to_digit(((n / 100000) % 100), "Hundred thousand ") + res;

	//handles digits at million
	res = convert_to_digit(((n / 1000000) % 100), "Million ") + res;

	return res;
}

int main()
{
	int input_var;
	cout << "Enter a number to be converted (1 to 1000000): ";

	do
	{
		if (!(cin >> input_var))
		{
			cout << "digits only please...\n";
			cin.clear();
			cin.ignore(10000000, '\n');
		} else
		{
			cout << number_to_words(input_var) << endl;
			cin.clear();
			cin.ignore(10000000000000, '\n');
		}
	} while (input_var != -1);
		cout << "Exiting...\n";
	return 0;
}