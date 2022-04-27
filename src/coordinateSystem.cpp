#include "include/coordinateSystem.h"

void coordinateSystem::Draw(worldData* data){
    int offsetX = data->offsetX;
    int offsetY = data->offsetY;

    char rectanglePoints[25][15] = {0};

    for(unsigned int i = 0; i < data->rectangles.size(); i++){
        rectangle* rectangle = &data->rectangles[i];

        int xMin = ceil(rectangle->GetXMin());
        int xMax = ceil(rectangle->GetXMax()) - 1;
        int yMin = ceil(rectangle->GetYMin());
        int yMax = ceil(rectangle->GetYMax()) - 1;

        for(int j = yMin; j <= yMax; j++){
            for(int k = xMin; k <= xMax; k++){
                //if((j != yMin && j != yMax) && (k != xMin && k != xMax)) continue;
                if((j < 0 + offsetY || j > 15 + offsetY) || (k < 0 + offsetX || k > 25 + offsetX)) continue;

                rectanglePoints[k - offsetX][j - offsetY] = rectangle->GetSymbol();
            }
        }
    }

    for(int y = 14; y >= 0; y--){
        std::cout << std::setfill(' ') << std::setw(4) << y + offsetY << " ";

        for(unsigned int x = 0; x <= 24; x++){
            if(rectanglePoints[x][y] != 0) cout << rectanglePoints[x][y] << " ";
            else cout << ". ";
        }
        cout << endl;
    }

    cout << "     ";
    for(unsigned int x = 0; x <= 24; x++){
        if(x + offsetX < 0)
            cout << "- ";
        else
            cout << "  ";
    }
    cout << endl;

    for(int i = 3; i >= 1; i--){
        cout << "     ";

        for(unsigned int x = 0; x <= 24; x++){
            int n = (x + offsetX) * (x + offsetX);

            if(utils::GetDigit(n) >= i)
                cout << utils::GetDigit(n, i) << " ";
            else
                cout << "  ";
        }

        cout << endl;
    }
}