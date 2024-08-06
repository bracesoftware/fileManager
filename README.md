# File Manager
📁 • **File Manager** is a C++ library designed to provide a friendlier approach to managing persistent data.

### `<>.set_name(std::string newname)`
- File type required: `all directories and files`
- Rename an object.
```cpp
myFile.set_name("something.txt");
```

### `<>.get_name()`
- File type required: `all directories and files`
- Get object name.
```cpp
std::string filename = myFile.get_name();
```

### `<>.remove()`
- File type required: `all directories and files`
- Remove the directory or file.
```cpp
myFile.remove();
```

### `<>.exists()`
- File type required: `all directories and files`
- Check if a file or directory exists.
```cpp
if(myFile.exists()){
    //foo
}
```

----------------------------------------------------------------

## Declaring directories as objects
```cpp
flmgr::dir myDir("myDir");
```

## Functions
### `<>.create()`
- File type required: `flmgr::filetype::txt` 
- Remove all contents from a file, and then write text to it.
```cpp
myDir.create();
```

----------------------------------------------------------------

## Declaring files as objects
```cpp
flmgr::file<flmgr::filetype::txt> myFile("randomfile.txt");
```
- In order to create an object holding the name of a file in a directory, use the overloaded constructor:

```cpp
flmgr::file<flmgr::filetype::txt> myFile(myDir, "randomfile.txt");
```

- Here `myDir` is a directory object created using the `flmgr::dir` class.

## Functions

### `<>.overwrite_text(std::string text)`
- File type required: `flmgr::filetype::txt` 
- Remove all contents from a file, and then write text to it.
```cpp
myFile.overwrite_text("test");
```

### `<>.append_text(std::string text)`
- File type required: `flmgr::filetype::txt`
- Append text to a file.
```cpp
myFile.append_text("test");
```

### `<>.read_text(std::vector<std::string> &dest)`
- File type required: `flmgr::filetype::txt`
- Read a file line by line and store each line in a vector.
```cpp
std::vector<std::string>fileContents;
myFile.read_text(fileContents);
```

### `<>.read_line(int line, std::string &dest)`
- File type required: `flmgr::filetype::txt`
- Read a specific line.
```cpp
std::string line;
myFile.read_line(4,line);
std::cout << "line content is : '" << line << "'" << std::endl;
```

### `<>.remove_content()`
- File type required: `all files`
- Remove all file contents.
```cpp
myFile.remove_content();
```

### `<>.set_key(std::string key, std::string value)`
- File type required: `flmgr::filetype::ini`
- Set a value in an INI file.
```cpp
myFile.set_key("Key", "value");
```

### `<>.get_key(std::string key)`
- File type required: `flmgr::filetype::ini`
- Get a value stored in an INI file.
```cpp
std::string value = myFile.get_key("Key");
```

### `<>.get_keys(std::unordered_map<std::string, std::string> &dest)`
- File type required: `flmgr::filetype::ini`
- Read all values stored in an INI file and store them in an unordered map.
```cpp
std::unordered_map<std::string, std::string> mymap;
myFile.get_keys(mymap);

for(auto &i : mymap)
{
    std::cout << i.first << "=" << i.second << std::endl;
}
```

## FAQ

### Creating directories in directories?

```cpp
flmgr::dir myPath("dir1/dir2");
```
- Of course, declaring an object like that will obviously not work, so we need to do it like this:

```cpp
flmgr::dir myPath; // leave the myPath "uninitialised" (it is initialised internally)

myPath.set_name("dir1");
myPath.create();

myPath.set_name("dir1/dir2");
myPath.create();

flmgr::file<flmgr::filetype::txt> FileInPath(myPath, "file.txt");

FileInPath.append_text("tesadasdast");
```

# Extra features

## Bit arrays

- You can create bit arrays.

```cpp
flmgr::extra::bitarray<8> myBitArray;

std::cout << "bitarray size: " << myBitArray.get_size() << std::endl;

myBitArray.set_at(3,1);
myBitArray.set_at(4,1);
myBitArray.set_at(7,1);
myBitArray.set_at(1,1);

for(int i = 0; i < myBitArray.get_size(); i++)
{
    std::cout << "bitarray<" << i << "> = " << myBitArray.get_at(i) << std::endl;
}
```

Output:

```
bitarray size: 8
bitarray<0> = 0
bitarray<1> = 1
bitarray<2> = 0
bitarray<3> = 1
bitarray<4> = 1
bitarray<5> = 0
bitarray<6> = 0
bitarray<7> = 1
```