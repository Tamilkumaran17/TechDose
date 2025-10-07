// config.h
#ifndef CONFIG_H
#define CONFIG_H

#ifndef ONLINE_JUDGE
    #include <fstream>
    #define USE_FAST_IO
    void setupIO() {
        freopen("D:/TechDose/input.txt", "r", stdin);
        freopen("D:/TechDose/output.txt", "w", stdout);
    }
#else
    void setupIO() {}
#endif

#endif // CONFIG_H
