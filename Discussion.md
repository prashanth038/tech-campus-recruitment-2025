# **Discussion on Efficient Log Retrieval Solution**

## **Solutions Considered**

### **1. Sequential File Scanning (Chosen Approach)**

- Reads the log file line by line.
- Checks if each line starts with the given date.
- Writes matching entries to an output file.
- **Pros:** Simple implementation, minimal memory usage.
- **Cons:** Slower for very large files as it scans the entire file.

### **2. Indexing-Based Search (Not Chosen)**

- Preprocesses the log file and creates an index mapping dates to byte offsets.
- On query, seeks directly to the relevant portion of the file.
- **Pros:** Faster queries after initial indexing.
- **Cons:** Requires preprocessing, additional storage for index files.

### **3. Parallel Processing (Not Chosen)**

- Splits the log file into chunks and processes them in parallel.
- **Pros:** Faster processing on multi-core machines.
- **Cons:** Complexity increases, not feasible for single-threaded execution.

---

## **Final Solution Summary**

The sequential file scanning approach was chosen because:

1. It **avoids extra storage overhead** required for indexing.
2. It **works efficiently** given that logs are evenly distributed per day.
3. It **keeps memory usage low** by processing logs line by line instead of loading large chunks into RAM.
4. It **ensures simplicity and portability** across different systems without requiring complex dependencies.

While indexing and parallel processing could improve performance, they introduce additional complexity and may not be necessary unless the log file is frequently queried.

---

## **Steps to Run**

### **1. Compile the Code**

Ensure you have a C++ compiler installed (such as g++). Open a terminal or command prompt and navigate to the source directory:

```sh
cd C:\Users\prashanth\tech-campus-recruitment-2025\src
```

Then, compile the code:

```sh
g++ extract_logs.cpp -o extract_logs -std=c++17
```

### **2. Run the Program**

Execute the program with the desired date:

```sh
.\extract_logs 2024-12-01
```

This will extract all logs from `logs_2024.log` for the given date and save them to:

```
C:\Users\prashanth\tech-campus-recruitment-2025\output\output_2024-12-01.txt
```

### **3. Verify Output**

Check the output file to confirm that it contains only the logs for the specified date.

---
