Date Date::operator-(int day)
{
	Date ret = *this;
	ret -= day;
	return ret;
}

Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += -day;
	}
	_day -= day;
	while (_day <= 0)
	{
		--_month;
		if (_month == 0)
		{
			--_year;
			_month = 12;
		}

		_day += GetMonthDay(_year, _month);
	}

	return *this;
}

Date Date::operator--(int) // 后置
{
	Date tmp(*this);
	*this -= 1;
	return tmp;
}

Date& Date::operator--()
{
	return *this -= 1;
}

// d1 - d2
int Date::operator-(const Date& d) //两个日期相减
{
	int flag = 1;
	Date max = *this;
	Date min = d;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}

	int n = 0;
	while (min != max)
	{
		++min;
		++n;
	}

	return n * flag;
}

Date Date::operator+(int day)
{
	//Date ret(*this);
	Date ret = *this;
	ret += day;

	return ret;
}

Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		return *this -= -day;
	}

	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GerMonthDay(_year, _month);
		++_month;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}

	return *this;
}

//void Date::operator<<(ostream& out)
//{
//	out << _year << "-" << _month << "-" << day;
//}

void operator<<(ostream& out, const Date& d)
{
	out <<"年"<< d._year << "月" << d._month << "日" << d._day << endl;
	return out;
}

void Date::Print() const //括号例默认是Date* const this
{
	cout << _year << "/" << _month << "/" << _day << endl;
}
