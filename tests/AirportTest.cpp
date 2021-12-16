#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/Airport.h"

using testing::Eq;

TEST(Airport, addTransport){
   Airport a1("Sá Carneiro");
   EXPECT_EQ(a1.getName(),"Sá Carneiro");
   Transport t1, t2, t3;
   Date d1(15,00);
   Date d2(18,00);
   vector <Date> v1;
   v1.push_back(d1);

   t1.type = "Comboio"; t2.type = "Metro"; t3.type = "Metro";
   t1.distance = 15; t2.distance = 15 ; t3.type = 13;
   t1.time = v1; t2.time =v1; t3.time = v1;
   set<Transport> s1;
   s1.insert(t1); s1.insert(t2); s1.insert(t3);

   Airport a2("Humberto Delgado",s1);
   EXPECT_EQ(a2.getTransports(),s1);

   v1.push_back(d2);
   Transport t4;
   t4.type = "Autocarro"; t4.distance = 20; t4.time = v1;
   a2.addTransport(t4);
   EXPECT_EQ(a2.getTransports().size(), 4);
}
TEST(Airport, findClosest){
   Transport t1, t2, t3;
   Date d1(15,00);
   vector <Date> v1;
   v1.push_back(d1);
   t1.type = "Comboio"; t2.type = "Metro"; t3.type = "Metro";
   t1.distance = 15; t2.distance = 15 ; t3.type = 13;
   t1.time = v1; t2.time =v1; t3.time = v1;
   set<Transport> s1;
   s1.insert(t1); s1.insert(t2); s1.insert(t3);
   Airport a1("Frankfurt",s1);
   EXPECT_EQ(a1.findClosest().type,"Metro");
   EXPECT_EQ(a1.findClosest().distance,13);
}