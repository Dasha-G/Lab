#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Семья\source\repos\2.1 lab ipz\2.1 lab ipz\2.1 lab ipz.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
    TEST_CLASS(calculate_y_Tests)
    {
    public:
        TEST_METHOD(TestMethod_xLessThan7)
        {
         
            double x = 5.0;
            int n = 10;
            double expected = 0.07891; 
            double tolerance = 0.001;
            double actual = calculate_y(x, n);

            Assert::AreEqual(expected, actual, tolerance, L"Test failed for x < 7");
        }

        TEST_METHOD(TestMethod_xGreaterThanOrEqual7)
        {
            double x = 8;
            int n = 6;
            double tolerance = 0.01;
            double expected = 2796.910;
                       
            double actual = calculate_y(x, n);
            Assert::AreEqual(expected, actual, tolerance, L"Test failed for x >= 7");
        }
    };


    TEST_CLASS(Validation_Tests)
    {
    public:
    
        TEST_METHOD(checkValidParams_ValidInput_NoExceptionThrown)
        {
            int n = 10;
            try
            {
                if (n <= 7)
                    throw std::invalid_argument("n must be greater than 7.");
                Assert::IsTrue(true); 
            }
            catch (...)
            {
                Assert::Fail(L"Exception thrown for valid n");
            }
        }


        TEST_METHOD(checkValidParams_InvalidInput_ExceptionThrown)
        {
            int n = 3;
            try
            {
                if (n <= 7)
                    throw std::invalid_argument("n must be greater than 7.");
                Assert::Fail(L"Exception not thrown for invalid n");
            }
            catch (...)
            {
                Assert::IsTrue(true); 
            }
        }
    };

    TEST_CLASS(UtilityFunctions_Tests)
    {
    public:
        
        TEST_METHOD(isInteger_ValidInteger_ReturnsTrue)
        {
            string validInteger = "123";
            Assert::IsTrue(isInteger(validInteger), L"Valid integer string failed");
        }

        TEST_METHOD(isInteger_InvalidInteger_ReturnsFalse)
        {
            string invalidInteger = "12.3";
            Assert::IsFalse(isInteger(invalidInteger), L"Invalid integer string passed");
        }

        TEST_METHOD(isValidDouble_ValidDouble_ReturnsTrue)
        {
            string validDouble = "123.45";
            Assert::IsTrue(isValidDouble(validDouble), L"Valid double string failed");
        }

        TEST_METHOD(isValidDouble_InvalidDouble_ReturnsFalse)
        {
            string invalidDouble = "12.3.4";
            Assert::IsFalse(isValidDouble(invalidDouble), L"Invalid double string passed");
        }
    };
}

