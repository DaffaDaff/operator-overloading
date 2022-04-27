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

            case '2':
                utils::ClearScreen();
                RectangleMenu(data);
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

        cout << endl;
        cout << "Use WASD to Move Coordinate" << endl;
        cout << "Press Escape to Exit" << endl;
        
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

void input::RectangleMenu(worldData* data){
    while(1){
        cout << endl;
        cout << "Rectangle Selection: " << endl;
        PrintRectangles(data);
        cout << endl;

        cout << endl;
        cout << "Other Menu: " << endl;
        cout << "99. Add Rectangle" << endl;
        cout << "0. Exit" << endl;
        cout << endl;
        cout << "-> Select Menu: ";

        int input;

        cin >> input;

        switch (input)
        {
        case 99:
            data->rectangles.push_back(InputRectangle());
            utils::ClearScreen();
            cout << "New Rectangle Succesfully Added" << endl;
            break;
        case 0:
            return;
        
        default:
            if(input < 1 || input > data->rectangles.size()) break;

            ShowRectangle(data, input - 1);

            break;
        }
    }
}

rectangle input::InputRectangle(){
    point point;
    int width, height;
    char symbol;

    utils::ClearScreen();

    cout << "Input New Rectangle";
    cout << endl;

    cout << endl << "Input Center X: ";
    cin >> point.x;
    cout << endl << "Input Center Y: ";
    cin >> point.y;
    cout << endl << "Input Width: ";
    cin >> width;
    cout << endl << "Input Height: ";
    cin >> height;
    cout << endl << "Input Symbol: ";
    cin >> symbol;
    
    return rectangle(point, width, height, symbol);
}

void input::PrintRectangles(worldData* data){
    for(unsigned int i = 0; i < data->rectangles.size(); i++){
        rectangle rectangle = data->rectangles[i];

        cout << i + 1 << ". ";
        cout << rectangle.GetSymbol() << " ";
        cout << "(" << rectangle.GetX() << ", " << rectangle.GetY() << ")";
        cout << "   " << "width: " << rectangle.GetWidth();
        cout << "   " << "height: " << rectangle.GetHeight();
        cout << endl;

    }
}

void input::ShowRectangle(worldData* data, int index){
    rectangle* rect = &data->rectangles[index];

    utils::ClearScreen();

    cout << "Center: " << "{" << rect->GetX() << ", " << rect->GetY() << ")" << endl;
    cout << "Width: " << rect->GetWidth() << endl;
    cout << "Height: " << rect->GetHeight() << endl;
    cout << "X Border: " << rect->GetYMin() << " - " << rect->GetYMax() << endl;
    cout << "Y Border: " << rect->GetXMin() << " - " << rect->GetXMax() << endl;
    cout << "Symbol: " << rect->GetSymbol() << endl;
    cout << endl;
    cout << "Options: " << endl;
    cout << "0. Delete Rectangle" << endl;
    cout << endl;
    cout << "-> ";

    int input;
    cin >> input;

    cout << endl;

    switch (input){
        case 0:
            cout << "Are You Sure You Want To Delete This Rectangle?(y/n) ";

            char YN;
            cin >> YN;

            if(YN != 'Y' && YN != 'y') break;

            data->rectangles.erase(data->rectangles.begin() + index);
            break;
        
        default:
            break;
    }

    utils::ClearScreen();
}