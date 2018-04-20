#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
using namespace std;
struct creditInfo
{
    int duty=0;
    int creditTime=0;
    double percentageRate=0;
    int instantDuty = 0;
};

struct client
{
    string fName;
    string sName;
    string mName;
    string password;
    unsigned int deposite = 0;
    unsigned int duty = 0;
    unsigned int creditTime = 0;
    unsigned int instantDuty = 0;
    double percentageRate = 0;
    client& operator=(client& seo)
    {
        deposite = seo.deposite;
        duty = seo.duty;
        creditTime = seo.creditTime;
        percentageRate = seo.percentageRate;
        fName = seo.fName;
        sName = seo.sName;
        mName = seo.mName;
        password = seo.password;
    }
};

class processingCenter
{   
private:
    vector <client> people;
public:
    processingCenter() = default;
    void addNew(client seo);
    size_t size();
    void setBio(size_t i, string _fName, string _sName, string _mName);
    void setPassword(size_t i, string _password);
    bool attemptToLogin(size_t i, string _password);
    unsigned int getDeposite(size_t i);
    void depositeAdd(size_t i, unsigned int money);
    void depositeMinus(size_t i, unsigned int money);
    void setDuty(size_t i, unsigned int money);
    unsigned int getDuty(size_t i);
    void minusDuty(size_t i, unsigned int money);
    void setInstantDuty(size_t i, unsigned int money);
    unsigned int getInstantDuty(size_t i);
    void setPercentageRate(size_t i, double rate);
    double getPercentageRate(size_t i);
    void setCreditTime(size_t i, unsigned int mouth);
    unsigned int getCreditTime(size_t i);
    void minusCreditTime(size_t i);
    bool isCreditTaken(size_t i);
};
void processingCenter::addNew(client seo)
{
    people.push_back(seo);
}
size_t processingCenter::size()
{
    return people.size();
}
bool processingCenter::isCreditTaken(size_t i)
{
    return (people[i].duty == 0 && people[i].creditTime == 0 && people[i].instantDuty == 0) ? 0 : 1;
}
void processingCenter::setBio(size_t i, string _fName, string _sName, string _mName)
{
    people[i].fName = _fName;
    people[i].sName = _sName;
    people[i].mName = _mName;
}
void processingCenter::setPassword(size_t i, string _password)
{
    people[i].password = _password;
}
bool processingCenter::attemptToLogin(size_t i, string _password)
{
    return (people[i].password == _password) ? 1 : 0;
}
unsigned int processingCenter::getDeposite(size_t i)
{
    return people[i].deposite;
}
void processingCenter::depositeAdd(size_t i, unsigned int money)
{
    people[i].deposite += money;
}
void processingCenter::depositeMinus(size_t i, unsigned int money)
{
    people[i].deposite -= money;
}
void processingCenter::setDuty(size_t i, unsigned int money)
{
    people[i].duty = money;
}
unsigned int processingCenter::getDuty(size_t i)
{
    return people[i].duty;
}
void processingCenter::minusDuty(size_t i, unsigned int money)
{
    people[i].duty -= money;
}
void processingCenter::setInstantDuty(size_t i, unsigned int money)
{
    people[i].instantDuty = money;
}
unsigned int processingCenter::getInstantDuty(size_t i)
{
    return people[i].instantDuty;
}
void processingCenter::setPercentageRate(size_t i, double rate)
{
    people[i].percentageRate = rate;
}
double processingCenter::getPercentageRate(size_t i)
{
    return people[i].percentageRate;
}
void processingCenter::setCreditTime(size_t i, unsigned int mounth)
{
    people[i].creditTime = mounth;
}
unsigned int processingCenter::getCreditTime(size_t i)
{
    return people[i].creditTime;
}
void processingCenter::minusCreditTime(size_t i)
{
    people[i].creditTime--;
}

