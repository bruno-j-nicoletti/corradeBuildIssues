# corradeBuildIssues

This repo demonstrates build issues when using corrade as a submodule. The same problem happens with magnum.

I’ve tried to include corrade and magnum in my project both as sub modules and via the [CPM package manager](https://github.com/cpm-cmake/CPM.cmake) and have hit issues with in both cases. My project layout is along the lines of...

```
- CMakeLists.txt
- CMake
    - various cmake modules
- Modules
    - MODULE_NAME
        - CMakeLists.txt
        - src
            - source files for the module
        - include
            - MODULE_NAME
                - header file for the module
        - test
            - CMakeLists.txt
                - src
                    - unitTest.cpp
```

I generally prefer ninja over make, so to build it all I go...

```
mkdir build
cmake -G Ninja -B build .
cd build
ninja
ctest
```

In this example project, this builds two unit test programs, `build/Modules/A/test/unitTest` and `build/Modules/B/test/unitTest`.

## Problem 1

The problem is if I add corrade as a sub directory, to see this uncomment line 33 in CMakeLists.txt. Running the same commands as above and it will generate ninja build files, but both unit test programs will now be built to `build/bin/unitTest`. This causes ninja to error out. If using `make` instead, it won’t error out, but will instead have both unit test programs written to `build/bin/unitTest`.

## Problem 2
I generally prefer to use CPM over git submodules, it’s much less painful, and when coupled with `ccache` leads to a much simpler CMake and git setup. I tried to add corrade as a CPM packages. To do that in this repo, uncomment lines 36 to 39. Be sure to set the environment variable `CPM_SOURCE_CACHE` to be the dir where CPM will fetch out source modules.

When I now run the build process, CMake fails for corrade, as it fetches the master branch and borks when the corrade CMakeFile.txt tries to parse the checkout tag as a Year/Month. So I get the error....

```
CMake Warning at /Users/bruno/.cpmCache/corrade/d5496cec8530ee46c22b5ccbbc82d857fa3fd6b7/src/Corrade/CMakeLists.txt:75 (message):
  Can't match Git version: fatal: No tags can describe
  'ed451d54ed4c7a20d0c4c5b6bc87ede089152b20'.

  Try --always, or create some tags.

``` 

## Resolving this
I’ve dug into the corrade CMake setup and I’m not at all clear on how to fix problem #1, problem number #2 is a fairly simple fix I’d be happy to do, but would mean having “unknown” or similar for the version year and month,