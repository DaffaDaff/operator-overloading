#include "include/input.h"

void input::MainMenu(worldData* data){
    while(1){
        c_clrscr();

        cout << "Welcome To Cartesian Rectangle Simulation" << endl;
        cout << endl;
        cout << "1. Show Graph" << endl;
        cout << "2. Show Rectangles" << endl;
        cout << "0. Exit" << endl;
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
                c_clrscr();
                RectangleMenu(data);
                break;
            case '0':
                c_clrscr();
                return;
            
            default:
                break;
        }
    }
}

void input::Graph(worldData* data){
    while(1){
        c_clrscr();

        coordinateSystem::Draw(data);

        cout << endl;
        cout << "Use WASD to Move Coordinate" << endl;
        cout << "Press Escape to Exit" << endl;
        
        int input = 0;
        
        input = c_getch();


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
        c_clrscr();

        cout << endl;
        cout << "Rectangle Selection: " << endl;
        PrintRectangles(data);
        cout << endl;

        cout << endl;
        cout << "Other Menu: " << endl;
        cout << "99. Add Rectangle" << endl;
        cout << "0. Back" << endl;
        cout << endl;
        cout << "-> Select Menu: ";

        int input;

        cin >> input;

        switch (input)
        {
        case 99:
            data->rectangles.push_back(InputRectangle());
            c_clrscr();
            cout << "New Rectangle Succesfully Added" << endl;
            cout << endl << "Press Any Key to Continue";

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

    c_clrscr();

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

    return rectangle(point, width, height, symbol, false);
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

    int input;

    while(1){
        c_clrscr();

        cout << "Center: " << "{" << rect->GetX() << ", " << rect->GetY() << ")" << endl;
        cout << "Width: " << rect->GetWidth() << endl;
        cout << "Height: " << rect->GetHeight() << endl;
        cout << "X Border: " << rect->GetXMin() << " - " << rect->GetXMax() << endl;
        cout << "Y Border: " << rect->GetYMin() << " - " << rect->GetYMax() << endl;
        cout << "Symbol: " << rect->GetSymbol() << endl;
        cout << "Fill Mode: " << (rect->GetFill() ? "Filled" : "Hollow") << endl;
        cout << endl;
        cout << "Options: " << endl;
        cout << "1. Change Size" << endl;
        cout << "2. Change Symbol" << endl;
        cout << "3. Change Fill Mode" << endl;
        cout << "4. Check Intersection" << endl;
        cout << "5. Create New Rectangle from Union" << endl;
        cout << "6. Create New Rectangle from Intersection" << endl;
        cout << "9. Delete Rectangle" << endl;
        cout << "0. Back" << endl;
        cout << endl;
        cout << "-> Select Option: ";

        cin >> input;

        cout << endl;

        switch (input){
            case 1:
                ChangeSize(rect);

                break;

            case 2:
                c_clrscr();

                cout << "Input New Symbol: ";

                char symbol;
                cin >> symbol;

                rect->SetSymbol(symbol);

                c_clrscr();

                cout << "Symbol Succesfully Changed to" << symbol << endl;
                cout << endl << "Pres Any Key To Continue";

                c_getch();

                break;
            case 3:
                c_clrscr();

                rect->SetFill(!rect->GetFill());

                c_clrscr();

                cout << "Fill Mode Succesfully Changed to " << (rect->GetFill() ? "Filled" : "Hollow") << endl;
                cout << endl << "Pres Any Key To Continue";

                c_getch();

                break;

            case 4:
                c_clrscr();

                PrintRectangles(data);
                cout << endl <<  "Select Second Rectangle: " ;

                cin >> input;

                if(input < 1 || input > data->rectangles.size()) break;

                c_clrscr();

                if(*rect == data->rectangles[input - 1]){
                    cout << "Rectangles Intersected" << endl;
                }
                else{
                    cout << "Rectangles NOT Intersected" << endl;
                }

                cout << endl << "Pres Any Key To Continue";

                c_getch();

                break;

            case 5:
                c_clrscr();

                PrintRectangles(data);
                cout << endl <<  "Select Second Rectangle: " ;

                cin >> input;

                if(input < 1 || input > data->rectangles.size()) break;

                data->rectangles.push_back(*rect + data->rectangles[input - 1]);

                break;

            case 6:
                c_clrscr();

                PrintRectangles(data);
                cout << endl <<  "Select Second Rectangle: " ;

                cin >> input;

                if(input < 1 || input > data->rectangles.size()) break;

                data->rectangles.push_back(*rect - data->rectangles[input - 1]);

                break;

            case 9:
                cout << "Are You Sure You Want To Delete This Rectangle?(y/n) ";

                char YN;
                cin >> YN;

                if(YN != 'Y' && YN != 'y') break;

                data->rectangles.erase(data->rectangles.begin() + index);

                c_clrscr();

                cout << "Rectangle Succesfully Deleted" << endl;
                cout << endl << "Press Any Key to Continue";

                c_getch();
                return;

            case 0:
                return;
            
            default:
                break;
        }
    }

    
}

void input::ChangeSize(rectangle* rect){
    c_clrscr();

    cout << "Options: " << endl;
    cout << "1. Change Width" << endl;
    cout << "2. Change Height" << endl;
    cout << "3. Set Size to Double" << endl;
    cout << "3. Set Size to Half" << endl;
    cout << endl;
    cout << "-> Select Option: ";

    int input;

    cin >> input;

    c_clrscr();

    switch (input){
        case 1:
            cout << "Input New Width: ";

            int width;

            cin >> width;

            rect->SetWidth(width);

            c_clrscr();

            cout << "Rectangle Width Succesfully Changed to " << width << endl;
            cout << endl << "Press Any Key to Continue";

            c_getch();

            break;
        
        case 2:
            cout << "Input New Height: ";

            int height;

            cin >> height;

            rect->SetHeight(width);

            c_clrscr();

            cout << "Rectangle Height Succesfully Changed to" << height << endl;
            cout << endl << "Press Any Key to Continue";

            c_getch();

            break;

        case 3:
            *rect++;

            c_clrscr();

            cout << "Rectangle Size Succesfully Changed to Double" << endl;
            cout << endl << "Press Any Key to Continue";

            c_getch();

            break;

        case 4:
            *rect--;

            c_clrscr();

            cout << "Rectangle Size Succesfully Changed to Half" << endl;
            cout << endl << "Press Any Key to Continue";

            c_getch();

            break;

        default:
            break;
    }
}