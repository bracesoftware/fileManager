# File Manager
📁 • **File Manager** is a C++ library designed to provide a friendlier approach to managing persistent data.

## Declaring files as objects
```cpp
flmgr::file<flmgr::filetype::txt> myFile("randomfile.txt");
```

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