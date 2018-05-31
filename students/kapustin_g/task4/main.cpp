#include <iostream>
#include <string>
#include <fstream>
#include <locale>
#include <vector>
#include <fcntl.h>
#include <algorithm>
#include <wchar.h>
#include <Windows.h>
#include <conio.h>
using namespace std;

#define darrow 80
#define uparrow 72
#define enter 13
#define esc 27
#define space 32
#define delete 224

class info
{
private:
    wstring fName;
    wstring sName;
    wstring mName;
    wstring birthDay;
    wstring phnum;
public:
    info() = default;
    info(wstring _fName, wstring _sName, wstring _mName, wstring _birthDay, wstring _phnum);
    info(wstring _birthDay, wstring _phnum) :
        birthDay(_birthDay), phnum(_phnum) {}
    void setInfo(info _m);
    void setStrings(wstring _fMame, wstring _sName, wstring _mName, wstring _birthDay, wstring _phnum);
    void setNames(wstring _fName, wstring _sName, wstring _mName);
    void setBirthDay(wstring _birthDay);
    void setNum(wstring _num);
    void setFName(wstring _fName);
    void setSName(wstring _sName);
    void setMName(wstring _mName);
    wstring getFName();
    wstring getSName();
    wstring getMName();
    wstring getNum();
    wstring getBirthDay();
    bool find(wstring input);
    bool findByFirstLetter(wchar_t input);
    friend wostream& operator<<(wostream& os, const info& dt);
    friend wistream& operator>>(wistream& is, info& dt);
    info& operator=(const info& v)
    {
        fName = v.fName;
        sName = v.sName;
        mName = v.mName;
        birthDay = v.birthDay;
        phnum = v.phnum;
        return *this;
    }
};

wostream& operator<<(wostream& os, const info& dt)
{
    os << dt.fName << ' ' << dt.sName << ' ' << dt.mName << ' ' << dt.phnum << ' ' << dt.birthDay;
    return os;
}
wistream& operator>>(wistream& is, info& dt)
{
    is >> dt.fName >> dt.sName >> dt.mName >> dt.phnum >> dt.birthDay;
    return is;
}
info::info(wstring _fName, wstring _sName, wstring _mName, wstring _birthDay, wstring _phnum):
    fName(_fName), sName(_sName), mName(_mName), birthDay(_birthDay), phnum(_phnum) {}
void info::setNames(wstring _fName, wstring _sName, wstring _mName)
{
    fName = _fName;
    sName = _sName;
    mName = _mName;
}
void info::setInfo(info _m)
{
    fName = _m.fName;
    sName = _m.sName;
    mName = _m.mName;
    birthDay = _m.birthDay;
    phnum = _m.phnum;
}
void info::setStrings(wstring _fName, wstring _sName, wstring _mName, wstring _birthDay, wstring _phnum)
{
    fName = _fName;
    sName = _sName;
    mName = _mName;
    birthDay = _birthDay;
    phnum = _phnum;
}
wstring info::getFName()
{
    return fName;
}
wstring info::getSName()
{
    return sName;
}
wstring info::getMName()
{
    return mName;
}
void info::setBirthDay(wstring _birthDay)
{
    birthDay = _birthDay;
}
void info::setNum(wstring _phnum)
{
    phnum = _phnum;
}
wstring info::getNum()
{
    return phnum;
}
wstring info::getBirthDay()
{
    return birthDay;
}
void info::setFName(wstring _fName)
{
    fName = _fName;
}
void info::setSName(wstring _sName)
{
    sName = _sName;
}
void info::setMName(wstring _mName)
{
    mName = _mName;
}
bool info::find(wstring input)
{
    if (fName.find(input) != -1 || sName.find(input) != -1 || mName.find(input) != -1 || phnum.find(input) != -1)
        return 1;
    else return 0;
}
bool info::findByFirstLetter(wchar_t input)
{
    if (fName[0] == input || sName[0] == input || mName[0] == input)
        return 1;
    return 0;
}
bool operator<(info &lhs, info &rhs)
{
    if (lhs.getFName() == rhs.getFName())
        if (lhs.getSName() == rhs.getSName())
            return lhs.getMName() < rhs.getMName();
        else
            return lhs.getSName() < rhs.getSName();
    else
        return lhs.getFName() < rhs.getFName();
}

