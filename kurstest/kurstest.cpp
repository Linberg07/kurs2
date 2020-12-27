#include "pch.h"
#include "CppUnitTest.h"
#include "../Kursovaya/function.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace kurstest
{
	TEST_CLASS(kurstest)
	{
	public:
		
		TEST_METHOD(Addition)
		{
			string Exp = "1+5+4";
			Exp = implementation(Exp);
			Assert::IsTrue(Exp == "10");
		}
		TEST_METHOD(AdditionNegativeValues)
		{
			string Exp = "1+5+4+(-10)";
			Exp = implementation(Exp);
			Assert::IsTrue(Exp == "0");
		}
		TEST_METHOD(Computation)
		{
			string Exp = "100-90-10";
			Exp = implementation(Exp);
			Assert::IsTrue(Exp == "0");
		}
		TEST_METHOD(ComputationNegativeValues)
		{
			string Exp = "100-(-100)";
			Exp = implementation(Exp);
			Assert::IsTrue(Exp == "200");
		}
		TEST_METHOD(Multiplication)
		{
			string Exp = "10*20*5";
			Exp = implementation(Exp);
			Assert::IsTrue(Exp == "1000");
		}
		TEST_METHOD(MultiplicationNegativeValues)
		{
			string Exp = "(-10)*5";
			Exp = implementation(Exp);
			Assert::IsTrue(Exp == "-50");
		}
		TEST_METHOD(Division)
		{
			string Exp = "((100/20)/5)/2";
			Exp = implementation(Exp);
			Assert::IsTrue(Exp == "0.5");
		}
		TEST_METHOD(DivisionNegativeValues)
		{
			string Exp = "-10/-10";
			Exp = implementation(Exp);
			Assert::IsTrue(Exp == "1");
		}
		TEST_METHOD(test1) {
			string Exp = "cos0+sin0";
			Exp = implementation(Exp);
			Assert::IsTrue(Exp == "1");
		}
		TEST_METHOD(test2) {
			string Exp = "sin0*sin0+cos0*cos0";
			Exp = implementation(Exp);
			Assert::IsTrue(Exp == "1");
		}
		TEST_METHOD(test3) {
			string Exp = "((2*4/2)*4)/16";
			Exp = implementation(Exp);
			Assert::IsTrue(Exp == "1");
		}
		TEST_METHOD(test4) {
			string Exp = "tg2*ctg2";
			Exp = implementation(Exp);
			Assert::IsTrue(Exp == "1");
		}
		TEST_METHOD(test5) {
			string Exp = "lne";
			Exp = implementation(Exp);
			Assert::IsTrue(Exp == "1");
		}
		TEST_METHOD(test6) {
			string Exp = "cospi";
			Exp = implementation(Exp);
			Assert::IsTrue(Exp == "-1");
		}
		TEST_METHOD(SymbolError) {
			string Exp = "12a+3";
			try {
				check_string(Exp);
			}
			catch (const char* warning)
			{
				Assert::AreEqual(warning, "Error in symbol");
			}
			
		}
		TEST_METHOD(ReplayError) {
			string Exp = "12+++3";
			try {
				check_string(Exp);
			}
			catch (const char* warning)
			{
				Assert::AreEqual(warning, "Replay symbol");
			}

		}
		TEST_METHOD(Invalidparentheses) {
			string Exp = "(1+2)-3)";
			try {
				check_string(Exp);
			}
			catch (const char* warning)
			{
				Assert::AreEqual(warning, "Invalid parentheses");
			}

		}
	};
}
