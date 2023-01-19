extern "C" {
  #include "tree.h"
}
#include <iostream>
#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

class Test : public CPPUNIT_NS::TestCase
{
  CPPUNIT_TEST_SUITE(Test);
  CPPUNIT_TEST(testcountNodesEmptyTree);
  CPPUNIT_TEST(testcountNodes);
  CPPUNIT_TEST_SUITE_END();

  struct tree emptyTree;
  struct tree ex1Tree;

  struct tree testa;
  struct tree testb;
  struct tree testc;
  struct tree testd;
  struct tree teste;

public:
  void setUp(void) {
    emptyTree.left = NULL;
    emptyTree.right = NULL;

    testa.value = (void*) "A";
    testa.left = &testb;
    testa.right = &testc;
    testb.value = (void*) "B";
    testc.value = (void*) "C";
    testc.left = &testd;
    testc.right = &teste;
    testd.value = (void*) "D";
    teste.value = (void*) "E";
  }
  void tearDown(void) {}

protected:
  void testcountNodesEmptyTree(void) {
    CPPUNIT_ASSERT_EQUAL(1, countNodes(&emptyTree));
  }

  void testcountNodes(void) {
    CPPUNIT_ASSERT_EQUAL(5, countNodes(&testa));
  }

};


CPPUNIT_TEST_SUITE_REGISTRATION(Test);

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