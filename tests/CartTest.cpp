#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/Airline/Airline.h"

using testing::Eq;

TEST(cart, insert)
{
   Cart cart1 = Cart(1, 2, 1);
   EXPECT_TRUE(cart1.insert(1));
   EXPECT_TRUE(cart1.insert(1));
   EXPECT_FALSE(cart1.insert(1));
}

TEST(cart, isFull)
{
   Cart cart1 = Cart(1, 2, 1);
   EXPECT_FALSE(cart1.isFull());
   cart1.insert(1);
   cart1.insert(1);
   EXPECT_TRUE(cart1.isFull());
}