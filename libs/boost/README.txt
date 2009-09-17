
Version 1.40.0

Updated Libraries

     * Accumulators:
          + Works on GCC 4.4.
     * Circular Buffer:
          + Fixed bugs #2785, #3285.
     * Foreach:
          + Workaround for conflict with Python headers (#3000).
     * Function:
          + Optimize the use of small target objects.
          + Make Boost.Function compile under BOOST_NO_EXCEPTIONS (#2499, #2494, #2469, #2466, #2900)
          + Various minor fixes (#2642, #2847, #2929 #3012)
     * Fusion:
          + Improved compile times for fusion::vector.
     * Hash:
          + Automatically configure the float functions using template metaprogramming instead of trying to configure every possibility manually.
     * Interprocess:
          + Windows shared memory is created in Shared Documents folder so that it can be shared between services and processes
          + Fixed bugs #2967, #2973, #2992, #3138, #3166, #3205.
     * Intrusive:
          + Code cleanup in tree_algorithms.hpp and avl_tree_algorithms.hpp
          + Fixed bug #3164.
     * MPL:
          + Added mpl::char_ and mpl::string for compile-time string manipulation, based on multichar literals (#2905).
          + Updated MPL Reference Manual.
          + Bug fixes.
     * Program.Options:
          + Support for building with disabled exceptions (#2096).
          + Unicode parser no longer drops original tokens (#2425).
          + Fixed crash on user-inserted items in variables_map (#2782).
     * Proto:
          + PrimitiveTransforms have stricter conformance to ResultOf protocol. (Warning: some invalid code may break.)
          + Add a sensible default for proto::_default's template parameter.
          + Improved default evaluation strategy for pointers to members.
          + GCC 3.4 portability fixes (#3021).
          + Work around Visual C++'s non-std-compliant ciso646 macros.
     * Serialization:
          + Removed deprecated headers: boost/static_warning.hpp, boost/state_saver.hpp, boost/smart_cast.hpp, boost/pfto.hpp. Use the the equivalent headers in the boost/serialization/ directory instead (#3062).
     * Unordered:
          + Implement emplace for all compilers, not just ones with rvalue references and variadic templates (#1978).
          + Create less buckets by default.
          + Some minor tweaks for better compiler support (#2908, #3096, #3082).
     * Xpressive:
          + Works on Visual C++ 10.0 (#3124).

Build System

   The default naming of libraries in Unix-like environment now matches system conventions, and does not include various decorations. Naming of libraries on Cygwin was also fixed. Support for beta versions of Microsoft Visual Studio 10 was added. With gcc, 64-bit compilation no longer requires that target architecture be specified.

Updated Tools

     * Boostbook:
          + Hide INTERNAL ONLY enums in doxygen documentation (#3242).
          + Tweaked appearance of member classes/structs/unions in a class synopsis.
     * Quickbook:
          + Support python code snippets (#3029).
          + Add teletype source mode (#1202)

Compilers Tested

   Boost's primary test compilers are:
     * OS X:
          + GCC 4.0.1 on Intel Tiger and Leopard
          + GCC 4.0.1 on PowerPC Tiger
     * Linux:
          + GCC 4.3.3 on Ubuntu Linux.
     * Windows:
          + Visual C++ 7.1 SP1, 8.0 SP1 and 9.0 SP1 on Windows XP.

   Boost's additional test compilers include:
     * Linux:
          + Intel 9.0 on Red Hat Enterprise Linux.
          + Intel 10.0 on Red Hat Enterprise Linux.
          + Intel 10.1 on 64-bit Linux Redhat 5.1 Server.
          + Intel 10.1 on Suse Linux on 64 bit Itanium.
          + Intel 11.0 on Red Hat Enterprise Linux.
          + Intel 11.1 on Red Hat Enterprise Linux.
          + GCC 3.4.3, GCC 4.0.1, GCC 4.2.4, GCC 4.3.3 and GCC 4.4.0 on Red Hat Enterprise Linux.
          + GCC 4.3.3 and GCC 4.4.0 with C++0x extensions on Red Hat Enterprise Linux.
          + GCC 4.1.1, 4.2.1 on 64-bit Red Hat Enterprise Linux.
          + GCC 4.1.2 on Suse Linux on 64 bit Itanium.
          + GCC 4.1.2 on 64-bit Redhat Server 5.1.
          + GCC Open64 4.2.2 on Red Hat Enterprise Linux.
          + GCC 4.3.4 on Debian unstable.
          + QLogic PathScale(TM) Compiler Suite: Version 3.1 on Red Hat Enterprise Linux.
          + GCC version 4.2.0 (PathScale 3.2 driver) on 64-bit Red Hat Enterprise Linux.
          + Sun 5.9 on Red Hat Enterprise Linux.
     * OS X:
          + Intel 10.1, 11.0 on Intel Leopard.
          + Intel 10.1, 11.0 on Intel Tiger.
          + GCC 4.0.1, 4.2.1 on Intel Leopard.
          + GCC 4.0.1 on Intel Tiger.
          + GCC 4.0.1 on PowerPC Tiger.
     * Windows:
          + Visual C++ 7.1 on XP.
          + Visual C++ 9.0 on XP.
          + Visual C++ 9.0 on Vista.
          + Visual C++ 9.0 on Vista 64-bit.
          + Visual C++ 9.0, using STLport 5.2, on XP and Windows Mobile 5.0.
          + Visual C++ 10.0 beta.
          + Borland 5.9.3, 6.1.0, 6.1.3.
          + Borland C++ Builder 2007 and 2009.
          + Intel C++ 11.1, with a Visual C++ 9.0 backend, on Vista 32-bit.
          + Intel C++ 11.1, with a Visual C++ 9.0 backend, on Vista 64-bit.
          + GCC 4.3.3 and 4.4.0, on Mingw with C++0x features.
     * AIX:
          + IBM XL C/C++ Enterprise Edition for AIX, V10.1.0.0, on AIX Version 5.3.0.40.
     * Solaris:
          + Sun C++ 5.7, 5.8, 5.9 on Solaris 5.10.
          + GCC 3.4.6 on Solaris 5.10.

Acknowledgements

   Beman Dawes, Eric Niebler, Rene Rivera, and Daniel James managed this release.
