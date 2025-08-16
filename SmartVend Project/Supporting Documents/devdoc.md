# Developer Documentation – SmartVend++

Project Title: SmartVend++ – C++ Vending Machine System  
Developer: Ozgur Serin  
Institution: Elizabeth School of London – Bath Spa University  

---

## Overview

SmartVend++ is a console-based vending machine simulator developed in C++. It demonstrates core principles of object-oriented programming including classes, data encapsulation, and input validation, while delivering a user-friendly purchasing experience.

---

## Project Structure

Core Source Code/
    └── main.cpp         Contains all logic: menu, purchase, payment

Data_Input files/
    ├── items.txt        Placeholder for product data
    ├── restock.txt      Placeholder for restocking feature
    └── setting.txt      Placeholder for future system settings

Output_Log Files/
    ├── sales.txt        Simulated purchase records
    ├── errors.txt       Simulated error logs
    └── change_log.txt   Development changes and progress

Supporting Documents/
    ├── devdoc.txt       Text version of this documentation
    ├── Read.md          Instructions on how to run and use
    ├── Report.pdf       Submission report placeholder
    ├── Design_diagram.png Design flowchart
    └── Learning Outcomes.txt Learning objectives met

---

## Key Features

- Contactless and cash payment options with validation  
- Ten percent discount automatically applied to all purchases  
- Suggestion system (for example, biscuits offered with coffee)  
- Change returned to users for cash payments  
- Category-based item listing (Drink, Snack, Hot Drink)  
- Stock management system with real-time updates  
- Friendly and clear console prompts and messages  
- Handles invalid inputs using cin.clear() and cin.ignore()

---

## Core Classes

Product  
Represents individual items in the vending machine  
Attributes: name, category, price, stock  
Methods: isAvailable(), purchase()

VendingMachine  
Handles menu, logic flow, purchasing and payments  
Methods:  
    start()  
    showMenu()  
    handlePurchase()  
    getIntInput()  
    getDoubleInput()

---

## How to Compile and Run

1. Open terminal or command prompt  
2. Navigate to the folder with main.cpp  
3. Compile and run the program using the following:

    g++ main.cpp -o SmartVend  
    ./SmartVend  

---

## Future Enhancements

- Load products from file (items.txt)  
- Admin panel for managing stock  
- GUI version for easier interaction  
- Loyalty and rewards system  
- Multi-language support  

---

## Assessment Brief Alignment

- Console menu with categorised products  
- Item selection using ID codes  
- Input validation to handle incorrect entries  
- Support for both card and cash payments  
- Accurate change returned for cash  
- Automatic discount calculation  
- Suggestion feature based on item choice  
- Loop for additional purchases  
- Full code comments in plain English  

---

## Final Notes

SmartVend++ meets all the requirements of the course brief and simulates a working vending machine. The code is clear, fully tested, and easy to maintain or expand. It was built using fundamental C++ programming techniques and is ready for assessment submission.
