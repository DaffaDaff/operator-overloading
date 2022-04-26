#include "include/input.h"

void input::MainMenu(worldData* data){
    while(1){
        utils::ClearScreen();

        cout << "Welcome To Cartesian Rectangle Simulation" << endl;
        cout << endl;
        cout << "1. Show Graph" << endl;
        cout << "2. Show Rectangles" << endl;
        cout << endl;
        cout << "-> Select Menu: ";

        char input;

        cin >> input;
        fflush(stdin);

        switch (input){
            case '1':
                Graph(data);
                break;
            
            default:
                break;
        }
    }
}

void input::Graph(worldData* data){
    while(1){
        utils::ClearScreen();

        coordinateSystem::Draw(data);

        ShowGraphSelection();

        
        int input = 0;
        
        input = utils::getch();

        switch (input){
            case 'w':
                data->offsetY++;
                break;
            case 's':
                data->offsetY--;
                break;
            case 'a':
                data->offsetX--;
                break;
            case 'd':
                data->offsetX++;
                break;

            case 'W':
                data->offsetY++;
                break;
            case 'S':
                data->offsetY--;
                break;
            case 'A':
                data->offsetX--;
                break;
            case 'D':
                data->offsetX++;
                break;

            case 27: //escape
                return;

            default:
                break;
        }
    }
}

void input::ShowGraphSelection(){
    cout << endl;
    cout << "Use WASD to Move Coordinate" << endl;
    cout << "Press Escape to Exit" << endl;
}