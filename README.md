# 🚗 Traffic Management System (C++)

## 📌 Project Description

This is a simple **Traffic Management System** built using **C++**.
The program allows users to manage car records and automatically calculates fines for overspeeding vehicles.

All data is stored in a **CSV file**, so information is saved even after closing the program.

---

## ⚙️ Features

* ➕ Add new car details
* ❌ Remove car from system
* 📋 Display all cars
* 🔍 Search car by license plate
* 💾 Save data to CSV file
* 📂 Load data automatically on startup
* 💰 Automatic fine calculation for overspeeding

---

## 🧠 How Fine is Calculated

* Speed limit = **100 km/h**
* Fine = **$2 for every km/h above 100**

Example:

* Speed = 110 → Fine = $20
* Speed = 90 → No fine

---

## 📁 File Structure

```
project-folder/
│
├── main.cpp
├── cars.csv   (auto-created)
└── README.md
```

---

## ▶️ How to Run

### Step 1: Compile the program

```
g++ main.cpp -o traffic
```

### Step 2: Run the program

```
./traffic
```

---

## 📂 CSV File Format

The file `cars.csv` stores data like this:

```
Toyota,Corolla,BA1234,120
Honda,Civic,BA5678,90
```

Format:

```
Make,Model,LicensePlate,Speed
```

---

## 🛠️ Technologies Used

* C++
* STL (Vector, String)
* File Handling (`fstream`)
* CSV format

---

## 🚀 Future Improvements

* ✏️ Update/edit car details
* 🧹 Delete all records
* 📊 Show highest speed car
* 🖥️ GUI version
* 🗄️ Database integration (SQLite)

---

## 👨‍💻 Author

**Sanjog Tamang**

---

## 📢 Notes

* The CSV file is automatically created when you add data.
* Make sure the program has permission to read/write files.

---

🔥 This project is a great step toward learning real-world C++ development with file handling.
