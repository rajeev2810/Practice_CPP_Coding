#include <iostream>
#include <vector>
#include <time.h>
#include <sys/types.h>
#include <sys/timeb.h>
#include <string.h>

using namespace std;

/*************************Example 1********************************/
class Subject;

class Observer
{
public:
    Observer() {};
    ~Observer() {};
    virtual void Update(Subject* theChangeSubject) = 0;
};

class Subject
{
public:
    Subject() {};
    virtual ~Subject() {};
    virtual void Attach(Observer*);
    virtual void Detach(Observer*);
    virtual void Notify();
private:
    vector<Observer*> _observers;
};

void Subject::Attach(Observer* o)
{
    _observers.push_back(o);
}

void Subject::Detach(Observer* o)
{
    int count = _observers.size();
    int i;

    for (i = 0; i < count; i++) {
        if (_observers[i] == o)
            break;
    }
    if (i < count)
        _observers.erase(_observers.begin() + i);

}

void Subject::Notify()
{
    int count = _observers.size();

    for (int i = 0; i < count; i++)
        (_observers[i])->Update(this);
}

class ClockTimer : public Subject
{
public:
    ClockTimer() { _strtime_s(tmpbuf); };
    int GetHour();
    int GetMinute();
    int GetSecond();
    void Tick();
private:
    char tmpbuf[128];
};

/* Set time zone from TZ environment variable. If TZ is not set,
 * the operating system is queried to obtain the default value
 * for the variable.
*/
void ClockTimer::Tick()
{
    _tzset();

    // Obtain operating system-style time. 
    _strtime_s(tmpbuf);
    Notify();
}

int ClockTimer::GetHour()
{
    char timebuf[128];
    strncpy_s(timebuf, tmpbuf, 2);
    timebuf[2] = NULL;

    return atoi(timebuf);
}

int ClockTimer::GetMinute()
{
    char timebuf[128];
    strncpy_s(timebuf, tmpbuf + 3, 2);
    timebuf[2] = NULL;

    return atoi(timebuf);
}

int ClockTimer::GetSecond()
{
    char timebuf[128];
    strncpy_s(timebuf, tmpbuf + 6, 2);
    timebuf[2] = NULL;

    return atoi(timebuf);
}


class DigitalClock : public Observer
{
public:
    DigitalClock(ClockTimer*);
    ~DigitalClock();
    void Update(Subject*);
    void Draw();
private:
    ClockTimer* _subject;
};

DigitalClock::DigitalClock(ClockTimer* s)
{
    _subject = s;
    _subject->Attach(this);
}

DigitalClock::~DigitalClock()
{
    _subject->Detach(this);
}

void DigitalClock::Update(Subject* theChangedSubject)
{
    if (theChangedSubject == _subject)
        Draw();
}

void DigitalClock::Draw()
{
    int hour = _subject->GetHour();
    int minute = _subject->GetMinute();
    int second = _subject->GetSecond();

    cout << "Digital time is " << hour << ":"
        << minute << ":"
        << second << endl;
}

class AnalogClock : public Observer
{
public:
    AnalogClock(ClockTimer*);
    ~AnalogClock();
    void Update(Subject*);
    void Draw();
private:
    ClockTimer* _subject;
};

AnalogClock::AnalogClock(ClockTimer* s)
{
    _subject = s;
    _subject->Attach(this);
}

AnalogClock::~AnalogClock()
{
    _subject->Detach(this);
}

void AnalogClock::Update(Subject* theChangedSubject)
{
    if (theChangedSubject == _subject)
        Draw();
}

void AnalogClock::Draw()
{
    int hour = _subject->GetHour();
    int minute = _subject->GetMinute();
    int second = _subject->GetSecond();

    cout << "Analog time is " << hour << ":"
        << minute << ":"
        << second << endl;
}

/*************************Example 2********************************
The important point to notice is that the MySubject class has not compile - time dependency on the MyObserver class.
The relationship between the two classes is dynamically created at run time.
*******************************************************************/
class ObserverInterface
{
public:
    virtual ~ObserverInterface() {}
    virtual void update(int message) = 0;
};

class SubjectInterface
{
public:
    virtual ~SubjectInterface();
    virtual void subscribe(ObserverInterface*);
    virtual void unsubscribe(ObserverInterface*);
    virtual void notify(int message);
private:
    std::vector<ObserverInterface*> mObservers;
};

SubjectInterface::~SubjectInterface()
{}

void SubjectInterface::subscribe(ObserverInterface* observer)
{
    mObservers.push_back(observer);
}

void SubjectInterface::unsubscribe(ObserverInterface* observer)
{
    int count = mObservers.size();
    int i;

    for (i = 0; i < count; i++) {
        if (mObservers[i] == 0)
            break;
    }
    if (i < count)
        mObservers.erase(mObservers.begin() + i);
}

void SubjectInterface::notify(int msg)
{
    int count = mObservers.size();

    for (int i = 0; i < count; i++)
        (mObservers[i])->update(msg);
}

class MySubject : public SubjectInterface
{
public:
    enum Message { ADD, REMOVE };
};

class MyObserver : public ObserverInterface
{
public:
    explicit MyObserver(const std::string& str) : name(str) {}
    void update(int message)
    {
        std::cout << name << " Got message " << message << std::endl;
    }
private:
    std::string name;
};

int main(void)
{
    ClockTimer timer;

    DigitalClock digitalClock(&timer);
    AnalogClock analogClock(&timer);

    timer.Tick();

    MyObserver observerA("observerA");
    MyObserver observerB("observerB");
    MyObserver observerC("observerC");

    MySubject subject;
    subject.subscribe(&observerA);
    subject.subscribe(&observerB);
    subject.unsubscribe(&observerB);
    subject.subscribe(&observerC);

    subject.notify(MySubject::ADD);
    subject.notify(MySubject::REMOVE);

    return 0;
}
/**************************************************************************
The calls to subject.notify() cause the subject to traverse its list of observers that have been subscribed and the call to(mObservers[i])->update(msg) method for each of them.
There may be a small performance hit due to iterating through a list of observers before making the virtual function call.
However, the cost is minimal when compared to the benefits of reduced coupling and increased code reuse.
**************************************************************************/