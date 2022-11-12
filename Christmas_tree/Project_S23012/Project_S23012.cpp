#include "engine.h"


using namespace std;

int main()
{
    base::start();
    
    bool workFlag = true;
    while (workFlag)
    {
        if (_kbhit())
        {
            int ch = _getch();
            cout << "Entered" << ch << endl;
            switch (ch)
            {
                //Esc
                case 27: workFlag = false; 
                    break;
                //Enter
                case 13: base::fileOpen();
                    break;
                //1 - increase picture size
                case 49: base::increasePicture(); 
                    break;
                //2 - decrease picture size
                case 50: base::decreasePicture();
                    break;

            }
        }

        string* tree = base::createChristmassTree();

        // Display the Christmass tree
        base::displayChristmassTree(tree);          

        base::fileClose();

        // Wait one second
        Sleep(1000);        
        base::clearConsole();
    }
}