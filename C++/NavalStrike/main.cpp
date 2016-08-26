#include <iostream>
#include <vector>

#include <stdio.h>

#define COLOR_RED "\033[31m"
#define COLOR_BLU "\033[34m"
#define COLOR_OFF "\033[0m"

using namespace std;

class GameSession
{
private:
	vector<vector<int>> gameFiled;

public:
	GameSession(int x = 10, int y = 10) {
		for (auto i = 0; i < x; ++i) {
			vector<int> newRow(y);
			gameFiled.push_back(newRow);
		}
	}
	~GameSession() {}

	void draw(int x, int y) {
		for (auto i = 0; i < gameFiled.size(); ++i) {
			auto drawRow = gameFiled[i];
			for (auto j = 0; j < drawRow.size(); ++j) {
				if ((i == x) && (j == y)) {
					cout << COLOR_RED << "[" << COLOR_OFF;

					if (drawRow[j] == 5) {
						cout << COLOR_BLU << drawRow[j] << COLOR_OFF;
					} else {
						cout << drawRow[j];
					}
					cout << COLOR_RED << "] " << COLOR_OFF;
				} else {
					
					cout << "[";
					if (drawRow[j] == 5) {
						cout << COLOR_BLU << drawRow[j] << COLOR_OFF;
					} else {
						cout << drawRow[j];
					}
					cout << "] ";
				}
			}
			cout << endl;
		}
	}

	void setCell(int x, int y) {


		char dir;

		cin >> dir;

		switch(dir) 
			{
				case 'w':
				{
					this->gameFiled[x][y] = 5;
					this->gameFiled[x][y+1] = 5;
					break;
				}
				case 'a':
				{
					this->gameFiled[x][y] = 5;
					this->gameFiled[x+1][y] = 5;
					break;
				}
			}
	}

	void clearScreen() {
		cout << "\033[2J\033[1;1H" << endl;
	}

	void run() {
		auto x = 4;
		auto y = 4;

		char key;

		this->draw(x,y);

		do {
			system("/bin/stty raw");
			key = getchar();
			system("/bin/stty cooked");

			switch(key) 
			{
				case 'w':
				{
					if ((x-1) >= 0)
						x -= 1;
					break;
				}
				case 's':
				{
					if ((x+1) < 10)
						x += 1;
					break;
				}
				case 'a':
				{
					if ((y-1) >= 0)
						y -= 1;
					break;
				}
				case 'd':
				{
					if ((y+1) < 10)
						y += 1;
					break;
				}
				case 'e':
				{
					this->setCell(x, y);
					break;
				}


				default:
					break;
			}

			this->clearScreen();
			this->draw(x, y);

		} while (key != 'q');

		this->clearScreen();
	}
	
};

int main(int argc, char const *argv[])
{
	GameSession gs;

	gs.run();

	return 0;
}