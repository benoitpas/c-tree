#include "tree98.h"

#include <iostream>
#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

class Test98 : public CPPUNIT_NS::TestCase
{
  CPPUNIT_TEST_SUITE(Test98);
//  CPPUNIT_TEST(testcountNodesEmptyTree);
//  CPPUNIT_TEST(testcountNodes);
  CPPUNIT_TEST_SUITE_END();

  Tree<const char*> *emptyTree = new Tree<const char*>("",0,0);
  Tree<const char*> *ex1Tree = new Tree<const char*> ("toto",0,0);

  Tree<const char*> *teste = new Tree<const char*> ("E",0,0);
  Tree<const char*> *testd = new Tree<const char*> ("D",0,0);
  Tree<const char*> *testc = new Tree<const char*> ("C",testd,teste);
  Tree<const char*> *testb = new Tree<const char*> ("B",testd,teste);
  Tree<const char*> *testa = new Tree<const char*> ("A",testb,testc);

public:
  void setUp(void) {}
  void tearDown(void) {}
/*
protected:
  void testcountNodesEmptyTree(void) {
    CPPUNIT_ASSERT_EQUAL(1, countNodes(&emptyTree));
  }

  void testcountNodes(void) {
    CPPUNIT_ASSERT_EQUAL(5, countNodes(&testa));
  }*/

};


CPPUNIT_TEST_SUITE_REGISTRATION(Test98);

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