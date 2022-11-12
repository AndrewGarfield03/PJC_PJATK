#include "engine.h"

using namespace std;

HANDLE  hConsole;

enum Colors
{
    BLUE = 1,
    GREEN = 2,
    RED = 4,
    VIOLET = 5,
    YELLOW = 6,
    WHITE = 7,
    BRIGHT_BLUE = 9,
    BRIGHT_GREEN = 10,
    BRIGHT_YELLOW = 14
};

const char SYMBOL_STAR = '*';
const char SYMBOL_GRID = '#';
const char SYMBOL_SPHERE = 'O';
const char SYMBOL_DOG = '@';
const char SYMBOL_PLUS = '+';
const char SYMBOL_PERSENT = '%';
const char SYMBOL_AMPERSAND = '&';


fstream file;

int heigh = 30;
int outputType = 0;
int row = 0;
int column = 0;
int length = 0;
bool flag = false;


void base::start()
{
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    cout << "Keys               Actions            " << endl;
    cout << "--------------------------------------" << endl;
    cout << "1            Increase picture         " << endl;
    cout << "2            Decrease picture         " << endl;
    cout << "Enter        Print picture to the file" << endl;
    cout << "Esc          Exit from program        " << endl;
    cout << endl;
    cout << "Please press any button to start the program..." << endl;
    _getch();
}

void base::writeTo(char symbol)
{
    switch (outputType)
    {
    //Output to console
    case 0: cout << symbol;
        break;
    //Output to the file
    case 1: file << symbol;
        break;
    default:
        break;
    }
}

void base::fileOpen()
{
    cout << "Open file" << endl;
    file.open("results.txt", ios::out);
    if (!file.good())
    {
        cout << "Can't open file results.txt" << endl;
    }
    else
    {
        outputType = 1;
    }
}

void base::fileClose()
{
    if (file.is_open())
    {
        file.close();
        cout << "File has been closed" << endl;
        outputType = 0;
    }
}

string* base::createChristmassTree()
{
    string* arr = new string[heigh];

    //Add the branches
    for (row = 0; row < heigh - 3; row++)
    {
        string wadding(heigh - row + 1, ' ');
        string branch(1 + row * 2, SYMBOL_GRID);
        arr[row] = wadding + branch;
    }

    for (row = 0; row < heigh; row++)
    {
        length = arr[row].length();
        for (column = heigh - row + 1; column < length; column++)
        {
            if (rand() % 6 == 0)
                arr[row].at(column) = SYMBOL_SPHERE;
        }
    }  

    // Randomly add symbol '&'
    for (row = 0; row < heigh; row++)
    {
        length = arr[row].length();
        for (column = heigh - row + 1; column < length; column++)
        {
            if (rand() % 8 == 0)
                arr[row].at(column) = SYMBOL_AMPERSAND;
        }
    }  

    // Randomly add symbol '+' or symbol '@'. Depends on flag value
    for (row = 0; row < heigh; row++)
    {
        length = arr[row].length();
        for (column = heigh - row + 1; column < length; column++)
        {
            if (rand() % 10 == 0)
                arr[row].at(column) = flag ? SYMBOL_PLUS : SYMBOL_DOG;
        }
    }  

    //Add the tree trunk
    for (row = heigh - 3; row < heigh; row++)
    {
        string wadding(heigh - 1, ' ');
        string trunk(5, SYMBOL_PERSENT);
        arr[row] = wadding + trunk;
    }
    //Add the symbol '*' to the top of tree
    arr[0][heigh + 1] = SYMBOL_STAR;

    flag = !flag;
    return arr;
}

void base::displayChristmassTree(std::string* tree)
{
    char currentSymbol;

    for (row = 0; row < heigh; row++)
    {
        length = tree[row].length();

        for (column = 0; column < length; column++)
        {
            currentSymbol = tree[row].at(column);
            //Paint symbols by different colours
            switch (currentSymbol)
            {                
            case SYMBOL_STAR:
                SetConsoleTextAttribute(hConsole, YELLOW);
                break;

            case SYMBOL_GRID:
                SetConsoleTextAttribute(hConsole, BRIGHT_GREEN);
                break;

            case SYMBOL_PERSENT:
                SetConsoleTextAttribute(hConsole, VIOLET);
                break;

            case SYMBOL_AMPERSAND:
                SetConsoleTextAttribute(hConsole, flag ? YELLOW : BRIGHT_YELLOW);
                break;

            case SYMBOL_PLUS:
                SetConsoleTextAttribute(hConsole, YELLOW);
                break;

            case SYMBOL_DOG:
                SetConsoleTextAttribute(hConsole, RED);
                break;

            case SYMBOL_SPHERE:
                SetConsoleTextAttribute(hConsole, flag ? BLUE : RED);
                break;
            }
            // Display symbol
            writeTo(currentSymbol);
        }
        writeTo('\n');
    }
}

void base::increasePicture()
{
    heigh++;
}

void base::decreasePicture()
{
    heigh--;
}

void base::clearConsole()
{
    system("cls");
}
