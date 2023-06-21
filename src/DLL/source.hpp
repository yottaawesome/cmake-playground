//#include "build/MyLibrary_Export.h" # See line in CMakeLists.txt to include export header in all files implicitly: add_definitions(/FI"build/MyLibrary_Export.h")

class X
{
    void Blah();
};

 MyLibrary_EXPORT void What();

// BLAH void Huh();