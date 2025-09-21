# XGreety Coding Style Guide

This document outlines the coding style conventions observed in the XGreety project based on analysis of the existing codebase.

## General Formatting

- **Indentation**: 2 spaces (no tabs)
- **Line Length**: No strict limit observed, but most lines are kept under 100 characters
- **Namespaces**: All code is wrapped in the `xgreety` namespace
- **Braces**: Opening braces on the same line as the statement (K&R style)
  ```cpp
  if (condition) {
    // code
  }
  ```

## Naming Conventions

- **Classes**: PascalCase (e.g., `LoginBox`, `StatusBar`, `ConfigManager`)
- **Methods**: camelCase (e.g., `configure()`, `handleInput()`, `getWindowInput()`)
- **Variables**: camelCase (e.g., `usernameChoice`, `currentActive`)
- **Member Variables**: No consistent prefix/suffix (neither `m_` nor trailing `_` is used)
- **Constants**: All uppercase with underscores (e.g., `CONFIG_PATH`)

## Header Files

- **Include Guards**: `#pragma once` is used instead of traditional include guards
- **Header Order**:
  1. Related header
  2. C++ standard library headers
  3. Third-party library headers (e.g., ncurses.h)
  4. Project headers

## Documentation

- **Function Documentation**: Detailed Doxygen-style comments for public methods
  ```cpp
  /**
   * @brief Description of the function
   * @param paramName Description of the parameter
   * @return Description of the return value
   */
  ```
- **Class Documentation**: Doxygen-style comments explaining class purpose
- **Implementation Comments**: Minimal but present where needed to explain non-obvious code

## Object-Oriented Practices

- **Encapsulation**: Private member variables with public accessor methods
- **Inheritance**: Used for UI components (derived from `Window` base class)
- **Constructors**: Multiple constructors provided (default and parameterized)
- **Virtual Methods**: Used for polymorphic behavior (e.g., `draw()`, `handleInput()`)

## Memory Management

- **Smart Pointers**: `std::unique_ptr` used for ownership management
- **Resource Acquisition Is Initialization (RAII)**: Used for window management

## Error Handling

- **Exceptions**: Used for critical errors (e.g., window creation failure)
- **Return Codes**: Not heavily used; prefer exceptions for error handling

## Other Conventions

- **Const Correctness**: Applied to methods that don't modify object state
- **Type Safety**: C++ style casts used instead of C-style casts
- **STL Usage**: Standard containers like `std::vector` and `std::string` used extensively
- **Comments**: Descriptive comments explaining complex logic or design decisions

## Specific Patterns

- **UI Component Structure**:
  - Constructor initializes resources
  - `configure()` sets up the component
  - `draw()` renders the component
  - `handleInput()` processes user input

This style guide is derived from analyzing the existing codebase and may evolve as the project matures.
