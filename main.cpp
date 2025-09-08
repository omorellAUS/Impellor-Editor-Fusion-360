#include <iostream>
#include <string>
#include <fmt/core.h>
#include <spdlog/spdlog.h>

// Improved help output with more details
void print_help() {
    fmt::print("Usage: Impellor [--help] [--version]\n");
    fmt::print("Options:\n");
    fmt::print("  --help      Show this help message and exit\n");
    fmt::print("  --version   Show build version and exit\n");
}

int main(int argc, char* argv[]) {
    if (argc == 1) {
        spdlog::info("Impellor V2 Build Triggered Successfully!");
        return 0;
    }

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--help") {
            print_help();
            return 0;
        } else if (arg == "--version") {
            fmt::print("Impellor V2 Build\n");
            return 0;
        } else {
            spdlog::error("Unknown argument: {}", arg);
            print_help();
            return 1;
        }
    }

    // Should not reach here, but return error if it does
    return 1;
}
