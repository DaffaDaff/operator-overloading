#include "include/coordinateSystem.h"

void coordinateSystem::Draw(worldData* data){
    int offsetX = data->offsetX;
    int offsetY = data->offsetY;

    for(int y = 15 + offsetY; y >= 0 + offsetY; y--){
        std::cout << std::setfill(' ') << std::setw(4) << y << " ";

        for(int x = 0 + offsetX; x <= 25 + offsetX; x++){
            cout << ". ";
        }
        cout << endl;
    }

    cout << "     ";
    for(int x = 0 + offsetX; x <= 25 + offsetX; x++){
        if(x < 0)
            cout << "- ";
        else
            cout << "  ";
    }
    cout << endl;

    for(int i = 3; i >= 1; i--){
        cout << "     ";

        for(int x = 0 + offsetX; x <= 25 + offsetX; x++){
            int n = abs(x);

            if(utils::GetDigit(n) >= i)
                cout << utils::GetDigit(n, i) << " ";
            else
                cout << "  ";
        }

        cout << endl;
    }
}