class credit
{
private:
    processingCenter clients;
    size_t sessionId;
    bool isSessionActive = 0;
public:
    credit() {}
    void addNew(client _client);
    bool login(short int id, string _password);
    void forcedLogout();
    bool ifSessionActive();
    unsigned int getDeposite();
    bool isCreditAvilable(unsigned int money, unsigned int years);
    double calculatePercent(unsigned int money, unsigned int years);
    bool takeCredit(unsigned int money, unsigned int years);
    bool payOneMonth();
    bool payArrea();
    bool payAllDuty();
    short int size();
    bool isCreditTaken();
    creditInfo getCreditStatus();
    void depositeChange(int money);
};

double credit::calculatePercent(unsigned int money, unsigned int years)
{
    if (!isSessionActive)
        return 0;
    double overValue = 0;
    double percentPerYear = 0;
    switch (years)
    {
    case 1:
        overValue = 1.1;
        break;
    case 2:
        overValue = 1.22;
        break;
    case 3:
        overValue = 1.36;
        break;
    case 5:
        overValue = 1.68;
        break;
    case 15:
        overValue = 3.48;
        break;
    }
    percentPerYear = (overValue - 1) / years;
    if (money <= 999000 && money >= 500000)
        percentPerYear *= 1.03;
    if (money <= 3000000 && money >= 1000000)
        percentPerYear *= 1.08;
    percentPerYear = round(percentPerYear * 1000) / 1000;
    return percentPerYear;
}
unsigned int credit::getDeposite()
{
    if (!isSessionActive)
        return 0;
    return clients.getDeposite(sessionId);
}
bool credit::isCreditAvilable(unsigned int money, unsigned int years)
{
    if (!isSessionActive)
        return 0;
    if (clients.isCreditTaken(sessionId))
        return 0;
    double percent;
    double moneyRequared;
    percent = calculatePercent(money, years);
    moneyRequared = ceil((money + money * percent) / 2);
    if (clients.getDeposite(sessionId) >= moneyRequared)
        return 1;
    else
        return 0;
}
void credit::addNew(client _client)
{
    clients.addNew(_client);
}
bool credit::login(short int _id, string _password)
{
    if (isSessionActive || _id > clients.size())
        return 0;
    if (clients.attemptToLogin(_id - 1, _password))
    {
        isSessionActive = 1;
        return 1;
    }
    else
        return 0;
}
void credit::forcedLogout()
{
    isSessionActive = 0;
    sessionId = 0;
}
bool credit::ifSessionActive()
{
    return isSessionActive;
}
bool credit::takeCredit(unsigned int money, unsigned int years)
{
    if (!isSessionActive || clients.isCreditTaken(sessionId))
        return 0;
    if (money < 100000 || money>3000000)
        return 0;
    if (isCreditAvilable(money, years))
    {
        clients.setPercentageRate(sessionId, calculatePercent(money, years));
        clients.setDuty(sessionId, money);
        clients.setCreditTime(sessionId, years * 12);
        clients.depositeAdd(sessionId, money);
        return 1;
    }
}
bool credit::payOneMonth()
{
    if (!isSessionActive)
        return 0;
    if (!clients.isCreditTaken(sessionId) || clients.getInstantDuty(sessionId))
        return 0;
    unsigned int duty = clients.getDuty(sessionId);
    unsigned int time = clients.getCreditTime(sessionId);
    unsigned int bill = ceil(duty / time);
    unsigned int bill1 = bill;
    bill += ceil(bill * clients.getPercentageRate(sessionId));
    clients.setInstantDuty(sessionId, bill);
    clients.setDuty(sessionId, duty - bill1);
    clients.minusCreditTime(sessionId);
    return 1;
}
bool credit::payArrea()
{
    if (!isSessionActive)
        return 0;
    if (!clients.isCreditTaken(sessionId))
        return 0;
    unsigned int instantDuty = clients.getInstantDuty(sessionId);
    if (instantDuty == 0)
        return 1;
    if (clients.getDeposite(sessionId) >= instantDuty)
    {
        clients.depositeMinus(sessionId, instantDuty);
        clients.setInstantDuty(sessionId, 0);
        if (clients.getCreditTime(sessionId) == 0)
            clients.setPercentageRate(sessionId, 0);
        return 1;
    }
    return 0;
}
bool credit::payAllDuty()
{
    if (!isSessionActive)
        return 0;
    if (!clients.isCreditTaken(sessionId))
        return 0;
    unsigned int duty = ceil(clients.getDuty(sessionId)*1.03) + clients.getInstantDuty(sessionId);
    unsigned int deposite = clients.getDeposite(sessionId);
    if (deposite >= duty)
    {
        clients.depositeMinus(sessionId,duty);
        clients.setDuty(sessionId,0);
        clients.setCreditTime(sessionId,0);
        clients.setPercentageRate(sessionId,0);
        clients.setInstantDuty(sessionId,0);
        return 1;
    }
    return 0;
}
short int credit::size()
{
    return clients.size();
}
bool credit::isCreditTaken()
{
    if (!isSessionActive)
        return 0;
    return clients.isCreditTaken(sessionId);
}
creditInfo credit::getCreditStatus()
{
    creditInfo tmp;
    if (!isSessionActive)
        return tmp; 
    tmp.creditTime = clients.getCreditTime(sessionId);
    tmp.duty = clients.getDuty(sessionId);
    tmp.percentageRate = clients.getPercentageRate(sessionId);
    tmp.instantDuty = clients.getInstantDuty(sessionId);
    return tmp;
}
void credit::depositeChange(int money)
{
    if (!isSessionActive)
        return;
    if (money >= 0)
        clients.depositeAdd(sessionId, money);
    else
        clients.depositeMinus(sessionId, money);
}


