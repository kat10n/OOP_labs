#include "str_ops.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(StrOpsTest, StrLen) {
    EXPECT_EQ(lab01::str_len("Hello, World!"), 13u);
    EXPECT_EQ(lab01::str_len(""), 0u);
}

TEST(StrOpsTest_Fail, StrLenNullptr) {
    EXPECT_EQ(lab01::str_len(nullptr), 0u);
}

TEST(StrOpsTest, StrCopy) {
    const char* src = "Hello, World!";
    char* dst = new char[lab01::str_len(src) + 1];
    lab01::str_copy(dst, src);
    EXPECT_STREQ(dst, src);
    delete[] dst;
}

TEST(StrOpsTest, StrAlloc) {
    const char* src = "Hello, World!";
    char* new_str = lab01::str_alloc(src);
    EXPECT_STREQ(new_str, src);
    lab01::str_delete(new_str);
}

TEST(StrOpsTest_Fail, StrAllocNullptr) {
    char* result = lab01::str_alloc(nullptr);
    EXPECT_EQ(result, nullptr);
}

TEST(StrOpsTest, StrDelete) {
    char* str = lab01::str_alloc("Hello, World!");
    lab01::str_delete(str);
    EXPECT_EQ(str, nullptr);
}

TEST(StrOpsTest_Fail, StrDeleteNullptr) {
    char* str = nullptr;
    lab01::str_delete(str);
    EXPECT_EQ(str, nullptr);
}

TEST(StrOpsTest, StrPrint) {
    const char* str = "Hello, World!";
    testing::internal::CaptureStdout(); // захват вывода
    lab01::str_print(str);
    std::string output = testing::internal::GetCapturedStdout(); // получение захваченного вывода
    EXPECT_EQ(output, "Hello, World!\n");
}

TEST(StrOpsTest, StrToUpper) {
    char* str = lab01::str_alloc("Hello, World!");
    lab01::str_to_upper(str);
    EXPECT_STREQ(str, "HELLO, WORLD!");
    lab01::str_delete(str);
}

TEST(StrOpsTest, StrToUpperNoLetters) {
    char* str = lab01::str_alloc("123!@#");
    lab01::str_to_upper(str);
    EXPECT_STREQ(str, "123!@#");
    lab01::str_delete(str);
}

TEST(StrOpsTest, StrCountChar) {
    const char* str = "Hello, World!";
    EXPECT_EQ(lab01::str_count_char(str, 'o'), 2u);
    EXPECT_EQ(lab01::str_count_char(str, 'l'), 3u);
    EXPECT_EQ(lab01::str_count_char(str, 'z'), 0u); 
}

TEST(StrOpsTest_Fail, StrCountCharNullptr) {
    EXPECT_EQ(lab01::str_count_char(nullptr, 'a'), 0u);
}
