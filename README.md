taraxa take home exercise.

This uses the C++ header only json parsing library here: https://github.com/nlohmann/json
This has used the cmake template from: https://github.com/mmorse1217/cmake-project-template

To run the example:

```
mkdir build
cd build
cmake ..
make
cd ../bin
./example ../files/tasks.json
```

Expected output:

```
Attempting to parse file ../files/tasks.json
21
22
18
5
```
