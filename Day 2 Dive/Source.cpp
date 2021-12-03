#include <fstream>
#include <string>

void autoPilot(void (*runInstruction)(char*, int, int*, int*, int*)) {

    int horizontal = 0;
    int depth = 0;
    int aim = 0;

    std::ifstream file("input.txt");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            const char* parsed_line = line.c_str();
            const int steps = 0;
            char* instruction = new char[strlen(parsed_line)];
            for (int i = 0; i < strlen(parsed_line); i++) {
                if (parsed_line[i] == ' ') {
                    instruction[i] = '\0';
                    int steps;
                    sscanf_s(&parsed_line[i], "%d", &steps);
                    runInstruction(instruction, steps, &depth, &horizontal, &aim);
                }
                else {
                    instruction[i] = parsed_line[i];
                }
            }
        }
        file.close();
    }
    printf("result: %d\n\n", horizontal * depth);
}

void runInstructionPartOne(char* instruction, int steps, int* depth, int* horizontal, int*) {
    if (strcmp(instruction, "forward") == 0) {
        *horizontal += steps;
    }
    else if (strcmp(instruction, "down") == 0) {
        *depth += steps;
    }
    else if (strcmp(instruction, "up") == 0) {
        *depth -= steps;
    }
}

void runInstructionPartTwo(char* instruction, int steps, int* depth, int* horizontal, int* aim) {
    if (strcmp(instruction, "forward") == 0) {
        *horizontal += steps;
        *depth += *aim * steps;
    }
    else if (strcmp(instruction, "down") == 0) {
        *aim += steps;
    }
    else if (strcmp(instruction, "up") == 0) {
        *aim -= steps;
    }
}

int main() {
    void (*instructionRunner)(char*, int, int*, int*, int*);

    // Uncomment to run task one
    //instructionRunner = &runInstructionPartOne;

    // Uncomment to run task two
    instructionRunner = &runInstructionPartTwo;

    autoPilot(instructionRunner);
    
    // Windows only but whatever
    system("pause");
	return 0;
}