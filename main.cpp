#include <iostream>
#include <Windows.h>
//#include <cstdlib>
#include <stdlib.h>
#include <string>

using namespace std;

const int size =5;

bool cleaner(bool matrix_next[size][size]){
    for(int x = 0; x < size; x++ )  // clearing matrix new
    {
        for(int y = 0; y < size; y++)
        {
            matrix_next[x][y] = false;
        }
    }
    return(matrix_next);
}

void display(bool matrix[size][size]){

    for(int x=0;x<size;x++)
    {
        for(int y=0;y<size;y++) { //
            if(matrix[x][y]){
                cout<< "#";
            }else{
                cout << "." ;
            }
            cout << " " ;

        }
        cout<<endl;
    }

    Sleep(1000);
    cout << string( 100, '\n' ); // patologia zmień to jak sie da

}

bool nextGen(bool matrix[size][size]){
    bool matrix_temp[size][size];
    for(int x = 0; x < size; x++ )  //
    {
        for(int y = 0; y < size; y++)
        {
            matrix[x][y] = matrix_temp[x][y];
        }
    }
    return(matrix_temp);
}

bool rules(bool matrix[size][size]){
// rules
    bool matrix_next[size][size];
    cleaner(matrix_next);

    for(int x = 0; x < size; x++ )  //rules
    {
        for(int y = 0; y < size; y++)
        {
            int neighbours=  matrix[x - 1][y +1] + matrix[x][y + 1] + matrix[x + 1][y + 1] + matrix[x - 1][y]  + matrix[x + 1][y] + matrix[x - 1][y - 1 ] + matrix[x][y - 1] + matrix[x + 1][y - 1];
            if(matrix[x][y]){
                if(neighbours == 2 || neighbours == 3) {
                    matrix_next[x][y] = true;
                }else{
                    matrix_next[x][y] = false;
                }
            }else{
                if(neighbours == 3) {
                    matrix_next[x][y] = true;
                }else{
                    matrix_next[x][y] = false;
                }
            }

        }

    }
    return(matrix);
}


int main() {
//setup to be changed into read random etc
    bool  matrix[size][size] =                  { { 0, 0, 0, 0, 0 },
                                                  { 0, 0, 1, 0, 0 },
                                                  { 0, 0, 1, 0, 0 },
                                                  { 0, 0, 1, 0, 0 },
                                                  { 0, 0, 0, 0, 0 } };

    while(true){
        display(matrix);
        rules(matrix);
        nextGen(matrix);
    }

    return 0;
}

