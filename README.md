
# 🛒 Online Shopping Management System

This is a simple console-based **shopping cart system** written in C++. It allows users to add products to a cart, remove them, and view a bill—all using data from a CSV file (`Products.csv`).

## 📦 Features

- Load products from a CSV file
- Add products to the shopping cart
- Remove products from the cart
- Display a full bill with total amount
- Basic input validation and error handling
- Clean object-oriented design using C++ classes

## 🗂️ Files

```
.
├── expl.cpp           // Main C++ source code
├── Products.csv       // CSV file containing available product data
```

## 🧾 Products.csv Format

Each line in the `Products.csv` file should contain:

```
ProductName,Price
```

**Example:**
```
Pen,10
Notebook,50
Eraser,5
```

## 🛠️ How to Compile and Run

1. **Compile:**
   ```bash
   g++ expl.cpp -o shopping
   ```

2. **Run:**
   ```bash
   ./shopping
   ```

## 📋 Menu Options

```
Main Menu:
1. Add Product to Cart
2. Show Bill
3. Remove Product from Cart
0. Exit
```

### ➕ Add Product
Enter the product name exactly as listed in `Products.csv`. The product will be added to the bill.

### ➖ Remove Product
Enter the product name to remove it from the bill.

### 🧾 Show Bill
Displays all items in the cart with their prices and total cost.

## 📌 Notes

- Product names are case-sensitive.
- Only one unit per product is supported in the current version.
- Products must exist in `Products.csv` to be added.

## 📃 License

This project is open-source and available under the [MIT License](https://opensource.org/licenses/MIT).

---

🛍️ Happy shopping from the terminal!
