#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable:4996)
#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab11.1/lab11.1.cpp"

extern "C" { // Declaration for C functions in C++

}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(Test_findThirdDot)
        {
            const char* testFilename = "testFile.txt";
            FILE* testFile = fopen(testFilename, "w");
            Assert::IsNotNull(testFile, L"Failed to create test file.");

            fprintf(testFile, "First line.\n");
            fprintf(testFile, "Second line.\n");
            fprintf(testFile, "Third. still.\n");
            fclose(testFile);

            int lineIndex = 0, charIndex = 0;

            int result = findThirdDot(testFilename, &lineIndex, &charIndex);
            Assert::AreEqual(1, result, L"Third dot not found.");
            Assert::AreEqual(3, lineIndex, L"Incorrect line number.");
            Assert::AreEqual(6, charIndex, L"Incorrect character position.");

            _unlink(testFilename);
        }

        TEST_METHOD(Test_findThirdDot_NoDots)
        {
            const char* testFilename = "testFileNoDots.txt";
            FILE* testFile = fopen(testFilename, "w");
            Assert::IsNotNull(testFile, L"Failed to create test file.");

            fprintf(testFile, "No dots here\n");
            fprintf(testFile, "Still no dots\n");
            fprintf(testFile, "Another line\n");
            fclose(testFile);

            int lineIndex = 0, charIndex = 0;

            int result = findThirdDot(testFilename, &lineIndex, &charIndex);
            Assert::AreEqual(0, result, L"Function should return 0 when less than three dots.");

            _unlink(testFilename);
        }
    };
}