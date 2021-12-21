#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/Airline/App.h"

using testing::Eq;

TEST(app, readCommand)
{
   ifstream in("one two three\n");
   cin.rdbuf(in.rdbuf());
   queue<string> test, result;
   test.push("one");
   test.push("two");
   test.push("three");
   //result = App().readCommand();
   //EXPECT_EQ(test.size(), result.size());
   //EXPECT_EQ(test.front(), App().readCommand().front());
   //EXPECT_EQ(test, App().readCommand());
}