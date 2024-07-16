#include <fstream>
#include <iostream>
#include <vector>

#include "./scanner.cpp"

void runFile(const char* path);
void runPrompt();
void run(const char* source);
void error(int line, const char* message);
void report(int line, const char* where, const char* message);

bool hadError = false;

int main(int argc, char const* argv[]) {
  if (argc > 2) {
    std::cout << "Usage: ladon [script]" << std::endl;
  } else if (argc == 2) {
    runFile(argv[1]);
  } else {
    runPrompt();
  }

  return 0;
}

void runFile(const char* path) {
  std::ifstream file(path, std::ios::binary | std::ios::ate);
  if (!file) {
    std::cout << "Could not open file" << std::endl;
    exit(74);
  }

  std::streamsize size = file.tellg();
  // move to the beginning of the file
  file.seekg(0, std::ios::beg);

  char* buffer = new char[size];

  // read the content of the file
  file.read(buffer, size);

  std::cout << buffer << std::endl;

  run(buffer);

  if (hadError) exit(65);
}

void run(const char* source) {
  Scanner scanner(source);
  std::vector<Token> tokens = scanner.scanTokens();

  /*for (Token token : tokens) {
    std::cout << token << std::endl;
  }*/
}

void error(int line, const char* message) { report(line, "", message); }

void report(int line, const char* where, const char* message) {
  std::cerr << "[line " << line << "] Error" << where << ": " << message
            << std::endl;
  hadError = true;
}

void runPrompt() {
  std::string line;
  while (true) {
    std::cout << "> ";
    std::getline(std::cin, line);
    if (line.empty()) break;
    run(line.c_str());
    hadError = false;
  }

  hadError = false;
}