class contacts
{
private:
    pair < vector <info>, vector <bool> > ppl; // пара векторов: информация о контакте, bool признак избран ли контакт
    bool notempty = 0;                         // 0 - класс не содержит в себе информации, 1 - содержит
public:
    contacts() = default;
    void createNew(info _ppl);
    void del(int id);
    void changeInfo(info _ppl, int id);
    void favourit(int id, bool i);
    bool isFavourit(int id);
    vector <int> getAllFavourit();
    vector <int> find(wstring str);
    vector <int> findByFirstLetter(wchar_t input);
    int size();
    info getInfo(int id);
    bool ifEmpty();
    bool save();
    bool read();
};

bool contacts::ifEmpty()
{
    return notempty;
}
void contacts::createNew(info _ppl)
{
    if (!notempty && !ppl.first.empty()) // 0 элементов в классе означает, что контейнеры хранят одно пустое значение
    {                                    // и notrempty = 0
        ppl.first[0].setInfo(_ppl);
        notempty = 1;
        return;
    }
    ppl.first.push_back(_ppl);
    ppl.second.push_back(0);
    sort(ppl.first.begin(), ppl.first.end());
    notempty = 1;
}
void contacts::changeInfo(info _ppl, int id)
{
    if ((!notempty) && id == 0)
        notempty = 1;
    ppl.first[id] = _ppl;
    sort(ppl.first.begin(), ppl.first.end());
}
vector <int> contacts::find(wstring str)
{
    vector <int> matchesId;
    for (int i = 0; i < ppl.first.size(); i++)
    {
        if (ppl.first[i].find(str))
            matchesId.push_back(i);
    }
    return matchesId;
}
vector <int> contacts::findByFirstLetter(wchar_t input)
{
    vector <int> matchesId;
    for (int i = 0; i < ppl.first.size(); i++)
    {
        if (ppl.first[i].findByFirstLetter(input))
            matchesId.push_back(i);
    }
    return matchesId;
}
int contacts::size()
{
    if (!notempty)
        return 0;
    return ppl.first.size();
}
void contacts::favourit(int id, bool i)
{
    ppl.second[id] = i;
}
bool contacts::isFavourit(int id)
{
    return ppl.second[id];
}
vector <int> contacts::getAllFavourit()
{
    vector <int> matchesId;
    for (int i = 0; i < ppl.first.size(); i++)
        if (ppl.second[i])
            matchesId.push_back(i);
    return matchesId;
}
void contacts::del(int id)
{
    if (id != (ppl.first.size() - 1))
        for (int i = id; i < ppl.first.size() - 1; i++)
        {
            ppl.first[i] = ppl.first[i + 1];
            ppl.second[i] = ppl.second[i + 1];
        }
    if (ppl.first.size() == 1)
    {
        ppl.first[0].setStrings(L"", L"", L"", L"", L""); // установка пустых строк
        ppl.second[0] = 0;
        notempty = 0;
        return;
    }
    ppl.first.pop_back();
    ppl.second.pop_back();
}
bool contacts::save()
{
    wofstream file(L"contacts.txt");
    if (!file)
    {
        file.close();
        return 0;
    }
    file.imbue(std::locale("rus_rus.1251"));
    if (!notempty)
    {
        file << L"empty";
        return 1;
    }
    for (int i = 0; i < ppl.first.size(); i++)
    {
        file << ppl.first[i] << L" " << ppl.second[i] << "\n";
    }
    file << L"end";
    file.close();
    return 1;
}
bool contacts::read()
{
    wifstream file(L"contacts.txt");
    if (!file)
        return 0;
    ppl.first.erase(ppl.first.begin(), ppl.first.end());
    ppl.second.erase(ppl.second.begin(), ppl.second.end());
    info buff1;
    bool buff2;
    file.imbue(std::locale("rus_rus.1251"));
    while (true)
    {
        file >> buff1;
        if (buff1.getFName() == L"end")
            break;
        if (buff1.getFName() == L"empty")
        {
            notempty = 0;
            break;
        }
        createNew(buff1);
        file >> buff2;
        ppl.second[ppl.second.size() - 1] = buff2;
    }
    file.close();
    return 1;
}
info contacts::getInfo(int id)
{
    return ppl.first[id];
}

