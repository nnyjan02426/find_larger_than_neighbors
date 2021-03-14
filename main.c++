#include<iostream>
using namespace std;

/*
TASK DESCRIPTION
Write a program to read the number of rows(r) and columns(c)
of a two-dimensional integer array, 
then read the array elements row by row.
Finally print the elements that are greater than all of its neighbors.
Note that an element can have at most 4 neighbors.
If ther are multiple such elements, print them in the order of 
row by row, column by column.
*/

/* Simple ver.
int main(){
    int r=0, c=0;
    cin >> r >> c;
        
    int arr[r][c];
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            int num = arr[i][j];
            bool pass = 1;

            if((i!=0)&&pass&&(num < arr[i-1][j])){ //上
                pass = 0;
            }
            if((i!=r-1)&&pass&&(num < arr[i+1][j])){ //下
                pass = 0;
            }
            if((j!=0)&&pass&&(num < arr[i][j-1])){ //左
                pass = 0;
            }
            if((j!=c-1)&&pass&&(num < arr[i][j+1])){ //右
                pass = 0;
            }

            if(pass){
                cout << num << endl;
            }
        }
    }

    return 0;
}
*/


int main(){
    int con = 1;
    while(con){
        cout << endl; //This line is only added for aesthetic
        int r=0, c=0;
        bool input_pass = 0;
        int pass_nums = 0;

        //User enter the row and column counts of the two-dimensional array
        while(!input_pass){
            cout << "Please enter two integers: ";
            cin >> r >> c;
            if(((r>0)&&(r<100)) && ((c>0)&&(c<100))){
                input_pass = 1;
            }
            else{
                cout << "The integers must be higher than 0, lower than 100." << endl;
            }
        }
        
        //User enter a sequence of numbers, the numbers will be saved in a two-dimensional array
        int arr[r][c];
        for(int i=0; i<r; i++){
            cout << "Please enter " << c << " numbers for row " << i << ": " ;
            for(int j=0; j<c; j++){
                cin >> arr[i][j];
            }
        }

        cout << "Elements that are larger than its neighbors:" << endl;
        //Find the numbers that are larger than their neighbors
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                //If there are any nearby numbers larger than the number, then pass=0
                int num = arr[i][j];
                bool pass = 1;

                if((i!=0)&&pass&&(num < arr[i-1][j])){ //up
                    pass = 0;
                }
                if((i!=r-1)&&pass&&(num < arr[i+1][j])){ //down
                    pass = 0;
                }
                if((j!=0)&&pass&&(num < arr[i][j-1])){ //left
                    pass = 0;
                }
                if((j!=c-1)&&pass&&(num < arr[i][j+1])){ //right
                    pass = 0;
                }

                if(pass){
                    cout << num << endl;
                    pass_nums++;
                }
            }
        }
        cout << "Total: " << pass_nums << " numbers" << endl;

        //User chooses if he/she wants to continue the program
        cout << "Do you want to continue? (y=1/n=0)";
        cin >> con;
        while((con!=0) && (con!=1)){
            cout << "Please enter 1 or 0: ";
            cin >> con;
        }
    }

    return 0;
}