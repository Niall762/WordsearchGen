#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <tuple>
#include <time.h>

using namespace std;

typedef vector<vector<char>> matrix;

const string LETTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


int rand_int(int min, int max) {
	return rand(min % max);
}


char random_letter() {
	int rand_num = rand_int(LETTERS.size() - 1);
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


tuple<int, int> random_direction() {
	int x = 0;
	int y = 0;
	while (x == 0 && y == 0) {
		x = rand_int(2) - 1;
		y = rand_int(2) - 1;
	}
	return make_tuple(x, y);
}


matrix add_words_to_grid(matrix grid, vector<string> words, int height, int width) {
	for (int w = 0; w < words(size); w++) {
		word = words[i]
			tuple<int, int> direction = random_direction();
		int x = get<0>(direction);
		int y = get<1>(direction);

		if (x == -1) {
			begin_x = rand_int(width - word(size), width)
		}
		if (x == 0) {
			begin_x = rand_int(0, width)
		}
		if (x == 1) {
			begin_x = rand_int(0, width - word(size))
		}
		if (y == -1) {
			begin_y = rand_int(0, height - word(size))
		}
		if (y == 0) {
			begin_y = rand_int(0, height)
		}
		if (y == 1) {
			begin_y = rand_int(height - word(size), height)
		}
		for (int q = 0; q < word.length(); q++){
				grid[begin_y + (y*q)][begin_x + (x*q)] = word[q]
			}
	}
	
	return grid;
}


int main() {
	srand(time(0));
	int height, width;
	cout << "Please enter the dimensions of the wordsearch, X and then Y" << endl;
	cin >> height >> width;

	matrix grid = create_grid(height, width);
	grid = randomise_grid(grid);

	vector<string> words = get_words();
	grid = add_words_to_grid(grid, words, height, width);

	display_grid(grid);
	return 0;
}