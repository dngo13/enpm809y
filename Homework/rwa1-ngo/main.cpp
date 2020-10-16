//Diane Ngo
#include <array>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/**
 * Structure for initial state
 * Defines the variables such as the parts
 * in the bin and gripper status
 */
struct initial {
int init_red_parts = 10;
int init_green_parts = 10;
int init_blue_parts = 10;
int red_parts_tray = 0;
int green_parts_tray = 0;
int blue_parts_tray = 0;
int final_red_parts = 0;
int final_green_parts = 0;
int final_blue_parts = 0;
bool gripper_empty = true;
bool kit_status_incomplete = true;
}robot;

/**
 * Function for Place - red part
 * After checking the required pre-conditions from
 * the PickRedPart function
 */
int PlaceRedPart(int red_parts_place,int init_red_parts, int red_parts_tray, int& final_red_parts){
    cout << "---Place red part" << endl;
    cout << "   Red parts in tray: " << red_parts_tray << endl;
    cout << "------------------------" << endl;
    final_red_parts = init_red_parts - red_parts_place;
    robot.gripper_empty = true;
    return final_red_parts;
}
/**
 * Function for Pick - red part
 * Compares the desired amount of red parts
 * to be picked and then picks it up
 */
int PickRedPart(int red_parts_place, int init_red_parts, int red_parts_tray, int& final_red_parts) {
    cout << "Red parts desired: " << red_parts_place << endl;
    while (red_parts_tray < red_parts_place) {
        for (int i = 0; i < red_parts_place; ++i) {
            red_parts_tray++;
            cout << "---Pick red part" << endl;

            robot.gripper_empty = false;
            if (!robot.gripper_empty && robot.kit_status_incomplete) {
                PlaceRedPart(red_parts_place, robot.init_red_parts, red_parts_tray, final_red_parts);
            }
        }
    }
    return final_red_parts;
}

/**
 * Function for Place - green part
 * After checking the required pre-conditions from
 * the PickGreenPart function
 */
int PlaceGreenPart(int green_parts_place, int init_green_parts, int green_parts_tray, int& final_green_parts){
    cout << "---Place green part" << endl;
    cout << "   Green parts in tray: " << green_parts_tray << endl;
    cout << "------------------------" << endl;
    final_green_parts = init_green_parts - green_parts_place;
    robot.gripper_empty = true;
    return final_green_parts;
}

/**
 * Function for Place - green part
 * After checking the required pre-conditions from
 * the PickGreenPart function
 */
void PickGreenPart(int green_parts_place, int init_green_parts, int green_parts_tray, int& final_green_parts){
    cout << "Green parts desired: " << green_parts_place << endl;
    while (green_parts_tray < green_parts_place) {
        for (int i = 0; i < green_parts_place; ++i) {
            green_parts_tray++;
            cout << "---Pick green part" << endl;

            robot.gripper_empty = false;
            if (!robot.gripper_empty && robot.kit_status_incomplete) {
                PlaceGreenPart(green_parts_place, robot.init_red_parts, green_parts_tray, final_green_parts);
            }
        }
    }
    }

/**
 * Function for Place - blue part
 * After checking the required pre-conditions from
 * the PickBluePart function
*/
int PlaceBluePart(int blue_parts_place,int init_blue_parts, int blue_parts_tray, int& final_blue_parts){
    cout << "---Place blue part" << endl;
    cout << "   Blue parts in tray: " << blue_parts_tray << endl;
    cout << "------------------------" << endl;
    final_blue_parts = init_blue_parts - blue_parts_place;
    robot.gripper_empty = true;
    return final_blue_parts;
}
/*
 * Function for Pick - blue part
 * Compares the desired amount of red parts
 * to be picked and then picks it up
 */
void PickBluePart(int blue_parts_place, int init_blue_parts, int& blue_parts_tray, int& final_blue_parts) {
    cout << "Blue parts desired: " << blue_parts_place << endl;
    while (blue_parts_tray < blue_parts_place) {
        for (int i = 0; i < blue_parts_place; ++i) {
            blue_parts_tray++;
            cout << "---Pick blue part" << endl;

            robot.gripper_empty = false;
            if (!robot.gripper_empty && robot.kit_status_incomplete) {
                PlaceBluePart(blue_parts_place, robot.init_blue_parts, blue_parts_tray, final_blue_parts);
            }
        }
    }
}

int main() {
    // Prints out the initial condition of how many parts are in the bin
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "There are " << robot.init_red_parts << " red parts in the bin." << endl;
    cout << "There are " << robot.init_green_parts << " green parts in the bin." << endl;
    cout << "There are " << robot.init_blue_parts << " blue parts in the bin." << endl;
    int red_parts_place = 0;
    int green_parts_place = 0;
    int blue_parts_place = 0;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "How many red parts to place in the kit tray? " ;
    cin >> red_parts_place;
    // Check to see if the user entered too many parts over how many are available
    if (red_parts_place > robot.init_red_parts) {
        cout << "--Not enough red parts in the bin to build the kit" << endl;
        cout << "How many red parts to place in the kit tray? ";
        cin >> red_parts_place;
    }
    // Check to see if the user entered too many parts over how many are available
    cout << "How many green parts to place in the kit tray? ";
    cin >> green_parts_place;
    if (green_parts_place > robot.init_green_parts) {
        cout << "--Not enough green parts in the bin to build the kit" << endl;
        cout << "How many green parts to place in the kit tray? ";
        cin >> green_parts_place;
    }
    // Check to see if the user entered too many parts over how many are available
    cout << "How many blue parts to place in the kit tray? ";
    cin >> blue_parts_place;
    if (blue_parts_place > robot.init_blue_parts) {
        cout << "--Not enough blue parts in the bin to build the kit" << endl;
        cout << "How many blue parts to place in the kit tray? ";
        cin >> blue_parts_place;
    }

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Generating a plan..." << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    // Start the picking process if the initial conditions are met
    if (robot.gripper_empty && robot.kit_status_incomplete){
        PickRedPart(red_parts_place, robot.init_red_parts, robot.red_parts_tray, robot.final_red_parts);
    }
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    // Start the picking process if the initial conditions are met
    if (robot.gripper_empty && robot.kit_status_incomplete){
        PickGreenPart(green_parts_place, robot.init_green_parts, robot.green_parts_tray, robot.final_green_parts);
            }
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    // Start the picking process if the initial conditions are met
    if (robot.gripper_empty && robot.kit_status_incomplete){
        PickBluePart(blue_parts_place, robot.init_blue_parts, robot.blue_parts_tray, robot.final_blue_parts);
    }
    // Prints out the summary
    cout << "Summary" << endl;
    cout << "There are " << robot.final_red_parts << " red parts left in the bin." << endl;
    cout << "The kit tray has " << red_parts_place << " red parts." << endl;
    cout << "There are " << robot.final_green_parts << " green parts left in the bin." << endl;
    cout << "The kit tray has " << green_parts_place << " green parts." << endl;
    cout << "There are " << robot.final_blue_parts << " blue parts left in the bin." << endl;
    cout << "The kit tray has " << blue_parts_place << " blue parts." << endl;
    return 0;

}
