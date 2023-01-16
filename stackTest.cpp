extern "C" {
  #include "stack.h"
  #include <stdio.h>
}
#include <iostream>
#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

class StackTest : public CPPUNIT_NS::TestCase
{
  CPPUNIT_TEST_SUITE(StackTest);
  CPPUNIT_TEST(testPushPop);
  CPPUNIT_TEST_SUITE_END();


public:
  void setUp(void) {}
  void tearDown(void) {}

protected:
  void testPushPop(void) {
    struct stack* s;
    int v1 = 1;
    int v2 = 2;

    s = newStack(10);
    CPPUNIT_ASSERT_EQUAL(0, push(s, &v1));
    CPPUNIT_ASSERT_EQUAL(0, push(s, &v2));

    CPPUNIT_ASSERT_EQUAL((void*) &v2, pop(s));
    CPPUNIT_ASSERT_EQUAL((void*) &v1, pop(s));
    freeStack(s);
  }

  void testEmptyAndFullStack(void) {
    struct stack* s;
    s = newStack(0);
    CPPUNIT_ASSERT_EQUAL((void*) NULL, pop(s));
    CPPUNIT_ASSERT_EQUAL(-1, push(s, s));
  }
};


CPPUNIT_TEST_SUITE_REGISTRATION(StackTest);

int main()
{
  CPPUNIT_NS::TestResult controller;

  CPPUNIT_NS::TestResultCollector result;
  controller.addListener(&result);

  CPPUNIT_NS::BriefTestProgressListener progress;
  controller.addListener(&progress);

  CPPUNIT_NS::TestRunner runner;
  runner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
  runner.run(controller);

  return result.wasSuccessful() ? 0 : 1;
}