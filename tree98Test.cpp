
#include <iostream>
#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

#include <cppunit/TestAssert.h>

static std::string valueToString(const std::pair<int, const char*>& pair);

static std::string valueToString(const char* s);

#include "tree98.h"

static std::string valueToString(const std::pair<int, const char*>& pair)
{
    std::ostringstream ost;
    ost << std::get<0>(pair) << "," << std::get<1>(pair);
    return ost.str();
}

static std::string valueToString(const char* s)
{
    std::ostringstream ost;
    ost << '"' << s << '"';
    return ost.str();
}

template <typename T>
struct CPPUNIT_NS::assertion_traits<Tree<T>>
{
    static bool equal( const Tree<T>& x, const Tree<T>& y )
    {
      Tree<T>* xLeft = x.getLeft();
      Tree<T>* xRight = x.getRight();
      Tree<T>* yLeft = y.getLeft();
      Tree<T>* yRight = y.getRight();

      return x.getValue() == y.getValue()
      && ((xLeft == 0 && yLeft == 0) || (xLeft != 0 && yLeft != 0 && *xLeft == *yLeft))
      && ((xRight == 0 && yRight == 0) || (xRight != 0 && yRight != 0 && *xRight == *yRight));
    }

    static std::string toString( const Tree<T>& x )
    {
      std::string text = x.toString();
      std::ostringstream ost;
      ost << text;
      return ost.str();
    }
 };

class Test98 : public CPPUNIT_NS::TestCase
{
  CPPUNIT_TEST_SUITE(Test98);
  CPPUNIT_TEST(testAddIdEmptyTree);
  CPPUNIT_TEST(testToStringEmptyString);
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

protected:
  void testAddIdEmptyTree(void) {
    Tree<std::pair<int,const char*>> *expectedTree = new Tree<std::pair<int,const char*>>(std::pair(0,""), 0, 0);

    CPPUNIT_ASSERT_EQUAL(*expectedTree, *(emptyTree->addId()));
  }
 
  void testToStringEmptyString() {
    std::string empty = "(\"\")";
    CPPUNIT_ASSERT_EQUAL(empty, emptyTree->toString());
  }

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