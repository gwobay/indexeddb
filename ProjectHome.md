# Indexed Database API W3C Draft Implementation #

The purpose of this project is to:
  1. implement the Indexed Database API working draft [as proposed by the W3C Web Applications Working Group](http://www.w3.org/TR/IndexedDB/),
  1. expose the ability to leverage this API within various user agent environments (e.g. via NPAPI, ActiveX), and
  1. serve as a demonstration illustrating the function of said implementation.

Where possible, the project will be made as cross-browser and operating system agnostic as is feasible.

Please review the [latest draft](http://www.w3.org/TR/IndexedDB/) for more details about the Indexed Database API.

## Project Background ##

The [W3C Indexed Database API working draft](http://www.w3.org/TR/IndexedDB/) defines an method by which a developer may operate on a set of indexable object stores persisted in a client's web browser environment.  Values in an object store or index may be associated with a developer-specified primary/secondary key, or alternatively keys may be automatically generated based upon the value inserted.  Left-, right-, full-, and un-bounded cursors are supported in both the forward and reverse direction.  Each connection supports up to one active transaction across any set of open object stores.

The working draft exists as a incremental improvement over previous specifications (e.g. [web storage](http://www.w3.org/TR/2009/WD-webstorage-20090910/)) in that robust indexes and duplicate keys are supported.  Indeed, an object store may have an arbitrary number of such indexes, each manually or automatically populated according to a developer's needs.  This API allows for advanced data scenarios _on the client_ that were until now quite difficult (or not possible).  For example, consider the following simple script:

```
connection = db.indexedDB.open("Fruits", "A Fruit Database!");

fruits = connection.createObjectStore("A Fruity Object Store", "fruit", true);
fruitIndexByColor = fruits.createIndex("A Fruity Index", "color", false);

fruits.put({ fruit: "Apple", color: "Red" });
fruits.put({ fruit: "Tangerine", color: "Orange" });
fruits.put({ fruit: "Grape", color: "Purple" });

var cursor = fruitIndexByColor.openCursor(undefined, db.IDBCursor.NEXT_NO_DUPLICATE);

assertEquals("Orange", cursor.key);
assertEquals("Tangerine", cursor.value);
cursor.continue();

assertEquals("Purple", cursor.key);
assertEquals("Grape", cursor.value);
cursor.continue();

assertEquals("Red", cursor.key);
assertEquals("Apple", cursor.value);
assertFalse(cursor.continue());
cursor.close();
```

Unfortunately, there currently exists no reference implementation for this working draft.  This project serves to fill this need, and exists as a browser plug-in that implements the API defined by the working draft.

## Goals ##

  * Implement the Indexed Database API working draft with as much fidelity as is possible
  * Produce a solution that is, insofar as is feasible, cross-browser compatible and platform agnostic
  * Separate browser interoperation concerns from the underlying database technology such that new persistence logic may be easily introduced
  * Ensure that the persistence layer has no direct dependencies upon the browser interoperation logic, so that the database persistence may be promoted or leveraged in outside projects (by being directly incorporated into a browser, for example).

## Installation and Deployment ##

The implementation currently exists in beta form (0.5 at this time), and is currently compiled for the Microsoft Windows platform.  (Although the project and all dependencies should be compatible with other platforms, no testing has yet been performed.  Contributions in this area would be greatly appreciated!)

  * To install the Indexed Database API plug-in on a Microsoft Windows system, [download and execute the installation MSI](http://indexeddb.googlecode.com/files/IndexedDatabase.msi).
  * To compile from source, ensure you have reviewed the [project dependences](ProjectDependencies.md) and [build instructions](build.md).  It is important to have the development environment properly configured before attempting to build.

## Sample Applications ##

### Magento Client-Side Shopping Cart ###
To demonstrate the utility of the implementation, visit our [high-level sample application](http://people.fas.harvard.edu/~bhaynes/IndexedDatabaseAPI/Samples/Magento/catalog.html) that utilizes the Indexed Database API (the pages themselves are a fork of the [Magento Community Edition](http://www.magentocommerce.com/) and thereby published and available under an [OSL 3.0](http://www.opensource.org/licenses/osl-3.0.php) license).

This demonstration uses the Indexed Database API to persist a user's selected catalog items _on the client_; these persisted values are reconstructed on the shopping cart page.  This demonstration uses one object store (which contains the n items in a user's cart) and one index (used to aggregate the selected items).

Note that this demonstration has the overwhelming bulk of its functionality disabled in order to focus on the simple add-to-cart/shopping basket experience.  Contributors who wish to extend the Indexed Database API to operate more completely are welcomed!

### FireBug Console-Ready Sample Page ###

A [page exists designed for direct console interaction](http://people.fas.harvard.edu/~bhaynes/IndexedDatabaseAPI/Samples/FireBug/FireBugSample.html) with a JavaScript debugger such as [FireBug](http://getfirebug.com/).

## Feedback is Greatly Appreciated! ##
Feedback about your experiences, along with community contributions, are greatly appreciated!