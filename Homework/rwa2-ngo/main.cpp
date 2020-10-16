//Diane Ngo
//RWA 2
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#define ROWS 6
#define COLS 8
bool WallThere(char maze[6][8], int& x, int& y){
    cout << "Checking wall" << endl;
    if (maze[y][x] == '#')
        return false;
    else
        return true;
};
bool OutsideMaze(char maze[6][8], int& x, int& y){
    cout << "Checking if outside the maze" << endl;
    if ((y > ROWS || y < 0) && (x > COLS || X < 0 ))
        return false;
    else
        return true;
};
/**
 * FindPathNorth Function
 * Checks if the space in the north direction from the
 * current position is not a wall and not outside of the maze.
 * If it meets these conditions, then it moves north and places
 * a plus sign.
 * @param maze
 * @param x
 * @param y
 * @return
 */
bool FindPathNorth(char maze[6][8], int& x, int& y){
    y = y+1;
    cout << "Checking north" << endl;
    bool no_wall = WallThere(maze, x, y);
    bool not_outside = OutsideMaze(maze, x, y);
    if (no_wall &&  not_outside){
        maze[y][x] = '+';
    }
    else
        cout << "North is blocked" << endl;
    return true;
};

int main() {
    //Maze array is reversed to print it out with respect to the coordinate system
    char maze[6][8] ={{'#' , '.', '.', '.', '#' , '#' , '.', '#' },
                      {'.', '.', '#' , '.', '.', '#' , '.', '.'},
                      {'#' , '.', '#' , '#', '.', '#' , '.', '#'},
                      {'#' , '.', '#' , '.' , '.', '#' , '.', '.' },
                      {'#' , '.',  '.', '#' , '.', '.', '.', '#' },
                      { '#' , '#', '#', '#', '#', '#', '#', '#'}};
    cout << "This is the maze." << endl;

    for (int i = 5; i >= 0; i--) {
        for (int j = 0; j < 8; j++) {
            cout << maze[i][j] << " ";
        }
        cout << " " << endl;
    }
    // Initialize the variables for the starting position
    int s_x = 0;
    int s_y = 0;
    int rows = sizeof(maze)/sizeof(maze[0]);
    int col = sizeof(maze)/rows;
    cout << rows <<  col << endl;
    cout << "Enter your desired starting position: " << endl;
    cin >> s_x >> s_y; // User Input
    while((s_x == (maze[s_y][s_x] = '#') ||s_y == (maze[s_y][s_x] = '#')
        cout << s_x << endl;
        cout << s_y << endl;
        cout << maze[s_x][s_y] << endl;
        cout << "Invalid starting position - that is a wall. " << endl;
        cout << "Please enter your desired starting position: " << endl;
        cin >> s_x, s_y;
    }));

    int s[] = {s_x, s_y};
    cout << "Starting position is: {" << s[0] << ", " << s[1]  << "}." << endl;
    maze[s_y][s_x] = 'S'; // had to swap y and x position because how C++ reads columns first
    // Initialize the variables for the goal position
    int g_x = 0;
    int g_y = 0;
    cout << "Enter your desired goal position: " << endl;
    cin >> g_x >> g_y;
    int g[] = {g_x, g_y};
    cout << "Goal position is: {" << g[0] << ", " << g[1]  << "}." << endl;
    maze[g_y][g_x] = 'G'; // had to swap y and x position because how C++ reads columns first


    FindPathNorth(maze, s_x, s_y);
    for (int i = 5; i >= 0; i--) {
        for (int j = 0; j < 8; j++) {
            cout << maze[i][j] << " ";
        }
        cout << " " << endl;
    }
    return 0;
}
