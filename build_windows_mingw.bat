
SET PATH=%PATH%;C:\RandomCoding\jansson\build
if not exist build (mkdir -p build)
cmake . -B build -G "MinGW Makefiles" && ^
cmake --build ./build