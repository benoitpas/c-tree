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

Tooling a bit clunky compared to Haskell ([stack]()) or JVM based languages, c.f. https://www.incredibuild.com/blog/using-github-actions-with-your-c-project.

writen on GCC-11 which enables [C++17 by default](https://gcc.gnu.org/gcc-11/changes.html).

for the C code, I'm going to compile it with the option [`-std=c89`](https://en.wikipedia.org/wiki/ANSI_C#C89).

# C Implementation

