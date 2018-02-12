#pragma once

#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include "exec.h"
using namespace std;


/**
 * Execute a Linux shell command.
 * From https://stackoverflow.com/a/478960/827927
 */
string exec(const char* cmd) {
    array<char, 128> buffer;
    string result;
    shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
    if (!pipe) throw runtime_error("popen() failed!");
    while (!feof(pipe.get())) {
        if (fgets(buffer.data(), 128, pipe.get()) != nullptr)
            result += buffer.data();
    }
    return result;
}
