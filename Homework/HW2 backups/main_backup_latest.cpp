//Diane Ngo
//RWA 2
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#define ROWS 6
#define COLS 8
/**
 * WallThere Function:
 * Function to check if there is a wall in the desired direction
 * @param maze
 * @param x
 * @param y
 * @return
 */
bool NoWall(char **maze, int& x, int& y){
    cout << "Checking wall" << endl;
    if (maze[y][x] == '#')
        return false;
    else
        return true;
};
/**
 * OutsideMaze Function:
 * Function to check if the desired direction is outside of the maze
 * @param maze
 * @param x
 * @param y
 * @return
 */
bool NotOutside(char **maze, int& x, int& y){
    cout << "Checking if outside the maze" << endl;
    if ((y > ROWS || y < 0) && (x > COLS || x < 0 ))
        return false;
    else
        return true;
};

bool FindPathNorth(char maze[6][8], int& x, int& y){
    y = y+1;
    cout << "Checking north" << endl;
    bool no_wall = WallThere(maze, x, y);
    bool not_outside = OutsideMaze(maze, x, y);
    if (no_wall &&  not_outside){
        maze[y][x] = '+';
    }
    else {
        cout << "North is blocked" << endl;
        y = y - 1;
    }
    return true;
};

bool FindPathEast(char maze[6][8], int& x, int& y){
    x = x+1;
    cout << "Checking east" << endl;
    bool no_wall = WallThere(maze, x, y);
    bool not_outside = OutsideMaze(maze, x, y);
    if (no_wall &&  not_outside){
        maze[y][x] = '+';
    }
    else {
        cout << "East is blocked" << endl;
        x = x - 1;
    }
    return true;
};

bool FindPathSouth(char maze[6][8], int& x, int& y){
    y = y-1;
    cout << "Checking south" << endl;
    bool no_wall = WallThere(maze, x, y);
    bool not_outside = OutsideMaze(maze, x, y);
    if (no_wall && not_outside){
        maze[y][x] = '+';
    }
    else {
        cout << "South is blocked" << endl;
        y = y + 1;
    }
    return true;

};

bool FindPathWest(char maze[6][8], int& x, int& y){
    x = x-1;
    cout << "Checking west" << endl;
    bool no_wall = WallThere(maze, x, y);
    bool not_outside = OutsideMaze(maze, x, y);
    if (no_wall &&  not_outside){
        maze[y][x] = '+';
    }
    else{
        cout << "West is blocked" << endl;
        x = x-1;
    }
    return true;
};

void display_maze(char maze[6][8], int i1, int i2) {
    for (int i = 5; i >= 0; i--) {
        for (int j = 0; j < 8; j++) {
            cout << maze[i][j] << " ";
        }
        cout << " " << endl;
    }
};
bool FindPath(char maze[6][8], int x, int y){
    bool not_outside = OutsideMaze(maze, x, y);
    cout << not_outside << endl;
    if (!not_outside)
        return false;
    if (maze[y][x] == 'G')
        return true;
    bool check_north = FindPath(maze, x, y+1);
    if (check_north){
        maze[y][x] = '+';
        return true;
    };
    bool check_east = FindPath(maze, x+1, y);
    if (check_east){
        maze[y][x] = '+';
        return true;
    };
    bool check_south = FindPath(maze, x, y-1);
    if (check_south){
        maze[y][x] = '+';
        return true;
    };
    bool check_west = FindPath(maze, x-1, y);
    if (check_west){
        maze[y][x] = '+';
        return true;
    };


    display_maze(maze);
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

    display_maze(maze);
    // Initialize the variables for the starting position
    int s_x = 0;
    int s_y = 0;

    cout << "Enter your desired starting position: " << endl;
    cin >> s_x >> s_y; // User Input
    //!Initialize temporary variables s_x and s_y to save the new input
    int temp_s_x = 0;
    int temp_s_y = 0;
    while(maze[s_y][s_x] == '#'){
        cout << "Coordinate contains: " << maze[s_y][s_x] << endl;
        cout << "Invalid starting position - that is a wall." << endl;
        cout << "Please enter your desired starting position: " << endl;
        cin >> temp_s_x;
        cin >> temp_s_y;
        s_x = temp_s_x;
        s_y = temp_s_y;

        maze[s_y][s_x] = maze[temp_s_y][temp_s_x];
        cout << "Updated coordinate: " << maze[s_y][s_x] << endl;
        /**
         * This while loop checks if the desired starting position
         * is outside of the maze.
         */
         while ((s_x > ROWS || s_x < 0) || (s_y > COLS || s_y < 0)){
             cout << "The starting position cannot be outside of the maze." << endl;
             cout << "Please enter your desired starting position: " << endl;
             cin >> temp_s_x;
             cin >> temp_s_y;
             s_x = temp_s_x;
             s_y = temp_s_y;
             maze[s_y][s_x] = maze[temp_s_y][temp_s_x];

         }
    }
    int s[] = {s_x, s_y};
    cout << "Starting position is: {" << s[0] << ", " << s[1]  << "}." << endl;
    maze[s_y][s_x] = 'S'; // had to swap y and x position because how C++ reads columns first
    temp_s_x = temp_s_y = 0;

    // Initialize the variables for the goal position
    int g_x = 0;
    int g_y = 0;
    cout << "Enter your desired goal position: " << endl;
    cin >> g_x >> g_y;
    //!Initialize temporary variables g_x and g_y to save the new input
    int temp_g_x = 0;
    int temp_g_y = 0;
    while(maze[g_y][g_x] == '#'){
        cout << "Coordinate contains: " << maze[g_y][g_x] << endl;
        cout << "Invalid starting position - that is a wall." << endl;
        cout << "Please enter your desired starting position: " << endl;
        cin >> temp_g_x;
        cin >> temp_g_y;

        g_x = temp_g_x;
        g_y = temp_g_y;
        maze[g_y][g_x] = maze[temp_g_y][temp_g_x];
        cout << "Updated coordinate: " << maze[g_y][g_x] << endl;
        /**
         * This while loop checks if the desired goal position
         * is outside of the maze.
         */
        while ((g_x > ROWS || g_x <0) || (g_y > COLS || g_y < 0)){
            cout << "The goal position cannot be outside of the maze." << endl;
            cout << "Please enter your desired goal position: " << endl;
            cin >> temp_g_x;
            cin >> temp_g_y;
            g_x = temp_g_x;
            g_y = temp_g_y;
            maze[g_y][g_x] = maze[temp_g_y][temp_g_x];
        }
    }
    int g[] = {g_x, g_y};
    cout << "Goal position is: {" << g[0] << ", " << g[1]  << "}." << endl;
    temp_g_x = temp_g_y = 0;
    maze[g_y][g_x] = 'G'; // had to swap y and x position because how C++ reads columns first

    //maze[s_y][s_x] = '+';
    FindPath(maze, s_x, s_y);

    display_maze(maze);

    return 0;
}
