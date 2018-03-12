#include <iostream>
#include <conio.h>
#include <string>
#include <locale>
#include <windows.h>

#define BACKSPACE '\b'
#define ENTER '\r'
#define EMPTY '\0'
#define SPACE 32
#define ESC 27

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

class textEditor
{
private:
    string line;
    COORD position;
    size_t len;
public:
    textEditor(size_t _len = 0, short _x = 1, short _y = 1) :
        len(_len)
    {
        position.X = _x;
        position.Y = _y;
    }
    textEditor(COORD _position) :
        position(_position)
    {
        len = 0;
    }
    textEditor(textEditor& m):
        len(m.len),line(m.line),position(m.position)
    {
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
    void setPosition(short _x, short _y)
    {
        position.X = _x;
        position.Y = _y;
    }
    void setPosition(COORD p)
    {
        position = p;
    }
    void putCursor()
    {
        SetConsoleCursorPosition(hConsole, position);
    }
    void main()
    {
        if (len == 0)
        {
            cout << "Error, length = 0 ";
            _getch();
            return;
        }
        string backup = line;
        char type;
        line.erase();
        for (int i = 0; i != -1; )
        {
            type = _getch();
            switch (type)
            {
            case BACKSPACE:
                if (i) //проверка на ненулевую строку, чтобы не удалось удалить элементы из пустой строки
                {
                    i--;
                    line.pop_back();
                    cout << BACKSPACE << EMPTY << BACKSPACE;
                }
                break;
            case ESC:
                line = backup;
            case ENTER: 
                i = -1;
                break;
            default:
                if (i == len) //если достигнут максимум длины, то блокируется возможноть добавлять символы
                    break;
                i++;
                line += type;
                cout << type;
                break;
            }
        }
    }
    void setLen(unsigned _len)
    {
        len = _len;
        for (size_t i = size(line); i > len; i--) //если новый размер меньше, то строка уменьшится 
            line.pop_back();
    }
};

int main()
{
    int tmp;
    COORD coord;
    string buf;
    bool menu = 1;
    bool isCursorPut = 0;
    textEditor m(0, 10, 10);

    while (menu)
    {
        system("cls");
        cout << "Put cursor: ";
        if (isCursorPut)
            cout << "ON" << endl;
        else
            cout << "OFF" << endl;
        cout << "Run Text Editor \t\t---1" << endl;
        cout << "Toggle PutCursor\t\t---2" << endl;
        cout << "Show line       \t\t---3" << endl;
        cout << "Show length     \t\t---4" << endl;
        cout << "Show pos        \t\t---5" << endl;
        cout << "Set new length \t\t\t---6" << endl;
        cout << "Set new pos     \t\t---7" << endl;
        cout << "Exit            \t\t---8" << endl;
        cin >> tmp;
        switch (tmp)
        {
        case 1:
            if(isCursorPut)
                m.putCursor();
            m.main();
            
            break;
        case 2:
            isCursorPut = !isCursorPut; // сменить переключатель на противоположный знак
            break;
        case 3:
            if (isCursorPut)
                m.putCursor();
            cout << m.getLine();
            _getch();
            break;
        case 4:
            cout << m.getLength();
            _getch();
            break;
        case 5:
            cout << "(" << m.getX() << "," << m.getY() << ")";
            _getch();
            break;
        case 6:
            cin >> tmp;
            m.setLen(tmp);
            break;
        case 7:
            cin >> coord.X >> coord.Y;
            m.setPosition(coord);
            break;
        case 8:
            menu = 0;
            break;
        }
    }
    return 0;
}