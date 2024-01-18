#include "pch.h"
#include "CppUnitTest.h"

#include "../currency_program/currency_structure.h"
#include "../currency_program/processing.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	currency_structure* create_currency(double buy, double sell, std::string bank_name)
	{
		currency_structure* item = new currency_structure;
		item->buy = buy;
		item->sell = sell;
		item->bank_name = bank_name;
		return item;
	}

	void delete_currency(currency_structure* array[], int size)
	{
		for (int i = 0; i < size; i++) {
			delete array[i];
		}
	}

	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			currency_structure* currencies[3];
			currencies[0] = create_currency(3.14, 3.10, "Альфа-банк");
			currencies[1] = create_currency(2.14, 2.00, "Беларусбанк");
			currencies[2] = create_currency(1.99, 1.98, "Приорбанк");
			const double epsilon = 1e-9;
			double expected = 0.14;
			Assert::AreEqual(expected, get_max_difference(currencies, 3), epsilon);
			delete_currency(currencies, 3);
		}
		TEST_METHOD(TestMethod2)
		{
			currency_structure* currencies[3];
			currencies[0] = create_currency(3.14, 3.14, "Альфа-банк");
			currencies[1] = create_currency(2.14, 2.14, "Беларусбанк");
			currencies[2] = create_currency(1.99, 1.98, "Приорбанк");
			const double epsilon = 1e-9;
			double expected = 0.01;
			Assert::AreEqual(expected, get_max_difference(currencies, 3), epsilon);
			delete_currency(currencies, 3);
		}
		TEST_METHOD(TestMethod3)
		{
			currency_structure* currencies[3];
			currencies[0] = create_currency(3.14, 3.14, "Альфа-банк");
			currencies[1] = create_currency(2.14, 2.14, "Беларусбанк");
			currencies[2] = create_currency(1.99, 1.99, "Приорбанк");
			const double epsilon = 1e-9;
			double expected = 0.0;
			Assert::AreEqual(expected, get_max_difference(currencies, 3), epsilon);
			delete_currency(currencies, 3);
		}
	};
}
