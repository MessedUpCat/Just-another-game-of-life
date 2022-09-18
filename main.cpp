#include <iostream>
#include <Windows.h>
//#include <cstdlib>
#include <stdlib.h>
#include <string>
int size  = 5 ;

using namespace std;



int main() {



//setup
bool matrix[size][size] = { { 0, 0, 0, 0, 0 },
                            { 0, 0, 1, 0, 0 },
                            { 0, 0, 1, 0, 0 },
                            { 0, 0, 1, 0, 0 },
                            { 0, 0, 0, 0, 0 } };
bool matrix_new[size][size];


    for(int x = 0; x < size; x++ )  // scrolling loop
    {
        for(int y = 0; y < size; y++)
        {
            matrix_new[x][y] = false;
        }
    }

//displaying values

    while(true){
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



        //system("cls");
        //printf("\e[1;1H\e[2J");


        // rules
        for(int x = 0; x < size; x++ )  //
        {
            for(int y = 0; y < size; y++)
            {
                int neighbours=  matrix[x - 1][y +1] + matrix[x][y + 1] + matrix[x + 1][y + 1] + matrix[x - 1][y]  + matrix[x + 1][y] + matrix[x - 1][y - 1 ] + matrix[x][y - 1] + matrix[x + 1][y - 1];
                if(matrix[x][y]){
                    if(neighbours == 2 || neighbours == 3) {
                        matrix_new[x][y] = true;
                    }else{
                        matrix_new[x][y] = false;
                    }
                }else{
                    if(neighbours == 3) {
                        matrix_new[x][y] = true;
                    }else{
                        matrix_new[x][y] = false;
                    }
                }

            }

        }




        cout<<endl;  // when the inner loop is done, go to a new line
        // change generation
        for(int x = 0; x < size; x++ )  //
        {
            for(int y = 0; y < size; y++)
            {
                matrix[x][y] = matrix_new[x][y];
        }

    }




    }


    return 0;
}
