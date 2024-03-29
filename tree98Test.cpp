
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
    ost << std::get<0>(pair) << ",'" << std::get<1>(pair) << "'";
    return ost.str();
}

static std::string valueToString(const char* s)
{
    std::ostringstream ost;
    ost << "'" << s << "'";
    return ost.str();
}

template <typename T>
struct CPPUNIT_NS::assertion_traits<Tree<T>>
{
    static bool equal( const Tree<T>& x, const Tree<T>& y )
    {
      return x.getValue() == y.getValue()
      && ((x.left == 0 && y.left == 0) || (x.left != 0 && y.left != 0 && *x.left == *y.left))
      && ((x.right == 0 && y.right == 0) || (x.right != 0 && y.right != 0 && *x.right == *y.right));
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
  CPPUNIT_TEST(testAddId);
  CPPUNIT_TEST(testToStringEmptyString);
  CPPUNIT_TEST(testToString);
  CPPUNIT_TEST_SUITE_END();

  Tree<const char*> *emptyTree = new Tree<const char*>("",0,0);

  Tree<const char*> *teste = new Tree<const char*> ("E",0,0);
  Tree<const char*> *testd = new Tree<const char*> ("D",0,0);
  Tree<const char*> *testc = new Tree<const char*> ("C",0,0);
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

  void testAddId(void) {

    Tree<std::pair<int,const char*>> *expectedTree =
    new Tree<std::pair<int,const char*>>(std::pair(0,"A"),
        new Tree<std::pair<int,const char*>>(std::pair(2,"B"),
            new Tree<std::pair<int,const char*>>(std::pair(4,"D"),0,0),
            new Tree<std::pair<int,const char*>>(std::pair(3,"E"),0,0)),
        new Tree<std::pair<int,const char*>>(std::pair(1,"C"),0,0));

    CPPUNIT_ASSERT_EQUAL(*expectedTree, *(testa->addId()));
  }
 
  void testToStringEmptyString() {
    std::string empty = "('')";
    CPPUNIT_ASSERT_EQUAL(empty, emptyTree->toString());
  }

  void testToString() {
    std::string e = "('A',('B',('D'),('E')),('C'))";
    CPPUNIT_ASSERT_EQUAL(e, testa->toString());
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