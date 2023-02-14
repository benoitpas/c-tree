#include "tree11.h"
#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

#include <cppunit/TestAssert.h>

class Test11 : public CPPUNIT_NS::TestCase
{
  CPPUNIT_TEST_SUITE(Test11);
  CPPUNIT_TEST(dummyTest);
  CPPUNIT_TEST_SUITE_END();

  protected:
     void dummyTest(void) {
        CPPUNIT_ASSERT_EQUAL(0, 0);
  }
};

CPPUNIT_TEST_SUITE_REGISTRATION(Test11);

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
