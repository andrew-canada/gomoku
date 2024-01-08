# readme

## bits header file location

C:\work\msys64\mingw64\include\c++\12.1.0\bits

## good c++ config json:

```json
{
  "configurations": [
    {
      "name": "windows-gcc-x64",
      "includePath": [
        "${workspaceFolder}/**"
      ],
      "compilerPath": "C:/MinGW/bin/gcc.exe",
      "cStandard": "${default}",
      "cppStandard": "${default}",
      "intelliSenseMode": "windows-gcc-x64",
      "compilerArgs": [
        ""
      ]
    }
  ],
  "version": 4
}
```

## bad c++ config json:

```json
{
    "configurations": [
        {
            "name": "Win32",
            "includePath": [
                "${workspaceFolder}/**",
                "C:/work/msys64/mingw64/include/c++/12.1.0"
            ],
            "defines": [
                "_DEBUG",
                "UNICODE",
                "_UNICODE"
            ],
            "windowsSdkVersion": "10.0.19041.0",
            "compilerPath": "cl.exe",
            "cStandard": "c17",
            "cppStandard": "c++17",
            "intelliSenseMode": "windows-msvc-x64"
        }
    ],
    "version": 4
}
```
