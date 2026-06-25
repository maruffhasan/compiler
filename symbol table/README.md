# Symbol Table Implementation

**Course:** CSE310 — Compiler Sessional  
**Institution:** Bangladesh University of Engineering and Technology (BUET), Dept. of CSE  
**Session:** January 2026  
**Deadline:** July 3, 2026 (Friday) at 11:55 PM

---

## Overview

This assignment involves implementing a **Symbol Table** — a core data structure used by compilers to store information (name, type, scope) about identifiers, function names, objects, and other entities encountered in source code.

The symbol table is structured as a **stack of hash tables**, where each hash table (called a *Scope Table*) holds symbols belonging to a particular scope. When a new block is entered, a new scope table is pushed; when the block ends, it is popped.

---

## Classes to Implement

### 1. `SymbolInfo`
Stores information about a single symbol.

- **Private members:** `name` (string), `type` (string)
- **Getter/setter** methods for both fields
- A `next` pointer to another `SymbolInfo` for **chaining** (collision resolution in hash table)
- Must be extensible for later compiler phases

### 2. `ScopeTable`
Implements a single hash table for one scope.

- Array of `SymbolInfo*` pointers (the buckets)
- Uses the **SDBM hash function**:

```cpp
unsigned int SDBMHash(string str, unsigned int num_buckets) {
    unsigned int hash = 0;
    unsigned int len = str.length();
    for (unsigned int i = 0; i < len; i++) {
        hash = ((str[i]) + (hash << 6) + (hash << 16) - hash) % num_buckets;
    }
    return hash;
}
```

- `parent_scope` pointer to the enclosing `ScopeTable`
- Unique numeric ID for each scope

**Methods:**
| Method | Description |
|--------|-------------|
| `Constructor(int n)` | Allocates `n` buckets |
| `Destructor` | Frees all allocated memory |
| `Insert(name, type)` | Inserts symbol if not already present; returns `bool` |
| `LookUp(name)` | Returns `SymbolInfo*` or `nullptr` if not found |
| `Delete(name)` | Deletes symbol if present; returns `bool` |
| `Print()` | Prints the scope table to output |

### 3. `SymbolTable`
Manages the stack of `ScopeTable`s.

- Pointer to the current (top) `ScopeTable`

**Methods:**
| Method | Description |
|--------|-------------|
| `EnterScope()` | Creates a new scope table, makes it current |
| `ExitScope()` | Removes the current scope table (cannot exit root) |
| `Insert(name, type)` | Inserts into the current scope table; returns `bool` |
| `Remove(name)` | Removes from the current scope table; returns `bool` |
| `LookUp(name)` | Searches from current scope upward; returns `SymbolInfo*` |
| `PrintCurrentScope()` | Prints the current scope table |
| `PrintAllScopes()` | Prints all scope tables |

---

## Input Format

- **Line 1:** Integer — number of buckets in each hash table
- **Subsequent lines:** Operation code followed by arguments

| Code | Operation | Arguments |
|------|-----------|-----------|
| `I` | Insert | `<name> <type>` — for `FUNCTION`: return type then arg types; for `STRUCT`/`UNION`: alternating type and variable name |
| `L` | Look Up | `<name>` |
| `D` | Delete | `<name>` |
| `P A` | Print All | Prints all scope tables |
| `P C` | Print Current | Prints only the current scope table |
| `S` | Enter Scope | Opens a new scope |
| `E` | Exit Scope | Closes the current scope (root scope cannot be exited) |
| `Q` | Quit | Stops processing |

> **Note:** Spacing between inputs may be uneven. Do not assume uniform spacing.

---

## Implementation Requirements

- Language: **C++**
- Use **dynamic memory allocation** — no STL containers (`vector`, `list`, etc.)
- Read input from and write output to **files** (pass filenames as command-line arguments)
- Must compile and run on **Linux** (use WSL or VirtualBox if on Windows)
- No hardcoded values
- All destructors must be **exception-safe** and **memory-leak-free**
  - Verify with: `g++ -fsanitize=address ...`

---

## Submission Instructions

1. Create a folder named with your **7-digit Student ID**
2. Name each file: `<StudentID>_<filename>` (e.g., `2205070_symbol_table.cpp`)
3. Optionally include a `<StudentID>_Makefile` or `<StudentID>_build.sh`
4. Compress the folder as a `.zip` file named after your Student ID
5. Submit via **Moodle**

> Do **not** include object files or executables in the submission.

---

## Notes

- This is an **ungraded practice assignment**, but subsequent graded assignments build directly on it — correctness matters.
- Test thoroughly, including **corner cases**.
- Avoid segmentation faults and dangling pointers, especially when iterating with pointer chains.
