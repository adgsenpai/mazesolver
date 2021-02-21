//ADG MAZE SOLVER

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <time.h> 
#include <iomanip>     
using namespace std;
const int WIDTH = 10;
const int HEIGHT = 10;
int moves = 0;
void printMaze(char maze[][WIDTH], int curx, int cury);
bool validMove(char maze[][WIDTH], bool visited[][WIDTH],
	int newX, int newY);
bool move(char maze[][WIDTH], bool visited[][WIDTH],
	int& curX, int& curY, int newX, int newY);
bool validMove(char maze[][WIDTH], bool visited[][WIDTH],
	int newX, int newY)
{

	if (newX < 0 || newX >= WIDTH)
		return false;
	if (newY < 0 || newY >= HEIGHT)
		return false;

	if (maze[newY][newX] == 'X')
		return false;

	if (visited[newY][newX])
		return false;
	return true;
}
 
bool move(char maze[][WIDTH], bool visited[][WIDTH],
	int& curX, int& curY, int newX, int newY)
{   ++moves;
	bool foundExit = false;
	if (maze[newY][newX] == 'E') 
		foundExit = true;
	curX = newX;
	curY = newY;
	visited[curY][curX] = true;
	return foundExit;
}

void printMaze(char maze[][WIDTH], int curx, int cury)
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if ((x == curx) && (y == cury))
				cout << "@";
			else
				cout << maze[y][x];
		}
		cout << endl;
	}
}

bool search(char maze[][WIDTH], bool visited[][WIDTH], int x, int y)
{
	bool foundExit = false;
	if (maze[y][x] == 'E')
		return true;
	visited[y][x] = true;
	if (validMove(maze, visited, x, y - 1))
		foundExit = search(maze, visited, x, y - 1);
	if (!foundExit && (validMove(maze, visited, x, y + 1)))
		foundExit = search(maze, visited, x, y + 1);
	if (!foundExit && (validMove(maze, visited, x - 1, y)))
		foundExit = search(maze, visited, x - 1, y);
	if (!foundExit && (validMove(maze, visited, x + 1, y)))
		foundExit = search(maze, visited, x + 1, y);
	if (foundExit)
	{
		printMaze(maze, x, y);
		cout << endl;
		return true;
	}

	return false;

}

int main()
{
	clock_t start, end;
	start = clock();
	char maze[HEIGHT][WIDTH] = {
	 {'X',' ','X','X','X','X','X','X','X','X'},
	 {'X',' ',' ',' ',' ',' ','X',' ',' ','X'},
	 {'X',' ','X',' ',' ',' ','X',' ',' ','X'},
	 {'X',' ','X','X','X',' ','X',' ',' ','X'},
	 {'X',' ',' ',' ','X',' ','X',' ',' ','X'},
	 {'X',' ',' ',' ','X',' ',' ',' ','X','X'},
	 {'X',' ','X','X','X',' ',' ',' ',' ','X'},
	 {'X',' ','X',' ',' ',' ','X',' ',' ','X'},
	 {'X',' ',' ',' ',' ',' ','X',' ',' ','X'},
	 {'X','X','X','X','X','X','X','E','X','X'}
	};

	bool visited[HEIGHT][WIDTH];
	int x = 1, y = 1;
	bool foundExit = false;
	cout << "ADG 2D MAZE \n\n";


	for (int x = 0; x < WIDTH; x++)
		for (int y = 0; y < HEIGHT; y++)
			visited[y][x] = false;
	visited[y][x] = true;
	 
	cout << search(maze, visited, x, y) << endl;
	end = clock();
	double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	cout << "Maze solved in : " << fixed
		<< time_taken << setprecision(5);
	cout << " sec " << endl;
	system("pause");

}
