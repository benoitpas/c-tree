#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

#include <cppunit/TestAssert.h>

static std::string valueToString(const char* s);

static std::string valueToString(const std::pair<int, const char*>& pair);


#include "tree17.h"

static std::string valueToString(const char* s)
{
    std::ostringstream ost;
    ost << "'" << s << "'";
    return ost.str();
}

static std::string valueToString(const Pair<int, const char*>& pair)
{
    std::ostringstream ost;
    ost << "(" << pair.first << "," << "'" << pair.second << "')";
    return ost.str();
}

template <typename T>
struct CPPUNIT_NS::assertion_traits<Tree<T>>
{
    static bool equal( const Tree<T>& x, const Tree<T>& y )
    {
      return x.value == y.value
      && ((x.left == nullptr && y.left == nullptr) || (x.left != nullptr && y.left != nullptr && *x.left == *y.left))
      && ((x.right == nullptr && y.right == nullptr) || (x.right != nullptr && y.right != nullptr && *x.right == *y.right));
    }

    static std::string toString( const Tree<T>& x )
    {
      return x.toString();
    }
 };

class Test17 : public CPPUNIT_NS::TestCase
{
  CPPUNIT_TEST_SUITE(Test17);
  CPPUNIT_TEST(emptyTreeEqualityTest);
  CPPUNIT_TEST(toStringEmptyTreeTest);
  CPPUNIT_TEST(toStringTest);
  CPPUNIT_TEST(addIdEmptyTreeTest);
  CPPUNIT_TEST(addIdTest);
  CPPUNIT_TEST_SUITE_END();

  Opt<Ptr<Tree<const char*>>> nil = std::nullopt;
  Opt<Ptr<Tree<Pair<int,const char*>>>> nilId = std::nullopt;

  Tree<const char*>* emptyTree = new Tree<const char*>("a", nil, nil);

  Tree<const char*> *teste = new Tree<const char*> ("E", nil, nil);
  Tree<const char*> *testd = new Tree<const char*> ("D", nil, nil);
  Tree<const char*> *testc = new Tree<const char*> ("C", nil, nil);
  Tree<const char*> *testb = new Tree<const char*> ("B", testd,teste);
  Tree<const char*> *testa = new Tree<const char*> ("A", testb,testc);

  protected:
    void emptyTreeEqualityTest(void)
    {
        auto anotherEmptyTree = new Tree<const char*>("a", nil, nil);
        CPPUNIT_ASSERT_EQUAL(*anotherEmptyTree, *emptyTree);
    }

    void toStringEmptyTreeTest(void)
    {
      CPPUNIT_ASSERT_EQUAL(std::string("('a')"), emptyTree->toString());
    }

    void toStringTest(void)
    {
      std::string e = "('A',('B',('D'),('E')),('C'))";
      CPPUNIT_ASSERT_EQUAL(e, testa->toString());
    }

    void addIdEmptyTreeTest(void)
    {
      auto emptyTreeWithId = new Tree<Pair<int,const char*>>(Pair<int,const char*>(0,"a"), nilId, nilId);
      CPPUNIT_ASSERT_EQUAL(*emptyTreeWithId, *emptyTree->addId(0));
    }

    void addIdTest(void)
    {
      auto e = new Tree<Pair<int,const char*>>(Pair<int,const char*>(4,"A"), 
        new Tree<Pair<int,const char*>>(Pair<int,const char*>(2,"B"), 
                new Tree<Pair<int,const char*>>(Pair<int,const char*>(0,"D"), nilId, nilId),
                new Tree<Pair<int,const char*>>(Pair<int,const char*>(1,"E"), nilId, nilId)),
        new Tree<Pair<int,const char*>>(Pair<int,const char*>(3,"C"), nilId, nilId));

      auto s = (*testa->addId(0)).toString();
      auto es = e->toString();
      CPPUNIT_ASSERT_EQUAL(es, s);
    }

};

CPPUNIT_TEST_SUITE_REGISTRATION(Test17);

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
