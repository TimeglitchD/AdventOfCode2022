#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class Day
{

public:
	Day(string day)
	{
		cout << "______________DAY " << Day::day << "________________________" << endl;

		this->day = day;
		this->input = this->getInput();

	}
	~Day() {
		if (this->input.is_open()) {
			this->input.close();
		}
		else {
			cout << "File " << Day::day << ".txt was not used..." << endl;
			throw(1);
		}

	}
protected:
	string day;
	ifstream input;
	void resetInput() {
		this->input.clear();                 // clear fail and eof bits
		this->input.seekg(0, std::ios::beg); // back to the start!
	}
	ifstream getInput() {
		ifstream file;
		file.open("Inputs/"+day + ".txt");
		if (!file.is_open()) {
			cout << "File " << Day::day << ".txt probably doesn't exist yet." << endl;
			throw(1);
		}
		return file;
	}
	void printSolution(string a, string b) {
		cout << "______________Part A________________________" << endl;
		cout << "\t" << a << endl;
		cout << "______________Part B________________________" << endl;
		cout << "\t" << b << endl << endl;
	}
	virtual string a()
	{
		return "Solution A unsolved!";
	}
	virtual string b()
	{
		return "Solution B unsolved!";
	}
};

