# 🛒 Shopping List Management System (C)

A menu-driven Shopping List Management System developed using the **C programming language**. This project allows users to manage shopping items, calculate expenses, and maintain a dynamic shopping list using Dynamic Memory Allocation.

## 🚀 Features

- **Add Items:** Add shopping items with their name, unit price, and quantity.
- **View Shopping List:** Display all added items in a structured table.
- **Automatic Total Calculation:** Calculate individual item totals and the grand total.
- **Remove Items:** Remove a specific item from the shopping list.
- **Clear Shopping List:** Remove all items and reset the list.
- **Dynamic Memory Allocation:** Automatically increase memory capacity using `realloc()` when more space is required.
- **Memory Management:** Use `malloc()`, `realloc()`, and `free()` for efficient memory handling.
- **Session Expense Tracking:** Display the total amount spent during the current session.

## 🛠️ Technologies Used

- **Language:** C
- **Header Files:** 
  - `stdio.h`
  - `stdlib.h`
  - `string.h`
- **Concepts Implemented:**
  - Structures (`struct`)
  - Pointers
  - Double Pointers
  - Dynamic Memory Allocation (DMA)
  - Functions
  - Loops and Conditional Statements
  - Arrays and Strings
  - `malloc()`, `realloc()`, and `free()`

## 💻 How to Run

### 1. Clone the Repository

```bash
git clone YOUR_REPOSITORY_URL
```

### 2. Navigate to the Project Folder

```bash
cd shopping-list-management
```

### 3. Compile the Program

Using GCC:

```bash
gcc main.c -o shopping_list
```

### 4. Run the Program

**Windows:**
```bash
shopping_list.exe
```

**Linux / macOS:**
```bash
./shopping_list
```

## 📋 Menu Options

```text
===== Shopping List Menu =====
1. Add Item
2. View List
3. Remove Item
4. Clear List
5. Exit
==============================
Enter your choice:
```

## 📸 Sample Output

```text
===== Shopping List Menu =====
1. Add Item
2. View List
3. Remove Item
4. Clear List
5. Exit

Enter your choice: 1

Enter item name: Milk
Enter unit price: 30
Enter quantity: 2

Item added successfully!

===== Shopping List =====
No   Item             Qty    Price    Total
1    Milk             2      ₹30.00   ₹60.00

Grand Total            ₹60.00
```

## 🎯 Learning Objectives

This project was developed to strengthen practical knowledge of C programming, especially:

- Understanding structures and user-defined data types.
- Working with pointers and double pointers.
- Implementing Dynamic Memory Allocation.
- Understanding memory resizing through `realloc()`.
- Dividing programs into reusable functions.
- Implementing a menu-driven application.

## 🔮 Future Improvements

- Save shopping lists permanently using file handling.
- Add an option to edit existing items.
- Improve input validation.
- Generate shopping expense reports.
- Maintain purchase history across multiple sessions.

## 👨‍💻 Author

**Rajveer Srinet**

B.Tech – Artificial Intelligence & Machine Learning

---

⭐ If you find this project useful, consider giving this repository a star!
