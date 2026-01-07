Clinical Data System 

A simple C++ program that collects patient details, validates heart rate inputs, and generates a clinical audit report based on the provided data.

Features

- Accepts patient name, age, and multiple heart rate readings

- Validates all numeric inputs using safe string-to-integer conversion

- Records invalid data as unique flags using a set

- Detects high heart rate conditions

- Generates a clear audit result: Pass / Review / Fail

- Displays formatted, user-friendly console output

Key Concepts Used

- Input validation with stoi and exception handling

- STL containers (vector, set)

- Clean separation of input, processing, and output logic
