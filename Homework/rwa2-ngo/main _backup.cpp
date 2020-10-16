//Diane Ngo
//RWA 2
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

bool FindPath(int x, int y){

}
int main() {
    //Maze array is reversed to print it out with respect to the coordinate system
    char maze[6][8] = {{'#', '.', '.', '.', '#', '#', '.', '#'},
                       {'.', '.', '#', '.', '.', '#', '.', '.'},
                       {'#', '.', '#', '#', '.', '#', '.', '#'},
                       {'#', '.', '#', '.', '.', '#', '.', '.'},
                       {'#', '.', '.', '#', '.', '.', '.', '#'},
                       {'#', '#', '#', '#', '#', '#', '#', '#'}};
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
    int rows = sizeof(maze) / sizeof(maze[0]);
    int col = sizeof(maze) / rows;
    //cout << rows << col << endl;
    cout << "Enter your desired starting position: " << endl;
    cin >> s_x >> s_y; // User Input

    do {
        //cout << maze[s_x][s_y] << endl;
        cout << "Coordinate contains: " << maze[s_y][s_x] << endl;
        cout << "Invalid starting position - that is a wall. " << endl;
        cout << "Please enter your desired starting position: " << endl;
        cin >> s_x, s_y;

        } while (maze[s_y][s_x] == '#');
    cout << "Updated coordinate: " << maze[s_y][s_x] << endl;
  /*  if ( (s_x & s_y) != '#' ) {
        do {
            cout << "Coordinate contains: " << maze[s_y][s_x] << endl;
            cout << "The starting position cannot be outside of the maze. " << endl;
            cout << "Please enter your desired starting position: " << endl;
            cin >> s_x, s_y;
            cout << "Updated coordinate: " << maze[s_y][s_x] << endl;
        } while ((s_x > rows || s_x < 0) || (s_y > col || s_y < 0));
    }*/
    int s[] = {s_x, s_y};
    cout << "Starting position is: {" << s[1] << ", " << s[0]  << "}." << endl;
    maze[s_y][s_x] = 'S'; // had to swap y and x position because how C++ reads columns first
    // Initialize the variables for the goal position
    int g_x = 0;
    int g_y = 0;
    /*cout << "Enter your desired goal position: " << endl;
    cin >> g_x >> g_y;
    do {
        cout << g_x << g_y << endl;
        //cout << maze[s_x][s_y] << endl;
        cout << "Invalid goal position - that is a wall. " << endl;
        cout << "Please enter your desired goal position: " << endl;
        cin >> g_x, g_y;
    } while (((g_x == (maze[g_y][g_x] = '#')) || (g_y == (maze[g_y][g_x] = '#'))));
    do {
        cout << "The goal position cannot be outside of the maze. " << endl;
        cout << "Please enter your desired goal position: " << endl;
        cin >> g_x, g_y;
    }while ((g_x > rows || g_x < 0) || (g_y > col || g_y < 0)) ;
    int g[] = {g_x, g_y};
    cout << "Goal position is: {" << g[1] << ", " << g[0]  << "}." << endl;
    maze[g_y][g_x] = 'G'; // had to swap y and x position because how C++ reads columns first



    //This goes last with solution
    for (int i = 5; i >= 0; i--) {
        for (int j = 0; j < 8; j++) {
            cout << maze[i][j] << " ";
        }
        cout << " " << endl;
    }*/

    return 0;
}
