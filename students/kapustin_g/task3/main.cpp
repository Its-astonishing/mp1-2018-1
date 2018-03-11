#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

class textEditor
{
private:
    string line;
    COORD position;
    size_t len;
public:
    textEditor(size_t _len=0, short _x = 1, short _y = 1):
        len(_len)
    {
        position.X = _x;
        position.Y = _y;
    }
    textEditor(COORD _position):
        position(_position) 
    {
    }
    textEditor(textEditor& m)
    {
        line = m.line;
        len = size(line);
    }
    string getLine()
    {
        return line;
    }
    size_t getLength()
    {
        return len;
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
    void setCursor(short _x, short _y)
    {
        position.X = _x;
        position.Y = _y;
    }
    void setCursorCoord(COORD p)
    {
        position = p;
    }
    void putCursor()
    {
        SetConsoleCursorPosition(hConsole, position);
    }
    void writeLine(string _line)
    {
        line = _line;
        len = size(line);
    }
    void writeTillLen(string _line) //записать в поле ввода символов не больше, чем задано в длине поля
    {
            line = _line;
            for (size_t i = size(line); i > len; i--)
                line.pop_back();
    }
    void setLen(unsigned _len)
    {
        len = _len;
            for (size_t i = size(line); i > len; i--)
                line.pop_back();
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    int tmp;
    COORD coord;
    string buf;
    bool menu=1;
    textEditor m(0,10,10);
    while (menu)
    {
        system("cls");
        cout << "Установить координаты(x,y)  \t\t\t\t---1" << endl
            << "Ввести текст                 \t\t\t\t---2" << endl
            << "Ввести текст (не больше заданной длины)\t\t\t---3" << endl
            << "Установить новую длину       \t\t\t\t---4" << endl
            << "Показать текст               \t\t\t\t---5" << endl
            << "Показать позицию             \t\t\t\t---6" << endl
            << "Показать длину               \t\t\t\t---7" << endl
            << "Выход                        \t\t\t\t---8" << endl;
        cin >> tmp;
        switch (tmp)
        {
        case 1:
            cin >> coord.X >> coord.Y;
            m.setCursorCoord(coord);
            break;
        case 2:
            m.putCursor();
            cin.ignore();
            getline(cin, buf);
            m.writeLine(buf);
            break;
        case 3:
            m.putCursor();
            cin.ignore();
            getline(cin, buf);
            m.writeTillLen(buf); 
            break;
        case 4:
            cin >> tmp;
            m.setLen(tmp);
            break;
        case 5:
            m.putCursor();
            cout << m.getLine();
            _getch();
            break;
        case 6:
            cout << "(" << m.getX() << "," << m.getY() << ")";
            _getch();
            break;
        case 7:
            cout << m.getLength();
            _getch();
            break;
        case 8:
            menu = 0;
            break;
        }
    }
    return 0;
}