int main()
{
    setlocale(LC_ALL, "Russian");   
    credit vtb;
    creditInfo creditTmp;
    processingCenter user;
    client man;
    client jack;
    man.fName = "John";
    man.sName = "Black";
    man.mName = "Oye";
    man.deposite = 100000;
    bool menu1 = 1;
    int cur = 0;
    short int id;
    unsigned int years;
    unsigned int money;
    int depositeChange;
    string tmp;
    cout << "Пожалуйста, зарегестрируйтесь\nПридумайте пароль: ";
    cin >> man.password;
    vtb.addNew(man);
    cout << "\nВаш id: " << vtb.size();
    system("pause");
    while (menu1)
    {
        system("cls");
        cout << "1.Войти\n"
            << "2.Зарегестрироваться\n"
            << "3.Возможные кредиты\n"
            << "4.Проверить наличие кредита\n"
            << "5.Проверить возможность взятия определенного кредита\n"
            << "6.Взять кредит\n"
            << "7.Информация по кредиту\n"
            << "8.Количество денег на зарплатном счету\n"
            << "9.Изменить количество  денег на счету (тестовая функция) \n"
            << "10.Сделать начисления по кредиту\n"
            << "11.Погасить начисления по кредиту\n"
            << "12.Досрочно погасить кредит (весь долг + 3%)\n"
            << "13.Выйти из аккаунта\n"
            << "14.Выход\n";
        cin >> cur;
        cout << endl;
        switch (cur)
        {
        case 1:
            cout << "Введите id и пароль:";
            cin >> id >> tmp;
            if (vtb.login(id, tmp))
                cout << "\nВход выполнен!";
            else
                cout << "\nЧто-то пошло не так!";
            break;
        case 2:
            cout << "Придумайте пароль: ";
            cin >> jack.password;
            vtb.addNew(jack);
            cout << "\nВаш id: " << vtb.size();
            break;
        case 3:
            if (!vtb.ifSessionActive())
            {
                cout << "Вход не выполнен";
                break;
            }
            for (int i = 100000; i <= 3000000; i += 100000)
            {
                if (vtb.isCreditAvilable(i, 1))
                    cout << "Возможен кредит на " << i << " рублей. " << " 1 год, " << vtb.calculatePercent(i, 1)*100 << "% годовых\n";
                if (vtb.isCreditAvilable(i, 2))
                    cout << "Возможен кредит на " << i << " рублей. " << " 2 годa, " << vtb.calculatePercent(i, 2) * 100 << "% годовых\n";
                if (vtb.isCreditAvilable(i, 3))
                    cout << "Возможен кредит на " << i << " рублей. " << " 3 годa, " << vtb.calculatePercent(i, 3) * 100 << "% годовых\n";
                if (vtb.isCreditAvilable(i, 5))
                    cout << "Возможен кредит на " << i << " рублей. " << " 5 лет, " << vtb.calculatePercent(i, 5) * 100 << "% годовых\n";
                if (vtb.isCreditAvilable(i, 15))
                    cout << "Возможен кредит на " << i << " рублей. " << " 15 лет, " << vtb.calculatePercent(i, 15) * 100 << "% годовых\n";
            }
            break;
        case 4:
            if (!vtb.ifSessionActive())
            {
            cout << "Вход не выполнен";
            break;
            }
            creditTmp = vtb.getCreditStatus();
            if (!vtb.isCreditTaken())
                cout << "Кредит не взят";
            else
                cout << "Кредит взят";
            break;
        case 5:
            if (!vtb.ifSessionActive())
            {
                cout << "Вход не выполнен";
                break;
            }
            cout << "Введите желаемый срок (1,2,3,5,15 лет) и размер кредита: ";
            cin >> years >> money;
            if(vtb.isCreditAvilable(money, years))
                cout << "\nВы можете взять этот кредит";
            else 
                cout << "\nВы не можете взять этот кредит)";
            break;
        case 6:
            if (!vtb.ifSessionActive())
            {
                cout << "Вход не выполнен";
                break;
            }
            cout << "Введите желаемый срок (1,2,3,5,15 лет) и размер кредита: ";
            cin >> years >> money;
            if (vtb.takeCredit(money, years))
                cout << "Кредит взят";
            else
                cout << "Кредит не может быть взят";
            break;
        case 7:
            if (!vtb.ifSessionActive())
            {
                cout << "Вход не выполнен";
                break;
            }
            creditTmp = vtb.getCreditStatus();
            cout << "Оставшееся время кредита --- " << creditTmp.creditTime / 12 << " лет " << creditTmp.creditTime % 12 << " месяцев";
            cout << "\nОставшееся задолженность --- " << creditTmp.duty;
            cout << "\nНачисления по кредиту --- " << creditTmp.instantDuty;
            cout << "\nПроцентная ставка кредита --- " << creditTmp.percentageRate * 100 << " %";
            break;
        case 8:
            if (!vtb.ifSessionActive())
            {
                cout << "Вход не выполнен";
                break;
            }
            cout << "\n" << vtb.getDeposite() << " рублей";
            break;
        case 9:
            if (!vtb.ifSessionActive())
            {
                cout << "Вход не выполнен";
                break;
            }
            cout << "Введите количество денег для начисления (положительное - прибававится, отрицательное - вычитается) : ";
            cin >> money;
            vtb.depositeChange(money);
            break;
        case 10:
            if (vtb.payOneMonth())
                cout << "Начисления сделаны!";
            else
                cout << "Ошибка...";
            break;
        case 11:
            if (vtb.payArrea())
                cout << "Сделано!";
            else
                cout << "Ошибка...";
            break;
        case 12:
            if (vtb.payAllDuty())
                cout << "Сделано!";
            else
                cout << "Ошибка...";
            break;
        case 13:
            vtb.forcedLogout();
            break;
        case 14:
            menu1 = 0;
            break;
        }
        cout << endl;
        system("pause");
    }
    return 0;
}