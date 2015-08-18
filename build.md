## Background ##

Building a project often poses some initial challenges, and this project is no exception.  However, due to the fact that we use FireBreath as our interoperation layer, this process is a bit more involved than usual.  The reason for this is that FireBreath is not an merely external library, but rather an application framework that handles the tedious details with packaging the NPAPI and ActiveX distributions.  The ease with which FireBreath is able to perform these tasks make the additional initial burden well-worth the effort.

## Step 1: Download and Install FireBreath ##

FireBreath may be cloned from its repository or downloaded from its [project homepage](http://code.google.com/p/firebreath/).  Note that FireBreath has its own perquisites (including CMake); please visit that project's [build page](http://code.google.com/p/firebreath/wiki/BuildingFireBreath) for details.

## Step 2: Download and Install BerkeleyDB ##

This project was built against BerkeleyDB 4.8.26, but should function correctly against the since-released 4.8.30 version.  BerkeleyDB is available via [its website](http://www.oracle.com/technology/software/products/berkeley-db/db/index.html).

## Step 3: Download and Install Boost 1.40 ##

This project requires a (small) subset of the [Boost libraries](http://boost.org), specifically the threading and file system components.  (The former is used during deadlock detection, while the latter is used to generate database paths).  The project has been tested against Boost version 1.40, though it is likely compatible with subsequent releases.  For convenience, the [minimal subset libraries and headers used in the project is available](http://code.google.com/p/indexeddb/downloads/list).  These files are distributed under the [Boost Software License](http://www.boost.org/users/license.html).

Note that the project makefile depends on the environment variable "`BOOST_HOME`", which must be manually defined if full Boost installation is bypassed.

## Step 4: Download or Clone the Indexed Database API Source ##

The source for this project (either downloaded from the [downloads page](http://code.google.com/p/indexeddb/downloads/list) or [cloned from the source repository](http://code.google.com/p/indexeddb/source/checkout)) must be installed in the `projects/IndexedDatabase` directory (relative to the FireBreath installation root).

## Step 5: Execute the Prep2008.cmd from the FireBreath Root ##

This script will configure the Indexed Database project in the FireBreath environment, allowing FireBreath to create a full configuration for the project.  Note that this is the area more prone to configuration-related failures; observe the resulting diagnostic information carefully`*`.

`*` Note that in some circumstances repeating the prep2008.cmd execution will clear up some forms of error, such as the build/projects directory not existing.

## Step 6: Load Visual Studio ##

## Step 7: Load the Indexed Database API Solution ##

The solution will be located in the `builds/projects/IndexedDatabase` directory, relative to the FireBreath root (note that it is **not** in the `/projects/IndexedDatabase` directory!).  The solution filename is IndexedDatabase.sln.

## Step 8: Build the Solution ##

This is the second most likely step to result in errors.  The most likely problems here include malformed include and linking directories; should this occur, tweak your project configuration or cmake files with configuration appropriate for your environment.

## Step 9: Register the Resulting DLL ##

The newly-build DLL must be registered on a machine before it may be used.  (Alternatively, if you have installed WiX, you may execute the resulting MSI.  However, note that debugging requires that the actual DLL be registered.)  The DLL is located in the `/build/bin/IndexedDatabase/Debug` directory relative to the FireBreath root, and is named npIndexedDatabase.dll.

Register the DLL using the following command:

```
regsvr32 npIndexedDatabase.dll
```

Open a browser and request a page that references the DLL.  (For example, visit the [project unit test page](http://people.fas.harvard.edu/~bhaynes/IndexedDatabaseAPI/UnitTests/jsunit/testRunner.html?testpage=http://people.fas.harvard.edu/~bhaynes/IndexedDatabaseAPI/UnitTests/jsunit/IndexedDatabaseAPIUnitTests.html).)

Note that the FireBreath wiki contains information on [attaching a debugger](http://code.google.com/p/firebreath/wiki/BuildingFireBreath#Attaching_a_debugger).