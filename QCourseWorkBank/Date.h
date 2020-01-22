#pragma once
#include "head.h"

class Date {
	private:
		int day;
		int month;
		int year;
	public:
		Date(int m = 0, int y = 0) : month(m), year(y), day(0) {}
		Date(int d, int m, int y) : day(d), month(m), year(y) {}
		void SetDate(int m, int y) {
			month = m;
			year = y;
		}
		int getMonth() { return month; }
		int getYear() { return year; }
		virtual string GetDateStr() {
			return string(month < 10 ? '0' + to_string(month) + '/' + to_string(year) : to_string(month) + '/' + to_string(year));
		}
};