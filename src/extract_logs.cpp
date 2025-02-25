#include <iostream>
#include <fstream>
#include <string>

// Function to extract logs for a given date and save them to an output file
void extract_logs(const std::string& date) {
    // Define the input log file path
    std::ifstream infile("C:\\Users\\Karthik\\tech-campus-recruitment-2025\\logs_2024.log");

    // Define the output file path where extracted logs will be saved
    std::string output_file = "C:\\Users\\Karthik\\tech-campus-recruitment-2025\\output\\output_" + date + ".txt";
    std::ofstream outfile(output_file);

    // Check if input or output file failed to open
    if (!infile.is_open() || !outfile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    std::string line;
    // Read the input file line by line
    while (std::getline(infile, line)) {
        // Check if the line starts with the given date
        if (line.compare(0, date.length(), date) == 0) {
            outfile << line << std::endl;  // Write matching log entry to the output file
        }
    }

    // Close input and output file streams
    infile.close();
    outfile.close();
}

// Main function to take command-line arguments and trigger log extraction
int main(int argc, char* argv[]) {
    // Check if the correct number of arguments is provided
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " YYYY-MM-DD" << std::endl;
        return 1;  // Return error code if the input format is incorrect
    }

    std::string date = argv[1];  // Extract the date from command-line arguments
    extract_logs(date);  // Call the function to extract logs for the given date

    // Print confirmation message with output file path
    std::cout << "Log entries for " << date << " have been saved to output/output_" << date << ".txt" << std::endl;
    return 0;  // Return success
}
