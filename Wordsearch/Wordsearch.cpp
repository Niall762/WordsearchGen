#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <time.h>
using namespace std;

const string LETTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

char random_letter() {
	int rand_num = rand() % LETTERS.size();
	return LETTERS[rand_num];
}


vector<vector<char>> random_matrix(int height, int width) {
	srand(time(0));
	vector<vector<char>> matrix;
	for (int i = 0; i < height; i++) {
		vector<char> row;
		for (int j = 0; j < width; j++) {
			row.push_back(random_letter());
		}
		matrix.push_back(row);
	}
	return matrix;
}


void display_matrix(vector<vector<char>> matrix) {
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
}


vector<string> get_words() {
	int num_words;
	cout << "How many words would you like you filthy animal" << endl;
	cin >> num_words;

	vector<string> words;
	cout << "What are the words" << endl;
	string word;
	for (int i = 0; i < num_words; i++) {
		cin >> word;
		words.push_back(word);
	}
	return words;
}

int main() {
	int height, width;
	cout << "Please enter the dimensions of the wordsearch, X and then Y" << endl;
	cin >> height >> width;

	vector<vector<char>> matrix = random_matrix(height, width);

	display_matrix(matrix);

	vector<string> words = get_words();

	cout << "The words you entered were:" << endl;
	for (int i = 0; i < words.size(); i++) {
		cout << words[i] << endl;
	}
	return 0;
}