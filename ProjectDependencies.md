# Project Dependencies #

This project depends on a number of external libraries, each of which must be installed prior to building the source.  These include:

### [Boost 1.40](http://boost.org) ###
This project requires a (small) subset of the [Boost libraries](http://boost.org), specifically the threading and file system components.  (The former is used during deadlock detection, while the latter is used to generate database paths).  The project has been tested against Boost version 1.40, though it is likely compatible with subsequent releases.  For convenience, the [minimal subset libraries and headers used in the project is available](http://code.google.com/p/indexeddb/downloads/list).  These files are distributed under the [Boost Software License](http://www.boost.org/users/license.html).

Note that the project makefile depends on the environment variable "BOOST\_HOME", which must be manually defined if full Boost installation is bypassed.

### [BerkeleyDB 4.8.26](http://www.oracle.com/technology/software/products/berkeley-db/db/index.html) ###
The (sole) persistence implementation utilizes the Berkeley Database library, which must be installed prior to building from source.

### [FireBreath 1.0.1 (or Nightly Build #5)](http://code.google.com/p/firebreath/downloads/list) ###
The project leverages the FireBreath project for browser NPAPI and ActiveX interoperation.  See the [build instructions](build.md) for important details about configuring FireBreath.

### [Visual Studio 2008](http://msdn.microsoft.com/en-us/vstudio/default.aspx) ###
Visual Studio is required in order to compile some of the ActiveX portions of the projects.  Although FireBreath supports both Visual Studio 2005 and 2010, this has not yet been tested.

### [Wix Toolset 3.0](http://wix.sourceforge.net/downloadv3.html) (Optional) ###
In order to automatically build the installation MSI from source files, the WiX toolset must be installed in the development environment.  This is not required if the result is not to be distributed via MSI.

### [Mercurial](http://mercurial.selenic.com/) (Optional) ###
Mercurial may be used to clone the source repository directly from Google Code; alternatively, one may simply [download the latest packaged release](http://code.google.com/p/indexeddb/downloads/list).