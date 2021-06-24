#include <iostream>
#include <string>
using namespace std;

class Harbinger
{
private:
	string h_name, catchPhrase;
	int h_age;

public:
	// К-р по умолчанию
	Harbinger(string h_name = "h1", int h_age = 113, string phrase = "3r") {
		this->h_name = h_name;
		this->h_age = h_age;
		catchPhrase = phrase;
	}

	// Геттеры
	string Get_h_name() {
		return h_name;
	}

	int Get_h_age() {
		return h_age;
	}

	string GetCatchPhrase() {
		return catchPhrase;
	}

	// Сеттеры
	void Set_h_name(string h_nameValue) {
		h_name = h_nameValue;
	}

	void Set_h_age(int h_ageValue) {
		h_age = h_ageValue;
	}

	void SetCatchPhrase(string cPhraseValue) {
		catchPhrase = cPhraseValue;
	}
};

// Режим public - все члены Harbinger наследуются со своими модиф-рами
class Prophet : public Harbinger
{
private:
	string ph_name, ph_call, MagnumOpus[3];
	int ph_age;

public:
	// К-р по умолчанию
	Prophet(string h_name = "gfd", int h_age = 5150, string phrase = "sbfg", string ph_name = "bgf", string ph_call = "sfg", string defaltMagnumOpusElementValue = "sgbr", int ph_age = 23)
		// Наследуем h_name, h_age и phrase из Harbinger.
		: Harbinger(h_name, h_age, phrase) {
		this->ph_name = ph_name;
		this->ph_call = ph_call;
		this->ph_age = ph_age;
		for (int i = 0; i < 3; i++)
		{
			MagnumOpus[i] = defaltMagnumOpusElementValue;
		}
	}

	// Геттеры
	string Get_ph_name() {
		return ph_name;
	}

	int Get_ph_age() {
		return ph_age;
	}

	string Get_ph_call() {
		return ph_call;
	}

	string* GetMagnumOpus() {
		return MagnumOpus;
	}

	// Сеттеры
	void Set_ph_name(string pNameValue) {
		ph_name = pNameValue;
	}

	void Set_ph_age(int pAgeValue) {
		ph_age = pAgeValue;
	}

	void Set_ph_call() {
		string longestString = MagnumOpus[0];
		for (int i = 1; i < 3; i++)
		{
			if (MagnumOpus[i].length() > longestString.length())
			{
				longestString = MagnumOpus[i];
			}
		}
		ph_call = longestString;
	}

	void SetMagnumOpus() {
		cout << "Ввод массива magnumOpus\n";
		for (int i = 0; i < 3; i++)
		{
			cout << "Введите " << i << "-й эл-т: ";
			do {
				cin >> MagnumOpus[i];
				if (MagnumOpus[i].length() > 25)
				{
					cout << "Строка слишком длинная! Повторите попытку: ";
				}
			} while (MagnumOpus[i].length() > 25);
		}
		Set_ph_call();
	}
};

// Режим public - все члены Prophet наследуются со своими модиф-рами
class DeusEx : public Prophet
{
private:
	string gd_name;
	int gd_year;

public:
	// К-р по умолчанию
	DeusEx(string h_name = "цмер", int h_age = 24, string phrase = "ырпп", string ph_name = "ыпав", string ph_call = "упав", string defaltMagnumOpusElementValue = "уимм", int ph_age = 25, string gd_name = "кеег")
		// Наследуем реализацию конструктора из Prophet.
		: Prophet(h_name, h_age, phrase, ph_name, ph_call, defaltMagnumOpusElementValue, ph_age) {
		this->gd_name = gd_name;
		// Рандом от 0 до 9999
		srand(time(0));
		gd_year = rand() % 10000;
	}

	// Геттеры
	string Get_gd_name() {
		return gd_name;
	}

	int Get_gd_year() {
		return gd_year;
	}

	// Метод, использующий унаследованные методы для вывода информации
	void ShowInfo() {
		Set_h_name("Предвестник");
		Set_h_age(100000);
		SetCatchPhrase("придет Пророк");
		Set_ph_name("Пророк");
		SetMagnumOpus();

		cout << Get_h_name() << " в возрасте " << Get_h_age() << " говорил, что " << GetCatchPhrase() << ".\n";
		int count = 0;
		for (int i = 0; i < 3; i++)
		{
			// Поиск  пророчеств. Главное пророчество - самый длинный элемент массива MagnumOpus. Остальные - первое и второе пророчества
			if (GetMagnumOpus()[i] == Get_ph_call())
			{
				continue;
			}
			else
			{
				count++;
				if (count == 1)
				{
					cout << "Первое ";
				}
				else if (count == 2)
				{
					cout << "Второе ";
				}
				cout << "пророчество: " << GetMagnumOpus()[i] << "\n";
			}
		}
		cout << "Главное пророчество: " << Get_ph_call() << ".\n";
		cout << "Так говорил " << Get_ph_name() << ".\n\n";
		cout << "В год " << gd_year << " пришел " << gd_name << ", которого предрекали " << Get_h_name() << " и " << Get_ph_name() << ".\n\n";
	}
};

class Believer : private DeusEx
{
private:
	string bv_name;
	int bv_age;

public:
	// К-р
	Believer(string bv_name, int bv_age)
	{
		this->bv_name = bv_name;
		this->bv_age = bv_age;
	}

	// Геттеры
	string Get_bv_name() {
		return bv_name;
	}

	int Get_bv_age() {
		return bv_age;
	}

	// Сеттеры
	void SetBelieverAge(int bv_age) {
		this->bv_age = bv_age;
	}

	void SetBelieverName(string bv_name) {
		this->bv_name = bv_name;
	}

	// Метод, использующий унаследованные методы для вывода информации
	void ShowMessage() {
		cout << "Верующий " << bv_name << " молится " << Get_gd_name() << " именем " << Get_ph_name() << "\n\n";
	}
};

int main()
{
	setlocale(LC_ALL, "ru");

	Prophet prophet;
	DeusEx god;
	Believer believer("Батя", 30);

	prophet.SetMagnumOpus();
	cout << "ph_call: " << prophet.Get_ph_call() << "\n\n";
	god.ShowInfo();
	believer.ShowMessage();

	system("pause");
	return 0;
}