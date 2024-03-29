#include <iostream>

using namespace std;

class Button
{
public:
	virtual void Paint() = 0;
};

class WinButton : public Button {
public:
	void Paint()
	{
		cout << "Win Button" << endl;
	}
};

class MacButton : public Button
{
public:
	void Paint()
	{
		cout << "Mac Button" <<endl;
	}
};

class Factory
{
public:
	virtual Button* createButton() = 0;
};

class WinFactory :public Factory
{
public:
	Button* createButton()
	{
		return new WinButton();
	}
};

class MacFactory :public Factory
{
public:
	Button* createButton()
	{
		return new MacButton();
	}
};

int main()
{
	Factory* f;

	f = new WinFactory();
	f->createButton()->Paint();

	f = new MacFactory();
	f->createButton()->Paint();

	return 0;
}
