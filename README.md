c-tree
------

[![C/C++ CI](https://github.com/benoitpas/c-tree/actions/workflows/ccpp.yml/badge.svg)](https://github.com/benoitpas/c-tree/actions/workflows/ccpp.yml)

I have not used C/C++ professionally for 20 years and only in very limited occasions in other settings, probably when programming [Arduinos](https://www.arduino.cc/) for very simple tasks. Recently a friend who was still using C++ profesionally at the time (he has stopped since) mentioned ['Modern C++'](https://www.modernescpp.com/index.php/what-is-modern-c).

Throught him and the news I knew C++ has been involving, incorporating aspects of the [boost library] as well as lambdas but I still found the expression funny as C++ did not really strike me as modern. But as I hadn't looked into C++ for a very long time I thought that trying to understand whether C++ is now modern could be interesting, especially since I last used it I have learnt about [functional programming](https://en.wikipedia.org/wiki/Functional_programming).

So I decided to write the algorithm that adds an identifier to a tree with various flavour of C/C++:
* classic C without object orientation
* OO C++, first without the [Standard Template Library](https://en.wikipedia.org/wiki/Standard_Template_Library)
* other variants using if appropriate the  [Standard Template Library](https://en.wikipedia.org/wiki/Standard_Template_Library) or [Boost](https://www.boost.org/).

If I'm bowled over, I may try the [advent of code 2022](https://adventofcode.com/2022) in C++ ;-).

Also I'm really curious to understand how good is the C++ support of [Visual Studio Code](https://code.visualstudio.com/) as well as using [TDD](https://code.visualstudio.com/) with C++ (I don't remember working on a C++ code base with unit tests).

Tooling a bit clunky compared to Haskell ([stack](https://docs.haskellstack.org/en/stable/)) or JVM based languages, c.f. https://www.incredibuild.com/blog/using-github-actions-with-your-c-project.

The project is writen on GCC-11 which enables [C++17 by default](https://gcc.gnu.org/gcc-11/changes.html).

For the C code, I'm going to compile it with the option [`-std=c89`](https://en.wikipedia.org/wiki/ANSI_C#C89).

# C Implementation

In most 'modern' language tree operations are implemented using recursive algorithms. This is not idiomatic C so I decided to use an algorithm with a loop and a [stack](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)) instead.

C being C, we need to allocate the memory for the stack and handle it by hand. So to handle any tree, to allocate the stack, we would need to know the size of the tree. Which itself requires a recursive algorithm or a stack to implement the algorithm ;-). Another option would be implementing a stack which can grow when it is full. To simplify this example I have implemented a recursive size function on the tree.

Implementing the algorithm, what really struct me is:
* how little is included in the C standard library, all data structures (like stack or a list) need to be implemented by hand.
* implementing 'polymorphic' methods and functions relies on 'void' pointers which is quite error prone.
* how much it complicates the implementation to do the memory management by hand (well done [rust](https://www.rust-lang.org/) to have improved so elegantly memory management !). And from a developer point of view, what a pain it is. Altought I added a method to free the tree, without running a memory analysis tool like [memcheck](https://valgrind.org/).

# C++ 98

For the next implementation, I'm going to use [C++98](https://en.wikipedia.org/wiki/C%2B%2B#Standardization). The goal here is to use what was introduced in C++, especially object orientation and templates.

So to implement the generic tree, there are 2 main options:
* Either use an OO solution (comparable to the one in [Java 1.3](https://github.com/benoitpas/java3-tree/), c.f. [Going back in time with Java](https://medium.com/@benoitpas/going-back-in-time-with-java-81c37c87ecfc])
* Or use templates to implement a generic solution.

I went with templates as C++ 98 standard library has a [pair](https://en.cppreference.com/w/cpp/utility/pair/pair) template.

Implementing the unit tests was a great learning experience, it is actually possible with templates to have something similar to [Haskell type classes](https://book.realworldhaskell.org/read/using-typeclasses.html). Here the [trait](https://accu.org/journals/overload/9/43/frogley_442/) assertion_traits is used to implement specific comparisons used by the unit tests (c.f. https://github.com/benoitpas/c-tree/blob/7d510f662a48fc84a3400e97ab089d431a3c6668/tree98Test.cpp#L33).

When using templates of templates of templates (like the stack definition), it does require a lot of attention to get them right especially as the stack contains a pair with a pointer and pointer of pointer. [Type inference](https://wiki.haskell.org/Type_inference) like in Haskell or Scala would be welcome here ;-).

Also the memory management is still quite tricky, for example when 'pop' is used on the stack the pair is freed so it important to keep a copy of it.