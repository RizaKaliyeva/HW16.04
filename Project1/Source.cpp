#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <locale>

using std::cin;
using std::ostream;
using std::cout;
using std::string;
using std::copy_if;
using std::ostream_iterator;
using std::locale;


class Route
{

	mutable string PointTo;
	mutable string RootNumber;
	mutable string PlaneType;
	mutable string TimeOut;
	mutable string WeekDay;

public:

	Route() {};
	~Route() {};

	Route(Route& r)
	{
		this->write_Plane(r.Plane());
		this->write_point_to(r.read_point_to());
		this->write_root_num(r.read_root_num());
		this->write_Weekday(r.Weekday());
		this->write_Time(r.Time());

	}

	const string& read_point_to() const
	{
		return PointTo;
	}
	template <typename T> void write_point_to(T data) const
	{
		PointTo.clear();
		PointTo.append(data);
	}


	const string& read_root_num() const
	{
		return RootNumber;
	}
	template <typename T> void write_root_num(T data) const
	{
		RootNumber.clear();
		RootNumber.append(data);
	}

	const string& Plane() const
	{
		return PlaneType;
	}
	template <typename T> void write_Plane(T data) const
	{
		PlaneType.clear();
		PlaneType.append(data);
	}

	const string& Time() const
	{
		return TimeOut;
	}
	template <typename T> void write_Time(T data) const
	{
		TimeOut.clear();
		TimeOut.append(data);
	}
	const string& Weekday() const
	{
		return  WeekDay;
	}
	template <typename T> void write_Weekday(T data) const
	{
		WeekDay.clear();
		WeekDay.append(data);
	}

	friend ostream& operator<<(ostream& os, Route& r);

};


ostream& operator<<(ostream& os, const Route& r)
{
	os << "Пункт назначения " << r.read_point_to() << "\n";
	os << "Номер рейса " << r.read_root_num() << "\n";
	os << "Тип самолета " << r.Plane() << "\n";
	os << "Время вылета " << r.Time() << "\n";
	os << "День недели " << r.Weekday() << "\n\n\n";


	return os;
}

int main()


{
	setlocale(LC_ALL, "RUS");

	const Route Aeroflot[5]; //массив из 5 рейсов для примера
							 //ввод без циклов, вручную, просто для демонстрации работы класса


	Aeroflot[0].write_Plane("Boing");
	Aeroflot[0].write_point_to("Magadan");
	Aeroflot[0].write_root_num("1057");
	Aeroflot[0].write_Weekday("Monday");
	Aeroflot[0].write_Time("10.30");

	Aeroflot[1].write_Plane("Boing");
	Aeroflot[1].write_point_to("Sochi");
	Aeroflot[1].write_root_num("1034");
	Aeroflot[1].write_Weekday("Monday");
	Aeroflot[1].write_Time("14.30");

	Aeroflot[2].write_Plane("tu134");
	Aeroflot[2].write_point_to("Yalta");
	Aeroflot[2].write_root_num("1057");
	Aeroflot[2].write_Weekday("Friday");
	Aeroflot[2].write_Time("17.17");

	Aeroflot[3].write_Plane("tu134");
	Aeroflot[3].write_point_to("Chegem");
	Aeroflot[3].write_root_num("2034");
	Aeroflot[3].write_Weekday("Monday");
	Aeroflot[3].write_Time("18.30");

	Aeroflot[4].write_Plane("Mig29");
	Aeroflot[4].write_point_to("Magadan");
	Aeroflot[4].write_root_num("104");
	Aeroflot[4].write_Weekday("Tuesday");
	Aeroflot[4].write_Time("00.30");

	cout << "Все рейсы понедельника" << "\n\n";
	copy_if(Aeroflot, Aeroflot + 5, ostream_iterator<Route>(cout), [](const Route& r)->bool {return r.Weekday() == "Monday"; });
	cout << "Все рейсы на Магадан" << "\n\n";
	copy_if(Aeroflot, Aeroflot + 5, ostream_iterator<Route>(cout), [](const Route& r)->bool {return r.read_point_to() == "Magadan"; });
	cout << "Все рейсы понедельника после 12.00" << "\n\n";
	copy_if(Aeroflot, Aeroflot + 5, ostream_iterator<Route>(cout), [](const Route& r)->bool {return r.Weekday() == "Monday"&&r.Time()>"12.00"; });

	system("pause");
	return 0;
}