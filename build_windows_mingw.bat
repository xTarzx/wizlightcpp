
@REM if you dont have jansson in path set it here
SET JANSSON_DIR=
SET PATH=%PATH%;%JANSSON_DIR%
if not exist build (mkdir -p build)
cmake . -B build -G "MinGW Makefiles" && ^
cmake --build ./build