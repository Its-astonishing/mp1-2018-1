#include <iostream>
#include <windows.h>
using namespace std;

class textEditor
{
private:
    char *string;
    int length;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position;
public:
    textEditor(int _length, short _x, short _y):
        length(_length)
    {
        position.X = _x;
        position.Y = _y;
        string = new char[length];
    }
    ~textEditor()
    {
        delete string;
    }
    char *getString()
    {
        return string;
    }
    void setLength(int _length)
    {
        length = _length;
    }
    int getLength()
    {
        return length;
    }
    void setCursor(short _x, short _y)
    {
        position.X = _x;
        position.Y = _y;
    }
    void putCursor()
    {
        SetConsoleCursorPosition(hConsole, position);
    }
    void write()
    {
        putCursor();
        cin >> string;
    }
    COORD getPos()
    {
        return position;
    }
    short getX() 
    {
        return position.X;
    }
    short getY()
    {
        return position.Y;
    }
    friend ostream& operator<<(ostream& os, const textEditor & dt);
};
ostream& operator<<(ostream& os, const textEditor & dt)
{
    os << dt.string;
    return os;
}
int main()
{
    bool menu;
    textEditor m(10,15,15);
   /* do
    {
        system("cls");
        cout << "Set positiont\t\t\t---1"
            << "Input text\t\t\t---2"
            << "Show textt\t\t\t---3"
            << "Get positiont\t\t\t---4";


    } while (menu); */
    m.putCursor();
    m.write();
    system("cls");
    m.putCursor();
    cout << m;
    system("pause");
    return 0;
}
/*HANDLE hConsole1 = GetStdHandle(STD_OUTPUT_HANDLE);
COORD position1;
position1.X = 10;
position1.Y = 10;
SetConsoleCursorPosition(hConsole1, position1);*/