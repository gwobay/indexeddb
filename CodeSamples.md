# Code Samples #

Herein we include some simple code samples for getting started with the Indexed Database API.  Note that the W3C standard contains a number of non-normative samples that provide equally valuable insight.

(This page is a bit sparse at the moment; please see the (large) number of unit tests for more details on API operation.)

### An Object Store and Index of Fruits ###
```
connection = db.indexedDB.open("A Fruit Database", "");

fruits = connection.createObjectStore("A Fruity Object Store", "fruit", true);
fruitIndexByColor = fruits.createIndex("A Fruity Index", "color", false);

fruits.put({ fruit: "Apple", color: "Red" });
fruits.put({ fruit: "Orange", color: "Orange" });
fruits.put({ fruit: "Tangerine", color: "Orange" });
fruits.put({ fruit: "Grape", color: "Purple" });
fruits.put({ fruit: "Pomegranate", color: "Red" });

var expectedIndexKeys =   ["Orange", "Purple", "Red"];
var expectedPrimaryKeys = ["Orange", "Grape",  "Apple"];

var cursor = fruitIndexByColor.openCursor(undefined, db.IDBCursor.NEXT_NO_DUPLICATE);

for (var index = 0; index < 2; index++) {
    assertEquals(expectedIndexKeys[index], cursor.key);
    assertObjectEquals(expectedPrimaryKeys[index], cursor.value);
    assertTrue(cursor["continue"]());
}

```