int main()
{
    SetConsoleCP(866);
    SetConsoleOutputCP(866);

    wcout << L"\n\n\n\t\t\tНавигация по программе осуществляется стрелками вверх вниз, esc и enter";
    _getch();
    contacts m;
    info tmp(L"Людвиг", L"Бетховен", L"Иоганнович", L"16.1770", L"+71212462");
    m.createNew(tmp);
    tmp.setStrings(L"Альберт", L"Эйнштейн", L"Германович", L"14.03.1879", L"012725(3)");
    m.createNew(tmp);
    tmp.setStrings(L"Эдгар", L"Аллан", L"По", L"19.01.1809", L"41(835)18822");
    m.createNew(tmp);
    tmp.setStrings(L"Дайенерис", L"Таргариен", L"Матерьдраконов", L"289", L"51(63)860-8477");
    m.createNew(tmp);
    tmp.setStrings(L"Джейме", L"Ланнистер", L"Цареубийца", L"260", L"9(27)802-9155");
    m.createNew(tmp);
    vector <int> find;
    vector <int> chosen;
    wstring fname;
    wstring sname;
    wstring mname;
    int cursorpos = -1;
    int cursorpos2 = 0;
    int i;
    bool menu1 = 1;
    bool menu2 = 1;
    while (menu1)
    {
        bool menu2 = 1;
        Sleep(40);
        system("cls");
        wcout << L"\n\n\n\t\t\tMENU";
        if (cursorpos == -1)
            wcout << L"<-";
        wcout << endl;
        for (int i = 0; i < m.size(); i++)
        {
            wcout << L"\t\t\t";
            tmp = m.getInfo(i);
            wcout << tmp.getFName() << L" "
                << tmp.getSName() << L" "
                << tmp.getMName();
            if (m.isFavourit(i))
                wcout << L" FAV ";
            if (cursorpos == i)
            {
                wcout << L"<-" << endl;
                wcout << L"\t\t\t" << tmp.getNum() << endl;
            }
            else
                wcout << endl;
        }
        wcout << L"\n\t\t\t" << m.size() << L" contacts" << endl;
        i = _getch();
        switch (i)
        {
        case darrow:
            if (!(m.ifEmpty()))
            {
                cursorpos = -1;
                break;
            }
            cursorpos++;
            if (cursorpos > m.size() - 1)
                cursorpos = -1;
            break;
        case uparrow:
            if (!(m.ifEmpty()))
            {
                cursorpos = -1;
                break;
            }
            cursorpos--;
            if (cursorpos < -1)
                cursorpos = m.size() - 1;
            break;
        case esc:
            menu1 = 0;
            break;
        case enter:
            if (cursorpos == -1)
            {
                while (menu2)
                {
                    Sleep(40);
                    system("cls");
                    wcout << L"\n\n\n\t\t\tSearch by full name or ph number";
                    if (cursorpos2 == 0)
                        wcout << L"<-";
                    wcout << endl;
                    wcout << L"\t\t\tSearch by first letter in full name";
                    if (cursorpos2 == 1)
                        wcout << L"<-";
                    wcout << endl;
                    wcout << L"\t\t\tAdd new contact";
                    if (cursorpos2 == 2)
                        wcout << L"<-";
                    wcout << endl;
                    wcout << L"\t\t\tLoad from file";
                    if (cursorpos2 == 3)
                        wcout << L"<-";
                    wcout << endl;
                    wcout << L"\t\t\tSave to file";
                    if (cursorpos2 == 4)
                        wcout << L"<-";
                    wcout << endl;
                    wcout << L"\t\t\tShow all chosen contacts";
                    if (cursorpos2 == 5)
                        wcout << L"<-";
                    wcout << endl;
                    i = _getch();
                    switch (i)
                    {
                    case darrow:
                        cursorpos2++;
                        if (cursorpos2 > 5)
                            cursorpos2 = 0;
                        break;
                    case uparrow:
                        cursorpos2--;
                        if (cursorpos2 < 0)
                            cursorpos2 = 5;
                        break;
                    case enter:
                        switch (cursorpos2)
                        {
                        case 0:
                            system("cls");
                            wcout << L"\n\n\n\t\t\tPlease, input:";
                            wcout << L"\n\t\t\t";
                            wcin >> fname;
                            wcout << endl;
                            find = m.find(fname);
                            for (int i = 0; i < find.size(); i++)
                            {
                                wcout << L"\t\t\t";
                                tmp = m.getInfo(find[i]);
                                wcout << tmp.getFName() << L" "
                                    << tmp.getSName() << L" "
                                    << tmp.getMName() << L" "
                                    << tmp.getNum() << endl;
                            }
                            wcout << endl;
                            _getch();
                            break;
                        case 1:
                            system("cls");
                            wcout << L"\n\n\n\t\t\tPlease input one character:";
                            wcout << L"\n\t\t\t";
                            wchar_t buf;
                            wcin >> buf;
                            wcout << endl;
                            find = m.findByFirstLetter(buf);
                            for (int i = 0; i < find.size(); i++)
                            {
                                wcout << L"\t\t\t";
                                tmp = m.getInfo(find[i]);
                                wcout << tmp.getFName() << L" "
                                    << tmp.getSName() << L" "
                                    << tmp.getMName() << endl;
                            }
                            wcout << endl;
                            _getch();
                            break;
                        case 2:
                            wcout << L"\n\t\t\t";
                            wcout << L"Name:";
                            wcin >> fname;
                            tmp.setFName(fname);
                            wcout << L"\n\t\t\t";
                            wcout << L"Second name:";
                            wcin >> fname;
                            tmp.setSName(fname);
                            wcout << L"\n\t\t\t";
                            wcout << L"Middle name:";
                            wcin >> fname;
                            tmp.setMName(fname);
                            wcout << L"\n\t\t\t";
                            wcout << L"Birth date:";
                            wcin >> fname;
                            tmp.setBirthDay(fname);
                            wcout << L"\n\t\t\t";
                            wcout << L"Ph number:";
                            wcin >> fname;
                            tmp.setNum(fname);
                            m.createNew(tmp);
                            break;
                        case 3:
                            if (m.read())
                                wcout << "Everything is done!";
                            else
                                wcout << L"Oops something went wrong..";
                            _getch();
                            break;
                        case 4:
                            if (m.save())
                                wcout << L"Everything is done!";
                            else
                                wcout << L"Oops something went wrong..";
                            _getch();
                            break;
                        case 5:
                            system("cls");
                            wcout << L"\n\n\n\t\t\tFavourite contacts:" << endl;
                            chosen = m.getAllFavourit();
                            for (int i = 0; i < chosen.size(); i++)
                            {
                                wcout << L"\t\t\t";
                                tmp = m.getInfo(chosen[i]);
                                wcout << tmp.getFName() << L" "
                                    << tmp.getSName() << L" "
                                    << tmp.getMName() << endl;
                            }
                            wcout << endl;
                            _getch();
                            break;
                        }
                        break;
                    case esc:
                        cursorpos2 = 0;
                        menu2 = 0;
                        break;
                    }
                }
                break;
            }
            system("cls");
            wcout << L"\n\n\n\t\t\t";
            wcout << L"Info:" << endl;
            wcout << L"\t\t\t";
            tmp = m.getInfo(cursorpos);
            wcout << tmp.getFName() << L" "
                << tmp.getSName() << L" "
                << tmp.getMName() << L" "
                << endl;
            wcout << L"\t\t\tBirth date: "
                << tmp.getBirthDay() << endl;
            wcout << L"\t\t\tPhone number: "
                << tmp.getNum() << L"\n\n\n\t\t\t";
            wcout << L"Press enter to favour contact\n\t\t\tEsc to unfavour\n\t\t\tSpace to edit\n\t\t\tDel to delete this item";
            i = _getch();
            bool ch = 0;
            switch (i)
            {
            case enter:
                ch = 1;
                m.favourit(cursorpos, ch);
                break;
            case esc:
                ch = 0;
                m.favourit(cursorpos, ch);
                break;
            case space:
                wcout << L"\n\t\t\t";
                wcout << L"Name:";
                wcin >> fname;
                tmp.setFName(fname);
                wcout << L"\n\t\t\t";
                wcout << L"Second name:";
                wcin >> fname;
                tmp.setSName(fname);
                wcout << L"\n\t\t\t";
                wcout << L"Middle name:";
                wcin >> fname;
                tmp.setMName(fname);
                wcout << L"\n\t\t\t";
                wcout << L"Birth date:";
                wcin >> fname;
                tmp.setBirthDay(fname);
                wcout << L"\n\t\t\t";
                wcout << L"Ph number:";
                wcin >> fname;
                tmp.setNum(fname);
                m.changeInfo(tmp, cursorpos);
                break;
            case delete:
                m.del(cursorpos );
                if (cursorpos == m.size())
                    cursorpos--;
                break;
            }
            break;
        }
    }
    return 0;

}