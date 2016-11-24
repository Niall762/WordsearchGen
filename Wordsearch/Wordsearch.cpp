#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <time.h>

using namespace std;

typedef vector<vector<char>> matrix;

const string LETTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


char random_letter() {
	int rand_num = rand() % LETTERS.size();
	return LETTERS[rand_num];
}


matrix create_grid(int height, int width) {
	matrix grid;
	for (int i = 0; i < height; i++) {
		vector<char> row;
		for (int j = 0; j < width; j++) {
			row.push_back(' ');
		}
		grid.push_back(row);
	}
	return grid;
}


matrix randomise_grid(matrix grid) {
	srand(time(0));
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			grid[i][j] = random_letter();
		}
	}
	return grid;
}


void display_grid(matrix grid) {
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			cout << grid[i][j] << ' ';
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

matrix add_words_to_grid(matrix grid, vector<string> words) {
	return grid;
}

int main() {
	int height, width;
	cout << "Please enter the dimensions of the wordsearch, X and then Y" << endl;
	cin >> height >> width;

	matrix grid = create_grid(height, width);
	grid = randomise_grid(grid);

	vector<string> words = get_words();
	grid = add_words_to_grid(grid, words);

	display_grid(grid);
	return 0;
}