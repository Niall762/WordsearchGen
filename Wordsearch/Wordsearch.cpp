#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <tuple>
#include <time.h>
#include <locale>

using namespace std;

typedef vector<vector<char>> matrix;

const string LETTERS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


int rand_int(int min, int max) {
	return rand() % (max - min + 1) + min;
}


char random_letter() {
	int rand_num = rand_int(0, LETTERS.size() - 1);
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


string to_upper(string str) {
	string result;
	locale loc;
	for (int i = 0; i < str.length(); i++) {
		result += toupper(str.at(i), loc);
	}
	return result;
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
		words.push_back(to_upper(word));
	}
	return words;
}


tuple<int, int> random_direction() {
	int x = 0;
	int y = 0;
	while (x == 0 && y == 0) {
		x = rand_int(-1, 1);
		y = rand_int(-1, 1);
	}
	return make_tuple(x, y);
}


matrix add_words_to_grid(matrix grid, vector<string> words) {
	int height = grid.size();
	int width = grid[0].size();
	for (int i = 0; i < words.size(); i++) {
		string word = words[i];
		tuple<int, int> direction = random_direction();
		int x = get<0>(direction);
		int y = get<1>(direction);

		int begin_x;
		int begin_y;
		if (x == 1) {
			begin_x = rand_int(0, width - word.size());
		}
		if (x == 0) {
			begin_x = rand_int(0, width - 1);
		}
		if (x == -1) {
			begin_x = rand_int(word.size() - 1, width - 1);
		}
		if (y == 1) {
			begin_y = rand_int(0, width - word.size());
		}
		if (y == 0) {
			begin_y = rand_int(0, width - 1);
		}
		if (y == -1) {
			begin_y = rand_int(word.size() - 1, width - 1);
		}

		cout << "Starting position: " << begin_x << ", " << begin_y << endl;
		cout << "Direction: " << x << ' ' << y << endl;

		for (int j = 0; j < word.length(); j++) {
			grid[begin_y + y * j][begin_x + x * j] = word[j];
		}
	}
	return grid;
}


int main() {
	srand(time(NULL));
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